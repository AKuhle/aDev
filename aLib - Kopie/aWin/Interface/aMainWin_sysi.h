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
* class aMainWin_sysi
*******************************************************************************/
class aMainWin_sysi
{
    protected:
        virtual void            setCentralWin(SysWinClass *_pWin) = 0;
        virtual SysWinClass*    centralWin() = 0;

}; // class aMainWin_sysi


} // namespace aWin
} // namespace aLib
