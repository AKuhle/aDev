/*******************************************************************************
* includes
*******************************************************************************/
#include <QMessageBox>
#include <QTimer>

#include "aFrame_def.h"

#include "ui_mainWin.h"

#include "aAppBase.h"
#include "mainWin.h"
#include "aJsonFile.h"
#include "aPath.h"
#include "scene.h"
#include "universe.h"

#include "dlgController.h"
#include "dlgUniverse.h"
#include "dlgDevice.h"
#include "dlgFixture.h"

using namespace std;
using namespace aFrame::aApp;
using namespace aFrame::aUtil;


/*******************************************************************************
* MainWin::onFileOpen
*******************************************************************************/
void MainWin::onFileOpen()
{
    // set the path for the configuration
    // aPath       sPath   = get_appPath();
    // sPath.append("qLights.json");

    aPath sPath = "C:/Tools/aDev/qLights/Documents/qLights.json";

    openFile(sPath);
} // onFileOpen


/*******************************************************************************
* MainWin::onFileSave
*******************************************************************************/
void MainWin::onFileSave()
{
    // aPath       sPath   = get_appPath();
    // sPath.append("qLights.json");

    aPath sPath = "C:/Tools/aDev/qLights/Documents/qLights.json";

    saveFile(sPath);
} // MainWin::onFileSave


/*******************************************************************************
* MainWin::onBackupOpen
*******************************************************************************/
void MainWin::onBackupOpen()
{
    // set the path for the configuration
    // aPath       sPath   = get_appPath();
    // sPath.append("qLights.json");

    aPath sPath = "C:/Tools/aDev/qLights/Documents/qLightsBup.json";

    openFile(sPath);
} // onBackupOpen


/*******************************************************************************
* MainWin::onBackupSave
*******************************************************************************/
void MainWin::onBackupSave()
{
    // aPath       sPath   = get_appPath();
    // sPath.append("qLights.json");

    aPath sPath = "C:/Tools/aDev/qLights/Documents/qLightsBup.json";

    saveFile(sPath);
} // MainWin::onBackupSave


