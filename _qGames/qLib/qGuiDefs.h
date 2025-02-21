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

#include <QtWidgets/QtWidgets>

using	SysWin_t    = QWidget;


namespace qLib
{
    /*******************************************************************************
    * ToolBaseFunctions
    *******************************************************************************/
    constexpr u64   TBF_NONE                = 0x00000000;
    constexpr u64   TBF_LXOR_RECT           = 0x00000001;
    constexpr u64   TBF_USER                = 0xffffff00;


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
