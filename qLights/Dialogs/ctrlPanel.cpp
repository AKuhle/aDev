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
#include "controller.h"

#include "bank.h"
#include "fixture.h"

// #include "aJsonFile.h"

// #include "universe.h"
// #include "channel.h"
// #include "scene.h"

//using namespace aLib::aUtil;


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
* CtrlPanel::resetAllChannels
*******************************************************************************/
void CtrlPanel::resetAllChannels()
{
    for (auto pFixture : m_vFixtures)
    {
        pFixture->resetAllChannels();
    }

    for (auto pController : m_vController)
    {
        pController->sendAllUniverses();
    }

    updateFaders();
} // CtrlPanel::resetAllChannels


/*******************************************************************************
* CtrlPanel::createSetup
*******************************************************************************/
void CtrlPanel::createSetup()
{
    // create the controller
    shared_ptr<Controller> pController = createController("Showtec NET-2/3 POCKET", "192.168.1.245", 2);

    // create a universe
    pController->addUniverse(1);

    // spot: eurolite-led-tmh-s90-de
    shared_ptr<Fixture> pSpot = createFixture("TMH-S90", pController, 1, 1);
    // the channels
    pSpot->addChannel(1, CHANNEL_ICN_PAN, false);
    pSpot->addChannel(2, CHANNEL_ICN_PAN_FINE, false);
    pSpot->addChannel(3, CHANNEL_ICN_TILT, false);
    pSpot->addChannel(4, CHANNEL_ICN_TILT_FINE, false);
    pSpot->addChannel(5, CHANNEL_ICN_PAN_TILT_SPEED, false);
    pSpot->addChannel(6, CHANNEL_ICN_BRIGHTNESS, true);
    pSpot->addChannel(7, CHANNEL_ICN_STROBE, false);
    pSpot->addChannel(8, CHANNEL_ICN_COLOR_WHEEL, false);
    pSpot->addChannel(9, CHANNEL_ICN_GOBO_STAT_01, false);
    pSpot->addChannel(10, CHANNEL_ICN_GOBO_ROT_01, false);
    pSpot->addChannel(11, CHANNEL_ICN_GOBO_ROT_SPEED, false);
    pSpot->addChannel(12, CHANNEL_ICN_FOCUS, false);
    pSpot->addChannel(13, CHANNEL_ICN_PRISMA, false);
    pSpot->addChannel(14, CHANNEL_ICN_FUNCTION_1, false);
    pSpot->addChannel(15, CHANNEL_ICN_RESET, false);

    // wash left: 16 channel mode
    shared_ptr<Fixture> pWash_l= createFixture("TMH-X4-16 left", pController, 1, 17);
    // the channels
    pWash_l->addChannel(1, CHANNEL_ICN_PAN, false);
    pWash_l->addChannel(2, CHANNEL_ICN_PAN_FINE, false);
    pWash_l->addChannel(3, CHANNEL_ICN_TILT, false);
    pWash_l->addChannel(4, CHANNEL_ICN_TILT_FINE, false);
    pWash_l->addChannel(5, CHANNEL_ICN_PAN_TILT_SPEED, false);
    pWash_l->addChannel(6, CHANNEL_ICN_BRIGHTNESS, true);
    pWash_l->addChannel(7, CHANNEL_ICN_STROBE, false);
    pWash_l->addChannel(8, CHANNEL_ICN_RED, false);
    pWash_l->addChannel(9, CHANNEL_ICN_GREEN, false);
    pWash_l->addChannel(10, CHANNEL_ICN_BLUE, false);
    pWash_l->addChannel(11, CHANNEL_ICN_WHITE, false);
    pWash_l->addChannel(12, CHANNEL_ICN_ZOOM, false);
    pWash_l->addChannel(14, CHANNEL_ICN_COLOR_SPEED, false);
    pWash_l->addChannel(15, CHANNEL_ICN_FUNCTION_1, false);
    pWash_l->addChannel(16, CHANNEL_ICN_RESET, false);

    // wash right: 16 channel mode
    shared_ptr<Fixture> pWash_r = createFixture("TMH-X4-16 right", pController, 1, 41);
    // the channels
    pWash_r->addChannel(1, CHANNEL_ICN_PAN, false);
    pWash_r->addChannel(2, CHANNEL_ICN_PAN_FINE, false);
    pWash_r->addChannel(3, CHANNEL_ICN_TILT, false);
    pWash_r->addChannel(4, CHANNEL_ICN_TILT_FINE, false);
    pWash_r->addChannel(5, CHANNEL_ICN_PAN_TILT_SPEED, false);
    pWash_r->addChannel(6, CHANNEL_ICN_BRIGHTNESS, true);
    pWash_r->addChannel(7, CHANNEL_ICN_STROBE, false);
    pWash_r->addChannel(8, CHANNEL_ICN_RED, false);
    pWash_r->addChannel(9, CHANNEL_ICN_GREEN, false);
    pWash_r->addChannel(10, CHANNEL_ICN_BLUE, false);
    pWash_r->addChannel(11, CHANNEL_ICN_WHITE, false);
    pWash_r->addChannel(12, CHANNEL_ICN_ZOOM, false);
    pWash_r->addChannel(14, CHANNEL_ICN_COLOR_SPEED, false);
    pWash_r->addChannel(15, CHANNEL_ICN_FUNCTION_1, false);
    pWash_r->addChannel(16, CHANNEL_ICN_RESET, false);

    // // wash right: 24 channel mode
    // shared_ptr<Fixture> pWash_r = createFixture("TMH-X4-24 right", pController, 1, 41);
    // // the channels
    // pWash_r->addChannel(1, CHANNEL_ICN_PAN, false);
    // pWash_r->addChannel(2, CHANNEL_ICN_PAN_FINE, false);
    // pWash_r->addChannel(3, CHANNEL_ICN_TILT, false);
    // pWash_r->addChannel(4, CHANNEL_ICN_TILT_FINE, false);
    // pWash_r->addChannel(5, CHANNEL_ICN_PAN_TILT_SPEED, false);
    // pWash_r->addChannel(6, CHANNEL_ICN_ZOOM, false);
    // pWash_r->addChannel(7, CHANNEL_ICN_BRIGHTNESS, true);
    // pWash_r->addChannel(8, CHANNEL_ICN_STROBE, false);
    // pWash_r->addChannel(9, CHANNEL_ICN_RED_1, false);
    // pWash_r->addChannel(10, CHANNEL_ICN_GREEN_1, false);
    // pWash_r->addChannel(11, CHANNEL_ICN_BLUE_1, false);
    // pWash_r->addChannel(12, CHANNEL_ICN_WHITE_1, false);
    // pWash_r->addChannel(13, CHANNEL_ICN_RED_2, false);
    // pWash_r->addChannel(14, CHANNEL_ICN_GREEN_2, false);
    // pWash_r->addChannel(15, CHANNEL_ICN_BLUE_2, false);
    // pWash_r->addChannel(16, CHANNEL_ICN_WHITE_2, false);
    // pWash_r->addChannel(17, CHANNEL_ICN_RED_3, false);
    // pWash_r->addChannel(18, CHANNEL_ICN_GREEN_3, false);
    // pWash_r->addChannel(19, CHANNEL_ICN_BLUE_3, false);
    // pWash_r->addChannel(20, CHANNEL_ICN_WHITE_3, false);
    // pWash_r->addChannel(22, CHANNEL_ICN_COLOR_SPEED, false);
    // pWash_r->addChannel(23, CHANNEL_ICN_FUNCTION_1, false);
    // pWash_r->addChannel(24, CHANNEL_ICN_RESET, false);

    // PAR left: 1 channel
    shared_ptr<Fixture> pPar_l = createFixture("PAR left", pController, 1, 65);
    // the channels
    pPar_l->addChannel(1, CHANNEL_ICN_BRIGHTNESS, true);

    // PAR right: 1 channel
    shared_ptr<Fixture> pPar_r = createFixture("PAR right", pController, 1, 66);
    // the channels
    pPar_r->addChannel(1, CHANNEL_ICN_BRIGHTNESS, true);

    // create the banks
    shared_ptr<Bank> pBank1 = createBank("All");
    assignBank(pBank1, 0);
    assignFixture(pBank1, pSpot, 0);
    assignFixture(pBank1, pWash_l, 1);
    assignFixture(pBank1, pWash_r, 2);
    assignFixture(pBank1, pPar_l, 3);
    assignFixture(pBank1, pPar_r, 4);

    shared_ptr<Bank> pBank2 = createBank("Wash MH");
    assignBank(pBank2, 1);
    assignFixture(pBank2, pWash_l, 0);
    assignFixture(pBank2, pWash_r, 1);

    shared_ptr<Bank> pBank3 = createBank("Spot MH");
    assignBank(pBank3, 2);
    assignFixture(pBank3, pSpot, 0);

    shared_ptr<Bank> pBank4 = createBank("PAR");
    assignBank(pBank4, 3);
    assignFixture(pBank4, pPar_l, 0);
    assignFixture(pBank4, pPar_r, 1);
} // CtrlPanel::createSetup


