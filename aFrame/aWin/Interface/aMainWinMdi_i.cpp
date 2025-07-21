/*******************************************************************************
* \file aMainWinMdi_i.cpp
* \author Andreas Kuhlewind
*
* \brief
*
*  Detailed description starts here.
*******************************************************************************/


/*******************************************************************************
* includes
*******************************************************************************/
#include "aMainWinMdi_i.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aFrame {
namespace aWin {


/*******************************************************************************
* aMainWinMdi_i::aMainWinMdi_i
*******************************************************************************/
aMainWinMdi_i::aMainWinMdi_i(SysWin *_pParent /*= nullptr*/)
: aMainWin(_pParent)
{
} // aMainWinMdi_i::aMainWinMdi_i


/*******************************************************************************
* aMainWinMdi_i::~aMainWinMdi_i
*******************************************************************************/
aMainWinMdi_i::~aMainWinMdi_i()
{
} // aMainWinMdi_i::~aMainWinMdi_i


// /*******************************************************************************
// * aMainWinMdi_i::mdiArea
// *******************************************************************************/
// aMdiArea* aMainWinMdi_i::mdiArea()
// {
//     return dynamic_cast<aMdiArea *> (centralWin());
//     //return (aMdiArea *) (centralWin());
// } // aMainWinMdi_i::mdiArea


// /*******************************************************************************
// * aMainWinMdi_i::mdiArea
// *******************************************************************************/
// aMdiArea* aMainWinMdi_i::mdiArea() const
// {
//     return dynamic_cast<aMdiArea *> (centralWin());
//     //return (aMdiArea *) (centralWin());
// } // aMainWinMdi_i::mdiArea


// /*******************************************************************************
// * aMainWinMdi_i::addMdiChild
// *******************************************************************************/
// void aMainWinMdi_i::addMdiChild(aMdiChild *_pMdiChild)
// {
//     aMdiArea    *pMdiArea = mdiArea();
//     CHECK_PRE_CONDITION_VOID(pMdiArea != nullptr);

//     pMdiArea->addMdiChild(_pMdiChild);
//     _pMdiChild->show();
// } // aMainWinMdi_i::addMdiChild


// /*******************************************************************************
// * aMainWinMdi_i::mdiChildList
// *******************************************************************************/
// void aMainWinMdi_i::mdiChildList(aPtrList<aMdiChild> &_lstMdiChild) const
// {
//     aMdiArea    *pMdiArea = mdiArea();
//     CHECK_PRE_CONDITION_VOID(pMdiArea != nullptr);

//     pMdiArea->mdiChildList(_lstMdiChild);
// } // aMainWinMdi_i::mdiChildList


// /*******************************************************************************
// * aMainWinMdi_i::activeMdiChild
// *******************************************************************************/
// aMdiChild* aMainWinMdi_i::activeMdiChild() const
// {
//     aMdiArea    *pMdiArea = mdiArea();
//     CHECK_PRE_CONDITION(pMdiArea != nullptr, nullptr);

//     return pMdiArea->activeMdiChild();
// } // aMainWinMdi_i::activeMdiChild


// /*******************************************************************************
// * aMainWinMdi_i::topmostMdiChild
// *******************************************************************************/
// aMdiChild* aMainWinMdi_i::topmostMdiChild() const
// {
//     aMdiArea    *pMdiArea = mdiArea();
//     CHECK_PRE_CONDITION(pMdiArea != nullptr, nullptr);

//     return pMdiArea->topmostMdiChild();
// } // aMainWinMdi_i::topmostMdiChild


// /*******************************************************************************
// * aMainWinMdi_i::onSysCreateWin
// *******************************************************************************/
// bool aMainWinMdi_i::onSysCreateWin()
// {
//     aMdiArea *pMdiArea = new aMdiArea();
//     pMdiArea->createWin();

//     setCentralWin(pMdiArea);

//     return true;
// } // aMainWinMdi_i::onSysCreateWin


} // namespace aWin
} // namespace aFrame
