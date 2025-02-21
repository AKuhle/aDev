/*******************************************************************************
* \file qCtrlBase.h
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



/*******************************************************************************
* includes
*******************************************************************************/
#include "qWin.h"


namespace qLib
{
    /*******************************************************************************
    * class qCtrlBase
    *******************************************************************************/
    class qCtrlMgr;


    /*******************************************************************************
    * class qCtrlBase
    *******************************************************************************/
    class qCtrlBase : public qWin
    {
        DeclareTypeProperty(u32, u32, CtrlId, 0)
        DeclarePtrProperty(qCtrlMgr, p, CtrlMgr)

        public:
            qCtrlBase(qWin  *_pParent,
                      u32   _u32Id);
            virtual ~qCtrlBase();

    }; // class qCtrlBase

} // namespace qLib
