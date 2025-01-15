/*******************************************************************************
* \file qFillBase.h
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
#include "aMath/aMath_def.h"
#include "aGraphic/aGraphic_def.h"

#include "aGraphic/GraphicObj/aGraphicObj.h"

using namespace aLib::aMath;


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aGraphic {


/*******************************************************************************
* class aFillObj
*******************************************************************************/
class aFillObj : public aGraphicObj
{
    public:
        aFillObj();
        virtual ~aFillObj();

        virtual void    draw(aPainter           &_painter,
                             const aRect2D<s32> &_boundingRect) = 0;    // e.g. for borders, == nullptr if not neccessary for e.g. solid fills
}; // class aFillObj


} // namespace aGraphic
} // namespace aLib
