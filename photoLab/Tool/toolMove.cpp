/*******************************************************************************
* \file ToolMove.inl
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
#include "photoLab_defs.h"
#include "toolMove.h"


/*******************************************************************************
* ToolMove::ToolMove
*******************************************************************************/
ToolMove::ToolMove(ViewBase *_pOwnerView)
: ToolBase(_pOwnerView, TOOL_ID_MOVE, TBF_WHEEL_ZOOM | TBF_LEFT_MOVE | TBF_SECTIONS)
{
    cout << __PRETTY_FUNCTION__ << endl;
} // ToolMove::ToolMove


/*******************************************************************************
* ToolMove::~ToolMove
*******************************************************************************/
ToolMove::~ToolMove()
{
    cout << __PRETTY_FUNCTION__ << endl;
} // ToolMove::~ToolMove


// /*******************************************************************************
// * ToolMove::ToolMove::OnContextMenu
// *******************************************************************************/
// enumToolResult ToolMove::OnContextMenu(u32                  /*_u32Modifiers*/,
//                                        const qVector2D<s32> &_v2dLocal,
//                                        const qVector2D<s32> &/*_v2dGlobal*/)
// {
//     // create the context menu
//     qContextMenu menu(OwnerWin());
//     menu.CreateWin();

//     menu.AppendMenuItem(1, ":/AppSpecific/magnifierFit.png", "Full Image");
//     menu.AppendMenuItem(2, ":/AppSpecific/magnifier1.png", "Zoom 100%");
//     menu.AppendMenuItem(3, ":/AppSpecific/magnifier2.png", "Zoom 200%");

//     switch (menu.ShowMenu(_v2dLocal))
//     {
//         case 1:
//             SetZoomFactorFit();
//             break;

//         case 2:
//             SetZoomFactor1();
//             break;

//         case 3:
//             SetZoomFactor2();
//             break;
//     }

//     return enumToolResult::Handled;
// } // ToolMove::ToolMoveOnContextMenu


// /*******************************************************************************
// * ToolMove::OnLMousePress
// *******************************************************************************/
// enumToolResult ToolMove::OnLMousePress(u32                  _u32Modifiers,
//                                        const qVector2D<s32> &_v2dLocal,
//                                        const qVector2D<s32> &_v2dGlobal)
// {
//     ViewBase    *pView = OwnerView();
//     CHECK_PRE_CONDITION(pView != nullptr, enumToolResult::Unhandled);

//     pView->SetCursor(qCursor(enumCursorShape::ClosedHand));

//     return ToolBase::OnLMousePress(_u32Modifiers, _v2dLocal, _v2dGlobal);
// } // ToolMove::OnLMousePress


// /*******************************************************************************
// * ToolMove::OnLMouseRelease
// *******************************************************************************/
// enumToolResult ToolMove::OnLMouseRelease(u32                  _u32Modifiers,
//                                          const qVector2D<s32> &_v2dLocal,
//                                          const qVector2D<s32> &_v2dGlobal)
// {
//     ViewBase    *pView = OwnerView();
//     CHECK_PRE_CONDITION(pView != nullptr, enumToolResult::Unhandled);

//     pView->SetCursor(qCursor(enumCursorShape::OpenHand));

//     return ToolBase::OnLMousePress(_u32Modifiers, _v2dLocal, _v2dGlobal);
// } // ToolMove::OnLMouseRelease
