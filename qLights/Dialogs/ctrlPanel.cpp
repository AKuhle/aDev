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
#include "aJsonFile.h"

#include "qLights_defs.h"
#include "mainWin.h"
#include "ctrlPanel.h"
#include "controller.h"
#include "universe.h"
#include "fixture.h"
#include "channel.h"
#include "scene.h"

using namespace aLib::aUtil;


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

    //createSetup();

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
    assignBank(pBank2, 4);

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
    // bank(1)->addFixture("TMH-x4-24", 0, 1, 42);
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
* CtrlPanel::setConfiguration
*******************************************************************************/
void CtrlPanel::setConfiguration(aMap<aString, controllerIoInfo>    &_mapControllerIoInfo,
                                 aMap<aString, bankIoInfo>          &_mapBankIoInfo,
                                 aMap<aString, fixtureIoInfo>       &_mapFixtureIoInfo,
                                 aMap<aString, sceneIoInfo>         &_mapSceneIoInfo)
{
    // clear previous configuration
    m_vController.clear();
    m_vBank.clear();
    m_pActiveBank = nullptr;
    m_vFixture.clear();
    m_pActiveFixture = nullptr;
    m_vMasterChannel.clear();
    for (sceneTuple &t : m_vSceneCtrl)
    {
        std::get<1> (t) = nullptr;
    }

    // create controller/universes
    for (auto me : _mapControllerIoInfo)
    {
        controllerIoInfo &ci = me.second;

        aString                         sCtrlName   = std::get<0> (ci);
        aString                         sCtrlAdress = std::get<1> (ci);
        s32                             s32CtrlUniMax = std::get<2> (ci);

        shared_ptr<Controller> pController = createController(sCtrlName, sCtrlAdress, s32CtrlUniMax);

        // generate the universes
        aMap<aString, universeIoInfo>   &mapUni = std::get<3> (ci);
        for (auto uniME : mapUni)
        {
            universeIoInfo &ui = uniME.second;

            s32         s32UniId    = std::get<0> (ui);
            //QByteArray  &ba         = std::get<1> (ui);

            pController->addUniverse(s32UniId);
        }
    } // for (auto me : m_mapControllerIoInfo)


    // create the banks
    for (auto me : _mapBankIoInfo)
    {
        bankIoInfo &bi = me.second;

        aString sBankName = std::get<0> (bi);
        s32 s32BnkBtnIdx = std::get<1> (bi);

        shared_ptr<Bank> pBank1 = createBank(sBankName);
        assignBank(pBank1, s32BnkBtnIdx);
    }


    // create the features
     for (auto me : _mapFixtureIoInfo)
    {
        fixtureIoInfo &fi = me.second;

        aString     sFixName            = std::get<0> (fi);
        aString     sFixControllerName  = std::get<1> (fi);
        s32         s32FixUniverseId    = std::get<2> (fi);
        s32         s32FixChannelOs     = std::get<3> (fi);
        aString     sFixBank            = std::get<4> (fi);
        s32         s32FixBtnIdx        = std::get<5> (fi);

        shared_ptr<Controller>  pController = findController(sFixControllerName);
        shared_ptr<Bank>        pBank       = findBank(sFixBank);

        if (pController)
        {
            // create the fixture
            shared_ptr<Fixture> pFix = createFixture(sFixName, pController, s32FixUniverseId, s32FixChannelOs);
            assignFixture(pFix, pBank, s32FixBtnIdx);

            for (auto ci : std::get<6> (fi))
            {
                aString sControllerName         = std::get<0> (ci.second);
                s32     s32ChannelNr            = std::get<1> (ci.second);
                aString sChannelIcon            = std::get<2> (ci.second);
                bool    bChannelBrightness      = std::get<3> (ci.second);

                // create the channel
                shared_ptr<Channel> pChannel = pFix->createChannel(s32ChannelNr, sChannelIcon, bChannelBrightness);

                // add brightness-channel to master channel
                if (bChannelBrightness)
                {
                    m_vMasterChannel.push_back(pChannel);
                }
            }
        }
    }


    // create the scenes
    for (auto me : m_mapSceneIoInfo)
    {
        aVector<channelValueTuple>  vtuple;
        sceneIoInfo                 &si             = me.second;

        s32                         s32Idx          = std::get<0> (si);
        aString                     sSceneName      = std::get<1> (si);
        aString                     sControllerName = std::get<2> (si);
        s32                         s32UniverseId   = std::get<3> (si);
        s32                         s32ChannelNr    = std::get<4> (si);
        s32                         s32ChannelOs    = std::get<5> (si);
        u8                          u8Value         = std::get<6> (si);

        shared_ptr<Channel>         pChannel        = findChannel(sControllerName,
                                                                  s32UniverseId,
                                                                  s32ChannelNr,
                                                                  s32ChannelOs);
        // shared_ptr<Bank> pBank1 = createBank(sBankName);
        // assignBank(pBank1, s32BnkBtnIdx);
    }

    // initial initialisation
    updateBankCtrls();
    updateFixtureCtrls();
    updateSceneCtrls();
    updateFaderCtrls();
} // CtrlPanel::setConfiguration


