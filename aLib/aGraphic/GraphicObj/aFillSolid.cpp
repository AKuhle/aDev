/*******************************************************************************
* \file aFillSolid.cpp
* \author Andreas Kuhlewind
*
* \brief
*
*  Detailed description starts here.
*******************************************************************************/


/*******************************************************************************
* includes
*******************************************************************************/
#include "aGraphic/GraphicObj/aFillSolid.h"
#include "aGraphic/aPainter.h"



/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aGraphic {


/*******************************************************************************
* aFillSolid::aFillSolid
*******************************************************************************/
aFillSolid::aFillSolid(const aColor &_color)
: m_color(_color)
{
} // aFillSolid::aFillSolid


/*******************************************************************************
* aFillSolid::~aFillSolid
*******************************************************************************/
aFillSolid::~aFillSolid()
{
} // aFillSolid::~aFillSolid


/*******************************************************************************
* aFillSolid::draw
*******************************************************************************/
void aFillSolid::draw(aPainter             &_painter,
                      const aRect2D<s32>   &_boundingRect)
{
    _painter.drawFilledRect(_boundingRect, &m_color);
} // aFillSolid::draw


} // namespace aGraphic
} // namespace aLib
