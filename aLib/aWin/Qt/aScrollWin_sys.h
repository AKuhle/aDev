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
#include "QAbstractScrollArea"

#include "aWin_def.h"

#include "aScrollWin_sysi.h"
#include "aBaseWin.h"



/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aWin {


/*******************************************************************************
* class aScrollWin_sys
*******************************************************************************/
class aScrollWin_sys : public aBaseWin<QAbstractScrollArea>,
                       public aScrollWin_sysi
{
    /*******************************************************************************
    * con-/destruction
    *******************************************************************************/
    protected:
        aScrollWin_sys(SysWinClass *_pParent = nullptr);
        ~aScrollWin_sys();

}; // class aScrollWin_sys


} // namespace aWin
} // namespace aLib


#endif //_USE_QT_
