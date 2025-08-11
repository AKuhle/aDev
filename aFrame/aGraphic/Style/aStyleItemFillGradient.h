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
        aColor      m_colStart;
        aColor      m_colEnd;
        s32         m_s32Angle;

    public:
        aStyleItemFillGradient(const aColor &_colStart,
                               const aColor &_colEnd,
                               s32          _s32Angle);
        virtual ~aStyleItemFillGradient();

        void            setColor(const aColor   &_colStart,
                                 const aColor   &_colEnd);
        aColor          startColor() const;
        aColor          endColor() const;
        s32             angle() const;

        void            draw(aPainter       &_p,
                             const aRect    &_r) override;
}; // class aStyleItemFillGradient


} // namespace aWin
} // namespace aFrame
