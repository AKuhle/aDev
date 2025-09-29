/*******************************************************************************
* includes
*******************************************************************************/
#include "aFrame_def.h"

#include "ui_mainWin.h"

#include "aAppBase.h"
#include "mainWin.h"
#include "aJsonFile.h"
#include "aPath.h"

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
            // device name
            aString sName = f.readStringValue(aString("device:") + aString::fromValue(idx) + ":name");

            // device image
            aString sImage = f.readStringValue(aString("device:") + aString::fromValue(idx) + ":image");

            // device channels
            vector<shared_ptr<Channel>> vChannel;

            addDevice(sName.toQString(), sImage.toQString(), vChannel);
        }

        // load the fixtures
        m_lstFixture.clear();
        count = f.readIntValue("fixture:count");

        for (idx = 0; idx < count; idx++)
        {
            // fixture name
            aString sName = f.readStringValue(aString("fixture:") + aString::fromValue(idx) + ":name");

            addFixture(sName.toQString());
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
        const Controller    *pC = pU->controller();

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
        QString sss = pD->pixmapName();
        sss.replace(QChar(92), QChar(47)); // 92 = '\', 47 = '/'
        f.addValue(sPre + ":image", aString::fromQString(sss));

        // device channels
        const vector<shared_ptr<Channel>>   &vChannel   = pD->channel();
        s32                                 iChannelIdx = 0;

        f.addValue(sPre + aString(":channelCount"), (int) vChannel.size()); // device channel count
        for (auto pC : vChannel)
        {
            f.addValue(sPre + ":channel" + aString::fromValue(iChannelIdx) + ":nr", aString::fromValue(pC->nr()));
            f.addValue(sPre + ":channel" + aString::fromValue(iChannelIdx) + ":name", aString::fromQString(pC->name()));
            f.addValue(sPre + ":channel" + aString::fromValue(iChannelIdx) + ":pixmapName", aString::fromQString(pC->pixmapName()));

            iChannelIdx++;
        }


        idx++;
    }

    // save the fixtures
    f.addValue(aString("fixture:count"), (int) m_lstFixture.size());
    idx = 0;
    for (const shared_ptr<Fixture> &pF : m_lstFixture)
    {
        // device name
        f.addValue(aString("fixture:") + aString::fromValue(idx) + ":name", aString::fromQString(pF->name()));

        idx++;
    }

    f.writeJsonFile(sPath);
} // MainWin::onFileSave


/*******************************************************************************
* MainWin::onPanel
*******************************************************************************/
void MainWin::onPanel()
{
    m_pUi->m_pPanelDock->setVisible(!m_pUi->m_pPanelDock->isVisible());
    updateGui();
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
        QString sName = pT->item(s32Row, 0)->text();

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
    Fixture *pFixture = nullptr;

    DlgFixture dlg(this, pFixture);

    dlg.exec();
} // MainWin::onAddFixture
