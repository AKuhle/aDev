/*******************************************************************************
* \file aCursorQt.h
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

#include "aGraphic/aGraphic_def.h"
#include "aWin/aWin_def.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aGraphic {
namespace SysQt {



/*******************************************************************************
* class aCursorQt
*******************************************************************************/
class aCursorQt : private QCursor
{

    friend class aLib::aGraphic::SysQt::aPainterQt;
    friend class aLib::aWin::SysQt::aSysWinQt;

    public:
        aCursorQt(enumCursorShape _eCursorShape);
        virtual ~aCursorQt();

}; // class aCursorQt


} // namespace SysQt
} // namespace aGraphic
} // namespace aLib

#endif // _USE_QT_
