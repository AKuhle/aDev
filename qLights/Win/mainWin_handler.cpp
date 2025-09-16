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

using namespace std;
using namespace aFrame::aApp;
using namespace aFrame::aUtil;


/*******************************************************************************
* MainWin::onFileOpen
*******************************************************************************/
void MainWin::onFileOpen()
{
} // MainWin::onFileOpen


/*******************************************************************************
* MainWin::onFileSave
*******************************************************************************/
void MainWin::onFileSave()
{
    aPath   sPath = get_appPath();
    sPath.append("qLights.json");

    aJsonFile   f;

    // save the controllers
    for (const unique_ptr<Controller> &c : m_lstController)
    {
        f.addValue(aString("controller:") + c->name(), "Showtec NET-2/3 POCKET");
        f.addValue(aString("controller:") + c->name() + ":adress", c->ipAdr());
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
    DlgController   dlg;

    dlg.exec();
} // MainWin::onAddController
