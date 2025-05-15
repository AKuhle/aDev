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
#include "controller.h"
#include "universe.h"
#include "fixture.h"
#include "channel.h"

//#include "dlgAddBank.h"


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
} // CtrlPanel::~CtrlPanel


/*******************************************************************************
* CtrlPanel::controller
*******************************************************************************/
shared_ptr<Controller> CtrlPanel::controller(s32 _idx) const
{
    if (_idx < m_vController.size())
    {
        return m_vController.at(_idx);
    }

    return nullptr;
} // ~CtrlPanel::controller


/*******************************************************************************
* CtrlPanel::onCreateWin
*******************************************************************************/
bool CtrlPanel::onCreateWin()
{
    // bank controls
    m_vBank.push_back(bankTuple(m_pUi->m_pBank_01, nullptr));
    m_vBank.push_back(bankTuple(m_pUi->m_pBank_02, nullptr));
    m_vBank.push_back(bankTuple(m_pUi->m_pBank_03, nullptr));
    m_vBank.push_back(bankTuple(m_pUi->m_pBank_04, nullptr));
    m_vBank.push_back(bankTuple(m_pUi->m_pBank_05, nullptr));
    m_vBank.push_back(bankTuple(m_pUi->m_pBank_06, nullptr));
    m_vBank.push_back(bankTuple(m_pUi->m_pBank_07, nullptr));
    m_vBank.push_back(bankTuple(m_pUi->m_pBank_08, nullptr));
    m_vBank.push_back(bankTuple(m_pUi->m_pBank_09, nullptr));
    m_vBank.push_back(bankTuple(m_pUi->m_pBank_10, nullptr));

    // fixture controls
    m_vFixtureBtn.push_back(m_pUi->m_pFixture_01);
    m_vFixtureBtn.push_back(m_pUi->m_pFixture_02);
    m_vFixtureBtn.push_back(m_pUi->m_pFixture_03);
    m_vFixtureBtn.push_back(m_pUi->m_pFixture_04);
    m_vFixtureBtn.push_back(m_pUi->m_pFixture_05);
    m_vFixtureBtn.push_back(m_pUi->m_pFixture_06);
    m_vFixtureBtn.push_back(m_pUi->m_pFixture_07);
    m_vFixtureBtn.push_back(m_pUi->m_pFixture_08);
    m_vFixtureBtn.push_back(m_pUi->m_pFixture_09);
    m_vFixtureBtn.push_back(m_pUi->m_pFixture_10);

    // fader controls
    m_vFader.push_back(faderTuple(m_pUi->m_pScribbleStrip_01, m_pUi->m_pFader_01, m_pUi->m_pNr_01, nullptr));
    m_vFader.push_back(faderTuple(m_pUi->m_pScribbleStrip_02, m_pUi->m_pFader_02, m_pUi->m_pNr_02, nullptr));
    m_vFader.push_back(faderTuple(m_pUi->m_pScribbleStrip_03, m_pUi->m_pFader_03, m_pUi->m_pNr_03, nullptr));
    m_vFader.push_back(faderTuple(m_pUi->m_pScribbleStrip_04, m_pUi->m_pFader_04, m_pUi->m_pNr_04, nullptr));
    m_vFader.push_back(faderTuple(m_pUi->m_pScribbleStrip_05, m_pUi->m_pFader_05, m_pUi->m_pNr_05, nullptr));
    m_vFader.push_back(faderTuple(m_pUi->m_pScribbleStrip_06, m_pUi->m_pFader_06, m_pUi->m_pNr_06, nullptr));
    m_vFader.push_back(faderTuple(m_pUi->m_pScribbleStrip_07, m_pUi->m_pFader_07, m_pUi->m_pNr_01, nullptr));
    m_vFader.push_back(faderTuple(m_pUi->m_pScribbleStrip_08, m_pUi->m_pFader_08, m_pUi->m_pNr_08, nullptr));
    m_vFader.push_back(faderTuple(m_pUi->m_pScribbleStrip_09, m_pUi->m_pFader_09, m_pUi->m_pNr_09, nullptr));
    m_vFader.push_back(faderTuple(m_pUi->m_pScribbleStrip_10, m_pUi->m_pFader_10, m_pUi->m_pNr_10, nullptr));
    m_vFader.push_back(faderTuple(m_pUi->m_pScribbleStrip_11, m_pUi->m_pFader_11, m_pUi->m_pNr_11, nullptr));
    m_vFader.push_back(faderTuple(m_pUi->m_pScribbleStrip_12, m_pUi->m_pFader_12, m_pUi->m_pNr_12, nullptr));
    m_vFader.push_back(faderTuple(m_pUi->m_pScribbleStrip_13, m_pUi->m_pFader_13, m_pUi->m_pNr_13, nullptr));
    m_vFader.push_back(faderTuple(m_pUi->m_pScribbleStrip_14, m_pUi->m_pFader_14, m_pUi->m_pNr_14, nullptr));
    m_vFader.push_back(faderTuple(m_pUi->m_pScribbleStrip_15, m_pUi->m_pFader_15, m_pUi->m_pNr_15, nullptr));
    m_vFader.push_back(faderTuple(m_pUi->m_pScribbleStrip_16, m_pUi->m_pFader_16, m_pUi->m_pNr_16, nullptr));
    m_vFader.push_back(faderTuple(m_pUi->m_pScribbleStrip_17, m_pUi->m_pFader_17, m_pUi->m_pNr_17, nullptr));
    m_vFader.push_back(faderTuple(m_pUi->m_pScribbleStrip_18, m_pUi->m_pFader_18, m_pUi->m_pNr_18, nullptr));
    m_vFader.push_back(faderTuple(m_pUi->m_pScribbleStrip_19, m_pUi->m_pFader_19, m_pUi->m_pNr_19, nullptr));
    m_vFader.push_back(faderTuple(m_pUi->m_pScribbleStrip_20, m_pUi->m_pFader_20, m_pUi->m_pNr_20, nullptr));
    m_vFader.push_back(faderTuple(m_pUi->m_pScribbleStrip_21, m_pUi->m_pFader_21, m_pUi->m_pNr_21, nullptr));
    m_vFader.push_back(faderTuple(m_pUi->m_pScribbleStrip_22, m_pUi->m_pFader_22, m_pUi->m_pNr_22, nullptr));
    m_vFader.push_back(faderTuple(m_pUi->m_pScribbleStrip_23, m_pUi->m_pFader_23, m_pUi->m_pNr_23, nullptr));
    m_vFader.push_back(faderTuple(m_pUi->m_pScribbleStrip_24, m_pUi->m_pFader_24, m_pUi->m_pNr_24, nullptr));

    createSetup();

    return true;
} // CtrlPanel::onCreateWin


