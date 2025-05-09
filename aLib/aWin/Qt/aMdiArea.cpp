/*******************************************************************************
* \file aMdiArea.cpp
* \author Andreas Kuhlewind
*
* \brief
*
*  Detailed description starts here.
*******************************************************************************/
#ifdef _USE_QT_


/*******************************************************************************
* includes
*******************************************************************************/
#include "aMdiArea.h"
#include "aMdiChild.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aWin {


/*******************************************************************************
* aMdiArea::aMdiArea
*******************************************************************************/
aMdiArea::aMdiArea(SysWin *_pParent)
: aBaseWin<QMdiArea>(_pParent)
{
} // aMdiArea::_isVisible


/*******************************************************************************
* aMdiArea::~aMdiArea
*******************************************************************************/
aMdiArea::~aMdiArea()
{
} // aMdiArea::~aMdiArea


/*******************************************************************************
* aMdiArea::addMdiChild
*******************************************************************************/
void aMdiArea::addMdiChild(aMdiChild *_pMdiChild)
{
    addSubWindow(_pMdiChild);
} // aMdiArea::addMdiChild


/*******************************************************************************
* aMdiArea::mdiChildList
*******************************************************************************/
void aMdiArea::mdiChildList(aPtrList<aMdiChild> &_lstMdiChild) const
{
    QList<QMdiSubWindow *>	lstSubWins 	= subWindowList();

    for (QMdiSubWindow *pMdiSubWin : lstSubWins)
    {
        aMdiChild *pChild = dynamic_cast<aMdiChild *> (pMdiSubWin);

        if (pChild != nullptr)
        {
            _lstMdiChild.push_back(pChild);
        }
    } // for ...
} // aMdiArea::mdiChildList


/*******************************************************************************
* aMdiArea::activeMdiChild
*******************************************************************************/
aMdiChild* aMdiArea::activeMdiChild() const
{
    return dynamic_cast<aMdiChild *> (activeSubWindow());
} // aMdiArea::activeMdiChild


/*******************************************************************************
* aMdiArea::topmostMdiChild
*******************************************************************************/
aMdiChild* aMdiArea::topmostMdiChild() const
{
    QList<QMdiSubWindow *>	lstSubWins 	= subWindowList(QMdiArea::StackingOrder);

    if (lstSubWins.size() > 0)
    {
        return dynamic_cast<aMdiChild *> (lstSubWins.back());
    }

    return nullptr;
} // aMdiArea::topmostMdiChild


} // namespace aWin
} // namespace aLib

#endif //_USE_QT_
