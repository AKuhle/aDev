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
// #include <QKeyEvent>
// #include <QWheelEvent>

#include "qGuiDefs.h"
#include "qCtrlMgr.h"
#include "qToolMgr.h"
#include "qVector2D.h"
#include "qDimension2D.h"
#include "qRect2D.h"
#include "qUrl.h"
#include "qFont.h"



namespace qLib
{
    /*******************************************************************************
    * forward
    *******************************************************************************/
    class qCursor;
    class qFont;


    /*******************************************************************************
    * class qSysWin
    *******************************************************************************/
    template <class T>
    class qSysWin : public T,
                    public qCtrlMgr,
                    public qToolMgr
    {
        private:
            qFont                       m_font;

        protected:
            qSysWin(SysWin_t  *_pParent = nullptr);
            ~qSysWin();

        public:
            bool                        CreateWin();
            bool                        CloseWin();

            void                        SetParent(SysWin_t *_pParent); // can be nullptr
            SysWin_t*                   Parent() const;

            void                        SetVisible(bool _bVisible);
            bool                        IsVisible() const;

            void                        SetMouseTracking(bool _bEnable);

            void                        SetAcceptDrops(bool _bAccept);

            void                        Update(); // repaint through queue
            void                        Update(const qRect2D<s32> &_r2dUpdateArea);
            void                        Repaint(); // repaint immediately

            // rect within parent (x, y, w, h)
            qRect2D<s32>                Geometry() const;

            void                        SetGeometry(const qRect2D<s32> &_r2d);

            void                        SetGeometry(s32 _s32X,
                                                    s32 _s32Y,
                                                    s32 _s32W,
                                                    s32 _s32H);

            // (0, 0, w, h)
            qRect2D<s32>                ClientRect() const;

            void                        SetMinW(s32 _s32MinW);
            void                        SetMinH(s32 _s32MinH);
            void                        SetMinDimension(const qDimension2D<s32> &_dim);
            void                        SetMinDimension(s32 _s32MinW,
                                                        s32 _s32MinH);

            void                        SetMaxW(s32 _s32MaxW);
            void                        SetMaxH(s32 _s32MaxH);
            void                        SetMaxDimension(const qDimension2D<s32> &_dim);
            void                        SetMaxDimension(s32 _s32MaxW,
                                                        s32 _s32MaxH);

            const qFont&                Font() const;

            static qVector2D<s32>       GlobalCursorPos();
            void                        SetCursor(const qCursor &_cursor);

        protected:
            u32                         Modifiers() const;
            u32                         MouseButton() const;
            u32                         MouseButton(QMouseEvent *_pEvent) const;
            qVector2D<s32>              LocalCursorPos() const;


        /*******************************************************************************
        * handler
        *******************************************************************************/
        protected:
            virtual bool                OnSysCreate();
            virtual bool                OnCreate();
            virtual bool                OnClose();

            virtual void                OnSysResize(const qDimension2D<s32>    &_d2dOld,
                                                    const qDimension2D<s32>    &_d2dNew);

            virtual void                OnResize(const qDimension2D<s32>    &_d2dOld,
                                                 const qDimension2D<s32>    &_d2dNew);

            virtual void                OnPaintBg();
            virtual void                OnPaint();

            virtual void                OnDropUrl(const qUrl &_url);

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


        /*******************************************************************************
        * interfasce of qCtrlManager
        *******************************************************************************/
        protected:
            virtual void                OnRegisterCtrl() override;
            virtual void                OnUpdateCtrl(qCtrlI *_pCtrl) override;


        #define	DECLARE_PAINT_EVENT\
        protected:\
            virtual void paintEvent(QPaintEvent */*_pEvent*/) override\
            {\
                OnPaintBg();\
                OnPaint();\
                ToolMgrOnPaintToolMarker();\
            }


        #define	DECLARE_RESIZE_EVENT\
        protected:\
            virtual void resizeEvent(QResizeEvent *_pEvent) override\
            {\
                OnSysResize(qDimension2D<s32> (_pEvent->oldSize().width(), _pEvent->oldSize().height()),\
                            qDimension2D<s32> (_pEvent->size().width(), _pEvent->size().height()));\
            \
                OnResize(qDimension2D<s32> (_pEvent->oldSize().width(), _pEvent->oldSize().height()),\
                         qDimension2D<s32> (_pEvent->size().width(), _pEvent->size().height()));\
            }


        #define	DECLARE_WHEEL_EVENT\
        protected:\
            virtual void wheelEvent(QWheelEvent *_pEvent) override\
            {\
                u32             u32Modifiers    = Modifiers();\
                qVector2D<s32>  v2dLocal        = LocalCursorPos();\
                qVector2D<s32>  v2dGlobal       = GlobalCursorPos();\
                s32             s32Degree       = (s32) (((dbl) _pEvent->angleDelta().y()) / 8.);\
\
                _pEvent->setAccepted(ToolMgrOnWheel(u32Modifiers, s32Degree, v2dLocal, v2dGlobal) ||\
                                     OnWheel(u32Modifiers, s32Degree, v2dLocal, v2dGlobal));\
            }


        #define DECLARE_DOUBLE_CLICK_EVENT\
        protected:\
            virtual void mouseDoubleClickEvent(QMouseEvent *_pEvent) override\
            {\
                u32             u32Modifiers	= Modifiers();\
                u32             u32MouseButton	= MouseButton(_pEvent);\
                qVector2D<s32>  v2dLocal        = LocalCursorPos();\
                qVector2D<s32>  v2dGlobal       = GlobalCursorPos();\
    \
                _pEvent->setAccepted(ToolMgrOnDoubleClick(u32Modifiers, u32MouseButton, v2dLocal, v2dGlobal) ||\
                                     OnDoubleClick(u32Modifiers, u32MouseButton, v2dLocal, v2dGlobal));\
            }


        #define DECLARE_MOUSE_PRESS_EVENT\
        protected:\
            virtual void mousePressEvent(QMouseEvent *_pEvent) override\
            {\
                u32             u32Modifiers	= Modifiers();\
                u32             u32MouseButton	= MouseButton(_pEvent);\
                qVector2D<s32>  v2dLocal        = LocalCursorPos();\
                qVector2D<s32>  v2dGlobal       = GlobalCursorPos();\
\
                _pEvent->setAccepted(ToolMgrOnMousePress(u32Modifiers, u32MouseButton, v2dLocal, v2dGlobal) ||\
                                     OnMousePress(u32Modifiers, u32MouseButton, v2dLocal, v2dGlobal));\
            }


        #define DECLARE_MOUSE_MOVE_EVENT\
        protected:\
            virtual void mouseMoveEvent(QMouseEvent *_pEvent) override\
            {\
               u32             u32Modifiers	= Modifiers();\
                u32             u32MouseButton	= MouseButton(_pEvent);\
                qVector2D<s32>  v2dLocal        = LocalCursorPos();\
                qVector2D<s32>  v2dGlobal       = GlobalCursorPos();\
    \
                _pEvent->setAccepted(ToolMgrOnMouseMove(u32Modifiers, u32MouseButton, v2dLocal, v2dGlobal) ||\
                                     OnMouseMove(u32Modifiers, u32MouseButton, v2dLocal, v2dGlobal));\
            }


        #define DECLARE_MOUSE_RELEASE_EVENT\
        protected:\
            virtual void mouseReleaseEvent(QMouseEvent *_pEvent) override\
            {\
                u32             u32Modifiers	= Modifiers();\
                u32             u32MouseButton	= MouseButton(_pEvent);\
                qVector2D<s32>  v2dLocal        = LocalCursorPos();\
                qVector2D<s32>  v2dGlobal       = GlobalCursorPos();\
    \
                _pEvent->setAccepted(ToolMgrOnMouseRelease(u32Modifiers, u32MouseButton, v2dLocal, v2dGlobal) ||\
                                     OnMouseRelease(u32Modifiers, u32MouseButton, v2dLocal, v2dGlobal));\
            }


        /*******************************************************************************
        * drag drop
        *******************************************************************************/
        #define	DECLARE_DROP_EVENT\
        protected:\
            virtual void dragEnterEvent(QDragEnterEvent *_pEvent) override\
            {\
                if (_pEvent->mimeData()->hasUrls())\
                {\
                    _pEvent->acceptProposedAction();\
                }\
                else\
                {\
                    _pEvent->ignore();\
                }\
            }\
\
            virtual void dragMoveEvent(QDragMoveEvent *_pEvent) override\
            {\
                if (_pEvent->mimeData()->hasUrls())\
                {\
                    _pEvent->acceptProposedAction();\
                }\
                else\
                {\
                    _pEvent->ignore();\
                }\
            }\
\
            virtual void dropEvent(QDropEvent   *_pEvent) override\
            {\
                if (_pEvent->mimeData()->hasUrls())\
                {\
                    _pEvent->acceptProposedAction();\
    \
                    foreach (QUrl url, _pEvent->mimeData()->urls())\
                    {\
                        OnDropUrl(qUrl(url));\
                    }\
                }\
            }\

    }; // class qSysWin

} // namespace qLib

