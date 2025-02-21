/*******************************************************************************
* \file qCursor.h
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
#include <QCursor>

#include "qGuiDefs.h"


namespace qLib
{
    /*******************************************************************************
    * forwards
    *******************************************************************************/
    class qRgba;


    /*******************************************************************************
    * class qCursor
    *******************************************************************************/
    class qCursor : private QCursor
	{
        public:
            qCursor(enumCursorShape _eCursorShape);
            virtual ~qCursor();

            const QCursor&  ToQCursor() const;
            QCursor&        ToQCursor();

    }; // class qCursor

} // namespace qLib

#endif // _USE_QT_
