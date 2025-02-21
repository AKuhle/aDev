/*******************************************************************************
* \file BaseApp.h
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
#include "aMainWinApp.h"
#include "mainWin.h"
#include "aLayoutMainWin.h"
#include "editScrollWin.h"
#include "editView.h"
#include "aMdiWin.h"

#include "stdBar.h"
#include "imageBar.h"
#include "statusBar.h"

using namespace aLib::aApp;
using namespace aLib::aWin;


/*******************************************************************************
* getMainWin
*******************************************************************************/
MainWin& getMainWin()
{
    return *dynamic_cast<MainWin *> (get_aMainWin());
} // getMainWin


/*******************************************************************************
* getActiveView
*******************************************************************************/
ViewBase* getActiveView()
{
    MainWin &mw = getMainWin();
    aMdiWin *pMdiWin = mw.activeMdiWin();
    CHECK_PRE_CONDITION(pMdiWin != nullptr, nullptr);

    // get the scroll window
    EditScrollWin *pEditScrollWin =  dynamic_cast<EditScrollWin *> (pMdiWin->centralWin());
    CHECK_PRE_CONDITION(pEditScrollWin != nullptr, nullptr);

    return dynamic_cast<ViewBase *> (pEditScrollWin->centralWin());
} // getActiveView


/*******************************************************************************
* getActiveDocument
*******************************************************************************/
std::shared_ptr<Document> getActiveDocument()
{
    ViewBase  *pView = getActiveView();

    shared_ptr<aDoc> pDoc = (pView != nullptr)?   pView->doc() : nullptr;

    return dynamic_pointer_cast<Document> (pDoc);
} // getActiveDocument


/*******************************************************************************
* getActiveLS
*******************************************************************************/
shared_ptr<SynchronizedLS> getActiveLS()
{
    shared_ptr<Document> pDoc = getActiveDocument();

    return (pDoc != nullptr)?   pDoc->activeLS() : nullptr;
} // getActiveLS


/*******************************************************************************
* MainWin::MainWin
*******************************************************************************/
MainWin::MainWin()
{
} // MainWin::MainWin


/*******************************************************************************
* MainWin::~MainWin
*******************************************************************************/
MainWin::~MainWin()
{
} // MainWin::~MainWin


/*******************************************************************************
* MainWin::onCreate
*******************************************************************************/
bool MainWin::onCreate()
{
    aLayoutMainWin  *pLayout = dynamic_cast<aLayoutMainWin *> (layout());
    CHECK_PRE_CONDITION(pLayout != nullptr, false);

    // create the standard bar
    StdBar  *pStdBar = new StdBar(this);
    pStdBar->create();
    pLayout->addTopWin(pStdBar);

    // create the image bar
    ImageBar  *pImageBar = new ImageBar(this);
    pImageBar->create();
    pLayout->addRightWin(pImageBar);

    // create the status bar
    StatusBar  *pStatusBar = new StatusBar(this);
    pStatusBar->create();
    pLayout->setStatusBar(pStatusBar);

    setGeometry(50, 50, 640, 360);
    setMinDim(480, 270);

    // enable drop
    enableDrop(true);

    // initialize the gui
    sendUpdateCmd(UPDATE_GUI);

    return true;
} // MainWin::onCreate


/*******************************************************************************
* MainWin::viewList
*******************************************************************************/
aPtrList<ViewBase> MainWin::viewList() const
{
    aPtrList<ViewBase>  lst;

    const aPtrList<aMdiWin> *pLstMdiWin = mdiWinList();

    if (pLstMdiWin != nullptr)
    {
        for (aMdiWin *pMdiWin : *pLstMdiWin)
        {
            EditScrollWin   *pEditScrollWin =  dynamic_cast<EditScrollWin *> (pMdiWin->centralWin());
            ViewBase        *pView          =  dynamic_cast<ViewBase *> (pEditScrollWin->centralWin());

            if (pView != nullptr)
            {
                lst.push_back(pView);
            }
        }
    }

    return lst;
} // MainWin::viewList


/*******************************************************************************
* MainWin::statusBar
*******************************************************************************/
StatusBar* MainWin::statusBar()
{
    aLayoutMainWin *pLayout = dynamic_cast<aLayoutMainWin *> (layout());
    CHECK_PRE_CONDITION(pLayout != nullptr, nullptr);

    return dynamic_cast<StatusBar*> (pLayout->statusBar());
} // MainWin::statusBar


/*******************************************************************************
* MainWin::isThreadRunning
*******************************************************************************/
bool MainWin::isThreadRunning() const
{
    return m_bThreadRunning;
} // MainWin::isThreadRunning
