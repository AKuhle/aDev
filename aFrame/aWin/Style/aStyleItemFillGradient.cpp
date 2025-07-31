/*******************************************************************************
* \file aStyleItemFillGradient.cpp
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

#include "aStyleItemFillGradient.h"
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
* aStyleItemFillGradient::aStyleItemFillGradient
*******************************************************************************/
aStyleItemFillGradient::aStyleItemFillGradient(const aColor  &_col1,
                                               const aColor &_col2,
                                               s32          _s32Angle)
: m_fillColor1(_col1),
  m_fillColor2(_col2),
  m_s32Angle(_s32Angle)
{
} // aStyleItemFillGradient::aStyleItemFillGradient


/*******************************************************************************
* aStyleItemFillGradient::~aStyleItemFillGradient
*******************************************************************************/
aStyleItemFillGradient::~aStyleItemFillGradient()
{
} // aStyleItemFillGradient::~aStyleItemFillGradient


/*******************************************************************************
* aStyleItemFillGradient::setFillColor
*******************************************************************************/
void aStyleItemFillGradient::setFillColor(const aColor   &_col1,
                                          const aColor   &_col2)
{
    m_fillColor1 = _col1;
    m_fillColor2 = _col2;
} // aStyleItemFillGradient::setFillColor


/*******************************************************************************
* aStyleItemFillGradient::fillColor1
*******************************************************************************/
aColor aStyleItemFillGradient::fillColor1() const
{
    return m_fillColor1;
} // aStyleItemFillGradient::fillColor1


/*******************************************************************************
* aStyleItemFillGradient::fillColor2
*******************************************************************************/
aColor aStyleItemFillGradient::fillColor2() const
{
    return m_fillColor2;
} // aStyleItemFillGradient::fillColor2


/*******************************************************************************
* aStyleItemFillGradient::angle
*******************************************************************************/
s32 aStyleItemFillGradient::angle() const
{
    return m_s32Angle;
} // aStyleItemFillGradient::angle


} // namespace aWin
} // namespace aFrame
