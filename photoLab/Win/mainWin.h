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
#include "photoLab_defs.h"
#include "aMainWinMdi.h"

// #include "aCmdMgr.h"
// #include "aCtrlMgr.h"

// #include "aLayerStack.h"
// #include "cmdBase.h"
// #include "varPool.h"

// #ifdef _USE_QT_
//     #include "ui_formMainWin.h"
// #endif

using namespace aFrame;
using namespace aFrame::aWin;
using namespace aFrame::aUtil;

class MainWin;
class ViewBase;
class Document;
class StatusBar;
class NavigatorToolWin;


/*******************************************************************************
* globals
*******************************************************************************/
// MainWin&                    getMainWin();
// StatusBar&                  getStatusBar();

// ViewBase*                   getActiveView();
// shared_ptr<Document>        getActiveDoc();
// shared_ptr<SynchronizedLS>  getActiveLS();

// ViewBase*                   getTopmostView();
// shared_ptr<Document>        getTopmostDoc();
// shared_ptr<SynchronizedLS>  getTopmostLS();


/*******************************************************************************
* class MainWin
*******************************************************************************/
class MainWin : public aMainWinMdi
                // public aCmdMgr,
                // public aCtrlMgr
{
    private:
        // #ifdef _USE_QT_
        //     Ui::FormMainWin     *m_pUi                  { nullptr };
        // #endif

        // VarPool             m_varPool;

        // enumEditMode        m_eEditMode                 { enumEditMode::Move };

        // StatusBar           *m_pStatusBar               { nullptr };

        // aDockWin            *m_pNavigatorDockWin        { nullptr };
        // NavigatorToolWin    *m_pNavigatorToolWin        { nullptr };

        // // true => app is busy, e.g. running a cmd
        // bool                m_bBusy                     { false };

    public:
        MainWin();
        ~MainWin();

    //     bool                busy() const;

    //     const StatusBar&    mwStatusBar() const         { return *m_pStatusBar; }
    //     StatusBar&          mwStatusBar()               { return *m_pStatusBar; }

    //     void                setEditMode(enumEditMode _eMode);
    //     enumEditMode        editMode() const;

    // private:
    //     void                viewList(aPtrList<ViewBase> &_lstView) const;


    /*******************************************************************************
    * mainWin_io
    *******************************************************************************/
    public:
        // void                openFile();
        // void                openFile(const aPath &_path);


    /*******************************************************************************
    * aCmdMgr interface
    *******************************************************************************/
    protected:
        // virtual void        onCmdProcessingStart(const shared_ptr<aCmdBase> &_pCmd);
        // virtual void        onCmdProcessingEnd(const shared_ptr<aCmdBase> &_pCmd);

        // void                onDoDone(const shared_ptr<aCmdBase> &_pCmd) override;

    private:
        // void                startCmd(u32 _u32CtrlId);


    /*******************************************************************************
    * aCtrlMgr interface
    *******************************************************************************/
    public:
        // void                onRegisterCtrl() override;
        // void                onUpdateCtrl(aCtrlI *_pCtrl) override;

        // void                onCtrlClicked(aCtrlI *_pCtrl) override;


    /*******************************************************************************
    * aSysWin interface
    *******************************************************************************/
    protected:
        bool                onCreateWin() override;
        // bool                onCloseWin() override;
        // void                onDropUrl(const aUrl  &_url) override;


    /*******************************************************************************
    * aMainWin_i interface
    *******************************************************************************/
    protected:
        // virtual void        onUpdateCmd(u64     _u64Cmd,
        //                                 aDoc    *_pDoc,
        //                                 aView   *_pView,
        //                                 s64     _s64Param1,
        //                                 s64     _s64Param2,
        //                                 u64     _u64Param1,
        //                                 u64     _u64Param2,
        //                                 flt     _fltParam1,
        //                                 flt     _fltParam2,
        //                                 dbl     _dblParam1,
        //                                 dbl     _dblParam2,
        //                                 void    *_pParam1,
        //                                 void    *_pParam2) override;

}; // class MainWin
