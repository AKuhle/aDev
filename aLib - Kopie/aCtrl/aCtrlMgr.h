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


/*******************************************************************************
* includes
*******************************************************************************/
#include "aUtil/Collection/aPtrList.h"

#include "aWin/Ctrl/aCtrl.h"

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
        //qPtrList<qAction>   m_lstAction;
        aPtrList<aCtrl>         m_lstCtrls;

    public:
        aCtrlMgr();
        virtual ~aCtrlMgr();

        void            updateAllCtrls();

        virtual void    onRegisterCtrl() = 0;
        virtual void    onUpdateCtrl(aCtrl *_pCtrl) = 0;

        void            registerCtrl(aCtrl  *_pCtrl);

        void            sendCtrlMessage(aCtrl   *_pCtrl,
                                        u32     _u32Mes);

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
        virtual void    onCtrlClicked(aCtrl *_pCtrl);
        // virtual void    OnCtrlValueChanged(qCtrlBase *_pCtrl);
}; // class aCtrlMgr


} // namespace aWin
} // namespace aLib
