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
* class aMdiArea_sysi
*******************************************************************************/
class aMdiArea_sysi
{
    protected:
        virtual void            addMdiChild(aMdiChild *_pMdiChild) = 0;
}; // class aMdiArea_sysi


} // namespace aWin
} // namespace aLib
