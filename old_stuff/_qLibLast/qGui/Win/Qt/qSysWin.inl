/*******************************************************************************
* \file qSysWin.cpp
* \author Andreas Kuhlewind
*
* \brief
*
*  Detailed description starts here.
*******************************************************************************/
#ifdef _USE_QT_


/*******************************************************************************
* includes
*******************************************************************************/
#include "qBaseDefs.h"
#include "qSysWin.h"
#include "qCursor.h"


namespace qLib
{
    /*******************************************************************************
    * qSysWin<T>::qSysWin
    *******************************************************************************/
    template <class T>
    qSysWin<T>::qSysWin(SysWin_t  *_pParent  /* = nullptr */)
    : T(_pParent)
    {
    } // qSysWin<T>::qSysWin


    /*******************************************************************************
    * qSysWin<T>::~qSysWin
    *******************************************************************************/
    template <class T>
    qSysWin<T>::~qSysWin()
    {
    } // qSysWin<T>::~qSysWin


    /*******************************************************************************
    * qSysWin<T>::CreateWin
    *******************************************************************************/
    template <class T>
    bool qSysWin<T>::CreateWin()
    {
        this->setAttribute(Qt::WA_DeleteOnClose);

        if (OnSysCreate() && OnCreate())
        {
            // initialize the ctrk manager
            OnRegisterCtrl();
            UpdateAllCtrls();

            this->setVisible(true);
            return true;
        }
        else
        {
            this->close();
            return false;
        }
    } // qSysWin<T>::CreateWin


    /*******************************************************************************
    * qSysWin<T>::CloseWin
    *******************************************************************************/
    template <class T>
    bool qSysWin<T>::CloseWin()
    {
        if (OnClose())
        {
            this->close();
            return true;
        }

        return false;
    } // qSysWin<T>::CloseWin


    /*******************************************************************************
    * qSysWin<T>::SetParent
    *******************************************************************************/
    template <class T>
    void qSysWin<T>::SetParent(SysWin_t *_pParent)
    {
        this->setParent(_pParent);
        this->SetVisible(true);
    } // qSysWin<T>::SetParent


    /*******************************************************************************
    * qSysWin<T>::Parent
    *******************************************************************************/
    template <class T>
    SysWin_t* qSysWin<T>::Parent() const
    {
        return (this->parentWidget());
    } // qSysWin<T>::SetParent


    /*******************************************************************************
    * qSysWin<T>::SetVisible
    *******************************************************************************/
    template <class T>
    void qSysWin<T>::SetVisible(bool _bVisible)
    {
        this->setVisible(_bVisible);
    } // qSysWin<T>::SetVisible


    /*******************************************************************************
    * qSysWin<T>::IsVisible
    *******************************************************************************/
    template <class T>
    bool qSysWin<T>::IsVisible() const
    {
        return this->isVisible();
    } // qSysWin<T>::IsVisible


    /*******************************************************************************
    * qSysWin<T>::SetMouseTracking
    *******************************************************************************/
    template <class T>
    void qSysWin<T>::SetMouseTracking(bool _bEnable)
    {
        this->setMouseTracking(_bEnable);
    } // qlSysWin<T>::SetMouseTracking


    /*******************************************************************************
    * qSysWin<T>::SetAcceptDrops
    *******************************************************************************/
    template <class T>
    void qSysWin<T>::SetAcceptDrops(bool _bAccept)
    {
        this->setAcceptDrops(_bAccept);
    } // qlSysWin<T>::SetAcceptDrops


    /*******************************************************************************
    * qSysWin<T>::Update
    *******************************************************************************/
    template <class T>
    void qSysWin<T>::Update()
    {
        this->update();
    } // qSysWin<T>::Update


    /*******************************************************************************
    * qSysWin<T>::Update
    *******************************************************************************/
    template <class T>
    void qSysWin<T>::Update(const qRect2D<s32> &_r2dUpdateArea)
    {
        this->update(_r2dUpdateArea.x(), _r2dUpdateArea.y(),
                     _r2dUpdateArea.w(), _r2dUpdateArea.h());
    } // qSysWin<T>::Update


    /*******************************************************************************
    * qSysWin<T>::Repaint
    *******************************************************************************/
    template <class T>
    void qSysWin<T>::Repaint()
    {
        this->repaint();
    } // qSysWin<T>::Repaint


