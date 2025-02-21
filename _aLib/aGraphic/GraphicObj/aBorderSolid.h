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
#include "aGraphic/GraphicObj/aBorderObj.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aGraphic {


/*******************************************************************************
* class aBorderSolid
*******************************************************************************/
class aBorderSolid : public aBorderObj
{
    private:
        aColor          m_color;

    public:
        aBorderSolid(const aColor &_color);
        virtual ~aBorderSolid();

        virtual void    draw(aPainter           &_painter,
                             const aRect2D<s32> &_boundingRect,
                             const aMargin      &_margin) override;

}; // class aBorderSolid


} // namespace aGraphic
} // namespace aLib
