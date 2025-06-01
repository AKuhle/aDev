// /*******************************************************************************
// * \file qCtrl_sysi.h
// * \author Andreas Kuhlewind
// *
// * \brief
// *
// * $Revision: 69 $
// * $LastChangedDate: 2010-08-17 14:10:45 +0200 (Di, 17 Aug 2010) $
// * $LastChangedBy: akuhlewi $
// *
// *  Detailed description starts here.
// *******************************************************************************/
#pragma once



/*******************************************************************************
* includes
*******************************************************************************/
#include "aLib_def.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aWin {


/*******************************************************************************
* class aScrollBarI
*******************************************************************************/
class aScrollBarI
{
    public:
        virtual ~aScrollBarI() = default;

    public:
        virtual void            setRange(s32    _s32Min,
                                         s32    _s32Max) = 0;

        virtual void            setTracking(bool _bTracking) = 0;

        virtual void            setPosition(s32 _s32Pos) = 0;
        virtual void            setValue(s32 _s32Val) = 0;

        virtual void            setInverse(bool _bInverse) = 0;

}; // class aScrollBarI


} // namespace aWin
} // namespace aLib




// namespace qLib
// {
//     /*******************************************************************************
//     * class qCtrl_sysi
//     *******************************************************************************/
//     class qCtrl_sysi
//     {
//         private:
//             u32             m_u32CtrlId     { 0 };
//             qCtrlMgr        *m_pCtrlMgr     { nullptr };
//             qGuiVarPool     *m_pVarPool     { nullptr };

//         public:
//             qCtrl_sysi();
//             virtual ~qCtrl_sysi();


//             void            SetVarPool(qGuiVarPool *_pVarPool);
//             qGuiVarPool*    VarPool() const;


//             virtual void    SetCtrlCheckable(bool _bCheckable);
//             virtual bool    IsCtrlCheckable() const;

//             virtual void    SetCtrlChecked(bool _bChecked);
//             virtual bool    IsCtrlChecked() const;

//             virtual void    SetCtrlEnabledChecked(bool    _bEnabled,
//                                                   bool    _bChecked);


//         // /*******************************************************************************
//         // * interface of qCtrl_sysi
//         // *******************************************************************************/
//         protected:
//         //     void            SetVisible(bool _bVisible) override;
//         //     bool            IsVisible() const override;

//         //     void            SetEnabled(bool     _bEnabled) override;
//         //     bool            IsEnabled() const override;

//             // virtual void        VarPool2Control();
//             // virtual void        Control2VarPool();


//         // /*******************************************************************************
//         // * slots
//         // *******************************************************************************/
//         // private slots:
//         //     void            SlotTriggered(bool _bChecked);

//     }; // class qCtrl_sysi
