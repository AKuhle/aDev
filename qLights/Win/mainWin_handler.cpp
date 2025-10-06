/*******************************************************************************
* includes
*******************************************************************************/
#include "aFrame_def.h"

#include "ui_mainWin.h"

#include "aAppBase.h"
#include "mainWin.h"
#include "aJsonFile.h"
#include "aPath.h"
#include "scene.h"

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
            cout << "channelCount" << channelCount << endl;

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

    updateAll();
} // MainWin::onFileOpen


/*******************************************************************************
* MainWin::onFileSave
*******************************************************************************/
void MainWin::onFileSave()
{
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
            f.addValue(sPre + ":channel" + aString::fromValue(iChannelIdx) + ":bright", pC->isBrightness());

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
        for (s32 iFix = 0; iFix < BANK_SET_COUNT; iFix++)
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

    for (s32 iSet = 0; iSet < SCENE_SET_COUNT; iSet++)
    {
        for (s32 iScene = 0; iScene < SCENE_BTN_COUNT; iScene++)
        {
            aString sKey = aString("scenes:") + aString::fromValue(iSet) + "-" + aString::fromValue(iScene);
            SceneButton *pSceneBtn = m_vvSceneButtons.at(iSet).at(iScene);
            shared_ptr<Scene> pScene = pSceneBtn->scene();

            if (pScene)
            {
                f.addValue(sKey + ":name", aString::fromQString(pScene->name()));
            }
            else
            {
                // no scene for this button
                f.addValue(sKey + ":name", aString("-"));
            }
        }
    }


    for (auto pUniverse : m_lstUniverse)
    {
        const QByteArray    &byteArray = pUniverse->dmxData();
        std::vector<u8> vec(byteArray.constBegin(), byteArray.constEnd());

        f.addValue("scenes:1", vec);
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
    updatePanel();
} // MainWin::onPanel


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
                                    {
                                        return pCtrl->name() == sName;
                                    });
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
    m_s32ActiveBank = BANK_1;
    updateBankButtons();
} // MainWin::onBankSelector_1


/*******************************************************************************
* MainWin::onBankSelector_2
*******************************************************************************/
void MainWin::onBankSelector_2(bool /*_bChecked*/)
{
    m_s32ActiveBank = BANK_2;
    updateBankButtons();
} // MainWin::onBankSelector_2


/*******************************************************************************
* MainWin::onBankSelector_3
*******************************************************************************/
void MainWin::onBankSelector_3(bool /*_bChecked*/)
{
    m_s32ActiveBank = BANK_3;
    updateBankButtons();
} // MainWin::onBankSelector_3


/*******************************************************************************
* MainWin::onBankSelector_4
*******************************************************************************/
void MainWin::onBankSelector_4(bool /*_bChecked*/)
{
    m_s32ActiveBank = BANK_4;
    updateBankButtons();
} // MainWin::onBankSelector_4


/*******************************************************************************
* MainWin::onBankSelector_5
*******************************************************************************/
void MainWin::onBankSelector_5(bool /*_bChecked*/)
{
    m_s32ActiveBank = BANK_5;
    updateBankButtons();
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
} // MainWin::onClearBank


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
