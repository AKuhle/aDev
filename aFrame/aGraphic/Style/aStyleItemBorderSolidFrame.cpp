/*******************************************************************************
* \file aStyleItemBorderSolidFrame.cpp
* \author Andreas Kuhlewind
*
* \brief
*
*  Detailed description starts here.
*******************************************************************************/


/*******************************************************************************
* includes
*******************************************************************************/
#include "aFrame_def.h"

#include "aStyleItemBorderSolidFrame.h"
#include "aPath.h"
#include "aJsonFile.h"

#include "aPainter.h"
#include "aPen.h"

#include "aMainWin.h"

using namespace std;


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aFrame {
namespace aWin {


/*******************************************************************************
* aStyleItemBorderSolidFrame::aStyleItemBorderSolidFrame
*******************************************************************************/
aStyleItemBorderSolidFrame::aStyleItemBorderSolidFrame(const aMargin    &_margin,
                                                       const aColor     &_col,
                                                       s32              _s32FrameThickness,
                                                       const aColor     &_colFrame)
: aStyleItemBorderSolid(_margin, _col),
  m_s32FrameThickness(_s32FrameThickness),
  m_colFrame(_colFrame)
{
} // aStyleItemBorderSolidFrame::aStyleItemBorderSolidFrame


/*******************************************************************************
* aStyleItemBorderSolidFrame::~aStyleItemBorderSolidFrame
*******************************************************************************/
aStyleItemBorderSolidFrame::~aStyleItemBorderSolidFrame()
{
} // aStyleItemBorderSolidFrame::~aStyleItemBorderSolidFrame


/*******************************************************************************
* aStyleItemBorderSolidFrame::draw
*******************************************************************************/
void aStyleItemBorderSolidFrame::draw(aPainter       &_p,
                                      const aRect    &_r)
{
    // 1. draw the border
    aStyleItemBorderSolid::draw(_p, _r);

    // 2. draw the outer frame of the border
    aPen    pen(m_colFrame, m_s32FrameThickness);

    _p.drawRect(_r, &pen);
} // aStyleItemBorderSolidFrame::draw


} // namespace aWin
} // namespace aFrame
