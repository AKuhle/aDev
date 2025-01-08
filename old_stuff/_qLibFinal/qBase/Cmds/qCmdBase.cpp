/*******************************************************************************
* \file qCmdBase.cpp
* \author Andreas Kuhlewind
*
* \brief
*
*  Detailed description starts here.
*******************************************************************************/


/*******************************************************************************
* includes
*******************************************************************************/
#include "qCmdBase.h"



namespace qLib
{
    /*******************************************************************************
    * qCmdBase::qCmdBase
    *******************************************************************************/
    qCmdBase::qCmdBase(s32                _s32CmdId,
                       const qString16    &_sCmdName,
                       enumCmdType        _eCmdType,
                       qProgress          *_pProgress)
    : m_s32CmdId(_s32CmdId),
      m_sCmdName(_sCmdName),
      m_eCmdType(_eCmdType),
      m_pProgress(_pProgress)
    {
    } // qCmdBase::qCmdBase


    /*******************************************************************************
    * qCmdBase::qCmdBase
    *******************************************************************************/
    qCmdBase::~qCmdBase()
    {
    } // qCmdBase::~qCmdBase


    /*******************************************************************************
    * qCmdBase::SetCmdMgr
    *******************************************************************************/
    void qCmdBase::SetCmdMgr(qCmdMgr* _pCmdMgr)
    {
        m_pCmdMgr = _pCmdMgr;
    } // qCmdBase::SetCmdMgr


    /*******************************************************************************
    * qCmdBase::GetCmdMgr
    *******************************************************************************/
    qCmdMgr* qCmdBase::GetCmdMgr() const
    {
        return m_pCmdMgr;
    } // qCmdBase::GetCmdMgr


    /*******************************************************************************
    * qCmdBase::GetProgress
    *******************************************************************************/
    qProgress* qCmdBase::GetProgress() const
    {
        return m_pProgress;
    } // qCmdBase::GetProgress


    /*******************************************************************************
    * qCmdBase::GetCmdId
    *******************************************************************************/
    s32 qCmdBase::GetCmdId() const
    {
        return m_s32CmdId;
    } // qCmdBase::GetCmdId


    /*******************************************************************************
    * qCmdBase::GetCmdName
    *******************************************************************************/
    const qString16& qCmdBase::GetCmdName() const
    {
        return m_sCmdName;
    } // qCmdBase::CmdName


    /*******************************************************************************
    * qCmdBase::CmdType
    *******************************************************************************/
    enumCmdType qCmdBase::GetCmdType() const
    {
        return m_eCmdType;
    } // qCmdBase::CmdType


    /*******************************************************************************
    * qCmdBase::CanUndo
    *******************************************************************************/
    bool qCmdBase::CanUndo() const
    {
        return (m_eCmdType == enumCmdType::CMD_TYPE_UNDO);
    } // qCmdBase::CanUndo

} // namespace qLib
