/*******************************************************************************
* \file qMdiChild.cpp
* \author Andreas Kuhlewind
*
* \brief
*
*  Detailed description starts here.
*******************************************************************************/


/*******************************************************************************
* includes
*******************************************************************************/
#include "qMdiChild.h"
#include "qLayoutMainWin.h"
#include "qTitleBar.h"
#include "qStatusBar.h"
#include "qBorderResizeTool.h"


namespace qLib
{
    /*******************************************************************************
    * qMdiChild::qMdiChild
    *******************************************************************************/
    qMdiChild::qMdiChild(qWin  *_pParent  /* = nullptr */)
    : qWin(_pParent)
    {
    } // qMdiChild::qMdiChild


    /*******************************************************************************
    * qMdiChild::~qMdiChild
    *******************************************************************************/
    qMdiChild::~qMdiChild()
    {
    } // qMdiChild::~qMdiChild


    /*******************************************************************************
    * qMdiChild::OnSysCreate
    *******************************************************************************/
    bool qMdiChild::OnSysCreate()
    {
        // create the title bar
        qTitleBar *pTitleBar = new qTitleBar(this);
        pTitleBar->CreateWin();

        // create the layout
        unique_ptr<qLayoutMainWin> pLayout = make_unique<qLayoutMainWin> ();
        pLayout->SetTitleBar(pTitleBar);
        SetLayout(std::move(pLayout));

        // enable mouse tracking for border resize
        SetMouseTracking(true);

        // start the border resize tool
        unique_ptr<qBorderResizeTool> pTool = make_unique<qBorderResizeTool> (this);
        SetTool(std::move(pTool));

        return true;
    } // qMdiChild::OnSysCreate


    /*******************************************************************************
    * qMdiChild::GetCenterWin
    *******************************************************************************/
    qWin* qMdiChild::GetCenterWin() const
    {
        qLayoutMainWin  *pLayout = dynamic_cast<qLayoutMainWin *> (GetLayout());
        CHECK_PRE_CONDITION(pLayout != nullptr, nullptr);

        return pLayout->GetCenterWin();
    } // qMdiChild::GetCenterWin


    /*******************************************************************************
    * qMdiChild::SetCenterWin
    *******************************************************************************/
    void qMdiChild::SetCenterWin(qWin *_pWin)
    {
        qLayoutMainWin  *pLayout = dynamic_cast<qLayoutMainWin *> (GetLayout());
        CHECK_PRE_CONDITION_VOID(pLayout != nullptr);

        _pWin->SetParent(this);

        pLayout->SetCenterWin(_pWin);
    } // qMdiChild::SetCenterWin


    /*******************************************************************************
    * qMdiChild::Activate
    *******************************************************************************/
    void qMdiChild::Activate(bool _bActive)
    {
        qLayoutMainWin  *pLayout = dynamic_cast<qLayoutMainWin *> (GetLayout());
        CHECK_PRE_CONDITION_VOID(pLayout != nullptr);

        qTitleBar       *pTB    = pLayout->GetTitleBar();
        CHECK_PRE_CONDITION_VOID(pTB != nullptr);

        if (pTB->IsActive() != _bActive)
        {
            pTB->SetActive(_bActive);
            pTB->Update();
        }
    } // qMdiChild::Activate


    /*******************************************************************************
    * qMdiChild::OnSetCursor
    *******************************************************************************/
    void qMdiChild::OnSetCursor()
    {
        // overwrite to avoid cursor flickering
        // otherwise the arrow cursor is beeing seen for a very short while
    } // qMdiChild::OnSetCursor


} // namespace qLib
