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

#include "ui_formNavigator.h"

#include "toolWinBase.h"
#include "aCtrlMgr.h"

using namespace aLib;
using namespace aLib::aWin;


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
class NavigatorToolWin : public ToolWinBase,
                         public aCtrlMgr
                // public qCmdMgr,
                // public qProgress
{
    private:
        Ui::FormNavigator   *m_pUi                 { nullptr };


    public:
        NavigatorToolWin(SysWin *_pParent = nullptr);
        ~NavigatorToolWin();


    private:
        NavigatorView*      navigatorView() const;

        void                setZoomFactor(dbl _dZoomFaktor) const;
        void                setZoomFactorFit() const;


    /*******************************************************************************
    * ToolWinBase interface
    *******************************************************************************/
    public:
        void                updateToolWin() override;


    /*******************************************************************************
    * aCtrlMgr interface
    *******************************************************************************/
    public:
        void                onRegisterCtrl() override;
        void                onUpdateCtrl(aCtrlI *_pCtrl) override;

        void                onCtrlClicked(aCtrlI *_pCtrl) override;


    /*******************************************************************************
    * aBaseWin interface
    *******************************************************************************/
    protected:
        bool                onCreateWin() override;
}; // class NavigatorToolWin
