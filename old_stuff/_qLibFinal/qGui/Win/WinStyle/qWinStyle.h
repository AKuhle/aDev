/*******************************************************************************
* \file qWinStyle.h
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
#include "qEdges.h"
#include "qColor.h"
#include "qFont.h"
#include "qStyleFillBase.h"
#include "qStyleFillBase.h"
#include "qStyleBorderBase.h"


namespace qLib
{
    /*******************************************************************************
    * class qWinStyle
    *******************************************************************************/
    using namespace std;


    /*******************************************************************************
    * class qWinStyle
    *******************************************************************************/
    class qWinStyle
    {
        // Bg colors
        DeclareClassProperty(qColor, rgba, BgDark1Color)
        DeclareClassProperty(qColor, rgba, BgDark2Color)
        DeclareClassProperty(qColor, rgba, BgDark3Color)

        // window colors
        DeclareClassProperty(qColor, rgba, WinColor)
        DeclareClassProperty(qColor, rgba, ActiveColor)

        // frame colors
        DeclareClassProperty(qColor, rgba, FrameDark1Color)
        DeclareClassProperty(qColor, rgba, FrameDark2Color)
        DeclareClassProperty(qColor, rgba, FrameBright1Color)
        DeclareClassProperty(qColor, rgba, FrameBright2Color)

        // state colors
        DeclareClassProperty(qColor, rgba, NormalColor)
        DeclareClassProperty(qColor, rgba, HoverColor)
        DeclareClassProperty(qColor, rgba, SelectedColor)
        DeclareClassProperty(qColor, rgba, DisabledColor)

        // styles
        DeclareUniquePtrProperty(qStyleFillBase, p, MarginFillStyle)
        DeclareUniquePtrProperty(qStyleBorderBase, p, BorderStyle)
        DeclareUniquePtrProperty(qStyleFillBase, p, PaddingFillStyle)
        DeclareUniquePtrProperty(qStyleFillBase, p, ContentFillStyle)

        // window fonts
        DeclareClassProperty(qFont, fnt, Font)

        public:
            qWinStyle();
            ~qWinStyle();

    }; // class qWinStyle

} // namespace aLib
