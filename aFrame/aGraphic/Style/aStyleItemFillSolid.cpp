/*******************************************************************************
* \file aStyleItemFillSolid.cpp
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

#include "aStyleItemFillSolid.h"
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
* aStyleItemFillSolid::aStyleItemFillSolid
*******************************************************************************/
aStyleItemFillSolid::aStyleItemFillSolid(const aColor   &_col)
: m_color(_col)
{
} // aStyleItemFillSolid::aStyleItemFillSolid


/*******************************************************************************
* aStyleItemFillSolid::~aStyleItemFillSolid
*******************************************************************************/
aStyleItemFillSolid::~aStyleItemFillSolid()
{
} // aStyleItemFillSolid::~aStyleItemFillSolid


/*******************************************************************************
* aStyleItemFillSolid::setColor
*******************************************************************************/
void aStyleItemFillSolid::setColor(const aColor   &_col)
{
    m_color = _col;
} // aStyleItemFillSolid::setColor


/*******************************************************************************
* aStyleItemFillSolid::color
*******************************************************************************/
const aColor& aStyleItemFillSolid::color() const
{
    return m_color;
} // aStyleItemFillSolid::color


/*******************************************************************************
* aStyleItemFillSolid::draw
*******************************************************************************/
void aStyleItemFillSolid::draw(aPainter       &_p,
                               const aRect    &_r)
{
    _p.drawFilledRect(_r, &m_color);
} // aStyleItemFillSolid::draw


} // namespace aWin
} // namespace aFrame
