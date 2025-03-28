/*******************************************************************************
* \file aMdiArea_sys.cpp
* \author Andreas Kuhlewind
*
* \brief
*
*  Detailed description starts here.
*******************************************************************************/
#ifdef _USE_QT_


/*******************************************************************************
* includes
*******************************************************************************/
#include "aMdiArea_sys.h"
#include "aMdiChild.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aWin {


/*******************************************************************************
* aMdiArea_sys::aMdiArea_sys
*******************************************************************************/
aMdiArea_sys::aMdiArea_sys(SysWinClass *_pParent)
: aBaseWin<QMdiArea>(_pParent)
{
} // aMdiArea_sys::_isVisible


/*******************************************************************************
* aMdiArea_sys::~aMdiArea_sys
*******************************************************************************/
aMdiArea_sys::~aMdiArea_sys()
{
} // aMdiArea_sys::~aMdiArea_sys


/*******************************************************************************
* aMdiArea_sys::addMdiChild
*******************************************************************************/
void aMdiArea_sys::addMdiChild(aMdiChild *_pMdiChild)
{
    addSubWindow(_pMdiChild);
} // aMdiArea_sys::addMdiChild


} // namespace aWin
} // namespace aLib

#endif //_USE_QT_