    /*******************************************************************************
    * qSysWin<T>::Geometry
    *******************************************************************************/
    template <class T>
    qRect2D<s32> qSysWin<T>::Geometry() const
    {
        const QRect &r  = this->geometry();

        return qRect2D<s32> (r.x(), r.y(), r.width(), r.height());
    } // qSysWin<T>::Geometry


    /*******************************************************************************
    * qSysWin<T>::SetGeometry
    *******************************************************************************/
    template <class T>
    void qSysWin<T>::SetGeometry(const qRect2D<s32> &_r2d)
    {
        this->setGeometry(_r2d.x(), _r2d.y(), _r2d.w(), _r2d.h());
    } // qSysWin<T>::SetGeometry


    /*******************************************************************************
    * qSysWin<T>::SetGeometry
    *******************************************************************************/
    template <class T>
    void qSysWin<T>::SetGeometry(s32    _s32X,
                                 s32    _s32Y,
                                 s32    _s32W,
                                 s32    _s32H)
    {
        this->setGeometry(_s32X, _s32Y, _s32W, _s32H);
    } // qSysWin<T>::SetGeometry


    /*******************************************************************************
    * qSysWin<T>::ClientRect
    *******************************************************************************/
    template <class T>
    qRect2D<s32> qSysWin<T>::ClientRect() const
    {
        return qRect2D<s32> (0, 0, this->width(), this->height());
    } // qSysWin<T>::ClientRect


    /*******************************************************************************
    * qSysWin<T>::SetMinW
    *******************************************************************************/
    template <class T>
    void qSysWin<T>::SetMinW(s32 _s32MinW)
    {
        this->setMinimumWidth(_s32MinW);
    } // qSysWin<T>::SetMinW


    /*******************************************************************************
    * qSysWin<T>::SetMinH
    *******************************************************************************/
    template <class T>
    void qSysWin<T>::SetMinH(s32 _s32MinH)
    {
        this->setMinimumHeight(_s32MinH);
    } // qSysWin<T>::SetMinH


    /*******************************************************************************
    * qSysWin<T>::SetMinDimension
    *******************************************************************************/
    template <class T>
    void qSysWin<T>::SetMinDimension(const qDimension2D<s32> &_dim)
    {
        this->setMinimumWidth(_dim.w());
        this->setMinimumHeight(_dim.h());
    } // qSysWin<T>::SetMinDimension


    /*******************************************************************************
    * qSysWin<T>::SetMinDimension
    *******************************************************************************/
    template <class T>
    void qSysWin<T>::SetMinDimension(s32 _s32MinW,
                                     s32 _s32MinH)
    {
        this->setMinimumWidth(_s32MinW);
        this->setMinimumHeight(_s32MinH);
    } // qSysWin<T>::SetMinDimension


    /*******************************************************************************
    * qSysWin<T>::SetMaxW
    *******************************************************************************/
    template <class T>
    void qSysWin<T>::SetMaxW(s32 _s32MaxW)
    {
        this->setMaximumWidth(_s32MaxW);
    } // qSysWin<T>::SetMaxW


    /*******************************************************************************
    * qSysWin<T>::SetMaxH
    *******************************************************************************/
    template <class T>
    void qSysWin<T>::SetMaxH(s32 _s32MaxH)
    {
        this->setMaximumHeight(_s32MaxH);
    } // qSysWin<T>::SetMaxH


    /*******************************************************************************
    * qSysWin<T>::SetMaxDimension
    *******************************************************************************/
    template <class T>
    void qSysWin<T>::SetMaxDimension(const qDimension2D<s32> &_dim)
    {
        this->setMaximumWidth(_dim.w());
        this->setMaximumHeight(_dim.h());
    } // qSysWin<T>::SetMaxDimension


    /*******************************************************************************
    * qSysWin<T>::SetMaxDimension
    *******************************************************************************/
    template <class T>
    void qSysWin<T>::SetMaxDimension(s32 _s32MaxW,
                                  s32 _s32MaxH)
    {
        this->setMaximumWidth(_s32MaxW);
        this->setMaximumHeight(_s32MaxH);
    } // qSysWin<T>::SetMaxDimension