/*******************************************************************************
* CtrlPanel::createController
*******************************************************************************/
shared_ptr<Controller> CtrlPanel::createController(const aString  &_sName,
                                                   const aString  &_sIpAdr,
                                                   s32            _s32UniverseMax)
{
    shared_ptr<Controller> pController = make_shared<Controller> (_sName, _sIpAdr, _s32UniverseMax);

    m_vController.push_back(pController);

    return pController;
} // CtrlPanel::createController


/*******************************************************************************
* CtrlPanel::createBank
*******************************************************************************/
shared_ptr<Bank> CtrlPanel::createBank(const aString    &_sName)
{
    // create the bank
    shared_ptr<Bank> pBank = make_shared<Bank> (_sName);

    // add to banks
    m_vBanks.push_back(pBank);

    return pBank;
} // CtrlPanel::createBank


/*******************************************************************************
* CtrlPanel::assignBank
*******************************************************************************/
void CtrlPanel::assignBank(shared_ptr<Bank>      _pBank,
                           s32                   _s32BankIdx)
{
    // assign to a bank button if idx is valid
    if (_s32BankIdx >= 0 && _s32BankIdx < BANK_MAX)
    {
        // assign the bank to the bank button
        std::get<1> (m_vBankTuples.at(_s32BankIdx)) = _pBank;

        // update the bank-button names depending on the bank tuples
        initBanks();
    }
} // CtrlPanel::assignBank


/*******************************************************************************
* CtrlPanel::createFixture
*******************************************************************************/
shared_ptr<Fixture> CtrlPanel::createFixture(const aString          &_sName,
                                             shared_ptr<Controller> _pConroller,
                                             s32                    _s32UniverseId,
                                             s32                    _s32ChannelOs)
{
    // create the bank
    shared_ptr<Fixture> pFixture = make_shared<Fixture> (_sName,
                                                        _pConroller,
                                                        _s32UniverseId,
                                                        _s32ChannelOs);

    // add to banks
    m_vFixtures.push_back(pFixture);

    return pFixture;
} // CtrlPanel::createFixture


