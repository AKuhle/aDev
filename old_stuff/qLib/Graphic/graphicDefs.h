/*******************************************************************************
* \file qPainterQt.h
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


namespace qLib {
namespace Graphic {


/*******************************************************************************
* enums
*******************************************************************************/
enum class enumCursorShape
{
    Arrow,
    Cross,
    Wait,
    IBeam,
    SizeVer,
    SizeHor,
    Size_TL_BR,
    Size_TR_BL,
    PointingHand,
    OpenHand,
    ClosedHand,
    Busy
}; // enumToolResult


/*******************************************************************************
* classes
*******************************************************************************/
namespace SysQt {
    class qPainterQt;
    class qPenQt;
} // namespace SysQt

#ifdef _USE_QT_
    using qPainter = qLib::Graphic::SysQt::qPainterQt;
    using qPen = qLib::Graphic::SysQt::qPenQt;
#endif // _USE_QT_

class qGraphicObj;

class qCursor;

class qBorderObj;
class qBorderSolid;

class qFillObj;
class qFillSolid;
// class qFillGradient;


} // namespace Graphic
} // namespace qLib
