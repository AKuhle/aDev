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
#include "qWinStyleFactory_dark.h"
#include "qWin.h"
#include "qStyleFillSolid.h"
#include "qStyleBorderSolid.h"

#include "qMainWin.h"
#include "qTitleBar.h"
#include "qStatusBar.h"
#include "qDockWin.h"
#include "qMdiWin.h"
#include "qMdiChild.h"
#include "qViewBase.h"

#include "qLabel.h"
#include "qScrollBar.h"
#include "qSpacer.h"
#include "qToolButton.h"

using namespace std;


namespace qLib
{
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
    * qWinStyleFactoryDark::SetDefaults
    *******************************************************************************/
    void qWinStyleFactoryDark::SetDefaults(qWin &_win) const
    {
        qColor   colActive(0x004a53);           // very dark between cyan and magenta
        qColor   colHover(0x00616d);            // dark between cyan and magenta
        qColor   colSelected(0x008b9b);         // bright between cyan and magenta

        // bg colors
        _win.SetBgDark1Color(colGrey5);
        _win.SetBgDark2Color(colGrey8);
        _win.SetBgDark3Color(colGrey11);

        // frame colors
        _win.SetFrameDark1Color(colGrey20);
        _win.SetFrameDark2Color(colGrey30);
        _win.SetFrameBright1Color(colGrey50);
        _win.SetFrameBright2Color(colGrey60);

        // window colors
        _win.SetWinColor(colGrey40);

        // state colors
        _win.SetNormalColor(colGrey55);
        _win.SetHoverColor(colHover);
        _win.SetSelectedColor(colSelected);
        _win.SetDisabledColor(colGrey30);
    } // qWinStyleFactoryDark::SetDefaults


    /*******************************************************************************
    * qWinStyleFactoryDark::SetWinStyle
    *******************************************************************************/
    void qWinStyleFactoryDark::SetWinStyle(qWin &_win)
    {
        // set the colors
        SetDefaults(_win);

        // set the default style (= qWin) and just do the changes for the paticular classes
        _win.SetContentFillStyle(make_unique<qStyleFillSolid> (_win.GetBgDark1Color()));

        _win.SetFont(qFont("Times New Roman", 12, enumFontWeight::Normal, false));

        // qMainWin
        if (dynamic_cast<qMainWin *> (&_win) != nullptr)
        {
            _win.GetMarginEdges().Set(5);
            _win.SetMarginFillStyle(make_unique<qStyleFillSolid> (colTransparent));

            _win.GetBorderEdges().Set(4);
            _win.SetBorderStyle(make_unique<qStyleBorderSolid> (_win.GetBgDark1Color()));
        }

        // qTitleBar
        else if (dynamic_cast<qTitleBar *> (&_win) != nullptr)
        {
            _win.SetMinSize(25, 25);
        }

        // qStatusBar
        else if (dynamic_cast<qStatusBar *> (&_win) != nullptr)
        {
            _win.SetMinSize(20, 20);
        }

        // qDockWin
        else if (dynamic_cast<qDockWin *> (&_win) != nullptr)
        {
            qDockWin *pDW = dynamic_cast<qDockWin *> (&_win);

            // bordersize, changed to l/r/t/b, depending on the docking state
            pDW->SetBorderSize(1);
            _win.SetBorderStyle(make_unique<qStyleBorderSolid> (_win.GetFrameDark1Color()));

            _win.SetMinSize(20, 20);
        }

        // qMdiWin
        else if (dynamic_cast<qMdiWin *> (&_win) != nullptr)
        {
            _win.SetContentFillStyle(make_unique<qStyleFillSolid> (_win.GetBgDark2Color()));
        }

        // qMdiChild
        else if (dynamic_cast<qMdiChild *> (&_win) != nullptr)
        {
            _win.GetMarginEdges().Set(5);
            _win.SetMarginFillStyle(make_unique<qStyleFillSolid> (colTransparent));

            _win.GetBorderEdges().Set(4);
            _win.SetBorderStyle(make_unique<qStyleBorderSolid> (_win.GetBgDark1Color()));

            _win.SetContentFillStyle(make_unique<qStyleFillSolid> (_win.GetBgDark3Color()));
        }

        // qViewBase
        else if (dynamic_cast<qViewBase *> (&_win) != nullptr)
        {
            _win.SetContentFillStyle(make_unique<qStyleFillSolid> (_win.GetBgDark3Color()));
        }

        // qLabel
        else if (dynamic_cast<qLabel *> (&_win) != nullptr)
        {
            _win.SetBorderStyle(make_unique<qStyleBorderSolid> (colYellowGreen));

            _win.SetMinSize(50, 24);
        }

        // qToolButton
        else if (dynamic_cast<qToolButton *> (&_win) != nullptr)
        {
            _win.SetFixedSize(24, 24);

            _win.SetContentFillStyle(make_unique<qStyleFillSolid> (_win.GetWinColor()));
        }

        // qSpacer
        else if (dynamic_cast<qSpacer *> (&_win) != nullptr)
        {
            _win.SetContentFillStyle(make_unique<qStyleFillSolid> (colTransparent));
        }

        // qScrollBar
        else if (dynamic_cast<qScrollBar *> (&_win) != nullptr)
        {
            _win.SetContentFillStyle(make_unique<qStyleFillSolid> (_win.GetBgDark2Color()));

            _win.GetBorderEdges().Set(1);
            _win.SetBorderStyle(make_unique<qStyleBorderSolid> (_win.GetFrameDark1Color()));

            _win.SetMinSize(14, 14);
        }


    } // qWinStyleFactoryDark::SetWinStyle

} // namespace qLib
