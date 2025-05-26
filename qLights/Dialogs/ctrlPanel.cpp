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
#include "scene.h"

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
* CtrlPanel::onCreateWin
*******************************************************************************/
bool CtrlPanel::onCreateWin()
{
    // bank controls
    m_vBankCtrl.push_back(bankTuple(m_pUi->m_pBank_01, nullptr));
    m_vBankCtrl.push_back(bankTuple(m_pUi->m_pBank_02, nullptr));
    m_vBankCtrl.push_back(bankTuple(m_pUi->m_pBank_03, nullptr));
    m_vBankCtrl.push_back(bankTuple(m_pUi->m_pBank_04, nullptr));
    m_vBankCtrl.push_back(bankTuple(m_pUi->m_pBank_05, nullptr));
    m_vBankCtrl.push_back(bankTuple(m_pUi->m_pBank_06, nullptr));
    m_vBankCtrl.push_back(bankTuple(m_pUi->m_pBank_07, nullptr));
    m_vBankCtrl.push_back(bankTuple(m_pUi->m_pBank_08, nullptr));
    m_vBankCtrl.push_back(bankTuple(m_pUi->m_pBank_09, nullptr));
    m_vBankCtrl.push_back(bankTuple(m_pUi->m_pBank_10, nullptr));

    // fixture controls
    m_vFixtureCtrl.push_back(fixtureTuple(m_pUi->m_pFixture_01));
    m_vFixtureCtrl.push_back(fixtureTuple(m_pUi->m_pFixture_02));
    m_vFixtureCtrl.push_back(fixtureTuple(m_pUi->m_pFixture_03));
    m_vFixtureCtrl.push_back(fixtureTuple(m_pUi->m_pFixture_04));
    m_vFixtureCtrl.push_back(fixtureTuple(m_pUi->m_pFixture_05));
    m_vFixtureCtrl.push_back(fixtureTuple(m_pUi->m_pFixture_06));
    m_vFixtureCtrl.push_back(fixtureTuple(m_pUi->m_pFixture_07));
    m_vFixtureCtrl.push_back(fixtureTuple(m_pUi->m_pFixture_08));
    m_vFixtureCtrl.push_back(fixtureTuple(m_pUi->m_pFixture_09));
    m_vFixtureCtrl.push_back(fixtureTuple(m_pUi->m_pFixture_10));

    // scene controls
    m_vSceneCtrl.push_back(sceneTuple(m_pUi->m_pScene_01, nullptr));
    m_vSceneCtrl.push_back(sceneTuple(m_pUi->m_pScene_02, nullptr));
    m_vSceneCtrl.push_back(sceneTuple(m_pUi->m_pScene_03, nullptr));
    m_vSceneCtrl.push_back(sceneTuple(m_pUi->m_pScene_04, nullptr));
    m_vSceneCtrl.push_back(sceneTuple(m_pUi->m_pScene_05, nullptr));
    m_vSceneCtrl.push_back(sceneTuple(m_pUi->m_pScene_06, nullptr));
    m_vSceneCtrl.push_back(sceneTuple(m_pUi->m_pScene_07, nullptr));
    m_vSceneCtrl.push_back(sceneTuple(m_pUi->m_pScene_08, nullptr));
    m_vSceneCtrl.push_back(sceneTuple(m_pUi->m_pScene_09, nullptr));
    m_vSceneCtrl.push_back(sceneTuple(m_pUi->m_pScene_10, nullptr));
    m_vSceneCtrl.push_back(sceneTuple(m_pUi->m_pScene_11, nullptr));
    m_vSceneCtrl.push_back(sceneTuple(m_pUi->m_pScene_12, nullptr));
    m_vSceneCtrl.push_back(sceneTuple(m_pUi->m_pScene_13, nullptr));
    m_vSceneCtrl.push_back(sceneTuple(m_pUi->m_pScene_14, nullptr));
    m_vSceneCtrl.push_back(sceneTuple(m_pUi->m_pScene_15, nullptr));
    m_vSceneCtrl.push_back(sceneTuple(m_pUi->m_pScene_16, nullptr));
    m_vSceneCtrl.push_back(sceneTuple(m_pUi->m_pScene_17, nullptr));
    m_vSceneCtrl.push_back(sceneTuple(m_pUi->m_pScene_18, nullptr));
    m_vSceneCtrl.push_back(sceneTuple(m_pUi->m_pScene_19, nullptr));
    m_vSceneCtrl.push_back(sceneTuple(m_pUi->m_pScene_20, nullptr));
    m_vSceneCtrl.push_back(sceneTuple(m_pUi->m_pScene_21, nullptr));
    m_vSceneCtrl.push_back(sceneTuple(m_pUi->m_pScene_22, nullptr));
    m_vSceneCtrl.push_back(sceneTuple(m_pUi->m_pScene_23, nullptr));
    m_vSceneCtrl.push_back(sceneTuple(m_pUi->m_pScene_24, nullptr));
    m_vSceneCtrl.push_back(sceneTuple(m_pUi->m_pScene_25, nullptr));
    m_vSceneCtrl.push_back(sceneTuple(m_pUi->m_pScene_26, nullptr));
    m_vSceneCtrl.push_back(sceneTuple(m_pUi->m_pScene_27, nullptr));
    m_vSceneCtrl.push_back(sceneTuple(m_pUi->m_pScene_28, nullptr));
    m_vSceneCtrl.push_back(sceneTuple(m_pUi->m_pScene_29, nullptr));
    m_vSceneCtrl.push_back(sceneTuple(m_pUi->m_pScene_30, nullptr));

    m_colButtonBg = m_pUi->m_pScene_01->backgroundColor();

    // fader controls
    m_vFader.push_back(faderTuple(m_pUi->m_pScribbleStrip_01, m_pUi->m_pFader_01, m_pUi->m_pNr_01, nullptr));
    m_vFader.push_back(faderTuple(m_pUi->m_pScribbleStrip_02, m_pUi->m_pFader_02, m_pUi->m_pNr_02, nullptr));
    m_vFader.push_back(faderTuple(m_pUi->m_pScribbleStrip_03, m_pUi->m_pFader_03, m_pUi->m_pNr_03, nullptr));
    m_vFader.push_back(faderTuple(m_pUi->m_pScribbleStrip_04, m_pUi->m_pFader_04, m_pUi->m_pNr_04, nullptr));
    m_vFader.push_back(faderTuple(m_pUi->m_pScribbleStrip_05, m_pUi->m_pFader_05, m_pUi->m_pNr_05, nullptr));
    m_vFader.push_back(faderTuple(m_pUi->m_pScribbleStrip_06, m_pUi->m_pFader_06, m_pUi->m_pNr_06, nullptr));
    m_vFader.push_back(faderTuple(m_pUi->m_pScribbleStrip_07, m_pUi->m_pFader_07, m_pUi->m_pNr_07, nullptr));
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


    for (auto tup : m_vFader)
    {
        (get<1> (tup))->setInverse(true);
    }

    m_masterFader = faderTuple(m_pUi->m_pScribbleStrip_M, m_pUi->m_pFader_M, m_pUi->m_pNr_M, nullptr);
    ScribbleStrip       *pScribble  = get<0>(m_masterFader);
    Fader               *pFader     = get<1>(m_masterFader);
    aLabel              *pLabel     = get<2>(m_masterFader);
    pScribble->setIcon(CHANNEL_ICN_BRIGHTNESS_ALL);
    pFader->setInverse(true);
    pFader->setValue(255);
    pLabel->setText("Mstr");

    createSetup();

    return true;
} // CtrlPanel::onCreateWin


