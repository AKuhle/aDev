/*******************************************************************************
* \file qCmdThread.cpp
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
#include "qCmdThread.h"
#include "qCmdMgr.h"


namespace qLib
{
    /*******************************************************************************
    * qCmdThread::qCmdThread
    *******************************************************************************/
    qCmdThread::qCmdThread(s32              _s32CmdId,
                           const qString16& _sCmdName,
                           enumCmdType      _eCmdType,
                           qProgress        *_pProgress)
    : qCmdI(_s32CmdId, _sCmdName, _eCmdType, _pProgress)
    {
    } // qCmdThread::qCmdThread


    /*******************************************************************************
    * qCmdThread::~qCmdThread
    *******************************************************************************/
    qCmdThread::~qCmdThread()
    {
    } // qCmdThread::~qCmdThread


    /*******************************************************************************
    * qCmdThread::DoPrepare
    *******************************************************************************/
    void qCmdThread::DoPrepare()
    {
        m_eCmdMsg = enumCmdMsg::Prepare;
        CmdWorkerThread *pWorker = new CmdWorkerThread (this, m_eCmdMsg, m_bSuccess);
        pWorker->StartThread();
    } // qCmdThread::DoPrepare


    /*******************************************************************************
    * qCmdThread::DoDo
    *******************************************************************************/
    void qCmdThread::DoDo()
    {
        m_eCmdMsg = enumCmdMsg::Do;
        CmdWorkerThread *pWorker = new CmdWorkerThread (this, m_eCmdMsg, m_bSuccess);
        pWorker->StartThread();
    } // qCmdThread::DoDo


    /*******************************************************************************
    * qCmdThread::DoUndo
    *******************************************************************************/
    void qCmdThread::DoUndo()
    {
        m_eCmdMsg = enumCmdMsg::Undo;
        CmdWorkerThread *pWorker = new CmdWorkerThread (this, m_eCmdMsg, m_bSuccess);
        pWorker->StartThread();
    } // qCmdThread::DoUndo


    /*******************************************************************************
    * qCmdThread::DoRedo
    *******************************************************************************/
    void qCmdThread::DoRedo()
    {
        m_eCmdMsg = enumCmdMsg::Redo;
        CmdWorkerThread *pWorker = new CmdWorkerThread (this, m_eCmdMsg, m_bSuccess);
        pWorker->StartThread();
    } // qCmdThread::DoRedo


    /*******************************************************************************
    * qCmdThread::OnThreadStarted
    *******************************************************************************/
    void qCmdThread::OnThreadStarted(u32 /*_u32ThreadID*/)
    {
        //cout << __FUNCTION__ << " - " << this << endl;
    } // qCmdThread::OnThreadStarted


    /*******************************************************************************
    * qCmdThread::OnThreadFinished
    *******************************************************************************/
    void qCmdThread::OnThreadFinished(u32 /*_u32ThreadID*/)
    {
        //cout << __FUNCTION__ << " - " << this << endl;
        CmdMgr()->ManageCmd(m_eCmdMsg, this, m_bSuccess);
    } // qCmdThread::OnThreadFinished



    /*******************************************************************************
    * CmdWorkerThread::CmdWorkerThread
    *******************************************************************************/
    CmdWorkerThread::CmdWorkerThread(qCmdThread*    _pCmd,
                                     enumCmdMsg     _eCmdMsg,
                                     bool&          _bSuccess)
    : qThread(0, _pCmd),
      m_pCmd(_pCmd),
      m_eCmdMsg(_eCmdMsg),
      m_bSuccess(_bSuccess)
    {
        cout << __PRETTY_FUNCTION__ << ": " << this << endl;
    } // CmdWorkerThread::CmdWorkerThread


    /*******************************************************************************
    * CmdWorkerThread::~CmdWorkerThread
    *******************************************************************************/
    CmdWorkerThread::~CmdWorkerThread()
    {
        cout << __PRETTY_FUNCTION__ << ": " << this << endl;
    } // CmdWorkerThread::~CmdWorkerThread


    /*******************************************************************************
    * CmdWorkerThread::OnRun
    *******************************************************************************/
    void CmdWorkerThread::OnRun()
    {
        switch (m_eCmdMsg)
        {
            case enumCmdMsg::Prepare:
                m_bSuccess = m_pCmd->Prepare();
                break;

            case enumCmdMsg::Do:
                m_bSuccess = m_pCmd->Do();
                break;

            case enumCmdMsg::Undo:
                m_bSuccess = m_pCmd->Undo();
                break;

            case enumCmdMsg::Redo:
                m_bSuccess = m_pCmd->Redo();
                break;
        }
    } // CmdWorkerThread::OnRun


} // namespace qLib
