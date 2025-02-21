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
#include "aWin/Framework/aStatusBar.h"


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

    addTopWin(_pBar);
} // aLayoutMainWin::setTitleBar


/*******************************************************************************
* aLayoutMainWin::titleBar
*******************************************************************************/
aTitleBar* aLayoutMainWin::titleBar() const
{
    return m_pTitleBar;;
} // aLayoutMainWin::titleBar


/*******************************************************************************
* aLayoutMainWin::setStatusBar
*******************************************************************************/
void aLayoutMainWin::setStatusBar(aStatusBar *_pBar)
{
    m_pStatusBar = _pBar;

    addBottomWin(_pBar);
} // aLayoutMainWin::setStatusBar


/*******************************************************************************
* aLayoutMainWin::statusBar
*******************************************************************************/
aStatusBar* aLayoutMainWin::statusBar() const
{
    return m_pStatusBar;;
} // aLayoutMainWin::statusBar


} // namespace aWin
} // namespace aLib