/*******************************************************************************
* MainWin::openFile
*******************************************************************************/
void MainWin::openFile(aPath _path)
{
    // ask for loading
    if (QMessageBox::question(this, "Load", "Replace Current Configuration?",
                              QMessageBox::Yes | QMessageBox::No) == QMessageBox::No)
    {
        return;
    }

    aJsonFile   f;
    s32         count, idx;

    if (f.readJsonFile(_path))
    {
        // reset the current gui
        initGui();

        // load the controllers
        m_lstController.clear();
        count = f.readIntValue("controller:count");

        for (idx = 0; idx < count; idx++)
        {
            aString sName = f.readStringValue(aString("controller:") + aString::fromValue(idx) + ":name");
            aString sAddress = f.readStringValue(aString("controller:") + aString::fromValue(idx) + ":address");

            addController(sName.toQString(), sAddress.toQString());
        }

        // load the universes
        m_lstUniverse.clear();
        count = f.readIntValue("universe:count");

        for (idx = 0; idx < count; idx++)
        {
            aString sName = f.readStringValue(aString("universe:") + aString::fromValue(idx) + ":name");
            aString sController = f.readStringValue(aString("universe:") + aString::fromValue(idx) + ":controller");
            s32 s32Id = f.readIntValue(aString("universe:") + aString::fromValue(idx) + ":id");

            addUniverse(sName.toQString(), sController.toQString(), s32Id);
        }

        // load the devices
        m_lstDevice.clear();
        count = f.readIntValue("device:count");

        for (idx = 0; idx < count; idx++)
        {
            aString     sPre = aString("device:") + aString::fromValue(idx);

            // device name
            aString sName = f.readStringValue(sPre + ":name");

            // device image
            aString sImage = f.readStringValue(sPre + ":image");

            // device channels
            vector<shared_ptr<ChannelDevice>> vChannel;

            s32 channelCount = f.readIntValue(sPre + aString(":channelCount"));

            for (s32 iChannelIdx = 0; iChannelIdx <  channelCount; iChannelIdx++)
            {
                s32 s32Nr = f.readIntValue(sPre + ":channel" + aString::fromValue(iChannelIdx) + ":nr");
                QString sName = f.readStringValue(sPre + ":channel" + aString::fromValue(iChannelIdx) + ":name").toQString();
                QString sPixmapName = f.readStringValue(sPre + ":channel" + aString::fromValue(iChannelIdx) + ":pixmapName").toQString();
                bool bBrightness = f.readBoolValue(sPre + ":channel" + aString::fromValue(iChannelIdx) + ":bright");

                vChannel.push_back(make_shared<ChannelDevice> (s32Nr, sName, sPixmapName, bBrightness));
            }

            addDevice(sName.toQString(), sImage.toQString(), vChannel);
        }

        // load the fixtures
        m_lstFixture.clear();
        count = f.readIntValue("fixture:count");

        for (idx = 0; idx < count; idx++)
        {
            // fixture name
            QString sName = f.readStringValue(aString("fixture:") + aString::fromValue(idx) + ":name").toQString();

            QString sDevice = f.readStringValue(aString("fixture:") + aString::fromValue(idx) + ":device").toQString();
            shared_ptr<Device> pDevice = findDevice(sDevice);

            QString sUniverse = f.readStringValue(aString("fixture:") + aString::fromValue(idx) + ":universe").toQString();
            shared_ptr<Universe> pUniverse = findUniverse(sUniverse);
            s32 s32Adress = f.readStringValue(aString("fixture:") + aString::fromValue(idx) + ":adress").to_s32();

            // create the fixture
            // this also attaches the fixture to the universe, which sets e.g. the brightness flags
            addFixture(sName, pDevice, pUniverse, s32Adress);
        }
    }


    ///////////////////////////////////////////
    // load the banks
    ///////////////////////////////////////////
    s32 bank_count = f.readIntValue(aString("banks:bank_set_count"));
    s32 bank_button_count = f.readIntValue(aString("banks:bank_button_count"));

    for (s32 iBank = 0; iBank < bank_count; iBank++)
    {
        for (s32 iFix = 0; iFix < bank_button_count; iFix++)
        {
            aString sKey = aString("banks:") + aString::fromValue(iBank) + "-" + aString::fromValue(iFix);
            QString sFixName = f.readStringValue(sKey).toQString();
            shared_ptr<Fixture> pFix = findFixture(sFixName);
            stBankBtn &bankBtn = m_vvBankButtons.at(iBank).at(iFix);

            // set the fixture in the tuple
            bankBtn.pFixture = pFix;
        }
    }


    ///////////////////////////////////////////
    // load the scenes
    ///////////////////////////////////////////
    s32 scene_set_count = f.readIntValue(aString("scenes:scene_set_count"));
    s32 scene_button_count = f.readIntValue(aString("scenes:scene_button_count"));

    for (s32 iSet = 0; iSet < scene_set_count; iSet++)
    {
        for (s32 iScene = 0; iScene < scene_button_count; iScene++)
        {
            aString sKey = aString("scenes:") + aString::fromValue(iSet) + "-" + aString::fromValue(iScene);
            auto &sceneBtn  = m_vvSceneButtons.at(iSet).at(iScene);

            // load the scene name
            QString sSceneName = f.readStringValue(sKey + ":name").toQString();

            if (sSceneName != "-")
            {
                // load the blackStart
                bool bBlackStart = f.readBoolValue(sKey + ":black_start");

                // load the fixture count
                s32 s32fixCount = f.readIntValue(sKey + ":fixture_count");

                // create the scene and add it to the scene button
                shared_ptr<Scene> pScene = make_shared<Scene> (sSceneName, bBlackStart);
                sceneBtn.pBtn->setScene(pScene);
                sceneBtn.pScene = pScene;

                // read the fixtures
                for (int iFixIdx = 0; iFixIdx < s32fixCount; iFixIdx++)
                {
                    aString sFixKey = sKey + ":fixture-" +  aString::fromValue(iFixIdx);

                    // read the fixture parameter => fixture
                    QString sFixName = f.readStringValue(sFixKey + ":fixture_name").toQString();
                    s32     s32ChannelCount = f.readIntValue(sFixKey + ":channel_count");

                    shared_ptr<Fixture> pFix = findFixture(sFixName);

                    if (pFix)
                    {
                        mapChannelValue     channelValue;

                        // read the channel values of the fixture
                        for (int iChannel = 0; iChannel < s32ChannelCount; iChannel++)
                        {
                            aString sChannelKey = sFixKey + ":channel-" +  aString::fromValue(iChannel);
                            s32     iChannelNr  = f.readIntValue(sChannelKey + ":channel-nr");
                            u8      u8Value     = static_cast<u8> (f.readIntValue(sChannelKey + ":channel-value"));

                            channelValue[iChannelNr] = u8Value;
                        }

                        // add the fixture to the scene
                        pScene->addFixture(pFix, channelValue);
                    }
                }

            }
            else
            {
                sceneBtn.pBtn->setScene(nullptr);
                sceneBtn.pScene = nullptr;
            }
        }
    }


    ///////////////////////////////////////////
    // load the chases
    ///////////////////////////////////////////
    s32 chase_set_count = f.readIntValue(aString("chases:chase_set_count"));
    s32 chase_button_count = f.readIntValue(aString("chases:chase_button_count"));

    for (s32 iSet = 0; iSet < chase_set_count; iSet++)
    {
        for (s32 iChase = 0; iChase < chase_button_count; iChase++)
        {
            aString sKey = aString("chases:") + aString::fromValue(iSet) + "-" + aString::fromValue(iChase);
            auto &chaseBtn  = m_vvChaseButtons.at(iSet).at(iChase);

            // load the chase name
            QString sChaseName = f.readStringValue(sKey + ":name").toQString();

            if (sChaseName != "-")
            {
                vector<stChaseStep>     vSteps;

                // load the blackStart
                bool bBlackStart = f.readBoolValue(sKey + ":black_start");
                bool bCycle = f.readBoolValue(sKey + ":cycle");

                // read the number of steps
                int iSteps = f.readIntValue(sKey + ":no_of_chase_steps");
                // read the steps
                for (int i = 0; i < iSteps; i++)
                {
                     QString sSceneName = f.readStringValue(sKey + ":step" + aString::fromValue(i) + ":scene_name").toQString();
                     int iDuration_ms = f.readIntValue(sKey + ":step" + aString::fromValue(i) + ":duration");

                     vSteps.push_back(stChaseStep { sSceneName, static_cast<u32> (iDuration_ms) } );
                }

                // create the chase
                shared_ptr<Chase> pChase = make_shared<Chase> (sChaseName, bBlackStart, bCycle, vSteps);
                chaseBtn.pBtn->setChase(pChase);
                chaseBtn.pChase = pChase;
            }
        }
    }

    // reset all universes and update all
    resetAllUniverses();
    updateAll();
} // MainWin::openFile


