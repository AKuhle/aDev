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

#include "cmdFlipHori.h"
#include "cmdFlipVert.h"
#include "cmdInvert.h"
#include "cmdRotate180.h"
#include "cmdRotateCCW.h"
#include "cmdRotateCW.h"


/*******************************************************************************
* MainWin::startCmd
*******************************************************************************/
void MainWin::startCmd(shared_ptr<CmdBase> _pCmd)
{
    shared_ptr<Document>    pDoc    = getActiveDocument();
    if (pDoc != nullptr)
    {
        pDoc->executeCmd(_pCmd);
    }
} // MainWin::startCmd


/*******************************************************************************
* MainWin::onRegisterCtrl
*******************************************************************************/
void MainWin::onRegisterCtrl()
{
} // MainWin::onRegisterCtrl


/*******************************************************************************
* MainWin::onUpdateCtrl
*******************************************************************************/
void MainWin::onUpdateCtrl(aCtrl *_pCtrl)
{
    bool    bDoc    = (getActiveDocument() != nullptr);
    bool    bThread = isThreadRunning();

    switch (_pCtrl->id())
    {
        // always true
        case ID_FILE_OPEN:
            _pCtrl->setEnabled(true);
            break;

        case ID_IMAGE_FLIP_HORI:
        case ID_IMAGE_FLIP_VERT:
        case ID_IMAGE_ROTATE_CCW:
        case ID_IMAGE_ROTATE_CW:
        case ID_IMAGE_ROTATE_180:
        case ID_IMAGE_FLIP_INVERT:
            _pCtrl->setEnabled(bDoc && !bThread);
            break;
    }
} // MainWin::onUpdateCtrl


/*******************************************************************************
* MainWin::onCtrlClicked
*******************************************************************************/
void MainWin::onCtrlClicked(aCtrl *_pCtrl)
{
    const shared_ptr<SynchronizedLS> &pSync = getActiveLS();

    switch (_pCtrl->id())
    {
        case ID_FILE_OPEN:
            loadFile();
            break;

        case ID_IMAGE_FLIP_HORI:
            if (pSync != nullptr)
                startCmd(make_shared<CmdFlipHori> (pSync, statusBar()));
            break;

        case ID_IMAGE_FLIP_VERT:
            if (pSync != nullptr)
                startCmd(make_shared<CmdFlipVert> (pSync, statusBar()));
            break;

        case ID_IMAGE_ROTATE_CCW:
            if (pSync != nullptr)
                startCmd(make_shared<CmdRotateCCW> (pSync, statusBar()));
            break;

        case ID_IMAGE_ROTATE_CW:
            if (pSync != nullptr)
                startCmd(make_shared<CmdRotateCW> (pSync, statusBar()));
            break;

        case ID_IMAGE_ROTATE_180:
            if (pSync != nullptr)
                startCmd(make_shared<CmdRotate180> (pSync, statusBar()));
            break;

        case ID_IMAGE_FLIP_INVERT:
            if (pSync != nullptr)
                startCmd(make_shared<CmdInvert> (pSync, statusBar()));
            break;
    } // switch (_pCtrl->id())

} // MainWin::onCtrlClicked
