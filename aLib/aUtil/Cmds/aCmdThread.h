/*******************************************************************************
* \file aCmdThread.h
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
#include "aCmdBase.h"
#include "aThread.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aUtil {


/*******************************************************************************
* class CmdWorkerThread
*******************************************************************************/
class CmdWorkerThread : public aThread
{
    private:
        aCmdThread  *m_pCmd;
        enumCmdMsg  m_eCmdMsg;
        bool        &m_bSuccess;

    public:
        CmdWorkerThread(aCmdThread  *_pCmd,
                        enumCmdMsg  _eCmdMsg,
                        bool        &_bSuccess);
        virtual ~CmdWorkerThread();

        void                onRun() override;
}; // class CmdWorkerThread


/*******************************************************************************
* class aCmdThread
*******************************************************************************/
class aCmdThread : public aCmdBase,
                   public aThreadCb_i
{
    private:
        enumCmdMsg                  m_eCmdMsg;
        bool                        m_bSuccess;

    protected:
        aCmdThread(s32              _s32Id,
                   const aString    &_sName,
                   enumCmdType      _eType);

    public:
        virtual ~aCmdThread();


    /*******************************************************************************
    * interface for the CmdMgr
    *******************************************************************************/
    private:
        //            virtual void                DoPreview(qlaCmdManager           *_paCmdManager,
        //                                                  shared_ptr<aCmd>     _paCmd) = 0;
        void        doPrepare() override;
        void        doExecute() override;
        void        doUndo() override;
        void        doRedo() override;


    /*******************************************************************************
    * interface of qlThreadCallback
    *******************************************************************************/
    protected:
        void        onThreadStarted(u32 _u32ThreadID) override;
        void        onThreadFinished(u32 _u32ThreadID) override;

}; // class aCmdThread


} // namespace aUtil
} // namespace aLib
