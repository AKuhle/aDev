/*******************************************************************************
* \file aWinStyleFactory.h
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
#include "aWIn/aWin_def.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aWin {


/*******************************************************************************
* class aWinStyleFactory
*******************************************************************************/
class aWinStyleFactory
{
    public:
        aWinStyleFactory();
        ~aWinStyleFactory();

    public:
        virtual void                setWinStyle(aBaseWin &_win) = 0;
}; // class aWinStyleFactory


} // namespace aWin
} // namespace aLib
