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


/*******************************************************************************
* includes
*******************************************************************************/
#pragma once

#include "qLib.h"

#include "ui_formMainWin.h"

#include "defsPl.h"
#include "varPoolPl.h"

using namespace qLib;


/*******************************************************************************
* forwards
*******************************************************************************/
class MainWin;
class ViewBase;
class ViewNavigator;
class CmdBase;
class DocPl;
class NavigatorToolWin;
class ToolBoxToolWin;
class ProtocolToolWin;
class RenderParams;

class OptionMoveWin;
class OptionZoomWin;


/*******************************************************************************
* globals
*******************************************************************************/
MainWin&                GetMainWin();
VarPoolPl&              GetVarPool();

ViewBase*               GetActiveView();
std::shared_ptr<DocPl>  GetActiveDoc();
shared_ptr<qLayerStack> GetActiveLS();

ViewBase*               GetActiveOrTopmostView();
const RenderParams*     GetActiveOrTopmostRenderParams();
std::shared_ptr<DocPl>  GetActiveOrTopmostDoc();
shared_ptr<qLayerStack> GetActiveOrTopmostLS();


/*******************************************************************************
* class MainWin
*******************************************************************************/
class MainWin : public qMainWinMdi,
                public qCmdMgr,
                public qProgress
{
    private:
        Ui::FormMainWin     *m_pUi                  { nullptr };

        VarPoolPl           m_varPool;

        qDockWin            *m_pOptionDockWin       { nullptr };
        OptionMoveWin       *m_pOptionMoveWin       { nullptr };
        OptionZoomWin       *m_pOptionZoomWin       { nullptr };

        qDockWin            *m_pToolBoxDockWin      { nullptr };
        ToolBoxToolWin      *m_pToolBoxToolWin      { nullptr };

        qDockWin            *m_pNavigatorDockWin    { nullptr };
        NavigatorToolWin    *m_pNavigatorToolWin    { nullptr };

        qDockWin            *m_pProtocolDockWin     { nullptr };
        ProtocolToolWin     *m_pProtocolToolWin     { nullptr };

        bool                m_bCalculating          { false };
        enumMode            m_eMode                 { enumMode::None };

    public:
        MainWin();
        ~MainWin();

        void                SetMode(enumMode _eMode);
        enumMode            Mode() const;

        VarPoolPl&          VarPool()   { return m_varPool; }

        bool                IsCalculating() const;

    private:
        void                UpdateTools();


    /*******************************************************************************
    * io
    *******************************************************************************/
    private:
        void                OnOpenFile();
        void                OpenFile(const qString16  &_sFileName);
        void                CreateDocView(std::unique_ptr<qCmdI> _pCmd);


    /*******************************************************************************
    * qMainWin interface
    *******************************************************************************/
    protected:
        // virtual qTitleBar*  OnCreateTitleBar();

        virtual void        OnUpdateCmd(u64    _u64Cmd,
                                        qDocI  *_pDoc,
                                        qViewI *_pView,
                                        s64    _s64Param1,
                                        s64    _s64Param2,
                                        u64    _u64Param1,
                                        u64    _u64Param2,
                                        flt    _fltParam1,
                                        flt    _fltParam2,
                                        dbl    _dblParam1,
                                        dbl    _dblParam2,
                                        void   *_pParam1,
                                        void   *_pParam2) override;


    /*******************************************************************************
    * qMainWinMdi interface
    *******************************************************************************/
    protected:
        virtual void        OnMdiWinActivated(qMdiWin *_pMdiWin) override;


    /*******************************************************************************
    * qCtrlManager interface
    *******************************************************************************/
    protected:
        virtual void        OnRegisterCtrl() override;
        virtual void        OnUpdateCtrl(qCtrlI *_pCtrl) override;

        virtual void        OnCtrlMessage(qCtrlI    *_pCtrl,
                                          u32       _u32Mes,
                                          s64       _s64Value = 0,
                                          void      *_pVoid1    = nullptr,
                                          void      *_pVoid2    = nullptr) override;

    private:
        void                StartCmd(u32    _u32CtrlId);

    /*******************************************************************************
    * qCmdMgr interface
    *******************************************************************************/
    protected:
        virtual void        OnCmdProcessingStart(qCmdI *_pCmd) override;
        virtual void        OnCmdProcessingEnd(qCmdI *_pCmd) override;
        virtual void        OnDoDone(qCmdI *_pCmd) override;


    /*******************************************************************************
    * qSysWin interface
    *******************************************************************************/
    protected:
        virtual bool        OnCreate() override;
        virtual bool        OnClose() override;

        virtual void        OnDropUrl(const qUrl &_url) override;



    /*******************************************************************************
    * qSysWin interface
    *******************************************************************************/
    protected:
        virtual void		OnOpenProgressDisplay() override;
        virtual void		OnCloseProgressDisplay() override;
        virtual void		OnUpdateProgressDisplay(const qString16 &_sInfoText) override;
        virtual void		OnUpdateProgressDisplay(u16 _u16Progress_pml) override;


        DECLARE_DROP_EVENT

}; // class MainWin
