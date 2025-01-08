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
#include "qPhotoLabDefs.h"
#include "mainWin.h"
#include "doc.h"
#include "viewStd.h"
#include "scrollWin.h"


using namespace qLib;


/*******************************************************************************
* MainWin::OnUpdateCmd
*******************************************************************************/
void MainWin::OnUpdateCmd(u64         _u64Cmd,
                          qDocBase    */*_pDoc*/,
                          qViewBase   *_pView,
                          s64         /*_s64Param1*/,
                          s64         /*_s64Param2*/,
                          u64         /*_u64Param1*/,
                          u64         /*_u64Param2*/,
                          flt         /*/*_fltParam1*/,
                          flt         /*_fltParam2*/,
                          dbl         /*_dblParam1*/,
                          dbl         /*_dblParam2*/,
                          void        */*_pParam1*/,
                          void        */*_pParam2*/)
{
    // UPDATE_VIEW
    if (MU<u64>::AreBitsSet(_u64Cmd, UPDATE_VIEW))
    {
        if (_pView != nullptr)
        {
            _pView->Update();
        }
    }

    // UPDATE_GUI
    if (MU<u64>::AreBitsSet(_u64Cmd, UPDATE_GUI))
    {

    }
} // MainWin::OnUpdateCmd


/*******************************************************************************
* MainWin::OnDropUrl
*******************************************************************************/
void MainWin::OnDropUrl(const qUrl  &_url)
{
    if (_url.IsLocalFile())
    {
        OpenFile(_url.ToLocalFile());
    }
} // MainWin::OnDropUrl


/*******************************************************************************
* MainWin::OnDoDone
*******************************************************************************/
void MainWin::OnDoDone(qCmdBase *_pCmd)
{
    switch (_pCmd->GetCmdId())
    {
        case ID_FILE_OPEN:
        {
            qRect2D<s32>    r2dContent = GetContentRect();

            // create a new mdi child
            qMdiChild   *pMdiChild = new qMdiChild();
            pMdiChild->CreateWin();
            AddMdiChild(pMdiChild);
            pMdiChild->SetMinSize(150, 100);

            // create the scroll win -> center win of the mdi-child
            ScrollWin *pScrollWin = new ScrollWin(pMdiChild);
            pScrollWin->CreateWin();
            pMdiChild->SetCenterWin(pScrollWin); // todo: must be closed

            // create the document
            unique_ptr<qCmdBase> pCmd = TakeCmdCtrl(_pCmd);
            shared_ptr<Doc> pDoc = make_shared<Doc> (std::move(pCmd));

            // create the view
            ViewStd *pView = new ViewStd(pScrollWin, pDoc);
            pView->CreateWin();
            pScrollWin->SetCenterWin(pView); // todo: must be closed

            // set the initial size
            pMdiChild->SetGeometry(r2dContent.x + 50, r2dContent.y + 50,
                                   pMdiChild->GetMinSize().w, pMdiChild->GetMinSize().h);

            // initialize the view
            pView->SetZoomFactor(1);
        }
    }

} // MainWin::OnDoDone