/*******************************************************************************
* CtrlPanel::assignFixture
*******************************************************************************/
void CtrlPanel::assignFixture(shared_ptr<Bank>      _pBank,
                              shared_ptr<Fixture>   _pFixture,
                              s32                   _s32FixtureIdx)
{
    CHECK_PRE_CONDITION_VOID(_pBank);

    // assign to a bank button if idx is valid
    if (_s32FixtureIdx >= 0 && _s32FixtureIdx < FIXTURE_MAX)
    {
        // assign the fixture to the bank
        _pBank->assignFixture(_pFixture, _s32FixtureIdx);

        if (_pBank == m_pActiveBank)
        {
            // update the fixture-buttons depending on the active bank
            initFixtures();
        }
    }
} // CtrlPanel::assignFixture


/*******************************************************************************
* CtrlPanel::updateGui
*******************************************************************************/
void CtrlPanel::updateGui()
{
    updateBanks();
    updateFixtures();
    updateScenes();
    updateFaders();
    //     updateBlackoutButton();
} // CtrlPanel::updateGui


/*******************************************************************************
* CtrlPanel::updateBanks
*******************************************************************************/
void CtrlPanel::updateBanks()
{
    for (auto pBankTuple : m_vBankTuples)
    {
        auto pBtn   = std::get<0> (pBankTuple);
        auto pBank  = std::get<1> (pBankTuple);

        pBtn->setCtrlEnabled(pBank != nullptr);
        pBtn->setCtrlChecked(pBank != nullptr && pBank == m_pActiveBank);
    }
} // CtrlPanel::updateBanks


/*******************************************************************************
* CtrlPanel::updateFixtures
*******************************************************************************/
void CtrlPanel::updateFixtures()
{
    for (auto pFixtureTuple : m_vFixtureTuples)
    {
        auto pBtn       = std::get<0> (pFixtureTuple);
        auto pFixture   = std::get<1> (pFixtureTuple);

        pBtn->setCtrlEnabled(pFixture != nullptr);
        pBtn->setCtrlChecked(pFixture != nullptr && pFixture == m_pActiveFixture);
    }
} // CtrlPanel::updateFixtures


/*******************************************************************************
* CtrlPanel::updateScenes
*******************************************************************************/
void CtrlPanel::updateScenes()
{
    MainWin     &mw = getMainWin();

    for (auto pSceneTuple : m_vSceneTuples)
    {
        aPushButton         *pBtn   = std::get<0> (pSceneTuple);
        shared_ptr<Scene>   pScene  = std::get<1> (pSceneTuple);

        switch (mw.workMode())
        {
            case enumWorkMode::Play:
                pBtn->setCtrlEnabled(pScene != nullptr);
                pBtn->setBackgroundColor(m_colButtonBg);
                break;

            case enumWorkMode::SaveScene:
                pBtn->setCtrlEnabled(true);
                pBtn->setBackgroundColor(colDarkOrange);
                break;
        } // switch
    } // for

} // CtrlPanel::updateScenes


/*******************************************************************************
* CtrlPanel::updateFaders
*******************************************************************************/
void CtrlPanel::updateFaders()
{
    for (auto pFader : m_vFaders)
    {
        pFader->updateState();
    }

    //     // update the faders
    //     for (s32 s32FaderIdx = 0; s32FaderIdx < FADER_MAX; s32FaderIdx++)
    //     {
    //         ScribbleStrip       *pScribble  = get<0>(m_vFader.at(s32FaderIdx));
    //         Fader               *pFader     = get<1>(m_vFader.at(s32FaderIdx));
    //         aLabel              *pLabel     = get<2>(m_vFader.at(s32FaderIdx));
    //         shared_ptr<Channel> pChannel    = get<3>(m_vFader.at(s32FaderIdx));

    //         if (pChannel)
    //         {
    //             pScribble->setIcon(pChannel->channelIcon());
    //             pFader->setEnabled(true);
    //             pLabel->setText(aString::fromValue(s32FaderIdx + 1));

    //             pFader->setValue(pChannel->value());
    //         }
    //         else
    //         {
    //             pScribble->setIcon("");
    //             pFader->setEnabled(false);
    //             pLabel->setText(aString(""));

    //             pFader->setValue(0);
    //         }

    //         pScribble->update();
    //     }
} // CtrlPanel::updateFaders


/*******************************************************************************
* CtrlPanel::initBanks
*******************************************************************************/
void CtrlPanel::initBanks()
{
    // update the bank-button names depending on the bank tuples

    for (auto pBankTuple : m_vBankTuples)
    {
        aPushButton         *pBtn   = std::get<0> (pBankTuple);
        shared_ptr<Bank>    pBank   = std::get<1> (pBankTuple);

        if (pBank != nullptr)
        {
            pBtn->setText(pBank->name());
        }
        else
        {
            pBtn->setText(aString(""));
        }
    } // CtrlPanel::initGui
} // CtrlPanel::initBanks


/*******************************************************************************
* CtrlPanel::initFixtures
*******************************************************************************/
void CtrlPanel::initFixtures()
{
    // update the fixture-buttons depending on the active bank

    for (s32 idx = 0; idx < FIXTURE_MAX; idx++)
    {
        aPushButton         *pBtn      = std::get<0> (m_vFixtureTuples.at(idx));
        shared_ptr<Fixture> &pFixture  = std::get<1> (m_vFixtureTuples.at(idx));

        if (m_pActiveBank && m_pActiveBank->fixture(idx))
        {
            pBtn->setText(m_pActiveBank->fixture(idx)->name());
            pFixture = m_pActiveBank->fixture(idx);
        }
        else
        {
            pBtn->setText(aString(""));
            pFixture = nullptr;
        }
    }
} // CtrlPanel::initFixtures


