/*******************************************************************************
* \file MainWin_cmd.cpp
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
#include "defsPl.h"
#include "mainWin.h"
#include "docPl.h"
#include "viewStd.h"
#include "stdMdiWin.h"


/*******************************************************************************
* MainWin::OnCmdProcessingStart
*******************************************************************************/
void MainWin::OnCmdProcessingStart(qCmdI */*_pCmd*/)
{
    SendUpdateCmd(UPDATE_CMD_PROCESSING_START);
} // MainWin::OnCmdProcessingStart


/*******************************************************************************
* MainWin::OnCmdProcessingEnd
*******************************************************************************/
void MainWin::OnCmdProcessingEnd(qCmdI */*_pCmd*/)
{
    SendUpdateCmd(UPDATE_CMD_PROCESSING_END);
} // MainWin::OnCmdProcessingEnd


/*******************************************************************************
* MainWin::OnDoDone
*******************************************************************************/
void MainWin::OnDoDone(qCmdI *_pCmd)
{
    cout << __PRETTY_FUNCTION__ << endl;

    switch (_pCmd->CmdId())
    {
        case ID_FILE_OPEN:
        {
            // get ownership over the cmd and create the doc/view
            CreateDocView(std::move(TakeCmdCtrl(_pCmd)));

            break;
        } // case ID_OPEN_FILE

    } // switch (_pCmd->CmdId())

} // MainWin::OnDoDone


/*******************************************************************************
* MainWin::CreateDocView
*******************************************************************************/
void MainWin::CreateDocView(std::unique_ptr<qCmdI> _pCmd)
{
    if (_pCmd != nullptr)
    {
        // qMdiWin *pMdiArea = new qMdiWin();
        // AddMdiWin(pMdiArea);
        // pMdiArea->SetGeometry(50, 50, 300, 200);

        // create a document
        shared_ptr<DocPl>   pDoc = make_shared<DocPl> (std::move(_pCmd));

        // create the mdiWin
        StdMdiWin *pStdMdiWin = new StdMdiWin(this);
        pStdMdiWin->CreateWin();

        // create a standard view
        ViewStd *pView = new ViewStd(nullptr, pDoc);
        pView->CreateWin();
        pStdMdiWin->SetView(pView);

        // finally add the mdi win
        // this must be the final step to ensure, that there is a view
        // during the onActivateMdiWin process
        AddMdiWin(pStdMdiWin);
        pStdMdiWin->SetGeometry(50, 50, 300, 200);
    } // if (pCmd != nullptr)

} // MainWin::CreateDocView
