/*******************************************************************************
* \file aToolButton_sys.inl
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
#ifdef _USE_QT_


/*******************************************************************************
* includes
*******************************************************************************/
#include "aToolButton_sys.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aWin {


/*******************************************************************************
* aToolButton_sys::aToolButton_sys
*******************************************************************************/
aToolButton_sys::aToolButton_sys(SysWinClass *_pParent)
: aCtrl<QToolButton>(_pParent)
{
} // aToolButton_sys::aToolButton_sys


/*******************************************************************************
* aToolButton_sys::~aToolButton_sys
*******************************************************************************/
aToolButton_sys::~aToolButton_sys()
{
} // aToolButton_sys::~aToolButton_sys


} // namespace aWin
} // namespace aLib

#endif //_USE_QT_
