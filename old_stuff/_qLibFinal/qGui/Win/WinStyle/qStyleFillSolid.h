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
    * class qStyleFillSolid
    *******************************************************************************/
    class qStyleFillSolid : public qStyleFillBase
	{
        DeclareClassProperty(qColor, rgba, Color)

        public:
            qStyleFillSolid(const qColor &_color);
            virtual ~qStyleFillSolid();

            virtual void    Draw(qPainter           &_painter,
                                 const qRect2D<s32> &_boundingRect) override;

    }; // class qStyleFillSolid

} // namespace qLib
