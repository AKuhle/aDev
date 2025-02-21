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

            qFont(const qFont &_font);

            qFont(qString16         _sFamily,
                  s32               _s32PointSize   = 12,
                  enumFontWeight    _eWeight        = enumFontWeight::Normal,
                  bool              _bItalic        = false);

            virtual ~qFont();

            void            SetFont(const QFont &_font);

            qFont&          operator=(const qFont &_font);

            qString16       GetFamily() const;

            void            SetPointSize(s32 _s32PointSize);
            void            SetPixelSize(s32 _s32PixelSize);
            void            SetBold(bool _bBold);

            const QFont&    ToQFont() const;
            QFont&          ToQFont();
    }; // class qFont

} // namespace qLib
