/*******************************************************************************
* \file qFillGradient.cpp
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
#include "Graphic/qFillGradient.h"
#include "Math/qRect2D.h"

using namespace qLib::Object;


/*******************************************************************************
* namespace
*******************************************************************************/
namespace qLib {
namespace Graphic {


/*******************************************************************************
* qFillGradient::qFillGradient
*******************************************************************************/
qFillGradient::qFillGradient(const qColor &_colorStart,
                             const qColor &_colorEnd)
: m_colorStart(_colorStart),
  m_colorEnd(_colorEnd)
{
} // qFillGradient::qFillGradient


/*******************************************************************************
* qFillGradient::~qFillGradient
*******************************************************************************/
qFillGradient::~qFillGradient()
{
} // qFillGradient::~qFillGradient


/*******************************************************************************
* qFillGradient::draw
*******************************************************************************/
void qFillGradient::draw(qPainter           &_painter,
                         const qRect2D<s32> &_boundingRect)
{
    _painter.drawGradientRect(_boundingRect,
                              _boundingRect.lb(), _boundingRect.lt(),
                              m_colorStart, m_colorEnd);
} // qFillGradient::draw



} // namespace Graphic
} // namespace qLib
