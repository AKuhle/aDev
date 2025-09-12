/*******************************************************************************
* \file BaseApp.h
* \author Andreas Kuhlewind
*
* \brief
*
* $Revision: 69 $
* $LastChangedDate: 2010-08-17 14:10:45 +0200 (Di, 17 Aug 2010) $
* $LastChangedBy: akuhlewi $
*
*  Detailed description starts here.
*******************************************************************************/


/*******************************************************************************
* includes
*******************************************************************************/
#include "photoLab_defs.h"
#include "mainWin.h"



/*******************************************************************************
* getMainWin
*******************************************************************************/
// MainWin& getMainWin()
// {
//     return *dynamic_cast<MainWin *> (get_aMainWin());
// } // getMainWin


/*******************************************************************************
* getStatusBar
*******************************************************************************/
// StatusBar& getStatusBar()
// {
//     return getMainWin().mwStatusBar();
// } // getStatusBar


/*******************************************************************************
* getActiveView
*******************************************************************************/
// ViewBase* getActiveView()
// {
//     MainWin     &mw = getMainWin();

//     aMdiChild   *pMdiChild = mw.activeMdiChild();
//     CHECK_PRE_CONDITION(pMdiChild != nullptr, nullptr);

//     // get the scroll window
//     EditScrollWin    *pScroll =  dynamic_cast<EditScrollWin *> (pMdiChild->centralWin());
//     CHECK_PRE_CONDITION(pScroll != nullptr, nullptr);

//     return dynamic_cast<ViewBase *> (pScroll->centralWin());
// } // getActiveView


// /*******************************************************************************
// * getActiveDoc
// *******************************************************************************/
// shared_ptr<Document> getActiveDoc()
// {
//     ViewBase    *pView = getActiveView();
//     CHECK_PRE_CONDITION(pView != nullptr, nullptr);

//     return dynamic_pointer_cast<Document> (pView->doc());
// } // getActiveDoc


// /*******************************************************************************
// * getActiveLS
// *******************************************************************************/
// shared_ptr<SynchronizedLS> getActiveLS()
// {
//     shared_ptr<Document>    pDoc = getActiveDoc();

//     return (pDoc != nullptr)?   pDoc->activeLS() : nullptr;
// } // getActiveLS


// /*******************************************************************************
// * getTopmostView
// *******************************************************************************/
// ViewBase* getTopmostView()
// {
//     MainWin     &mw = getMainWin();

//     aMdiChild   *pMdiChild = mw.topmostMdiChild();
//     CHECK_PRE_CONDITION(pMdiChild != nullptr, nullptr);

//     // get the scroll window
//     EditScrollWin    *pScroll =  dynamic_cast<EditScrollWin *> (pMdiChild->centralWin());
//     CHECK_PRE_CONDITION(pScroll != nullptr, nullptr);

//     return dynamic_cast<ViewBase *> (pScroll->centralWin());
// } // getTopmostView


// /*******************************************************************************
// * getTopmostDoc
// *******************************************************************************/
// shared_ptr<Document> getTopmostDoc()
// {
//     ViewBase    *pView = getTopmostView();
//     CHECK_PRE_CONDITION(pView != nullptr, nullptr);

//     return dynamic_pointer_cast<Document> (pView->doc());
// } // getTopmostDoc


// /*******************************************************************************
// * getTopmostLS
// *******************************************************************************/
// shared_ptr<SynchronizedLS> getTopmostLS()
// {
//     shared_ptr<Document>    pDoc = getTopmostDoc();

//     return (pDoc != nullptr)?   pDoc->activeLS() : nullptr;
// } // getTopmostLS


