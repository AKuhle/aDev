/*******************************************************************************
* \file qFillSolid.cpp
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
#include "qFillSolid.h"

using namespace qLib::Object;


/*******************************************************************************
* namespace
*******************************************************************************/
namespace qLib {
namespace Graphic {


/*******************************************************************************
* qFillSolid::qFillSolid
*******************************************************************************/
qFillSolid::qFillSolid(const qColor &_color)
: m_color(_color)
{
} // qFillSolid::qFillSolid


/*******************************************************************************
* qFillSolid::~qFillSolid
*******************************************************************************/
qFillSolid::~qFillSolid()
{
} // qFillSolid::~qFillSolid


/*******************************************************************************
* qFillSolid::draw
*******************************************************************************/
void qFillSolid::draw(qPainter             &_painter,
                      const qRect2D<s32>   &_boundingRect)
{
    _painter.drawFilledRect(_boundingRect, &m_color);
} // qFillSolid::draw


} // namespace Graphic
} // namespace qLib
