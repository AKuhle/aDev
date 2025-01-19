/*******************************************************************************
* \file aTitleBar.h
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
#include "aWin/Framework/aBaseWin.h"
#include "aWin/Ctrl/aCtrlMgr.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aWin {


/*******************************************************************************
* class aTitleBar
*******************************************************************************/
class aTitleBar : public aBaseWin,
                  public aCtrlMgr
{
    public:
        aTitleBar(aBaseWin *_pParent = nullptr);
        ~aTitleBar();


    /*******************************************************************************
    * aCtrlMgr interface
    *******************************************************************************/
    protected:
        void                        onRegisterCtrl() override;
        void                        onUpdateCtrl(aCtrl *_pCtrl) override;

        void                        onCtrlClicked(aCtrl *_pCtrl) override;


    /*******************************************************************************
    * aBaseWin interface
    *******************************************************************************/
    protected:
        bool                        onSysCreate() override;
};


} // namespace aWin
} // namespace aLib