#include "qSysWin.inl"
#include "qSysWin_handler.inl"

#endif // _USE_QT_







        // public:
            // void                        SetEnabled(bool _bEnabled);
            // bool                        IsEnabled() const;

            // void                        SetBgColor(const Rgba &_rgbaBg)     { m_rgbaBg = _rgbaBg; }

            // void                        SetObjectName(const aString    &_sTitle);

            // void                        SetWindowTitle(const aString    &_sTitle);

            // void                        SetMouseTracking(bool   _bEnable);

            // void                        SetFocusPolicy(enumFocusPolicy  _ePolicy);
            // bool                        HasFocus() const;

            // void                        SetCursor(const aCursor    &_cursor);

            // void                        ToggleFullScreen();


        /*******************************************************************************
        * handler
        *******************************************************************************/
        // protected:
            // virtual bool                OnKeyPress(u32          _u32Modifiers,
            //                                        enumKeyCode  _eKeyCode,
            //                                        aString      _sText);

            // virtual bool                OnEnterWin(u32                  _u32Modifiers,
            //                                        const Vector2D<s32>  &_v2dLocalPos,
            //                                        const Vector2D<s32>  &_v2dGlobalPos);

            // virtual bool                OnLeaveWin(u32  _u32Modifiers);

            // virtual bool                OnDoubleClick(u32                   _u32Modifiers,
            //                                           u32                   _u32MouseButton,
            //                                           const Vector2D<s32>   &_v2dLocal,
            //                                           const Vector2D<s32>   &_v2dGlobal);

            // virtual void                OnDropUrl(const aUrl   &_url);


        /*******************************************************************************
        * qt-events
        *******************************************************************************/
        // private:
            //virtual void                closeEvent(QCloseEvent *_pEvent) override;



