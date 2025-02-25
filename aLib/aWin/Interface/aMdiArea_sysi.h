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
#include "aWin_def.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aWin {


/*******************************************************************************
* class aMdiArea_sysi
*******************************************************************************/
class aMdiArea_sysi
{
    protected:
        virtual void            _addMdiWin(aMdiWin *_pMdiWin) = 0;

}; // class aMdiArea_sysi


} // namespace aWin
} // namespace aLib
