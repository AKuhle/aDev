/*******************************************************************************
* \file mainWin.cpp
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
#include "ui_formMainWin.h"

#include "mainWin.h"
#include "viewBase.h"
#include "DocPl.h"
#include "stdScrollWin.h"

#include "navigatorToolWin.h"
#include "toolBoxToolWin.h"
#include "protocolToolWin.h"
#include "stdMdiWin.h"
#include "viewStd.h"

#include "optionMoveWin.h"
#include "optionZoomWin.h"

#include "toolMove.h"
#include "toolZoom.h"


using namespace qLib;


/*******************************************************************************
* GetMainWin
*******************************************************************************/
MainWin& GetMainWin()
{
    return *dynamic_cast<MainWin *> (Get_qMainWin());
} // GetMainWin


/*******************************************************************************
* GetVarPool
*******************************************************************************/
VarPoolPl& GetVarPool()
{
    return GetMainWin().VarPool();
} // GetVarPool


/*******************************************************************************
* GetActiveView
*******************************************************************************/
ViewBase* GetActiveView()
{
    MainWin &mw = GetMainWin();
    qMdiWin *pMdiWin = mw.ActiveMdiWin();
    CHECK_PRE_CONDITION(pMdiWin != nullptr, nullptr);

    // get the scroll window
    StdScrollWin    *pScroll =  dynamic_cast<StdScrollWin *> (pMdiWin->CentralWin());
    CHECK_PRE_CONDITION(pScroll != nullptr, nullptr);

    return dynamic_cast<ViewBase *> (pScroll->CentralWin());
} // GetActiveView


/*******************************************************************************
* GetActiveDoc
*******************************************************************************/
std::shared_ptr<DocPl> GetActiveDoc()
{
    ViewBase  *pView = GetActiveView();

    return (pView != nullptr)?   pView->Doc() : nullptr;
} // GetActiveDoc


/*******************************************************************************
* GetActiveLS
*******************************************************************************/
shared_ptr<qLayerStack> GetActiveLS()
{
    std::shared_ptr<DocPl> pDoc = GetActiveDoc();

    return (pDoc != nullptr)?   pDoc->ActiveLS() : nullptr;
} // GetActiveLS


/*******************************************************************************
* GetActiveOrTopmostView
*******************************************************************************/
ViewBase* GetActiveOrTopmostView()
{
    MainWin &mw = GetMainWin();
    qMdiWin *pMdiWin = mw.ActiveOrTopmostMdiWin();
    CHECK_PRE_CONDITION(pMdiWin != nullptr, nullptr);

    // get the scroll window
    StdScrollWin    *pScroll =  dynamic_cast<StdScrollWin *> (pMdiWin->CentralWin());
    CHECK_PRE_CONDITION(pScroll != nullptr, nullptr);

    return dynamic_cast<ViewBase *> (pScroll->CentralWin());
} // GetActiveOrTopmostView


/*******************************************************************************
* GetActiveOrTopmostRenderParams
*******************************************************************************/
const RenderParams* GetActiveOrTopmostRenderParams()
{
    ViewBase *pView = GetActiveOrTopmostView();

    return (pView != nullptr)?   &pView->GetRenderParams() : nullptr;
} // GetActiveOrTopmostRenderParams


/*******************************************************************************
* GetActiveOrTopmostDoc
*******************************************************************************/
std::shared_ptr<DocPl> GetActiveOrTopmostDoc()
{
    ViewBase  *pView = GetActiveOrTopmostView();

    return (pView != nullptr)?   pView->Doc() : nullptr;
} // GetActiveOrTopmostDoc


/*******************************************************************************
* GetActiveOrTopmostLS
*******************************************************************************/
shared_ptr<qLayerStack> GetActiveOrTopmostLS()
{
    std::shared_ptr<DocPl> pDoc = GetActiveOrTopmostDoc();

    return (pDoc != nullptr)?   pDoc->ActiveLS() : nullptr;
} // GetActiveOrTopmostLS







/*******************************************************************************
* MainWin::MainWin
*******************************************************************************/
MainWin::MainWin()
: m_pUi(new Ui::FormMainWin)
{
    m_pUi->setupUi(this);
} // MainWin::MainWin