/*******************************************************************************
* CtrlPanel::findController
*******************************************************************************/
shared_ptr<Controller> CtrlPanel::findController(const aString &_sControllerName) const
{
    for (shared_ptr<Controller> pCtrl : m_vController)
    {
        if (pCtrl->name() == _sControllerName)
        {
            return pCtrl;
        }
    }

    return nullptr;
} // CtrlPanel::findController


/*******************************************************************************
* CtrlPanel::findBank
*******************************************************************************/
shared_ptr<Bank> CtrlPanel::findBank(const aString &_sBankName) const
{
    for (shared_ptr<Bank> pBank : m_vBank)
    {
        if (pBank->name() == _sBankName)
        {
            return pBank;
        }
    }

    return nullptr;
} // CtrlPanel::findBank


/*******************************************************************************
* CtrlPanel::findBank4Fixture
*******************************************************************************/
bool CtrlPanel::findBank4Fixture(shared_ptr<Fixture>    _pFix,
                                 shared_ptr<Bank>       &_pBank,
                                 s32                    &_s32FixtureBtnIdx) const
{
    for (const shared_ptr<Bank> &pBank : m_vBank)
    {
        for (s32 idx = 0; idx < FIXTURE_MAX; idx++)
        {
            shared_ptr<Fixture> pFix = pBank->fixture(idx);

            if (pFix && pFix->name() == _pFix->name())
            {
                _pBank = pBank;
                _s32FixtureBtnIdx = idx;
                return true;
            }
        }
    }

    return false;
} // CtrlPanel::findBank4Fixture


/*******************************************************************************
* CtrlPanel::findChannel
*******************************************************************************/
shared_ptr<Channel> CtrlPanel::findChannel(const aString   &_sControllerName,
                                           s32             _s32UniverseId,
                                           s32             _s32channelNr,
                                           s32             _s32ChannelOs)
{
    return nullptr;
} // CtrlPanel::findChannel


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
* CtrlPanel::sendAllUniverses
*******************************************************************************/
void CtrlPanel::sendAllUniverses()
{
    for (shared_ptr<Controller> pCtrl : m_vController)
    {
        pCtrl->sendAllUniverses();
    }
} // CtrlPanel::sendAllUniverses


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
* CtrlPanel::activeBank
*******************************************************************************/
shared_ptr<Bank> CtrlPanel::activeBank() const
{
    return (m_pActiveBank)?   std::get<1> (*m_pActiveBank) : nullptr;
} // CtrlPanel::activeBank


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
* CtrlPanel::onFixtureSelected
*******************************************************************************/
void CtrlPanel::onFixtureSelected(s32 _s32FixtureBtnIdx)
{
    CHECK_PRE_CONDITION_VOID(_s32FixtureBtnIdx < FIXTURE_MAX);

    shared_ptr<Bank>    pBank       = activeBank();

    m_pActiveFixture = (pBank)?   pBank->fixture(_s32FixtureBtnIdx) : nullptr;

    // deselect non selected buttons
    for (s32 i = 0; i < FIXTURE_MAX; i++)
    {
        if (i != _s32FixtureBtnIdx)
        {
            std::get<0> (m_vFixtureCtrl.at(i))->setChecked(false);
        }
    }

    for (s32 i = 0; i < FADER_MAX; i++)
    {
        shared_ptr<Channel> pChannel = (m_pActiveFixture)?   m_pActiveFixture->channel(i+1) : nullptr;

        std::get<3> (m_vFader.at(i)) = pChannel;
    }

    updateFaderCtrls();
} // CtrlPanel::onFixtureSelected


/*******************************************************************************
* CtrlPanel::activeFixture
*******************************************************************************/
shared_ptr<Fixture> CtrlPanel::activeFixture() const
{
    return m_pActiveFixture;
} // CtrlPanel::activeFixture


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
        }
        else
        {
            pSceneBtn->setBtnText("");
        }
    }
} // CtrlPanel::updateSceneCtrls


