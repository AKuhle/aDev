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
#include "defsPl.h"
#include "mainWin.h"
#include "toolBoxToolWin.h"
#include "navigatorToolWin.h"
#include "protocolToolWin.h"
#include "stdMdiWin.h"
#include "viewStd.h"
#include "docPl.h"
#include "stdScrollWin.h"


using namespace qLib;


/*******************************************************************************
* MainWin::OnUpdate
*******************************************************************************/
void MainWin::OnUpdateCmd(u64    _u64Cmd,
                          qDocI  *_pDoc,
                          qViewI *_pView,
                          s64    /*_s64Param1*/,
                          s64    /*_s64Param2*/,
                          u64    /*_u64Param1*/,
                          u64    /*_u64Param2*/,
                          flt    /*_fltParam1*/,
                          flt    /*_fltParam2*/,
                          dbl    /*_dblParam1*/,
                          dbl    /*_dblParam2*/,
                          void   */*_pParam1*/,
                          void   */*_pParam2*/)
{
    // cmd processing started
    if (BitsSet(_u64Cmd, UPDATE_CMD_PROCESSING_START))
    {
        m_bCalculating = true;
        _u64Cmd |= UPDATE_GUI;
    } // UPDATE_CMD_PROCESSING_START

    // cmd processing ended
    if (BitsSet(_u64Cmd, UPDATE_CMD_PROCESSING_END))
    {
        m_bCalculating = false;
        _u64Cmd |= UPDATE_GUI;
    } // UPDATE_CMD_PROCESSING_END

    // cmd processing ended
    if (BitsSet(_u64Cmd, UPDATE_MODE_CHANGED))
    {
        UpdateTools();
        _u64Cmd |= UPDATE_GUI;
    } // UPDATE_MODE_CHANGED

    // view has been activated
    if (BitsSet(_u64Cmd, UPDATE_VIEW_ACTVATED))
    {
        UpdateTools();
        _u64Cmd |= UPDATE_GUI;
    } // UPDATE_VIEW_ACTVATED

    // UPDATE_SCALE_CHANGED
    // e.g. resize, zomm changed
    if (BitsSet(_u64Cmd, UPDATE_SCALE_CHANGED))
    {
        StdScrollWin *pSW = dynamic_cast<StdScrollWin *> (_pView->Parent());

        if (pSW != nullptr)
        {
            pSW->UpdateScrollbars();
        }
    } // UPDATE_SCALE_CHANGED

    // update one view
    // _pView = view to update
    if (BitsSet(_u64Cmd, UPDATE_VIEW))
    {
        if (_pView != nullptr)
            _pView->Update();
    } // UPDATE_VIEW

    // update all views
    if (BitsSet(_u64Cmd, UPDATE_ALL_VIEWS))
    {
        // get all mdi win
        qPtrList<qMdiWin> lstMdiWin;
        GetMdiWinList(lstMdiWin);

        for (qMdiWin *pMdiWin : lstMdiWin)
        {
            StdMdiWin   *pStdMdiWin = dynamic_cast<StdMdiWin *> (pMdiWin);
            ViewStd     *pView      = (pStdMdiWin != nullptr)?   pStdMdiWin->StdView() : nullptr;

            if (pView != nullptr)
            {
                pView->Update();
            }
        }
    } // UPDATE_ALL_VIEWS

    // update all views with a given document
    if (BitsSet(_u64Cmd, UPDATE_VIEWS_BY_DOC))
    {
        // get all mdi win
        qPtrList<qMdiWin> lstMdiWin;
        GetMdiWinList(lstMdiWin);

        for (qMdiWin *pMdiWin : lstMdiWin)
        {
            StdMdiWin   *pStdMdiWin = dynamic_cast<StdMdiWin *> (pMdiWin);
            ViewStd     *pView      = (pStdMdiWin != nullptr)?   pStdMdiWin->StdView() : nullptr;

            if (pView != nullptr)
            {
                shared_ptr<DocPl> pDoc = pView->Doc();

                if (pDoc.get() == _pDoc)
                {
                    pView->Update();
                }
            }
        }
    } // UPDATE_VIEWS_BY_DOC

    // update the user interface
    if (BitsSet(_u64Cmd, UPDATE_GUI))
    {
        // update all ctrls
        UpdateAllCtrls();
    } // UPDATE_GUI

    // update the option dlg
    if (BitsSet(_u64Cmd, UPDATE_OPTION_DLG) || BitsSet(_u64Cmd, UPDATE_GUI))
    {
        ToolWin *pToolWin = dynamic_cast<ToolWin *> (m_pOptionDockWin->TitleBarWin());

        // update the toolbox
        if (pToolWin != nullptr)
        {
            pToolWin->UpdateToolWin();
        }
    } // UPDATE_TOOLBOX_DLG

    // update the toolbox dlg
    if (BitsSet(_u64Cmd, UPDATE_TOOLBOX_DLG) || BitsSet(_u64Cmd, UPDATE_GUI))
    {
        // update the toolbox
        if (m_pToolBoxToolWin != nullptr)
        {
            m_pToolBoxToolWin->UpdateToolWin();
        }
    } // UPDATE_TOOLBOX_DLG

    // update the navigator dlg
    if (BitsSet(_u64Cmd, UPDATE_NAVIGATOR_DLG) || BitsSet(_u64Cmd, UPDATE_GUI))
    {
        // update the toolbox
        if (m_pNavigatorToolWin != nullptr)
        {
            m_pNavigatorToolWin->UpdateToolWin();
        }
    } // UPDATE_NAVIGATOR_DLG

    // update the protocol dlg
    if (BitsSet(_u64Cmd, UPDATE_PROTOCOL_DLG) || BitsSet(_u64Cmd, UPDATE_GUI))
    {
        // update the toolbox
        if (m_pProtocolToolWin != nullptr)
        {
            m_pProtocolToolWin->UpdateToolWin();
        }
    } // UPDATE_PROTOCOL_DLG

} // MainWin::OnUpdate
