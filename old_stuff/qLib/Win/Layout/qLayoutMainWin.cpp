/*******************************************************************************
* \file qLayoutMainWin.cpp
* \author Andreas Kuhlewind
*
* \brief
*
*  Detailed description starts here.
*******************************************************************************/


/*******************************************************************************
* includes
*******************************************************************************/
#include "Win/Layout/qLayoutMainWin.h"
#include "Win/FrameWin/qWin.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace qLib {
namespace Win {


/*******************************************************************************
* qLayoutMainWin::qLayoutMainWin
*******************************************************************************/
qLayoutMainWin::qLayoutMainWin()
{
} // qLayoutMainWin::qLayoutMainWin


/*******************************************************************************
* qLayoutMainWin::~qLayoutMainWin
*******************************************************************************/
qLayoutMainWin::~qLayoutMainWin()
{
} // qLayoutMainWin::~qLayoutMainWin


/*******************************************************************************
* qLayoutMainWin::setTitleBar
*******************************************************************************/
void qLayoutMainWin::setTitleBar(qWin *_pBar)
{
    m_pTitleBar = _pBar;
} // qLayoutMainWin::setTitleBar


/*******************************************************************************
* qLayoutMainWin::titleBar
*******************************************************************************/
qWin* qLayoutMainWin::titleBar() const
{
    return m_pTitleBar;;
} // qLayoutMainWin::titleBar


/*******************************************************************************
* qLayoutMainWin::adjustContentRect
*******************************************************************************/
void qLayoutMainWin::adjustContentRect(qRect2D<s32> &_r2d)
{
    // arrange the titlebar
    if (m_pTitleBar != nullptr)
    {
        _r2d.y() += m_pTitleBar->minH();
        _r2d.h() -= m_pTitleBar->minH();
    }
} // qLayoutMainWin::adjustContentRect


/*******************************************************************************
* qLayoutMainWin::arrangeChilds
*******************************************************************************/
void qLayoutMainWin::arrangeChilds(qRect2D<s32>  _r2d)
{
    // arrange the titlebar
    if (m_pTitleBar != nullptr)
    {
        m_pTitleBar->setGeometry(_r2d.x(),
                                 _r2d.y(),
                                 _r2d.w(),
                                 m_pTitleBar->minH());

        _r2d.y() += m_pTitleBar->minH();
        _r2d.h() -= m_pTitleBar->minH();
    }
} // qLayoutMainWin::arrangeChilds


} // namespace Win
} // namespace qLib
