/*******************************************************************************
* \file qCmdThread.h
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
#include "qCmdBase.h"
#include "qProgress.h"
#include "qThread.h"
#include "qThreadCb.h"


namespace qLib
{
    /*******************************************************************************
    * forwards
    *******************************************************************************/
    class qCmdMgr;
    class qCmdStack;
    class qCmdThread;

    using namespace std;


    /*******************************************************************************
    * class CmdWorkerThread
    *******************************************************************************/
    class CmdWorkerThread : public qThread
    {
        private:
            qCmdThread  *m_pCmd;
            enumCmdMsg  m_eCmdMsg;
            bool        &m_bSuccess;

        public:
            CmdWorkerThread(qCmdThread  *_pCmd,
                            enumCmdMsg  _eCmdMsg,
                            bool        &_bSuccess);
            virtual ~CmdWorkerThread();

            virtual void            OnRun() override;
    }; // class CmdWorkerThread


    /*******************************************************************************
    * class qCmdThread
    *******************************************************************************/
    class qCmdThread : public qCmdBase,
                       public qThreadCb
    {
        private:
            enumCmdMsg                  m_eCmdMsg;
            bool                        m_bSuccess;

        protected:
            qCmdThread(s32              _s32CmdID,
                       const qString16  &_sCmdName,
                       enumCmdType      _eCmdType,
                       qProgress        *_pProgress);

        public:
            virtual ~qCmdThread();


        /*******************************************************************************
        * interface for the CmdMgr
        *******************************************************************************/
        private:
            //            virtual void                DoPreview(qlaCmdManager           *_paCmdManager,
            //                                                  shared_ptr<aCmd>     _paCmd) = 0;
            virtual void                DoPrepare() override;
            virtual void                DoDo() override;
            virtual void                DoUndo() override;
            virtual void                DoRedo() override;


        /*******************************************************************************
        * interface of qlThreadCallback
        *******************************************************************************/
        protected:
            virtual void                OnThreadStarted(u32 _u32ThreadID) override;
            virtual void                OnThreadFinished(u32 _u32ThreadID) override;

    }; // class qCmdThread

} // namespace qLib
