/*******************************************************************************
* includes
*******************************************************************************/
#include "aFrame_def.h"

#include "aAppBase.h"
#include "mainWin.h"
#include "aJsonFile.h"
#include "aPath.h"

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

    aJsonFile   f(sPath);

    // save the controllers
    for (const unique_ptr<Controller> &c : m_lstController)
    {
        f.addValue(aString("controller:") + c->name(), "Showtec NET-2/3 POCKET");
        f.addValue(aString("controller:") + c->name() + ":adress", c->ipAdr());
    }


    f.writeJsonFile();

} // MainWin::onFileSave


/*******************************************************************************
* MainWin::onController
*******************************************************************************/
void MainWin::onController()
{
    //shared_ptr<Controller> pController = createController("Showtec NET-2/3 POCKET", "192.168.1.245", 2);
} // MainWin::onController


/*******************************************************************************
* MainWin::onUniverse
*******************************************************************************/
void MainWin::onUniverse()
{
} // MainWin::onUniverse
