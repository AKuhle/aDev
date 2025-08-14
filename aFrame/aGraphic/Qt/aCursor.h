/*******************************************************************************
* \file aCursor.h
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


/*******************************************************************************
* includes
*******************************************************************************/
#include <QCursor>

#include "aGraphic_def.h"
#include "aColor.h"
#include "aCursorI.h"

using namespace aFrame::aUtil;


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aFrame {
namespace aGraphic {


/*******************************************************************************
* class aCursor
*******************************************************************************/
class aCursor : private QCursor,
                public aCursorI
{
    public:
        aCursor(enumCursorShape _eShape);
        virtual ~aCursor();

        const QCursor&          toQCursor() const      { return *this; }

    private:
        static Qt::CursorShape  aCursor2QCursor(enumCursorShape _eShape);
}; // aCursor


} // namespace aGraphic
} // namespace aFrame

#endif // _USE_QT_
