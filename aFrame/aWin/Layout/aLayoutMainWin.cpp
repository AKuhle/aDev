/*******************************************************************************
* \file aLayoutMainWin.cpp
* \author Andreas Kuhlewind
*
* \brief
*
*  Detailed description starts here.
*******************************************************************************/


/*******************************************************************************
* includes
*******************************************************************************/
#include "aLayoutMainWin.h"
#include "aTitleBar.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aFrame {
namespace aWin {


/*******************************************************************************
* aLayoutMainWin::aLayoutMainWin
*******************************************************************************/
aLayoutMainWin::aLayoutMainWin()
{
} // aLayoutMainWin::aLayoutMainWin


/*******************************************************************************
* aLayoutMainWin::~aLayoutMainWin
*******************************************************************************/
aLayoutMainWin::~aLayoutMainWin()
{
} // aLayoutMainWin::~aLayoutMainWin


/*******************************************************************************
* aLayoutMainWin::setTitleBar
*******************************************************************************/
void aLayoutMainWin::setTitleBar(unique_ptr<aTitleBar>   _pTitleBar)
{
    m_pTitleBar = std::move(_pTitleBar);
} // aLayoutMainWin::setTitleBar


/*******************************************************************************
* aLayoutMainWin::titleBar
*******************************************************************************/
const aTitleBar* aLayoutMainWin::titleBar() const
{
    return m_pTitleBar.get();
} // aLayoutMainWin::titleBar


/*******************************************************************************
* aLayoutMainWin::titleBar
*******************************************************************************/
aTitleBar* aLayoutMainWin::titleBar()
{
    return m_pTitleBar.get();
} // aLayoutMainWin::titleBar


/*******************************************************************************
* aLayoutMainWin::layoutDemand
*******************************************************************************/
aDimension aLayoutMainWin::layoutDemand() const
{
    aDimension   dimMin = aLayoutCentralWin::layoutDemand();

    // add the minDim of the titlebar
    if (m_pTitleBar)
    {
        dimMin += layoutDemandOfChild(m_pTitleBar.get());
    }

    return dimMin;
} // aLayoutMainWin::layoutDemand


/*******************************************************************************
* aLayoutMainWin::arrange
*******************************************************************************/
void aLayoutMainWin::arrange(const aRect &_r)
{
    aRect r = _r;

    // set the titlebar
    if (m_pTitleBar)
    {
        aDimension dimTitle = layoutDemandOfChild(m_pTitleBar.get());

        m_pTitleBar->setGeometry(r.l(), r.t(), r.w(), dimTitle.h());
        r.y() += dimTitle.h();
        r.h() -= dimTitle.h();
    }

    // set the central win
    if (centralWin())
    {
        aDimension dimTitle = layoutDemandOfChild(m_pTitleBar.get());

        m_pTitleBar->setGeometry(r);
    }
} // aLayoutMainWin::arrange


} // namespace aWin
} // namespace aFrame
