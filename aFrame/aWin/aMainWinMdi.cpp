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
#include "aFrame_def.h"
#include "aWin_def.h"

#include "aMainWinMdi.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aFrame {
namespace aWin {


/*******************************************************************************
* aMainWinMdi::aMainWinMdi
*******************************************************************************/
aMainWinMdi::aMainWinMdi(aBaseWin *_pParent /*= nullptr*/)
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
* aMainWinMdi::onSysCreateWin
*******************************************************************************/
bool aMainWinMdi::onSysCreateWin()
{
    if (aMainWin::onSysCreateWin())
    {
        //     aMdiArea *pMdiArea = new aMdiArea();
        //     pMdiArea->createWin();

        //     setCentralWin(pMdiArea);
    }

    return true;
} // aMainWinMdi::onSysCreateWin


// /*******************************************************************************
// * aMainWinMdi::mdiArea
// *******************************************************************************/
// aMdiArea* aMainWinMdi::mdiArea()
// {
//     return dynamic_cast<aMdiArea *> (centralWin());
//     //return (aMdiArea *) (centralWin());
// } // aMainWinMdi::mdiArea


// /*******************************************************************************
// * aMainWinMdi::mdiArea
// *******************************************************************************/
// aMdiArea* aMainWinMdi::mdiArea() const
// {
//     return dynamic_cast<aMdiArea *> (centralWin());
//     //return (aMdiArea *) (centralWin());
// } // aMainWinMdi::mdiArea


// /*******************************************************************************
// * aMainWinMdi::addMdiChild
// *******************************************************************************/
// void aMainWinMdi::addMdiChild(aMdiChild *_pMdiChild)
// {
//     aMdiArea    *pMdiArea = mdiArea();
//     CHECK_PRE_CONDITION_VOID(pMdiArea != nullptr);

//     pMdiArea->addMdiChild(_pMdiChild);
//     _pMdiChild->show();
// } // aMainWinMdi::addMdiChild


// /*******************************************************************************
// * aMainWinMdi::mdiChildList
// *******************************************************************************/
// void aMainWinMdi::mdiChildList(aPtrList<aMdiChild> &_lstMdiChild) const
// {
//     aMdiArea    *pMdiArea = mdiArea();
//     CHECK_PRE_CONDITION_VOID(pMdiArea != nullptr);

//     pMdiArea->mdiChildList(_lstMdiChild);
// } // aMainWinMdi::mdiChildList


// /*******************************************************************************
// * aMainWinMdi::activeMdiChild
// *******************************************************************************/
// aMdiChild* aMainWinMdi::activeMdiChild() const
// {
//     aMdiArea    *pMdiArea = mdiArea();
//     CHECK_PRE_CONDITION(pMdiArea != nullptr, nullptr);

//     return pMdiArea->activeMdiChild();
// } // aMainWinMdi::activeMdiChild


// /*******************************************************************************
// * aMainWinMdi::topmostMdiChild
// *******************************************************************************/
// aMdiChild* aMainWinMdi::topmostMdiChild() const
// {
//     aMdiArea    *pMdiArea = mdiArea();
//     CHECK_PRE_CONDITION(pMdiArea != nullptr, nullptr);

//     return pMdiArea->topmostMdiChild();
// } // aMainWinMdi::topmostMdiChild


} // namespace aWin
} // namespace aFrame