/*******************************************************************************
* MainWin::~MainWin
*******************************************************************************/
MainWin::~MainWin()
{

    delete m_pUi;
} // ~MainWin::MainWin


/*******************************************************************************
* MainWin::OnCreate
*******************************************************************************/
bool MainWin::OnCreate()
{
    // standard toolbar
    m_pUi->m_pTbStandard->SetAllowedDockAreas(DOCK_AREA_VERT | DOCK_AREA_TOP);

    // transform toolbar
    m_pUi->m_pTbTransform->SetAllowedDockAreas(DOCK_AREA_VERT | DOCK_AREA_TOP);


    // create the option pages
    m_pOptionMoveWin = new OptionMoveWin();
    m_pOptionMoveWin->CreateWin();
    m_pOptionMoveWin->SetVisible(false);

    m_pOptionZoomWin = new OptionZoomWin();
    m_pOptionZoomWin->CreateWin();
    m_pOptionZoomWin->SetVisible(false);


    // create the option dock win
    m_pOptionDockWin = new qDockWin();
    m_pOptionDockWin->CreateWin();
    m_pOptionDockWin->SetAllowedDockAreas(DOCK_AREA_TOP);
    AddDockWindow("options", m_pOptionDockWin, DOCK_AREA_TOP);
    m_pNavigatorToolWin = new NavigatorToolWin();
    m_pOptionDockWin->setFeatures(QDockWidget::NoDockWidgetFeatures);
    m_pOptionDockWin->SetTitleBarWin(m_pOptionMoveWin);


    // create the navigator dock win
    m_pNavigatorDockWin = new qDockWin();
    m_pNavigatorDockWin->CreateWin();
    m_pNavigatorDockWin->SetAllowedDockAreas(DOCK_AREA_VERT);
    AddDockWindow("Navigator", m_pNavigatorDockWin, DOCK_AREA_RIGHT);
    // the navigator tool win
    m_pNavigatorToolWin = new NavigatorToolWin();
    m_pNavigatorToolWin->CreateWin();
    m_pNavigatorDockWin->SetCentralWin(m_pNavigatorToolWin);


    // create the toolbox dock win
    m_pToolBoxDockWin = new qDockWin();
    m_pToolBoxDockWin->CreateWin();
    m_pToolBoxDockWin->SetAllowedDockAreas(DOCK_AREA_VERT);
    AddDockWindow("Toolbox", m_pToolBoxDockWin, DOCK_AREA_LEFT);
    // the navigator tool win
    m_pToolBoxToolWin = new ToolBoxToolWin();
    m_pToolBoxToolWin->CreateWin();
    m_pToolBoxDockWin->SetCentralWin(m_pToolBoxToolWin);


    // create the protocol dock win
    m_pProtocolDockWin = new qDockWin();
    m_pProtocolDockWin->CreateWin();
    m_pProtocolDockWin->SetAllowedDockAreas(DOCK_AREA_VERT);
    AddDockWindow("Protocol", m_pProtocolDockWin, DOCK_AREA_RIGHT);
    // the navigator tool win
    m_pProtocolToolWin = new ProtocolToolWin();
    m_pProtocolToolWin->CreateWin();
    m_pProtocolDockWin->SetCentralWin(m_pProtocolToolWin);


    SetAcceptDrops(true);

    // restore the windows geometry
    RestoreWinGeometry("qSoft", "qFotoStudio");

    // send initial gui update cmd
    SetMode(enumMode::Move);

    return true;
} // MainWin::OnCreate


/*******************************************************************************
* MainWin::OnClose
*******************************************************************************/
bool MainWin::OnClose()
{
    SaveWinGeometry("qSoft", "qFotoStudio");

    return true;
} // MainWin::OnClose


/*******************************************************************************
* MainWin::SetMode
*******************************************************************************/
void MainWin::SetMode(enumMode _eMode)
{
    if (m_eMode != _eMode)
    {
        m_eMode = _eMode;

        SendUpdateCmd(UPDATE_MODE_CHANGED);
    }
    else
    {
        // update the gui because a mode-button which already was on could
        // be pressed again and now it is unselectd, even if the mode
        // has not been changed
        SendUpdateCmd(UPDATE_GUI);
    }
} // MainWin::SetMode


