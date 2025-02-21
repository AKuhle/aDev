/*******************************************************************************
* \file qScrollBar.h
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
#include "qBaseDefs.h"
#include "qCtrlBase.h"
#include "qCtrlMgr.h"
#include "qInterval2D.h"


namespace qLib
{
    /*******************************************************************************
    * forward
    *******************************************************************************/
    class qToolButton;
    class qPixmap;


    /*******************************************************************************
    * class qScrollBar
    *******************************************************************************/
    class qScrollBar : public qCtrlBase,
                       public qCtrlMgr
    {
        DeclareTypeProperty(s32, s32, LineStep, 1)
        DeclareTypeProperty(s32, s32, PageStep, 10)
        DeclareBoolProperty(Tracking, false)

        private:
            enumOrientation     m_eOrientation      { };

            s32                 m_s32MinValue       { 0 };
            s32                 m_s32MaxValue       { 100 };
            s32                 m_s32Value          { 50 };

            qToolButton         *m_pBtnDec          { nullptr };
            qToolButton         *m_pBtnInc          { nullptr };

            s32                 m_s32SliderSize     { 50 };
            s32                 m_s32MinSliderSize  { 16 };

            s32                 m_s32Pos            { 0 };

        public:
            qScrollBar(qWin             *_pParent,
                       u32              _u32Id,
                       enumOrientation  _eOrientation);

            virtual ~qScrollBar();

            void                    SetRange(s32 _s32MinValue,
                                             s32 _s32MaxValue);

            void                    SetRange(const qInterval2D<s32> &_rhs);

            qInterval2D<s32>        GetRange() const;
            s32                     GetMinValue() const;
            s32                     GetMaxValue() const;

            bool                    SetValue(s32 _s32Value);    // true => value changed
            s32                     GetValue() const;

            enumOrientation         GetOrientation() const;
            qRect2D<s32>            GetSlideArea() const;       // area, in which the slider can move
            qRect2D<s32>            GetSliderRect() const;      // slider handle rect
            s32                     GetPos() const;

    private:
            s32                     Pos2Value(s32 _s32Pos) const;
            s32                     Value2Pos(s32 _s32Value) const;

            void                    UpdateSlider();


        /*******************************************************************************
        * qCtrlMgr interface
        *******************************************************************************/
        protected:
            virtual void            OnRegisterCtrl() override;
            virtual void            OnUpdateCtrl(qCtrlBase *_pCtrl) override;

            virtual void            OnCtrlClicked(qCtrlBase *_pCtrl) override;


        /*******************************************************************************
        * qToolMgr interface
        *******************************************************************************/
        protected:
            virtual void            OnToolMsg(qToolBase *_pTool,
                                              u32       _u32Msg,
                                              s32       _s32Param,
                                              u32       _u32Param,
                                              s64       _s64Param,
                                              u64       _u64Param,
                                              flt       _fltParam,
                                              dbl       _dblParam);


        /*******************************************************************************
        * qWin interface
        *******************************************************************************/
        public:
            virtual bool            OnSysCreate();

            virtual void            OnSysResize(const qDimension2D<s32>    &_oldSize,
                                                const qDimension2D<s32>    &_newSize);

            virtual void            OnPaintContent();
    }; // class qScrollBar

} // namespace qLib
