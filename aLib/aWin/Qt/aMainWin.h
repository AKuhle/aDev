/*******************************************************************************
* \file qWin.h
* \author Andreas Kuhlewind
*
* \brief
*
*  Detailed description starts here.
*******************************************************************************/
#pragma once

#ifdef _USE_QT_


/*******************************************************************************
* includes
*******************************************************************************/
#include <QMainWindow>

#include "aWin_def.h"
#include "aMainWinI.h"
#include "aBaseWin.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aWin {


/*******************************************************************************
* class aMainWin
*******************************************************************************/
class aMainWin : public aBaseWin<QMainWindow>,
                 public aMainWinI
{
    /*******************************************************************************
    * con-/destruction
    *******************************************************************************/
    protected:
        aMainWin(SysWin *_pParent);
        virtual ~aMainWin();


    /*******************************************************************************
    * aMainWini interface
    *******************************************************************************/
    protected:
        void                setCentralWin(SysWin *_pWin) override;
        SysWin*             centralWin() override;

        void                onUpdateCmd(u64     _u64Cmd,
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
                                        void    *_pParam2) override;
    public:
        void                sendUpdateCmd(u64 _u64Cmd) override;

        void                sendUpdateCmd(u64   _u64Cmd,
                                          aDoc  *_pDoc) override;

        void                sendUpdateCmd(u64   _u64Cmd,
                                          aView *_pView) override;

        void                sendUpdateCmd(u64   _u64Cmd,
                                          aDoc  *_pDoc,
                                          aView *_pView) override;

        void                sendUpdateCmd(u64   _u64Cmd,
                                          s64   _s64Param1) override;

        void                sendUpdateCmd(u64   _u64Cmd,
                                          s64   _s64Param1,
                                          s64   _s64Param2) override;

        void                sendUpdateCmd(u64   _u64Cmd,
                                          u64   _u64Param1) override;

        void                sendUpdateCmd(u64   _u64Cmd,
                                          u64   _u64Param1,
                                          u64   _u64Param2) override;
}; // class aMainWin


} // namespace aWin
} // namespace aLib


#endif //_USE_QT_
