/*******************************************************************************
* \file qCtrlBar.h
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
#include "qCtrlBarBase.h"


namespace qLib
{
    /*******************************************************************************
    * class qCtrlBar
    *******************************************************************************/
    class qCtrlBar : public qCtrlBarBase
    {
        public:
            qCtrlBar(qWin  *_pParent = nullptr);
            ~qCtrlBar();


        /*******************************************************************************
        * qWin interface
        *******************************************************************************/
        public:
            virtual bool                OnCreate() override;
    }; // class qCtrlBar

} // namespace aLib