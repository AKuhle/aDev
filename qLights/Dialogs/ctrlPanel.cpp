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
#include "mainWin.h"
#include "ctrlPanel.h"
#include "universe.h"

#include "dlgAddBank.h"


/*******************************************************************************
* CtrlPanel::CtrlPanel
*******************************************************************************/
CtrlPanel::CtrlPanel(SysWin *_pParent /*= nullptr*/)
: aPlainWin(_pParent)
{
    #ifdef _USE_QT_
        m_pUi = new Ui::FormCtrlPanel;
        m_pUi->setupUi(this);
    #endif
} // CtrlPanel::CtrlPanel


/*******************************************************************************
* CtrlPanel::~CtrlPanel
*******************************************************************************/
CtrlPanel::~CtrlPanel()
{
    #ifdef _USE_QT_
        delete m_pUi;
    #endif
} // ~CtrlPanel::CtrlPanel


/*******************************************************************************
* CtrlPanel::onCreateWin
*******************************************************************************/
bool CtrlPanel::onCreateWin()
{
    // create the universe
    m_pUniverse = make_shared<Universe> (UNIVERSE);

    // bank controls
    m_vBankBtn.push_back(m_pUi->m_pBank_01, m_pUi->m_pBank_02, m_pUi->m_pBank_03);
    m_vBankBtn.push_back(m_pUi->m_pBank_04, m_pUi->m_pBank_05, m_pUi->m_pBank_06);
    m_vBankBtn.push_back(m_pUi->m_pBank_07, m_pUi->m_pBank_08, m_pUi->m_pBank_09);
    m_vBankBtn.push_back(m_pUi->m_pBank_10);

    // fader controls
    m_vFader.push_back(m_pUi->m_pFader_01, m_pUi->m_pFader_02, m_pUi->m_pFader_03);
    m_vFader.push_back(m_pUi->m_pFader_04, m_pUi->m_pFader_05, m_pUi->m_pFader_06);
    m_vFader.push_back(m_pUi->m_pFader_07, m_pUi->m_pFader_08, m_pUi->m_pFader_09);
    m_vFader.push_back(m_pUi->m_pFader_10, m_pUi->m_pFader_11, m_pUi->m_pFader_12);
    m_vFader.push_back(m_pUi->m_pFader_13, m_pUi->m_pFader_14, m_pUi->m_pFader_15);
    m_vFader.push_back(m_pUi->m_pFader_16, m_pUi->m_pFader_17, m_pUi->m_pFader_18);
    m_vFader.push_back(m_pUi->m_pFader_19, m_pUi->m_pFader_20, m_pUi->m_pFader_21);
    m_vFader.push_back(m_pUi->m_pFader_22, m_pUi->m_pFader_23, m_pUi->m_pFader_24);

    return true;
} // CtrlPanel::onCreateWin


/*******************************************************************************
* CtrlPanel::activeUniverse
*******************************************************************************/
shared_ptr<Universe> CtrlPanel::activeUniverse() const
{
    return m_pUniverse;
} // CtrlPanel::activeUniverse


/*******************************************************************************
* CtrlPanel::bankCount
*******************************************************************************/
u32 CtrlPanel::bankCount() const
{
    return (activeUniverse())?   activeUniverse()->bankCount() : 0;
} // CtrlPanel::bankCount


/*******************************************************************************
* CtrlPanel::addBank
*******************************************************************************/
void CtrlPanel::addBank()
{
    shared_ptr<Universe>    pUniverse = activeUniverse();
    CHECK_PRE_CONDITION_VOID(pUniverse != nullptr);

    u32 nBank = pUniverse->bankCount();

    if (nBank < BANK_COUNT)
    {
        aString     sBankName;

        DlgAddBank  *pDlg = new DlgAddBank(this, sBankName);
        pDlg->createWin();
        if (pDlg->showModal() == DialogReturn::accepted)
        {
            shared_ptr<Bank> pBank = bank(nBank);

            if (pBank)
            {
                pBank->setName(sBankName);

                getMainWin().sendUpdateCmd(UPDATE_GUI);
            }
        }
    }
} // CtrlPanel::addBank


/*******************************************************************************
* CtrlPanel::bank
*******************************************************************************/
shared_ptr<Bank> CtrlPanel::bank(u32 _u32Idx) const
{
    return (activeUniverse())?   activeUniverse()->bank(_u32Idx) : nullptr;
} // CtrlPanel::bank