    /*******************************************************************************
    * qSysWin<T>::Font
    *******************************************************************************/
    template <class T>
    const qFont& qSysWin<T>::Font() const
    {
        return this->m_font;
    } // qSysWin<T>::Font


    /*******************************************************************************
    * qSysWin<T>::GlobalCursorPos
    *******************************************************************************/
    template <class T>
    qVector2D<s32> qSysWin<T>::GlobalCursorPos()
    {
        QPoint pos = QCursor::pos();

        return qVector2D<s32> (pos.x(), pos.y());
    } // qSysWin<T>::GlobalCursorPos


    /*******************************************************************************
    * qSysWin<T>::SetCursor
    *******************************************************************************/
    template <class T>
    void qSysWin<T>::SetCursor(const qCursor &_cursor)
    {
        this->setCursor(_cursor.ToQCursor());
    } // qSysWin<T>::SetCursor


    /*******************************************************************************
    * qSysWin<T>::Modifiers
    *******************************************************************************/
    template <class T>
    u32 qSysWin<T>::Modifiers() const           // e.g. MODIFIER_SHIFT
    {
        Qt::KeyboardModifiers	mods	= QApplication::keyboardModifiers();
        u32						u32Mods	= MODIFIER_NONE;

        if (mods & Qt::ShiftModifier)
            u32Mods |= MODIFIER_SHIFT;

        if (mods & Qt::ControlModifier)
            u32Mods |= MODIFIER_CTRL;

        if (mods & Qt::AltModifier)
            u32Mods |= MODIFIER_ALT;

        if (mods & Qt::KeypadModifier)
            u32Mods |= MODIFIER_KEYPAD;

        return u32Mods;
    } // qSysWin<T>::Modifiers


    /*******************************************************************************
    * qSysWin<T>::MouseButton
    *******************************************************************************/
    template <class T>
    u32 qSysWin<T>::MouseButton() const
    {
        Qt::MouseButtons    but             = QApplication::mouseButtons();
        u32                 u32MouseButton  = MOUSE_BTN_NONE;

        if (but & Qt::LeftButton)
            u32MouseButton |= MOUSE_BTN_LEFT;

        if (but & Qt::MiddleButton)
            u32MouseButton |= MOUSE_BTN_MIDDLE;

        if (but & Qt::RightButton)
            u32MouseButton |= MOUSE_BTN_RIGHT;

        return u32MouseButton;
    } // qSysWin<T>::MouseButton


    /*******************************************************************************
    * qSysWin<T>::MouseButton
    *******************************************************************************/
    template <class T>
    u32 qSysWin<T>::MouseButton(QMouseEvent *_pEvent) const
    {
        Qt::MouseButtons    but             = _pEvent->buttons();
        u32                 u32MouseButton  = MOUSE_BTN_NONE;

        if (but & Qt::LeftButton)
            u32MouseButton |= MOUSE_BTN_LEFT;

        if (but & Qt::MiddleButton)
            u32MouseButton |= MOUSE_BTN_MIDDLE;

        if (but & Qt::RightButton)
            u32MouseButton |= MOUSE_BTN_RIGHT;

        return u32MouseButton;
    } // qSysWin<T>::MouseButton


    /*******************************************************************************
    * qSysWin<T>::LocalCursorPos
    *******************************************************************************/
    template <class T>
    qVector2D<s32> qSysWin<T>::LocalCursorPos() const
    {
        QPoint pos =this->mapFromGlobal(QCursor::pos());

        return qVector2D<s32> (pos.x(), pos.y());
    } // qSysWin<T>::LocalCursorPos


} // namespace qLib

