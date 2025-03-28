/*******************************************************************************
* \file qWin.h
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
#include "aMainWin_sys.h"



/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aWin {


/*******************************************************************************
* class aMainWin
*******************************************************************************/
class aMainWin : public aMainWin_sys
{
    /*******************************************************************************
    * con-/destruction
    *******************************************************************************/
    protected:
        aMainWin(SysWinClass *_pParent = nullptr);
        ~aMainWin();

        void                setCentralWin(SysWinClass *_pWin);
        SysWinClass*        centralWin();


    /*******************************************************************************
    * update
    *******************************************************************************/
    protected:
        virtual void        onUpdateCmd(u64     _u64Cmd,
                                        aDoc    *_pDoc,
                                        aView   *_pView,
                                        s64     _s64Param1,
                                        s64     _s64Param2,
                                        u64     _u64Param1,
                                        u64     _u64Param2,
                                        flt     _fltParam1,
                                        flt     _fltParam2,
                                        dbl     _dblParam1,
                                        dbl     _dblParam2,
                                        void    *_pParam1,
                                        void    *_pParam2) = 0;


    // public:
        void                sendUpdateCmd(u64 _u64Cmd);

        void                sendUpdateCmd(u64   _u64Cmd,
                                          aDoc  *_pDoc);

        void                sendUpdateCmd(u64   _u64Cmd,
                                          aView *_pView);

        void                sendUpdateCmd(u64   _u64Cmd,
                                          aDoc  *_pDoc,
                                          aView *_pView);

        void                sendUpdateCmd(u64   _u64Cmd,
                                          s64   _s64Param1);

        void                sendUpdateCmd(u64   _u64Cmd,
                                          s64   _s64Param1,
                                          s64   _s64Param2);

        void                sendUpdateCmd(u64   _u64Cmd,
                                          u64   _u64Param1);

        void                sendUpdateCmd(u64   _u64Cmd,
                                          u64   _u64Param1,
                                          u64   _u64Param2);

}; // class aMainWin


} // namespace aWin
} // namespace aLib
