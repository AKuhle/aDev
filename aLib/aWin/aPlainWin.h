/*******************************************************************************
* \file qWin.h
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
#include "aPlainWin_sys.h"



/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aWin {


/*******************************************************************************
* class aPlainWin
*******************************************************************************/
class aPlainWin : public aPlainWin_sys
{
    /*******************************************************************************
    * con-/destruction
    *******************************************************************************/
    protected:
        aPlainWin(SysWinClass *_pParent = nullptr);
        ~aPlainWin();

}; // class aPlainWin


} // namespace aWin
} // namespace aLib
