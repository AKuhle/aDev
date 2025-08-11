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
* aLayoutMainWin::arrange
*******************************************************************************/
void aLayoutMainWin::arrange(const aRect &_r)
{
    aRect r = _r;

    if (m_pTitleBar)
    {
        m_pTitleBar->setGeometry(r.l(), r.t(), r.w(), m_pTitleBar->sysMetrics().h());
    }
} // aLayoutMainWin::arrange


} // namespace aWin
} // namespace aFrame
