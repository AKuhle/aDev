/*******************************************************************************
* \file qFont.h
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
#include <QFont>
#include "qLibDefs.h"


namespace qLib
{
    /*******************************************************************************
    * forwards
    *******************************************************************************/
    class qRgba;


    /*******************************************************************************
    * class qFont
    *******************************************************************************/
    class qFont : private QFont
	{
        friend class qPainter;

        public:
            qFont();
            virtual ~qFont();

            void            SetPointSize(s32 _s32PointSize);
            void            SetBold(bool _bBold);

            const QFont&    ToQFont() const;
            QFont&          ToQFont();
    }; // class qFont

} // namespace qLib

#endif // _USE_QT_
