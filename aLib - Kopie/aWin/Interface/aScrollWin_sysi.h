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
#include "aUtil/aUrl.h"

using namespace aLib::aUtil;


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aWin {


/*******************************************************************************
* class aScrollWin_sysi
*******************************************************************************/
class aScrollWin_sysi
{
    protected:
        virtual void            setCentralWin(SysWinClass *_pWin) = 0;
        virtual SysWinClass*    centralWin() = 0;

        // policy
        virtual void            setHoriScrollBarPolicy(ScrollBarPolicy _policy) = 0;
        virtual void            setVertScrollBarPolicy(ScrollBarPolicy _policy) = 0;

}; // class aScrollWin_sysi


} // namespace aWin
} // namespace aLib
