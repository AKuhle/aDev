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
#ifdef _USE_QT_


/*******************************************************************************
* includes
*******************************************************************************/
#include <QBrush>


namespace qLib
{
    /*******************************************************************************
    * forwards
    *******************************************************************************/
    class qRgba;


    /*******************************************************************************
    * class qBrush
    *******************************************************************************/
    class qBrush : private QBrush
	{
        friend class qPainter;

        public:
            qBrush(const qRgba  &_rgba);
            virtual ~qBrush();

            qRgba       Color() const;

    }; // class qBrush

} // namespace qLib

#endif // _USE_QT_