/*******************************************************************************
* CtrlPanel::createSetup
*******************************************************************************/
void CtrlPanel::createSetup()
{
    // create the controller
    shared_ptr<Controller> pController = createController("Showtec NET-2/3 POCKET", "192.168.1.245", 2);

    // create a universe
    pController->addUniverse(1);

    // create the banks
    shared_ptr<Bank> pBank1 = createBank("KMC-1");
    assignBank(pBank1, 0);
    shared_ptr<Bank> pBank2 = createBank("KMC-2");
    assignBank(pBank2, 1);

    // eurolite-led-tmh-s90-de
    shared_ptr<Fixture> pFix1 = createFixture("TMH-s90", pController, 1, 1);
    assignFixture(pFix1, pBank1, 0);
    // the channels
    pFix1->createChannel(1, CHANNEL_ICN_PAN, false);
    pFix1->createChannel(2, CHANNEL_ICN_PAN_FINE, false);
    pFix1->createChannel(3, CHANNEL_ICN_TILT, false);
    pFix1->createChannel(4, CHANNEL_ICN_TILT_FINE, false);
    pFix1->createChannel(5, CHANNEL_ICN_PAN_TILT_SPEED, false);
    pFix1->createChannel(6, CHANNEL_ICN_BRIGHTNESS, true);
    pFix1->createChannel(7, CHANNEL_ICN_STROBE, false);
    pFix1->createChannel(8, CHANNEL_ICN_COLOR_WHEEL, false);
    pFix1->createChannel(9, CHANNEL_ICN_GOBO_STAT_01, false);
    pFix1->createChannel(10, CHANNEL_ICN_GOBO_ROT_01, false);
    pFix1->createChannel(11, CHANNEL_ICN_GOBO_ROT_SPEED, false);
    pFix1->createChannel(12, CHANNEL_ICN_FOCUS, false);
    pFix1->createChannel(13, CHANNEL_ICN_PRISMA, false);
    pFix1->createChannel(14, CHANNEL_ICN_FUNCTION_1, false);
    pFix1->createChannel(15, CHANNEL_ICN_RESET, false);
    // add brightness-channel to master channel
    m_vMasterChannel.push_back(pFix1->channel(6));

    // 16 channel mode
    shared_ptr<Fixture> pFix2 = createFixture("TMH-x4-16 l", pController, 1, 17);
    assignFixture(pFix2, pBank1, 1);
    // the channels
    pFix2->createChannel(1, CHANNEL_ICN_PAN, false);
    pFix2->createChannel(2, CHANNEL_ICN_PAN_FINE, false);
    pFix2->createChannel(3, CHANNEL_ICN_TILT, false);
    pFix2->createChannel(4, CHANNEL_ICN_TILT_FINE, false);
    pFix2->createChannel(5, CHANNEL_ICN_PAN_TILT_SPEED, false);
    pFix2->createChannel(6, CHANNEL_ICN_BRIGHTNESS, true);
    pFix2->createChannel(7, CHANNEL_ICN_STROBE, false);
    pFix2->createChannel(8, CHANNEL_ICN_RED, false);
    pFix2->createChannel(9, CHANNEL_ICN_GREEN, false);
    pFix2->createChannel(10, CHANNEL_ICN_BLUE, false);
    pFix2->createChannel(11, CHANNEL_ICN_WHITE, false);
    pFix2->createChannel(12, CHANNEL_ICN_ZOOM, false);
    pFix2->createChannel(14, CHANNEL_ICN_COLOR_SPEED, false);
    pFix2->createChannel(15, CHANNEL_ICN_FUNCTION_1, false);
    pFix2->createChannel(16, CHANNEL_ICN_RESET, false);
    // add brightness-channel to master channel
    m_vMasterChannel.push_back(pFix2->channel(6));


    // 16 channel mode
    shared_ptr<Fixture> pFix3 = createFixture("TMH-x4-16 r", pController, 1, 42);
    assignFixture(pFix3, pBank1, 2);
    // the channels
    pFix3->createChannel(1, CHANNEL_ICN_PAN, false);
    pFix3->createChannel(2, CHANNEL_ICN_PAN_FINE, false);
    pFix3->createChannel(3, CHANNEL_ICN_TILT, false);
    pFix3->createChannel(4, CHANNEL_ICN_TILT_FINE, false);
    pFix3->createChannel(5, CHANNEL_ICN_PAN_TILT_SPEED, false);
    pFix3->createChannel(6, CHANNEL_ICN_BRIGHTNESS, true);
    pFix3->createChannel(7, CHANNEL_ICN_STROBE, false);
    pFix3->createChannel(8, CHANNEL_ICN_RED, false);
    pFix3->createChannel(9, CHANNEL_ICN_GREEN, false);
    pFix3->createChannel(10, CHANNEL_ICN_BLUE, false);
    pFix3->createChannel(11, CHANNEL_ICN_WHITE, false);
    pFix3->createChannel(12, CHANNEL_ICN_ZOOM, false);
    pFix3->createChannel(14, CHANNEL_ICN_COLOR_SPEED, false);
    pFix3->createChannel(15, CHANNEL_ICN_FUNCTION_1, false);
    pFix3->createChannel(16, CHANNEL_ICN_RESET, false);
    // add brightness-channel to master channel
    m_vMasterChannel.push_back(pFix3->channel(6));

    // 24 channel mode
    // bank(1)->addFixture("TMH-x4-24", 0, 1, 17);
    // bank(1)->fixture(0)->addChannel(1, 0, CHANNEL_ICN_PAN);
    // bank(1)->fixture(0)->addChannel(2, 1, CHANNEL_ICN_PAN_FINE);
    // bank(1)->fixture(0)->addChannel(3, 2, CHANNEL_ICN_TILT);
    // bank(1)->fixture(0)->addChannel(4, 3, CHANNEL_ICN_TILT_FINE);
    // bank(1)->fixture(0)->addChannel(5, 4, CHANNEL_ICN_PAN_TILT_SPEED);
    // bank(1)->fixture(0)->addChannel(6, 5, CHANNEL_ICN_ZOOM);
    // bank(1)->fixture(0)->addChannel(7, 6, CHANNEL_ICN_BRIGHTNESS);
    // bank(1)->fixture(0)->addChannel(8, 7, CHANNEL_ICN_STROBE);
    // bank(1)->fixture(0)->addChannel(9, 8, CHANNEL_ICN_RED_1);
    // bank(1)->fixture(0)->addChannel(10, 9, CHANNEL_ICN_GREEN_1);
    // bank(1)->fixture(0)->addChannel(11, 10, CHANNEL_ICN_BLUE_1);
    // bank(1)->fixture(0)->addChannel(12, 11, CHANNEL_ICN_WHITE_1);
    // bank(1)->fixture(0)->addChannel(13, 12, CHANNEL_ICN_RED_2);
    // bank(1)->fixture(0)->addChannel(14, 13, CHANNEL_ICN_GREEN_2);
    // bank(1)->fixture(0)->addChannel(15, 14, CHANNEL_ICN_BLUE_2);
    // bank(1)->fixture(0)->addChannel(16, 15, CHANNEL_ICN_WHITE_2);
    // bank(1)->fixture(0)->addChannel(17, 16, CHANNEL_ICN_RED_3);
    // bank(1)->fixture(0)->addChannel(18, 17, CHANNEL_ICN_GREEN_3);
    // bank(1)->fixture(0)->addChannel(19, 18, CHANNEL_ICN_BLUE_3);
    // bank(1)->fixture(0)->addChannel(20, 19, CHANNEL_ICN_WHITE_3);
    // bank(1)->fixture(0)->addChannel(22, 21, CHANNEL_ICN_COLOR_SPEED);
    // bank(1)->fixture(0)->addChannel(23, 22, CHANNEL_ICN_FUNCTION_1);
    // bank(1)->fixture(0)->addChannel(24, 23, CHANNEL_ICN_RESET);

    // initial initialisation
    updateBankCtrls();
    updateFixtureCtrls();
    updateSceneCtrls();
    updateFaderCtrls();
} // CtrlPanel::createSetup


