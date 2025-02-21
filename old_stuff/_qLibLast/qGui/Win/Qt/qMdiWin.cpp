/*******************************************************************************
* \file qMdiWin.h
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


/*******************************************************************************
* includes
*******************************************************************************/
#include "qMdiWin.h"


namespace qLib
{
    /*******************************************************************************
    * qMdiWin::qMdiWin
    *******************************************************************************/
    qMdiWin::qMdiWin(SysWin_t *_pParent /*= nullptr*/)
    : qSysWin<QMdiSubWindow>(_pParent)
    {
    } // qMdiWin::qMdiWin


    /*******************************************************************************
    * qMdiWin::~qMdiWin
    *******************************************************************************/
    qMdiWin::~qMdiWin()
    {
    } // qMdiWin::~qMdiWin


    /*******************************************************************************
    * qMdiWin::SetCentralWin
    *******************************************************************************/
    void qMdiWin::SetCentralWin(SysWin_t *_pWin)
    {
        setWidget(_pWin);
        _pWin->setVisible(true);
    } // qMdiWin::SetCentralWin


    /*******************************************************************************
    * qMdiWin::CentralWin
    *******************************************************************************/
    SysWin_t* qMdiWin::CentralWin() const
    {
        return widget();
    } // qMdiWin::CentralWin

} //namespace qLib