/*******************************************************************************
* CtrlPanel::createSetup
*******************************************************************************/
void CtrlPanel::createSetup()
{
    // create the controller
    addController("Showtec NET-2/3 POCKET", "192.168.1.245", 2);

    // create a universe
    m_vController.at(0)->addUniverse(1);

    // create a bank
    addBank("KMC-1");
    addBank("KMC-2");

    bank(0)->addFixture("TMH-x4-16", 0, 1, 17);
    bank(1)->addFixture("TMH-x4-24", 0, 1, 17);

    // 16 channel mode
    bank(0)->fixture(0)->addChannel(1, 0, CHANNEL_ICN_PAN);
    bank(0)->fixture(0)->addChannel(2, 1, CHANNEL_ICN_PAN_FINE);
    bank(0)->fixture(0)->addChannel(3, 2, CHANNEL_ICN_TILT);
    bank(0)->fixture(0)->addChannel(4, 3, CHANNEL_ICN_TILT_FINE);
    bank(0)->fixture(0)->addChannel(5, 4, CHANNEL_ICN_PAN_TILT_SPEED);
    bank(0)->fixture(0)->addChannel(6, 5, CHANNEL_ICN_BRIGHTNESS);
    bank(0)->fixture(0)->addChannel(7, 6, CHANNEL_ICN_STROBE);
    bank(0)->fixture(0)->addChannel(8, 7, CHANNEL_ICN_RED);
    bank(0)->fixture(0)->addChannel(9, 8, CHANNEL_ICN_GREEN);
    bank(0)->fixture(0)->addChannel(10, 9, CHANNEL_ICN_BLUE);
    bank(0)->fixture(0)->addChannel(11, 10, CHANNEL_ICN_WHITE);
    bank(0)->fixture(0)->addChannel(12, 11, CHANNEL_ICN_ZOOM);
    bank(0)->fixture(0)->addChannel(14, 13, CHANNEL_ICN_COLOR_SPEED);
    bank(0)->fixture(0)->addChannel(15, 14, CHANNEL_ICN_FUNCTION_1);
    bank(0)->fixture(0)->addChannel(16, 15, CHANNEL_ICN_RESET);

    // 16 channel mode
    bank(1)->fixture(0)->addChannel(1, 0, CHANNEL_ICN_PAN);
    bank(1)->fixture(0)->addChannel(2, 1, CHANNEL_ICN_PAN_FINE);
    bank(1)->fixture(0)->addChannel(3, 2, CHANNEL_ICN_TILT);
    bank(1)->fixture(0)->addChannel(4, 3, CHANNEL_ICN_TILT_FINE);
    bank(1)->fixture(0)->addChannel(5, 4, CHANNEL_ICN_PAN_TILT_SPEED);
    bank(1)->fixture(0)->addChannel(6, 5, CHANNEL_ICN_ZOOM);
    bank(1)->fixture(0)->addChannel(7, 6, CHANNEL_ICN_BRIGHTNESS);
    bank(1)->fixture(0)->addChannel(8, 7, CHANNEL_ICN_STROBE);
    bank(1)->fixture(0)->addChannel(9, 8, CHANNEL_ICN_RED_1);
    bank(1)->fixture(0)->addChannel(10, 9, CHANNEL_ICN_GREEN_1);
    bank(1)->fixture(0)->addChannel(11, 10, CHANNEL_ICN_BLUE_1);
    bank(1)->fixture(0)->addChannel(12, 11, CHANNEL_ICN_WHITE_1);
    bank(1)->fixture(0)->addChannel(13, 12, CHANNEL_ICN_RED_2);
    bank(1)->fixture(0)->addChannel(14, 13, CHANNEL_ICN_GREEN_2);
    bank(1)->fixture(0)->addChannel(15, 14, CHANNEL_ICN_BLUE_2);
    bank(1)->fixture(0)->addChannel(16, 15, CHANNEL_ICN_WHITE_2);
    bank(1)->fixture(0)->addChannel(17, 16, CHANNEL_ICN_RED_3);
    bank(1)->fixture(0)->addChannel(18, 17, CHANNEL_ICN_GREEN_3);
    bank(1)->fixture(0)->addChannel(19, 18, CHANNEL_ICN_BLUE_3);
    bank(1)->fixture(0)->addChannel(20, 19, CHANNEL_ICN_WHITE_3);
    bank(1)->fixture(0)->addChannel(22, 21, CHANNEL_ICN_COLOR_SPEED);
    bank(1)->fixture(0)->addChannel(23, 22, CHANNEL_ICN_FUNCTION_1);
    bank(1)->fixture(0)->addChannel(24, 23, CHANNEL_ICN_RESET);

    // initial fader initialisation
    onFixtureSeleted(0);
} // CtrlPanel::createSetup


