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
#include "mainWin.h"

#include "qLights_defs.h"
#include "ctrlPanel.h"
#include "dlgAddScene.h"
#include "scene.h"
#include "aString.h"
#include "channel.h"


/*******************************************************************************
* CtrlPanel::onRegisterCtrl
*******************************************************************************/
void CtrlPanel::onRegisterCtrl()
{
    // register bank buttons
    for (u32 i = 0; i < BANK_MAX; i++)
    {
        auto pBankBtn = std::get<0>(m_vBankTuples.at(i));
        registerCtrl(pBankBtn, ID_FIRST_BANK_IDX + i, true);
    }

    // register fixture buttons
    for (u32 i = 0; i < FIXTURE_MAX; i++)
    {
        auto pFixtureBtn = std::get<0>(m_vFixtureTuples.at(i));
        registerCtrl(pFixtureBtn, ID_FIRST_FIXTURE_IDX + i, true);
    }

    // register scenes
    for (u32 i = 0; i < SCENE_MAX; i++)
    {
        auto pSceneBtn = std::get<0>(m_vSceneTuples.at(i));
        registerCtrl(pSceneBtn, ID_FIRST_SCENE_IDX + i, true);
    }

    // register faders
    for (u32 iFaderIdx = 0; iFaderIdx < FADER_MAX; iFaderIdx++)
    {
        registerCtrl(m_vFaders.at(iFaderIdx), ID_FIRST_FADER_IDX + iFaderIdx, true);
    }

    // // register master fader
    // registerCtrl(get<1>(m_masterFader), ID_MASTER_FADER_IDX, true);

    // // register blackout button
    // registerCtrl(m_pUi->m_pBlackout, ID_BACKOUT_IDX, true);

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
       onBankSelected(s32CtrlId - ID_FIRST_BANK_IDX);
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

   // // check for scenes
   // if (s32CtrlId == ID_BACKOUT_IDX)
   // {
   //     onBlackoutClicked();
   // }

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
    // else if (s32CtrlId == ID_MASTER_FADER_IDX)
    // {
    //     onMasterFaderMoved(_s32Value);
    // }

} // CtrlPanel::onCtrlValueChanged


/*******************************************************************************
* CtrlPanel::onBankSelected
*******************************************************************************/
void CtrlPanel::onBankSelected(s32 _s32BankBtnIdx)
{
    CHECK_PRE_CONDITION_VOID(_s32BankBtnIdx < BANK_MAX);

    // set the active bank and fixture to nullptr
    m_pActiveBank = nullptr;
    m_pActiveFixture = nullptr;

    // (de)select the buttons
    for (s32 idx = 0; idx < BANK_MAX; idx++)
    {
        auto pBankBtn = std::get<0> (m_vBankTuples.at(idx));

        if (pBankBtn->isChecked() && idx == _s32BankBtnIdx)
        {
            // button checked => set active bank
            m_pActiveBank = std::get<1> (m_vBankTuples.at(idx));
        }
    }

    initFixtures();
    initFaders();
    updateGui();
} // CtrlPanel::onBankSelected


/*******************************************************************************
* CtrlPanel::onFixtureSelected
*******************************************************************************/
void CtrlPanel::onFixtureSelected(s32 _s32FixtureBtnIdx)
{
    CHECK_PRE_CONDITION_VOID(_s32FixtureBtnIdx < FIXTURE_MAX);

    m_pActiveFixture = nullptr;

    auto pFixtureBtn    = std::get<0> (m_vFixtureTuples.at(_s32FixtureBtnIdx));
    auto pFixture       = std::get<1> (m_vFixtureTuples.at(_s32FixtureBtnIdx));

    if (pFixtureBtn->isChecked())
    {
        // button checked => set active bank
        m_pActiveFixture = pFixture;
    }

    initFaders();
    updateGui();
} // CtrlPanel::onFixtureSelected


/*******************************************************************************
* CtrlPanel::onSceneSelected
*******************************************************************************/
void CtrlPanel::onSceneSelected(s32 _s32SceneBtnIdx)
{
    cout << __PRETTY_FUNCTION__ << ": " << _s32SceneBtnIdx << endl;

    CHECK_PRE_CONDITION_VOID(_s32SceneBtnIdx < SCENE_MAX);

    auto        pSceneBtn   = std::get<0> (m_vSceneTuples.at(_s32SceneBtnIdx));
    auto        pScene      = std::get<1> (m_vSceneTuples.at(_s32SceneBtnIdx));
    MainWin     &mw         = getMainWin();

    cout << pSceneBtn << " - " << pScene << endl;

    DlgAddScene *pDlg = new DlgAddScene(this, pSceneBtn->text());
    pDlg->createWin();

    switch (mw.workMode())
    {
        case enumWorkMode::Play:
            loadScene(_s32SceneBtnIdx);
            break;

        case enumWorkMode::SaveScene:
        {
            DlgAddScene *pDlg = new DlgAddScene(this, pSceneBtn->text());
            pDlg->createWin();

            if (pDlg->showModal() == DialogReturn::accepted)
            {
                saveScene(_s32SceneBtnIdx, pDlg->sceneName());
            } // if

            break;
        }
    } // switch

    // reset the work mode
    mw.setWorkMode(enumWorkMode::Play);
    mw.sendUpdateCmd(UPDATE_GUI);
} // CtrlPanel::onSceneSelected


/*******************************************************************************
* CtrlPanel::onFaderMoved
*******************************************************************************/
void CtrlPanel::onFaderMoved(s32    s32FaderIdx,
                             s32    _s32Value)
{
    auto pChannel = m_vFaders.at(s32FaderIdx)->channel();
    CHECK_PRE_CONDITION_VOID(pChannel);

    pChannel->setValue(static_cast<u8> (_s32Value), true);
} // CtrlPanel::onFaderMoved
