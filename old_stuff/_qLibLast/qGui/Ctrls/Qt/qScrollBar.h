/*******************************************************************************
* \file qScrollBar.h
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


namespace qLib
{
    /*******************************************************************************
    * \class qScrollBar
    *******************************************************************************/
    class qScrollBar : public qSysWin<QScrollBar>,
                       public qCtrlI
    {
        Q_OBJECT

        public:
            qScrollBar(enumOrientation  _eOrientation,
                       SysWin_t         *_pParent = nullptr);

            virtual ~qScrollBar();

            void                SetOrientation(enumOrientation  _eOrientation);
            enumOrientation     Orientation() const;

            void                SetRange(s32    _s32Min,
                                         s32    _s32Max);

            void                SetValue(s32 _s32Value);
            s32                 Value() const;


        /*******************************************************************************
        * interface of qCtrlI
        *******************************************************************************/
        protected:
            virtual void        SetCtrlEnabled(bool _bEnabled) override;
            virtual bool        IsCtrlEnabled() const override;

            // virtual void    VarPool2Control() override;
            // virtual void    Control2VarPool() override;^^


        /*******************************************************************************
        * slots
        *******************************************************************************/
        private slots:
            void                SlotValueChanged(int _iValue);
    }; // class qScrollBar

} // namespace qLib

#endif // _USE_QT_
