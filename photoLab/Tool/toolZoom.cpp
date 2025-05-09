/*******************************************************************************
* \file ToolZoom.inl
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
#include "toolZoom.h"


/*******************************************************************************
* ToolZoom::ToolZoom
*******************************************************************************/
ToolZoom::ToolZoom(ViewBase *_pOwnerView)
: ToolBase(_pOwnerView, TOOL_ID_ZOOM, TBF_WHEEL_ZOOM | TBF_MIDDLE_MOVE | TBF_SECTIONS)
{
} // ToolZoom::ToolZoom


/*******************************************************************************
* ToolZoom::~ToolZoom
*******************************************************************************/
ToolZoom::~ToolZoom()
{
} // ToolZoom::~ToolZoom


/*******************************************************************************
* ToolZoom::ToolMove::OnContextMenu
*******************************************************************************/
enumToolResult ToolZoom::OnContextMenu(u32                  /*_u32Modifiers*/,
                                       const qVector2D<s32> &_v2dLocal,
                                       const qVector2D<s32> &/*_v2dGlobal*/)
{
    // create the context menu
    qContextMenu menu(OwnerWin());
    menu.CreateWin();

    menu.AppendMenuItem(1, ":/AppSpecific/magnifierFit.png", "Full Image");
    menu.AppendMenuItem(2, ":/AppSpecific/magnifier1.png", "Zoom 100%");
    menu.AppendMenuItem(3, ":/AppSpecific/magnifier2.png", "Zoom 200%");

    switch (menu.ShowMenu(_v2dLocal))
    {
    case 1:
        SetZoomFactorFit();
        break;

    case 2:
        SetZoomFactor1();
        break;

    case 3:
        SetZoomFactor2();
        break;
    }

    return enumToolResult::Handled;
} // ToolZoom::ToolMoveOnContextMenu