/*******************************************************************************
* CtrlPanel::initScenes
*******************************************************************************/
void CtrlPanel::initScenes()
{
    for (auto pSceneTuple : m_vSceneTuples)
    {
        aPushButton *pBtn = std::get<0> (pSceneTuple);

        pBtn->setText(aString(""));
    } // CtrlPanel::initGui
} // CtrlPanel::initScenes


/*******************************************************************************
* CtrlPanel::initFaders
*******************************************************************************/
void CtrlPanel::initFaders()
{
    // update the faders
    for (s32 s32FaderIdx = 0; s32FaderIdx < FADER_MAX; s32FaderIdx++)
    {
        if (m_pActiveFixture)
        {
            m_vFaders.at(s32FaderIdx)->setChannel(m_pActiveFixture->channel(s32FaderIdx + 1));
        }
        else
        {
            m_vFaders.at(s32FaderIdx)->setChannel(nullptr);
        }
    }
        // auto pFader     = get<0>(m_vFaders.at(s32FaderIdx));
        // auto &pScene    = get<1>(m_vFaders.at(s32FaderIdx));



//         ScribbleStrip       *pScribble  = get<0>(m_vFader.at(s32FaderIdx));
//         Fader               *pFader     = get<1>(m_vFader.at(s32FaderIdx));
//         aLabel              *pLabel     = get<2>(m_vFader.at(s32FaderIdx));
//         shared_ptr<Channel> pChannel    = get<3>(m_vFader.at(s32FaderIdx));

//         if (pChannel)
//         {
//             pScribble->setIcon(pChannel->channelIcon());
//             pFader->setEnabled(true);
//             pLabel->setText(aString::fromValue(s32FaderIdx + 1));

//             pFader->setValue(pChannel->value());
//         }
//         else
//         {
//             pScribble->setIcon("");
//             pFader->setEnabled(false);
//             pLabel->setText(aString(""));

//             pFader->setValue(0);
//         }

//         pScribble->update();
} // CtrlPanel::initFaders


