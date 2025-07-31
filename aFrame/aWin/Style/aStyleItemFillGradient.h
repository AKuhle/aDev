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

#include "aColor.h"
#include "aStyleItemFill.h"

using namespace aFrame::aUtil;


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aFrame {
namespace aWin {


/*******************************************************************************
* class aStyleItemFillGradient
*******************************************************************************/
class aStyleItemFillGradient : public aStyleItemFill
{
    private:
        aColor      m_fillColor1;
        aColor      m_fillColor2;
        s32         m_s32Angle;

    public:
        aStyleItemFillGradient(const aColor &_col1,
                               const aColor &_col2,
                               s32          _s32Angle);
        virtual ~aStyleItemFillGradient();

        void            setFillColor(const aColor   &_col1,
                                     const aColor   &_col2);
        aColor          fillColor1() const;
        aColor          fillColor2() const;
        s32             angle() const;
}; // class aStyleItemFillGradient


} // namespace aWin
} // namespace aFrame
