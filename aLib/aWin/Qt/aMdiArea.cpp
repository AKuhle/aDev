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


} // namespace aWin
} // namespace aLib

#endif //_USE_QT_