/*******************************************************************************
* CtrlPanel::addFixture
*******************************************************************************/
void CtrlPanel::addFixture()
{
} // CtrlPanel::addFixture


/*******************************************************************************
* CtrlPanel::updateGui
*******************************************************************************/
void CtrlPanel::updateGui()
{
    updateBanks();
    updateFixtures();
    updateScenes();
    updateFaders();
} // CtrlPanel::updateGui


/*******************************************************************************
* CtrlPanel::updateBanks
*******************************************************************************/
void CtrlPanel::updateBanks()
{
    for (u32 i = 0; i < BANK_COUNT; i++)
    {
        shared_ptr<Bank> pBank = bank(i);

        if (pBank)
        {
            m_vBankBtn.at(i)->setBtnText(pBank->name());
            m_vBankBtn.at(i)->setCtrlEnabled(true);
            m_vBankBtn.at(i)->setCtrlChecked(m_vBankBtn.at(i) == m_pActiveBankBtn);
        }
        else
        {
            m_vBankBtn.at(i)->setBtnText("");
            m_vBankBtn.at(i)->setCtrlEnabled(false);
            m_vBankBtn.at(i)->setCtrlChecked(false);
        }
    }
} // CtrlPanel::updateBanks


/*******************************************************************************
* CtrlPanel::updateFixtures
*******************************************************************************/
void CtrlPanel::updateFixtures()
{
} // CtrlPanel::updateFixtures


/*******************************************************************************
* CtrlPanel::updateScenes
*******************************************************************************/
void CtrlPanel::updateScenes()
{
} // CtrlPanel::updateScenes


/*******************************************************************************
* CtrlPanel::updateFaders
*******************************************************************************/
void CtrlPanel::updateFaders()
{
} // CtrlPanel::updateFaders


/*******************************************************************************
* CtrlPanel::onFaderMoved
*******************************************************************************/
void CtrlPanel::onFaderMoved(s32    _s32SliderIdx,
                             s32    _s32Value)
{
    shared_ptr<Universe>    pUniverse = activeUniverse();
    CHECK_PRE_CONDITION_VOID(pUniverse != nullptr);

    pUniverse->setDmxChannel(_s32SliderIdx + 1, _s32Value);
} // CtrlPanel::onFaderMoved


/*******************************************************************************
* CtrlPanel::onRegisterCtrl
*******************************************************************************/
void CtrlPanel::onRegisterCtrl()
{
    // add banks
    for (u32 i = 0; i < BANK_COUNT; i++)
    {
        registerCtrl(m_vBankBtn.at(i), ID_FIRST_BANK_IDX + i, true);
    }

    // add faders
    for (u32 i = 0; i < FADER_COUNT; i++)
    {
        registerCtrl(m_vFader.at(i), ID_FIRST_FADER_IDX + i, true);
    }
} // CtrlPanel::onRegisterCtrl


/*******************************************************************************
* CtrlPanel::onUpdateCtrl
*******************************************************************************/
void CtrlPanel::onUpdateCtrl(aCtrlI */*_pCtrl*/)
{
    // ViewBase    *pView  = getActiveView();
    // bool        bView   = (pView != nullptr);

    // switch (_pCtrl->ctrlId())
    // {
    //     case ID_ZOOM_FIT:
    //     case ID_ZOOM_100_PCNT:
    //     case ID_ZOOM_200_PCNT:
    //         _pCtrl->setCtrlEnabled(bView);
    //         break;
    // } // switch
} // CtrlPanel::onUpdateCtrl


/*******************************************************************************
* CtrlPanel::onCtrlClicked
*******************************************************************************/
void CtrlPanel::onCtrlClicked(aCtrlI *_pCtrl)
{
   u32 s32CtrlId = _pCtrl->ctrlId();

    // check for banks
    if (s32CtrlId >= ID_FIRST_BANK_IDX &&
        s32CtrlId < ID_FIRST_BANK_IDX + BANK_COUNT)
    {
        aPushButton *pBtn = dynamic_cast<aPushButton *> (_pCtrl);

        if (pBtn != nullptr && pBtn->isChecked())
        {
            m_pActiveBankBtn = pBtn;
        }
        else
        {
            m_pActiveBankBtn = nullptr;
        }

       getMainWin().sendUpdateCmd(UPDATE_GUI);
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
        s32CtrlId < ID_FIRST_FADER_IDX + FADER_COUNT)
    {
        // fader moved
        onFaderMoved(s32CtrlId - ID_FIRST_FADER_IDX, _s32Value);
    }

} // CtrlPanel::onCtrlValueChanged
