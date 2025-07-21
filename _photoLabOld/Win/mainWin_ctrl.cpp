/*******************************************************************************
* \file BaseApp.h
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
#include "photoLab_defs.h"

#include "mainWin.h"
#include "document.h"

#include "aAction.h"

#include "cmdFlipHori.h"
#include "cmdFlipVert.h"
#include "cmdRotateCCW.h"
#include "cmdRotateCW.h"
#include "cmdRotate180.h"
#include "cmdInvert.h"

#include "aDockWin.h"
#include "statusBar.h"


using namespace aLib::aWin;
using namespace std;


/*******************************************************************************
* MainWin::onRegisterCtrl
*******************************************************************************/
void MainWin::onRegisterCtrl()
{
    registerCtrl(m_pUi->m_pActionFileOpen, ID_FILE_OPEN);
    registerCtrl(m_pUi->m_pActionExit, ID_EXIT);

    registerCtrl(m_pUi->m_pActionUndo, ID_UNDO);
    registerCtrl(m_pUi->m_pActionRedo, ID_REDO);

    registerCtrl(m_pUi->m_pActionNavigator, ID_VIEW_NAVIGATOR);
    registerCtrl(m_pUi->m_pActionStatusBar, ID_VIEW_STATUSBAR);

    registerCtrl(m_pUi->m_pActionFlipHori, ID_IMAGE_FLIP_HORI);
    registerCtrl(m_pUi->m_pActionFlipVert, ID_IMAGE_FLIP_VERT);
    registerCtrl(m_pUi->m_pActionRotCCW, ID_IMAGE_ROTATE_CCW);
    registerCtrl(m_pUi->m_pActionRotCW, ID_IMAGE_ROTATE_CW);
    registerCtrl(m_pUi->m_pActionRot180, ID_IMAGE_ROTATE_180);
    registerCtrl(m_pUi->m_pActionInvert, ID_IMAGE_FLIP_INVERT);
} // MainWin::onRegisterCtrl


/*******************************************************************************
* MainWin::onUpdateCtrl
*******************************************************************************/
void MainWin::onUpdateCtrl(aCtrlI *_pCtrl)
{
    bool                    b        = busy();
    shared_ptr<Document>    pDoc     = getActiveDoc();
    bool                    bDoc     = (pDoc != nullptr);
    aAction                 *pAction = dynamic_cast<aAction *> (_pCtrl);

    switch (_pCtrl->ctrlId())
    {
        // always ebabled
        case ID_FILE_OPEN:
            _pCtrl->setCtrlEnabled(true);
            break;

        case ID_EXIT:
            _pCtrl->setCtrlEnabled(!b);
            break;

        case ID_VIEW_NAVIGATOR:
            pAction->setCtrlEnabledChecked(true, m_pNavigatorDockWin->isVisible());
            break;

        case ID_VIEW_STATUSBAR:
            pAction->setCtrlEnabledChecked(true, m_pStatusBar->isVisible());
            break;

        case ID_UNDO:
            _pCtrl->setCtrlEnabled(!b && bDoc && pDoc->canUndo());
            break;

        case ID_REDO:
            _pCtrl->setCtrlEnabled(!b && bDoc && pDoc->canRedo());
            break;

        case ID_IMAGE_FLIP_HORI:
        case ID_IMAGE_FLIP_VERT:
        case ID_IMAGE_ROTATE_CCW:
        case ID_IMAGE_ROTATE_CW:
        case ID_IMAGE_ROTATE_180:
        case ID_IMAGE_FLIP_INVERT:
            _pCtrl->setCtrlEnabled(!b && bDoc);
            break;
    }
} // MainWin::onUpdateCtrl


/*******************************************************************************
* MainWin::onCtrlClicked
*******************************************************************************/
void MainWin::onCtrlClicked(aCtrlI *_pCtrl)
{
    shared_ptr<Document>    pDoc    = getActiveDoc();
    bool                    bDoc    = (pDoc != nullptr);

    switch (_pCtrl->ctrlId())
    {
        case ID_FILE_OPEN:
            //_pCtrl->setCtrlEnabled(true);
            break;

        case ID_EXIT:
            closeWin();
            break;

        case ID_VIEW_NAVIGATOR:
        {
            m_pNavigatorDockWin->setVisible(!m_pNavigatorDockWin->isVisible());
            //updateCtrl(_pCtrl);
            break;
        }

        case ID_VIEW_STATUSBAR:
        {
            m_pStatusBar->setVisible(!m_pStatusBar->isVisible());
            //updateCtrl(_pCtrl);
            break;
        }

        case ID_UNDO:
            if (bDoc)
                pDoc->undoCmd();
            break;

        case ID_REDO:
            if (bDoc)
                pDoc->redoCmd();
            break;

        case ID_IMAGE_FLIP_HORI:
        case ID_IMAGE_FLIP_VERT:
        case ID_IMAGE_ROTATE_CCW:
        case ID_IMAGE_ROTATE_CW:
        case ID_IMAGE_ROTATE_180:
        case ID_IMAGE_FLIP_INVERT:
            startCmd(_pCtrl->ctrlId());
            break;
    }
} // MainWin::onCtrlClicked


/*******************************************************************************
* MainWin::startCmd
*******************************************************************************/
void MainWin::startCmd(u32 _u32CtrlId)
{
    shared_ptr<Document>        pDoc    = getActiveDoc();
    shared_ptr<SynchronizedLS>  pPrevLS = getActiveLS();
    shared_ptr<CmdBase>         pCmd;
    CHECK_PRE_CONDITION_VOID(pDoc != nullptr && pPrevLS != nullptr);

    switch (_u32CtrlId)
    {
        case ID_IMAGE_FLIP_HORI:        pCmd = make_shared<CmdFlipHori> (pPrevLS, &getStatusBar());    break;
        case ID_IMAGE_FLIP_VERT:        pCmd = make_shared<CmdFlipVert> (pPrevLS, &getStatusBar());    break;
        case ID_IMAGE_ROTATE_CCW:       pCmd = make_shared<CmdRotateCCW> (pPrevLS, &getStatusBar());   break;
        case ID_IMAGE_ROTATE_CW:        pCmd = make_shared<CmdRotateCW> (pPrevLS, &getStatusBar());    break;
        case ID_IMAGE_ROTATE_180:       pCmd = make_shared<CmdRotate180> (pPrevLS, &getStatusBar());   break;
        case ID_IMAGE_FLIP_INVERT:      pCmd = make_shared<CmdInvert> (pPrevLS, &getStatusBar());      break;
    }

    pDoc->executeCmd(std::move(pCmd));
} // MainWin::startCmd
