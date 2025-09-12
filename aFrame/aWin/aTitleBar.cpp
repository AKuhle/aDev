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
#include "aLayoutHoriVert.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aFrame {
namespace aWin {


/*******************************************************************************
* aTitleBar::aTitleBar
*******************************************************************************/
aTitleBar::aTitleBar(aBaseWin *_pParent /*= nullptr*/)
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

    // create the layout
    unique_ptr<aLayoutHoriVert>  pLayout = make_unique<aLayoutHoriVert> ();
    setLayout(std::move(pLayout));

    addTool(make_unique<aParentCtrlTool> (this));

    return true;
} // namespace aFrame


} // namespace aWin
} // namespace aFrame
