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

namespace U = aFrame::aUtil;


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
* aLayoutMainWin::titleBar
*******************************************************************************/
void aLayoutMainWin::addToolBar(unique_ptr<aToolBar> _pToolBar)
{
    m_lstToolBar.push_back(std::move(_pToolBar));
} // aLayoutMainWin::titleBar


/*******************************************************************************
* aLayoutMainWin::arrange
*******************************************************************************/
void aLayoutMainWin::arrange(const aRect &_r)
{
    aRect       r = _r;
    aDimension  dim;


    // set the titlebar
    if (m_pTitleBar)
    {
        dim = m_pTitleBar->minDim();

        m_pTitleBar->setGeometry(r.l(), r.t(), r.w(), dim.h());
        r.y() += dim.h();
        r.h() -= dim.h();
    }

    // add the toolbars
    for (unique_ptr<aToolBar> &pToolBar : m_lstToolBar)
    {
        // upper toolbars
        if (pToolBar->dockPosition() == DOCK_POS_T)
        {
            dim = pToolBar->minDim();

            pToolBar->setGeometry(r.l(), r.t(), r.w(), dim.h());
            r.y() += dim.h();
            r.h() -= dim.h();
        }
        else if (pToolBar->dockPosition() == DOCK_POS_B)
        {

        }
        else if (pToolBar->dockPosition() == DOCK_POS_L)
        {

        }
        else if (pToolBar->dockPosition() == DOCK_POS_R)
        {

        }
    }

    // set the central win
    if (centralWin())
    {
        centralWin()->setGeometry(r);
    }
} // aLayoutMainWin::arrange


/*******************************************************************************
* aLayoutMainWin::layoutMinDim
*******************************************************************************/
aDimension aLayoutMainWin::layoutMinDim() const
{
    aDimension  dim;

    // min = minDim of central window
    aDimension  dimMin = aLayoutCentralWin::layoutMinDim();

    // add the minDim of the titlebar
    if (m_pTitleBar)
    {
        dim = m_pTitleBar->minDim();

        dimMin.h() += dim.h();
        dimMin.w() = U::max(dimMin.w(), dim.w());
    }

    return dimMin;
} // aLayoutMainWin::layoutMinDim


} // namespace aWin
} // namespace aFrame
