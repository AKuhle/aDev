/*******************************************************************************
* \file qCmdBase.h
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
#include "qBaseDefs.h"
#include "qString16.h"


namespace qLib
{
    /*******************************************************************************
    * forward
    *******************************************************************************/
    class qProgress;
    class qCmdMgr;

    using namespace std;


    /*******************************************************************************
    * class qCmdBase
    *******************************************************************************/
    class qCmdBase
    {
        /*******************************************************************************
        * friends
        *******************************************************************************/
        friend class qCmdMgr;
        friend class qCmdStack;


        private:
            qCmdMgr     *m_pCmdMgr          { nullptr };
            s32         m_s32CmdId;
            qString16   m_sCmdName          { "?" };
            enumCmdType m_eCmdType;
            qProgress   *m_pProgress        { nullptr };
            qString16   m_sSnapshotName     { "?" };


        protected:
            qCmdBase(s32               _s32aCmdId,
                     const qString16   &_sCmdName,
                     enumCmdType       _eCmdType,
                     qProgress         *_pProgress);


            void                        SetCmdMgr(qCmdMgr* _pCmdMgr);
            qCmdMgr*                    GetCmdMgr() const;
            qProgress*                  GetProgress() const;

        public:
            virtual ~qCmdBase();

            s32                         GetCmdId() const;
            const qString16&            GetCmdName() const;
            enumCmdType                 GetCmdType() const;

            bool						CanUndo() const;

            virtual bool				Prepare()       { return true; }
//            virtual bool				PrepareDone()   { return true; }

            virtual bool				Do() = 0;
//            virtual bool				DoDone()        { return true; }

            virtual bool				Undo()          { return false; }		// CMD_TYPE_NO_UNDO commands can't Undo
//            virtual bool				UndoDone()      { return true; }

            virtual bool				Redo()          { return false; }		// CMD_TYPE_NO_UNDO commands can't Redo
//            virtual bool				RedoDone()      { return true; }


//            virtual void                SetCmdName(const qString16 &_sName)       {  m_sCmdName = _sName; }
//            virtual qString16             CmdName() const                         { return m_sCmdName; }

//            virtual void                SetSnapshotName(const qString16 &_sName)  {  m_sSnapshotName = _sName; }
//            virtual qString16             SnapshotName() const                    { return m_sSnapshotName; }


        private:
            /*******************************************************************************
            * members called by the qCmdMgr/qCmdStack
            *******************************************************************************/
            virtual void                DoPrepare() = 0;
            virtual void                DoDo() = 0;
            virtual void                DoUndo() = 0;
            virtual void                DoRedo() = 0;
    }; // class qCmdBase

} // namespace qLib
