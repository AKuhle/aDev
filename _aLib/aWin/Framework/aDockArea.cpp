/*******************************************************************************
* \file aDockArea.cpp
* \author Andreas Kuhlewind
*
* \brief
*
*  Detailed description starts here.
*******************************************************************************/


/*******************************************************************************
* includes
*******************************************************************************/
#include "aGraphic/GraphicObj/aFillSolid.h"

#include "aWin/Framework/aDockArea.h"
#include "aWin/Framework/aMdiArea.h"
#include "aWin/Framework/aTitleBar.h"

#include "aWin/Layout/aLayoutMainWin.h"

#include "aWin/Tool/aBorderResizeTool.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aWin {


/*******************************************************************************
* aDockArea::aDockArea
*******************************************************************************/
aDockArea::aDockArea(aBaseWin  *_pParent  /* = nullptr */)
: aBaseWin(_pParent)
{
} // aDockArea::aDockArea


/*******************************************************************************
* aDockArea::~aDockArea
*******************************************************************************/
aDockArea::~aDockArea()
{
} // aDockArea::aDockArea


} // namespace aWin
} // namespace aLib
