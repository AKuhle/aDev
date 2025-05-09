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
class aProgressBar;
class aToolButton;

class aCtrlMgr;

} // namespace aWin
} // namespace aLib
