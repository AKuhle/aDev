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
#include "aWin/Layout/aLayoutMainWin.h"
#include "aWin/Framework/aTitleBar.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
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
void aLayoutMainWin::setTitleBar(aTitleBar *_pBar)
{
    m_pTitleBar = _pBar;
} // aLayoutMainWin::setTitleBar


/*******************************************************************************
* aLayoutMainWin::titleBar
*******************************************************************************/
aTitleBar* aLayoutMainWin::titleBar() const
{
    return m_pTitleBar;;
} // aLayoutMainWin::titleBar


/*******************************************************************************
* aLayoutMainWin::shrinkContentSize
*******************************************************************************/
void aLayoutMainWin::shrinkContentSize(aRect2D<s32>  &_r2dContent) const
{
    // arrange the titlebar
    if (m_pTitleBar != nullptr)
    {
        _r2dContent.y() += m_pTitleBar->h();
        _r2dContent.h() -= m_pTitleBar->h();
    }
} // aLayoutMainWin::shrinkContentSize


/*******************************************************************************
* aLayoutMainWin::calculateMinDim
*******************************************************************************/
aDimension2D<s32> aLayoutMainWin::calculateMinDim() const
{
    aDimension2D<s32>   d;

    // arrange the titlebar
    if (m_pTitleBar != nullptr)
    {
        d.h() += m_pTitleBar->minDim().h();
    }

    return d;
} // aLayoutMainWin::calculateMinDim


/*******************************************************************************
* aLayoutMainWin::arrangeChilds
*******************************************************************************/
void aLayoutMainWin::arrangeChilds(aRect2D<s32>  _r2dLayout)
{
    // arrange the titlebar
    if (m_pTitleBar != nullptr)
    {
        aDimension2D<s32>   min = m_pTitleBar->minDim();

        m_pTitleBar->setGeometry(_r2dLayout.x(),
                                 _r2dLayout.y(),
                                 _r2dLayout.w(),
                                 min.h());

        _r2dLayout.y() += min.h();
        _r2dLayout.h() -= min.h();
    }
} // aLayoutMainWin::arrangeChilds


} // namespace aWin
} // namespace aLib
