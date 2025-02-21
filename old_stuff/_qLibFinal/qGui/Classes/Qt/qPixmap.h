/*******************************************************************************
* \file qPixmap.h
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
#include <QPixmap>

#include "qGuiDefs.h"
#include "qDimension2D.h"


namespace qLib
{
    /*******************************************************************************
    * forwards
    *******************************************************************************/
    class qColor;
    class qPixmap;


    /*******************************************************************************
    * class qPixmap
    *******************************************************************************/
    class qPixmap : private QPixmap
	{
        friend class qPainter;

        public:
            qPixmap(const qString16 &_rscName);
            qPixmap(const char *_rscName);

            virtual ~qPixmap();

            qPixmap             Scale(const qDimension2D<s32>  &_d);

            void                Fill(const qColor &_col);

        private:
            qPixmap(const QPixmap &_pixmap);
    }; // class qPixmap

} // namespace qLib

#endif // _USE_QT_
