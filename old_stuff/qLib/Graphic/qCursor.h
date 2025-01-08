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

#include "Graphic/graphicDefs.h"
#include "Win/^winDefs.h"


namespace qLib {
namespace Graphic {


/*******************************************************************************
* forwards
*******************************************************************************/


/*******************************************************************************
* class qCursor
**************************************W*****************************************/
class qCursor : private QCursor
{
    friend class qSysWin;

    public:
        qCursor(enumCursorShape _eCursorShape);
        virtual ~qCursor();

}; // class qCursor


} // namespace Graphic
} // namespace qLib

#endif // _USE_QT_