/*******************************************************************************
* CtrlPanel::createController
*******************************************************************************/
shared_ptr<Controller> CtrlPanel::createController(const aString   &_sName,
                                                   const aString   &_sIpAdr,
                                                   s32             _s32UniverseMax)
{
    shared_ptr<Controller> pCtrl = make_shared<Controller> (_sName, _sIpAdr, _s32UniverseMax);

    m_vController.push_back(pCtrl);

    return pCtrl;
} // CtrlPanel::createController


/*******************************************************************************
* CtrlPanel::createBank
*******************************************************************************/
shared_ptr<Bank> CtrlPanel::createBank(const aString &_sName)
{
    shared_ptr<Bank> pBank = make_shared<Bank> (_sName);

    m_vBank.push_back(pBank);

    return pBank;
} // CtrlPanel::createBank


/*******************************************************************************
* CtrlPanel::assignBank
*******************************************************************************/
void CtrlPanel::assignBank(shared_ptr<Bank> _pBank,
                           s32              _s32BankBtnIdx)
{
    std::get<1>(m_vBankCtrl.at((_s32BankBtnIdx))) = _pBank;
} // CtrlPanel::assignBank


/*******************************************************************************
* CtrlPanel::updateBankCtrls
*******************************************************************************/
void CtrlPanel::updateBankCtrls()
{
    for (bankTuple &bt : m_vBankCtrl)
    {
        auto pBankBtn   = std::get<0> (bt);
        auto pBank      = std::get<1> (bt);

        if (pBank)
        {
            pBankBtn->setBtnText(pBank->name());
            pBankBtn->setCtrlEnabled(true);
        }
        else
        {
            pBankBtn->setBtnText("");
            pBankBtn->setCtrlEnabled(false);
       }

       pBankBtn->setCtrlChecked(false);
    }
} // CtrlPanel::updateBankCtrls


