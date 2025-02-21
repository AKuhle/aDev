/*******************************************************************************
* \file qStatusBar.h
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
#include "qCtrlBar.h"


namespace qLib
{
    /*******************************************************************************
    * class qStatusBar
    *******************************************************************************/
    class qStatusBar : public qCtrlBar
    {
        public:
            qStatusBar(qWin  *_pParent = nullptr);
            ~qStatusBar();


        /*******************************************************************************
        * qCtrlMgr interface
        *******************************************************************************/
        public:
            virtual void                OnRegisterCtrl() override;
            virtual void                OnUpdateCtrl(qCtrlBase *_pCtrl) override;

    }; // class qStatusBar

} // namespace aLib
