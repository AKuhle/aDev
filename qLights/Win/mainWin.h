/*******************************************************************************
* \file mainWin.h
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
#ifdef _USE_QT_
    #include "ui_formMainWin.h"
#endif

#include "aAppMainWin.h"
#include "qLights_defs.h"
#include "aMainWinSdi.h"

using namespace aLib;
using namespace aLib::aWin;
using namespace aLib::aUtil;

class MainWin;
class CtrlPanel;


/*******************************************************************************
* globals
*******************************************************************************/
MainWin&                    getMainWin();


/*******************************************************************************
* class MainWin
*******************************************************************************/
class MainWin : public aMainWinSdi,
                public aCtrlMgr
{
    Q_OBJECT

    private:
        #ifdef _USE_QT_
            Ui::FormMainWin     *m_pUi { nullptr };
        #endif

        enumWorkMode            m_eWorkMode             { enumWorkMode::Edit };
        CtrlPanel               *m_pCtrlPanel           { nullptr };

    public:
        MainWin();
        ~MainWin();

        enumWorkMode            workMode() const        { return m_eWorkMode; }


    /*******************************************************************************
    * aSysWin interface
    *******************************************************************************/
    protected:
        bool                onCreateWin() override;
        bool                onCloseWin() override;


    /*******************************************************************************
    * aMainWin_i interface
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
                                        void    *_pParam2) override;


    /*******************************************************************************
    * aCtrlMgr interface
    *******************************************************************************/
    public:
        void                onRegisterCtrl() override;
        void                onUpdateCtrl(aCtrlI *_pCtrl) override;

        void                onCtrlClicked(aCtrlI *_pCtrl) override;

}; // class MainWin