/*******************************************************************************
* CtrlPanel::onSceneSelected
*******************************************************************************/
void CtrlPanel::onSceneSelected(s32 _s32SceneBtnIdx)
{
    MainWin     &mw = getMainWin();

    //aPushButton         *pBtn   = std::get<0> (m_vSceneCtrl.at(_s32SceneBtnIdx));
    shared_ptr<Scene>   &pScene = std::get<1> (m_vSceneCtrl.at(_s32SceneBtnIdx));

    switch (mw.workMode())
    {
        case enumWorkMode::Play:
        {
            if (pScene)
            {
                const aVector<channelValueTuple> vValues = pScene->channelValues();

                // set all channel values
                for (auto &tup : vValues)
                {
                    shared_ptr<Channel> pChannel    = std::get<0> (tup);
                    u8                  u8Val       = std::get<1> (tup);

                    pChannel->setValue(u8Val);
                    updateDmxValue(pChannel, false);
                }
            }

            // finally send all universe data
            sendAllUniverses();

            updateFaders();

            break;
        }

        case enumWorkMode::SaveScene:
        {
            aString                     sBtn = aString::fromValue(_s32SceneBtnIdx);
            aVector<channelValueTuple>  vValues;

            // get all channel values
            for (auto pFix : m_vFixture)
            {
                pFix->allChannelValues(vValues);
            }

            pScene = make_shared<Scene> (sBtn, vValues);

            updateSceneCtrls();

            mw.setWorkMode(enumWorkMode::Play);
            break;
        }
    }
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

        pScribble->update();
    }
} // CtrlPanel::updateFaderCtrls


/*******************************************************************************
* CtrlPanel::updateDmxValue
*******************************************************************************/
void CtrlPanel::updateDmxValue(shared_ptr<Channel>  _pChannel,
                               bool                 _bSend)
{
    CHECK_PRE_CONDITION_VOID(_pChannel);

    if (_pChannel->isBrightness())
    {
        u8 u8Val = static_cast<u8> (m_dMasterBrightness * _pChannel->value());
        _pChannel->updateDmxValue(u8Val, _bSend);
    }
    else
    {
        _pChannel->updateDmxValue(_pChannel->value(), _bSend);
    }
} // CtrlPanel::updateDmxValue


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
    MainWin     &mw     = getMainWin();
    bool        bSave   = (mw.workMode() == enumWorkMode::SaveScene);

    for (s32 i = 0; i < SCENE_MAX; i++)
    {
        aPushButton         *pSceneBtn = std::get<0>(m_vSceneCtrl.at(i));
        shared_ptr<Scene>   pScene = std::get<1>(m_vSceneCtrl.at(i));

        // set background
        if (bSave)
        {
            pSceneBtn->setBackgroundColor(colDarkGoldenRod);
            pSceneBtn->setEnabled(true);
        }
        else
        {
            pSceneBtn->setBackgroundColor(m_colButtonBg);
            pSceneBtn->setEnabled(pScene != nullptr);
        }
    }
} // CtrlPanel::updateScenes


/*******************************************************************************
* CtrlPanel::updateFaders
*******************************************************************************/
void CtrlPanel::updateFaders()
{
    shared_ptr<Fixture> pFix = activeFixture();

    // update the faders
    for (s32 s32FaderIdx = 0; s32FaderIdx < FADER_MAX; s32FaderIdx++)
    {
        Fader               *pFader     = get<1>(m_vFader.at(s32FaderIdx));
        shared_ptr<Channel> pChannel    = (pFix)?   pFix->channel(s32FaderIdx + 1) : nullptr;

        pFader->setTracking(false);
        if (pChannel)
        {
            pFader->setPosition(pChannel->value());
        }
        else
        {
            pFader->setPosition(0);
        }
        pFader->setTracking(true);
    }
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
    cout << __PRETTY_FUNCTION__ << endl;

    CHECK_PRE_CONDITION_VOID(m_pActiveFixture);

    auto pChannel = std::get<3>(m_vFader.at(s32FaderIdx));
    CHECK_PRE_CONDITION_VOID(pChannel);

    pChannel->setValue(static_cast<u8> (_s32Value));
    updateDmxValue(pChannel, true);
} // CtrlPanel::onFaderMoved


/*******************************************************************************
* CtrlPanel::onMasterFaderMoved
*******************************************************************************/
void CtrlPanel::onMasterFaderMoved(s32 _s32Value)
{
    cout << "onMasterFaderMoved" << endl;

    m_dMasterBrightness = ((dbl) (_s32Value)) / 255.;
    s32 s32Size = m_vMasterChannel.size();

     for (s32 i = 0; i < s32Size; i++)
     {
        updateDmxValue(m_vMasterChannel.at(i), i == s32Size - 1);
     }

    updateBlackoutButton();
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
* CtrlPanel::allChannels
*******************************************************************************/
void CtrlPanel::allChannels(aVector<shared_ptr<Channel>> &_vChannel) const
{
    // deselect non selected buttons
    for (shared_ptr<Fixture> pFix : m_vFixture)
    {
        pFix->allChannels(_vChannel);
    }
} // CtrlPanel::allChannels


/*******************************************************************************
* CtrlPanel::resetAllChannels
*******************************************************************************/
void CtrlPanel::resetAllChannels()
{
    aVector<shared_ptr<Channel>> vChannel;

    allChannels(vChannel);

    // set all channel values
    for (auto &pChannel : vChannel)
    {
        pChannel->setValue(0);
        updateDmxValue(pChannel, false);
    }

    // finally send all universe data
    sendAllUniverses();

    updateFaders();
} // CtrlPanel::resetAllChannels
