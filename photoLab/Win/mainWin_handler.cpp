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
#include "aString.h"
#include "mainWin.h"
#include "aMdiChild.h"
#include "editScrollWin.h"
#include "editView.h"

#include "cmdOpenFile.h"

using namespace aLib::aWin;
using namespace std;


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

                // create the mdiChild
                aMdiChild *pMdiChild = new aMdiChild();
                pMdiChild->create();
                addMdiChild(pMdiChild);
                pMdiChild->setMinSize(300, 200);
                pMdiChild->show();

                // create the scrollWin
                EditScrollWin *pScrollWin = new EditScrollWin;
                 pScrollWin->create();
                pScrollWin->setScrollBarPolicy(ScrollBarPolicy::ScrollBarAlwaysOn);
                pMdiChild->setCentralWin(pScrollWin);

                // // create the edit view
                // EditView *pEditView = new EditView(nullptr, pDoc);
                // pEditView->create();
                // //pScrollWin->setCentralWin(pEditView->ToSysWin());

                // //pMdiWin->setVisible(true);
                // pScrollWin->setVisible(true);
                // //pEditView->setVisible(true);

                // sendUpdateCmd(UPDATE_VIEW, pEditView);
            }
        } //case ID_FILE_OPEN

    } // switch (pCmd->id())

} // MainWin::onDoDone


/*******************************************************************************
* MainWin::onDropUrl
*******************************************************************************/
void MainWin::onDropUrl(const aUrl  &_url)
{
    aPath   path(_url.toLocalFile());

    //shared_ptr<CmdOpenFile> pCmd = make_shared<CmdOpenFile> (path, statusBar());
    shared_ptr<CmdOpenFile> pCmd = make_shared<CmdOpenFile> (path, nullptr);

    executeCmd(pCmd);
} // MainWin::onDropUrl


/*******************************************************************************
* MainWin::onUpdateCmd
*******************************************************************************/
void MainWin::onUpdateCmd(u64     _u64Cmd,
                          aDoc    */*_pDoc*/,
                          aView   *pView,
                          s64     /*_s64Param1*/,
                          s64     /*_s64Param2*/,
                          u64     /*_u64Param1*/,
                          u64     /*_u64Param2*/,
                          flt     /*_fltParam1*/,
                          flt     /*_fltParam2*/,
                          dbl     /*_dblParam1*/,
                          dbl     /*_dblParam2*/,
                          void    */*_pParam1*/,
                          void    */*_pParam2*/)
{
    if (isBitsSet(_u64Cmd, UPDATE_VIEW))
    {
        if (pView != nullptr)
        {
            //pView->repaint();
        }
    }
} // MainWin::onUpdateCmd
