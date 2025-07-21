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
#include "aMainWin_i.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aFrame {
namespace aWin {


/*******************************************************************************
* class aMainWin
*******************************************************************************/
class aMainWin : public aMainWin_i
{
    /*******************************************************************************
    * con-/destruction
    *******************************************************************************/
    protected:
        aMainWin(SysWin *_pParent);
        virtual ~aMainWin();


    /*******************************************************************************
    * aMainWinI interface
    *******************************************************************************/
    protected:
        // void                setCentralWin(SysWin *_pWin) override;
        // SysWin*             centralWin() override;
        // SysWin*             centralWin() const override;

        // void                setStatusBar(aStatusBar *_pBar) override;
        // aStatusBar*         statusBar() const override;

        // void                addDockWin(const aString &_sTile,
        //                                aDockWin      *_pDockWin,
        //                                u16           _u16Area) override;

        // void                saveWinGeometry(const aString   &_sCompany,
        //                                     const aString   &_sApplication);

        // void                restoreWinGeometry(const aString    &_sCompany,
        //                                        const aString    &_sApplication);

    public:
        // void                sendUpdateCmd(u64 _u64Cmd) override;

        // void                sendUpdateCmd(u64   _u64Cmd,
        //                                   aDoc  *_pDoc) override;

        // void                sendUpdateCmd(u64   _u64Cmd,
        //                                   aView *_pView) override;

        // void                sendUpdateCmd(u64   _u64Cmd,
        //                                   aDoc  *_pDoc,
        //                                   aView *_pView) override;

        // void                sendUpdateCmd(u64   _u64Cmd,
        //                                   s64   _s64Param1) override;

        // void                sendUpdateCmd(u64   _u64Cmd,
        //                                   s64   _s64Param1,
        //                                   s64   _s64Param2) override;

        // void                sendUpdateCmd(u64   _u64Cmd,
        //                                   u64   _u64Param1) override;

        // void                sendUpdateCmd(u64   _u64Cmd,
        //                                   u64   _u64Param1,
        //                                   u64   _u64Param2) override;
}; // class aMainWin


} // namespace aWin
} // namespace aFrame
