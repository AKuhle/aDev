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
#include "aMdiArea.h"
#include "aMdiWin.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aWin {


/*******************************************************************************
* aMdiArea_sys::aMdiArea_sys
*******************************************************************************/
aMdiArea_sys::aMdiArea_sys(SysWinClass *_pParent /*= nullptr*/)
: aBaseWin(_pParent)
{
} // aMdiArea_sys::_isVisible


/*******************************************************************************
* aMdiArea_sys::~aMdiArea_sys
*******************************************************************************/
aMdiArea_sys::~aMdiArea_sys()
{
} // aMdiArea_sys::~aMdiArea_sys


/*******************************************************************************
* aMdiArea_sys::_addMdiWin
*******************************************************************************/
void aMdiArea_sys::_addMdiWin(aMdiWin *_pMdiWin)
{
    CHECK_PRE_CONDITION_VOID(_pMdiWin != nullptr);

    addSubWindow(_pMdiWin);
} // aMdiArea_sys::_addMdiWin


} // namespace aWin
} // namespace aLib

#endif //_USE_QT_
