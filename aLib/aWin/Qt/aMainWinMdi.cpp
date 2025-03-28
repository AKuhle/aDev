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
#include "aMdiChild.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aWin {


/*******************************************************************************
* aMainWinMdi::aMainWinMdi
*******************************************************************************/
aMainWinMdi::aMainWinMdi(SysWin *_pParent /*= nullptr*/)
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
    //return (aMdiArea *) (centralWin());
} // aMainWinMdi::mdiArea


/*******************************************************************************
* aMainWinMdi::addMdiChild
*******************************************************************************/
void aMainWinMdi::addMdiChild(aMdiChild *_pMdiChild)
{
    aMdiArea    *pMdiArea = mdiArea();
    CHECK_PRE_CONDITION_VOID(pMdiArea != nullptr);

    pMdiArea->addMdiChild(_pMdiChild);
    _pMdiChild->show();
} // aMainWinMdi::addMdiChild


/*******************************************************************************
* aMainWinMdi::onSysCreate
*******************************************************************************/
bool aMainWinMdi::onSysCreate()
{
    aMdiArea *pMdiArea = new aMdiArea();
    pMdiArea->create();

    setCentralWin(pMdiArea);

    return true;
} // aMainWinMdi::onSysCreate


} // namespace aWin
} // namespace aLib
