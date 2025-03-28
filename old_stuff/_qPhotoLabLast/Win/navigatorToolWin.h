/*******************************************************************************
* \file NavigatorToolWin.h
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
#include "ui_formNavigator.h"
#include "toolWin.h"

using namespace qLib;


/*******************************************************************************
* forwards
*******************************************************************************/
class ViewNavigator;


/*******************************************************************************
* globals
*******************************************************************************/


/*******************************************************************************
* class NavigatorToolWin
*******************************************************************************/
class NavigatorToolWin : public ToolWin
                // public qCmdMgr,
                // public qProgress
{
    private:
        Ui::FormNavigator   *m_pUi                 { nullptr };

    public:
        NavigatorToolWin();
        ~NavigatorToolWin();

    private:
        ViewNavigator*      NavigatorView() const;


    /*******************************************************************************
    * ToolWin interface
    *******************************************************************************/
    public:
        virtual void        UpdateToolWin() override;


        /*******************************************************************************
    * qCtrlManager interface
    *******************************************************************************/
    protected:
        virtual void        OnRegisterCtrl() override;
        virtual void        OnUpdateCtrl(qCtrlI *_pCtrl) override;

        virtual void        OnCtrlMessage(qCtrlI    *_pCtrl,
                                          u32       _u32Mes,
                                          s64       _s64Value   = 0,
                                          void      *_pVoid1    = nullptr,
                                          void      *_pVoid2    = nullptr) override;


    /*******************************************************************************
    * qSysWin interface
    *******************************************************************************/
    protected:
        virtual bool        OnCreate() override;
}; // class NavigatorToolWin
