/*******************************************************************************
* \file StdScrollWin.cpp
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
#include "stdScrollWin.h"
#include "viewBase.h"


using namespace qLib;


/*******************************************************************************
* StdScrollWin::StdScrollWin
*******************************************************************************/
StdScrollWin::StdScrollWin(SysWin_t  *_pParent /*= nullptr*/)
: qScrollWin(_pParent)
{
} // StdScrollWin::StdScrollWin


/*******************************************************************************
* StdScrollWin::~StdScrollWin
*******************************************************************************/
StdScrollWin::~StdScrollWin()
{
} // ~StdScrollWin::StdScrollWin


/*******************************************************************************
* StdScrollWin::CentralViewBase
*******************************************************************************/
ViewBase* StdScrollWin::CentralViewBase() const
{
    return dynamic_cast<ViewBase *> (CentralWin());
} // StdScrollWin::CentralViewBase


/*******************************************************************************
* StdScrollWin::OnHoriScroll
*******************************************************************************/
void StdScrollWin::OnHoriScroll(s32 /*_s32Pos*/)
{
    ViewBase *pView = CentralViewBase();
    CHECK_PRE_CONDITION_VOID(pView != nullptr);

    MainWin &mw = GetMainWin();

    mw.SendUpdateCmd(UPDATE_VIEW, pView);
} // StdScrollWin::OnHoriScroll


/*******************************************************************************
* StdScrollWin::OnVertScroll
*******************************************************************************/
void StdScrollWin::OnVertScroll(s32 /*_s32Pos*/)
{
    ViewBase *pView = CentralViewBase();
    CHECK_PRE_CONDITION_VOID(pView != nullptr);

    MainWin &mw = GetMainWin();

    mw.SendUpdateCmd(UPDATE_VIEW, pView);
} // StdScrollWin::OnVertScroll


/*******************************************************************************
* StdScrollWin::OnResize
*******************************************************************************/
void StdScrollWin::OnResize(const qDimension2D<s32>    &/*_d2dOld*/,
                            const qDimension2D<s32>    &/*_d2dNew*/)
{
    ViewBase    *pView  = dynamic_cast<ViewBase *> (CentralWin());
    CHECK_PRE_CONDITION_VOID(pView != nullptr);

    GetMainWin().SendUpdateCmd(UPDATE_VIEW | UPDATE_GUI, pView);
} // StdScrollWin::OnResize


/*******************************************************************************
* StdScrollWin::UpdateScrollbars
*******************************************************************************/
void StdScrollWin::UpdateScrollbars()
{
    ViewBase    *pView  = dynamic_cast<ViewBase *> (CentralWin());
    CHECK_PRE_CONDITION_VOID(pView != nullptr);

    qRect2D<s32>        r2dClient   = pView->ClientRect();
    qDimension2D<s32>   d2dPic      = pView->PicSize_zoom();

    s32                 s32MinX     = -r2dClient.w() + Min(MIN_PIC_VISIBLE, d2dPic.w());
    s32                 s32MaxX     = d2dPic.w() - Min(MIN_PIC_VISIBLE, d2dPic.w());

    s32                 s32MinY     = -r2dClient.h() + Min(MIN_PIC_VISIBLE, d2dPic.h());
    s32                 s32MaxY     = d2dPic.h() - Min(MIN_PIC_VISIBLE, d2dPic.h());

    SetHoriSbRange(s32MinX, s32MaxX);
    SetVertSbRange(s32MinY, s32MaxY);
} // StdScrollWin::UpdateScrollbars