/*******************************************************************************
* CtrlPanel::onBankSeleted
*******************************************************************************/
void CtrlPanel::onBankSeleted(s32 _s32BankBtnIdx)
{
    // set the active bank to nullptr
    m_pActiveBank = nullptr;

    for (s32 idx = 0; idx < BANK_MAX; idx++)
    {
        auto pBankBtn = std::get<0> (m_vBankCtrl.at(idx));

        if (idx == _s32BankBtnIdx)
        {
            if (pBankBtn->isChecked())
            {
                // button checked => set active bank
                m_pActiveBank = &m_vBankCtrl.at(idx);
            }
        }
        else
        {
            // deselect all other buttons
            pBankBtn->setCtrlChecked(_s32BankBtnIdx == idx);
        }
    }

    // update the fixture buttons
    updateFixtureCtrls();
} // CtrlPanel::onBankSeleted


/*******************************************************************************
* CtrlPanel::createFixture
*******************************************************************************/
shared_ptr<Fixture> CtrlPanel::createFixture(const aString          &_sName,
                                             shared_ptr<Controller> _pConroller,
                                             s32                    _s32UniverseId,
                                             s32                    _s32ChannelOs)
{
    shared_ptr<Fixture> pFix = make_shared<Fixture> (_sName,
                                                     _pConroller,
                                                     _s32UniverseId,
                                                     _s32ChannelOs);

    m_vFixture.push_back(pFix);

    return pFix;
} // CtrlPanel::createFixture


