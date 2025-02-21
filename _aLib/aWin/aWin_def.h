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
* namespace
*******************************************************************************/
#ifdef _USE_QT_
    #include <QWidget>
#endif // _USE_QT_

#include "aLib_def.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aWin {


/*******************************************************************************
* mouse buttons
*******************************************************************************/
constexpr u16   MOUSE_BTN_NONE              = 0x0000;
constexpr u16   MOUSE_BTN_LEFT              = 0x0001;
constexpr u16   MOUSE_BTN_MIDDLE            = 0x0002;
constexpr u16   MOUSE_BTN_RIGHT             = 0x0004;


/*******************************************************************************
* update commands
*******************************************************************************/
constexpr u64   UPDATE_SYS_BITS         = 0x000000000000ffff;
constexpr u64   UPDATE_USER_BITS        = 0xffffffffffff0000;

constexpr u64   UPDATE_GUI              = 0x0000000000000001;
constexpr u64   UPDATE_VIEW             = 0x0000000000000002;
constexpr u64   UPDATE_VIEWS_BY_DOC     = 0x0000000000000004;
constexpr u64   UPDATE_ALL_VIEWS        = 0x0000000000000008;


/*******************************************************************************
* ToolBaseFunctions
*******************************************************************************/
constexpr u64   TBF_NONE                    = 0x0000000000000000;
constexpr u64   TBF_LXOR_RECT               = 0x0000000000000001;
constexpr u64   TBF_USER                    = 0xffffffffffff0000;


/*******************************************************************************
* tool id's
*******************************************************************************/
constexpr u32   TOOL_ID_PARENT_CONTROL      = 1;
constexpr u32   TOOL_ID_BORDER_RESIZE       = 2;
constexpr u32   TOOL_ID_BUTTON              = 3;

constexpr u32   TOOL_ID_USER                = 1000;


/*******************************************************************************
* ctrl id's
*******************************************************************************/
constexpr u32   CTRL_ID_HORI_SPACER         = 1;
constexpr u32   CTRL_ID_VERT_SPACER         = 2;
constexpr u32   CTRL_ID_HORI_VERT_SPACER    = 3;
constexpr u32   CTRL_ID_HORI_SCROLLBAR      = 4;
constexpr u32   CTRL_ID_VERT_SCROLLBAR      = 5;
constexpr u32   CTRL_ID_PROGRESS_CTRL       = 6;
constexpr u32   CTRL_ID_LABEL               = 7;

constexpr u32   CTRL_ID_MINIMIZE            = 20;
constexpr u32   CTRL_ID_MAXIMIZE            = 21;
constexpr u32   CTRL_ID_CLOSE               = 22;

constexpr u32   CTRL_ID_USER                = 1000;


/*******************************************************************************
* ctrl messages
*******************************************************************************/
constexpr u32   MSG_CLICKED                 = 1;

constexpr u32   MSG_USER                    = 1000;


/*******************************************************************************
* enums
*******************************************************************************/
enum class enumToolResult
{
    Handled,
    Unhandled,
    Success,
    Canceled
}; // enumToolResult

enum class enumButtonStyle
{
    MASKED_MODE,
    MASKED_ROUND_MODE
}; // enumButtonStyle

enum class enumFocusReason
{
    NoFocusReason,
    MouseFocusReason,           // A mouse action occurred.
    TabFocusReason,             // The Tab key was pressed.
    BacktabFocusReason,         // A Backtab occurred. The input for this may include the Shift or Control keys; e.g. Shift+Tab.
    ActiveWindowFocusReason,    // The window system made this window either active or inactive.
    PopupFocusReason,           // The application opened/closed a pop-up that grabbed/released the keyboard focus.
    ShortcutFocusReason,        // The user typed a label's buddy shortcut
    MenuBarFocusReason,         // The menu bar took focus.
    OtherFocusReason            // Another reason, usually application-specific.
}; // enumButtonStyle

enum class enumFocusPolicy
{
    NoFocus,                    // the widget does not accept focus.
    TabFocus,                   // the widget accepts focus by tabbing.
    ClickFocus,                 // the widget accepts focus by clicking.
    StrongFocus,                // the widget accepts focus by both tabbing and clicking.
    WheelFocus                  // like Qt::StrongFocus plus the widget accepts focus by using the mouse wheel.
}; // enumButtonStyle

/*******************************************************************************
* classes
*******************************************************************************/
// layout
class aLayoutObj;
class aLayout;
class aLayoutCentralWin;
class aLayoutMainWin;
class aLayoutHoriVert;

class aToolBase;
class aToolMgr;

// FrameWin
#ifdef _USE_QT_
    namespace SysQt
    {
        class aSysWinQt;
    } // namespace SysQt

    using aSysWin_t = QWidget;
    using aSysWin = aLib::aWin::SysQt::aSysWinQt;
#endif // _USE_QT_

class aSysWinI;

class aWinStyleItem;
class aWinStyle;
class aWinStyleDark;

class aCtrlMgr;
class aCtrl;
class aButton;
class aToolButton;
class aScrollBar;
class aProgressCtrl;
class aLabel;

class aBaseWin;
class aPositionWin;
class aDockArea;
class aMainWin;
class aCentralWin;
class aScrollWin;
class aMainWin;
class aMdiMainWin;
class aMdiWin;
class aMdiArea;

class aTitleBar;
class aStatusBar;

class aDoc;
class aView;

} // namespace aWin
} // namespace aLib