/*******************************************************************************
* CtrlPanel::onCreateWin
*******************************************************************************/
bool CtrlPanel::onCreateWin()
{
    m_colButtonBg = m_pUi->m_pScene_01->backgroundColor();

    // bank controls
    m_vBankTuples.push_back(BankTuple(m_pUi->m_pBank_01, nullptr));
    m_vBankTuples.push_back(BankTuple(m_pUi->m_pBank_02, nullptr));
    m_vBankTuples.push_back(BankTuple(m_pUi->m_pBank_03, nullptr));
    m_vBankTuples.push_back(BankTuple(m_pUi->m_pBank_04, nullptr));
    m_vBankTuples.push_back(BankTuple(m_pUi->m_pBank_05, nullptr));
    m_vBankTuples.push_back(BankTuple(m_pUi->m_pBank_06, nullptr));
    m_vBankTuples.push_back(BankTuple(m_pUi->m_pBank_07, nullptr));
    m_vBankTuples.push_back(BankTuple(m_pUi->m_pBank_08, nullptr));
    m_vBankTuples.push_back(BankTuple(m_pUi->m_pBank_09, nullptr));
    m_vBankTuples.push_back(BankTuple(m_pUi->m_pBank_10, nullptr));

    // fixture controls
    m_vFixtureTuples.push_back(FixtureTuple(m_pUi->m_pFixture_01, nullptr));
    m_vFixtureTuples.push_back(FixtureTuple(m_pUi->m_pFixture_02, nullptr));
    m_vFixtureTuples.push_back(FixtureTuple(m_pUi->m_pFixture_03, nullptr));
    m_vFixtureTuples.push_back(FixtureTuple(m_pUi->m_pFixture_04, nullptr));
    m_vFixtureTuples.push_back(FixtureTuple(m_pUi->m_pFixture_05, nullptr));
    m_vFixtureTuples.push_back(FixtureTuple(m_pUi->m_pFixture_06, nullptr));
    m_vFixtureTuples.push_back(FixtureTuple(m_pUi->m_pFixture_07, nullptr));
    m_vFixtureTuples.push_back(FixtureTuple(m_pUi->m_pFixture_08, nullptr));
    m_vFixtureTuples.push_back(FixtureTuple(m_pUi->m_pFixture_09, nullptr));
    m_vFixtureTuples.push_back(FixtureTuple(m_pUi->m_pFixture_10, nullptr));

    // scene controls
    m_vSceneTuples.push_back(SceneTuple(m_pUi->m_pScene_01, nullptr));
    m_vSceneTuples.push_back(SceneTuple(m_pUi->m_pScene_02, nullptr));
    m_vSceneTuples.push_back(SceneTuple(m_pUi->m_pScene_03, nullptr));
    m_vSceneTuples.push_back(SceneTuple(m_pUi->m_pScene_04, nullptr));
    m_vSceneTuples.push_back(SceneTuple(m_pUi->m_pScene_05, nullptr));
    m_vSceneTuples.push_back(SceneTuple(m_pUi->m_pScene_06, nullptr));
    m_vSceneTuples.push_back(SceneTuple(m_pUi->m_pScene_07, nullptr));
    m_vSceneTuples.push_back(SceneTuple(m_pUi->m_pScene_08, nullptr));
    m_vSceneTuples.push_back(SceneTuple(m_pUi->m_pScene_09, nullptr));
    m_vSceneTuples.push_back(SceneTuple(m_pUi->m_pScene_10, nullptr));
    m_vSceneTuples.push_back(SceneTuple(m_pUi->m_pScene_11, nullptr));
    m_vSceneTuples.push_back(SceneTuple(m_pUi->m_pScene_12, nullptr));
    m_vSceneTuples.push_back(SceneTuple(m_pUi->m_pScene_13, nullptr));
    m_vSceneTuples.push_back(SceneTuple(m_pUi->m_pScene_14, nullptr));
    m_vSceneTuples.push_back(SceneTuple(m_pUi->m_pScene_15, nullptr));
    m_vSceneTuples.push_back(SceneTuple(m_pUi->m_pScene_16, nullptr));
    m_vSceneTuples.push_back(SceneTuple(m_pUi->m_pScene_17, nullptr));
    m_vSceneTuples.push_back(SceneTuple(m_pUi->m_pScene_18, nullptr));
    m_vSceneTuples.push_back(SceneTuple(m_pUi->m_pScene_19, nullptr));
    m_vSceneTuples.push_back(SceneTuple(m_pUi->m_pScene_20, nullptr));
    m_vSceneTuples.push_back(SceneTuple(m_pUi->m_pScene_21, nullptr));
    m_vSceneTuples.push_back(SceneTuple(m_pUi->m_pScene_22, nullptr));
    m_vSceneTuples.push_back(SceneTuple(m_pUi->m_pScene_23, nullptr));
    m_vSceneTuples.push_back(SceneTuple(m_pUi->m_pScene_24, nullptr));
    m_vSceneTuples.push_back(SceneTuple(m_pUi->m_pScene_25, nullptr));
    m_vSceneTuples.push_back(SceneTuple(m_pUi->m_pScene_26, nullptr));
    m_vSceneTuples.push_back(SceneTuple(m_pUi->m_pScene_27, nullptr));
    m_vSceneTuples.push_back(SceneTuple(m_pUi->m_pScene_28, nullptr));
    m_vSceneTuples.push_back(SceneTuple(m_pUi->m_pScene_29, nullptr));
    m_vSceneTuples.push_back(SceneTuple(m_pUi->m_pScene_30, nullptr));

    // fader controls
    m_vFaders.push_back(m_pUi->m_pFader_01);
    m_vFaders.push_back(m_pUi->m_pFader_02);
    m_vFaders.push_back(m_pUi->m_pFader_03);
    m_vFaders.push_back(m_pUi->m_pFader_04);
    m_vFaders.push_back(m_pUi->m_pFader_05);
    m_vFaders.push_back(m_pUi->m_pFader_06);
    m_vFaders.push_back(m_pUi->m_pFader_07);
    m_vFaders.push_back(m_pUi->m_pFader_08);
    m_vFaders.push_back(m_pUi->m_pFader_09);
    m_vFaders.push_back(m_pUi->m_pFader_10);
    m_vFaders.push_back(m_pUi->m_pFader_11);
    m_vFaders.push_back(m_pUi->m_pFader_12);
    m_vFaders.push_back(m_pUi->m_pFader_13);
    m_vFaders.push_back(m_pUi->m_pFader_14);
    m_vFaders.push_back(m_pUi->m_pFader_15);
    m_vFaders.push_back(m_pUi->m_pFader_16);
    m_vFaders.push_back(m_pUi->m_pFader_17);
    m_vFaders.push_back(m_pUi->m_pFader_18);
    m_vFaders.push_back(m_pUi->m_pFader_19);
    m_vFaders.push_back(m_pUi->m_pFader_20);
    m_vFaders.push_back(m_pUi->m_pFader_21);
    m_vFaders.push_back(m_pUi->m_pFader_22);
    m_vFaders.push_back(m_pUi->m_pFader_23);
    m_vFaders.push_back(m_pUi->m_pFader_24);

    m_pUi->m_pFader_01->setControls(m_pUi->m_pScribbleStrip_01, m_pUi->m_pNr_01);
    m_pUi->m_pFader_02->setControls(m_pUi->m_pScribbleStrip_02, m_pUi->m_pNr_02);
    m_pUi->m_pFader_03->setControls(m_pUi->m_pScribbleStrip_03, m_pUi->m_pNr_03);
    m_pUi->m_pFader_04->setControls(m_pUi->m_pScribbleStrip_04, m_pUi->m_pNr_04);
    m_pUi->m_pFader_05->setControls(m_pUi->m_pScribbleStrip_05, m_pUi->m_pNr_05);
    m_pUi->m_pFader_06->setControls(m_pUi->m_pScribbleStrip_06, m_pUi->m_pNr_06);
    m_pUi->m_pFader_07->setControls(m_pUi->m_pScribbleStrip_07, m_pUi->m_pNr_07);
    m_pUi->m_pFader_08->setControls(m_pUi->m_pScribbleStrip_08, m_pUi->m_pNr_08);
    m_pUi->m_pFader_09->setControls(m_pUi->m_pScribbleStrip_09, m_pUi->m_pNr_09);
    m_pUi->m_pFader_10->setControls(m_pUi->m_pScribbleStrip_10, m_pUi->m_pNr_10);
    m_pUi->m_pFader_10->setControls(m_pUi->m_pScribbleStrip_10, m_pUi->m_pNr_10);
    m_pUi->m_pFader_11->setControls(m_pUi->m_pScribbleStrip_11, m_pUi->m_pNr_11);
    m_pUi->m_pFader_12->setControls(m_pUi->m_pScribbleStrip_12, m_pUi->m_pNr_12);
    m_pUi->m_pFader_13->setControls(m_pUi->m_pScribbleStrip_13, m_pUi->m_pNr_13);
    m_pUi->m_pFader_14->setControls(m_pUi->m_pScribbleStrip_14, m_pUi->m_pNr_14);
    m_pUi->m_pFader_15->setControls(m_pUi->m_pScribbleStrip_15, m_pUi->m_pNr_15);
    m_pUi->m_pFader_16->setControls(m_pUi->m_pScribbleStrip_16, m_pUi->m_pNr_16);
    m_pUi->m_pFader_17->setControls(m_pUi->m_pScribbleStrip_17, m_pUi->m_pNr_17);
    m_pUi->m_pFader_18->setControls(m_pUi->m_pScribbleStrip_18, m_pUi->m_pNr_18);
    m_pUi->m_pFader_19->setControls(m_pUi->m_pScribbleStrip_19, m_pUi->m_pNr_19);
    m_pUi->m_pFader_20->setControls(m_pUi->m_pScribbleStrip_20, m_pUi->m_pNr_20);
    m_pUi->m_pFader_21->setControls(m_pUi->m_pScribbleStrip_21, m_pUi->m_pNr_21);
    m_pUi->m_pFader_22->setControls(m_pUi->m_pScribbleStrip_22, m_pUi->m_pNr_22);
    m_pUi->m_pFader_23->setControls(m_pUi->m_pScribbleStrip_23, m_pUi->m_pNr_23);
    m_pUi->m_pFader_24->setControls(m_pUi->m_pScribbleStrip_24, m_pUi->m_pNr_24);

    for (auto pFader : m_vFaders)
    {
        pFader->setInverse(true);
    }

//     m_masterFader = FaderTuple(m_pUi->m_pScribbleStrip_M, m_pUi->m_pFader_M, m_pUi->m_pNr_M, nullptr);
//     ScribbleStrip       *pScribble  = get<0>(m_masterFader);
//     Fader               *pFader     = get<1>(m_masterFader);
//     aLabel              *pLabel     = get<2>(m_masterFader);
//     pScribble->setIcon(CHANNEL_ICN_BRIGHTNESS_ALL);
//     pFader->setInverse(true);
//     pFader->setValue(255);
//     pLabel->setText("Mstr");

    createSetup();

    initBanks();
    initFixtures();
    initScenes();
    initFaders();

    updateGui();

    return true;
} // CtrlPanel::onCreateWin


