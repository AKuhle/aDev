/*******************************************************************************
* \file qMainWin.cpp
* \author Andreas Kuhlewind
*
* \brief
*
*  Detailed description starts here.
*******************************************************************************/


/*******************************************************************************
* includes
*******************************************************************************/
#include "qMainWin.h"
#include "qLayoutMainWin.h"
#include "qTitleBar.h"
#include "qStatusBar.h"
#include "qBorderResizeTool.h"


namespace qLib
{
    /*******************************************************************************
    * qMainWin::qMainWin
    *******************************************************************************/
    qMainWin::qMainWin(qWin  *_pParent  /* = nullptr */)
    : qWin(_pParent)
    {
    } // qMainWin::qMainWin


    /*******************************************************************************
    * qMainWin::~qMainWin
    *******************************************************************************/
    qMainWin::~qMainWin()
    {
    } // qMainWin::~qMainWin


    /*******************************************************************************
    * qMainWin::OnSysCreate
    *******************************************************************************/
    bool qMainWin::OnSysCreate()
    {
        // create the title bar
        qTitleBar *pTitleBar = new qTitleBar(this);
        pTitleBar->CreateWin();

        // create the status bar
        qStatusBar *pStatusBar = new qStatusBar(this);
        pStatusBar->CreateWin();

        // create the layout
        unique_ptr<qLayoutMainWin> pLayout = make_unique<qLayoutMainWin> ();
        pLayout->SetTitleBar(pTitleBar);
        pLayout->SetStatusBar(pStatusBar);
        SetLayout(std::move(pLayout));

        // enable mouse tracking for border resize
        SetMouseTracking(true);

        // start the border resize tool
        unique_ptr<qBorderResizeTool> pTool = make_unique<qBorderResizeTool> (this);
        SetTool(std::move(pTool));

        return true;
    } // qMainWin::OnSysCreate


    /*******************************************************************************
    * qMainWin::GetCenterWin
    *******************************************************************************/
    qWin* qMainWin::GetCenterWin() const
    {
        qLayoutMainWin  *pLayout = dynamic_cast<qLayoutMainWin *> (GetLayout());
        CHECK_PRE_CONDITION(pLayout != nullptr, nullptr);

        return pLayout->GetCenterWin();
    } // qMainWin::GetCenterWin


    /*******************************************************************************
    * qMainWin::SetCenterWin
    *******************************************************************************/
    void qMainWin::SetCenterWin(qWin *_pWin)
    {
        qLayoutMainWin  *pLayout = dynamic_cast<qLayoutMainWin *> (GetLayout());
        CHECK_PRE_CONDITION_VOID(pLayout != nullptr);

        _pWin->SetParent(this);

        pLayout->SetCenterWin(_pWin);
    } // qMainWin::SetCenterWin


    /*******************************************************************************
    * qMainWin::SendUpdateCmd
    *******************************************************************************/
    void qMainWin::SendUpdateCmd(u64 _u64Cmd)
    {
        OnUpdateCmd(_u64Cmd, nullptr, nullptr, 0, 0, 0, 0, 0.0, 0.0, 0.0, 0.0, nullptr, nullptr);
    } // qMainWin::SendUpdateCmd


    /*******************************************************************************
    * qMainWin::SendUpdateCmd
    *******************************************************************************/
    void qMainWin::SendUpdateCmd(u64        _u64Cmd,
                                 qDocBase   *_pDoc)
    {
        OnUpdateCmd(_u64Cmd, _pDoc, nullptr, 0, 0, 0, 0, 0.0, 0.0, 0.0, 0.0, nullptr, nullptr);
    } // qMainWin::SendUpdateCmd


    /*******************************************************************************
    * qMainWin::SendUpdateCmd
    *******************************************************************************/
    void qMainWin::SendUpdateCmd(u64        _u64Cmd,
                                 qViewBase  *_pView)
    {
        OnUpdateCmd(_u64Cmd, nullptr, _pView, 0, 0, 0, 0, 0.0, 0.0, 0.0, 0.0, nullptr, nullptr);
    } // qMainWin::SendUpdateCmd


    /*******************************************************************************
    * qMainWin::SendUpdateCmd
    *******************************************************************************/
    void qMainWin::SendUpdateCmd(u64        _u64Cmd,
                                 qDocBase   *_pDoc,
                                 qViewBase  *_pView)
    {
        OnUpdateCmd(_u64Cmd, _pDoc, _pView, 0, 0, 0, 0, 0.0, 0.0, 0.0, 0.0, nullptr, nullptr);
    } // qMainWin::SendUpdateCmd


    /*******************************************************************************
    * qMainWin::SendUpdateCmd
    *******************************************************************************/
    void qMainWin::SendUpdateCmd(u64     _u64Cmd,
                                 s64     _s64Param1)
    {
        OnUpdateCmd(_u64Cmd, nullptr, nullptr, _s64Param1, 0, 0, 0, 0.0, 0.0, 0.0, 0.0, nullptr, nullptr);
    } // qMainWin::SendUpdateCmd


    /*******************************************************************************
    * qMainWin::SendUpdateCmd
    *******************************************************************************/
    void qMainWin::SendUpdateCmd(u64     _u64Cmd,
                                 s64     _s64Param1,
                                 s64     _s64Param2)
    {
        OnUpdateCmd(_u64Cmd, nullptr, nullptr, _s64Param1, _s64Param2, 0, 0, 0.0, 0.0, 0.0, 0.0, nullptr, nullptr);
    } // qMainWin::SendUpdateCmd


    /*******************************************************************************
    * qMainWin::SendUpdateCmd
    *******************************************************************************/
    void qMainWin::SendUpdateCmd(u64     _u64Cmd,
                                 u64     _u64Param1)
    {
        OnUpdateCmd(_u64Cmd, nullptr, nullptr, 0, 0, _u64Param1, 0, 0.0, 0.0, 0.0, 0.0, nullptr, nullptr);
    } // qMainWin::SendUpdateCmd


    /*******************************************************************************
    * qMainWin::SendUpdateCmd
    *******************************************************************************/
    void qMainWin::SendUpdateCmd(u64     _u64Cmd,
                                 u64     _u64Param1,
                                 u64     _u64Param2)
    {
        OnUpdateCmd(_u64Cmd, nullptr, nullptr, 0, 0, _u64Param1, _u64Param2, 0.0, 0.0, 0.0, 0.0, nullptr, nullptr);
    } // qMainWin::SendUpdateCmd


    /*******************************************************************************
    * qMainWin::OnSetCursor
    *******************************************************************************/
    void qMainWin::OnSetCursor()
    {
        // overwrite to avoid cursor flickering
        // otherwise the arrow cursor is beeing seen for a very short while
    } // qMainWin::OnSetCursor


} // namespace qLib
