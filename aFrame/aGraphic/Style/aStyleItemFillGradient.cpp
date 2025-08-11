/*******************************************************************************
* \file aStyleItemFillGradient.cpp
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

#include "aStyleItemFillGradient.h"
#include "aPath.h"
#include "aJsonFile.h"

#include "aRect2D.h"

#include "aPainter.h"

#include "aMainWin.h"

using namespace std;
using namespace aFrame::aMath;


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aFrame {
namespace aWin {


/*******************************************************************************
* aStyleItemFillGradient::aStyleItemFillGradient
*******************************************************************************/
aStyleItemFillGradient::aStyleItemFillGradient(const aColor &_colStart,
                                               const aColor &_colEnd,
                                               s32          _s32Angle)
: m_colStart(_colStart),
  m_colEnd(_colEnd),
  m_s32Angle(_s32Angle)
{
} // aStyleItemFillGradient::aStyleItemFillGradient


/*******************************************************************************
* aStyleItemFillGradient::~aStyleItemFillGradient
*******************************************************************************/
aStyleItemFillGradient::~aStyleItemFillGradient()
{
} // aStyleItemFillGradient::~aStyleItemFillGradient


/*******************************************************************************
* aStyleItemFillGradient::setColor
*******************************************************************************/
void aStyleItemFillGradient::setColor(const aColor   &_colStart,
                                      const aColor   &_colEnd)
{
    m_colStart  = _colStart;
    m_colEnd    = _colEnd;
} // aStyleItemFillGradient::setColor


/*******************************************************************************
* aStyleItemFillGradient::startColor
*******************************************************************************/
aColor aStyleItemFillGradient::startColor() const
{
    return m_colStart;
} // aStyleItemFillGradient::startColor


/*******************************************************************************
* aStyleItemFillGradient::endColor
*******************************************************************************/
aColor aStyleItemFillGradient::endColor() const
{
    return m_colEnd;
} // aStyleItemFillGradient::endColor


/*******************************************************************************
* aStyleItemFillGradient::angle
*******************************************************************************/
s32 aStyleItemFillGradient::angle() const
{
    return m_s32Angle;
} // aStyleItemFillGradient::angle


/*******************************************************************************
* aStyleItemFillGradient::draw
*******************************************************************************/
void aStyleItemFillGradient::draw(aPainter       &_p,
                                  const aRect    &_r)
{
    aVector<aPoint> vIntersect;

    // calculate the intersection of the content rect with the
    // parametric line through the centerpoint
    aRect2D<float> r2d(_r);
    aParametricLine2D<float> l(r2d.centerPoint(), m_s32Angle);

    // get the intersection points
    r2d.intersect(l, vIntersect);

    // draw the gradient between the found points
    if (vIntersect.size() == 2)
    {
        // draw the gradient
        _p.drawGradientRect(_r, vIntersect.at(0), vIntersect.at(1), m_colStart, m_colEnd);
    }
    else
    {
        // no gradient points found => just fill the rect
        _p.drawFilledRect(_r, &m_colStart);
    }
} // aStyleItemFillGradient::draw


} // namespace aWin
} // namespace aFrame
