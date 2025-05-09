/*******************************************************************************
* \file qaCtrlMgr
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
#include <QAction>

#include "aUtil/Collection/aPtrList.h"
#include "aCtrl/aCtrl_def.h"

using namespace aLib::aUtil;


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aWin {


/*******************************************************************************
* class aCtrlMgr
*******************************************************************************/
class aCtrlMgr
{
    private:
        //qPtrList<qAction>     m_lstAction;
        aPtrList<aCtrlI>       m_lstCtrls;

    public:
        aCtrlMgr();
        virtual ~aCtrlMgr();

        void            updateAllCtrls();
        void            updateCtrl(aCtrlI *_pCtrl);

        virtual void    onRegisterCtrl() = 0;
        virtual void    onUpdateCtrl(aCtrlI *_pCtrl) = 0;

        //void            registerCtrl(aCtrlI  *_pCtrl);

        void            sendCtrlMessage(aCtrlI  *_pCtrl,
                                        u32     _u32Mes);

        void            registerCtrl(QAction        *_pAction,
                                     s32            _s32ID);
                                     //qGuiVarPool    *_pVarPool  = nullptr,
                                     //bool           _bDefState  = false);

        void            registerCtrl(aToolButton    *_pBtn,
                                     s32            _s32ID,
                                     bool           _bCreateWin);
                                     //qGuiVarPool    *_pVarPool  = nullptr,
                                     //bool           _bDefState  = false);

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
        virtual void    onCtrlClicked(aCtrlI *_pCtrl);
        // virtual void    OnCtrlValueChanged(qCtrlBase *_pCtrl);
}; // class aCtrlMgr


} // namespace aWin
} // namespace aLib


#endif //_USE_QT_
