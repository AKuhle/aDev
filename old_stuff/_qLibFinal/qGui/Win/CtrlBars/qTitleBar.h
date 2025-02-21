/*******************************************************************************
* \file qTitleBar.h
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
    * class qTitleBar
    *******************************************************************************/
    class qTitleBar : public qCtrlBar
    {
        DeclareBoolProperty(Active, false);

        public:
            qTitleBar(qWin  *_pParent = nullptr);
            ~qTitleBar();


        /*******************************************************************************
        * qCtrlMgr interface
        *******************************************************************************/
        protected:
            virtual void                OnRegisterCtrl() override;
            virtual void                OnUpdateCtrl(qCtrlBase *_pCtrl) override;
            virtual void                OnCtrlClicked(qCtrlBase *_pCtrl) override;

    }; // class qTitleBar

} // namespace aLib