//         /*******************************************************************************
//         * key-events
//         *******************************************************************************/
//         #define	DECLARE_KEY_PRESS_EVENT
//         virtual void keyPressEvent(QKeyEvent *_pEvent) override
//         {
//             u32         u32Modifiers    = Modifiers();
//             enumKeyCode eKeyCode        = aKey::QtKey2KeyCode(_pEvent->key());
//             aString     s               = _pEvent->text();
//
//             _pEvent->setAccepted(ToolManagerOnKeyPress(u32Modifiers, eKeyCode, s) ||
//                                  OnKeyPress(u32Modifiers, eKeyCode, s));
//         }

//         #define	DECLARE_KEY_RELEASE_EVENT
//         virtual void keyReleaseEvent(QKeyEvent *_pEvent) override
//         {
//                 u32         u32Modifiers    = Modifiers();
//                 enumKeyCode eKeyCode        = aKey::QtKey2KeyCode(_pEvent->key());
//                 aString     s               = _pEvent->text();
//
//                 _pEvent->setAccepted(ToolManagerOnKeyRelease(u32Modifiers, eKeyCode, s) ||
//                                      OnKeyRelease(u32Modifiers, eKeyCode, s));
//         }


//         /*******************************************************************************
//         * mouse events
//         *******************************************************************************/
//         #define	DECLARE_ENTER_WINDOW_EVENT
//         virtual void enterEvent(QEvent *_pEvent) override
//         {
//             u32             u32Modifiers	= Modifiers();
//             Vector2D<s32>   v2dLocalPos     = LocalCursorPos();
//             Vector2D<s32>   v2dGlobalPos    = GlobalCursorPos();
//
//             _pEvent->setAccepted(ToolManagerOnEnterWin(u32Modifiers, v2dLocalPos, v2dGlobalPos) ||
//                                  OnEnterWin(u32Modifiers, v2dLocalPos, v2dGlobalPos));
//         }


//         #define	DECLARE_LEAVE_WINDOW_EVENT
//         virtual void leaveEvent(QEvent *_pEvent) override
//         {
//             u32                 u32Modifiers	= Modifiers();
//
//             _pEvent-> setAccepted(ToolManagerOnLeaveWin(u32Modifiers) ||
//                                   OnLeaveWin(u32Modifiers));
//         }
