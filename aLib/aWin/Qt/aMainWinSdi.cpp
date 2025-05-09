/*******************************************************************************
* \file aMainWinSdi.cpp
* \author Andreas Kuhlewind
*
* \brief
*
*  Detailed description starts here.
*******************************************************************************/


/*******************************************************************************
* includes
*******************************************************************************/
#include "aMainWinSdi.h"
#include "aMdiArea.h"
#include "aMdiChild.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aWin {


/*******************************************************************************
* aMainWinSdi::aMainWinSdi
*******************************************************************************/
aMainWinSdi::aMainWinSdi(SysWin *_pParent /*= nullptr*/)
: aMainWin(_pParent)
{
} // aMainWinSdi::aMainWinSdi


/*******************************************************************************
* aMainWinSdi::~aMainWinSdi
*******************************************************************************/
aMainWinSdi::~aMainWinSdi()
{
} // aMainWinSdi::~aMainWinSdi


/*******************************************************************************
* aMainWinSdi::onSysCreateWin
*******************************************************************************/
bool aMainWinSdi::onSysCreateWin()
{
    return true;
} // aMainWinSdi::onSysCreateWin


} // namespace aWin
} // namespace aLib
