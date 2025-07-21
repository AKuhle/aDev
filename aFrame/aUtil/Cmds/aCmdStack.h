/*******************************************************************************
* \file aCmdStack.h
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
#include "aCmdMgr.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aFrame {
namespace aUtil {


/*******************************************************************************
* class aCmdStack
*******************************************************************************/
class aCmdStack : public aCmdMgr
{
    private:
        //qSpList<aCmdBase>          m_lstSnapshot;
        aSharedPtrList<aCmdBase>    m_lstUndo;
        aSharedPtrList<aCmdBase>    m_lstRedo;
        s32                         m_s32MaxUndo        { 10 };

        //std::shared_ptr<aCmdBase>  m_pSelectedSnapshot;

    protected:
        aCmdStack();
        virtual ~aCmdStack();

    public:
        void                            executeCmd(shared_ptr<aCmdBase>   _pCmd);

        // initialize the undo cmd stack with the cmd and
        // clears the redo stack.
        // the command is not beeing executed
        void                            setCmd(shared_ptr<aCmdBase> _pCmd);

        // the active command is the top most undo command
        aCmdBase*                       activeCmd() const;

        // add a snapshoot at the end of the list
//            void                    AddSnapshot(std::shared_ptr<aCmdBase>	_pCmd);

//            bool                    IsSnapshotSelected() const  { return m_pSelectedSnapshot != nullptr; }
//            std::shared_ptr<aCmdBase>  Snapshot() const            { return m_pSelectedSnapshot; }
//            void                    SelectSnapshot(std::shared_ptr<aCmdBase> _pCmd);

//            const qSpList<aCmdBase>&   SnapshotList() const        { return m_lstSnapshot; }
        const aSharedPtrList<aCmdBase>& undoList() const;
        const aSharedPtrList<aCmdBase>& redoList() const;

        bool                            canUndo() const;
        bool                            canRedo() const;

        void                            undoCmd();
        void                            redoCmd();

        // "jumps" to the given command -> the given command is moved to the
        // top of the undo stack.
        //
        // the Undo/Redo methods of the commands are NOT CALLED, this means, the
        // commands must know their pre- and post state.
        //
        // TBD: if the commands need to call Undo/Redo to calculate their
        // pre-/post state, you need to call "ScrollToCmd"
        //void                    JumpToCmd(std::shared_ptr<aCmdBase> _pCmd);
        //void                    ScrollToCmd(std::shared_ptr<aCmdBase> _pCmd);


    /*******************************************************************************
    * call back functions
    *******************************************************************************/
    protected:
        virtual void                    onUndoDone(const shared_ptr<aCmdBase> &_pCmd);
        virtual void                    onUndoFailed(const shared_ptr<aCmdBase> &_pCmd);

        virtual void                    onRedoDone(const shared_ptr<aCmdBase> &_pCmd);
        virtual void                    onRedoFailed(const shared_ptr<aCmdBase> &_pCmd);

    private:
        virtual void                    manageCmd(enumCmdMsg    _eCmdMsg,
                                                  aCmdBase      *_pCmd,
                                                  bool          _bSuccess);
}; // class aCmdStack


} // namespace aUtil
} // namespace aFrame
