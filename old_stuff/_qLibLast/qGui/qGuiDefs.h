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
* includes
*******************************************************************************/
#include "qBaseDefs.h"

#ifdef _USE_QT_
    #include <QtWidgets/QtWidgets>

    using	SysWin_t    = QWidget;
#endif // _USE_QT_


namespace qLib
{
    /*******************************************************************************
    * object Id's
    *******************************************************************************/
    constexpr u32   ID_HORI_SCROLLBAR       = 1;
    constexpr u32   ID_VERT_SCROLLBAR       = 2;

    constexpr u32   ID_USER                 = 1000;


    /*******************************************************************************
    * mouse buttons
    *******************************************************************************/
    constexpr u16   MOUSE_BTN_NONE          = 0x0000;
    constexpr u16   MOUSE_BTN_LEFT          = 0x0001;
    constexpr u16   MOUSE_BTN_MIDDLE        = 0x0002;
    constexpr u16   MOUSE_BTN_RIGHT         = 0x0004;


    /*******************************************************************************
    * update commands
    *******************************************************************************/
    constexpr u64   UPDATE_SYS_BITS         = 0x000000000000ffff;
    constexpr u64   UPDATE_USER_BITS        = 0xffffffffffff0000;

    constexpr u64   UPDATE_GUI              = 0x0000000000000001;
    constexpr u64   UPDATE_VIEW             = 0x0000000000000002;
    constexpr u64   UPDATE_VIEWS_BY_DOC     = 0x0000000000000004;
    constexpr u64   UPDATE_ALL_VIEWS        = 0x0000000000000008;


    /*******************************************************************************
    * ToolBaseFunctions
    *******************************************************************************/
    constexpr u64   TBF_NONE                = 0x0000000000000000;
    constexpr u64   TBF_LXOR_RECT           = 0x0000000000000001;
    constexpr u64   TBF_USER                = 0xffffffffffff0000;


    /*******************************************************************************
    * dock areas
    *******************************************************************************/
    #define DOCK_AREA_NONE                  0x0000
    #define DOCK_AREA_LEFT                  0x0001
    #define DOCK_AREA_RIGHT                 0x0002
    #define DOCK_AREA_TOP                   0x0004
    #define DOCK_AREA_BOTTOM                0x0008
    #define DOCK_AREA_HORI                  0x000c  // top and bottom
    #define DOCK_AREA_VERT                  0x0003  // left and right
    #define DOCK_AREA_ALL                   0x000f  // top, bottom, left and right


    /*******************************************************************************
    * ctrl message
    *******************************************************************************/
    constexpr u32   MsgTriggered            = 1000;
    constexpr u32   MsgValueChanged         = 1001;
    constexpr u32   MsgSliderMoved          = 1002; // _s64Value contains the new position

    constexpr u32   MsgCurrentItemChanged   = 1010; // e.g. for qListCtrl
    constexpr u32   MsgCurrentRowChanged    = 1011; // e.g. for qListCtrl
    constexpr u32   MsgItemChanged          = 1012; // e.g. for qListCtrl
    constexpr u32   MsgItemClicked          = 1013; // e.g. for qListCtrl


    /*******************************************************************************
    * enums
    *******************************************************************************/
    enum class enumPenStyle
    {
        NoPen,
        SolidLine
        // DashLine,
        // DotLine,        // == TabFocus and ClickFocus
        // DashDotLine.
        // DashDotDotLine,
        // CustomDashLine
    }; // enumScrollBarPolicy

    // enum class enumFocusPolicy
    // {
    //     NoFocus,
    //     TabFocus,
    //     ClickFocus,
    //     StrongFocus,        // == TabFocus and ClickFocus
    //     WheelFocus
    // }; // enumScrollBarPolicy

    enum class enumScrollBarPolicy
    {
        AlwaysOff,
        AlwaysOn,
        AsNeeded
    }; // enum class enumCmdType

    enum class enumOrientation
    {
        Horizontal,
        Vertical
    }; // enumOrientation

    enum class enumToolResult
    {
        None,
        Handled,
        Unhandled,
        Done,
        Canceled
    }; // enumToolResult

    enum class enumCompositionMode
    {
        SourceOver,
        Xor
    }; // enumToolResult

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

} // namespace qLib
