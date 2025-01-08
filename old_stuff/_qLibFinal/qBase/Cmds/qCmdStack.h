/*******************************************************************************
* \file qCmdStack.h
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
#pragma once


/*******************************************************************************
* includes
*******************************************************************************/
#include "qCmdMgr.h"
#include "qUniquePtrList.h"


namespace qLib
{
    /*******************************************************************************
    * forwards
    *******************************************************************************/
    class qCmdBase;

    using namespace std;


    /*******************************************************************************
    * class qCmdStack
    *******************************************************************************/
    class qCmdStack : public qCmdMgr
    {
        friend class qCmd;
        friend class qCmdThread;

        private:
            //qSpList<qCmdBase>          m_lstSnapshot;
            qUniquePtrList<qCmdBase>    m_lstUndo;
            qUniquePtrList<qCmdBase>    m_lstRedo;

            //std::shared_ptr<qCmdBase>  m_pSelectedSnapshot;

        protected:
            qCmdStack();
            virtual ~qCmdStack();

        public:
            void                            ExecuteCmd(unique_ptr<qCmdBase>   _pCmd);

            // initialize the undo cmd stack with the cmd and
            // clears the redo stack
            // the cmd is not executed, because it is assumed
            // that's already done
            void                            SetCmd(unique_ptr<qCmdBase>   _pCmd);

            // the active command is the top most undo command
            qCmdBase*                       GetActiveCmd() const;

            // add a snapshoot at the end of the list
//            void                    AddSnapshot(std::shared_ptr<qCmdBase>	_pCmd);

//            bool                    IsSnapshotSelected() const  { return m_pSelectedSnapshot != nullptr; }
//            std::shared_ptr<qCmdBase>  Snapshot() const            { return m_pSelectedSnapshot; }
//            void                    SelectSnapshot(std::shared_ptr<qCmdBase> _pCmd);

//            const qSpList<qCmdBase>&   SnapshotList() const        { return m_lstSnapshot; }
            const qUniquePtrList<qCmdBase>& UndoList() const;
            const qUniquePtrList<qCmdBase>& RedoList() const;

            bool                            CanUndo() const;
            bool                            CanRedo() const;

            void                            UndoCmd();
            void                            RedoCmd();

            // "jumps" to the given command -> the given command is moved to the
            // top of the undo stack.
            //
            // the Undo/Redo methods of the commands are NOT CALLED, this means, the
            // commands must know their pre- and post state.
            //
            // TBD: if the commands need to call Undo/Redo to calculate their
            // pre-/post state, you need to call "ScrollToCmd"
            //void                    JumpToCmd(std::shared_ptr<qCmdBase> _pCmd);
            //void                    ScrollToCmd(std::shared_ptr<qCmdBase> _pCmd);


        /*******************************************************************************
        * call back functions
        *******************************************************************************/
        protected:
            virtual void            OnUndoDone(qCmdBase *_pCmd);
            virtual void            OnUndoFailed(qCmdBase *_pCmd);

            virtual void            OnRedoDone(qCmdBase *_pCmd);
            virtual void            OnRedoFailed(qCmdBase *_pCmd);

        private:
            virtual void            ManageCmd(enumCmdMsg    _eCmdMsg,
                                              qCmdBase      *_pCmd,
                                              bool          _bSuccess);
    }; // class qCmdStack

} // namespace qLib