/*******************************************************************************
* MainWin::Mode
*******************************************************************************/
enumMode MainWin::Mode() const
{
    return m_eMode;
} // MainWin::Mode


/*******************************************************************************
* MainWin::IsCalculating
*******************************************************************************/
bool MainWin::IsCalculating() const
{
    return m_bCalculating;
} // MainWin::IsCalculating


/*******************************************************************************
* MainWin::UpdateTools
*******************************************************************************/
void MainWin::UpdateTools()
{
    ViewBase            *pView  = GetActiveView();
    unique_ptr<qTool>   pTool;

    qPtrList<qMdiWin>   lstMdiWin;
    GetMdiWinList(lstMdiWin);

    // cancel all tools in all views
    for (qMdiWin *pMdiWin : lstMdiWin)
    {
        StdMdiWin   *pStdMdiWin = dynamic_cast<StdMdiWin *> (pMdiWin);
        ViewStd     *pView      = (pStdMdiWin != nullptr)?   pStdMdiWin->StdView() : nullptr;

        if (pView != nullptr)
        {
            pView->CancelAllTools();
        }
    }

    // start the proper tool in the active view
    if (pView != nullptr)
    {
        switch (m_eMode)
        {
            case enumMode::None:
                break;

            case enumMode::Move:
                pTool = make_unique<ToolMove> (pView);
                m_pOptionDockWin->SetTitleBarWin(m_pOptionMoveWin);
                break;

            case enumMode::Zoom:
                pTool = make_unique<ToolZoom> (pView);
                m_pOptionDockWin->SetTitleBarWin(m_pOptionZoomWin);
                break;

        }
    }

    if (pTool != nullptr)
    {
        pView->SetTool(std::move (pTool));
    }
} // MainWin::UpdateTools


/*******************************************************************************
* MainWin::OnMdiWinActivated
*******************************************************************************/
void MainWin::OnMdiWinActivated(qMdiWin */*_pMdiWin*/)
{
    SendUpdateCmd(UPDATE_VIEW_ACTVATED);
} // MainWin::OnMdiWinActivated


/*******************************************************************************
* MainWin::OnOpenProgressDisplay
*******************************************************************************/
void MainWin::OnOpenProgressDisplay()
{
} // MainWin::OnOpenProgressDisplay


/*******************************************************************************
* MainWin::OnCloseProgressDisplay
*******************************************************************************/
void MainWin::OnCloseProgressDisplay()
{
} // MainWin::OnCloseProgressDisplay


/*******************************************************************************
* MainWin::OnUpdateProgressDisplay
*******************************************************************************/
void MainWin::OnUpdateProgressDisplay(const qString16 &_sInfoText)
{
    cout << "OnMdiWinActivated: " << _sInfoText << endl;
} // MainWin::OnUpdateProgressDisplay


/*******************************************************************************
* MainWin::OnUpdateProgressDisplay
*******************************************************************************/
void MainWin::OnUpdateProgressDisplay(u16 _u16Progress_pml)
{
    cout << "OnMdiWinActivated: " << _u16Progress_pml << endl;
} // MainWin::OnUpdateProgressDisplay






// /*******************************************************************************
// * GetStatusBar
// *******************************************************************************/
// //plStatusBar& GetStatusBar()
// //{
// //    MainWin& mw = GetMainWin();

// //    return mw.AppStatusBar();
// //} // GetStatusBar


// /*******************************************************************************
// * MainWin::OnCreateTitleBar
// *******************************************************************************/
// qTitleBar* MainWin::OnCreateTitleBar()
// {
//     MainWinTitleBar *pTB = new MainWinTitleBar(this, this);
//     pTB->CreateWin();

//     return pTB;
// } // MainWin::OnCreateTitleBar


// /*******************************************************************************
// * MainWin::OnCloseWin
// *******************************************************************************/
// bool MainWin::OnCloseWin()
// {
//     //cout << __PRETTY_FUNCTION__ << endl;

//     return qMainWinMdi::OnCloseWin();
// } // qCtrlI::MainWin

// /*******************************************************************************
// * MainWin::OnDropUrl
// *******************************************************************************/
// void MainWin::OnDropUrl(const qUrl   &_url)
// {
//     // create the document
//     OpenFile(_url.ToLocalFile());
// } // MainWin::OnDropUrl
