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
: aCtrlBar(_pParent)
{
} // aTitleBar::aTitleBar


/*******************************************************************************
* aTitleBar::~aTitleBar
*******************************************************************************/
aTitleBar::~aTitleBar()
{
} // aTitleBar::~aTitleBar


/*******************************************************************************
* aTitleBar::onRegisterCtrl
*******************************************************************************/
void aTitleBar::onRegisterCtrl()
{
    // get the layout
    aLayoutHoriVert *pLayout    = layoutHoriVert();
    CHECK_PRE_CONDITION_VOID(pLayout != nullptr);

    aToolButton     *pBtn;
    aHoriSpacer     *pSpacer;

    pSpacer = new aHoriSpacer(this);
    pSpacer->create();
    pLayout->addChild(pSpacer);

    pBtn = new aToolButton(this, CTRL_ID_MINIMIZE);
    pBtn->create();
    pBtn->setPixmap("Masked/minimize.png");
    pBtn->setButtonStyle(enumButtonStyle::MASKED_ROUND_MODE);
    pBtn->setFixedDim(22, 22);
    pLayout->addChild(pBtn);
    registerCtrl(pBtn);

    pBtn = new aToolButton(this, CTRL_ID_MAXIMIZE);
    pBtn->create();
    pBtn->setPixmap("Masked/maximize.png");
    pBtn->setButtonStyle(enumButtonStyle::MASKED_ROUND_MODE);
    pBtn->setFixedDim(22, 22);
    pLayout->addChild(pBtn);
    registerCtrl(pBtn);

    pBtn = new aToolButton(this, CTRL_ID_CLOSE);
    pBtn->create();
    pBtn->setHoverColor(colDarkRed);
    pBtn->setPixmap("Masked/close.png");
    pBtn->setButtonStyle(enumButtonStyle::MASKED_ROUND_MODE);
    pBtn->setFixedDim(22, 22);
    pLayout->addChild(pBtn);
    registerCtrl(pBtn);

} // aTitleBar::onRegisterCtrl


/*******************************************************************************
* aTitleBar::onUpdateCtrl
*******************************************************************************/
void aTitleBar::onUpdateCtrl(aCtrl */*_pCtrl*/)
{
} // aTitleBar::onUpdateCtrl


/*******************************************************************************
* aTitleBar::onCtrlClicked
*******************************************************************************/
void aTitleBar::onCtrlClicked(aCtrl *_pCtrl)
{
    CHECK_PRE_CONDITION_VOID(parent() != nullptr);

    switch (_pCtrl->id())
    {
        case CTRL_ID_MINIMIZE:
            parent()->showMinimized();
            break;

        case CTRL_ID_MAXIMIZE:
            parent()->toggleMaximized();
            break;

        case CTRL_ID_CLOSE:
            parent()->close();
            break;

    }
} // aTitleBar::onCtrlClicked


/*******************************************************************************
* aTitleBar::onSysCreate
*******************************************************************************/
bool aTitleBar::onSysCreate()
{
    // baseclass sets the layout
    aCtrlBar::onSysCreate();

    // start the parent ctrl tool
    unique_ptr<aParentControlTool> pTool = make_unique<aParentControlTool> (this);
    setTool(std::move(pTool));

    return true;
} // aTitleBar::onSysCreate


} // namespace aWin
} // namespace aLib
