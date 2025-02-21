/*******************************************************************************
* \file aCmdMgr.cpp
* \author Andreas Kuhlewind
*
* \brief
*
* Detailed description starts here.
*******************************************************************************/


/*******************************************************************************
* includes
*******************************************************************************/
#include "aCmdMgr.h"

using namespace std;


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aUtil {


/*******************************************************************************
* aCmdMgr::aCmdMgr
*******************************************************************************/
aCmdMgr::aCmdMgr()
{
} // aCmdMgr::aCmdMgr


/*******************************************************************************
* aCmdMgr::~aCmdMgr
*******************************************************************************/
aCmdMgr::~aCmdMgr()
{
} // aCmdMgr::~aCmdMgr


/*******************************************************************************
* aCmdMgr::executeCmd
*******************************************************************************/
void aCmdMgr::executeCmd(shared_ptr<aCmdBase> _pCmd)
{
    CHECK_PRE_CONDITION_VOID(_pCmd != nullptr);

    // set the command manager
    _pCmd->setCmdMgr(this);

    onCmdProcessingStart(_pCmd);
    m_lstCmds.push_back(std::move(_pCmd));
    m_lstCmds.back()->doPrepare();
} // aCmdMgr::executeCmd


/*******************************************************************************
* handler
*******************************************************************************/
void aCmdMgr::onCmdProcessingStart(const shared_ptr<aCmdBase> &/*_pCmd*/) {}
void aCmdMgr::onCmdProcessingEnd(const shared_ptr<aCmdBase> &/*_pCmd*/) {}

void aCmdMgr::onPrepareDone(const shared_ptr<aCmdBase> &/*_pCmd*/) {}
void aCmdMgr::onPrepareFailed(const shared_ptr<aCmdBase> &/*_pCmd*/) {}

void aCmdMgr::onDoDone(const shared_ptr<aCmdBase> &/*_pCmd*/) {}
void aCmdMgr::onDoFailed(const shared_ptr<aCmdBase> &/*_pCmd*/) {}


/*******************************************************************************
* aCmdMgr::manageCmd
*******************************************************************************/
void aCmdMgr::manageCmd(enumCmdMsg  _eCmdMsg,
                        aCmdBase    *_pCmd,
                        bool        _bSuccess)
{
    std::shared_ptr<aCmdBase>   pCmd = m_lstCmds.find(_pCmd);
    CHECK_PRE_CONDITION_VOID(pCmd != nullptr);

    switch (_eCmdMsg)
    {
        default:
            break;

        case enumCmdMsg::Prepare:
        {
            if (_bSuccess)
            {
                // cmd successfully perpared -> now do it
                onPrepareDone(pCmd);
                pCmd->doExecute();
            }
            else
            {
                // prepare failed => do failed
                onPrepareFailed(pCmd);
                onCmdProcessingEnd(pCmd);
                m_lstCmds.removeElement(pCmd);
            }
            break;
        }

        // do the Cmd => put the cmd on the top of the undo-stack
        case enumCmdMsg::Do:
        {
            if (_bSuccess)
            {
                // cmd successfully executed
                onDoDone(pCmd);
                onCmdProcessingEnd(pCmd);
                m_lstCmds.removeElement(pCmd);
            }
            else
            {
                // do failed
                onDoFailed(pCmd);
                onCmdProcessingEnd(pCmd);
                m_lstCmds.removeElement(pCmd);
            }
            break;
        } // case qCmd::MANAGE_CMD_DO

    } // switch (_eManageCmd)

} // aCmdMgr::manageCmd


} // namespace aUtil
} // namespace aLib
