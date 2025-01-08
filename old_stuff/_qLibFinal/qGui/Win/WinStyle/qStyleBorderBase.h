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
#include "qStyleItemBase.h"
#include "qColor.h"
#include "qBrush.h"
#include "qEdges.h"


namespace qLib
{
    /*******************************************************************************
    * class qStyleBorderBase
    *******************************************************************************/
    class qStyleBorderBase : public qStyleItemBase
	{
        public:
            qStyleBorderBase();

            virtual ~qStyleBorderBase();

            virtual void    Draw(qPainter           &_painter,
                                 const qRect2D<s32> &_boundingRect,
                                 const qEdges       &_edges) = 0;
    }; // class qStyleBorderBase

} // namespace qLib
