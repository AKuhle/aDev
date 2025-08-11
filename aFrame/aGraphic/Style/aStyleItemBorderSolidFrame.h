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

#include "aStyleItemBorderSolid.h"

using namespace aFrame::aUtil;


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aFrame {
namespace aWin {


/*******************************************************************************
* class aStyleItemBorderSolidFrame
*******************************************************************************/
class aStyleItemBorderSolidFrame : public aStyleItemBorderSolid
{
    private:
        s32         m_s32FrameThickness;
        aColor      m_colFrame;

    public:
        aStyleItemBorderSolidFrame(const aMargin    &_margin,
                                   const aColor     &_col,
                                   s32              _s32FrameThickness,
                                   const aColor     &_colFrame);
        virtual ~aStyleItemBorderSolidFrame();

        void            setFrameThickness(s32 _s32FrameThickness)   { m_s32FrameThickness = _s32FrameThickness; }
        s32             frameThickness() const                      { return m_s32FrameThickness; }

        void            setFrameColor(const aColor &_colFrame)      { m_colFrame = _colFrame; }
        const aColor&   frameColor() const                          { return m_colFrame; }

        void            draw(aPainter       &_p,
                             const aRect    &_r) override;
}; // class aStyleItemBorderSolidFrame


} // namespace aWin
} // namespace aFrame