/*******************************************************************************
* MainWin::saveFile
*******************************************************************************/
void MainWin::saveFile(aPath _path)
{
    // ask for saving
    if (QMessageBox::question(this, "Save", "Overwrite Configuration?",
                              QMessageBox::Yes | QMessageBox::No) == QMessageBox::No)
    {
        return;
    }

    aJsonFile   f;
    s32         idx;

    // save the controllers
    f.addValue(aString("controller:count"), (int) m_lstController.size());
    idx = 0;
    for (const shared_ptr<Controller> &c : m_lstController)
    {
        f.addValue(aString("controller:") + aString::fromValue(idx) + ":name", aString::fromQString(c->name()));
        f.addValue(aString("controller:") + aString::fromValue(idx) + ":address", aString::fromQString(c->ipAdr()));
        idx++;
    }

    // save the universes
    f.addValue(aString("universe:count"), (int) m_lstUniverse.size());
    idx = 0;
    for (const shared_ptr<Universe> &pU : m_lstUniverse)
    {
        shared_ptr<Controller> pC = pU->controller();

        // universe name
        f.addValue(aString("universe:") + aString::fromValue(idx) + ":name", aString::fromQString(pU->name()));

        if (pC)
        {
            // we have a controller
            f.addValue(aString("universe:") + aString::fromValue(idx) + ":controller", aString::fromQString(pC->name()));
            f.addValue(aString("universe:") + aString::fromValue(idx) + ":id", (int) pU->id());
        }
        else
        {
            // no controller => no controller name and no universe id
            f.addValue(aString("universe:") + aString::fromValue(idx) + ":controller", "");
            f.addValue(aString("universe:") + aString::fromValue(idx) + ":id", -1);
        }

        idx++;
    }

    // save the devices
    f.addValue(aString("device:count"), (int) m_lstDevice.size());
    idx = 0;
    for (const shared_ptr<Device> &pD : m_lstDevice)
    {
        aString     sPre = aString("device:") + aString::fromValue(idx);

        // device name
        f.addValue(sPre + ":name", aString::fromQString(pD->name()));

        // device image
        f.addValue(sPre + ":image", aString::fromQString(pD->pixmapName()));

        // device channels
        const vector<shared_ptr<ChannelDevice>> &vChannel   = pD->channel();
        s32                                     iChannelIdx = 0;

        f.addValue(sPre + aString(":channelCount"), (int) vChannel.size()); // device channel count
        for (auto pC : vChannel)
        {
            f.addValue(sPre + ":channel" + aString::fromValue(iChannelIdx) + ":nr", (int) pC->nr());
            f.addValue(sPre + ":channel" + aString::fromValue(iChannelIdx) + ":name", aString::fromQString(pC->name()));
            f.addValue(sPre + ":channel" + aString::fromValue(iChannelIdx) + ":pixmapName", aString::fromQString(pC->pixmapName()));
            f.addValue(sPre + ":channel" + aString::fromValue(iChannelIdx) + ":bright", pC->isBrightnessChannel());

            iChannelIdx++;
        }

        idx++;
    }

    // save the fixtures
    f.addValue(aString("fixture:count"), (int) m_lstFixture.size());
    idx = 0;
    for (const shared_ptr<Fixture> &pF : m_lstFixture)
    {
        // fixture name
        f.addValue(aString("fixture:") + aString::fromValue(idx) + ":name", aString::fromQString(pF->name()));

        // device name
        f.addValue(aString("fixture:") + aString::fromValue(idx) + ":device", aString::fromQString(pF->device()->name()));

        // universe name
        f.addValue(aString("fixture:") + aString::fromValue(idx) + ":universe", aString::fromQString(pF->universe()->name()));

        // fixture adress
        f.addValue(aString("fixture:") + aString::fromValue(idx) + ":adress", aString::fromValue(pF->adress()));

        idx++;
    }

    // save the banks
    f.addValue(aString("banks:bank_set_count"), BANK_SET_COUNT);
    f.addValue(aString("banks:bank_button_count"), BANK_BTN_COUNT);

    for (s32 iBank = 0; iBank < BANK_SET_COUNT; iBank++)
    {
        for (s32 iFix = 0; iFix < BANK_BTN_COUNT; iFix++)
        {
            aString sKey = aString("banks:") + aString::fromValue(iBank) + "-" + aString::fromValue(iFix);
            shared_ptr<Fixture> pFix = m_vvBankButtons.at(iBank).at(iFix).pFixture;
            QString sFix = (pFix)?   pFix->name() : "";

            f.addValue(sKey, aString::fromQString(sFix));
        }
    }

    ///////////////////////////////////////////
    // save the scenes
    ///////////////////////////////////////////
    f.addValue(aString("scenes:scene_set_count"), SCENE_SET_COUNT);
    f.addValue(aString("scenes:scene_button_count"), SCENE_BTN_COUNT);

    // iterate over all scene sets
    for (s32 iSet = 0; iSet < SCENE_SET_COUNT; iSet++)
    {
        // iterate over all scene button within the current set
        for (s32 iScene = 0; iScene < SCENE_BTN_COUNT; iScene++)
        {
            aString sKey = aString("scenes:") + aString::fromValue(iSet) + "-" + aString::fromValue(iScene);
            const stSceneBtn &sceneBtn  = m_vvSceneButtons.at(iSet).at(iScene);
            shared_ptr<Scene> pScene = sceneBtn.pScene;

            if (!pScene)
            {
                // no scene for this button
                f.addValue(sKey + ":name", aString("-"));
            }
            else
            {
                // save the scene name
                f.addValue(sKey + ":name", aString::fromQString(pScene->name()));

                // save the blackStart
                f.addValue(sKey + ":black_start", pScene->isBlackStart());

                // save the fixtures for this scene
                const vector<shared_ptr<Fixture>>   &vFix = pScene->fixtures();
                f.addValue(sKey + ":fixture_count", (int) vFix.size());

                int iFixIdx = 0;
                for (const shared_ptr<Fixture>  &pFix : vFix)
                {
                    aString sFixKey = sKey + ":fixture-" +  aString::fromValue(iFixIdx);
                    // save the fixture name
                    f.addValue(sFixKey + ":fixture_name", aString::fromQString(pFix->name()));

                    // add the channels and values
                    const mapChannelValue *pMapChannelValue = pScene->findChannelValues(pFix);
                    if (!pMapChannelValue)
                    {
                        f.addValue(sFixKey + ":channel_count", 0);
                    }
                    else
                    {
                        f.addValue(sFixKey + ":channel_count", (int) pMapChannelValue->size());

                        int iChannel = 0;
                        for (const auto& [key, value] : (*pMapChannelValue))
                        {
                            aString sChannelKey = sFixKey + ":channel-" +  aString::fromValue(iChannel);
                            f.addValue(sChannelKey + ":channel-nr", (int) key);
                            f.addValue(sChannelKey + ":channel-value", (int) value);
                            iChannel++;
                        }
                    }

                    iFixIdx++;
                }
            }
        }
    }


    ///////////////////////////////////////////
    // save the chases
    ///////////////////////////////////////////
    f.addValue(aString("chases:chase_set_count"), CHASE_SET_COUNT);
    f.addValue(aString("chases:chase_button_count"), CHASE_BTN_COUNT);

    // iterate over all chase sets
    for (s32 iSet = 0; iSet < CHASE_SET_COUNT; iSet++)
    {
        // iterate over all scene button within the current set
        for (s32 iChase = 0; iChase < CHASE_BTN_COUNT; iChase++)
        {
            aString sKey = aString("chases:") + aString::fromValue(iSet) + "-" + aString::fromValue(iChase);
            const stChaseBtn &chaseBtn  = m_vvChaseButtons.at(iSet).at(iChase);
            shared_ptr<Chase> pChase = chaseBtn.pChase;

            if (pChase)
            {
                const vector<stChaseStep>   &vSteps = pChase->chaseSteps();
                int                         iStep   = 0;

                // save the chase name
                f.addValue(sKey + ":name", aString::fromQString(pChase->name()));

                // save the blackStart
                f.addValue(sKey + ":black_start", pChase->isBlackStart());
                f.addValue(sKey + ":cycle", pChase->isCycle());

                // save number of chase steps and the steps
                f.addValue(sKey + ":no_of_chase_steps", (int) vSteps.size());
                for (const stChaseStep &step : vSteps)
                {
                    f.addValue(sKey + ":step" + aString::fromValue(iStep) + ":scene_name", aString::fromQString(step.sSceneName));
                    f.addValue(sKey + ":step" + aString::fromValue(iStep) + ":duration", (int) step.u32Duration_ms);
                    iStep++;
                }
            }
            else
            {
                // no chase for this button
                f.addValue(sKey + ":name", aString("-"));
            }
        }
    }

    // write the file to disk
    f.writeJsonFile(_path);
} // MainWin::saveFile


