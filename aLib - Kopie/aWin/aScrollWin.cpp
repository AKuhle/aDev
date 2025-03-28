/*******************************************************************************
* \file aMainWin.cpp
* \author Andreas Kuhlewind
*
* \brief
*
*  Detailed description starts here.
*******************************************************************************/


/*******************************************************************************
* includes
*******************************************************************************/
#include "aScrollWin.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aWin {


/*******************************************************************************
* aScrollWin::aScrollWin
*******************************************************************************/
aScrollWin::aScrollWin(SysWinClass *_pParent /*= nullptr*/)
: aScrollWin_sys(_pParent)
{
} // aScrollWin::aScrollWin


/*******************************************************************************
* aScrollWin::~aScrollWin
*******************************************************************************/
aScrollWin::~aScrollWin()
{
} // aScrollWin::aScrollWin


/*******************************************************************************
* aScrollWin::setCentralWin
*******************************************************************************/
void aScrollWin::setCentralWin(SysWinClass *_pWin)
{
    aScrollWin_sys::setCentralWin(_pWin);
} // aScrollWin::setCentralWin


/*******************************************************************************
* aScrollWin::centralWin
*******************************************************************************/
SysWinClass* aScrollWin::centralWin()
{
    return aScrollWin_sys::centralWin();
} // aScrollWin::centralWin


/*******************************************************************************
* aScrollWin::setScrollBarPolicy
*******************************************************************************/
void aScrollWin::setScrollBarPolicy(ScrollBarPolicy _policy)
{
    aScrollWin_sys::setHoriScrollBarPolicy(_policy);
    aScrollWin_sys::setVertScrollBarPolicy(_policy);
} // aScrollWin::setScrollBarPolicy


/*******************************************************************************
* aScrollWin::setHoriScrollBarPolicy
*******************************************************************************/
void aScrollWin::setHoriScrollBarPolicy(ScrollBarPolicy _policy)
{
    aScrollWin_sys::setHoriScrollBarPolicy(_policy);
} // aScrollWin::setHoriScrollBarPolicy


/*******************************************************************************
* aScrollWin::setVertScrollBarPolicy
*******************************************************************************/
void aScrollWin::setVertScrollBarPolicy(ScrollBarPolicy _policy)
{
    aScrollWin_sys::setVertScrollBarPolicy(_policy);
} // aScrollWin::setVertScrollBarPolicy


} // namespace aWin
} // namespace aLib
