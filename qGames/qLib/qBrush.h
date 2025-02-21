/*******************************************************************************
* \file qBrush.h
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
#include "qGuiDefs.h"
#include <QBrush>


namespace qLib
{
    /*******************************************************************************
    * forwards
    *******************************************************************************/
    class qColor;


    /*******************************************************************************
    * class qBrush
    *******************************************************************************/
    class qBrush : private QBrush
	{
        friend class qPainter;

        public:
            qBrush(const qColor  &_col);

            qBrush(Rgba_t   _r,
                   Rgba_t   _g,
                   Rgba_t   _b,
                   Rgba_t   _a = 1);

            virtual ~qBrush();

            qColor               GetColor() const;
    }; // class qBrush

} // namespace qLib
