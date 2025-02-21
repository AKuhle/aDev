/*******************************************************************************
* \file BaseApp.h
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
#include "aLib_def.h"

#include "aMdiMainWin.h"
#include "aCmdMgr.h"
#include "aCtrlMgr.h"
#include "document.h"
#include "viewBase.h"
#include "aLayerStack.h"
#include "editView.h"
#include "statusBar.h"

using namespace aLib;
using namespace aLib::aWin;

class MainWin;


/*******************************************************************************
* globals
*******************************************************************************/
MainWin&                    getMainWin();
ViewBase*                   getActiveView();
shared_ptr<Document>        getActiveDocument();
shared_ptr<SynchronizedLS>  getActiveLS();


/*******************************************************************************
* class MainWin
*******************************************************************************/
class MainWin : public aMdiMainWin,
                public aCmdMgr,
                public aCtrlMgr
{
    private:
        bool    m_bThreadRunning        { false };

    public:
        MainWin();
        ~MainWin();

        aPtrList<ViewBase>  viewList() const;

        StatusBar*          statusBar();

        bool                isThreadRunning() const;


    private:
        void                startCmd(shared_ptr<CmdBase> _pCmd);

    /*******************************************************************************
    * io
    *******************************************************************************/
    protected:
         void               loadFile();


    /*******************************************************************************
    * aMainWin interface
    *******************************************************************************/
    protected:
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


    /*******************************************************************************
    * aCmdMgr interface
    *******************************************************************************/
    protected:
        virtual void        onCmdProcessingStart(const shared_ptr<aCmdBase> &_pCmd);
        virtual void        onCmdProcessingEnd(const shared_ptr<aCmdBase> &_pCmd);

        void                onDoDone(const shared_ptr<aCmdBase> &_pCmd) override;


     /*******************************************************************************
     * aCtrlMgr interface
     *******************************************************************************/
     protected:
        void                onRegisterCtrl() override;
        void                onUpdateCtrl(aCtrl *_pCtrl) override;
        void                onCtrlClicked(aCtrl *_pCtrl) override;


    /*******************************************************************************
    * BaseWin interface
    *******************************************************************************/
    protected:
        bool                onCreate() override;
        void                onDropUrl(const aUrl &_url) override;

}; // class MainWin
