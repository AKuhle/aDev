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
* class aMainWinMdiI
*******************************************************************************/
class aMainWinMdiI
{
    public:
        virtual ~aMainWinMdiI() = default;

    /*******************************************************************************
    * mdi win management
    *******************************************************************************/
    protected:
        virtual aMdiArea*       mdiArea() = 0;
        virtual void            addMdiChild(aMdiChild *_pMdiChild) = 0;

}; // class aMainWinMdiI


} // namespace aWin
} // namespace aLib