// /*******************************************************************************
// * CtrlPanel::setConfiguration
// *******************************************************************************/
// void CtrlPanel::setConfiguration(aMap<aString, controllerIoInfo>    &_mapControllerIoInfo,
//                                  aMap<aString, bankIoInfo>          &_mapBankIoInfo,
//                                  aMap<aString, fixtureIoInfo>       &_mapFixtureIoInfo,
//                                  aMap<aString, sceneIoInfo>         &_mapSceneIoInfo)
// {
//     // clear previous configuration
//     m_vController.clear();
//     m_vBank.clear();
//     m_pActiveBank = nullptr;
//     m_vFixture.clear();
//     m_pActiveFixture = nullptr;
//     m_vMasterChannel.clear();
//     for (sceneTuple &t : m_vSceneTuple)
//     {
//         std::get<1> (t) = nullptr;
//     }

//     // create controller/universes
//     for (auto me : _mapControllerIoInfo)
//     {
//         controllerIoInfo &ci = me.second;

//         aString                         sCtrlName   = std::get<0> (ci);
//         aString                         sCtrlAdress = std::get<1> (ci);
//         s32                             s32CtrlUniMax = std::get<2> (ci);

//         shared_ptr<Controller> pController = createController(sCtrlName, sCtrlAdress, s32CtrlUniMax);

//         // generate the universes
//         aMap<aString, universeIoInfo>   &mapUni = std::get<3> (ci);
//         for (auto uniME : mapUni)
//         {
//             universeIoInfo &ui = uniME.second;

//             s32         s32UniId    = std::get<0> (ui);
//             //QByteArray  &ba         = std::get<1> (ui);

//             pController->addUniverse(s32UniId);
//         }
//     } // for (auto me : m_mapControllerIoInfo)


//     // create the banks
//     for (auto me : _mapBankIoInfo)
//     {
//         bankIoInfo &bi = me.second;

//         aString sBankName = std::get<0> (bi);
//         s32 s32BnkBtnIdx = std::get<1> (bi);

//         shared_ptr<Bank> pBank1 = createBank(sBankName);
//         assignBank(pBank1, s32BnkBtnIdx);
//     }


//     // create the features
//      for (auto me : _mapFixtureIoInfo)
//     {
//         fixtureIoInfo &fi = me.second;

//         aString     sFixName            = std::get<0> (fi);
//         aString     sFixControllerName  = std::get<1> (fi);
//         s32         s32FixUniverseId    = std::get<2> (fi);
//         s32         s32FixChannelOs     = std::get<3> (fi);
//         aString     sFixBank            = std::get<4> (fi);
//         s32         s32FixBtnIdx        = std::get<5> (fi);

//         shared_ptr<Controller>  pController = findController(sFixControllerName);
//         shared_ptr<Bank>        pBank       = findBank(sFixBank);

//         if (pController)
//         {
//             // create the fixture
//             shared_ptr<Fixture> pFix = createFixture(sFixName, pController, s32FixUniverseId, s32FixChannelOs);
//             assignFixture(pFix, pBank, s32FixBtnIdx);

//             for (auto ci : std::get<6> (fi))
//             {
//                 aString sControllerName         = std::get<0> (ci.second);
//                 s32     s32ChannelNr            = std::get<1> (ci.second);
//                 aString sChannelIcon            = std::get<2> (ci.second);
//                 bool    bChannelBrightness      = std::get<3> (ci.second);

//                 // create the channel
//                 shared_ptr<Channel> pChannel = pFix->addChannel(s32ChannelNr, sChannelIcon, bChannelBrightness);

//                 // add brightness-channel to master channel
//                 if (bChannelBrightness)
//                 {
//                     m_vMasterChannel.push_back(pChannel);
//                 }
//             }
//         }
//     }


//     // create the scenes
//     for (auto me : _mapSceneIoInfo)
//     {
//         //aVector<channelValueTuple>  vtuple;
//         //sceneIoInfo                 &si             = me.second;