/*******************************************************************************
* CtrlPanel::assignFixture
*******************************************************************************/
void CtrlPanel::assignFixture(shared_ptr<Fixture>   _pFixture,
                              shared_ptr<Bank>      _pBank,
                              s32                   _s32FixtureBtnIdx)
{
    // assign the fixture to the bank
    _pBank->addFixture(_s32FixtureBtnIdx, _pFixture);

    updateFixtureCtrls();
} // CtrlPanel::assignFixture


/*******************************************************************************
* CtrlPanel::updateFixtureCtrls
*******************************************************************************/
void CtrlPanel::updateFixtureCtrls()
{
    // get the active bank
    shared_ptr<Bank>    pBank = (m_pActiveBank)?   std::get<1> (*m_pActiveBank) : nullptr;

    for (s32 i = 0; i < FIXTURE_MAX; i++)
    {
        auto pFixBtn = std::get<0> (m_vFixtureCtrl.at(i));

        // find the fixture for idx i
        shared_ptr<Fixture> pFix = (pBank)?   pBank->fixture(i) : nullptr;

        // set the button for the fixture
        pFixBtn->setCtrlChecked(false);
        if (pFix)
        {
            pFixBtn->setBtnText(pFix->name());
            pFixBtn->setCtrlEnabled(true);
        }
        else
        {
            pFixBtn->setBtnText("");
            pFixBtn->setCtrlEnabled(false);
        }
    } // for...

    m_pActiveFixture = nullptr;
} // CtrlPanel::updateFixtureCtrls


