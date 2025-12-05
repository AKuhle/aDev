/*******************************************************************************
* \file qlBaseDefs.h
* \author Andreas Kuhlewind
*
* \brief
*
*  Detailed description starts here.
*******************************************************************************/
#pragma once


/*******************************************************************************
* includes
*******************************************************************************/
#ifdef _USE_QT_
    #include <QWidget>

    using SysWin = QWidget;
#endif // _USE_QT_

#include "aFrame_def.h"



/*******************************************************************************
* namespace
*******************************************************************************/
namespace aFrame {
namespace aWin {


/*******************************************************************************
* mouse Btns
*******************************************************************************/
constexpr u16   MOUSE_BTN_NONE              = 0x0000;
constexpr u16   MOUSE_BTN_LEFT              = 0x0001;
constexpr u16   MOUSE_BTN_MIDDLE            = 0x0002;
constexpr u16   MOUSE_BTN_RIGHT             = 0x0004;


/*******************************************************************************
* update commands
*******************************************************************************/
// constexpr u64   UPDATE_SYS_BITS             = 0x000000000000ffff;
// constexpr u64   UPDATE_USER_BITS            = 0xffffffffffff0000;

// constexpr u64   UPDATE_GUI                  = 0x0000000000000001;
// constexpr u64   UPDATE_VIEW                 = 0x0000000000000002;
// constexpr u64   UPDATE_VIEWS_BY_DOC         = 0x0000000000000004;
// constexpr u64   UPDATE_ALL_VIEWS            = 0x0000000000000008;


/*******************************************************************************
* tool flags
*******************************************************************************/
constexpr u32   TOOL_ID_PARENT_CTRL     = 1;
constexpr u32   TOOL_ID_BORDER_RESIZE   = 2;
constexpr u32   TOOL_ID_BUTTON          = 3;
constexpr u32   TOOL_ID_USER            = 1000;


/*******************************************************************************
* tool flags
*******************************************************************************/
constexpr u32   TF_NONE                 = 0x00000001;


/*******************************************************************************
* ctrl id's
*******************************************************************************/
// constexpr u32   CTRL_ID_USER                = 1000;


/*******************************************************************************
* dock positions (for aToolBar, aDockWin, etc.)
*******************************************************************************/
constexpr u32   DOCK_POS_NONE           = 0x00000000;
constexpr u32   DOCK_POS_L              = 0x00000001;   // left
constexpr u32   DOCK_POS_R              = 0x00000002;   // right
constexpr u32   DOCK_POS_T              = 0x00000004;   // top
constexpr u32   DOCK_POS_B              = 0x00000008;   // bottom
constexpr u32   DOCK_POS_FLOATING       = 0x00000010;

constexpr u32   DOCK_POS_LR             = DOCK_POS_L + DOCK_POS_R;
constexpr u32   DOCK_POS_TB             = DOCK_POS_T + DOCK_POS_B;
constexpr u32   DOCK_POS_LRTB           = DOCK_POS_LR + DOCK_POS_TB;


/*******************************************************************************
* enums
*******************************************************************************/
enum class enumToolResult
{
    UNHANDLED,
    HANDLED,
    SUCCESS,
    CANCELED
}; // enumBtnStyle


enum class enumBtnStyle
{
    MASKED_MODE,            // pixmap in state colors
    MASKED_ROUND_MODE,      // round bg in state colors

    ICON_MODE,              // icon, bg changes depending on the state (e.g. hover)
    ICON_STATIC_MODE        // static btn, no visual response of mouse actions
}; // enumBtnStyle


// enum class enumFocusReason
// {
//     NoFocusReason,
//     MouseFocusReason,           // A mouse action occurred.
//     TabFocusReason,             // The Tab key was pressed.
//     BacktabFocusReason,         // A Backtab occurred. The input for this may include the Shift or Control keys; e.g. Shift+Tab.
//     ActiveWindowFocusReason,    // The window system made this window either active or inactive.
//     PopupFocusReason,           // The application opened/closed a pop-up that grabbed/released the keyboard focus.
//     ShortcutFocusReason,        // The user typed a label's buddy shortcut
//     MenuBarFocusReason,         // The menu bar took focus.
//     OtherFocusReason            // Another reason, usually application-specific.
// }; // enumBtnStyle

// enum class enumFocusPolicy
// {
//     NoFocus,                    // the widget does not accept focus.
//     TabFocus,                   // the widget accepts focus by tabbing.
//     ClickFocus,                 // the widget accepts focus by clicking.
//     StrongFocus,                // the widget accepts focus by both tabbing and clicking.
//     WheelFocus                  // like Qt::StrongFocus plus the widget accepts focus by using the mouse wheel.
// }; // enumBtnStyle

// enum class ScrollBarPolicy {
//     ScrollBarAsNeeded,
//     ScrollBarAlwaysOff,
//     ScrollBarAlwaysOn
// }; // ScrollBarPolicy

// enum class DialogReturn {
//     accepted,
//     rejected
// }; // DialogReturn


/*******************************************************************************
* classes
*******************************************************************************/
class aLayout_i;
class aLayoutCentralWin;
class aLayoutMainWin;
class aLayoutHoriVert;

class aToolBase;
class aBorderResizeTool;
class aButtonTool;
class aParentCtrlTool;
class aToolCb;
class aToolManager;

class aBaseWin_sys;
class aBaseWin;

class aCtrl;
class aBtn;
class aPushBtn;
class aToolBtn;
class aSpacer;

class aMainWin;
class aMainWinMdi;
class aTitleBar;
class aToolBar;

class aMdiArea;
class aMdiSubWin;

class aStyleParser;
class aStyleItem;
class aStyleItemFill;
class aStyleItemFillSolid;
class aStyleItemFillGradient;
class aStyleItemBorder;
class aStyleItemBorderSolid;
class aStyleItemBorderSolidFrame;

// class aDialog;
// class aDockWin;
// class aMainWin;
// class aMainWinSdi;
// class aMdiArea;
// class aMdiChild;
// class aPlainWin;
// class aScrollWin;
// class aStatusBar;

// class aDoc;
// class aView;

} // namespace aWin
} // namespace aFrame
