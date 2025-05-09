/*******************************************************************************
* \file qWin.h
* \author Andreas Kuhlewind
*
* \brief
*
*  Detailed description starts here.
*******************************************************************************/
#pragma once

#ifdef _USE_QT_


/*******************************************************************************
* includes
*******************************************************************************/
#include "aWin_def.h"
#include "aButtonI.h"
#include "aCtrl.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aWin {


/*******************************************************************************
* class aButton
*******************************************************************************/
template<class T>
class aButton : public aCtrl<T>,
                public aButtonI
{
    /*******************************************************************************
    * con-/destruction
    *******************************************************************************/
    protected:
        aButton(SysWin *_pParent);
        virtual ~aButton();


    /*******************************************************************************
    * aButtonI interface
    *******************************************************************************/
    public:
        void            setCtrlChecked(bool _bChecked) override;
        void            setCtrlEnabledChecked(bool _bEnabled,
                                              bool _bChecked) override;
        bool            ctrlChecked() const override;
}; // class aButton


} // namespace aWin
} // namespace aLib

#include "aButton.inl"

#endif //_USE_QT_
