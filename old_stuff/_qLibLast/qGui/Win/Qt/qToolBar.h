/*******************************************************************************
* \file qToolBar.h
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
#pragma once

#ifdef _USE_QT_


/*******************************************************************************
* includes
*******************************************************************************/
#include "qSysWin.h"

namespace qLib
{
    /*******************************************************************************
    * class qToolBar
    *******************************************************************************/
    class qToolBar : public qSysWin<QToolBar>
    {
        public:
            qToolBar(SysWin_t  *_pParent = nullptr);
            ~qToolBar();

            void                SetAllowedDockAreas(u32 _u32Areas);

    }; // class qToolBar

} //namespace qLib

#endif // _USE_QT_
