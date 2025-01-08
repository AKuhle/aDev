/*******************************************************************************
* \file StdBar.h
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
#include "qLib.h"


namespace qLib
{
    /*******************************************************************************
    * class StdBar
    *******************************************************************************/
    class StdBar : public qCtrlBar
    {
        public:
            StdBar(qWin  *_pParent = nullptr);
            ~StdBar();


        /*******************************************************************************
        * qCtrlMgr interface
        *******************************************************************************/
        protected:
            virtual void                OnRegisterCtrl() override;
            virtual void                OnUpdateCtrl(qCtrlBase *_pCtrl) override;
            virtual void                OnCtrlClicked(qCtrlBase *_pCtrl) override;

    }; // class StdBar

} // namespace aLib
