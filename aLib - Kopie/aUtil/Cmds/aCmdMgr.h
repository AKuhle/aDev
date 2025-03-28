/*******************************************************************************
* \file aCmdMgr.h
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
#include "aSharedPtrList.h"
#include "aCmdBase.h"

using namespace std;


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aUtil {


/*******************************************************************************
* class aCmdMgr
*******************************************************************************/
class aCmdMgr
{
    friend class aCmd;
    friend class aCmdThread;

    private:
        aSharedPtrList<aCmdBase>    m_lstCmds;

    protected:
        aCmdMgr();
        virtual ~aCmdMgr();

    public:
        virtual void            executeCmd(shared_ptr<aCmdBase> _pCmd);


    /*******************************************************************************
    * call back functions
    *******************************************************************************/
    protected:
        virtual void            onCmdProcessingStart(const shared_ptr<aCmdBase> &_pCmd);
        virtual void            onCmdProcessingEnd(const shared_ptr<aCmdBase> &_pCmd);

        virtual void            onPrepareDone(const shared_ptr<aCmdBase> &_pCmd);
        virtual void            onPrepareFailed(const shared_ptr<aCmdBase> &_pCmd);

        virtual void            onDoDone(const shared_ptr<aCmdBase> &_pCmd);
        virtual void            onDoFailed(const shared_ptr<aCmdBase> &_pCmd);


    /*******************************************************************************
    * functions for qCmdI only
    *******************************************************************************/
    private:
        virtual void            manageCmd(enumCmdMsg    _eCmdMsg,
                                          aCmdBase      *_pCmd,
                                          bool          _bSuccess);
}; // class aCmdMgr


} // namespace aUtil
} // namespace aLib
