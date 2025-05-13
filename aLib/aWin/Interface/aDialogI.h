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
* class aDialogI
*******************************************************************************/
class aDialogI
{
    public:
        virtual ~aDialogI() = default;

    public:
        virtual DialogReturn        showModal() = 0;

        virtual void                onAccepted() {}

}; // class aDialogI


} // namespace aWin
} // namespace aLib
