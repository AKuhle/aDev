/*******************************************************************************
* \file aStyleItemBorderSolid.cpp
* \author Andreas Kuhlewind
*
* \brief
*
*  Detailed description starts here.
*******************************************************************************/


/*******************************************************************************
* includes
*******************************************************************************/
#include "aFrame_def.h"

#include "aStyleItemBorderSolid.h"
#include "aPath.h"
#include "aJsonFile.h"

#include "aPainter.h"

#include "aMainWin.h"

using namespace std;


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aFrame {
namespace aWin {


/*******************************************************************************
* aStyleItemBorderSolid::aStyleItemBorderSolid
*******************************************************************************/
aStyleItemBorderSolid::aStyleItemBorderSolid(const aMargin  &_margin,
                                             const aColor   &_col)
: aStyleItemBorder(_margin, _col)
{
} // aStyleItemBorderSolid::aStyleItemBorderSolid


/*******************************************************************************
* aStyleItemBorderSolid::~aStyleItemBorderSolid
*******************************************************************************/
aStyleItemBorderSolid::~aStyleItemBorderSolid()
{
} // aStyleItemBorderSolid::~aStyleItemBorderSolid


/*******************************************************************************
* aStyleItemBorderSolid::draw
*******************************************************************************/
void aStyleItemBorderSolid::draw(aPainter       &_p,
                                 const aRect    &_r)
{
    // left rect
    _p.drawFilledRect(aRect(_r.l(), _r.t(), margin().l(), _r.h()), &color());

    // right rect
    _p.drawFilledRect(aRect(_r.r() - margin().r() + 1, _r.t(), margin().r(), _r.h()), &color());

    // top rect
    _p.drawFilledRect(aRect(_r.l(), _r.t(), _r.w(), margin().t()), &color());

    // bottom rect
    _p.drawFilledRect(aRect(_r.l(), _r.b() - margin().b() + 1, _r.w(), margin().b()), &color());
} // aStyleItemBorderSolid::draw


} // namespace aWin
} // namespace aFrame