#endif // _USE_QT_


    /*******************************************************************************
    * qSysWin<T>::ToggleFullScreen
    *******************************************************************************/
    // template <class T>
    // void qSysWin<T>::ToggleFullScreen()
    // {
    //     this->setWindowState(this->windowState() ^ Qt::WindowFullScreen);
    // } // qSysWin<T>::ToggleFullScreen








    // // /*******************************************************************************
    // // * qSysWin<T>::SetEnabled
    // // *******************************************************************************/
    // // void qSysWin<T>::SetEnabled(bool _bEnabled)
    // // {
    // //     this->setEnabled(_bEnabled);
    // // } // qSysWin<T>::SetEnabled


    // // /*******************************************************************************
    // // * qSysWin<T>::IsEnabled
    // // *******************************************************************************/
    // // bool qSysWin<T>::IsEnabled() const
    // // {
    // //     return this->isEnabled();
    // // } // qSysWin<T>::IsEnabled


    // // /*******************************************************************************
    // // * qSysWin<T>::SetObjectName
    // // *******************************************************************************/
    // // void qSysWin<T>::SetObjectName(const aString    &_sTitle)
    // // {
    // //     this->setObjectName(_sTitle);
    // // } // qlSysWin<T>::SetObjectName


    // // /*******************************************************************************
    // // * qSysWin<T>::SetWindowTitle
    // // *******************************************************************************/
    // // void qSysWin<T>::SetWindowTitle(const aString    &_sTitle)
    // // {
    // //     this->setWindowTitle(_sTitle);
    // // } // qlSysWin<T>::SetWindowTitle


    // // /*******************************************************************************
    // // * qSysWin<T>::SetMouseTracking
    // // *******************************************************************************/
    // // void qSysWin<T>::SetMouseTracking(bool   _bEnable)
    // // {
    // //     this->setMouseTracking(_bEnable);
    // // } // qlSysWin<T>::SetMouseTracking


    // // /*******************************************************************************
    // // * qSysWin<T>::SetFocusPolicy
    // // *******************************************************************************/
    // // void qSysWin<T>::SetFocusPolicy(enumFocusPolicy  _ePolicy)
    // // {
    // //     switch (_ePolicy)
    // //     {
    // //     case enumFocusPolicy::NoFocus:
    // //         this->setFocusPolicy(Qt::FocusPolicy::NoFocus);
    // //         break;

    // //     case enumFocusPolicy::TabFocus:
    // //         this->setFocusPolicy(Qt::FocusPolicy::TabFocus);
    // //         break;

    // //     case enumFocusPolicy::ClickFocus:
    // //         this->setFocusPolicy(Qt::FocusPolicy::ClickFocus);
    // //         break;

    // //     case enumFocusPolicy::StrongFocus :
    // //         this->setFocusPolicy(Qt::FocusPolicy::StrongFocus);
    // //         break;

    // //     case enumFocusPolicy::WheelFocus:
    // //         this->setFocusPolicy(Qt::FocusPolicy::WheelFocus);
    // //         break;
    // //     }
    // // } // qlWin::SetFocusPolicy


    // // /*******************************************************************************
    // // * qSysWin<T>::HasFocus
    // // *******************************************************************************/
    // // bool qSysWin<T>::HasFocus() const
    // // {
    // //     return this->hasFocus();
    // // } // qlWin::HasFocus


    // // /*******************************************************************************
    // // * qSysWin<T>::SetCursor
    // // *******************************************************************************/
    // // void qSysWin<T>::SetCursor(const aCursor    &_cursor)
    // // {
    // //     this->setCursor(_cursor.GetQCursor());
    // // } // qlSysWin<T>::SetCursor


    // // /*******************************************************************************
    // // * qSysWin<T>::OnResize
    // // *******************************************************************************/
    // // void qSysWin<T>::OnResize(const Dimension2D<s32>     &/*_d2dOld*/,
    // //                              const Dimension2D<s32>     &/*_d2dNew*/)
    // // {
    // // } // qSysWin<T>::OnResize


    // // /*******************************************************************************
    // // * qSysWin<T>::OnPaintBg
    // // *******************************************************************************/
    // // void qSysWin<T>::OnPaintBg()
    // // {
    // //     aPainter    p(this);

    // //     if (m_rgbaBg != rgbaTransparent)
    // //     {
    // //         p.DrawFilledRect(ClientRect(), &m_rgbaBg);
    // //     }
    // // } // qSysWin<T>::OnPaintBg


    // // /*******************************************************************************
    // // * qSysWin<T>::OnPaint
    // // *******************************************************************************/
    // // void qSysWin<T>::OnPaint()
    // // {
    // // } // qSysWin<T>::OnPaint


    // // /*******************************************************************************
    // // * qSysWin<T>::OnKeyPress
    // // *******************************************************************************/
    // // bool qSysWin<T>::OnKeyPress(u32          /*_u32Modifiers*/,
    // //                                enumKeyCode  /*_eKeyCode*/,
    // //                                aString      /*_sText*/)
    // // {
    // //     return false;
    // // } // qSysWin<T>::OnKeyPress


    // // /*******************************************************************************
    // // * qSysWin<T>::OnEnterWin
    // // *******************************************************************************/
    // // bool qSysWin<T>::OnEnterWin(u32                  /*_u32Modifiers*/,
    // //                                const qVector2D<s32>  &/*_v2dLocalPos*/,
    // //                                const qVector2D<s32>  &/*_v2dGlobalPos*/)
    // // {
    // //     return false;
    // // } // qSysWin<T>::OnEnterWin


    // // /*******************************************************************************
    // // * qSysWin<T>::OnLeaveWin
    // // *******************************************************************************/
    // // bool qSysWin<T>::OnLeaveWin(u32  /*_u32Modifiers*/)
    // // {
    // //     return false;
    // // } // qSysWin<T>::OnLeaveWin


    // // /*******************************************************************************
    // // * qSysWin<T>::OnWheel
    // // *******************************************************************************/
    // // bool qSysWin<T>::OnWheel(const u32			/*_u32Modifiers*/,
    // //                             const s32			/*_s32Degree*/,
    // //                             const qVector2D<s32> /*_v2dLocal*/,
    // //                             const qVector2D<s32> /*_v2dGlobal*/)
    // // {
    // //     return false;
    // // } // qSysWin<T>::OnWheel


    // // /*******************************************************************************
    // // * qSysWin<T>::OnMousePress
    // // *******************************************************************************/
    // // bool qSysWin<T>::OnMousePress(u32                    /*_u32Modifiers*/,
    // //                                  u32                    /*_u32MouseButton*/,
    // //                                  const qVector2D<s32>    & /*_v2dLocal*/,
    // //                                  const qVector2D<s32>    &/*_v2dGlobal*/)
    // // {
    // //     return false;
    // // } // qSysWin<T>::OnMousePress


    // // /*******************************************************************************
    // // * qSysWin<T>::OnMouseMove
    // // *******************************************************************************/
    // // bool qSysWin<T>::OnMouseMove(u32                    /*_u32Modifiers*/,
    // //                                 u32                    /*_u32MouseButton*/,
    // //                                 const qVector2D<s32>    & /*_v2dLocal*/,
    // //                                 const qVector2D<s32>    &/*_v2dGlobal*/)
    // // {
    // //     return false;
    // // } // qSysWin<T>::OnMouseMove


    // // /*******************************************************************************
    // // * qSysWin<T>::OnMouseRelease
    // // *******************************************************************************/
    // // bool qSysWin<T>::OnMouseRelease(u32                    /*_u32Modifiers*/,
    // //                                    u32                    /*_u32MouseButton*/,
    // //                                    const qVector2D<s32>    & /*_v2dLocal*/,
    // //                                    const qVector2D<s32>    &/*_v2dGlobal*/)
    // // {
    // //     return false;
    // // } // qSysWin<T>::OnMouseRelease


    // // /*******************************************************************************
    // // * qSysWin<T>::OnDoubleClick
    // // *******************************************************************************/
    // // bool qSysWin<T>::OnDoubleClick(u32                    /*_u32Modifiers*/,
    // //                                   u32                    /*_u32MouseButton*/,
    // //                                   const qVector2D<s32>    & /*_v2dLocal*/,
    // //                                   const qVector2D<s32>    &/*_v2dGlobal*/)
    // // {
    // //     return false;
    // // } // qSysWin<T>::OnDoubleClick


    // // /*******************************************************************************
    // // * qSysWin<T>::OnDropUrl
    // // *******************************************************************************/
    // // void qSysWin<T>::OnDropUrl(const aUrl   &/*_url*/)
    // // {
    // // } // qSysWin<T>::OnDropUrl


    // // /*******************************************************************************
    // // * qSysWin<T>::closeEvent
    // // *******************************************************************************/
    // // void qSysWin<T>::closeEvent(QCloseEvent *_pEvent)
    // // {
    // //     bool bCanClose = OnClose();

    // //     if (!bCanClose)
    // //     {
    // //         _pEvent->ignore();
    // //     }
    // //     else
    // //     {
    // //         _pEvent->accept();
    // //     }
    // // } // qSysWin<T>::closeEvent
