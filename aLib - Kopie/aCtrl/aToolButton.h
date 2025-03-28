/*******************************************************************************
* \file aToolButton.h
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
#include "aToolButton_sys.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aWin {


/*******************************************************************************
* class aToolButton
*******************************************************************************/
class aToolButton : public aToolButton_sys
{
    public:
        aToolButton(SysWinClass *_pParent = nullptr);
        virtual ~aToolButton();

}; // class aToolButton


} // namespace aWin
} // namespace aLib


    //private:
        // u32             m_u32CtrlId     { 0 };
        // aToolButtonMgr        *m_pCtrlMgr     { nullptr };
        // qGuiVarPool     *m_pVarPool     { nullptr };

    // public:
        // void            SetCtrlId(u32  _u32CtrlId);
        // u32             CtrlId() const;

        // void            SetVarPool(qGuiVarPool *_pVarPool);
        // qGuiVarPool*    VarPool() const;

        // void            SetCtrlMgr(aToolButtonMgr *_pCtrlMgr);
        // aToolButtonMgr*       CtrlMgr() const;

        // virtual void    SetCtrlEnabled(bool _bEnabled) = 0;
        // virtual bool    IsCtrlEnabled() const = 0;

        // virtual void    SetCtrlCheckable(bool _bCheckable);
        // virtual bool    IsCtrlCheckable() const;

        // virtual void    SetCtrlChecked(bool _bChecked);
        // virtual bool    IsCtrlChecked() const;

        // virtual void    SetCtrlEnabledChecked(bool    _bEnabled,
        //                                       bool    _bChecked);


    // /*******************************************************************************
    // * interface of aToolButton
    // *******************************************************************************/
    //protected:
    //     void            SetVisible(bool _bVisible) override;
    //     bool            IsVisible() const override;

    //     void            SetEnabled(bool     _bEnabled) override;
    //     bool            IsEnabled() const override;

        // virtual void        VarPool2Control();
        // virtual void        Control2VarPool();


    // /*******************************************************************************
    // * slots
    // *******************************************************************************/
    // private slots:
    //     void            SlotTriggered(bool _bChecked);
