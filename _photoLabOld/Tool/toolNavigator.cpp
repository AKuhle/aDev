/*******************************************************************************
* \file ToolNavigator.inl
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
#include "toolNavigator.h"
#include "viewBase.h"


/*******************************************************************************
* ToolNavigator::ToolNavigator
*******************************************************************************/
ToolNavigator::ToolNavigator(ViewBase *_pOwnerView)
: ToolBase(_pOwnerView, TOOL_ID_NAVIGATOR, TBF_LXOR_RECT)
{
} // ToolNavigator::ToolNavigator


/*******************************************************************************
* ToolNavigator::~ToolNavigator
*******************************************************************************/
ToolNavigator::~ToolNavigator()
{
} // ToolNavigator::~ToolNavigator


/*******************************************************************************
* ToolNavigator::OnLDoubleClick
*******************************************************************************/
enumToolResult ToolNavigator::OnLDoubleClick(u32                  /*_u32Modifiers*/,
                                             const qVector2D<s32> &_v2dLocal,
                                             const qVector2D<s32> &/*_v2dGlobal*/)
{
    MainWin         &mw             = GetMainWin();
    ViewBase*       pActiveView     = GetActiveView();
    ViewBase*       pNavigatorView  = OwnerView();
    CHECK_PRE_CONDITION(pActiveView != nullptr && pNavigatorView != nullptr, enumToolResult::Unhandled);

    // transform the click position to zoom
    qVector2D<s32>  v2dCenter_pic = pNavigatorView->Client2Pic(_v2dLocal);

    // set the centerpoint to the active view
    pActiveView->SetCenterPoint_pic(v2dCenter_pic);

    mw.SendUpdateCmd(UPDATE_VIEW | UPDATE_GUI, pActiveView);

    return enumToolResult::Handled;
} // ToolNavigator::OnLDoubleClick


/*******************************************************************************
* ToolNavigator::OnLMousePress
*******************************************************************************/
enumToolResult ToolNavigator::OnLMousePress(u32                  _u32Modifiers,
                                            const qVector2D<s32> &_v2dLocal,
                                            const qVector2D<s32> &_v2dGlobal)
{
    return ToolBase::OnLMousePress(_u32Modifiers, _v2dLocal, _v2dGlobal);
} // ToolNavigator::OnLMousePress


/*******************************************************************************
* ToolNavigator::OnLMouseMove
*******************************************************************************/
enumToolResult ToolNavigator::OnLMouseMove(u32                  _u32Modifiers,
                                           const qVector2D<s32> &_v2dLocal,
                                           const qVector2D<s32> &_v2dGlobal)
{
    return ToolBase::OnLMouseMove(_u32Modifiers, _v2dLocal, _v2dGlobal);
} // ToolNavigator::OnLMouseMove


/*******************************************************************************
* ToolNavigator::OnLMouseRelease
*******************************************************************************/
enumToolResult ToolNavigator::OnLMouseRelease(u32                   _u32Modifiers,
                                              const qVector2D<s32>  &_v2dLocal,
                                              const qVector2D<s32>  &_v2dGlobal)
{
    return ToolBase::OnLMouseRelease(_u32Modifiers, _v2dLocal, _v2dGlobal);
} // ToolNavigator::OnLMouseRelease


/*******************************************************************************
* ToolNavigator::OnXorRect
*******************************************************************************/
void ToolNavigator::OnXorRect(const qRect2D<s32>    &_r2dXor)
{
    ViewBase*       pActiveView     = GetActiveView();
    ViewBase*       pNavigatorView  = OwnerView();
    CHECK_PRE_CONDITION_VOID(pActiveView != nullptr && pNavigatorView != nullptr);

    // rect must have a minimal size to zoom in
    if (_r2dXor.w() >= 5 && _r2dXor.h() >= 5)
    {
        MainWin         &mw             =  GetMainWin();
        qRect2D<s32>    r2dClient       = pActiveView->ClientRect();
        qVector2D<s32>  v2dCenter_pic   = pNavigatorView->Client2Pic(_r2dXor.CenterPoint());
        qRect2D<s32>    r2d_zoom        = pNavigatorView->Client2Zoom(_r2dXor);

        dbl             dZoomW          = ((dbl) r2dClient.w()) / r2d_zoom.w();
        dbl             dZoomH          = ((dbl) r2dClient.h()) / r2d_zoom.h();

        pActiveView->SetZoomFactor(Min(dZoomW, dZoomH));

        pActiveView->SetCenterPoint_pic(v2dCenter_pic);

        mw.SendUpdateCmd(UPDATE_VIEW | UPDATE_GUI, pActiveView);
    }
} // ToolNavigator::OnXorRect
