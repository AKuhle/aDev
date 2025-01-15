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
* aLayoutMainWin::calculateMinSize
*******************************************************************************/
aDimension2D<s32> aLayoutMainWin::calculateMinSize() const
{
    aDimension2D<s32>   d;

    // arrange the titlebar
    if (m_pTitleBar != nullptr)
    {
        d.h() += m_pTitleBar->minH();
    }

    return d;
} // aLayoutMainWin::calculateMinSize


/*******************************************************************************
* aLayoutMainWin::arrangeChilds
*******************************************************************************/
void aLayoutMainWin::arrangeChilds(aRect2D<s32>  _r2dLayout)
{
    // arrange the titlebar
    if (m_pTitleBar != nullptr)
    {
        m_pTitleBar->setGeometry(_r2dLayout.x(),
                                 _r2dLayout.y(),
                                 _r2dLayout.w(),
                                 m_pTitleBar->minH());

        _r2dLayout.y() += m_pTitleBar->minH();
        _r2dLayout.h() -= m_pTitleBar->minH();
    }
} // aLayoutMainWin::arrangeChilds


} // namespace aWin
} // namespace aLib
