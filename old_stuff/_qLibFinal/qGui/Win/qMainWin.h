/*******************************************************************************
* \file qMainWin.h
* \author Andreas Kuhlewind
*
* \brief
*
*  Detailed description starts here.
*******************************************************************************/
#pragma once


/*******************************************************************************
* includes
*******************************************************************************/
#include "qWin.h"
#include "qCtrlMgr.h"


namespace qLib
{
    /*******************************************************************************
    * forward
    *******************************************************************************/
    class qDocBase;
    class qViewBase;


    /*******************************************************************************
    * class qMainWin
    *******************************************************************************/
    class qMainWin : public qWin,
                     public qCtrlMgr
    {
        protected:
            qMainWin(qWin  *_pParent = nullptr);
            ~qMainWin();

            qWin*               GetCenterWin() const;
            void                SetCenterWin(qWin *_pWin);


        /*******************************************************************************
        * update cmd
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
                                            void        *_pParam2) = 0;

        public:
            void                SendUpdateCmd(u64 _u64Cmd);

            void                SendUpdateCmd(u64       _u64Cmd,
                                              qDocBase  *_pDoc);

            void                SendUpdateCmd(u64       _u64Cmd,
                                              qViewBase *_pView);

            void                SendUpdateCmd(u64       _u64Cmd,
                                              qDocBase  *_pDoc,
                                              qViewBase *_pView);

            void                SendUpdateCmd(u64   _u64Cmd,
                                              s64   _s64Param1);

            void                SendUpdateCmd(u64   _u64Cmd,
                                              s64   _s64Param1,
                                              s64   _s64Param2);

            void                SendUpdateCmd(u64   _u64Cmd,
                                              u64   _u64Param1);

            void                SendUpdateCmd(u64   _u64Cmd,
                                              u64   _u64Param1,
                                              u64   _u64Param2);


        /*******************************************************************************
        * qWin interface
        *******************************************************************************/
        public:
            virtual bool        OnSysCreate();
            virtual void        OnSetCursor();

    }; // class qMainWin

} // namespace aLib
