/*******************************************************************************
* includes
*******************************************************************************/
#include "aWin/Framework/aTitleBar.h"
#include "aWin/Tool/aParentControlTool.h"

#include "aWin/Layout/aLayoutHoriVert.h"

#include "aWin/Ctrl/aToolButton.h"


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
    setMinSize(30, 30);

    // create the layout
    unique_ptr<aLayoutHoriVert> pLayout = make_unique<aLayoutHoriVert> ();

    aToolButton *pBtn = new aToolButton(this, 1234);
    pBtn->create();
    pBtn->setFixedSize(30, 30);

    // set the layout
    setLayout(std::move (pLayout));

    // start the parent ctrl tool
    unique_ptr<aParentControlTool> pTool = make_unique<aParentControlTool> (this);
    setTool(std::move(pTool));

    return true;
} // aTitleBar::onSysCreate


} // namespace aWin
} // namespace aLib
