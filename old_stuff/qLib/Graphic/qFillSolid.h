/*******************************************************************************
* \file qFillSolid.h
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
#include "Graphic/qFillObj.h"
#include "Object/qColor.h"

using namespace qLib::Object;


/*******************************************************************************
* namespace
*******************************************************************************/
namespace qLib {
namespace Graphic {


/*******************************************************************************
* class qFillSolid
*******************************************************************************/
class qFillSolid : public qFillObj
{
    private:
        qColor          m_color;

    public:
        qFillSolid(const qColor &_color);
        virtual ~qFillSolid();

        virtual void    draw(qPainter           &_painter,
                             const qRect2D<s32> &_boundingRect) override;

}; // class qFillSolid


} // namespace Graphic
} // namespace qLib
