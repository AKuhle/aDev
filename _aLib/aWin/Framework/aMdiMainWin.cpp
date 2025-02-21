/*******************************************************************************
* \file aMdiMainWin.cpp
* \author Andreas Kuhlewind
*
* \brief
*
*  Detailed description starts here.
*******************************************************************************/


/*******************************************************************************
* includes
*******************************************************************************/
#include "aWin/Framework/aMdiMainWin.h"
#include "aWin/Framework/aTitleBar.h"
#include "aWin/Framework/aMdiArea.h"

#include "aWin/Layout/aLayoutMainWin.h"

#include "aWin/Tool/aBorderResizeTool.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aWin {


/*******************************************************************************
* aMdiMainWin::aMdiMainWin
*******************************************************************************/
aMdiMainWin::aMdiMainWin(aMdiMainWin  *_pParent  /* = nullptr */)
: aMainWin(_pParent)
{
} // aMdiMainWin::aMdiMainWin


/*******************************************************************************
* aMdiMainWin::~aMdiMainWin
*******************************************************************************/
aMdiMainWin::~aMdiMainWin()
{
} // aMdiMainWin::~aMdiMainWin


/*******************************************************************************
* aMdiMainWin::mdiArea
*******************************************************************************/
aMdiArea* aMdiMainWin::mdiArea() const
{
    return dynamic_cast<aMdiArea*> (centralWin());
} // aMdiMainWin::mdiArea


/*******************************************************************************
* aMdiMainWin::addMdiWin
*******************************************************************************/
void aMdiMainWin::addMdiWin(aMdiWin *_pMdiWin)
{
    CHECK_PRE_CONDITION_VOID(mdiArea() != nullptr);

    mdiArea()->addMdiWin(_pMdiWin);
} // aMdiMainWin::addMdiWin


/*******************************************************************************
* aMdiMainWin::activeMdiWin
*******************************************************************************/
aMdiWin* aMdiMainWin::activeMdiWin() const
{
    CHECK_PRE_CONDITION(mdiArea() != nullptr, nullptr);

    return mdiArea()->activeMdiWin();
} // aMdiMainWin::activeMdiWin


/*******************************************************************************
* aMdiMainWin::mdiWinList
*******************************************************************************/
const aPtrList<aMdiWin>* aMdiMainWin::mdiWinList() const
{
    CHECK_PRE_CONDITION(mdiArea() != nullptr, nullptr);

    return &mdiArea()->mdiWinList();
} // aMdiMainWin::mdiWinList


/*******************************************************************************
* aMdiMainWin::onSysCreate
*******************************************************************************/
bool aMdiMainWin::onSysCreate()
{
    // baseclass creates titlebar and dock areas
    // and the border resize tool
    aMainWin::onSysCreate();

    // set the MdiArea as central widget
    aMdiArea    *pMdiArea = new aMdiArea(this);
    pMdiArea->create();
    setCentralWin(pMdiArea);

    return true;
} // aMdiMainWin::onSysCreate


} // namespace aWin
} // namespace aLib
