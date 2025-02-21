/*******************************************************************************
* \file qWinStyleFactoryDark.cpp
* \author Andreas Kuhlewind
*
* \brief
*
*  Detailed description starts here.
*******************************************************************************/


/*******************************************************************************
* includes
*******************************************************************************/
#include "Object/qColor.h"

#include "Graphic/qBorderSolid.h"
#include "Graphic/qFillSolid.h"

#include "Win/FrameWin/qMainWin.h"
#include "Win/FrameWin/qTitleBar.h"
#include "Win/WinStyle/qWinStyleFactory_dark.h"

using namespace qLib::Object;


/*******************************************************************************
* namespace
*******************************************************************************/
namespace qLib {
namespace Win {


/*******************************************************************************
* qWinStyleFactoryDarkDark::qWinStyleFactoryDark
*******************************************************************************/
qWinStyleFactoryDark::qWinStyleFactoryDark()
{
} // qWinStyleFactoryDark::qWinStyleFactoryDark


/*******************************************************************************
* qWinStyleFactoryDark::~qWinStyleFactoryDark
*******************************************************************************/
qWinStyleFactoryDark::~qWinStyleFactoryDark()
{
} // qWinStyleFactoryDark::~qWinStyleFactoryDark


/*******************************************************************************
* qWinStyleFactoryDark::setWinStyle
*******************************************************************************/
void qWinStyleFactoryDark::setWinStyle(qWin &_win)
{
    qColor      colDark0(colGrey0);
    qColor      colDark1(colGrey10);

    // qMainWin
    if (dynamic_cast<qMainWin *> (&_win) != nullptr)
    {
        // invisible margin (if not maximize) for better frame grabbing
        _win.margin().set(5, 5, 5, 5);

        // border (within the margin
        _win.border().set(4);
        _win.setBorderObj(make_unique<qBorderSolid> (colDark0));

        // content bg
        _win.setContentObj(make_unique<qFillSolid> (colDark1));
    }

    // qTitleBar
    else if (dynamic_cast<qTitleBar *> (&_win) != nullptr)
    {
        // content bg
        _win.setContentObj(make_unique<qFillSolid> (colDark0));
    }

    // qWin
    else
    {
        _win.setContentObj(make_unique<qFillSolid> (colDarkRed));
    }

    //     qColor   colActive(0x004a53);           // very dark between cyan and magenta
    //     qColor   colHover(0x00616d);            // dark between cyan and magenta
    //     qColor   colSelected(0x008b9b);         // bright between cyan and magenta
    //qColor      colDark0(colDarkGoldenRod);

    //setColorBg1(colDark0);

    // // set the default style (= qWin) and just do the changes for the paticular classes
    // _win.SetContentFillStyle(make_unique<qStyleFillSolid> (_win.GetBgDark1Color()));

    // _win.SetFont(qFont("Times New Roman", 12, enumFontWeight::Normal, false));

    // // qMainWin
    // if (dynamic_cast<qMainWin *> (&_win) != nullptr)
    // {
    //     _win.GetMarginEdges().Set(5);
    //     _win.SetMarginFillStyle(make_unique<qStyleFillSolid> (colTransparent));

    //     _win.GetBorderEdges().Set(4);
    //     _win.SetBorderStyle(make_unique<qStyleBorderSolid> (_win.GetBgDark1Color()));
    // }

    // // qTitleBar
    // else if (dynamic_cast<qTitleBar *> (&_win) != nullptr)
    // {
    //     _win.SetMinSize(25, 25);
    // }

    // // qStatusBar
    // else if (dynamic_cast<qStatusBar *> (&_win) != nullptr)
    // {
    //     _win.SetMinSize(20, 20);
    // }

    // // qDockWin
    // else if (dynamic_cast<qDockWin *> (&_win) != nullptr)
    // {
    //     qDockWin *pDW = dynamic_cast<qDockWin *> (&_win);

    //     // bordersize, changed to l/r/t/b, depending on the docking state
    //     pDW->SetBorderSize(1);
    //     _win.SetBorderStyle(make_unique<qStyleBorderSolid> (_win.GetFrameDark1Color()));

    //     _win.SetMinSize(20, 20);
    // }

    // // qMdiChild
    // else if (dynamic_cast<qMdiChild *> (&_win) != nullptr)
    // {
    //     _win.GetMarginEdges().Set(5);
    //     _win.SetMarginFillStyle(make_unique<qStyleFillSolid> (colTransparent));

    //     _win.GetBorderEdges().Set(4);
    //     _win.SetBorderStyle(make_unique<qStyleBorderSolid> (_win.GetBgDark1Color()));

    //     _win.SetContentFillStyle(make_unique<qStyleFillSolid> (_win.GetBgDark3Color()));
    // }

    // // qViewBase
    // else if (dynamic_cast<qViewBase *> (&_win) != nullptr)
    // {
    //     _win.SetContentFillStyle(make_unique<qStyleFillSolid> (_win.GetBgDark3Color()));
    // }

    // // qLabel
    // else if (dynamic_cast<qLabel *> (&_win) != nullptr)
    // {
    //     _win.SetBorderStyle(make_unique<qStyleBorderSolid> (colYellowGreen));

    //     _win.SetMinSize(50, 24);
    // }

    // // qToolButton
    // else if (dynamic_cast<qToolButton *> (&_win) != nullptr)
    // {
    //     _win.SetFixedSize(24, 24);

    //     _win.SetContentFillStyle(make_unique<qStyleFillSolid> (_win.GetWinColor()));
    // }

    // // qSpacer
    // else if (dynamic_cast<qSpacer *> (&_win) != nullptr)
    // {
    //     _win.SetContentFillStyle(make_unique<qStyleFillSolid> (colTransparent));
    // }

    // // qScrollBar
    // else if (dynamic_cast<qScrollBar *> (&_win) != nullptr)
    // {
    //     _win.SetContentFillStyle(make_unique<qStyleFillSolid> (_win.GetBgDark2Color()));

    //     _win.GetBorderEdges().Set(1);
    //     _win.SetBorderStyle(make_unique<qStyleBorderSolid> (_win.GetFrameDark1Color()));

    //     _win.SetMinSize(14, 14);
    // }

} // qWinStyleFactoryDark::setWinStyle


} // namespace Win
} // namespace qLib
