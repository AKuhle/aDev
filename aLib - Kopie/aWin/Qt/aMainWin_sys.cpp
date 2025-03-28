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
aMainWin_sys::aMainWin_sys(SysWinClass *_pParent)
: aBaseWin<QMainWindow>(_pParent)
{
} // aMainWin_sys::_isVisible


/*******************************************************************************
* aMainWin_sys::~aMainWin_sys
*******************************************************************************/
aMainWin_sys::~aMainWin_sys()
{
} // aMainWin_sys::~aMainWin_sys


/*******************************************************************************
* aMainWin_sys::setCentralWin
*******************************************************************************/
void aMainWin_sys::setCentralWin(SysWinClass *_pWin)
{
    QMainWindow::setCentralWidget(_pWin);
} // aMainWin_sys::setCentralWin


/*******************************************************************************
* aMainWin_sys::centralWin
*******************************************************************************/
SysWinClass* aMainWin_sys::centralWin()
{
    return QMainWindow::centralWidget();
} // aMainWin_sys::centralWin


} // namespace aWin
} // namespace aLib

#endif //_USE_QT_
