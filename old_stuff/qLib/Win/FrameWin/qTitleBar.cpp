/*******************************************************************************
* includes
*******************************************************************************/
#include "Win/FrameWin/qTitleBar.h"
#include "Tool/qParentControlTool.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace qLib {
namespace Win {


/*******************************************************************************
* qTitleBar::qTitleBar
*******************************************************************************/
qTitleBar::qTitleBar(qWin *_pParent /*= nullptr*/)
: qWin(_pParent)
{
} // qTitleBar::qTitleBar


/*******************************************************************************
* qTitleBar::~qTitleBar
*******************************************************************************/
qTitleBar::~qTitleBar()
{
} // qTitleBar::~qTitleBar


/*******************************************************************************
* qTitleBar::onCreateWin
*******************************************************************************/
bool qTitleBar::onCreateWin()
{
    setMinSize(30, 30);

    // start th eparent ctrl tool
    unique_ptr<qParentControlTool> pTool = make_unique<qParentControlTool> (this);
    setTool(std::move(pTool));

    return true;
} // qTitleBar::onCreateWin


} // namespace Win
} // namespace qLib
