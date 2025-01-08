/*******************************************************************************
* \file qqCtrlMgr
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
#include "qGuiDefs.h"
#include "qPtrList.h"


namespace qLib
{
    /*******************************************************************************
    * forwards
    *******************************************************************************/
    class qCtrlBase;


    /*******************************************************************************
    * class qCtrlMgr
    *******************************************************************************/
    class qCtrlMgr
	{
        friend class qWin;

        private:
            //qPtrList<qAction>   m_lstAction;
            qPtrList<qCtrlBase>    m_lstCtrls;

        public:
            qCtrlMgr();
            virtual ~qCtrlMgr();

            void            UpdateAllCtrls();

            virtual void    OnRegisterCtrl() = 0;
            virtual void    OnUpdateCtrl(qCtrlBase *_pCtrl) = 0;

            void            Register(qCtrlBase  *_pCtrl);

            void            SendCtrlMessage(qCtrlBase *_pCtrl,
                                            u32       _u32Mes);

            // void            Register(QAction        *_pAction,
            //                          s32            _s32ID,
            //                          qGuiVarPool    *_pVarPool  = nullptr,
            //                          bool           _bDefState  = false);

            // template <class tEnum>
            // void            Register(qToolButton    *_pBtn,
            //                          bool           _bCreateCtrl,
            //                          s32            _s32ID,
            //                          s32            _s32EnumID,
            //                          tEnum          m_enum,
            //                          qGuiVarPool    *_pVarPool  = nullptr,
            //                          bool           _bDefState  = false);


        /*******************************************************************************
        * handler
        *******************************************************************************/
        protected:
            virtual void    OnCtrlClicked(qCtrlBase *_pCtrl);
            virtual void    OnCtrlValueChanged(qCtrlBase *_pCtrl);
    }; // class qCtrlMgr

} // namespace qLib
