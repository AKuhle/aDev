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


enum class enumFontWeight
{
    Thin,
    ExtraLight,
    Light,
    Normal,
    Medium,
    DemiBold,
    Bold,
    ExtraBold,
    Black
}; // enumFontWeight


enum class enumAlignmentHori
{
    AlignLeft,
    AlignHCenter,
    AlignRight
}; // enumAlignmentHori


enum class enumAlignmentVert
{
    AlignTop,
    AlignVCenter,
    AlignBottom
}; // enumAlignmentVert


/*******************************************************************************
* classes
*******************************************************************************/
class aBrush;
class aPen;
class aPainter;

} // namespace aGraphic
} // namespace aLib
