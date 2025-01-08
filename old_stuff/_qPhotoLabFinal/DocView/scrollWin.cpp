/*******************************************************************************
* \file ScrollWin.cpp
* \author Andreas Kuhlewind
*
* \brief
*
*  Detailed description starts here.
*******************************************************************************/


/*******************************************************************************
* includes
*******************************************************************************/
#include "mainWin.h"
#include "scrollWin.h"
#include "viewStd.h"


/*******************************************************************************
* ScrollWin::ScrollWin
*******************************************************************************/
ScrollWin::ScrollWin(qWin             *_pParent)
: qScrollWin(_pParent)
{
} // ScrollWin::ScrollWin


/*******************************************************************************
* ScrollWin::~ScrollWin
*******************************************************************************/
ScrollWin::~ScrollWin()
{
} // ScrollWin::~ScrollWin


/*******************************************************************************
* ScrollWin::OnCreate
*******************************************************************************/
bool ScrollWin::OnCreate()
{
    EnableTracking(true);

    return true;
} // ScrollWin::OnCreate


/*******************************************************************************
* ScrollWin::OnHoriChanged
*******************************************************************************/
void ScrollWin::OnHoriChanged(s32 /*_s32Value*/)
{
    ViewStd *pView = dynamic_cast<ViewStd *> (GetCenterWin());
    CHECK_PRE_CONDITION_VOID(pView != nullptr);

    MainWin     &mw = GetMainWin();

    mw.SendUpdateCmd(UPDATE_VIEW, pView);
} // ScrollWin::OnHoriChanged


/*******************************************************************************
* ScrollWin::OnVertChanged
*******************************************************************************/
void ScrollWin::OnVertChanged(s32 /*_s32Value*/)
{
    ViewStd *pView = dynamic_cast<ViewStd *> (GetCenterWin());
    CHECK_PRE_CONDITION_VOID(pView != nullptr);

    MainWin     &mw = GetMainWin();

    mw.SendUpdateCmd(UPDATE_VIEW, pView);
} // ScrollWin::OnVertChanged
