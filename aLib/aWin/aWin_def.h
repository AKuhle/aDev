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
constexpr u16   MOUSE_BTN_NONE          = 0x0000;
constexpr u16   MOUSE_BTN_LEFT          = 0x0001;
constexpr u16   MOUSE_BTN_MIDDLE        = 0x0002;
constexpr u16   MOUSE_BTN_RIGHT         = 0x0004;


/*******************************************************************************
* ToolBaseFunctions
*******************************************************************************/
constexpr u64   TBF_NONE                = 0x00000000;
constexpr u64   TBF_LXOR_RECT           = 0x00000001;
constexpr u64   TBF_USER                = 0xffffff00;


/*******************************************************************************
* tool id's
*******************************************************************************/
constexpr u32   TOOL_ID_PARENT_CONTROL  = 1;
constexpr u32   TOOL_ID_BORDER_RESIZE   = 2;

constexpr u32   TOOL_ID_USER            = 1000;


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


/*******************************************************************************
* classes
*******************************************************************************/
// layout
class aLayoutObj;
class aLayout;
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

class aBaseWin;
class aMainWin;
class aMdiMainWin;

class aTitleBar;

} // namespace aWin
} // namespace aLib
