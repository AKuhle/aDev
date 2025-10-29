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
    // ask for loading
    if (QMessageBox::question(this, "Load", "Replace Current Configuration?",
                              QMessageBox::Yes | QMessageBox::No) == QMessageBox::No)
    {
        return;
    }

    aJsonFile   f;
    s32         count, idx;

    // set the path for the configuration
    aPath       sPath   = get_appPath();
    sPath.append("qLights.json");
    sPath = "C:/Tools/aDev/qLights/Documents/qLights.json";

    if (f.readJsonFile(sPath))
    {
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
            vector<shared_ptr<Channel>> vChannel;

            s32 channelCount = f.readIntValue(sPre + aString(":channelCount"));

            for (s32 iChannelIdx = 0; iChannelIdx <  channelCount; iChannelIdx++)
            {
                s32 s32Nr = f.readIntValue(sPre + ":channel" + aString::fromValue(iChannelIdx) + ":nr");
                QString sName = f.readStringValue(sPre + ":channel" + aString::fromValue(iChannelIdx) + ":name").toQString();
                QString sPixmapName = f.readStringValue(sPre + ":channel" + aString::fromValue(iChannelIdx) + ":pixmapName").toQString();
                bool bBrightness = f.readBoolValue(sPre + ":channel" + aString::fromValue(iChannelIdx) + ":bright");

                vChannel.push_back(make_shared<Channel> (s32Nr, sName, sPixmapName, bBrightness));
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

    // load the banks
    s32 bank_count = f.readIntValue(aString("banks:bank_set_count"));
    s32 bank_button_count = f.readIntValue(aString("banks:bank_button_count"));

    for (s32 iBank = 0; iBank < bank_count; iBank++)
    {
        for (s32 iFix = 0; iFix < bank_button_count; iFix++)
        {
            aString sKey = aString("banks:") + aString::fromValue(iBank) + "-" + aString::fromValue(iFix);
            QString sFixName = f.readStringValue(sKey).toQString();
            shared_ptr<Fixture> pFix = findFixture(sFixName);
            BankTuple &tup = m_vvBankButtons.at(iBank).at(iFix);

            // set the fixture in the tuple
            std::get<1> (tup) = pFix;
        }
    }

    // load the scenes
    s32 scene_set_count = f.readIntValue(aString("scenes:scene_set_count"));
    s32 scene_button_count = f.readIntValue(aString("scenes:scene_button_count"));

    for (s32 iSet = 0; iSet < scene_set_count; iSet++)
    {
        for (s32 iScene = 0; iScene < scene_button_count; iScene++)
        {
            aString sKey = aString("scenes:") + aString::fromValue(iSet) + "-" + aString::fromValue(iScene);
            auto &tup  = m_vvSceneButtons.at(iSet).at(iScene);

            QString sSceneName = f.readStringValue(sKey + ":name").toQString();

            if (false && sSceneName != "-")
            {
                s32 s32UniCount = f.readIntValue(sKey + ":universe_count");
                shared_ptr<Scene> pScene = make_shared<Scene> (sSceneName, m_u8MasterBrightness);
                list<shared_ptr<Universe>> lstUniverses;

                std::get<0> (tup)->setScene(pScene);
                std::get<1> (tup) = pScene;

                for (int iUni = 0; iUni < s32UniCount; iUni++)
                {
                    aString sKeyU = sKey + ":universe" + aString::fromValue(iUni);
                    QString sUniName = f.readStringValue(sKeyU + ":name").toQString();
                    shared_ptr<Universe> pUni = findUniverse(sUniName);

                    std::vector<u8> vecDmxData = f.readVectorU8(sKeyU + ":data");

                    // set the dmx data in the universe
                    //pUni->setDmxData(vecDmxData, false);

                    // add the universe to the list
                    lstUniverses.push_back(pUni);
                }

                // add the universes with the data
                pScene->addUniverses(lstUniverses);
            }
            else
            {
                std::get<0> (tup)->setScene(nullptr);
                std::get<1> (tup) = nullptr;
            }
        }
    }

    resetAllUniverses(true);

    updateAll();
} // MainWin::onFileOpen


/*******************************************************************************
* MainWin::onFileSave
*******************************************************************************/
void MainWin::onFileSave()
{
    // ask for saving
    if (QMessageBox::question(this, "Save", "Overwrite Configuration?",
                              QMessageBox::Yes | QMessageBox::No) == QMessageBox::No)
    {
        return;
    }

    aJsonFile   f;
    s32         idx;

    // set the path for the configuration
    aPath       sPath   = get_appPath();
    sPath.append("qLights.json");
    sPath = "C:/Tools/aDev/qLights/Documents/qLights.json";

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
        const vector<shared_ptr<Channel>>   &vChannel   = pD->channel();
        s32                                 iChannelIdx = 0;

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
            shared_ptr<Fixture> pFix = std::get<1> (m_vvBankButtons.at(iBank).at(iFix));
            QString sFix = (pFix)?   pFix->name() : "";

            f.addValue(sKey, aString::fromQString(sFix));
        }
    }

    // save the scenes
    f.addValue(aString("scenes:scene_set_count"), SCENE_SET_COUNT);
    f.addValue(aString("scenes:scene_button_count"), SCENE_BTN_COUNT);

    // iterate over all scene sets
    for (s32 iSet = 0; iSet < SCENE_SET_COUNT; iSet++)
    {
        // iterate over all scene button within the current set
        for (s32 iScene = 0; iScene < SCENE_BTN_COUNT; iScene++)
        {
            aString sKey = aString("scenes:") + aString::fromValue(iSet) + "-" + aString::fromValue(iScene);
            const SceneTuple &tup  = m_vvSceneButtons.at(iSet).at(iScene);
            shared_ptr<Scene> pScene = std::get<1> (tup);

            if (pScene)
            {
                const list<UniverseTuple> &lstUniverses = pScene->universes();
                f.addValue(sKey + ":name", aString::fromQString(pScene->name()));
                f.addValue(sKey + ":universe_count", (int) lstUniverses.size());

                int iUni = 0;
                for (const UniverseTuple &uniTuple : lstUniverses)
                {
                    shared_ptr<Universe>    pUni        = std::get<0> (uniTuple);
                    aString                 sKeyU       = sKey + ":universe" + aString::fromValue(iUni);

                    // create vector from dmx data
                    size_t count = std::get<1> (uniTuple).size() / sizeof(u8);
                    std::vector<u8> vDmxData(reinterpret_cast<const u8*> (std::get<1> (uniTuple).constData()),
                                             reinterpret_cast<const u8*> (std::get<1> (uniTuple).constData()) + count);


                    // add the universe name
                    f.addValue(sKeyU + ":name", aString::fromQString(pUni->name()));

                    // add the dmx data
                    f.addValue(sKeyU + ":data", vDmxData);

                    iUni++;
                }
            }
            else
            {
                // no scene for this button
                f.addValue(sKey + ":name", aString("-"));
            }
        }
    }

    // write the file to disk
    f.writeJsonFile(sPath);
} // MainWin::onFileSave


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
    vector<BankTuple> &vTup = m_vvBankButtons.at(m_s32ActiveBank);

    for (BankTuple &tup : vTup)
    {
        (std::get<0> (tup))->setFixture(nullptr);
        (std::get<1> (tup)) = nullptr;
    }

    updateBankButtons();

    assignFaders(nullptr);
} // MainWin::onClearBank


