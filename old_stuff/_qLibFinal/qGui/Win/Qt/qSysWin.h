/*******************************************************************************
* \file qSysWin.h
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
#include "qGuiDefs.h"
#include "qWinStyle.h"
#include "qRect2D.h"


namespace qLib
{
    /*******************************************************************************
    * forward
    *******************************************************************************/
    class qCursor;
    class qUrl;


    /*******************************************************************************
    * class qSysWin
    *******************************************************************************/
    class qSysWin : public QWidget
    {
        protected:
            qSysWin(SysWin_t  *_pParent = nullptr);
            ~qSysWin();

        protected:
            bool                _CloseWin();

            SysWin_t*           _Parent() const;
            void                _SetParent(SysWin_t *_pParent); // can be nullptr

            bool                _IsVisible() const;
            void                _SetVisible(bool _bVisible);

            bool                _IsDisabled() const;
            void                _SetDisabled(bool _bDisabled);

            qRect2D<s32>        _Geometry() const;
            s32                 _w() const;
            s32                 _h() const;

            void                _SetGeometry(s32 _x,
                                             s32 _y,
                                             s32 _w,
                                             s32 _h);

            void                _SetPosition(s32 _x,
                                             s32 _y);

            void                _ShowMaximized();
            void                _ShowMinimized();
            void                _ShowNormal();
            bool                _IsMaximized() const;
            bool                _IsMinimized() const;

            qVector2D<s32>      _GlobalCursorPos();
            u32                 _Modifiers() const;
            u32                 _MouseButton() const;
            u32                 _MouseButton(QMouseEvent *_pEvent) const;
            qVector2D<s32>      _LocalCursorPos() const;

            void                _SetMouseTracking(bool _bEnable);

            void                _EnableDrop(bool _bAccept);

            void                _SetCursor(const qCursor &_cursor);

            void                _Update();      // update queue
            void                _Repaint();     // updates immidiately


        /*******************************************************************************
        * event handler
        *******************************************************************************/
        protected:
            virtual void        OnOsResize(const qDimension2D<s32>    &_oldSize,
                                           const qDimension2D<s32>    &_newSize) = 0;

            virtual void        OnOsPaint() = 0;

            virtual bool        OnOsEnter(u32                   _u32Modifiers,
                                          const qVector2D<s32>    &_v2dLocal,
                                          const qVector2D<s32>    &_v2dGlobal) = 0;

            virtual bool        OnOsLeave(u32 _u32Modifiers) = 0;

            virtual bool        OnOsWheel(u32                     _u32Modifiers,
                                          s32                     _s32Degree,
                                          const qVector2D<s32>    &_v2dLocal,
                                          const qVector2D<s32>    &_v2dGlobal) = 0;

            virtual bool        OnOsDoubleClick(u32                   _u32Modifiers,
                                                u32                   _u32MouseButton,
                                                const qVector2D<s32>  &_v2dLocal,
                                                const qVector2D<s32>  &_v2dGlobal) = 0;

            virtual bool        OnOsMousePress(u32                   _u32Modifiers,
                                               u32                   _u32MouseButton,
                                               const qVector2D<s32>  &_v2dLocal,
                                               const qVector2D<s32>  &_v2dGlobal) = 0;

            virtual bool        OnOsMouseMove(u32                   _u32Modifiers,
                                              u32                   _u32MouseButton,
                                              const qVector2D<s32>   &_v2dLocal,
                                              const qVector2D<s32>   &_v2dGlobal) = 0;

            virtual bool        OnOsMouseRelease(u32                   _u32Modifiers,
                                                 u32                   _u32MouseButton,
                                                 const qVector2D<s32>  &_v2dLocal,
                                                 const qVector2D<s32>  &_v2dGlobal) = 0;

            virtual void        OnOsDropUrl(const qUrl  &_url) = 0;


        /*******************************************************************************
        * system events
        *******************************************************************************/
        private:
            virtual void        resizeEvent(QResizeEvent *_pEvent) override;
            virtual void        paintEvent(QPaintEvent *_pEvent) override;

            virtual void        enterEvent(QEnterEvent *_pEvent) override;
            virtual void        leaveEvent(QEvent *event) override;

            virtual void        wheelEvent(QWheelEvent *_pEvent) override;
            virtual void        mouseDoubleClickEvent(QMouseEvent *_pEvent) override;
            virtual void        mousePressEvent(QMouseEvent *_pEvent) override;
            virtual void        mouseMoveEvent(QMouseEvent *_pEvent) override;
            virtual void        mouseReleaseEvent(QMouseEvent *_pEvent) override;

            virtual void        dragEnterEvent(QDragEnterEvent *_pEvent) override;
            virtual void        dragMoveEvent(QDragMoveEvent *_pEvent) override;
            virtual void        dropEvent(QDropEvent   *_pEvent) override;

    }; // class qSysWin

} // namespace qLib


#endif // _USE_QT_
