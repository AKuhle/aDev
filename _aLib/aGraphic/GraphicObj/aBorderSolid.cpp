/*******************************************************************************
* \file aBorderSolid.cpp
* \author Andreas Kuhlewind
*
* \brief
*
*  Detailed description starts here.
*******************************************************************************/


/*******************************************************************************
* includes
*******************************************************************************/
#include "aUtil/aColor.h"

#include "aMath/Obj2D/aRect2D.h"

#include "aGraphic/GraphicObj/aBorderSolid.h"
#include "aGraphic/aPainter.h"



/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aGraphic {


/*******************************************************************************
* aBorderSolid::aBorderSolid
*******************************************************************************/
aBorderSolid::aBorderSolid(const aColor &_color)
: m_color(_color)
{
} // aBorderSolid::aBorderSolid


/*******************************************************************************
* aBorderSolid::~aBorderSolid
*******************************************************************************/
aBorderSolid::~aBorderSolid()
{
} // aBorderSolid::~aBorderSolid


/*******************************************************************************
* aBorderSolid::draw
*******************************************************************************/
void aBorderSolid::draw(aPainter            &_painter,
                        const aRect2D<s32>  &_boundingRect,
                        const aMargin       &_margin)
{
    // upper border
    _painter.drawFilledRect(_boundingRect.l(),
                            _boundingRect.t(),
                            _boundingRect.w(),
                            _margin.t(),
                            &m_color);

    // lower border
    _painter.drawFilledRect(_boundingRect.l(),
                            _boundingRect.b() - _margin.b(),
                            _boundingRect.w(),
                            _margin.b());

    // left border
    _painter.drawFilledRect(_boundingRect.l(),
                            _boundingRect.t() + _margin.t(),
                            _margin.l(),
                            _boundingRect.h() - _margin.h());

    // left border
    _painter.drawFilledRect(_boundingRect.r() - _margin.r(),
                            _boundingRect.t() + _margin.t(),
                            _margin.r(),
                            _boundingRect.h() - _margin.h());
} // aBorderSolid::draw


} // namespace aGraphic
} // namespace aLib
