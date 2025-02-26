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
#include "aMdiWin.h"


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
* aMainWinMdi::mdiArea
*******************************************************************************/
aMdiArea* aMainWinMdi::mdiArea()
{
    return dynamic_cast<aMdiArea *> (centralWin());
} // aMainWinMdi::mdiArea


/*******************************************************************************
* aMainWinMdi::addMdiWin
*******************************************************************************/
void aMainWinMdi::addMdiWin(aMdiWin *_pMdiWin)
{
    aMdiArea    *pMdiArea = mdiArea();
    CHECK_PRE_CONDITION_VOID(pMdiArea != nullptr);

    pMdiArea->addMdiWin(_pMdiWin);
    _pMdiWin->show();
} // aMainWinMdi::addMdiWin


/*******************************************************************************
* aMainWinMdi::onSysCreate
*******************************************************************************/
bool aMainWinMdi::onSysCreate()
{
    aMdiArea *pMdiArea = new aMdiArea(this);

    setCentralWin(pMdiArea);

    return true;
} // aMainWinMdi::onSysCreate


} // namespace aWin
} // namespace aLib
