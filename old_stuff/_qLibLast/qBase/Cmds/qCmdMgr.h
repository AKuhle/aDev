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
    class qCmdI;

    using namespace std;


    /*******************************************************************************
    * class qCmdMgr
    *******************************************************************************/
    class qCmdMgr
    {
        //friend class qCmd;
        friend class qCmdThread;
        //friend class qCmdStack;

        private:
            qUniquePtrList<qCmdI>		m_lstCmds;

        protected:
            qCmdMgr();
            virtual ~qCmdMgr();

        public:
            virtual void            ExecuteCmd(unique_ptr<qCmdI> _pCmd);

            unique_ptr<qCmdI>       TakeCmdCtrl(qCmdI *_pCmd);


        /*******************************************************************************
        * call back functions
        *******************************************************************************/
        protected:
            virtual void            OnCmdProcessingStart(qCmdI *_pCmd);
            virtual void            OnCmdProcessingEnd(qCmdI *_pCmd);

            virtual void            OnPrepareDone(qCmdI *_pCmd);
            virtual void            OnPrepareFailed(qCmdI *_pCmd);

            virtual void            OnDoDone(qCmdI *_pCmd);
            virtual void            OnDoFailed(qCmdI *_pCmd);


        private:
            /*******************************************************************************
            * functions for qCmdI only
            *******************************************************************************/
            virtual void            ManageCmd(enumCmdMsg    _eCmdMsg,
                                              qCmdI         *_pCmd,
                                              bool          _bSuccess);
    }; // class qCmdMgr

} // namespace qLib
