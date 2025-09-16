/*******************************************************************************
* includes
*******************************************************************************/
#include "ui_mainWin.h"
#include "aFrame_def.h"

#include "aAppBase.h"
#include "mainWin.h"
#include "aJsonFile.h"
#include "aPath.h"

#include "dlgcontroller.h"
#include "dlgController.h"

using namespace std;
using namespace aFrame::aApp;
using namespace aFrame::aUtil;


/*******************************************************************************
* MainWin::onFileOpen
*******************************************************************************/
void MainWin::onFileOpen()
{
    aJsonFile   f;
    s32         i, j;
    aPath       sPath   = get_appPath();
    sPath.append("qLights.json");

    if (f.readJsonFile(sPath))
    {
        // load the controllers
        m_lstController.clear();
        i = f.readIntValue("controller:count");

        for (j = 0; j < i; j++)
        {
            aString sName = f.readStringValue(aString("controller:") + aString::fromValue(j) + ":name");
            aString sAddress = f.readStringValue(aString("controller:") + aString::fromValue(j) + ":address");

            addController(sName, sAddress);
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
    s32         i;
    aPath       sPath   = get_appPath();
    sPath.append("qLights.json");

    // save the controllers #
    f.addValue(aString("controller:count"), m_lstController.size());

    // save the controllers
    f.addValue(aString("controller:count"), m_lstController.size());
    i = 0;
    for (const unique_ptr<Controller> &c : m_lstController)
    {
        f.addValue(aString("controller:") + aString::fromValue(i) + ":name", c->name());
        f.addValue(aString("controller:") + aString::fromValue(i) + ":address", c->ipAdr());
        i++;
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
    Controller *pController = nullptr;

    DlgController   dlg(this, pController);

    dlg.exec();
} // MainWin::onAddController
