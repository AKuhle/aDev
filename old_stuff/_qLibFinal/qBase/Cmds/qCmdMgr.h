/*******************************************************************************
* \file qCmdMgr.h
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
#include "qUniquePtrList.h"


namespace qLib
{
    /*******************************************************************************
    * forwards
    *******************************************************************************/
    class qCmdBase;

    using namespace std;


    /*******************************************************************************
    * class qCmdMgr
    *******************************************************************************/
    class qCmdMgr
    {
        friend class qCmd;
        friend class qCmdThread;
        //friend class qCmdStack;

        private:
            qUniquePtrList<qCmdBase>    m_lstCmds;

        protected:
            qCmdMgr();
            virtual ~qCmdMgr();

        public:
            virtual void            ExecuteCmd(unique_ptr<qCmdBase> _pCmd);

            unique_ptr<qCmdBase>    TakeCmdCtrl(qCmdBase *_pCmd);


        /*******************************************************************************
        * call back functions
        *******************************************************************************/
        protected:
            virtual void            OnCmdProcessingStart(qCmdBase *_pCmd);
            virtual void            OnCmdProcessingEnd(qCmdBase *_pCmd);

            virtual void            OnPrepareDone(qCmdBase *_pCmd);
            virtual void            OnPrepareFailed(qCmdBase *_pCmd);

            virtual void            OnDoDone(qCmdBase *_pCmd);
            virtual void            OnDoFailed(qCmdBase *_pCmd);


        private:
            /*******************************************************************************
            * functions for qCmdI only
            *******************************************************************************/
            virtual void            ManageCmd(enumCmdMsg    _eCmdMsg,
                                              qCmdBase      *_pCmd,
                                              bool          _bSuccess);
    }; // class qCmdMgr

} // namespace qLib
