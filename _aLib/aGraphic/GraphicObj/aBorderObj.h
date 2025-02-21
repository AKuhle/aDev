/*******************************************************************************
* \file aBorderObj.h
* \author Andreas Kuhlewind
*
* \brief
*
* $Revision: 69 $
* $LastChangedDate: 2010-08-17 14:10:45 +0200 (Di, 17 Aug 2010) $
* $LastChangedBy: akuhlewi $
*
* Detailed description starts here.
*******************************************************************************/
#pragma once


/*******************************************************************************
* includes
*******************************************************************************/
#include "aLib_def.h"
#include "aUtil/aUtil_def.h"
#include "aMath/aMath_def.h"
#include "aGraphic/aGraphic_def.h"

#include "aGraphic/GraphicObj/aGraphicObj.h"

using namespace aLib::aUtil;
using namespace aLib::aMath;


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aGraphic {


/*******************************************************************************
* class aBorderObj
*******************************************************************************/
class aBorderObj : public aGraphicObj
{
    public:
        aBorderObj();
        virtual ~aBorderObj();

        virtual void    draw(aPainter           &_painter,
                             const aRect2D<s32> &_boundingRect,
                             const aMargin      &_margin) = 0;
}; // class aBorderObj


} // namespace aGraphic
} // namespace aLib
