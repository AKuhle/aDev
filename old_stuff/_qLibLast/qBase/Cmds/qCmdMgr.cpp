/*******************************************************************************
* \file qCmdMgr.cpp
* \author Andreas Kuhlewind
*
* \brief
*
* Detailed description starts here.
*******************************************************************************/


/*******************************************************************************
* includes
*******************************************************************************/
#include "qCmdMgr.h"
#include "qCmd_i.h"

using namespace std;


namespace qLib
{
    /*******************************************************************************
    * qCmdMgr::qCmdMgr
    *******************************************************************************/
    qCmdMgr::qCmdMgr()
    {
    } // qCmdMgr::qCmdMgr


    /*******************************************************************************
    * qCmdMgr::~qCmdMgr
    *******************************************************************************/
    qCmdMgr::~qCmdMgr()
    {
    } // qCmdMgr::~qCmdMgr


    /*******************************************************************************
    * qCmdMgr::ExecuteCmd
    *******************************************************************************/
    void qCmdMgr::ExecuteCmd(unique_ptr<qCmdI> _pCmd)
    {
        CHECK_PRE_CONDITION_VOID(_pCmd != nullptr);

        // set the command manager
        _pCmd->SetCmdMgr(this);

        OnCmdProcessingStart(_pCmd.get());
        m_lstCmds.push_back(std::move(_pCmd));
        m_lstCmds.back()->DoPrepare();

    } // qCmdMgr::ExecuteCmd


    /*******************************************************************************
    * qCmdMgr::TakeCmdCtrl
    *******************************************************************************/
    unique_ptr<qCmdI> qCmdMgr::TakeCmdCtrl(qCmdI *_pCmd)
    {
        unique_ptr<qCmdI> pCmd = m_lstCmds.FindAndRemove(_pCmd);

        return pCmd;
    } // qCmdMgr::TakeCmdCtrl


    /*******************************************************************************
    * handler
    *******************************************************************************/
    void qCmdMgr::OnCmdProcessingStart(qCmdI */*_pCmd*/) {}
    void qCmdMgr::OnCmdProcessingEnd(qCmdI */*_pCmd*/) {}

    void qCmdMgr::OnPrepareDone(qCmdI */*_pCmd*/) {}
    void qCmdMgr::OnPrepareFailed(qCmdI */*_pCmd*/) {}

    void qCmdMgr::OnDoDone(qCmdI */*_pCmd*/) {}
    void qCmdMgr::OnDoFailed(qCmdI */*_pCmd*/) {}


    /*******************************************************************************
    * qCmdMgr::ManageCmd
    *******************************************************************************/
    void qCmdMgr::ManageCmd(enumCmdMsg  _eCmdMsg,
                            qCmdI       *_pCmd,
                            bool        _bSuccess)
    {
        switch (_eCmdMsg)
        {
            default:
                break;

            case enumCmdMsg::Prepare:
            {
                if (_bSuccess)
                {
                    // cmd successfully perpared -> now do it
                    OnPrepareDone(_pCmd);
                    _pCmd->DoDo();
                }
                else
                {
                    // prepare failed => do failed
                    OnPrepareFailed(_pCmd);
                    OnCmdProcessingEnd(_pCmd);
                    m_lstCmds.RemoveElement(_pCmd);
                }
                break;
            }

            // do the Cmd => put the cmd on the top of the undo-stack
            case enumCmdMsg::Do:
            {
                if (_bSuccess)
                {
                    // cmd successfully executed
                    OnDoDone(_pCmd);
                    OnCmdProcessingEnd(_pCmd);
                    m_lstCmds.RemoveElement(_pCmd);
                }
                else
                {
                    // do failed
                    OnDoFailed(_pCmd);
                    OnCmdProcessingEnd(_pCmd);
                    m_lstCmds.RemoveElement(_pCmd);
                }
                break;
            } // case qCmd::MANAGE_CMD_DO

        } // switch (_eManageCmd)

    } // qCmdMgr::ManageCmd

} // namespace qLib