/*******************************************************************************
* MainWin::onPanel
*******************************************************************************/
void MainWin::onPanel()
{
    m_pUi->m_pPanelDock->setVisible(!m_pUi->m_pPanelDock->isVisible());
    updateToolbar();
} // MainWin::onPanel


/*******************************************************************************
* MainWin::onShowValues
*******************************************************************************/
void MainWin::onShowValues()
{
    m_bShowValues = !m_bShowValues;

    updateToolbar();
    updateFaders();
} // MainWin::onShowValues


/*******************************************************************************
* MainWin::onAddController
*******************************************************************************/
void MainWin::onAddController(bool /*_bChecked*/)
{
    shared_ptr<Controller> pController;

    DlgController   dlg(this, pController);

    dlg.exec();
} // MainWin::onAddController


/*******************************************************************************
* MainWin::onRemoveController
*******************************************************************************/
void MainWin::onRemoveController(bool /*_bChecked*/)
{
    QTableWidget *pT = m_pUi->m_pControllerTable;

    s32 s32Row = pT->currentRow();

    // -1 => now row selected
    if (s32Row >= 0)
    {
        QString sName = pT->item(s32Row, 0)->text();

        m_lstController.remove_if([&sName](shared_ptr<Controller> pCtrl)
                                   { return pCtrl->name() == sName; });
    }

    updateAll();
} // MainWin::onRemoveController


