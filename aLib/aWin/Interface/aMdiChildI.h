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
* class aMdiChildI
*******************************************************************************/
class aMdiChildI
{
    public:
        virtual ~aMdiChildI() = default;

    protected:
        virtual void            setCentralWin(SysWin *_pWin) = 0;
        virtual SysWin*         centralWin() = 0;

}; // class aMdiChildI


} // namespace aWin
} // namespace aLib
