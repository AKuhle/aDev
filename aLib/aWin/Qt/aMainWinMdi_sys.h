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

#include "aMainWinMdi_sysi.h"

#include "aSysWin.h"



/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aWin {


/*******************************************************************************
* class aMainWinMdi_sys
*******************************************************************************/
template<class T>
class aMainWinMdi_sys : public aSysWin<T>,
                        public aMainWinMdi_sysi
{
    /*******************************************************************************
    * con-/destruction
    *******************************************************************************/
    protected:
        aMainWinMdi_sys(SysWinClass *_pParent = nullptr);
        ~aMainWinMdi_sys();

}; // class aMainWinMdi_sys


} // namespace aWin
} // namespace aLib

#include "aMainWinMdi_sys.inl"

#endif //_USE_QT_
