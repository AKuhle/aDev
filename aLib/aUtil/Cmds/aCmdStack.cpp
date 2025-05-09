/*******************************************************************************
* \file aCmdStack.cpp
* \author Andreas Kuhlewind
*
* \brief
*
* Detailed description starts here.
*******************************************************************************/


/*******************************************************************************
* includes
*******************************************************************************/
#include "aCmdStack.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aUtil {


/*******************************************************************************
* aCmdStack::aCmdStack
*******************************************************************************/
aCmdStack::aCmdStack()
{
} // aCmdStack::aCmdStack


/*******************************************************************************
* aCmdStack::~aCmdStack
*******************************************************************************/
aCmdStack::~aCmdStack()
{
} // aCmdStack::~aCmdStack


/*******************************************************************************
* aCmdStack::executeCmd
*******************************************************************************/
void aCmdStack::executeCmd(shared_ptr<aCmdBase> _pCmd)
{
    CHECK_PRE_CONDITION_VOID(_pCmd != nullptr);

//        // if a snapshot is selected => all stack are clearee and
//        // the processing starts with the snapshot
////        if (m_pSelectedSnapshot != nullptr)
////        {
////            m_lstUndo.clear();
////            m_lstRedo.clear();
////        }

//        // unselect the snapshot
////        m_pSelectedSnapshot = nullptr;

    // set the command manager
    _pCmd->setCmdMgr(this);

    onCmdProcessingStart(_pCmd);
    m_lstUndo.push_back(std::move(_pCmd));
    m_lstUndo.back()->doPrepare();
} // aCmdStack::executeCmd


/*******************************************************************************
* aCmdStack::setCmd
*******************************************************************************/
void aCmdStack::setCmd(shared_ptr<aCmdBase> _pCmd)
{
    CHECK_PRE_CONDITION_VOID(_pCmd != nullptr);

    // unselect the snapshot
//        m_pSelectedSnapshot = nullptr;

    m_lstUndo.clear();
    m_lstRedo.clear();

    // set the command manager
    _pCmd->setCmdMgr(this);

    m_lstUndo.push_back(std::move(_pCmd));
} // aCmdStack::setCmd


/*******************************************************************************
* aCmdStack::activeCmd
*******************************************************************************/
aCmdBase* aCmdStack::activeCmd() const
{
//        if (IsSnapshotSelected())
//        {
//            return m_pSelectedSnapshot;
//        }
    /*else*/if (m_lstUndo.size() > 0)
    {
        return m_lstUndo.back().get();
    }
    else
    {
        return nullptr;
    }

} // qlCmdStack::activeCmd


/*******************************************************************************
* aCmdStack::AddSnapshot
*******************************************************************************/
//    void aCmdStack::AddSnapshot(std::shared_ptr<aCmdI>	_pCmd)
//    {
//        CHECK_PRE_CONDITION_VOID(_pCmd != nullptr);

//        m_lstSnapshot.push_back(_pCmd);
//    } // aCmdStack::AddSnapshot


/*******************************************************************************
* aCmdStack::SelectSnapshot
*******************************************************************************/
//    void aCmdStack::SelectSnapshot(std::shared_ptr<aCmdI> _pCmd)
//    {
//        m_pSelectedSnapshot = _pCmd;
//    } // aCmdStack::SelectSnapshot


/*******************************************************************************
* aCmdStack::undoList
*******************************************************************************/
const aSharedPtrList<aCmdBase>& aCmdStack::undoList() const
{
    return m_lstUndo;
} // aCmdStack::undoList


/*******************************************************************************
* aCmdStack::redoList
*******************************************************************************/
const aSharedPtrList<aCmdBase>& aCmdStack::redoList() const
{
    return m_lstRedo;
} // aCmdStack::redoList


/*******************************************************************************
* aCmdStack::canUndo
*******************************************************************************/
bool aCmdStack::canUndo() const
{
    return /*m_pSelectedSnapshot == nullptr &&*/
           m_lstUndo.size() > 0 &&
           m_lstUndo.back()->type() == enumCmdType::CMD_TYPE_UNDO;
} // aCmdStack::canUndo


/*******************************************************************************
* aCmdStack::canRedo
*******************************************************************************/
bool aCmdStack::canRedo() const
{
    return /*m_pSelectedSnapshot == nullptr &&*/
           m_lstRedo.size() > 0;
} // aCmdStack::canRedo


/*******************************************************************************
* aCmdStack::undoCmd
*******************************************************************************/
void aCmdStack::undoCmd()
{
    if (canUndo() /*&& m_pSelectedSnapshot == nullptr*/)
    {
        onCmdProcessingStart(m_lstUndo.back());
        m_lstUndo.back()->doUndo();
    }
} // aCmdStack::undoCmd


/*******************************************************************************
* aCmdStack::redoCmd
*******************************************************************************/
void aCmdStack::redoCmd()
{
    if (canRedo() /*&& m_pSelectedSnapshot == nullptr*/)
    {
        onCmdProcessingStart(m_lstRedo.back());
        m_lstRedo.back()->doRedo();
    }
} // aCmdStack::redoCmd


/*******************************************************************************
* aCmdStack::JumpToCmd
*******************************************************************************/
//    void aCmdStack::JumpToCmd(std::shared_ptr<aCmdI> _pCmd)
//    {
//        aSpList<aCmdI>::reverse_iterator rit;

