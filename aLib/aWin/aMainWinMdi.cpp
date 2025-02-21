/*******************************************************************************
* \file aMainWinMdi.cpp
* \author Andreas Kuhlewind
*
* \brief
*
*  Detailed description starts here.
*******************************************************************************/


/*******************************************************************************
* includes
*******************************************************************************/
#include "aMainWinMdi.h"
#include "aMdiArea.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aWin {


/*******************************************************************************
* aMainWinMdi::aMainWinMdi
*******************************************************************************/
aMainWinMdi::aMainWinMdi(SysWinClass *_pParent /*= nullptr*/)
: aMainWin(_pParent)
{
} // aMainWinMdi::aMainWinMdi


/*******************************************************************************
* aMainWinMdi::~aMainWinMdi
*******************************************************************************/
aMainWinMdi::~aMainWinMdi()
{
} // aMainWinMdi::~aMainWinMdi


/*******************************************************************************
* aMainWinMdi::onSysCreate
*******************************************************************************/
bool aMainWinMdi::onSysCreate()
{
    // QWidget *pW = sysWinClass();

    // QWidget *pMdiArea = new aMdiArea(pW);

    // setCentralWin(pMdiArea);

    return true;
} // aMainWinMdi::onSysCreate


} // namespace aWin
} // namespace aLib
