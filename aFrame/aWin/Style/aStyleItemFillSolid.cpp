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
: m_fillColor(_col)
{
} // aStyleItemFillSolid::aStyleItemFillSolid


/*******************************************************************************
* aStyleItemFillSolid::~aStyleItemFillSolid
*******************************************************************************/
aStyleItemFillSolid::~aStyleItemFillSolid()
{
} // aStyleItemFillSolid::~aStyleItemFillSolid


/*******************************************************************************
* aStyleItemFillSolid::setFillColor
*******************************************************************************/
void aStyleItemFillSolid::setFillColor(const aColor   &_col)
{
    m_fillColor = _col;
} // aStyleItemFillSolid::setFillColor


/*******************************************************************************
* aStyleItemFillSolid::fillColor
*******************************************************************************/
aColor aStyleItemFillSolid::fillColor() const
{
    return m_fillColor;
} // aStyleItemFillSolid::fillColor


} // namespace aWin
} // namespace aFrame
