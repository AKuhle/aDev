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

#include "aTitleBar.h"
#include "aSpacer.h"
#include "aToolBtn.h"
#include "aLayoutMainWin.h"

using namespace aFrame::aApp;
using namespace aFrame::aWin;



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

    setGeometry(100, 100, 600, 400);

    // activate drag/drop
    enableDragDrop(true);

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
// * MainWin::onCreateChilds
// *******************************************************************************/
bool MainWin::onCreateChilds()
{
    createTitlebar();
    createStdTooBar();

    return true;
} // MainWin::onCreateChilds


// /*******************************************************************************
// * MainWin::createTitlebar
// *******************************************************************************/
void MainWin::createTitlebar()
{
    aTitleBar   *pTitleBar = titleBar();
    aToolBtn    *pBtn;
    aSpacer     *pSpacer;

    // app button
    pBtn = new aToolBtn(pTitleBar, ":/PhotoLab/photoLab.png", "");
    pBtn->createWin();
    pBtn->setBtnStyle(enumBtnStyle::ICON_STATIC_MODE);
    pBtn->setFixDim(pBtn->sysMetrics());
    //pBtn->addClickHandler([this](aBtn* btn) { onMinimize(btn); });
    pTitleBar->addChild(pBtn);

    // spacer
    pSpacer = new aSpacer(pTitleBar);
    pSpacer->createWin();
    pTitleBar->addChild(pSpacer);

    // minimize button
    pBtn = new aToolBtn(pTitleBar, ":/Standard/Masked/32/minimize.png", "");
    pBtn->createWin();
    pBtn->setFixDim(pBtn->sysMetrics());
    pBtn->addClickHandler([this](aBtn* btn) { onMinimize(btn); });
    pTitleBar->addChild(pBtn);

    // maximize button
    pBtn = new aToolBtn(pTitleBar, ":/Standard/Masked/32/maximize.png", "");
    pBtn->createWin();
    pBtn->setCheckable(true);
    pBtn->setFixDim(pBtn->sysMetrics());
    pBtn->addClickHandler([this](aBtn* btn) { onMaximize(btn); });
    pTitleBar->addChild(pBtn);

    // close button
    pBtn = new aToolBtn(pTitleBar, ":/Standard/Masked/32/close.png", "");
    pBtn->createWin();
    pBtn->setFixDim(pBtn->sysMetrics());
    pBtn->setHoverColor(colRed);
    pBtn->addClickHandler([this](aBtn* btn) { onClose(btn); });
    pTitleBar->addChild(pBtn);
} // MainWin::createTitlebar


// /*******************************************************************************
// * MainWin::createStdTooBar
// *******************************************************************************/
void MainWin::createStdTooBar()
{
    aLayoutMainWin *pLayoutMw = dynamic_cast<aLayoutMainWin *> (layout());
    CHECK_PRE_CONDITION_VOID(pLayoutMw);

    // create the toolbar
    unique_ptr<aToolBar> pToolBar = make_unique<aToolBar> (this);
    pToolBar->createWin();
    pToolBar->setAllowedDockPosition(DOCK_POS_T);
    pToolBar->setDockPosition(DOCK_POS_T);

    aToolBtn    *pBtn;

    // open file button
    pBtn = new aToolBtn(pToolBar.get(), ":/Standard/Masked/32/folder.png", "");
    pBtn->createWin();
    pBtn->setFixDim(pBtn->sysMetrics());
    pBtn->addClickHandler([this](aBtn* btn) { onOpenFile(btn); });
    pToolBar->addChild(pBtn);

    // add the toolbat to the main window
    pLayoutMw->addToolBar(std::move(pToolBar));
} // MainWin::createStdTooBar


// /*******************************************************************************
// * MainWin::onCloseWin
// *******************************************************************************/
bool MainWin::onCloseWin()
{
    // // save the var pool
    // aPath   path = get_appPath() / "vpool.json";
    // m_varPool.writeToJsonFile(path);

    // // save the current win geomatry
    // saveWinGeometry(COMPANY_NAME, APP_NAME);

    return !isBusy();
} // MainWin::onCloseWin


/*******************************************************************************
* MainWin::isBusy
*******************************************************************************/
bool MainWin::isBusy() const
{
    return m_bBusy;
} // MainWin::isBusy



















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