//        if (m_lstUndo.Contains(_pCmd))
//        {
//            // check, whether all commands up to _pCmd can be undone
//            bool    bUndo = true;
//            for (rit = m_lstUndo.rbegin(); rit != m_lstUndo.rend(); rit++)
//            {
//                if ((*rit) == _pCmd)
//                {
//                    // we found the command -> undo is possible
//                    break;
//                }
//                else if ((*rit)->CmdType() == enumCmdType::CMD_TYPE_NO_UNDO)
//                {
//                    // command not reached, but a previous cmd can't be undone
//                    bUndo = false;
//                    break;
//                }
//            }

//            if (bUndo)
//            {
//                while (m_lstUndo.back() != _pCmd)
//                {
//                    m_lstRedo.push_back(m_lstUndo.back());
//                    m_lstUndo.pop_back();
//                }
//            }

//            // unselect the snapshot
//            m_pSelectedSnapshot = nullptr;
//        }
//        else if (m_lstRedo.Contains(_pCmd))
//        {
//            while (m_lstUndo.back() != _pCmd)
//            {
//                m_lstUndo.push_back(m_lstRedo.back());
//                m_lstRedo.pop_back();
//            }

//            // unselect the snapshot
//            m_pSelectedSnapshot = nullptr;
//        }
//    } // aCmdStack::JumpToCmd


/*******************************************************************************
* handler
*******************************************************************************/
void aCmdStack::onUndoDone(const shared_ptr<aCmdBase> &/*_pCmd*/) {}
void aCmdStack::onUndoFailed(const shared_ptr<aCmdBase> &/*_pCmd*/) {}

void aCmdStack::onRedoDone(const shared_ptr<aCmdBase> &/*_pCmd*/) {}
void aCmdStack::onRedoFailed(const shared_ptr<aCmdBase> &/*_pCmd*/) {}


/*******************************************************************************
* aCmdStack::manageCmd
*******************************************************************************/
void aCmdStack::manageCmd(enumCmdMsg    _eCmdMsg,
                          aCmdBase      *_pCmd,
                          bool          _bSuccess)
{
    // command can be in undo or redo list
    std::shared_ptr<aCmdBase> pCmd = m_lstUndo.find(_pCmd);
    if (pCmd == nullptr)
    {
        pCmd = m_lstRedo.find(_pCmd);
    }
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
                m_lstUndo.removeElement(pCmd);

                onCmdProcessingEnd(pCmd);
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

                // empty the redo stack
                m_lstRedo.clear();

                // remove undo steps > m_s32MaxUndo
                // m_s32MaxUndo steps => m_s32MaxUndo + 1 commands
                if (m_lstUndo.size() > m_s32MaxUndo + 1)
                {
                    while (m_lstUndo.size() > m_s32MaxUndo + 1)
                    {
                        m_lstUndo.pop_front();
                    }

                    // the new front cmd can not be undone
                    m_lstUndo.front()->setType(enumCmdType::CMD_TYPE_NO_UNDO);
                }

                onCmdProcessingEnd(pCmd);
            }
            else
            {
                // do failed
                onDoFailed(pCmd);
                m_lstUndo.removeElement(pCmd);

                onCmdProcessingEnd(pCmd);
            }
            break;
        } // case qCmd::MANAGE_CMD_DO

        case enumCmdMsg::Undo:
        {
            // pCmd must be at the back the undo stack
            if (pCmd == m_lstUndo.back())
            {
                if (_bSuccess)
                {
                    // undo succes => move the current undo-cmd to the redo stack
                    shared_ptr<aCmdBase> pCmd = m_lstUndo.getAndPopBack();
                    m_lstRedo.push_back(std::move(pCmd));

                    onUndoDone(m_lstRedo.back());

                    onCmdProcessingEnd(m_lstRedo.back());
                }
                else
                {
                    // undo failed => remove the cmd and clear the redo stack because
                    // the cmd chain is broken
                    onUndoFailed(pCmd);

                    m_lstUndo.pop_back();
                    m_lstRedo.clear();

                    onCmdProcessingEnd(pCmd);
                }
            } // if (pCmd == m_lstUndo.back())
            break;
        } // case enumCmdMsg::Undo

        case enumCmdMsg::Redo:
        {
            // pCmd must be at the back the redo stack
            if (pCmd == m_lstRedo.back())
            {
                if (_bSuccess)
                {
                    // redo succes => move the current redo-cmd to the undo stack
                    shared_ptr<aCmdBase> pCmd = m_lstRedo.getAndPopBack();
                    m_lstUndo.push_back(std::move(pCmd));

                    onRedoDone(m_lstUndo.back());

                    onCmdProcessingEnd(m_lstUndo.back());
                }
                else
                {
                    // redo failed => clear the redo stack because
                    // the cmd chain is broken
                    onRedoFailed(pCmd);

                    m_lstRedo.clear();

                    onCmdProcessingEnd(pCmd);
                }
            } // if (pCmd == m_lstRedo.back())
            break;
        } // case enumCmdMsg::Redo

    } // switch (_eManageCmd)

} // aCmdStack::manageCmd


} // namespace aUtil
} // namespace aLib