/*******************************************************************************
* CtrlPanel::addBank
*******************************************************************************/
void CtrlPanel::addBank(const aString &_sName)
{
    for (s32 i = 0; i < BANK_MAX; i++)
    {
        bankTuple &bt = m_vBank.at(i);

        if (get<1> (bt) == nullptr)
        {
            get<1> (bt) = make_shared<Bank> (_sName);

            getMainWin().sendUpdateCmd(UPDATE_GUI);

            return;
        }
    }
} // CtrlPanel::addBank


/*******************************************************************************
* CtrlPanel::activeBankBtn
*******************************************************************************/
aPushButton* CtrlPanel::activeBankBtn() const
{
    if (m_pActiveBank)
    {
        return std::get<0>(*m_pActiveBank);
    }

    return nullptr;
} // CtrlPanel::activeBankBtn


/*******************************************************************************
* CtrlPanel::bankBtn
*******************************************************************************/
aPushButton* CtrlPanel::bankBtn(s32 _idx) const
{
    if (_idx < m_vBank.size())
    {
        return std::get<0>(m_vBank.at(_idx));
    }

    return nullptr;
} // CtrlPanel::bankBtn


/*******************************************************************************
* CtrlPanel::activeBank
*******************************************************************************/
shared_ptr<Bank> CtrlPanel::activeBank() const
{
    if (m_pActiveBank)
    {
        return std::get<1>(*m_pActiveBank);
    }

    return nullptr;
} // CtrlPanel::activeBank


