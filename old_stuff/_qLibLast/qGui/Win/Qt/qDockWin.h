/*******************************************************************************
* \file qDockWin.h
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
    * class qDockWin
    *******************************************************************************/
    class qDockWin : public qSysWin<QDockWidget>
    {
        public:
            qDockWin(SysWin_t *_pParent = nullptr);
            ~qDockWin();

            void                SetTitleBarWin(SysWin_t   *_pWin);
            SysWin_t*           TitleBarWin() const;

            void                SetCentralWin(SysWin_t   *_pWin);
            SysWin_t*           CentralWin() const;

            void                SetAllowedDockAreas(u32 _u32Areas);
    }; // class qLib

} //namespace qFrame