/*******************************************************************************
* MainWin::onResetFixtures
*******************************************************************************/
void MainWin::onResetFixtures(bool /*_bChecked*/)
{
    vector<BankTuple> &vTup = m_vvBankButtons.at(m_s32ActiveBank);

    for (BankTuple &tup : vTup)
    {
        shared_ptr<Fixture> pFix = std::get<1> (tup);

        if (pFix)
        {
            pFix->resetFixture(false);
        }
    }

    // send all universes to update the reseted fixtures
    sendAllUniverses();

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
* MainWin::onFaderIn
*******************************************************************************/
void MainWin::onFaderIn(bool /*_bChecked*/)
{
    int     iSteps          = 20;
    int     iDuration_ms    = 2000;

    m_fFaderValue           = m_u8MasterBrightness;
    m_fFaderStep            = (255.f - m_fFaderValue) / iSteps;
    m_u8FaderInterval       = iDuration_ms / iSteps;

    QTimer::singleShot(m_u8FaderInterval, this, SLOT(onFade()));
} // MainWin::onFaderIn


/*******************************************************************************
* MainWin::onFaderOut
*******************************************************************************/
void MainWin::onFaderOut(bool /*_bChecked*/)
{
    int     iSteps          = 20;
    int     iDuration_ms    = 2000;

    m_fFaderValue           = m_u8MasterBrightness;
    m_fFaderStep            = -m_fFaderValue / iSteps;
    m_u8FaderInterval       = iDuration_ms / iSteps;

    QTimer::singleShot(m_u8FaderInterval, this, SLOT(onFade()));
} // MainWin::onFaderOut


/*******************************************************************************
* MainWin::onSwitchOn
*******************************************************************************/
void MainWin::onSwitchOn(bool /*_bChecked*/)
{
    setMasterBrightness(255, true);
} // MainWin::onSwitchOn


/*******************************************************************************
* MainWin::onSwitchOff
*******************************************************************************/
void MainWin::onSwitchOff(bool /*_bChecked*/)
{
    setMasterBrightness(0, true);
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
        setMasterBrightness(static_cast<u8> (max(0.f, m_fFaderValue)), true);
        if (m_u8MasterBrightness > 0)
        {
            QTimer::singleShot(m_u8FaderInterval, this, SLOT(onFade()));
        }
    }
    else
    {
        // fade in
        m_fFaderValue = m_fFaderValue + m_fFaderStep;
        setMasterBrightness(static_cast<u8> (min(255.f, m_fFaderValue)), true);
        if (m_u8MasterBrightness < 255)
        {
            QTimer::singleShot(m_u8FaderInterval, this, SLOT(onFade()));
        }
    }
} // MainWin::onFade
