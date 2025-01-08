/*******************************************************************************
* \file StdBar.cpp
* \author Andreas Kuhlewind
*
* \brief
*
*  Detailed description starts here.
*******************************************************************************/


/*******************************************************************************
* includes
*******************************************************************************/
#include "mainWin.h"
#include "qGamesDefs.h"
#include "stdBar.h"


namespace qLib
{
    /*******************************************************************************
    * StdBar::StdBar
    *******************************************************************************/
    StdBar::StdBar(qWin  *_pParent  /* = nullptr */)
    : qCtrlBar(_pParent)
    {
    } // StdBar::StdBar


    /*******************************************************************************
    * StdBar::~StdBar
    *******************************************************************************/
    StdBar::~StdBar()
    {
    } // StdBar::~StdBar


    /*******************************************************************************
    * StdBar::OnRegisterCtrl
    *******************************************************************************/
    void StdBar::OnRegisterCtrl()
    {
        MainWin &mw = GetMainWin();

        // create the layout
        qLayoutHoriVert *pLayout = dynamic_cast<qLayoutHoriVert *> (GetLayout());
        CHECK_PRE_CONDITION_VOID(pLayout != nullptr);

        qToolButton *pBtn;

        // add the minimize button
        pBtn = new qToolButton(this, ID_FILE_OPEN);
        pBtn->CreateWin();
        pBtn->SetPixmap("Masked/file_open.png");
        pBtn->SetButtonStyle(enumButtonStyle::MASKED_MODE);
        pLayout->AddChild(pBtn);
        mw.Register(pBtn);
    } // StdBar::OnRegisterCtrl


    /*******************************************************************************
    * StdBar::OnUpdateCtrl
    *******************************************************************************/
    void StdBar::OnUpdateCtrl(qCtrlBase */*_pCtrl*/)
    {

    } // StdBar::OnUpdateCtrl


    /*******************************************************************************
    * StdBar::OnCtrlClicked
    *******************************************************************************/
    void StdBar::OnCtrlClicked(qCtrlBase */*_pCtrl*/)
    {
        // qWin *pParent = GetParent();
        // CHECK_PRE_CONDITION_VOID(pParent != nullptr);

        // if (_u32Mes == MES_CLICKED)
        // {
        //     switch (_pCtrl->GetCtrlId())
        //     {
        //         case SYS_ID_MINIMIZE:
        //         pParent->ShowMinimized();
        //             break;

        //         case SYS_ID_MAXIMIZE:
        //             pParent->ToggleMaximized();
        //             break;

        //         case SYS_ID_CLOSE:
        //             pParent->CloseWin();
        //             break;
        //     }
        // }

    } // StdBar::OnCtrlClicked

} // namespace qLib
