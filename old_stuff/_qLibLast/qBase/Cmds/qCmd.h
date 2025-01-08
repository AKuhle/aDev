/*******************************************************************************
* \file qCmd.h
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
#include "qCmd_i.h"


namespace qFrame
{
    /*******************************************************************************
    * forwards
    *******************************************************************************/
    class qCmdMgr;
    class qCmdStack;

    using namespace std;


    /*******************************************************************************
    * class qCmd
    *******************************************************************************/
    class qCmd : public qCmdI
    {
        protected:
            qCmd(s32                    _s32aCmdId,
                 const qString16&       _sCmdName,
                 enumCmdType            _eCmdType);
                //qlProgressCallback    *_pProgressCallback = nullptr);

        public:
            virtual ~qCmd();


        /*******************************************************************************
        * interface of aCmdI
        *******************************************************************************/


        /*******************************************************************************
        * interface for the aCmdManager
        *******************************************************************************/
        private:
            //            virtual void                DoPreview(qlaCmdManager           *_paCmdManager,
            //                                                  shared_ptr<aCmd>     _paCmd) = 0;
            virtual void                DoPrepare() override;
            virtual void                DoDo() override;
            virtual void                DoUndo() override;
            virtual void                DoRedo() override;

    }; // class qCmd

} // namespace qFrame
