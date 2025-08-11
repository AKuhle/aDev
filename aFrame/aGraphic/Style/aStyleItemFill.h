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
#include "aUtil_def.h"
#include "aWin_def.h"

#include "aStyleItem.h"

using namespace aFrame::aUtil;


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aFrame {
namespace aWin {


/*******************************************************************************
* class aStyleItemFill
*******************************************************************************/
class aStyleItemFill : public aStyleItem
{
    public:
        aStyleItemFill();
        virtual ~aStyleItemFill();
}; // class aStyleItemFill


} // namespace aWin
} // namespace aFrame
