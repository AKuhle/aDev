/*******************************************************************************
* \file aWinStyleFactoryDark.cpp
* \author Andreas Kuhlewind
*
* \brief
*
*  Detailed description starts here.
*******************************************************************************/


/*******************************************************************************
* includes
*******************************************************************************/
#include "aGraphic/aGraphic_def.h"

#include "aUtil/aColor.h"

#include "aGraphic/GraphicObj/aBorderSolid.h"
#include "aGraphic/GraphicObj/aFillSolid.h"

#include "aWin/Style/aWinStyleFactory_dark.h"

#include "aWin/Framework/aBaseWin.h"
#include "aWin/Framework/aScrollWin.h"
#include "aWin/Framework/aMainWin.h"
#include "aWin/Framework/aTitleBar.h"
#include "aWin/Framework/aStatusBar.h"
#include "aWin/Framework/aMdiWin.h"
#include "aWin/Framework/aMdiArea.h"
#include "aWin/Framework/aDockArea.h"

#include "aWin/Ctrl/aCtrl.h"
#include "aWin/Ctrl/aScrollBar.h"
#include "aWin/Ctrl/aButton.h"
#include "aWin/Ctrl/aProgressCtrl.h"
#include "aWin/Ctrl/aLabel.h"

using namespace aLib::aGraphic;
using namespace aLib::aUtil;


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aWin {


/*******************************************************************************
* aWinStyleFactoryDark::aWinStyleFactoryDark
*******************************************************************************/
aWinStyleFactoryDark::aWinStyleFactoryDark()
{
} // aWinStyleFactoryDark::aWinStyleFactoryDark


/*******************************************************************************
* aWinStyleFactoryDark::~aWinStyleFactoryDark
*******************************************************************************/
aWinStyleFactoryDark::~aWinStyleFactoryDark()
{
} // aWinStyleFactoryDark::~aWinStyleFactoryDark


/*******************************************************************************
* aWinStyleFactoryDark::setDefaults
*******************************************************************************/
void aWinStyleFactoryDark::setDefaults(aBaseWin &_win)
{
    // defaults colors
    _win.setBgColor(colBlack);
    _win.setActiveColor(aColor::fromU8(0, 35, 44));
    _win.setTextColor(colGrey90);

    // default objects
    _win.setContentObj(make_unique<aFillSolid> (_win.bgColor()));

    // default font
    _win.setFont(aFont("Arial", 8, enumFontWeight::Normal, false));
} // aWinStyleFactoryDark::setDefaults


/*******************************************************************************
* aWinStyleFactoryDark::setWinStyle
*******************************************************************************/
void aWinStyleFactoryDark::setWinStyle(aBaseWin &_win)
{
    aColor      colDark0(colGrey0);
    aColor      colDark1(colGrey8);
    aColor      colDark2(colGrey10);
    aColor      colDark3(colGrey15);

    aColor      colHover(aColor::fromU8(0, 148,148));
    aColor      colDisabled(colGrey25);
    aColor      colNormal(colGrey50);
    aColor      colSelected(colGrey70);

    setDefaults(_win);

    // aMainWin
    if (dynamic_cast<aMainWin *> (&_win) != nullptr)
    {
        // margin
        _win.margin().set(3);

        // border
        _win.border().set(5);
        _win.setBorderObj(make_unique<aBorderSolid> (colDark0));

        // content bg
        _win.setBgColor(colDark3);
        _win.setContentObj(make_unique<aFillSolid> (colDark3));
    }

    // aDockArea
    else if (dynamic_cast<aDockArea *> (&_win) != nullptr)
    {
        _win.setContentObj(make_unique<aFillSolid> (colDarkBlue));
        _win.setMinDim(40, 40);
    }

    // aMdiWin
    else if (dynamic_cast<aMdiWin *> (&_win) != nullptr)
    {
        // margin
        _win.margin().set(3);

        // active color for the progress fill
        _win.setActiveColor(aColor::fromU8(0, 35, 44));

        // border
        _win.border().set(4);
        _win.setBorderObj(make_unique<aBorderSolid> (colDark0));

        // content bg
        _win.setBgColor(colDark0);
        _win.setContentObj(make_unique<aFillSolid> (colDark0));
    }

    // aMdiArea
    else if (dynamic_cast<aMdiArea *> (&_win) != nullptr)
    {
        // content bg
        _win.setBgColor(colDark3);
        _win.setContentObj(make_unique<aFillSolid> (colDark3));
    }

    // aScrollWin
    else if (dynamic_cast<aScrollWin *> (&_win) != nullptr)
    {
        // content bg
        _win.setBgColor(colDark3);
        _win.setContentObj(make_unique<aFillSolid> (colDark3));
    }

    // aTitleBar
    else if (dynamic_cast<aTitleBar *> (&_win) != nullptr)
    {
        _win.border().set(0, 0, 0, 1);
        _win.setBorderObj(make_unique<aBorderSolid> (colDark0));

        // content bg
        _win.setBgColor(colDark0);
        _win.setContentObj(make_unique<aFillSolid> (colDark0));
    }

    // aStatusBar
    else if (dynamic_cast<aStatusBar *> (&_win) != nullptr)
    {
        // content bg
        _win.setBgColor(colDark0);
        _win.setContentObj(make_unique<aFillSolid> (colDark0));
    }

    // aCtrlBar
    else if (dynamic_cast<aCtrlBar *> (&_win) != nullptr)
    {
        // border
        _win.setBorderObj(make_unique<aBorderSolid> (colDark3));

        // content bg
        _win.setBgColor(colDark0);
        _win.setContentObj(make_unique<aFillSolid> (colDark0));
    }

    // aScrollBar
    else if (dynamic_cast<aScrollBar *> (&_win) != nullptr)
    {
        // border
        _win.border().set(1);
        _win.setBorderObj(make_unique<aBorderSolid> (colDark0));

        // content bg
        _win.setBgColor(colDark1);
        _win.setContentObj(make_unique<aFillSolid> (colDark1));
        _win.setMinDim(16, 16);
    }

    // aButton
    else if ((dynamic_cast<aButton *> (&_win)) != nullptr)
    {
        aButton *pBtn = dynamic_cast<aButton *> (&_win);

        pBtn->distance().set(1);                                       // set distance to 1
        pBtn->setFixedDim(27, 27);

        _win.setBgColor(colYellow);
        pBtn->setContentObj(make_unique<aFillSolid> (colYellow));      // content bg

        pBtn->setHoverColor(colHover);                                 // hover color
        pBtn->setDisabledColor(colDisabled);                           // disabled color
        pBtn->setNormalColor(colNormal);                               // normal color
        pBtn->setSelectedColor(colSelected);                           // selected color
    }

    // aLabel
    else if ((dynamic_cast<aLabel *> (&_win)) != nullptr)
    {
        _win.distance().set(1);                                       // set distance to 1

        _win.setBgColor(colDark2);
        _win.setContentObj(make_unique<aFillSolid> (colDark2));      // content bg
    }

    // aProgressCtrl
    else if ((dynamic_cast<aProgressCtrl *> (&_win)) != nullptr)
    {
        _win.distance().set(1);                                       // set distance to 1

        // active color for the progress fill
        _win.setActiveColor(colDarkBlue);

        _win.setBgColor(colDark2);
        _win.setContentObj(make_unique<aFillSolid> (colDark2));      // content bg
    }

    // aCtrl
    else if ((dynamic_cast<aCtrl *> (&_win)) != nullptr)
    {
        aCtrl *pCtrl = dynamic_cast<aCtrl *> (&_win);

        pCtrl->distance().set(1);                                       // set distance to 1

        _win.setBgColor(colYellow);
        pCtrl->setContentObj(make_unique<aFillSolid> (colYellow));      // content bg

        pCtrl->setHoverColor(colHover);                                 // hover color
        pCtrl->setDisabledColor(colDisabled);                           // disabled color
        pCtrl->setNormalColor(colNormal);                               // normal color
    }

    // aBaseWin
    else
    {
        // content bg
        _win.setBgColor(colDark0);
        _win.setContentObj(make_unique<aFillSolid> (colDark0));
    }

} // aWinStyleFactoryDark::setWinStyle


} // namespace aWin
} // namespace aLib
