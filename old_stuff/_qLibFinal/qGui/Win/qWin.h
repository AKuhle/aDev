/*******************************************************************************
* \file qWin.h
* \author Andreas Kuhlewind
*
* \brief
*
*  Detailed description starts here.
*******************************************************************************/
#pragma once


/*******************************************************************************
* includes
*******************************************************************************/
#include "qSysWin.h"
#include "qRect2D.h"
#include "qVector2D.h"
#include "qToolMgr.h"
#include "qCursor.h"
#include "qLayoutObj.h"


namespace qLib
{
    /*******************************************************************************
    * class qWin
    *******************************************************************************/
    class qWinStyleFactoryBase;
    class qLayoutObj;


    /*******************************************************************************
    * class qWin
    *******************************************************************************/
    class qWin : public qSysWin,
                 public qWinStyle,
                 public qToolMgr,
                 public qLayoutObj
    {
        DeclareBoolProperty(Hover, false);

        private:
            static unique_ptr<qWinStyleFactoryBase> m_pWinStyleFactory;

            std::unique_ptr<qLayoutObj>            m_pLayout;
            qCursor                                 m_cursor        { enumCursorShape::Arrow };
            qDimension2D<s32>                       m_d2dMaxSize    { WIN_SIZE_MAX, WIN_SIZE_MAX };

        protected:
            qWin(SysWin_t  *_pParent = nullptr);
            ~qWin();

        public:
            bool                        CreateWin();
            bool                        CloseWin();

            qWin*                       GetParent() const;
            void                        SetParent(qWin *_pParent);  // can be nullptr

            qLayoutObj*                 GetLayout() const;
            void                        SetLayout(unique_ptr<qLayoutObj> _pLayout);

            bool                        IsVisible() const;
            void                        SetVisible(bool _bVisible);

            bool                        IsDisabled() const;
            void                        SetDisabled(bool _bDisabled);


        // geometry & style
        public:
            // screen geometry within the parent (x, y, w, h)
            qRect2D<s32>                GeometryRect() const;
            s32                         w() const;
            s32                         h() const;

            void                        SetGeometry(const qRect2D<s32> &geo);
            virtual void                SetGeometry(s32 _x,
                                                    s32 _y,
                                                    s32 _w,
                                                    s32 _h);

            virtual void                SetPosition(s32 _x,
                                                    s32 _y);


            // show maximized/minimized/normal
            void                        ShowMaximized();
            void                        ShowMinimized();
            void                        ShowNormal();
            void                        ToggleMaximized();

            bool                        IsMaximized() const;
            bool                        IsMinimized() const;

            qVector2D<s32>              LocalCursorPos() const;

            void                        SetMouseTracking(bool _bEnable);

            void                        EnableDrop(bool _bAccept);

            void                        SetCursor(const qCursor &_cursor);

            void                        Update();      // update queue
            void                        Repaint();     // updates immidiately

            // geometry within the window, (0, 0) is left top
            virtual qRect2D<s32>        GetMarginRect() const;
            virtual qRect2D<s32>        GetBorderRect() const;
            virtual qRect2D<s32>        GetPaddingRect() const;
            virtual qRect2D<s32>        GetContentRect() const;


        /*******************************************************************************
        * handler
        *******************************************************************************/
        protected:
            virtual bool                OnSysCreate();

            virtual bool                OnCreate();

            virtual bool                OnClose();

            virtual void                OnSysResize(const qDimension2D<s32>    &_oldSize,
                                                    const qDimension2D<s32>    &_newSize);

            virtual void                OnResize(const qDimension2D<s32>    &_oldSize,
                                                 const qDimension2D<s32>    &_newSize);

            virtual bool                OnEnter(u32                   _u32Modifiers,
                                                const qVector2D<s32>    &_v2dLocal,
                                                const qVector2D<s32>    &_v2dGlobal);

            virtual bool                OnLeave(u32 _u32Modifiers);

            virtual void                OnSetCursor();

            virtual bool                OnWheel(u32                     _u32Modifiers,
                                                s32                     _s32Degree,
                                                const qVector2D<s32>    &_v2dLocal,
                                                const qVector2D<s32>    &_v2dGlobal);

            virtual bool                OnDoubleClick(u32                   _u32Modifiers,
                                                      u32                   _u32MouseButton,
                                                      const qVector2D<s32>  &_v2dLocal,
                                                      const qVector2D<s32>  &_v2dGlobal);

            virtual bool                OnMousePress(u32                   _u32Modifiers,
                                                     u32                   _u32MouseButton,
                                                     const qVector2D<s32>  &_v2dLocal,
                                                     const qVector2D<s32>  &_v2dGlobal);

            virtual bool                OnMouseMove(u32                   _u32Modifiers,
                                                    u32                   _u32MouseButton,
                                                    const qVector2D<s32>   &_v2dLocal,
                                                    const qVector2D<s32>   &_v2dGlobal);

            virtual bool                OnMouseRelease(u32                   _u32Modifiers,
                                                       u32                   _u32MouseButton,
                                                       const qVector2D<s32>  &_v2dLocal,
                                                       const qVector2D<s32>  &_v2dGlobal);

            virtual void                OnDropUrl(const qUrl  &_url);

            virtual void                OnPaintMarginBg();
            virtual void                OnPaintPaddingBg();
            virtual void                OnPaintContentBg();
            virtual void                OnPaintBorder();
            virtual void                OnPaintContent();


        /*******************************************************************************
        * system handler, triggered from qSysWin
        *******************************************************************************/
        protected:
            virtual void                OnOsResize(const qDimension2D<s32>    &_oldSize,
                                                   const qDimension2D<s32>    &_newSize) override;

            virtual void                OnOsPaint() override;

            virtual bool                OnOsEnter(u32                   _u32Modifiers,
                                                  const qVector2D<s32>  &_v2dLocal,
                                                  const qVector2D<s32>  &_v2dGlobal) override;

            virtual bool                OnOsLeave(u32 _u32Modifiers) override;

            virtual bool                OnOsWheel(u32                     _u32Modifiers,
                                                  s32                     _s32Degree,
                                                  const qVector2D<s32>    &_v2dLocal,
                                                  const qVector2D<s32>    &_v2dGlobal) override;

            virtual bool                OnOsDoubleClick(u32                   _u32Modifiers,
                                                        u32                   _u32MouseButton,
                                                        const qVector2D<s32>  &_v2dLocal,
                                                        const qVector2D<s32>  &_v2dGlobal) override;

            virtual bool                OnOsMousePress(u32                   _u32Modifiers,
                                                       u32                   _u32MouseButton,
                                                       const qVector2D<s32>  &_v2dLocal,
                                                       const qVector2D<s32>  &_v2dGlobal) override;

            virtual bool                OnOsMouseMove(u32                   _u32Modifiers,
                                                      u32                   _u32MouseButton,
                                                      const qVector2D<s32>   &_v2dLocal,
                                                      const qVector2D<s32>   &_v2dGlobal) override;

            virtual bool                OnOsMouseRelease(u32                   _u32Modifiers,
                                                         u32                   _u32MouseButton,
                                                         const qVector2D<s32>  &_v2dLocal,
                                                         const qVector2D<s32>  &_v2dGlobal) override;

            virtual void                OnOsDropUrl(const qUrl  &_url) override;


        /*******************************************************************************
        * qLayoutObj interface
        *******************************************************************************/
        public:
            qDimension2D<s32>           GetMinSize() const;
    }; // class qWin

} // namespace aLib
