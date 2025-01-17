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
#include "aUtil/aColor.h"

#include "aGraphic/GraphicObj/aBorderSolid.h"
#include "aGraphic/GraphicObj/aFillSolid.h"

#include "aWin/Style/aWinStyleFactory_dark.h"

#include "aWin/Framework/aBaseWin.h"
#include "aWin/Framework/aMainWin.h"
#include "aWin/Framework/aTitleBar.h"

#include "aWin/Ctrl/aCtrl.h"

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
* aWinStyleFactoryDark::setWinStyle
*******************************************************************************/
void aWinStyleFactoryDark::setWinStyle(aBaseWin &_win)
{
    aColor      colDark0(colGrey0);
    aColor      colDark1(colGrey15);

    aColor      colHover(colGrey25);
    aColor      colDisabled(colGrey30);
    aColor      colNormal(colGrey60);
    aColor      colSelected(colGrey90);

    // aMainWin
    if (dynamic_cast<aMainWin *> (&_win) != nullptr)
    {
        // margin
        _win.margin().set(3);

        // border
        _win.border().set(5);
        _win.setBorderObj(make_unique<aBorderSolid> (colDark0));

        // content bg
        _win.setContentObj(make_unique<aFillSolid> (colDark1));
    }

    // aTitleBar
    else if (dynamic_cast<aTitleBar *> (&_win) != nullptr)
    {
        // content bg
        _win.setContentObj(make_unique<aFillSolid> (colDark0));
    }

    // aCtrl
    else if ((dynamic_cast<aCtrl *> (&_win)) != nullptr)
    {
        aCtrl *pCtrl = dynamic_cast<aCtrl *> (&_win);

        pCtrl->distance().set(1);                                       // set distance to 1

        pCtrl->setContentObj(make_unique<aFillSolid> (colYellow));      // content bg

        pCtrl->setHoverColor(colHover);                                 // hover color
        pCtrl->setDisabledColor(colDisabled);                           // disabled color
        pCtrl->setNormalColor(colNormal);                               // normal color
        pCtrl->setSelectedColor(colSelected);                           // selected color
    }

    // aBaseWin
    else
    {
        // content bg
        _win.setContentObj(make_unique<aFillSolid> (colDarkRed));
    }

} // aWinStyleFactoryDark::setWinStyle


} // namespace aWin
} // namespace aLib
