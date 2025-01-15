/*******************************************************************************
* \file qlBaseDefs.h
* \author Andreas Kuhlewind
*
* \brief
*
*  Detailed description starts here.
*******************************************************************************/
#pragma once


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aGraphic {


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
// FrameWin
#ifdef _USE_QT_
    namespace SysQt
    {
        class aCursorQt;
        class aPenQt;
        class aPainterQt;
    } // namespace SysQt

    using aCursor = aLib::aGraphic::SysQt::aCursorQt;
    using aPen = aLib::aGraphic::SysQt::aPenQt;
    using aPainter = aLib::aGraphic::SysQt::aPainterQt;

    class qGraphicObj;
    class aFillObj;
    class aFillSolid;

#endif // _USE_QT_


} // namespace aGraphic
} // namespace aLib
