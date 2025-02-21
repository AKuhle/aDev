/*******************************************************************************
* \file qBorderSolid.cpp
* \author Andreas Kuhlewind
*
* \brief
*
*  Detailed description starts here.
*******************************************************************************/


/*******************************************************************************
* includes
*******************************************************************************/
#include "Graphic/graphicDefs.h"
#include "Graphic/qPainter.h"
#include "Math/qRect2D.h"
#include "Object/qMargin.h"

#include "qBorderSolid.h"

using namespace qLib::Object;


/*******************************************************************************
* namespace
*******************************************************************************/
namespace qLib {
namespace Graphic {


/*******************************************************************************
* qBorderSolid::qBorderSolid
*******************************************************************************/
qBorderSolid::qBorderSolid(const qColor &_color)
: m_color(_color)
{
} // qBorderSolid::qBorderSolid


/*******************************************************************************
* qBorderSolid::~qBorderSolid
*******************************************************************************/
qBorderSolid::~qBorderSolid()
{
} // qBorderSolid::~qBorderSolid


/*******************************************************************************
* qBorderSolid::draw
*******************************************************************************/
void qBorderSolid::draw(qPainter            &_painter,
                        const qRect2D<s32>  &_boundingRect,
                        const qMargin       &_margin)
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
} // qBorderSolid::draw


} // namespace Graphic
} // namespace qLib
