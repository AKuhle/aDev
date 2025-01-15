/*******************************************************************************
* \file aFillSolid.h
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

#include "aGraphic/GraphicObj/aFillObj.h"
#include "aUtil/aColor.h"

using namespace aLib::aUtil;


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aGraphic {


/*******************************************************************************
* class aFillSolid
*******************************************************************************/
class aFillSolid : public aFillObj
{
    private:
        aColor          m_color;

    public:
        aFillSolid(const aColor &_color);
        virtual ~aFillSolid();

        virtual void    draw(aPainter           &_painter,
                             const aRect2D<s32> &_boundingRect) override;

}; // class aFillSolid


} // namespace aGraphic
} // namespace aLib
