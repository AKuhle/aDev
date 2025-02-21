/*******************************************************************************
* \file mainWin.cpp
* \author Andreas Kuhlewind
*
* \brief
*
* $Revision: 69 $
* $LastChangedDate: 2010-08-17 14:10:45 +0200 (Di, 17 Aug 2010) $
* $LastChangedBy: akuhlewi $
*
*  Detailed description starts here.
*******************************************************************************/


/*******************************************************************************
* includes
*******************************************************************************/
#include "ui_formMainWin.h"

#include "defsPl.h"
#include "mainWin.h"
#include "docPl.h"

#include "cmdFlipHori.h"
#include "cmdFlipVert.h"
#include "cmdRotateCCW.h"
#include "cmdRotateCW.h"
#include "cmdRotate180.h"
#include "cmdInvert.h"


using namespace qLib;


/*******************************************************************************
* MainWin::OnRegisterCtrl
*******************************************************************************/
void MainWin::OnRegisterCtrl()
{
    // standard toolbar
    Register(m_pUi->m_pActionToolBox, ID_TOOLBOX);
    Register(m_pUi->m_pActionNavigator, ID_NAVIGATOR);
    Register(m_pUi->m_pActionProtocol, ID_PROTOCOL);

    Register(m_pUi->m_pActionUndo, ID_UNDO);
    Register(m_pUi->m_pActionRedo, ID_REDO);

    // transform toolbar
    Register(m_pUi->m_pActionFlipHori, ID_FLIP_HORI);
    Register(m_pUi->m_pActionFlipVert, ID_FLIP_VERT);
    Register(m_pUi->m_pActionRotCCW, ID_ROTATE_CCW);
    Register(m_pUi->m_pActionRotCW, ID_ROTATE_CW);
    Register(m_pUi->m_pActionRot180, ID_ROTATE_180);
    Register(m_pUi->m_pActionInvert, ID_INVERT);

    // file menu
    Register(m_pUi->m_pActionFileOpen, ID_FILE_OPEN);
    Register(m_pUi->m_pActionExit, ID_EXIT);
} // MainWin::OnRegisterCtrl


/*******************************************************************************
* MainWin::OnUpdateCtrl
*******************************************************************************/
void MainWin::OnUpdateCtrl(qCtrlI *_pCtrl)
{
    std::shared_ptr<DocPl>  pDoc    = GetActiveDoc();
    bool                    bDoc    = (pDoc != nullptr);

    bool                    bView   = (GetActiveView() != nullptr);
    bool                    bC      = IsCalculating();

    switch (_pCtrl->CtrlId())
    {
        default:
            _pCtrl->SetCtrlEnabled(false);
            break;

        // ctrls, which are always enabled
        case ID_FILE_OPEN:
        case ID_EXIT:
            _pCtrl->SetCtrlEnabled(!bC);
            break;

        case ID_TOOLBOX:
            _pCtrl->SetCtrlEnabledChecked(true, m_pToolBoxDockWin->IsVisible());
            break;

        case ID_NAVIGATOR:
            _pCtrl->SetCtrlEnabledChecked(true, m_pNavigatorDockWin->IsVisible());
            break;

        case ID_PROTOCOL:
            _pCtrl->SetCtrlEnabledChecked(true, m_pProtocolDockWin->IsVisible());
            break;

        case ID_UNDO:
            _pCtrl->SetCtrlEnabled(!bC && bDoc && pDoc->CanUndo());
            break;

        case ID_REDO:
            _pCtrl->SetCtrlEnabled(!bC && bDoc && pDoc->CanRedo());
            break;

        case ID_FLIP_HORI:
        case ID_FLIP_VERT:
        case ID_ROTATE_CCW:
        case ID_ROTATE_CW:
        case ID_ROTATE_180:
        case ID_INVERT:
            _pCtrl->SetCtrlEnabled(bView && !bC);
            break;

    } // switch (_pCtrl->CtrlId())
} // MainWin::OnUpdateCtrl


/*******************************************************************************
* MainWin::OnCtrlMessage
*******************************************************************************/
void MainWin::OnCtrlMessage(qCtrlI  *_pCtrl,
                            u32     _u32Mes,
                            s64     /*_s64Value*/   /*= 0*/,
                            void     */*_pVoid1*/   /*= nullptr*/,
                            void     */*_pVoid2*/   /*= nullptr*/)
{
    std::shared_ptr<DocPl>  pDoc        = GetActiveDoc();
    bool                    bDoc        = (pDoc != nullptr);

    bool                    bTriggered  = (_u32Mes == MsgTriggered);

    switch (_pCtrl->CtrlId())
    {
        default:
            break;

        case ID_FILE_OPEN:
            if (bTriggered)
                OnOpenFile();
            break;

        case ID_TOOLBOX:
            if (bTriggered)
                m_pToolBoxDockWin->SetVisible(!m_pToolBoxDockWin->IsVisible());
            break;

        case ID_NAVIGATOR:
            if (bTriggered)
                m_pNavigatorDockWin->SetVisible(!m_pNavigatorDockWin->IsVisible());
            break;

        case ID_PROTOCOL:
            if (bTriggered)
                m_pProtocolDockWin->SetVisible(!m_pProtocolDockWin->IsVisible());
            break;

        case ID_EXIT:
            if (bTriggered)
                CloseWin();
            break;


        case ID_UNDO:
            if (bTriggered && bDoc)
                pDoc->UndoCmd();
            break;

        case ID_REDO:
            if (bTriggered && bDoc)
                pDoc->RedoCmd();
            break;

        case ID_FLIP_HORI:
        case ID_FLIP_VERT:
        case ID_ROTATE_CCW:
        case ID_ROTATE_CW:
        case ID_ROTATE_180:
        case ID_INVERT:
            if (bTriggered)
                StartCmd(_pCtrl->CtrlId());
            break;

    } // switch (_pCtrl->CtrlId())
} // MainWin::OnCtrlMessage



/*******************************************************************************
* MainWin::StartCmd
*******************************************************************************/
void MainWin::StartCmd(u32    _u32CtrlId)
{
    std::shared_ptr<DocPl>      pDoc    = GetActiveDoc();
    shared_ptr<qLayerStack>     pPrevLS = GetActiveLS();
    unique_ptr<CmdBase>         pCmd;
    CHECK_PRE_CONDITION_VOID(pDoc != nullptr && pPrevLS != nullptr);

    switch (_u32CtrlId)
    {
        case ID_FLIP_HORI:          pCmd = make_unique<CmdFlipHori> (pPrevLS, this);            break;
        case ID_FLIP_VERT:          pCmd = make_unique<CmdFlipVert> (pPrevLS, this);            break;
        case ID_ROTATE_CCW:         pCmd = make_unique<CmdRotateCCW> (pPrevLS, this);           break;
        case ID_ROTATE_CW:          pCmd = make_unique<CmdRotateCW> (pPrevLS, this);            break;
        case ID_ROTATE_180:         pCmd = make_unique<CmdRotate180> (pPrevLS, this);           break;
        case ID_INVERT:             pCmd = make_unique<CmdInvert> (pPrevLS, this);              break;
    }

    pDoc->ExecuteCmd(std::move(pCmd));
} // MainWin::StartCmd
