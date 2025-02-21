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
*  Detailed description starts here.
*******************************************************************************/
#pragma once


/*******************************************************************************
* includes
*******************************************************************************/
#include "Math/mathDefs.h"
#include "Object/objectDefs.h"

#include "Graphic/qBorderObj.h"
#include "Object/qColor.h"

using namespace qLib::Object;



namespace qLib {
namespace Graphic {


/*******************************************************************************
* class qBorderSolid
*******************************************************************************/
class qBorderSolid : public qBorderObj
{
    private:
        qColor          m_color;

    public:
        qBorderSolid(const qColor &_color);
        virtual ~qBorderSolid();

        virtual void    draw(qPainter           &_painter,
                             const qRect2D<s32> &_boundingRect,
                             const qMargin      &_margin) override;

}; // class qBorderSolid


} // namespace Graphic
} // namespace qLib
