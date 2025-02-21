/*******************************************************************************
* \file qTitleBar.cpp
* \author Andreas Kuhlewind
*
* \brief
*
*  Detailed description starts here.
*******************************************************************************/


/*******************************************************************************
* includes
*******************************************************************************/
#include "qTitleBar.h"
#include "qParentControlTool.h"
#include "qToolButton.h"
#include "qLayoutHoriVert.h"
#include "qSpacer.h"


namespace qLib
{
    /*******************************************************************************
    * qTitleBar::qTitleBar
    *******************************************************************************/
    qTitleBar::qTitleBar(qWin  *_pParent  /* = nullptr */)
    : qCtrlBar(_pParent)
    {
    } // qTitleBar::qTitleBar


    /*******************************************************************************
    * qTitleBar::~qTitleBar
    *******************************************************************************/
    qTitleBar::~qTitleBar()
    {
    } // qTitleBar::~qTitleBar


    /*******************************************************************************
    * qTitleBar::OnRegisterCtrl
    *******************************************************************************/
    void qTitleBar::OnRegisterCtrl()
    {
        // create the layout
        qLayoutHoriVert *pLayout = dynamic_cast<qLayoutHoriVert *> (GetLayout());
        CHECK_PRE_CONDITION_VOID(pLayout != nullptr);

        qToolButton *pBtn;
        qSpacer     *pSpacer;

        // add the qSpacer
        pSpacer = new qSpacer(this);
        pSpacer->CreateWin();
        pLayout->AddChild(pSpacer);

        // add the minimize button
        pBtn = new qToolButton(this, SYS_ID_MINIMIZE);
        pBtn->CreateWin();
        pBtn->SetPixmap("Masked/minimize.png");
        pBtn->SetButtonStyle(enumButtonStyle::MASKED_ROUND_MODE);
        pLayout->AddChild(pBtn);
        Register(pBtn);

        // add the maximize button
        pBtn = new qToolButton(this, SYS_ID_MAXIMIZE);
        pBtn->CreateWin();
        pBtn->SetPixmap("Masked/maximize.png");
        pBtn->SetButtonStyle(enumButtonStyle::MASKED_ROUND_MODE);
        pLayout->AddChild(pBtn);
        Register(pBtn);

        // add the close button
        pBtn = new qToolButton(this, SYS_ID_CLOSE);
        pBtn->CreateWin();
        pBtn->SetPixmap("Masked/close.png");
        pBtn->SetButtonStyle(enumButtonStyle::MASKED_ROUND_MODE);
        pBtn->SetHoverColor(colDarkRed);
        pLayout->AddChild(pBtn);
        Register(pBtn);

        unique_ptr<qParentControlTool> pTool = make_unique<qParentControlTool> (this);
        SetTool(std::move(pTool));
    } // qTitleBar::OnRegisterCtrl


    /*******************************************************************************
    * qTitleBar::OnUpdateCtrl
    *******************************************************************************/
    void qTitleBar::OnUpdateCtrl(qCtrlBase */*_pCtrl*/)
    {

    } // qTitleBar::OnUpdateCtrl


    /*******************************************************************************
    * qTitleBar::OnCtrlClicked
    *******************************************************************************/
    void qTitleBar::OnCtrlClicked(qCtrlBase *_pCtrl)
    {
        qWin *pParent = GetParent();
        CHECK_PRE_CONDITION_VOID(pParent != nullptr);

        switch (_pCtrl->GetCtrlId())
        {
            case SYS_ID_MINIMIZE:
                pParent->ShowMinimized();
                break;

            case SYS_ID_MAXIMIZE:
                pParent->ToggleMaximized();
                break;

            case SYS_ID_CLOSE:
                pParent->CloseWin();
                break;
        }

    } // qTitleBar::OnCtrlClicked

} // namespace qLib
