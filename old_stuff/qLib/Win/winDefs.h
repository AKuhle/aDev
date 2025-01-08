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
#include "qLibDefs.h"

using namespace qLib;


namespace qLib {
namespace Win {


/*******************************************************************************
* mouse buttons
*******************************************************************************/
constexpr u16   MOUSE_BTN_NONE          = 0x0000;
constexpr u16   MOUSE_BTN_LEFT          = 0x0001;
constexpr u16   MOUSE_BTN_MIDDLE        = 0x0002;
constexpr u16   MOUSE_BTN_RIGHT         = 0x0004;


/*******************************************************************************
* classes
*******************************************************************************/
namespace SysQt {
    class qSysWinQt;
} // namespace SysQt

// FrameWin
class qSysWinI;
#ifdef _USE_QT_
    using qSysWin = qLib::Win::SysQt::qSysWinQt;
#endif // _USE_QT_
class qWin;
class qMainWin;
class qMainWinMdi;
class qTitleBar;

// Layout
class qLayoutObj;
class qLayout;
class qLayoutMainWin;

// WinStyle
class qWinStyle;
class qWinStyleFactory;
class qWinStyleFactoryDark;


} // namespace Win
} // namespace qLib
