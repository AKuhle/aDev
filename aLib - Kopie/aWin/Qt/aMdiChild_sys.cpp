/*******************************************************************************
* \file aMdiChild_sys.cpp
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
#include "aMdiChild_sys.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aWin {


/*******************************************************************************
* aMdiArea_sys::aMdiChild_sys
*******************************************************************************/
aMdiChild_sys::aMdiChild_sys(SysWinClass *_pParent /*= nullptr*/)
: aBaseWin<QMdiSubWindow>(_pParent)
{
} // aMdiChild_sys::_isVisible


/*******************************************************************************
* aMdiChild_sys::~aMdiChild_sys
*******************************************************************************/
aMdiChild_sys::~aMdiChild_sys()
{
} // aMdiChild_sys::~aMdiChild_sys


/*******************************************************************************
* aMdiChild_sys::setCentralWin
*******************************************************************************/
void aMdiChild_sys::setCentralWin(SysWinClass *_pWin)
{
    setWidget(_pWin);
} // aMdiChild_sys::setCentralWin


/*******************************************************************************
* aMdiChild_sys::centralWin
*******************************************************************************/
SysWinClass * aMdiChild_sys::centralWin()
{
    return widget();
} // aMdiChild_sys::centralWin


} // namespace aWin
} // namespace aLib


#endif //_USE_QT_
