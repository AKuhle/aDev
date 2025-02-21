/*******************************************************************************
* \file qCmdStack.cpp
* \author Andreas Kuhlewind
*
* \brief
*
* Detailed description starts here.
*******************************************************************************/


/*******************************************************************************
* includes
*******************************************************************************/
#include "qCmdStack.h"
#include "qCmd_i.h"

using namespace std;


namespace qLib
{
    /*******************************************************************************
    * qCmdStack::qCmdStack
    *******************************************************************************/
    qCmdStack::qCmdStack()
    {
    } // qCmdStack::qCmdStack


    /*******************************************************************************
    * qCmdStack::~qCmdStack
    *******************************************************************************/
    qCmdStack::~qCmdStack()
    {
    } // qCmdStack::~qCmdStack


    /*******************************************************************************
    * qCmdStack::ExecuteCmd
    *******************************************************************************/
    void qCmdStack::ExecuteCmd(unique_ptr<qCmdI> _pCmd)
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
        _pCmd->SetCmdMgr(this);

        OnCmdProcessingStart(_pCmd.get());
        m_lstUndo.push_back(std::move(_pCmd));
        m_lstUndo.back()->DoPrepare();
    } // qCmdStack::ExecuteCmd


    /*******************************************************************************
    * qCmdStack::SetCmd
    *******************************************************************************/
    void qCmdStack::SetCmd(unique_ptr<qCmdI> _pCmd)
    {
        CHECK_PRE_CONDITION_VOID(_pCmd != nullptr);

        // unselect the snapshot
//        m_pSelectedSnapshot = nullptr;

        // set the command manager
        _pCmd->SetCmdMgr(this);

        m_lstUndo.clear();
        m_lstRedo.clear();

        m_lstUndo.push_back(std::move(_pCmd));
    } // qCmdStack::SetCmd


    /*******************************************************************************
    * qCmdStack::ActiveCmd
    *******************************************************************************/
    qCmdI* qCmdStack::ActiveCmd() const
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

    } // qlCmdStack::ActiveCmd


    /*******************************************************************************
    * qCmdStack::AddSnapshot
    *******************************************************************************/
//    void qCmdStack::AddSnapshot(std::shared_ptr<aCmdI>	_pCmd)
//    {
//        CHECK_PRE_CONDITION_VOID(_pCmd != nullptr);

//        m_lstSnapshot.push_back(_pCmd);
//    } // qCmdStack::AddSnapshot


    /*******************************************************************************
    * qCmdStack::SelectSnapshot
    *******************************************************************************/
//    void qCmdStack::SelectSnapshot(std::shared_ptr<aCmdI> _pCmd)
//    {
//        m_pSelectedSnapshot = _pCmd;
//    } // qCmdStack::SelectSnapshot


    /*******************************************************************************
    * qCmdStack::UndoList
    *******************************************************************************/
    const qUniquePtrList<qCmdI>& qCmdStack::UndoList() const
    {
        return m_lstUndo;
    } // qCmdStack::UndoList


    /*******************************************************************************
    * qCmdStack::RedoList
    *******************************************************************************/
    const qUniquePtrList<qCmdI>& qCmdStack::RedoList() const
    {
        return m_lstRedo;
    } // qCmdStack::RedoList


    /*******************************************************************************
    * qCmdStack::CanUndo
    *******************************************************************************/
    bool qCmdStack::CanUndo() const
    {
        return /*m_pSelectedSnapshot == nullptr &&*/
               m_lstUndo.size() > 0 &&
               m_lstUndo.back()->CmdType() == enumCmdType::CMD_TYPE_UNDO;
    } // qCmdStack::CanUndo


    /*******************************************************************************
    * qCmdStack::CanRedo
    *******************************************************************************/
    bool qCmdStack::CanRedo() const
    {
        return /*m_pSelectedSnapshot == nullptr &&*/
               m_lstRedo.size() > 0;
    } // qCmdStack::CanRedo


    /*******************************************************************************
    * qCmdStack::UndoCmd
    *******************************************************************************/
    void qCmdStack::UndoCmd()
    {
        if ( CanUndo() /*&& m_pSelectedSnapshot == nullptr*/)
        {
            OnCmdProcessingStart(m_lstUndo.back().get());
            m_lstUndo.back()->DoUndo();
        }
    } // qCmdStack::UndoCmd


    /*******************************************************************************
    * qCmdStack::RedoCmd
    *******************************************************************************/
    void qCmdStack::RedoCmd()
    {
        if (CanRedo() /*&& m_pSelectedSnapshot == nullptr*/)
        {
            OnCmdProcessingStart(m_lstRedo.back().get());
            m_lstRedo.back()->DoRedo();
        }
    } // qCmdStack::RedoCmd


    /*******************************************************************************
    * qCmdStack::JumpToCmd
    *******************************************************************************/
