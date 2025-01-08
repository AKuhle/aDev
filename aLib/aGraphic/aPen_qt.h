/*******************************************************************************
* \file aPenQt.h
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

#include "aUtil/aUtil_def.h"
#include "aGraphic_def.h"

using namespace aLib::aUtil;


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aGraphic {
namespace SysQt {


/*******************************************************************************
* class aPenQt
*******************************************************************************/
class aPenQt : private QPen
{
    friend class aLib::aGraphic::SysQt::aPainterQt;

    public:
        aPenQt(const aColor &_color);      // creates a solid pen with the width 1
        virtual ~aPenQt();

        aColor       color() const;

}; // class aPenQt


} // namespace SysQt
} // namespace aGraphic
} // namespace aLib

#endif // _USE_QT_
