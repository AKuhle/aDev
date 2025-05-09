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
#include "aLib_def.h"
#include "aCtrlBar.h"

using namespace aLib;
using namespace aLib::aWin;


/*******************************************************************************
* class StdBar
*******************************************************************************/
class StdBar : public aCtrlBar
{
    public:
        StdBar(aBaseWin     *_pParent   = nullptr);
        ~StdBar();


    /*******************************************************************************
    * qCtrlMgr interface
    *******************************************************************************/
    protected:
        virtual void                onRegisterCtrl() override;
        virtual void                onUpdateCtrl(aCtrl *_pCtrl) override;
        virtual void                onCtrlClicked(aCtrl *_pCtrl) override;

}; // class StdBar