/*******************************************************************************
* MainWin::onEditController
*******************************************************************************/
void MainWin::onEditController(bool /*_bChecked*/)
{
    QTableWidget *pT = m_pUi->m_pControllerTable;

    s32 s32Row = pT->currentRow();

    // -1 => now row selected
    if (s32Row >= 0)
    {
        QString sName = pT->item(s32Row, 0)->text();

        shared_ptr<Controller> pController = findController(sName);

        DlgController   dlg(this, pController);
        dlg.exec();
    }
} // MainWin::onEditController


/*******************************************************************************
* MainWin::onAddUniverse
*******************************************************************************/
void MainWin::onAddUniverse(bool /*_bChecked*/)
{
    shared_ptr<Universe> pUniverse;

    DlgUniverse dlg(this, m_lstController, pUniverse);

    dlg.exec();
} // MainWin::onAddUniverse


/*******************************************************************************
* MainWin::onRemoveUniverse
*******************************************************************************/
void MainWin::onRemoveUniverse(bool /*_bChecked*/)
{
    QTableWidget *pT = m_pUi->m_pUniverseTable;

    s32 s32Row = pT->currentRow();

    // -1 => now row selected
    if (s32Row >= 0)
    {
        QString sName = pT->item(s32Row, 0)->text();

        m_lstUniverse.remove_if([&sName](shared_ptr<Universe> pUniverse)
                                    {
                                        return pUniverse->name() == sName;
                                    });
    }

    updateAll();
} // MainWin::onRemoveUniverse


/*******************************************************************************
* MainWin::onEditUniverse
*******************************************************************************/
void MainWin::onEditUniverse(bool /*_bChecked*/)
{
    QTableWidget *pT = m_pUi->m_pUniverseTable;

    s32 s32Row = pT->currentRow();

    // -1 => now row selected
    if (s32Row >= 0)
    {
        QString sName = pT->item(s32Row, 0)->text();

        shared_ptr<Universe> pUniverse = findUniverse(sName);

        DlgUniverse   dlg(this, m_lstController, pUniverse);
        dlg.exec();
    }
} // MainWin::onEditUniverse


/*******************************************************************************
* MainWin::onAddDevice
*******************************************************************************/
void MainWin::onAddDevice(bool /*_bChecked*/)
{
    shared_ptr<Device> pDevice;

    DlgDevice dlg(this, m_lstDeviceIconName, m_lstChannelIcon, pDevice);

    dlg.exec();
} // MainWin::onAddDevice


