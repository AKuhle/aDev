/*******************************************************************************
* \file ctrlPanel.h
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

#include "ui_formCtrlPanel.h"

#include "aPlainWin.h"


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
* class CtrlPanel
*******************************************************************************/
class CtrlPanel : public aPlainWin,
                  public aCtrlMgr
{
    private:
        Ui::FormCtrlPanel   *m_pUi                { nullptr };


    public:
        CtrlPanel(SysWin *_pParent = nullptr);
        ~CtrlPanel();


    private:


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

}; // class CtrlPanel
