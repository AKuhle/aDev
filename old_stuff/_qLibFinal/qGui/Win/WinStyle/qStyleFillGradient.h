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
#include "qStyleFillBase.h"
#include "qColor.h"


namespace qLib
{
    /*******************************************************************************
    * class qStyleFillGradient
    *******************************************************************************/
    class qStyleFillGradient : public qStyleFillBase
	{
        DeclareClassProperty(qColor, rgba, ColorStart)
        DeclareClassProperty(qColor, rgba, ColorEnd)

        public:
            qStyleFillGradient(const qColor &_colStart,
                               const qColor &_colEnd);
            virtual ~qStyleFillGradient();

            virtual void    Draw(qPainter           &_painter,
                                 const qRect2D<s32> &_boundingRect) override;

    }; // class qStyleFillGradient

} // namespace qLib
