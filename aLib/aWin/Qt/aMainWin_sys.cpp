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
: aSysWin(_pParent)
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
void aMainWin_sys::_setCentralWin(SysWinClass */*_pWin*/)
{
    QWidget *pW = nullptr;
    //QMainWindow *pMw = dynamic_cast<QMainWindow *> (sysWinClass());
    // CHECK_PRE_CONDITION_VOID(pMw != nullptr);

    // pMw->setCentralWidget(_pWin);
} // aMainWin_sys::_setCentralWin


} // namespace aWin
} // namespace aLib

#endif //_USE_QT_
