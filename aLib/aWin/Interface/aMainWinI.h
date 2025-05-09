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
#include "aWin_def.h"
#include "aUtil/aUrl.h"

using namespace aLib::aUtil;


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aWin {


/*******************************************************************************
* class aMainWinI
*******************************************************************************/
class aMainWinI
{
    public:
        virtual ~aMainWinI() = default;

    protected:
        virtual void        setCentralWin(SysWin *_pWin) = 0;
        virtual SysWin*     centralWin() = 0;
        virtual SysWin*     centralWin() const = 0;

        virtual void        setStatusBar(aStatusBar *_pBar) = 0;
        virtual aStatusBar* statusBar() const = 0;

        virtual void        addDockWin(const aString &_sTile,
                                       aDockWin      *_pDockWin,
                                       u16           _u16Area) = 0;

        virtual void        saveWinGeometry(const aString   &_sCompany,
                                            const aString   &_sApplication) = 0;

        virtual void        restoreWinGeometry(const aString    &_sCompany,
                                               const aString    &_sApplication) = 0;


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


    public:
        virtual void        sendUpdateCmd(u64 _u64Cmd) = 0;

        virtual void        sendUpdateCmd(u64   _u64Cmd,
                                          aDoc  *_pDoc) = 0;

        virtual void        sendUpdateCmd(u64   _u64Cmd,
                                          aView *_pView) = 0;

        virtual void        sendUpdateCmd(u64   _u64Cmd,
                                          aDoc  *_pDoc,
                                          aView *_pView) = 0;

        virtual void        sendUpdateCmd(u64   _u64Cmd,
                                          s64   _s64Param1) = 0;

        virtual void        sendUpdateCmd(u64   _u64Cmd,
                                          s64   _s64Param1,
                                          s64   _s64Param2) = 0;

        virtual void        sendUpdateCmd(u64   _u64Cmd,
                                          u64   _u64Param1) = 0;

        virtual void        sendUpdateCmd(u64   _u64Cmd,
                                          u64   _u64Param1,
                                          u64   _u64Param2) = 0;
}; // class aMainWinI


} // namespace aWin
} // namespace aLib
