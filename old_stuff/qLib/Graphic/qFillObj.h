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
#include "Math/mathDefs.h"
#include "Graphic/graphicDefs.h"

#include "Graphic/qGraphicObj.h"

using namespace qLib::Math;


/*******************************************************************************
* namespace
*******************************************************************************/
namespace qLib {
namespace Graphic {


/*******************************************************************************
* class qFillObj
*******************************************************************************/
class qFillObj : public qGraphicObj
{
    public:
        qFillObj();
        virtual ~qFillObj();

        virtual void    draw(qPainter           &_painter,
                             const qRect2D<s32> &_boundingRect) = 0;    // e.g. for borders, == nullptr if not neccessary for e.g. solid fills
}; // class qFillObj


} // namespace Graphic
} // namespace qLib
