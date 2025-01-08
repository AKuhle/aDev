/*******************************************************************************
* \file qPen.h
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
#ifdef _USE_QT_


/*******************************************************************************
* includes
*******************************************************************************/
#include <QPen>


namespace qLib
{
    /*******************************************************************************
    * forwards
    *******************************************************************************/
    class qColor;


    /*******************************************************************************
    * class qPen
    *******************************************************************************/
    class qPen : private QPen
	{
        friend class qPainter;

        public:
            qPen(const qColor &_col); // creates a solid pen with the width 1
            virtual ~qPen();

            qColor       GetColor() const;

    }; // class qPen

} // namespace qLib

#endif // _USE_QT_
