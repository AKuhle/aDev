/*******************************************************************************
* \file aMainWin_sys.cpp
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
#include "aMainWin_sys.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aWin {


/*******************************************************************************
* aMainWin_sys::aMainWin_sys
*******************************************************************************/
aMainWin_sys::aMainWin_sys(SysWinClass *_pParent /*= nullptr*/)
: aBaseWin(_pParent)
{
} // aMainWin_sys::_isVisible


/*******************************************************************************
* aMainWin_sys::~aMainWin_sys
*******************************************************************************/
aMainWin_sys::~aMainWin_sys()
{
} // aMainWin_sys::~aMainWin_sys


/*******************************************************************************
* aMainWin_sys::_setCentralWin
*******************************************************************************/
void aMainWin_sys::_setCentralWin(SysWinClass *_pWin)
{
    QMainWindow *pMw = qobject_cast<QMainWindow *> (this);
    CHECK_PRE_CONDITION_VOID(pMw != nullptr);

    pMw->setCentralWidget(_pWin);
} // aMainWin_sys::_setCentralWin


/*******************************************************************************
* aMainWin_sys::_centralWin
*******************************************************************************/
SysWinClass* aMainWin_sys::_centralWin()
{
    QMainWindow *pMw = qobject_cast<QMainWindow *> (this);
    CHECK_PRE_CONDITION(pMw != nullptr, nullptr);

    return pMw->centralWidget();
} // aMainWin_sys::


} // namespace aWin
} // namespace aLib

#endif //_USE_QT_
