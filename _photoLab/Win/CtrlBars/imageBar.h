/*******************************************************************************
* \file ImageBar.h
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
* class ImageBar
*******************************************************************************/
class ImageBar : public aCtrlBar
{
    public:
        ImageBar(aBaseWin       *_pParent   = nullptr);
        ~ImageBar();


    /*******************************************************************************
    * qCtrlMgr interface
    *******************************************************************************/
    protected:
        virtual void                onRegisterCtrl() override;
        virtual void                onUpdateCtrl(aCtrl *_pCtrl) override;
        virtual void                onCtrlClicked(aCtrl *_pCtrl) override;

}; // class ImageBar
