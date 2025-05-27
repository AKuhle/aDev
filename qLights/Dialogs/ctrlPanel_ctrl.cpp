/*******************************************************************************
* \file CtrlPanel.cpp
* \author Andreas Kuhlewind
*
* \brief
*
* $Revision: 69 $
* $LastChangedDate: 2010-08-17 14:10:45 +0200 (Di, 17 Aug 2010) $
* $LastChangedBy: akuhlewi $
*
*  Detailed description starts here.
*******************************************************************************/


/*******************************************************************************
* includes
*******************************************************************************/
#include "qLights_defs.h"
#include "ctrlPanel.h"


/*******************************************************************************
* CtrlPanel::onRegisterCtrl
*******************************************************************************/
void CtrlPanel::onRegisterCtrl()
{
    // register banks
    for (u32 i = 0; i < BANK_MAX; i++)
    {
        auto pBankBtn = std::get<0>(m_vBankCtrl.at(i));
        registerCtrl(pBankBtn, ID_FIRST_BANK_IDX + i, true);
    }

    // register fixtures
    for (u32 i = 0; i < FIXTURE_MAX; i++)
    {
        registerCtrl(std::get<0>(m_vFixtureCtrl.at(i)), ID_FIRST_FIXTURE_IDX + i, true);
    }

    // register scenes
    for (u32 i = 0; i < SCENE_MAX; i++)
    {
        auto pSceneBtn = std::get<0>(m_vSceneCtrl.at(i));
        registerCtrl(pSceneBtn, ID_FIRST_SCENE_IDX + i, true);
    }

    // register faders
    for (u32 iFaderIdx = 0; iFaderIdx < FADER_MAX; iFaderIdx++)
    {
        registerCtrl(get<1>(m_vFader.at(iFaderIdx)), ID_FIRST_FADER_IDX + iFaderIdx, true);
    }

    // register master fader
    registerCtrl(get<1>(m_masterFader), ID_MASTER_FADER_IDX, true);

    // register blackout button
    registerCtrl(m_pUi->m_pBlackout, ID_BACKOUT_IDX, true);

} // CtrlPanel::onRegisterCtrl


/*******************************************************************************
* CtrlPanel::onUpdateCtrl
*******************************************************************************/
void CtrlPanel::onUpdateCtrl(aCtrlI */*_pCtrl*/)
{
} // CtrlPanel::onUpdateCtrl


/*******************************************************************************
* CtrlPanel::onCtrlClicked
*******************************************************************************/
void CtrlPanel::onCtrlClicked(aCtrlI *_pCtrl)
{
   u32 s32CtrlId = _pCtrl->ctrlId();

   // check for banks
   if (s32CtrlId >= ID_FIRST_BANK_IDX &&
       s32CtrlId < ID_FIRST_BANK_IDX + BANK_MAX)
   {
       onBankSeleted(s32CtrlId - ID_FIRST_BANK_IDX);
   }

   // check for fixture
   if (s32CtrlId >= ID_FIRST_FIXTURE_IDX &&
       s32CtrlId < ID_FIRST_FIXTURE_IDX + FIXTURE_MAX)
   {
       onFixtureSelected(s32CtrlId - ID_FIRST_FIXTURE_IDX);
   }

   // check for scenes
   if (s32CtrlId >= ID_FIRST_SCENE_IDX &&
       s32CtrlId < ID_FIRST_SCENE_IDX + SCENE_MAX)
   {
       onSceneSelected(s32CtrlId - ID_FIRST_SCENE_IDX);
   }

   // check for scenes
   if (s32CtrlId == ID_BACKOUT_IDX)
   {
       onBlackoutClicked();
   }

} // CtrlPanel::onCtrlClicked


/*******************************************************************************
* CtrlPanel::onCtrlValueChanged
*******************************************************************************/
void CtrlPanel::onCtrlValueChanged(aCtrlI   *_pCtrl,
                                   s32      _s32Value)
{
    u32 s32CtrlId = _pCtrl->ctrlId();

    // check for faders
    if (s32CtrlId >= ID_FIRST_FADER_IDX &&
        s32CtrlId < ID_FIRST_FADER_IDX + FADER_MAX)
    {
        // fader moved
        onFaderMoved(s32CtrlId - ID_FIRST_FADER_IDX, _s32Value);
    }
    else if (s32CtrlId == ID_MASTER_FADER_IDX)
    {
        onMasterFaderMoved(_s32Value);
    }

} // CtrlPanel::onCtrlValueChanged
