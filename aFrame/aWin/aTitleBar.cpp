/*******************************************************************************
* \file aTitleBar.cpp
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

#include "aTitleBar.h"
#include "aParentCtrlTool.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aFrame {
namespace aWin {


/*******************************************************************************
* aTitleBar::aTitleBar
*******************************************************************************/
aTitleBar::aTitleBar(SysWin *_pParent /*= nullptr*/)
: aBaseWin(_pParent)
{
} // aTitleBar::aTitleBar


/*******************************************************************************
* aTitleBar::~aTitleBar
*******************************************************************************/
aTitleBar::~aTitleBar()
{
} // aTitleBar::~aTitleBar


/*******************************************************************************
* aTitleBar::onSysCreateWin
*******************************************************************************/
bool aTitleBar::onSysCreateWin()
{
    CHECK_PRE_CONDITION(aBaseWin::onSysCreateWin(), false);

    addTool(make_unique<aParentCtrlTool> (this));

    return true;
} // namespace aFrame


/*******************************************************************************
* aTitleBar::onLDoubleClick
*******************************************************************************/
 bool aTitleBar::onLDoubleClick(u16          _u16Modifier,
                                const aPoint &_pntLocal,
                                const aPoint &_pntGlobal)
{
     return onToolManagerLDoubleClick(_u16Modifier, _pntLocal, _pntGlobal);
} // aTitleBar::onLDoubleClick


} // namespace aWin
} // namespace aFrame
