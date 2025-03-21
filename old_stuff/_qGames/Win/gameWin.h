/*******************************************************************************
* \file GameWin.h
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

#include "qLib.h"

using namespace qLib;


/*******************************************************************************
* forwards
*******************************************************************************/
class GameWin;


/*******************************************************************************
* globals
*******************************************************************************/
GameWin&    GetGameWin();


/*******************************************************************************
* class GameWin
*******************************************************************************/
class GameWin : public qLib::qMainWinSdi
{
    public:
        GameWin();
        ~GameWin();


    /*******************************************************************************
    * qCtrlMgr interface
    *******************************************************************************/
        virtual void        OnRegisterCtrl() override;
        virtual void        OnUpdateCtrl(qCtrlBase *_pCtrl) override;


    /*******************************************************************************
    * qMainWin interface
    *******************************************************************************/
    protected:
        virtual void        OnUpdateCmd(u64         _u64Cmd,
                                        qDocBase    *_pDoc,
                                        qViewBase   *_pView,
                                        s64         _s64Param1,
                                        s64         _s64Param2,
                                        u64         _u64Param1,
                                        u64         _u64Param2,
                                        flt         _fltParam1,
                                        flt         _fltParam2,
                                        dbl         _dblParam1,
                                        dbl         _dblParam2,
                                        void        *_pParam1,
                                        void        *_pParam2) override;


    /*******************************************************************************
    * qWin interface
    *******************************************************************************/
    protected:
        virtual bool        OnCreate() override;
}; // class GameWin
