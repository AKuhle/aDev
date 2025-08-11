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

#include "aStyleItemBorder.h"

using namespace aFrame::aUtil;


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aFrame {
namespace aWin {


/*******************************************************************************
* class aStyleItemBorderSolid
*******************************************************************************/
class aStyleItemBorderSolid : public aStyleItemBorder
{
    public:
        aStyleItemBorderSolid(const aMargin  &_margin,
                              const aColor   &_col);
        virtual ~aStyleItemBorderSolid();


        void            draw(aPainter       &_p,
                             const aRect    &_r) override;
}; // class aStyleItemBorderSolid


} // namespace aWin
} // namespace aFrame
