/*******************************************************************************
* includes
*******************************************************************************/
#include "aWin/Framework/aTitleBar.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
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
* aTitleBar::onSysCreate
*******************************************************************************/
bool aTitleBar::onSysCreate()
{
    // setMinSize(30, 30);

    // // start th eparent ctrl tool
    // unique_ptr<qParentControlTool> pTool = make_unique<qParentControlTool> (this);
    // setTool(std::move(pTool));

    return true;
} // aTitleBar::onSysCreate


} // namespace aWin
} // namespace aLib