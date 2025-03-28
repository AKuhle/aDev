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


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aWin {


/*******************************************************************************
* class aCtrl_sys
*******************************************************************************/
template<class T>
class aCtrl_sys : public T
{
    /*******************************************************************************
    * con-/destruction
    *******************************************************************************/
    protected:
        aCtrl_sys(SysWinClass *_pParent);

    public:
        virtual ~aCtrl_sys();

}; // class aCtrl_sys


} // namespace aWin
} // namespace aLib

#include "aCtrl_sys.inl"

#endif //_USE_QT_