/*******************************************************************************
* MainWin::onRemoveDevice
*******************************************************************************/
void MainWin::onRemoveDevice(bool /*_bChecked*/)
{
    QTableWidget *pT = m_pUi->m_pDeviceTable;

    s32 s32Row = pT->currentRow();

    // -1 => now row selected
    if (s32Row >= 0)
    {
        QString sName = pT->item(s32Row, 1)->text();

        m_lstDevice.remove_if([&sName](shared_ptr<Device> pDevice)
                                    {
                                        return pDevice->name() == sName;
                                    });
    }

    updateAll();
} // MainWin::onRemoveDevice


/*******************************************************************************
* MainWin::onEditDevice
*******************************************************************************/
void MainWin::onEditDevice(bool /*_bChecked*/)
{
    QTableWidget *pT = m_pUi->m_pDeviceTable;

    s32 s32Row = pT->currentRow();

    // -1 => now row selected
    if (s32Row >= 0)
    {
        QString sName = pT->item(s32Row, 1)->text();

        shared_ptr<Device> pDevice = findDevice(sName);

        DlgDevice   dlg(this, m_lstDeviceIconName, m_lstChannelIcon, pDevice);
        dlg.exec();
    }
} // MainWin::onEditDevice


/*******************************************************************************
* MainWin::onAddFixture
*******************************************************************************/
void MainWin::onAddFixture(bool /*_bChecked*/)
{
    DlgFixture dlg(this, m_lstDevice, m_lstUniverse, nullptr);

    dlg.exec();
} // MainWin::onAddFixture


/*******************************************************************************
* MainWin::onRemoveFixture
*******************************************************************************/
void MainWin::onRemoveFixture(bool /*_bChecked*/)
{
    QTableWidget *pT = m_pUi->m_pFixtureTable;

    s32 s32Row = pT->currentRow();

    // -1 => now row selected
    if (s32Row >= 0)
    {
        QString sName = pT->item(s32Row, 1)->text();

        m_lstFixture.remove_if([&sName](shared_ptr<Fixture> pFixture)
                                    {
                                        return pFixture->name() == sName;
                                    });
    }

    updateAll();
} // MainWin::onRemoveFixture


/*******************************************************************************
* MainWin::onEditFixture
*******************************************************************************/
void MainWin::onEditFixture(bool /*_bChecked*/)
{
    QTableWidget *pT = m_pUi->m_pFixtureTable;

    s32 s32Row = pT->currentRow();

    // -1 => now row selected
    if (s32Row >= 0)
    {
        QString sName = pT->item(s32Row, 1)->text();

        shared_ptr<Fixture> pFixture = findFixture(sName);

        DlgFixture   dlg(this, m_lstDevice, m_lstUniverse, pFixture);
        dlg.exec();
    }
} // MainWin::onEditFixture


/*******************************************************************************
* MainWin::onBankSelector_1
*******************************************************************************/
void MainWin::onBankSelector_1(bool /*_bChecked*/)
{
    if (m_s32ActiveBank != BANK_1)
    {
        m_s32ActiveBank = BANK_1;
        m_pActiveFixture = nullptr;

        activateBankButton(m_pActiveFixture);

        updateBankButtons();

        assignFaders(nullptr);
    }
} // MainWin::onBankSelector_1


/*******************************************************************************
* MainWin::onBankSelector_2
*******************************************************************************/
void MainWin::onBankSelector_2(bool /*_bChecked*/)
{
    if (m_s32ActiveBank != BANK_2)
    {
        m_s32ActiveBank = BANK_2;
        m_pActiveFixture = nullptr;

        activateBankButton(m_pActiveFixture);

        updateBankButtons();

        assignFaders(nullptr);
    }
} // MainWin::onBankSelector_2


/*******************************************************************************
* MainWin::onBankSelector_3
*******************************************************************************/
void MainWin::onBankSelector_3(bool /*_bChecked*/)
{
    if (m_s32ActiveBank != BANK_3)
    {
        m_s32ActiveBank = BANK_3;
        m_pActiveFixture = nullptr;

        activateBankButton(m_pActiveFixture);

        updateBankButtons();

        assignFaders(nullptr);
    }
} // MainWin::onBankSelector_3


/*******************************************************************************
* MainWin::onBankSelector_4
*******************************************************************************/
void MainWin::onBankSelector_4(bool /*_bChecked*/)
{
    if (m_s32ActiveBank != BANK_4)
    {
        m_s32ActiveBank = BANK_4;
        m_pActiveFixture = nullptr;

        activateBankButton(m_pActiveFixture);

        updateBankButtons();

        assignFaders(nullptr);
    }
} // MainWin::onBankSelector_4


