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
EditScrollWin::EditScrollWin(SysWin *_pParent /*= nullptr*/)
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
* EditScrollWin::viewBase
*******************************************************************************/
ViewBase*  EditScrollWin::viewBase()
{
    return dynamic_cast<ViewBase *> (centralWin());
} // EditScrollWin::viewBase


/*******************************************************************************
* EditScrollWin::onCreateWin
*******************************************************************************/
bool EditScrollWin::onCreateWin()
{
    setScrollBarPolicy(ScrollBarPolicy::ScrollBarAlwaysOn);

    return true;
} // EditScrollWin::onCreateWin


/*******************************************************************************
* EditScrollWin::updateScrollBars
*******************************************************************************/
void EditScrollWin::updateScrollBars()
{
} // EditScrollWin::updateScrollBars


/*******************************************************************************
* EditScrollWin::onPaint
*******************************************************************************/
bool EditScrollWin::onPaint()
{
    ViewBase* pView = viewBase();
    CHECK_PRE_CONDITION(pView != nullptr, false);

    aPainter    p(pView);
    pView->doPaint(p);

    return true;
} // EditScrollWin::onPaint


/*******************************************************************************
* EditScrollWin::onWheel
*******************************************************************************/
bool EditScrollWin::onWheel(u32                  _u32Modifiers,
                            s32                  _s32Degree,
                            const aPoint2D<s32> &_v2dLocal,
                            const aPoint2D<s32> &_v2dGlobal)
{
    ViewBase* pView = viewBase();
    CHECK_PRE_CONDITION(pView != nullptr, false);

    return pView->doWheel(_u32Modifiers, _s32Degree, _v2dLocal, _v2dGlobal);
} // EditScrollWin::onWheel
