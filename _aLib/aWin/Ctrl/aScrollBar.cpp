/*******************************************************************************
* \file aScrollBar.inl
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
#include "aWin/Ctrl/aScrollBar.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aWin {


/*******************************************************************************
* aScrollBar::aScrollBar
*******************************************************************************/
aScrollBar::aScrollBar(aBaseWin    *_pParent,
                       u32         _u32Id)
: aCtrl(_pParent, _u32Id)
{
} // aScrollBar::aScrollBar


/*******************************************************************************
* aScrollBar::~aScrollBar
*******************************************************************************/
aScrollBar::~aScrollBar()
{
} // aScrollBar::~aScrollBar


/*******************************************************************************
* aScrollBar::onSysCreate
*******************************************************************************/
bool aScrollBar::onSysCreate()
{
    // // enable mouse tracking for border resize
    // setMouseTracking(true);

    // // start the border resize tool
    // unique_ptr<aScrollBarTool> pTool = make_unique<aScrollBarTool> (this);
    // setTool(std::move(pTool));

    return true;
} // aScrollBar::onSysCreate


} // namespace aWin
} // namespace aLib