//         //s32                         s32Idx          = std::get<0> (si);
//         //aString                     sSceneName      = std::get<1> (si);
//         //aString                     sControllerName = std::get<2> (si);
//         //s32                         s32UniverseId   = std::get<3> (si);
//         //s32                         s32ChannelNr    = std::get<4> (si);
//         //s32                         s32ChannelOs    = std::get<5> (si);
//         //u8                          u8Value         = std::get<6> (si);

//         //shared_ptr<Channel>         pChannel        = findChannel(sControllerName,
//         //                                                          s32UniverseId,
//         //                                                          s32ChannelNr,
//         //                                                          s32ChannelOs);
//         // shared_ptr<Bank> pBank1 = createBank(sBankName);
//         // assignBank(pBank1, s32BnkBtnIdx);
//     }

//     // initial initialisation
//     updateBankTuples();
//     updateFixtureTuples();
//     updateSceneTuples();
//     updateFaderCtrls();
// } // CtrlPanel::setConfiguration


// /*******************************************************************************
// * CtrlPanel::findController
// *******************************************************************************/
// shared_ptr<Controller> CtrlPanel::findController(const aString &_sControllerName) const
// {
//     for (shared_ptr<Controller> pCtrl : m_vController)
//     {
//         if (pCtrl->name() == _sControllerName)
//         {
//             return pCtrl;
//         }
//     }

//     return nullptr;
// } // CtrlPanel::findController


// /*******************************************************************************
// * CtrlPanel::findBank
// *******************************************************************************/
// shared_ptr<Bank> CtrlPanel::findBank(const aString &_sBankName) const
// {
//     for (shared_ptr<Bank> pBank : m_vBank)
//     {
//         if (pBank->name() == _sBankName)
//         {
//             return pBank;
//         }
//     }

//     return nullptr;
// } // CtrlPanel::findBank


// /*******************************************************************************
// * CtrlPanel::findBank4Fixture
// *******************************************************************************/
// bool CtrlPanel::findBank4Fixture(shared_ptr<Fixture>    _pFix,
//                                  shared_ptr<Bank>       &_pBank,
//                                  s32                    &_s32FixtureBtnIdx) const
// {
//     for (const shared_ptr<Bank> &pBank : m_vBank)
//     {
//         for (s32 idx = 0; idx < FIXTURE_MAX; idx++)
//         {
//             shared_ptr<Fixture> pFix = pBank->fixture(idx);

//             if (pFix && pFix->name() == _pFix->name())
//             {
//                 _pBank = pBank;
//                 _s32FixtureBtnIdx = idx;
//                 return true;
//             }
//         }
//     }

//     return false;
// } // CtrlPanel::findBank4Fixture


// /*******************************************************************************
// * CtrlPanel::findChannel
// *******************************************************************************/
// shared_ptr<Channel> CtrlPanel::findChannel(const aString   &_sControllerName,
//                                            s32             _s32UniverseId,
//                                            s32             _s32channelNr,
//                                            s32             _s32ChannelOs)
// {
//     return nullptr;
// } // CtrlPanel::findChannel


// /*******************************************************************************
// * CtrlPanel::createController
// *******************************************************************************/
// shared_ptr<Controller> CtrlPanel::createController(const aString   &_sName,
//                                                    const aString   &_sIpAdr,
//                                                    s32             _s32UniverseMax)
// {
//     shared_ptr<Controller> pCtrl = make_shared<Controller> (_sName, _sIpAdr, _s32UniverseMax);

//     m_vController.push_back(pCtrl);

//     return pCtrl;
// } // CtrlPanel::createController


// /*******************************************************************************
// * CtrlPanel::sendAllUniverses
// *******************************************************************************/
// void CtrlPanel::sendAllUniverses()
// {
//     for (shared_ptr<Controller> pCtrl : m_vController)
//     {
//         pCtrl->sendAllUniverses();
//     }
// } // CtrlPanel::sendAllUniverses



// /*******************************************************************************
// * CtrlPanel::updateSceneTuples
// *******************************************************************************/
// void CtrlPanel::updateSceneTuples()
// {
//     for (sceneTuple &st : m_vSceneTuple)
//     {
//         auto pSceneBtn   = std::get<0> (st);
//         auto pScene      = std::get<1> (st);

//         if (pScene)
//         {
//             pSceneBtn->setBtnText(pScene->name());
//         }
//         else
//         {
//             pSceneBtn->setBtnText("");
//         }
//     }
// } // CtrlPanel::updateSceneTuples


// /*******************************************************************************
// * CtrlPanel::onSceneSelected
// *******************************************************************************/
// void CtrlPanel::onSceneSelected(s32 _s32SceneBtnIdx)
// {
//     MainWin     &mw = getMainWin();

//     //aPushButton         *pBtn   = std::get<0> (m_vSceneTuple.at(_s32SceneBtnIdx));
//     shared_ptr<Scene>   &pScene = std::get<1> (m_vSceneTuple.at(_s32SceneBtnIdx));

//     switch (mw.workMode())
//     {
//         case enumWorkMode::Play:
//         {
//             if (pScene)
//             {
//                 const aVector<channelValueTuple> vValues = pScene->channelValues();

//                 // set all channel values
//                 for (auto &tup : vValues)
//                 {
//                     shared_ptr<Channel> pChannel    = std::get<0> (tup);
//                     u8                  u8Val       = std::get<1> (tup);

//                     pChannel->setValue(u8Val);
//                     updateDmxValue(pChannel, false);
//                 }
//             }

//             // finally send all universe data
//             sendAllUniverses();

//             updateFaders();

//             break;
//         }