/*******************************************************************************
* CtrlPanel::onFixtureSeleted
*******************************************************************************/
void CtrlPanel::onFixtureSeleted(s32 /*_s32FixtureIdx*/)
{
    // CHECK_PRE_CONDITION_VOID(m_pActiveBank);
    // CHECK_PRE_CONDITION_VOID(_s32FixtureIdx < FIXTURE_MAX);

    // auto pFix = std::get<1>(*m_pActiveBank)->fixture(_s32FixtureIdx);

    // shared_ptr<Bank> pBank      = activeBank();
    // CHECK_PRE_CONDITION_VOID(pBank);

    // fixtureTuple     &fixture   = m_vFixture.at(_s32FixtureIdx);

    // // get the active bank
    // if (pBank->isChecked())
    // {
    //     m_pActiveFixture = &fixture;
    // }
    // else
    // {
    //     m_pActiveFixture = nullptr;
    // }

    // getMainWin().sendUpdateCmd(UPDATE_GUI);
} // CtrlPanel::onFixtureSeleted


/*******************************************************************************
* CtrlPanel::updateSceneCtrls
*******************************************************************************/
void CtrlPanel::updateSceneCtrls()
{
    for (sceneTuple &st : m_vSceneCtrl)
    {
        auto pSceneBtn   = std::get<0> (st);
        auto pScene      = std::get<1> (st);

        if (pScene)
        {
            pSceneBtn->setBtnText(pScene->name());
            pSceneBtn->setCtrlEnabled(true);
        }
        else
        {
            pSceneBtn->setBtnText("");
            pSceneBtn->setCtrlEnabled(false);
        }

        pSceneBtn->setCtrlChecked(false);
    }
} // CtrlPanel::updateSceneCtrls


/*******************************************************************************
* CtrlPanel::onSceneSelected
*******************************************************************************/
void CtrlPanel::onSceneSelected(s32 /*_s32SceneBtnIdx*/)
{
    // MainWin     &mw = getMainWin();

    // switch (mw.workMode())
    // {
    //     case enumWorkMode::Play:
    //         break;

    //     case enumWorkMode::SaveScene:
    //         mw.setMode(enumWorkMode::Play);
    //         break;
    // }
} // CtrlPanel::onSceneSelected


/*******************************************************************************
* CtrlPanel::updateFaderCtrls
*******************************************************************************/
void CtrlPanel::updateFaderCtrls()
{
    // update the faders
    for (s32 s32FaderIdx = 0; s32FaderIdx < FADER_MAX; s32FaderIdx++)
    {
        ScribbleStrip       *pScribble  = get<0>(m_vFader.at(s32FaderIdx));
        Fader               *pFader     = get<1>(m_vFader.at(s32FaderIdx));
        aLabel              *pLabel     = get<2>(m_vFader.at(s32FaderIdx));
        shared_ptr<Channel> pChannel    = get<3>(m_vFader.at(s32FaderIdx));

        if (pChannel)
        {
            pScribble->setIcon(pChannel->channelIcon());
            pFader->setEnabled(true);
            pLabel->setText(aString::fromValue(s32FaderIdx + 1));

            pFader->setValue(pChannel->value());
        }
        else
        {
            pScribble->setIcon("");
            pFader->setEnabled(false);
            pLabel->setText(aString(""));

            pFader->setValue(0);
        }

        std::get<0>(m_vFader.at(s32FaderIdx))->update();
    }
} // CtrlPanel::updateFaderCtrls


/*******************************************************************************
* CtrlPanel::updateGui
*******************************************************************************/
void CtrlPanel::updateGui()
{
    updateScenes();
    updateFaders();
    updateBlackoutButton();
} // CtrlPanel::updateGui


/*******************************************************************************
* CtrlPanel::updateScenes
*******************************************************************************/
void CtrlPanel::updateScenes()
{
    // MainWin     &mw = getMainWin();

    // for (s32 i = 0; i < SCENE_MAX; i++)
    // {
    //     aPushButton *pSceneBtn = std::get<0>(m_vScene.at(i));
    //     aString     sSceneName = std::get<1>(m_vScene.at(i));

    //     // set background
    //     if (mw.workMode() == enumWorkMode::SaveScene)
    //     {
    //         pSceneBtn->setBackgroundColor(colDarkGoldenRod);
    //     }
    //     else
    //     {
    //         pSceneBtn->setBackgroundColor(m_colButtonBg);
    //     }

    //     // set scene names
    //     pSceneBtn->setText(sSceneName);
    // }
} // CtrlPanel::updateScenes


