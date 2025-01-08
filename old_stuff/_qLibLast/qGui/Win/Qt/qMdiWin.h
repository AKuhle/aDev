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
#pragma once

#include "qSysWin.h"


namespace qLib
{
    /*******************************************************************************
    * class qMdiWin
    *******************************************************************************/
    class qMdiWin : public qSysWin<QMdiSubWindow>
    {
        public:
            qMdiWin(SysWin_t *_pParent = nullptr);
            ~qMdiWin();

            void                SetCentralWin(SysWin_t   *_pWin);
            SysWin_t*           CentralWin() const;

    }; // class qLib

} //namespace qFrame