/*******************************************************************************
* CtrlPanel::bank
*******************************************************************************/
shared_ptr<Bank> CtrlPanel::bank(s32 _idx) const
{
    if (_idx < m_vBank.size())
    {
        return std::get<1>(m_vBank.at(_idx));
    }

    return nullptr;
} // CtrlPanel::bank


/*******************************************************************************
* CtrlPanel::activeFixtureBtn
*******************************************************************************/
aPushButton* CtrlPanel::activeFixtureBtn() const
{
    return m_pActiveFixtureBtn;
} // CtrlPanel::activeFixtureBtn


/*******************************************************************************
* CtrlPanel::fixtureBtn
*******************************************************************************/
aPushButton* CtrlPanel::fixtureBtn(s32 _idx) const
{
    if (_idx < m_vFixtureBtn.size())
    {
        return m_vFixtureBtn.at(_idx);
    }

    return nullptr;
} // CtrlPanel::fixtureBtn


/*******************************************************************************
* CtrlPanel::activeFixture
*******************************************************************************/
shared_ptr<Fixture> CtrlPanel::activeFixture() const
{
    return m_pActiveFixture;
} // CtrlPanel::activeFixture


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
* CtrlPanel::addController
*******************************************************************************/
void CtrlPanel::addController(const aString &_sName,
                              const aString &_sIpAdr,
                              s32           _s32UniverseMax)
{
    m_vController.push_back(make_shared<Controller> (_sName, _sIpAdr, _s32UniverseMax));
} // CtrlPanel::addController


/*******************************************************************************
* CtrlPanel::updateBanks
*******************************************************************************/
void CtrlPanel::updateBanks()
{
    for (s32 i = 0; i < BANK_MAX; i++)
    {
        auto pActiveBankBtn = activeBankBtn();
        auto pBankBtn = bankBtn(i);
        auto pBank = bank(i);

        if (pBank)
        {
            pBankBtn->setBtnText(pBank->name());
            pBankBtn->setCtrlEnabled(true);
            pBankBtn->setCtrlChecked(pBankBtn == pActiveBankBtn);
        }
        else
        {
            pBankBtn->setBtnText("");
            pBankBtn->setCtrlEnabled(false);
            pBankBtn->setCtrlChecked(false);
        }
    }
} // CtrlPanel::updateBanks


/*******************************************************************************
* CtrlPanel::updateFixtures
*******************************************************************************/
void CtrlPanel::updateFixtures()
{
    shared_ptr<Bank> pBank = activeBank();

    for (s32 i = 0; i < FIXTURE_MAX; i++)
    {
        auto pActiveFixtureBtn = activeFixtureBtn();
        auto pBtn = fixtureBtn(i);
        auto pFixture = (pBank)?   pBank->fixture(i) : nullptr;

        if (pFixture)
        {
            pBtn->setBtnText(pFixture->name());
            pBtn->setCtrlEnabled(true);
            pBtn->setCtrlChecked(pBtn == pActiveFixtureBtn);
        }
        else
        {
            pBtn->setBtnText("");
            pBtn->setCtrlEnabled(false);
            pBtn->setCtrlChecked(false);
        }
    }
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
    for (s32 i = 0; i < FADER_MAX; i++)
    {
        std::get<0>(m_vFader.at(i))->update();
    }
} // CtrlPanel::updateFaders


/*******************************************************************************
* CtrlPanel::onFaderMoved
*******************************************************************************/
void CtrlPanel::onFaderMoved(s32    s32FaderIdx,
                             s32    _s32Value)
{
    shared_ptr<Fixture> pFix = activeFixture();
    CHECK_PRE_CONDITION_VOID(pFix);

    shared_ptr<Controller> pController = controller(pFix->controllerIdx());
    CHECK_PRE_CONDITION_VOID(pController);

    shared_ptr<Universe> pUniverse = pController->universe(pFix->universeId());
    CHECK_PRE_CONDITION_VOID(pUniverse);

    shared_ptr<Channel> pChannel = pFix->channel(s32FaderIdx);
    CHECK_PRE_CONDITION_VOID(pChannel);

    pUniverse->setDmxChannel(pFix->channelOs(), pChannel->channelNr(), (u8) _s32Value, true);
} // CtrlPanel::onFaderMoved


