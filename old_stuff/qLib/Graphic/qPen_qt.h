/*******************************************************************************
* \file qPenQt.h
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

#include "Graphic/graphicDefs.h"

#include "Object/qColor.h"

using namespace qLib::Object;


namespace qLib {
namespace Graphic {
namespace SysQt {


/*******************************************************************************
* class qPenQt
*******************************************************************************/
class qPenQt : private QPen
{
    friend class qLib::Graphic::SysQt::qPainterQt;

    public:
        qPenQt(const qColor &_color);      // creates a solid pen with the width 1
        virtual ~qPenQt();

        qColor       color() const;

}; // class qPenQt


} // namespace SysQt
} // namespace Graphic
} // namespace qLib

#endif // _USE_QT_