//    void qCmdStack::JumpToCmd(std::shared_ptr<aCmdI> _pCmd)
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
//    } // qCmdStack::JumpToCmd


    /*******************************************************************************
    * handler
    *******************************************************************************/
    void qCmdStack::OnUndoDone(qCmdI* /*_pCmd*/) {}
    void qCmdStack::OnUndoFailed(qCmdI* /*_pCmd*/) {}

    void qCmdStack::OnRedoDone(qCmdI* /*_pCmd*/) {}
    void qCmdStack::OnRedoFailed(qCmdI* /*_pCmd*/) {}


    /*******************************************************************************
    * qCmdStack::ManageCmd
    *******************************************************************************/
    void qCmdStack::ManageCmd(enumCmdMsg    _eCmdMsg,
                              qCmdI         *_pCmd,
                              bool          _bSuccess)
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
                    m_lstUndo.RemoveElement(_pCmd);

                    OnCmdProcessingEnd(_pCmd);
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
                    m_lstRedo.clear();

                    OnCmdProcessingEnd(_pCmd);
                }
                else
                {
                    // do failed
                    OnDoFailed(_pCmd);
                    m_lstUndo.RemoveElement(_pCmd);

                    OnCmdProcessingEnd(_pCmd);
                }
                break;
            } // case qCmd::MANAGE_CMD_DO

            case enumCmdMsg::Undo:
            {
                // _pCmd must be at the back the undo stack
                if (_pCmd == m_lstUndo.back().get())
                {
                    if (_bSuccess)
                    {
                        // undo succes => move the current undo-cmd to the redo stack
                        unique_ptr<qCmdI> pCmd = m_lstUndo.GetAndPopBack();
                        m_lstRedo.push_back(std::move(pCmd));

                        OnUndoDone(m_lstRedo.back().get());

                        OnCmdProcessingEnd(m_lstRedo.back().get());
                    }
                    else
                    {
                        // undo failed => remove the cmd and clear the redo stack because
                        // the cmd chain is broken
                        OnUndoFailed(_pCmd);

                        m_lstUndo.pop_back();
                        m_lstRedo.clear();

                        OnCmdProcessingEnd(_pCmd);
                    }
                } // if (_pCmd == m_lstUndo.back().get())
                break;
            } // case enumCmdMsg::Undo

            case enumCmdMsg::Redo:
            {
                // _pCmd must be at the back the redo stack
                if (_pCmd == m_lstRedo.back().get())
                {
                    if (_bSuccess)
                    {
                        // redo succes => move the current redo-cmd to the undo stack
                        unique_ptr<qCmdI> pCmd = m_lstRedo.GetAndPopBack();
                        m_lstUndo.push_back(std::move(pCmd));

                        OnRedoDone(m_lstUndo.back().get());

                        OnCmdProcessingEnd(m_lstUndo.back().get());
                    }
                    else
                    {
                        // redo failed => clear the redo stack because
                        // the cmd chain is broken
                        OnRedoFailed(_pCmd);

                        m_lstRedo.clear();

                        OnCmdProcessingEnd(_pCmd);
                    }
                } // if (_pCmd == m_lstRedo.back().get())
                break;
            } // case enumCmdMsg::Redo

        } // switch (_eManageCmd)

    } // qCmdStack::ManageCmd

} // namespace qLib
