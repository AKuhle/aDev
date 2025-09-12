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
* aLayoutCentralWin::layoutDemand
*******************************************************************************/
aDimension aLayoutCentralWin::layoutDemand() const
{
    aDimension   dMin;

    if (m_pCentralWin)
    {
        dMin += layoutDemandOfChild(m_pCentralWin);
    }

    return dMin;
} // aLayoutCentralWin::layoutDemand


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


} // namespace aWin
} // namespace aFrame
