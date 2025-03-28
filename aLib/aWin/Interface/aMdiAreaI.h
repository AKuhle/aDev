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
* class aMdiAreaI
*******************************************************************************/
class aMdiAreaI
{
    public:
        virtual ~aMdiAreaI() = default;

    public:
        virtual void            addMdiChild(aMdiChild *_pMdiChild) = 0;
}; // class aMdiAreaI


} // namespace aWin
} // namespace aLib
