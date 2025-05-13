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
#include "aLib_def.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aWin {


/*******************************************************************************
* ctrl messages
*******************************************************************************/
constexpr u32   MSG_CLICKED                 = 1;

constexpr u32   MSG_USER                    = 1000;
constexpr u32   MSG_VALUE_CHANGED           = 1001;


/*******************************************************************************
* classes
*******************************************************************************/
template <typename T> class aButton;
template <typename T> class aCtrl;

class aCtrlI;

class aButtonI;
class aLabelI;

class aAction;
class aLabel;
class aLineEdit;
class aProgressBar;
class aPushButton;
class aScrollBar;
class aToolButton;

class aCtrlMgr;

} // namespace aWin
} // namespace aLib
