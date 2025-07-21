/*******************************************************************************
* \file aCmdThread.cpp
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
#include "aCmdThread.h"
#include "aCmdMgr.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aFrame {
namespace aUtil {


/*******************************************************************************
* aCmdThread::aCmdThread
*******************************************************************************/
aCmdThread::aCmdThread(s32              _s32Id,
                       const aString    &_sName,
                       enumCmdType      _eType)
: aCmdBase(_s32Id, _sName, _eType)
{
    //cout << __PRETTY_FUNCTION__ << ": " << this << endl;
} // aCmdThread::aCmdThread


/*******************************************************************************
* aCmdThread::~aCmdThread
*******************************************************************************/
aCmdThread::~aCmdThread()
{
    //cout << __PRETTY_FUNCTION__ << ": " << this << endl;
} // aCmdThread::~aCmdThread


/*******************************************************************************
* aCmdThread::doPrepare
*******************************************************************************/
void aCmdThread::doPrepare()
{
    m_eCmdMsg = enumCmdMsg::Prepare;
    CmdWorkerThread *pWorker = new CmdWorkerThread (this, m_eCmdMsg, m_bSuccess);
    pWorker->startThread();
} // aCmdThread::doPrepare


/*******************************************************************************
* aCmdThread::doExecute
*******************************************************************************/
void aCmdThread::doExecute()
{
    m_eCmdMsg = enumCmdMsg::Do;
    CmdWorkerThread *pWorker = new CmdWorkerThread (this, m_eCmdMsg, m_bSuccess);
    pWorker->startThread();
} // aCmdThread::doExecute


/*******************************************************************************
* aCmdThread::doUndo
*******************************************************************************/
void aCmdThread::doUndo()
{
    m_eCmdMsg = enumCmdMsg::Undo;
    CmdWorkerThread *pWorker = new CmdWorkerThread (this, m_eCmdMsg, m_bSuccess);
    pWorker->startThread();
} // aCmdThread::doUndo


/*******************************************************************************
* aCmdThread::doRedo
*******************************************************************************/
void aCmdThread::doRedo()
{
    m_eCmdMsg = enumCmdMsg::Redo;
    CmdWorkerThread *pWorker = new CmdWorkerThread (this, m_eCmdMsg, m_bSuccess);
    pWorker->startThread();
} // aCmdThread::doRedo


/*******************************************************************************
* aCmdThread::onThreadStarted
*******************************************************************************/
void aCmdThread::onThreadStarted(u32 /*_u32ThreadID*/)
{
    //cout << __FUNCTION__ << " - " << this << endl;
} // aCmdThread::onThreadStarted


/*******************************************************************************
* aCmdThread::onThreadFinished
*******************************************************************************/
void aCmdThread::onThreadFinished(u32 /*_u32ThreadID*/)
{
    //cout << __FUNCTION__ << " - " << this << endl;
    cmdMgr()->manageCmd(m_eCmdMsg, this, m_bSuccess);
} // aCmdThread::onThreadFinished


/*******************************************************************************
* CmdWorkerThread::CmdWorkerThread
*******************************************************************************/
CmdWorkerThread::CmdWorkerThread(aCmdThread *_pCmd,
                                 enumCmdMsg _eCmdMsg,
                                 bool       &_bSuccess)
: aThread(0, _pCmd),
  m_pCmd(_pCmd),
  m_eCmdMsg(_eCmdMsg),
  m_bSuccess(_bSuccess)
{
    //cout << __PRETTY_FUNCTION__ << ": " << this << endl;
} // CmdWorkerThread::CmdWorkerThread


/*******************************************************************************
* CmdWorkerThread::~CmdWorkerThread
*******************************************************************************/
CmdWorkerThread::~CmdWorkerThread()
{
    //cout << __PRETTY_FUNCTION__ << ": " << this << endl;
} // CmdWorkerThread::~CmdWorkerThread


/*******************************************************************************
* CmdWorkerThread::onRun
*******************************************************************************/
void CmdWorkerThread::onRun()
{
    switch (m_eCmdMsg)
    {
        case enumCmdMsg::Prepare:
            m_bSuccess = m_pCmd->prepare();
            break;

        case enumCmdMsg::Do:
            m_bSuccess = m_pCmd->execute();
            break;

        case enumCmdMsg::Undo:
            m_bSuccess = m_pCmd->undo();
            break;

        case enumCmdMsg::Redo:
            m_bSuccess = m_pCmd->redo();
            break;
    }
} // CmdWorkerThread::onRun


} // namespace aUtil
} // namespace aFrame
