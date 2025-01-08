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


namespace qLib
{
    /*******************************************************************************
    * forwards
    *******************************************************************************/


    /*******************************************************************************
    * class qStyleFillBase
    *******************************************************************************/
    class qStyleFillBase : public qStyleItemBase
	{
        public:
            qStyleFillBase();
            virtual ~qStyleFillBase();

            virtual void    Draw(qPainter           &_painter,
                                 const qRect2D<s32> &_boundingRect) = 0;    // e.g. for borders, == nullptr if not neccessary for e.g. solid fills
    }; // class qStyleFillBase

} // namespace qLib
