/*******************************************************************************
* \file aCmd.h
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
#include "aProgressMgr.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aUtil {


/*******************************************************************************
* class aCmd
*******************************************************************************/
class aCmd : public aCmdBase
{
    protected:
        aCmd(s32                _s32ID,
             const aString      &_sName,
             enumCmdType        _eType);

    public:
        virtual ~aCmd();


    /*******************************************************************************
    * interface of aCmdI
    *******************************************************************************/


    /*******************************************************************************
    * interface for the aCmdManager
    *******************************************************************************/
    private:
        //            virtual void                DoPreview(qlaCmdManager           *_paCmdManager,
        //                                                  shared_ptr<aCmd>     _paCmd) = 0;
        void                        doPrepare() override;
        void                        doExecute() override;
        void                        doUndo() override;
        void                        doRedo() override;

}; // class aCmd


} // namespace aUtil
} // namespace aLib
