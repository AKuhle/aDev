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

#ifdef _USE_QT_


/*******************************************************************************
* includes
*******************************************************************************/
#include "qBaseDefs.h"
#include "qGuiDefs.h"
#include "qPtrList.h"


namespace qLib
{
    /*******************************************************************************
    * forwards
    *******************************************************************************/
    class qCtrlI;
    class qAction;
    class qListCtrl;
    class qScrollBar;
    class qSlider;
    class qToolButton;
    class qGuiVarPool;


    /*******************************************************************************
    * class qCtrlMgr
    *******************************************************************************/
    class qCtrlMgr
	{
        private:
            qPtrList<qAction>   m_lstAction;
            qPtrList<qCtrlI>    m_lstCtrls;

        public:
            qCtrlMgr();
            virtual ~qCtrlMgr();

            void            UpdateAllCtrls();

        protected:
            virtual void    OnRegisterCtrl() = 0;
            virtual void    OnUpdateCtrl(qCtrlI *_pCtrl) = 0;

            void            Register(QAction        *_pAction,
                                     s32            _s32ID,
                                     qGuiVarPool    *_pVarPool  = nullptr,
                                     bool           _bDefState  = false);

            void            Register(qListCtrl *_pList,
                                     bool       _bCreateCtrl,
                                     s32        _s32ID);

            void            Register(qScrollBar *_pSb,
                                     bool       _bCreateCtrl,
                                     s32        _s32ID);

            void            Register(qSlider    *_pSlider,
                                     bool       _bCreateCtrl,
                                     s32        _s32ID);

            void            Register(qToolButton    *_pBtn,
                                     bool           _bCreateCtrl,
                                     s32            _s32ID,
                                     qGuiVarPool    *_pVarPool  = nullptr,
                                     bool           _bDefState  = false);

            template <class tEnum>
            void            Register(qToolButton    *_pBtn,
                                     bool           _bCreateCtrl,
                                     s32            _s32ID,
                                     s32            _s32EnumID,
                                     tEnum          m_enum,
                                     qGuiVarPool    *_pVarPool  = nullptr,
                                     bool           _bDefState  = false);


        /*******************************************************************************
        * handler
        *******************************************************************************/
        public:
            virtual void    OnCtrlMessage(qCtrlI    *_pCtrl,
                                          u32       _u32Mes,
                                          s64       _s64Value   = 0,
                                          void      *_pVoid1    = nullptr,
                                          void      *_pVoid2    = nullptr);
    }; // class qCtrlMgr

} // namespace qLib

#endif // _USE_QT_
