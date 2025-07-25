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
#include "aAppMainWin.h"
#include "mainWin.h"

// #include "aMdiChild.h"
// #include "editScrollWin.h"
// #include "aDockWin.h"
// #include "aPath.h"
// #include "viewBase.h"
// #include "document.h"
// #include "statusBar.h"
// #include "navigatorToolWin.h"

using namespace aFrame::aApp;
using namespace aFrame::aWin;


/*******************************************************************************
* getMainWin
*******************************************************************************/
// MainWin& getMainWin()
// {
//     return *dynamic_cast<MainWin *> (get_aMainWin());
// } // getMainWin


/*******************************************************************************
* getStatusBar
*******************************************************************************/
// StatusBar& getStatusBar()
// {
//     return getMainWin().mwStatusBar();
// } // getStatusBar


/*******************************************************************************
* getActiveView
*******************************************************************************/
// ViewBase* getActiveView()
// {
//     MainWin     &mw = getMainWin();

//     aMdiChild   *pMdiChild = mw.activeMdiChild();
//     CHECK_PRE_CONDITION(pMdiChild != nullptr, nullptr);

//     // get the scroll window
//     EditScrollWin    *pScroll =  dynamic_cast<EditScrollWin *> (pMdiChild->centralWin());
//     CHECK_PRE_CONDITION(pScroll != nullptr, nullptr);

//     return dynamic_cast<ViewBase *> (pScroll->centralWin());
// } // getActiveView


// /*******************************************************************************
// * getActiveDoc
// *******************************************************************************/
// shared_ptr<Document> getActiveDoc()
// {
//     ViewBase    *pView = getActiveView();
//     CHECK_PRE_CONDITION(pView != nullptr, nullptr);

//     return dynamic_pointer_cast<Document> (pView->doc());
// } // getActiveDoc


// /*******************************************************************************
// * getActiveLS
// *******************************************************************************/
// shared_ptr<SynchronizedLS> getActiveLS()
// {
//     shared_ptr<Document>    pDoc = getActiveDoc();

//     return (pDoc != nullptr)?   pDoc->activeLS() : nullptr;
// } // getActiveLS


// /*******************************************************************************
// * getTopmostView
// *******************************************************************************/
// ViewBase* getTopmostView()
// {
//     MainWin     &mw = getMainWin();

//     aMdiChild   *pMdiChild = mw.topmostMdiChild();
//     CHECK_PRE_CONDITION(pMdiChild != nullptr, nullptr);

//     // get the scroll window
//     EditScrollWin    *pScroll =  dynamic_cast<EditScrollWin *> (pMdiChild->centralWin());
//     CHECK_PRE_CONDITION(pScroll != nullptr, nullptr);

//     return dynamic_cast<ViewBase *> (pScroll->centralWin());
// } // getTopmostView


// /*******************************************************************************
// * getTopmostDoc
// *******************************************************************************/
// shared_ptr<Document> getTopmostDoc()
// {
//     ViewBase    *pView = getTopmostView();
//     CHECK_PRE_CONDITION(pView != nullptr, nullptr);

//     return dynamic_pointer_cast<Document> (pView->doc());
// } // getTopmostDoc


// /*******************************************************************************
// * getTopmostLS
// *******************************************************************************/
// shared_ptr<SynchronizedLS> getTopmostLS()
// {
//     shared_ptr<Document>    pDoc = getTopmostDoc();

//     return (pDoc != nullptr)?   pDoc->activeLS() : nullptr;
// } // getTopmostLS


/*******************************************************************************
* MainWin::MainWin
*******************************************************************************/
MainWin::MainWin()
//: m_pStatusBar(new StatusBar(this))
{
    // #ifdef _USE_QT_
    //     m_pUi = new Ui::FormMainWin;
    //     m_pUi->setupUi(this);
    // #endif
} // MainWin::MainWin


/*******************************************************************************
* MainWin::~MainWin
*******************************************************************************/
MainWin::~MainWin()
{
    // #ifdef _USE_QT_
    //     delete m_pUi;1
    // #endif
} // MainWin::~MainWin


/*******************************************************************************
* MainWin::onCreateWin
*******************************************************************************/
bool MainWin::onCreateWin()
{
    setMinDim(600, 400);


//     // create the navigator dock win
//     m_pNavigatorDockWin = new aDockWin(this);
//     m_pNavigatorDockWin->createWin();
//     m_pNavigatorDockWin->setAllowedAreas(DOCK_POS_LR);
//     addDockWin("Navigator", m_pNavigatorDockWin, DOCK_POS_R);
//     // create the navigator tool win
//     m_pNavigatorToolWin = new NavigatorToolWin;
//     m_pNavigatorToolWin->createWin();
//     m_pNavigatorDockWin->setCentralWin(m_pNavigatorToolWin);

//     // create the status bar
//     m_pStatusBar->createWin();
//     setStatusBar(m_pStatusBar);

//     //setMinSize(600, 400);

//     setEditMode(enumEditMode::Move);

//     // restore the win geomatry
//     restoreWinGeometry(COMPANY_NAME, APP_NAME);

//     aColor c1 = m_varPool.getColor(70);
//     cout << c1 << endl;

//     // read the last variable pool
//     aPath   path = get_appPath() / "vpool.json";
//     m_varPool.readFromJsonFile(path);

//     aColor c2 = m_varPool.getColor(70);
//     cout << c2 << endl;

//     // initial gui update
//     sendUpdateCmd(UPDATE_GUI | UPDATE_CMD_TOOL_WIN);

    return true;
} // MainWin::onCreateWin


// /*******************************************************************************
// * MainWin::onCloseWin
// *******************************************************************************/
// bool MainWin::onCloseWin()
// {
//     // save the var pool
//     aPath   path = get_appPath() / "vpool.json";
//     m_varPool.writeToJsonFile(path);

//     // save the current win geomatry
//     saveWinGeometry(COMPANY_NAME, APP_NAME);

//     return !busy();
// } // MainWin::onCloseWin


// /*******************************************************************************
// * MainWin::busy
// *******************************************************************************/
// bool MainWin::busy() const
// {
//     return m_bBusy;
// } // MainWin::busy


// /*******************************************************************************
// * MainWin::setEditMode
// *******************************************************************************/
// void MainWin::setEditMode(enumEditMode _eMode)
// {
//     m_eEditMode = _eMode;

//     ViewBase *pView = getActiveView();

//     if (pView != nullptr)
//     {
//         pView->setTool(m_eEditMode);
//     }
// } // MainWin::setEditMode


// /*******************************************************************************
// * MainWin::editMode
// *******************************************************************************/
// enumEditMode MainWin::editMode() const
// {
//     return m_eEditMode;
// } // MainWin::editMode


// /*******************************************************************************
// * MainWin::viewList
// *******************************************************************************/
// void MainWin::viewList(aPtrList<ViewBase> &_lstView) const
// {
//     aPtrList<aMdiChild> lstMdiChild;

//     mdiChildList(lstMdiChild);

//     for (aMdiChild *pChild : lstMdiChild)
//     {
//         EditScrollWin   *pScroll = dynamic_cast<EditScrollWin *> (pChild->centralWin());
//         ViewBase        *pView   = (pScroll != nullptr)?   dynamic_cast<ViewBase *> (pScroll->centralWin()) : nullptr;

//         if (pView != nullptr)
//         {
//             _lstView.push_back(pView);
//         }
//     }
// } // MainWin::viewList