/*******************************************************************************
* MainWin::onBankSelector_5
*******************************************************************************/
void MainWin::onBankSelector_5(bool /*_bChecked*/)
{
    if (m_s32ActiveBank != BANK_5)
    {
        m_s32ActiveBank = BANK_5;
        m_pActiveFixture = nullptr;

        activateBankButton(m_pActiveFixture);

        updateBankButtons();

        assignFaders(nullptr);
    }
} // MainWin::onBankSelector_5


/*******************************************************************************
* MainWin::onClearBank
*******************************************************************************/
void MainWin::onClearBank(bool /*_bChecked*/)
{
    // confirm deletion
    if (QMessageBox::question(this, "Delete Fixtures", "Really delete all\nfixtures in this set?",
                              QMessageBox::Yes | QMessageBox::No) == QMessageBox::No)
    {
        return;
    }

    vector<stBankBtn> &vBankBtn = m_vvBankButtons.at(m_s32ActiveBank);

    for (stBankBtn &bankBtn : vBankBtn)
    {
        bankBtn.pBtn->setFixture(nullptr);
        bankBtn.pFixture = nullptr;
    }

    updateBankButtons();

    assignFaders(nullptr);
} // MainWin::onClearBank


/*******************************************************************************
* MainWin::onResetFixtures
*******************************************************************************/
void MainWin::onResetFixtures(bool /*_bChecked*/)
{
    vector<stBankBtn> &vBankBtn = m_vvBankButtons.at(m_s32ActiveBank);

    for (stBankBtn &bankBtn : vBankBtn)
    {
        shared_ptr<Fixture> pFix = bankBtn.pFixture;

        if (pFix)
        {
            pFix->resetFixture();
        }
    }

    updateFaders();
} // MainWin::onResetFixtures


/*******************************************************************************
* MainWin::onSceneSelector_1
*******************************************************************************/
void MainWin::onSceneSelector_1(bool /*_bChecked*/)
{
    m_s32ActiveScene = SCENE_1;
    updateSceneButtons();
} // MainWin::onSceneSelector_1


/*******************************************************************************
* MainWin::onSceneSelector_2
*******************************************************************************/
void MainWin::onSceneSelector_2(bool /*_bChecked*/)
{
    m_s32ActiveScene = SCENE_2;
    updateSceneButtons();
} // MainWin::onSceneSelector_2


/*******************************************************************************
* MainWin::onSceneSelector_3
*******************************************************************************/
void MainWin::onSceneSelector_3(bool /*_bChecked*/)
{
    m_s32ActiveScene = SCENE_3;
    updateSceneButtons();
} // MainWin::onSceneSelector_3


/*******************************************************************************
* MainWin::onSceneSelector_4
*******************************************************************************/
void MainWin::onSceneSelector_4(bool /*_bChecked*/)
{
    m_s32ActiveScene = SCENE_4;
    updateSceneButtons();
} // MainWin::onSceneSelector_4


/*******************************************************************************
* MainWin::onSceneSelector_5
*******************************************************************************/
void MainWin::onSceneSelector_5(bool /*_bChecked*/)
{
    m_s32ActiveScene = SCENE_5;
    updateSceneButtons();
} // MainWin::onSceneSelector_5


/*******************************************************************************
* MainWin::onClearScenes
*******************************************************************************/
void MainWin::onClearScenes(bool /*_bChecked*/)
{
    // confirm deletion
    if (QMessageBox::question(this, "Delete Scenes", "Really delete all\nscenes in this set?",
                              QMessageBox::Yes | QMessageBox::No) == QMessageBox::No)
    {
        return;
    }

    vector<stSceneBtn> &vSceneBtn = m_vvSceneButtons.at(m_s32ActiveScene);

    for (stSceneBtn &sceneBtn : vSceneBtn)
    {
        sceneBtn.pBtn->setScene(nullptr);
        sceneBtn.pScene = nullptr;
    }

    updateSceneButtons();
} // MainWin::onClearScenes


/*******************************************************************************
* MainWin::onChaseSelector_1
*******************************************************************************/
void MainWin::onChaseSelector_1(bool /*_bChecked*/)
{
    m_s32ActiveChase = CHASE_1;
    updateChaseButtons();
} // MainWin::onChaseSelector_1


/*******************************************************************************
* MainWin::onChaseSelector_2
*******************************************************************************/
void MainWin::onChaseSelector_2(bool /*_bChecked*/)
{
    m_s32ActiveChase = CHASE_2;
    updateChaseButtons();
} // MainWin::onChaseSelector_2


/*******************************************************************************
* MainWin::onChaseSelector_3
*******************************************************************************/
void MainWin::onChaseSelector_3(bool /*_bChecked*/)
{
    m_s32ActiveChase = CHASE_3;
    updateChaseButtons();
} // MainWin::onChaseSelector_3


/*******************************************************************************
* MainWin::onChaseSelector_4
*******************************************************************************/
void MainWin::onChaseSelector_4(bool /*_bChecked*/)
{
    m_s32ActiveChase = CHASE_4;
    updateChaseButtons();
} // MainWin::onChaseSelector_4


