/*******************************************************************************
* \file aLayoutCentralWin.cpp
* \author Andreas Kuhlewind
*
* \brief
*
*  Detailed description starts here.
*******************************************************************************/


/*******************************************************************************
* includes
*******************************************************************************/
#include "aLayoutCentralWin.h"
#include "aBaseWin.h"

using namespace aFrame::aUtil;


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aFrame {
namespace aWin {


/*******************************************************************************
* aLayoutCentralWin::aLayoutCentralWin
*******************************************************************************/
aLayoutCentralWin::aLayoutCentralWin()
{
} // aLayoutCentralWin::_isVisible


/*******************************************************************************
* aLayoutCentralWin::~aLayoutCentralWin
*******************************************************************************/
aLayoutCentralWin::~aLayoutCentralWin()
{
} // aLayoutCentralWin::~aLayoutCentralWin


/*******************************************************************************
* aLayoutCentralWin::arrange
*******************************************************************************/
void aLayoutCentralWin::arrange(const aRect &_r)
{
    if (m_pCentralWin)
    {
        m_pCentralWin->setGeometry(_r);
    }
} // aLayoutCentralWin::arrange


/*******************************************************************************
* aLayoutCentralWin::layoutMinDim
*******************************************************************************/
aDimension aLayoutCentralWin::layoutMinDim() const
{
    aDimension   dMin;

    if (m_pCentralWin)
    {
        dMin += m_pCentralWin->minDim();
    }

    return dMin;
} // aLayoutCentralWin::layoutMinDim


} // namespace aWin
} // namespace aFrame
