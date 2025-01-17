/*******************************************************************************
* includes
*******************************************************************************/
#include "aWin/Framework/aTitleBar.h"
#include "aWin/Tool/aParentControlTool.h"

#include "aWin/Layout/aLayoutHoriVert.h"

#include "aWin/Ctrl/aToolButton.h"
#include "aWin/Ctrl/aHoriSpacer.h"


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
    aToolButton     *pBtn;
    aHoriSpacer     *pSpacer;

    // create the layout
    unique_ptr<aLayoutHoriVert> pLayout = make_unique<aLayoutHoriVert> ();

    pSpacer = new aHoriSpacer(this);
    pSpacer->create();
    pLayout->addChild(pSpacer);

    pBtn = new aToolButton(this, CTRL_ID_MINIMIZE);
    pBtn->create();
    pBtn->setPixmap("Masked/minimize.png");
    pBtn->setButtonStyle(enumButtonStyle::MASKED_ROUND_MODE);
    pBtn->setFixedDim(22, 22);
    pLayout->addChild(pBtn);
    // Register(pBtn);

    pBtn = new aToolButton(this, CTRL_ID_MAXIMIZE);
    pBtn->create();
    pBtn->setEnabled(false);
    pBtn->setPixmap("Masked/maximize.png");
    pBtn->setButtonStyle(enumButtonStyle::MASKED_ROUND_MODE);
    pBtn->setFixedDim(22, 22);
    pLayout->addChild(pBtn);
    // Register(pBtn);

    pBtn = new aToolButton(this, CTRL_ID_CLOSE);
    pBtn->create();
    pBtn->setHoverColor(colDarkRed);
    pBtn->setPixmap("Masked/close.png");
    pBtn->setButtonStyle(enumButtonStyle::MASKED_ROUND_MODE);
    pBtn->setFixedDim(22, 22);
    pLayout->addChild(pBtn);
    // Register(pBtn);

    // set the layout
    setLayout(std::move (pLayout));

    // start the parent ctrl tool
    unique_ptr<aParentControlTool> pTool = make_unique<aParentControlTool> (this);
    setTool(std::move(pTool));

    return true;
} // aTitleBar::onSysCreate


} // namespace aWin
} // namespace aLib
