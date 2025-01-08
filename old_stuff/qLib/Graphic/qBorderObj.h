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
<<<<<<< HEAD
*  Detailed description starts here.
=======
* Detailed description starts here.
>>>>>>> 8a0ad4657bcd2902b9ab6539820b977a7c9d531e
*******************************************************************************/
#pragma once


/*******************************************************************************
* includes
*******************************************************************************/
#include "Object/objectDefs.h"
#include "Math/mathDefs.h"
#include "Graphic/graphicDefs.h"

#include "Graphic/qGraphicObj.h"

using namespace qLib::Object;
using namespace qLib::Math;


/*******************************************************************************
* namespace
*******************************************************************************/
namespace qLib {
namespace Graphic {


/*******************************************************************************
* class qBorderObj
*******************************************************************************/
class qBorderObj : public qGraphicObj
{
    public:
        qBorderObj();
        virtual ~qBorderObj();

        virtual void    draw(qPainter           &_painter,
                             const qRect2D<s32> &_boundingRect,
                             const qMargin      &_margin) = 0;
}; // class qBorderObj


} // namespace Graphic
} // namespace qLib
