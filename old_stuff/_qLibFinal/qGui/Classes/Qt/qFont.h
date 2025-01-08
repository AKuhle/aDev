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
#include "qGuiDefs.h"
#include "qString16.h"


namespace qLib
{
    /*******************************************************************************
    * forwards
    *******************************************************************************/


    /*******************************************************************************
    * class qFont
    *******************************************************************************/
    class qFont : private QFont
	{
        friend class qPainter;

        public:
            qFont();

            qFont(qString16         _sFamily,
                  s32               _s32PointSize,
                  enumFontWeight    _eWeight,
                  bool              _bItalic);

            virtual ~qFont();

            qFont&          operator=(const qFont &_font);

            void            SetPointSize(s32 _s32PointSize);
            void            SetBold(bool _bBold);

            const QFont&    ToQFont() const;
            QFont&          ToQFont();
    }; // class qFont

} // namespace qLib

#endif // _USE_QT_
