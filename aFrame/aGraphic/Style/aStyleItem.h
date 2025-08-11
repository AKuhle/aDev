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
#include "aGraphic_def.h"
#include "aWin_def.h"

using namespace aFrame::aUtil;
using namespace aFrame::aGraphic;


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aFrame {
namespace aWin {


/*******************************************************************************
* class aStyleItem
*******************************************************************************/
class aStyleItem
{
    public:
        aStyleItem();
        virtual ~aStyleItem();

        virtual void        draw(aPainter       &_p,
                                 const aRect    &_r) = 0;
}; // class aStyleItem


} // namespace aWin
} // namespace aFrame
