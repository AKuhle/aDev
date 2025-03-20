/*******************************************************************************
* \file aMdiArea.cpp
* \author Andreas Kuhlewind
*
* \brief
*
*  Detailed description starts here.
*******************************************************************************/


/*******************************************************************************
* includes
*******************************************************************************/
#include "aWin/Framework/aMdiArea.h"
#include "aWin/Framework/aTitleBar.h"
#include "aWin/Framework/aMdiWin.h"

#include "aWin/Layout/aLayoutMainWin.h"

#include "aWin/Tool/aBorderResizeTool.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aWin {


/*******************************************************************************
* aMdiArea::aMdiArea
*******************************************************************************/
aMdiArea::aMdiArea(aBaseWin  *_pParent  /* = nullptr */)
: aBaseWin(_pParent)
{
} // aMdiArea::aMdiArea


/*******************************************************************************
* aMdiArea::~aMdiArea
*******************************************************************************/
aMdiArea::~aMdiArea()
{
} // aMdiArea::aMdiArea


/*******************************************************************************
* aMdiArea::addMdChild
*******************************************************************************/
void aMdiArea::addMdChild(aMdiWin   *_pMdiWin)
{
    m_lstMdiWin.push_back(_pMdiWin);
    _pMdiWin->setParent(this);

    // bring the window to the top of the z-order
    _pMdiWin->setFocus();
} // aMdiArea::addMdChild


/*******************************************************************************
* aMdiArea::activeMdiWin
*******************************************************************************/
aMdiWin* aMdiArea::activeMdiWin() const
{
    CHECK_PRE_CONDITION(!m_lstMdiWin.empty(), nullptr);

    return m_lstMdiWin.front();
} // aMdiArea::activeMdiWin


/*******************************************************************************
* aMdiArea::mdiWinList
*******************************************************************************/
const aPtrList<aMdiWin>& aMdiArea::mdiWinList() const
{
    return m_lstMdiWin;
} // aMdiArea::mdiWinList


/*******************************************************************************
* aMdiArea::mdiChildRaised
*******************************************************************************/
void aMdiArea::mdiChildRaised(aMdiWin *_pMdiWin)
{
    m_lstMdiWin.moveToBegin(_pMdiWin);
} // aMdiArea::mdiChildRaised


} // namespace aWin
} // namespace aLib
