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
    * general constants
    *******************************************************************************/
    constexpr s32   WIN_SIZE_MAX            = 128000;


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
    constexpr u64   TBF_NONE                = 0x00000000;
    constexpr u64   TBF_LXOR_RECT           = 0x00000001;
    constexpr u64   TBF_USER                = 0xffffff00;


    /*******************************************************************************
    * Ctrl Id's
    *******************************************************************************/
    constexpr u32   SYS_ID_MINIMIZE         = 1;
    constexpr u32   SYS_ID_MAXIMIZE         = 2;
    constexpr u32   SYS_ID_CLOSE            = 3;
    constexpr u32   SYS_ID_SPACER           = 4;

    constexpr u32   ID_SCROLLBAR_HORI       = 5;
    constexpr u32   ID_SCROLLBAR_VERT       = 6;
    constexpr u32   ID_SCROLLBAR_LINE_DEC   = 7;
    constexpr u32   ID_SCROLLBAR_LINE_INC   = 8;

    constexpr u32   ID_USER                 = 10000;

    /*******************************************************************************
    * Ctrl-Messages
    *******************************************************************************/
    constexpr u32   MSG_CLICKED             = 0x00000001;
    constexpr u32   MSG_VALUE_CHANGED       = 0x00000002;


    /*******************************************************************************
    * Tool-Messages
    *******************************************************************************/
    constexpr u32   MSG_PAGE_DEC            = 0x00000001;   // page decrement
    constexpr u32   MSG_PAGE_INC            = 0x00000002;   // page increment
    constexpr u32   MSG_SLIDER_POS_MOVED    = 0x00000003;   // slider moved (during tracking) -> _s32Param1 = new position
    constexpr u32   MSG_SLIDER_POS_SET      = 0x00000004;   // set (not tracking) -> _s32Param1 = new position


    /*******************************************************************************
    * Tool Id's
    *******************************************************************************/
    constexpr u32   TOOL_ID_PARENT_CONTROL  = 1;
    constexpr u32   TOOL_ID_BORDER_RESIZE   = 2;
    constexpr u32   TOOL_ID_BUTTON          = 3;
    constexpr u32   TOOL_ID_SCROLL_BAR      = 4;
    constexpr u32   TOOL_ID_USER            = 1000;


    /*******************************************************************************
    * dock positions
    *******************************************************************************/
    constexpr u32   DOCK_POS_NONE           = 0x00000000;
    constexpr u32   DOCK_POS_L              = 0x00000001;   // left
    constexpr u32   DOCK_POS_R              = 0x00000002;   // right
    constexpr u32   DOCK_POS_T              = 0x00000004;   // top
    constexpr u32   DOCK_POS_B              = 0x00000008;   // bottom
    constexpr u32   DOCK_POS_FLOATING       = 0x00000010;

    constexpr u32   DOCK_POS_LR             = DOCK_POS_L + DOCK_POS_R;
    constexpr u32   DOCK_POS_TB             = DOCK_POS_T + DOCK_POS_B;
    constexpr u32   DOCK_POS_LRTB           = DOCK_POS_LR + DOCK_POS_TB;


    /*******************************************************************************
    * alignment
    *******************************************************************************/
    constexpr u16   AlignLeft       = 0x0001;
    constexpr u16   AlignRight      = 0x0002;
    constexpr u16   AlignHCenter    = 0x0004;
    //AlignJustify = 0x0008,
    //AlignAbsolute = 0x0010,

    constexpr u16   AlignTop        = 0x0010;
    constexpr u16   AlignBottom     = 0x0020;
    constexpr u16   AlignVCenter    = 0x0040;

    constexpr u16   AlignCenter     = AlignVCenter | AlignHCenter;


    /*******************************************************************************
    * enums
    *******************************************************************************/
    enum class enumCompositionMode
    {
        SourceOver,
        Xor
    }; // enumCompositionMode

    enum class enumToolResult
    {
        Handled,
        Unhandled,
        Success,
        Canceled
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

    enum class enumButtonStyle
    {
        MASKED_MODE,
        MASKED_ROUND_MODE
    }; // enumButtonStyle

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
    }; // enumButtonStyle

} // namespace qLib
