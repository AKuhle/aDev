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
#include "mainWin.h"
#include "qDockWin.h"
#include "stdBar.h"


using namespace qLib;


/*******************************************************************************
* GetMainWin
*******************************************************************************/
MainWin& GetMainWin()
{
    return dynamic_cast<MainWin &> (Get_qMainWin());
} // GetMainWin


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
} // ~MainWin::MainWin


/*******************************************************************************
* MainWin::OnCreate
*******************************************************************************/
bool MainWin::OnCreate()
{
    qLayoutMainWin  *pLayout = dynamic_cast<qLayoutMainWin *> (GetLayout());
    CHECK_PRE_CONDITION(pLayout != nullptr, false);

    // create the standard toolbar
    StdBar  *pStdBar = new StdBar;
    pStdBar->CreateWin();
    // create the dock win
    qDockWin *pDock = new qDockWin(this);
    pDock->CreateWin();
    pDock->SetCenterWin(pStdBar);
    pDock->SetAllowedDockPositions(DOCK_POS_T + DOCK_POS_LR);
    pDock->SetDockPosition(DOCK_POS_T);
    pLayout->AddTopChild(pDock);

    // restore the position
    SetMinSize(600, 400);
    SetGeometry(100, 100, GetMinSize().w, GetMinSize().h);

    // enable drop
    EnableDrop(true);

    return true;
} // MainWin::OnCreate


/*******************************************************************************
* MainWin::OnClose
*******************************************************************************/
bool MainWin::OnClose()
{
    return true;
} // MainWin::OnClose
