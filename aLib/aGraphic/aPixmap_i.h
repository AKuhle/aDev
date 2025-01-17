/*******************************************************************************
* \file qPixmap.h
* \author Andreas Kuhlewind
*
* \brief
*
* $Revision: 69 $
* $LastChangedDate: 2010-08-17 14:10:45 +0200 (Di, 17 Aug 2010) $
* $LastChangedBy: akuhlewi $
*
*  Detailed description starts here.
*******************************************************************************/
#pragma once


/*******************************************************************************
* includes
*******************************************************************************/
#include "aGraphic/aGraphic_def.h"
#include "aUtil/aUtil_def.h"
#include "aMath/aMath_def.h"
#include "aLib_def.h"

using namespace aLib::aUtil;
using namespace aLib::aMath;


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aGraphic {


/*******************************************************************************
* class qPixmap
*******************************************************************************/
class aPixmapI
{
        virtual aPixmap     scale(const aDimension2D<s32>  &_d) = 0;

        virtual void        fill(const aColor &_col) = 0;
}; // class qPixmap


} // namespace aGraphic
} // namespace aLib
