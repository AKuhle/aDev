/*******************************************************************************
* \file qWin.h
* \author Andreas Kuhlewind
*
* \brief
*
*  Detailed description starts here.
*******************************************************************************/
#pragma once

#ifdef _USE_QT_


/*******************************************************************************
* includes
*******************************************************************************/
#include "aBaseWin.h"
#include "aCtrlI.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aWin {


/*******************************************************************************
* class aCtrl
*******************************************************************************/
template<class T>
class aCtrl : public aBaseWin<T>,
              public aCtrlI
{
    private:
        s32             m_s32CtrlID     { 0 };
        aCtrlMgr        *m_pCtrlMgr     { nullptr };


    /*******************************************************************************
    * con-/destruction
    *******************************************************************************/
    protected:
        aCtrl(SysWin *_pParent);
        virtual ~aCtrl();


    /*******************************************************************************
    * aCtrlI interface
    *******************************************************************************/
    public:
        void            setCtrlId(s32 _s32CtrlID) override;
        s32             ctrlId() const override;

        void            setCtrlMgr(aCtrlMgr *_pCtrlMgr) override;
        aCtrlMgr*       ctrlMgr() const override;

        void            setCtrlEnabled(bool _bEnabled) override;
        bool            ctrlEnabled() const override;
}; // class aCtrl


} // namespace aWin
} // namespace aLib

#include "aCtrl.inl"

#endif //_USE_QT_
