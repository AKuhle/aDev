/*******************************************************************************
* \file BaseApp.h
* \author Andreas Kuhlewind
*
* \brief
*
* $Revision: 69 $
* $LastChangedDate: 2010-08-17 14:10:45 +0200 (Di, 17 Aug 2010) $
* $LastChangedBy: akuhlewi $
*
*  Detailed description starts here.
*******************************************************************************/


/*******************************************************************************
* includes
*******************************************************************************/
#include "editScrollWin.h"
#include "viewBase.h"
#include "aPainter.h"

using namespace aLib::aWin;

/*******************************************************************************
* EditScrollWin::EditScrollWin
*******************************************************************************/
EditScrollWin::EditScrollWin(SysWinClass *_pParent /*= nullptr*/)
: aScrollWin(_pParent)
{
} // EditScrollWin::EditScrollWin


/*******************************************************************************
* EditScrollWin::~EditScrollWin
*******************************************************************************/
EditScrollWin::~EditScrollWin()
{
} // EditScrollWin::~EditScrollWin


/*******************************************************************************
* EditScrollWin::onCreate
*******************************************************************************/
bool EditScrollWin::onCreate()
{
    setScrollBarPolicy(ScrollBarPolicy::ScrollBarAlwaysOn);

    return true;
} // EditScrollWin::onCreate


/*******************************************************************************
* EditScrollWin::onPaint
*******************************************************************************/
bool EditScrollWin::onPaint()
{
    ViewBase *pView = win_cast<ViewBase *> (centralWin());
    CHECK_PRE_CONDITION(pView != nullptr, false);

    aPainter    p(pView);
    pView->doPaint(p);

    return true;
} // EditScrollWin::onPaint