//         case enumWorkMode::SaveScene:
//         {
//             aString                     sBtn = aString::fromValue(_s32SceneBtnIdx);
//             aVector<channelValueTuple>  vValues;

//             // get all channel values
//             for (auto pFix : m_vFixture)
//             {
//                 pFix->allChannelValues(vValues);
//             }

//             pScene = make_shared<Scene> (sBtn, vValues);

//             updateSceneTuples();

//             mw.setWorkMode(enumWorkMode::Play);
//             break;
//         }
//     }
// } // CtrlPanel::onSceneSelected


// /*******************************************************************************
// * CtrlPanel::updateDmxValue
// *******************************************************************************/
// void CtrlPanel::updateDmxValue(shared_ptr<Channel>  _pChannel,
//                                bool                 _bSend)
// {
//     CHECK_PRE_CONDITION_VOID(_pChannel);

//     if (_pChannel->isBrightness())
//     {
//         u8 u8Val = static_cast<u8> (m_dMasterBrightness * _pChannel->value());
//         _pChannel->updateDmxValue(u8Val, _bSend);
//     }
//     else
//     {
//         _pChannel->updateDmxValue(_pChannel->value(), _bSend);
//     }
// } // CtrlPanel::updateDmxValue


// /*******************************************************************************
// * CtrlPanel::updateScenes
// *******************************************************************************/
// void CtrlPanel::updateScenes()
// {
//     MainWin     &mw     = getMainWin();
//     bool        bSave   = (mw.workMode() == enumWorkMode::SaveScene);

//     for (s32 i = 0; i < SCENE_MAX; i++)
//     {
//         aPushButton         *pSceneBtn = std::get<0>(m_vSceneTuple.at(i));
//         shared_ptr<Scene>   pScene = std::get<1>(m_vSceneTuple.at(i));

//         // set background
//         if (bSave)
//         {
//             pSceneBtn->setBackgroundColor(colDarkGoldenRod);
//             pSceneBtn->setEnabled(true);
//         }
//         else
//         {
//             pSceneBtn->setBackgroundColor(m_colButtonBg);
//             pSceneBtn->setEnabled(pScene != nullptr);
//         }
//     }
// } // CtrlPanel::updateScenes


// /*******************************************************************************
// * CtrlPanel::updateFaders
// *******************************************************************************/
// void CtrlPanel::updateFaders()
// {
//     shared_ptr<Fixture> pFix = activeFixture();

//     // update the faders
//     for (s32 s32FaderIdx = 0; s32FaderIdx < FADER_MAX; s32FaderIdx++)
//     {
//         Fader               *pFader     = get<1>(m_vFader.at(s32FaderIdx));
//         shared_ptr<Channel> pChannel    = (pFix)?   pFix->channel(s32FaderIdx + 1) : nullptr;

//         pFader->setTracking(false);
//         if (pChannel)
//         {
//             pFader->setPosition(pChannel->value());
//         }
//         else
//         {
//             pFader->setPosition(0);
//         }
//         pFader->setTracking(true);
//     }
// } // CtrlPanel::updateFaders


// /*******************************************************************************
// * CtrlPanel::updateBlackoutButton
// *******************************************************************************/
// void CtrlPanel::updateBlackoutButton()
// {
//     if (m_dMasterBrightness > 0)
//     {
//         m_pUi->m_pBlackout->setBackgroundColor(colBlack);
//     }
//     else
//     {
//         m_pUi->m_pBlackout->setBackgroundColor(aColor::fromU8(255, 255,128, 255));
//     }
// } // CtrlPanel::updateBlackoutButton


// /*******************************************************************************
// * CtrlPanel::onMasterFaderMoved
// *******************************************************************************/
// void CtrlPanel::onMasterFaderMoved(s32 _s32Value)
// {
//     cout << "onMasterFaderMoved" << endl;

//     m_dMasterBrightness = ((dbl) (_s32Value)) / 255.;
//     s32 s32Size = m_vMasterChannel.size();

//      for (s32 i = 0; i < s32Size; i++)
//      {
//         updateDmxValue(m_vMasterChannel.at(i), i == s32Size - 1);
//      }

//     updateBlackoutButton();
// } // CtrlPanel::onMasterFaderMoved


// /*******************************************************************************
// * CtrlPanel::onBlackoutClicked
// *******************************************************************************/
// void CtrlPanel::onBlackoutClicked()
// {
//     Fader   *pFader     = get<1>(m_masterFader);

//     if (m_dMasterBrightness > 0)
//     {
//         pFader->setValue(0);
//         m_dMasterBrightness = 0;
//     }
//     else
//     {
//         pFader->setValue(255);
//         m_dMasterBrightness = 1;
//     }

//     updateBlackoutButton();
// } // CtrlPanel::onBlackoutClicked


// /*******************************************************************************
// * CtrlPanel::allChannels
// *******************************************************************************/
// void CtrlPanel::allChannels(aVector<shared_ptr<Channel>> &_vChannel) const
// {
//     // deselect non selected buttons
//     for (shared_ptr<Fixture> pFix : m_vFixture)
//     {
//         pFix->allChannels(_vChannel);
//     }
// } // CtrlPanel::allChannels


// /*******************************************************************************
// * CtrlPanel::resetAllChannels
// *******************************************************************************/
// void CtrlPanel::resetAllChannels()
// {
//     aVector<shared_ptr<Channel>> vChannel;

//     allChannels(vChannel);

//     // set all channel values
//     for (auto &pChannel : vChannel)
//     {
//         pChannel->setValue(0);
//         updateDmxValue(pChannel, false);
//     }

//     // finally send all universe data
//     sendAllUniverses();

//     updateFaders();
// } // CtrlPanel::resetAllChannels
