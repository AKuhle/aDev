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
#include "aUrl.h"
#include "aPath.h"

using namespace aFrame::aUtil;



/*******************************************************************************
* MainWin::onMinimize
*******************************************************************************/
void MainWin::onMinimize(aBtn */*_pBtn*/)
{
    showMinimized();
} // MainWin::onMinimize


/*******************************************************************************
* MainWin::onMaximize
*******************************************************************************/
void MainWin::onMaximize(aBtn */*_pBtn*/)
{
    showMaximized();
} // MainWin::onMaximize


/*******************************************************************************
* MainWin::onClose
*******************************************************************************/
void MainWin::onClose(aBtn */*_pBtn*/)
{
    closeWin();
} // MainWin::onClose


/*******************************************************************************
* MainWin::onOpenFile
*******************************************************************************/
void MainWin::onOpenFile(aBtn */*_pBtn*/)
{
    cout << __PRETTY_FUNCTION__ << endl;
} // MainWin::onOpenFile


/*******************************************************************************
* MainWin::onPaintContent
*******************************************************************************/
void MainWin::onPaintContent()
{
    //cout << __PRETTY_FUNCTION__ << endl;
} // MainWin::onPaintContent


/*******************************************************************************
* MainWin::onDropUrl
*******************************************************************************/
void MainWin::onDropUrl(const aUrl  &_url)
{
    aPath   path(_url.toLocalFile());

    cout << path.canonicalPath() << endl;
    //openFile(path);
} // MainWin::onDropUrl


// /*******************************************************************************
// * MainWin::onCmdProcessingStart
// *******************************************************************************/
// void MainWin::onCmdProcessingStart(const shared_ptr<aCmdBase> &/*_pCmd*/)
// {
//     sendUpdateCmd(UPDATE_CMD_PROCESSING_START);
// } // MainWin::onCmdProcessingStart


// /*******************************************************************************
// * MainWin::onCmdProcessingEnd
// *******************************************************************************/
// void MainWin::onCmdProcessingEnd(const shared_ptr<aCmdBase> &/*_pCmd*/)
// {
//     sendUpdateCmd(UPDATE_CMD_PROCESSING_END);
// } // MainWin::onCmdProcessingEnd


// /*******************************************************************************
// * MainWin::onDoDone
// *******************************************************************************/
// void MainWin::onDoDone(const shared_ptr<aCmdBase> &_pCmd)
// {
//     shared_ptr<CmdBase> pCmd = dynamic_pointer_cast<CmdBase> (_pCmd);
//     CHECK_PRE_CONDITION_VOID(pCmd != nullptr);

//     switch (pCmd->id())
//     {
//         case ID_FILE_OPEN:
//         {
//             const shared_ptr<SynchronizedLS> &pSync = pCmd->postLS();
//             SharedLS pShared(*pSync);
//             shared_ptr<aLayerStack> pPostLS = pShared.get();

//             if (pPostLS->isValid())
//             {
//                 // create the document with the layerstack
//                 shared_ptr<Document> pDoc = make_shared<Document> (std::move(pCmd));

//                 // create the mdiChild
//                 aMdiChild *pMdiChild = new aMdiChild();
//                 pMdiChild->createWin();
//                 addMdiChild(pMdiChild);
//                 pMdiChild->setMinSize(300, 200);
//                 pMdiChild->show();

//                 // create the scrollWin
//                 EditScrollWin *pScrollWin = new EditScrollWin;
//                  pScrollWin->createWin();
//                 pMdiChild->setCentralWin(pScrollWin);

//                 // create the edit view
//                 EditView *pEditView = new EditView(nullptr, pDoc);
//                 pEditView->createWin();
//                 pScrollWin->setCentralWin(pEditView);

//                 // //pMdiWin->setVisible(true);
//                 // pScrollWin->setVisible(true);
//                 pEditView->setVisible(true);

//                 sendUpdateCmd(UPDATE_CMD_VIEW_ACTIVATED, pEditView);
//             }
//         } //case ID_FILE_OPEN

//     } // switch (pCmd->id())

// } // MainWin::onDoDone


// /*******************************************************************************
// * MainWin::onUpdateCmd
// *******************************************************************************/
// void MainWin::onUpdateCmd(u64     _u64Cmd,
//                           aDoc    *_pDoc,
//                           aView   *_pView,
//                           s64     /*_s64Param1*/,
//                           s64     /*_s64Param2*/,
//                           u64     /*_u64Param1*/,
//                           u64     /*_u64Param2*/,
//                           flt     /*_fltParam1*/,
//                           flt     /*_fltParam2*/,
//                           dbl     /*_dblParam1*/,
//                           dbl     /*_dblParam2*/,
//                           void    */*_pParam1*/,
//                           void    */*_pParam2*/)
// {
//     // UPDATE_CMD_PROCESSING_START
//     if (isBitsSet(_u64Cmd, UPDATE_CMD_PROCESSING_START))
//     {
//         // update gui, e.g. disable buttons
//         _u64Cmd |= UPDATE_GUI | UPDATE_CMD_TOOL_WIN;
//     }

//     // UPDATE_CMD_PROCESSING_END
//     if (isBitsSet(_u64Cmd, UPDATE_CMD_PROCESSING_END))
//     {
//         // update gui, e.g. enable buttons
//         _u64Cmd |= UPDATE_GUI | UPDATE_CMD_TOOL_WIN;
//     }

//     // UPDATE_CMD_VIEW_ACTIVATED
//     if (isBitsSet(_u64Cmd, UPDATE_CMD_VIEW_ACTIVATED))
//     {
//         ViewBase *pView = dynamic_cast<ViewBase *> (_pView);

//         if (pView != nullptr)
//         {
//             pView->setTool(m_eEditMode);

//             // changing the active view results in an update of the gui
//             // e.g. the activated view has another color mode
//             _u64Cmd |= UPDATE_GUI | UPDATE_CMD_TOOL_WIN;
//         }
//     }

//     // UPDATE_VIEW
//     if (isBitsSet(_u64Cmd, UPDATE_VIEW))
//     {
//         if (_pView != nullptr)
//         {
//             _pView->update();
//         }
//     }

//     // UPDATE_VIEWS_BY_DOC
//     if (isBitsSet(_u64Cmd, UPDATE_VIEWS_BY_DOC))
//     {
//         // get all views
//         aPtrList<ViewBase> lstView;
//         viewList(lstView);

//         for (ViewBase *pView : lstView)
//         {
//             if (pView->document().get() == _pDoc)
//             {
//                 pView->update();
//             }
//         }
//     }


//     /*******************************************************************************
//     * Gui update - must be the last update in the queue
//     *******************************************************************************/
//     // UPDATE_GUI
//     if (isBitsSet(_u64Cmd, UPDATE_GUI))
//     {
//         updateAllCtrls();
//     }

//     // UPDATE_CMD_NAVIGATOR
//     if (isBitsSet(_u64Cmd, UPDATE_CMD_NAVIGATOR) && m_pNavigatorDockWin->isVisible())
//     {
//         m_pNavigatorToolWin->updateToolWin();
//     }

// } // MainWin::onUpdateCmd
