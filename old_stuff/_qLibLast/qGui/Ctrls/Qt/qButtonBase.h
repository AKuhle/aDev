/*******************************************************************************
* \file qButtonBase.h
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
#include "qSysWin.h"
#include "qCtrl_i.h"
#include "qGuiVarPool.h"


namespace qLib
{
    /*******************************************************************************
    * \class qButtonBase
    *******************************************************************************/
    template <class T>
    class qButtonBase : public qSysWin<T>,
                        public qCtrlI
    {
        public:
            qButtonBase(SysWin_t *_pParent = nullptr);
            virtual ~qButtonBase();


        /*******************************************************************************
        * interface of qCtrlI
        *******************************************************************************/
        public:
            virtual void    SetCtrlEnabled(bool _bEnabled) override;
            virtual bool    IsCtrlEnabled() const override;

            virtual void    SetCtrlCheckable(bool _bCheckable) override;
            virtual bool    IsCtrlCheckable() const override;

            virtual void    SetCtrlChecked(bool _bChecked) override;
            virtual bool    IsCtrlChecked() const override;

            virtual void    SetCtrlEnabledChecked(bool    _bEnabled,
                                                  bool    _bChecked) override;

        protected:
            virtual void    VarPool2Control() override;
            virtual void    Control2VarPool() override;


        /*******************************************************************************
        * slots
        *******************************************************************************/
        private slots:
            // void            SlotClicked(bool _bChecked);
    }; // class qButtonBase

} // namespace qLib

#include "qButtonBase.inl"

#endif // _USE_QT_
