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
#include "Graphic/qFillObj.h"
#include "Object/qColor.h"

using namespace qLib::Object;


/*******************************************************************************
* namespace
*******************************************************************************/
namespace qLib {
namespace Graphic {


/*******************************************************************************
* class qFillGradient
*******************************************************************************/
class qFillGradient : public qFillObj
{
    private:
        qColor          m_colorStart;
        qColor          m_colorEnd;

    public:
        qFillGradient(const qColor &_colorStart,
                      const qColor &_colorEnd);
        virtual ~qFillGradient();

        virtual void    draw(qPainter           &_painter,
                             const qRect2D<s32> &_boundingRect) override;

}; // class qFillGradient


} // namespace Graphic
} // namespace qLib