/*******************************************************************************
* CtrlPanel::onRegisterCtrl
*******************************************************************************/
void CtrlPanel::onRegisterCtrl()
{
    // add banks
    for (u32 i = 0; i < BANK_MAX; i++)
    {
        auto pBankBtn = std::get<0>(m_vBank.at(i));
        registerCtrl(pBankBtn, ID_FIRST_BANK_IDX + i, true);
    }

    // add fixtures
    for (u32 i = 0; i < FIXTURE_MAX; i++)
    {
        registerCtrl(m_vFixtureBtn.at(i), ID_FIRST_FIXTURE_IDX + i, true);
    }

    // add faders
    for (u32 iFaderIdx = 0; iFaderIdx < FADER_MAX; iFaderIdx++)
    {
        registerCtrl(get<1>(m_vFader.at(iFaderIdx)), ID_FIRST_FADER_IDX + iFaderIdx, true);
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
       s32CtrlId < ID_FIRST_BANK_IDX + BANK_MAX)
   {
       onBankSeleted(s32CtrlId - ID_FIRST_BANK_IDX);
   }

   // check for fixture
   if (s32CtrlId >= ID_FIRST_FIXTURE_IDX &&
       s32CtrlId < ID_FIRST_FIXTURE_IDX + FIXTURE_MAX)
   {
       onFixtureSeleted(s32CtrlId - ID_FIRST_FIXTURE_IDX);
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

} // CtrlPanel::onCtrlValueChanged


/*******************************************************************************
* CtrlPanel::onBankSeleted
*******************************************************************************/
void CtrlPanel::onBankSeleted(s32 _s32BankIdx)
{
    bankTuple &bt = m_vBank.at(_s32BankIdx);

    // get the active bank
    if (get<0> (bt)->isChecked())
    {
        m_pActiveBank = &bt;
    }
    else
    {
        m_pActiveBank = nullptr;
    }

    // deselect active fixture
    m_pActiveFixtureBtn = nullptr;
    m_pActiveFixture = nullptr;

    getMainWin().sendUpdateCmd(UPDATE_GUI);
} // CtrlPanel::onBankSeleted


/*******************************************************************************
* CtrlPanel::onFixtureSeleted
*******************************************************************************/
void CtrlPanel::onFixtureSeleted(s32 _s32FixtureIdx)
{
    shared_ptr<Bank> pBank          = activeBank();
    aPushButton     *pFixtureBtn    = m_vFixtureBtn.at(_s32FixtureIdx);
    s32             s32FaderIdx;

    // get the active bank
    if (pFixtureBtn->isChecked())
    {
        m_pActiveFixtureBtn = pFixtureBtn;
        m_pActiveFixture = (pBank)?   pBank->fixture(_s32FixtureIdx) : nullptr;
    }
    else
    {
        m_pActiveFixtureBtn = nullptr;
        m_pActiveFixture = nullptr;
    }

    // update the faders
    for (s32FaderIdx = 0; s32FaderIdx < FADER_MAX; s32FaderIdx++)
    {
        ScribbleStrip       *pScribble  = get<0>(m_vFader.at(s32FaderIdx));
        Fader               *pFader     = get<1>(m_vFader.at(s32FaderIdx));
        aLabel              *pLabel     = get<2>(m_vFader.at(s32FaderIdx));
        shared_ptr<Channel> pChannel    = (m_pActiveFixture)?   m_pActiveFixture->channel(s32FaderIdx) : nullptr;

        if (pChannel)
        {
            pScribble->setIcon(pChannel->channelIcon());
            pFader->setEnabled(true);
            pLabel->setText(aString::fromValue(s32FaderIdx + 1));
        }
        else
        {
            pScribble->setIcon("");
            pFader->setEnabled(false);
            pLabel->setText(aString(""));
        }
    }

    getMainWin().sendUpdateCmd(UPDATE_GUI);
} // CtrlPanel::onFixtureSeleted