/*******************************************************************************
* CtrlPanel::updateFaders
*******************************************************************************/
void CtrlPanel::updateFaders()
{
    // shared_ptr<Fixture> pFix = activeFixture();

    // // update the faders
    // for (s32 s32FaderIdx = 0; s32FaderIdx < FADER_MAX; s32FaderIdx++)
    // {
    //     ScribbleStrip       *pScribble  = get<0>(m_vFader.at(s32FaderIdx));
    //     Fader               *pFader     = get<1>(m_vFader.at(s32FaderIdx));
    //     aLabel              *pLabel     = get<2>(m_vFader.at(s32FaderIdx));
    //     shared_ptr<Channel> pChannel    = (pFix)?   pFix->channel(s32FaderIdx) : nullptr;

    //     if (pChannel)
    //     {
    //         pScribble->setIcon(pChannel->channelIcon());
    //         pFader->setEnabled(true);
    //         pLabel->setText(aString::fromValue(s32FaderIdx + 1));

    //         pFader->setValue(pChannel->value());
    //     }
    //     else
    //     {
    //         pScribble->setIcon("");
    //         pFader->setEnabled(false);
    //         pLabel->setText(aString(""));

    //         pFader->setValue(0);
    //     }

    //     std::get<0>(m_vFader.at(s32FaderIdx))->update();
    // }
} // CtrlPanel::updateFaders


/*******************************************************************************
* CtrlPanel::updateBlackoutButton
*******************************************************************************/
void CtrlPanel::updateBlackoutButton()
{
    if (m_dMasterBrightness > 0)
    {
        m_pUi->m_pBlackout->setBackgroundColor(colBlack);
    }
    else
    {
        m_pUi->m_pBlackout->setBackgroundColor(aColor::fromU8(255, 255,128, 255));
    }
} // CtrlPanel::updateBlackoutButton


/*******************************************************************************
* CtrlPanel::onFaderMoved
*******************************************************************************/
void CtrlPanel::onFaderMoved(s32    s32FaderIdx,
                             s32    _s32Value)
{
    CHECK_PRE_CONDITION_VOID(m_pActiveFixture);

    auto pChannel = std::get<3>(m_vFader.at(s32FaderIdx));
    CHECK_PRE_CONDITION_VOID(pChannel);

    pChannel->setValue(static_cast<u8> (_s32Value), true);
} // CtrlPanel::onFaderMoved


/*******************************************************************************
* CtrlPanel::onMasterFaderMoved
*******************************************************************************/
void CtrlPanel::onMasterFaderMoved(s32 /*_s32Value*/)
{
    //m_dMasterBrightness = ((dbl) (_s32Value)) / 255.;
    //s32 s32Size = m_vMasterChannel.size();

    // for (s32 i = 0; i < s32Size; i++)
    // {
    //     updateDmxValue(m_vMasterChannel.at(i), i == s32Size-1);
    // }

    // updateBlackoutButton();
} // CtrlPanel::onMasterFaderMoved


/*******************************************************************************
* CtrlPanel::onBlackoutClicked
*******************************************************************************/
void CtrlPanel::onBlackoutClicked()
{
    Fader   *pFader     = get<1>(m_masterFader);

    if (m_dMasterBrightness > 0)
    {
        pFader->setValue(0);
        m_dMasterBrightness = 0;
    }
    else
    {
        pFader->setValue(255);
        m_dMasterBrightness = 1;
    }

    updateBlackoutButton();
} // CtrlPanel::onBlackoutClicked


/*******************************************************************************
* CtrlPanel::resetAll
*******************************************************************************/
void CtrlPanel::resetAll()
{
    // // reset all banks->fixtures->channels
    // for (auto &bankTuple : m_vBank)
    // {
    //     shared_ptr<Bank> pBank = std::get<1>(bankTuple);

    //     if (pBank)
    //     {
    //         pBank->resetAll();
    //     }
    // }

    // // reset all universes
    // for (shared_ptr<Controller> &pController : m_vController)
    // {
    //     pController->resetAllUniverses();
    // }
} // CtrlPanel::resetAll