/*******************************************************************************
* MainWin::onChaseSelector_5
*******************************************************************************/
void MainWin::onChaseSelector_5(bool /*_bChecked*/)
{
    m_s32ActiveChase = CHASE_5;
    updateChaseButtons();
} // MainWin::onChaseSelector_5


/*******************************************************************************
* MainWin::onClearChases
*******************************************************************************/
void MainWin::onClearChases(bool /*_bChecked*/)
{
    // confirm deletion
    if (QMessageBox::question(this, "Delete Chases", "Really delete all\nchases in this set?",
                              QMessageBox::Yes | QMessageBox::No) == QMessageBox::No)
    {
        return;
    }

    vector<stChaseBtn> &vChaseBtn = m_vvChaseButtons.at(m_s32ActiveChase);

    for (stChaseBtn &chaseBtn : vChaseBtn)
    {
        chaseBtn.pBtn->setChase(nullptr);
        chaseBtn.pChase = nullptr;
    }

    updateChaseButtons();
} // MainWin::onClearChases


/*******************************************************************************
* MainWin::onFader...
*******************************************************************************/
void MainWin::onFaderIn_1s(bool /*_bChecked*/)      { onStartFaderIn(20, 1000); }
void MainWin::onFaderIn_2s(bool /*_bChecked*/)      { onStartFaderIn(40, 2000); }
void MainWin::onFaderIn_3s(bool /*_bChecked*/)      { onStartFaderIn(60, 3000); }
void MainWin::onFaderIn_5s(bool /*_bChecked*/)      { onStartFaderIn(100, 5000); }
void MainWin::onFaderIn_10s(bool /*_bChecked*/)     { onStartFaderIn(200, 10000); }

void MainWin::onFaderOut_1s(bool /*_bChecked*/)     { onStartFaderOut(20, 1000); }
void MainWin::onFaderOut_2s(bool /*_bChecked*/)     { onStartFaderOut(40, 2000); }
void MainWin::onFaderOut_3s(bool /*_bChecked*/)     { onStartFaderOut(60, 3000); }
void MainWin::onFaderOut_5s(bool /*_bChecked*/)     { onStartFaderOut(100, 5000); }
void MainWin::onFaderOut_10s(bool /*_bChecked*/)    { onStartFaderOut(200, 10000); }


/*******************************************************************************
* MainWin::onStartFaderIn
*******************************************************************************/
void MainWin::onStartFaderIn(int    _iSteps,
                             int    _iDuration_ms)
{
    m_fFaderValue           = m_u8MasterBrightness;
    m_fFaderStep            = (255.f - m_fFaderValue) / _iSteps;
    m_u8FaderInterval       = _iDuration_ms / _iSteps;

    QTimer::singleShot(m_u8FaderInterval, this, SLOT(onFade()));
} // MainWin::onStartFaderIn


/*******************************************************************************
* MainWin::onStartFaderOut
*******************************************************************************/
void MainWin::onStartFaderOut(int    _iSteps,
                              int    _iDuration_ms)
{
    m_fFaderValue           = m_u8MasterBrightness;
    m_fFaderStep            = -m_fFaderValue / _iSteps;
    m_u8FaderInterval       = _iDuration_ms / _iSteps;

    QTimer::singleShot(m_u8FaderInterval, this, SLOT(onFade()));
} // MainWin::onStartFaderOut


/*******************************************************************************
* MainWin::onSwitchOn
*******************************************************************************/
void MainWin::onSwitchOn(bool /*_bChecked*/)
{
    setMasterBrightness(255);
} // MainWin::onSwitchOn


/*******************************************************************************
* MainWin::onSwitchOff
*******************************************************************************/
void MainWin::onSwitchOff(bool /*_bChecked*/)
{
    setMasterBrightness(0);
} // MainWin::onSwitchOff


/*******************************************************************************
* MainWin::onFade
*******************************************************************************/
void MainWin::onFade()
{
    if (m_fFaderStep < 0)
    {
        // fade out
        m_fFaderValue = m_fFaderValue + m_fFaderStep;
        setMasterBrightness(static_cast<u8> (max(0.f, m_fFaderValue)));
        if (m_u8MasterBrightness > 0)
        {
            QTimer::singleShot(m_u8FaderInterval, this, SLOT(onFade()));
        }
    }
    else
    {
        // fade in
        m_fFaderValue = m_fFaderValue + m_fFaderStep;
        setMasterBrightness(static_cast<u8> (min(255.f, m_fFaderValue)));
        if (m_u8MasterBrightness < 255)
        {
            QTimer::singleShot(m_u8FaderInterval, this, SLOT(onFade()));
        }
    }
} // MainWin::onFade
