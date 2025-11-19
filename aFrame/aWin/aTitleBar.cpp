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
aTitleBar::aTitleBar(aBaseWin *_pParent /*= nullptr*/)
: aToolBar(_pParent)
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
    CHECK_PRE_CONDITION(aToolBar::onSysCreateWin(), false);

    // set the minimin w, h
    setMinDim(sysMetrics());

    addTool(make_unique<aParentCtrlTool> (this));

    return true;
} // namespace aFrame


} // namespace aWin
} // namespace aFrame
