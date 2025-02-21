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
#include "mainWin.h"
#include "viewBase.h"
#include "cmdOpenFile.h"
#include "aUrl.h"
#include "cmdBase.h"
#include "aMdiWin.h"
#include "aMdiArea.h"
#include "editScrollWin.h"
#include "editView.h"
//#include "aStopwatch.h"



/*******************************************************************************
* MainWin::onUpdateCmd
*******************************************************************************/
void MainWin::onUpdateCmd(u64     _u64Cmd,
                          aDoc    *_pDoc,
                          aView   *_pView,
                          s64     _s64Param1,
                          s64     _s64Param2,
                          u64     /*_u64Param1*/,
                          u64     /*_u64Param2*/,
                          flt     /*_fltParam1*/,
                          flt     /*_fltParam2*/,
                          dbl     /*_dblParam1*/,
                          dbl     /*_dblParam2*/,
                          void    */*_pParam1*/,
                          void    */*_pParam2*/)
{
    //static aStopwatch stopwatch;

    //Document *pDoc  = dynamic_cast<Document> (_pDoc);
    ViewBase *pView = dynamic_cast<ViewBase*> (_pView);

    // UPDATE_VIEW
    if (aUtil::isBitsSet<u64> (_u64Cmd, UPDATE_VIEW))
    {
        if (_pView != nullptr)
        {
            pView->update();
        }
    }

    // UPDATE_VIEWS_BY_DOC
    if (aUtil::isBitsSet<u64> (_u64Cmd, UPDATE_VIEWS_BY_DOC))
    {
        aPtrList<ViewBase>  lstView = viewList();
        for (ViewBase *pView : lstView)
        {
            if (pView->document().get() == _pDoc)
            {
                pView->repaint();
            }
        }
    }

    // UPDATE_CMD_PROCESSING_START
    if (aUtil::isBitsSet<u64> (_u64Cmd, UPDATE_CMD_PROCESSING_START))
    {
        m_bThreadRunning = true;
        aUtil::setBits(_u64Cmd, UPDATE_GUI);

        //stopwatch.start();
    }

    // UPDATE_CMD_COORDINATES
    if (aUtil::isBitsSet<u64> (_u64Cmd, UPDATE_CMD_COORDINATES))
    {
        StatusBar *pStatusBar = statusBar();

        if (pStatusBar != nullptr && pStatusBar->isVisible())
        {
            pStatusBar->updateCoordinates(_s64Param1, _s64Param2);
        }
    }

    // UPDATE_CMD_COORDINATES_CLEAR
    if (aUtil::isBitsSet<u64> (_u64Cmd, UPDATE_CMD_COORDINATES_CLEAR))
    {
        StatusBar *pStatusBar = statusBar();

        if (pStatusBar != nullptr && pStatusBar->isVisible())
        {
            pStatusBar->clearCoordinates();
        }
    }

    // UPDATE_CMD_PROCESSING_END
    if (aUtil::isBitsSet<u64> (_u64Cmd, UPDATE_CMD_PROCESSING_END))
    {
        //std::cout << "stopwatch: " << stopwatch.stop() << std::endl;

        m_bThreadRunning = false;
        aUtil::setBits(_u64Cmd, UPDATE_GUI);
    }

    if (aUtil::isBitsSet<u64> (_u64Cmd, UPDATE_GUI))
    {
        // update ctrls of mainWIn
        updateAllCtrls();
    }
} // MainWin::onUpdateCmd


/*******************************************************************************
* MainWin::onDropUrl
*******************************************************************************/
void MainWin::onDropUrl(const aUrl &_url)
{
    aPath   path(_url.toLocalFile());

    shared_ptr<CmdOpenFile> pCmd = make_shared<CmdOpenFile> (path, statusBar());

    executeCmd(pCmd);
} // MainWin::onDropUrl


/*******************************************************************************
* MainWin::onCmdProcessingStart
*******************************************************************************/
void MainWin::onCmdProcessingStart(const shared_ptr<aCmdBase> &/*_pCmd*/)
{
    sendUpdateCmd(UPDATE_CMD_PROCESSING_START);
} // MainWin::onCmdProcessingStart


/*******************************************************************************
* MainWin::onCmdProcessingEnd
*******************************************************************************/
void MainWin::onCmdProcessingEnd(const shared_ptr<aCmdBase> &/*_pCmd*/)
{
    sendUpdateCmd(UPDATE_CMD_PROCESSING_END);
} // MainWin::onCmdProcessingEnd


/*******************************************************************************
* MainWin::onDoDone
*******************************************************************************/
void MainWin::onDoDone(const shared_ptr<aCmdBase> &_pCmd)
{
    shared_ptr<CmdBase> pCmd = dynamic_pointer_cast<CmdBase> (_pCmd);
    CHECK_PRE_CONDITION_VOID(pCmd != nullptr);

    switch (pCmd->id())
    {
        case ID_FILE_OPEN:
        {
            const shared_ptr<SynchronizedLS> &pSync = pCmd->postLS();
            SharedLS pShared(*pSync);
            shared_ptr<aLayerStack> pPostLS = pShared.get();

            if (pPostLS->isValid())
            {
                // create the document with the layerstack
                shared_ptr<Document> pDoc = make_shared<Document> (std::move(pCmd));

                // create the mdiWin
                aMdiWin     *pMdiWin = new aMdiWin(mdiArea());
                pMdiWin->create();
                addMdiWin(pMdiWin);
                pMdiWin->setGeometry(100, 100, 200, 150);
                pMdiWin->setMinDim(200, 150);

                // create the EditScrollWin and set it to the
                // child of the mdiWin
                EditScrollWin     *pEditScrollWin = new EditScrollWin();
                pEditScrollWin->create();
                pMdiWin->setCentralWin(pEditScrollWin);

                // create the view an set it to the
                // child of the scrollWin
                EditView *pView = new EditView(nullptr, pDoc);
                pView->create();
                pEditScrollWin->setCentralWin(pView);
            }
        } //case ID_FILE_OPEN
    } // switch (pCmd->id())
} // MainWin::onDoDone
