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
#include "qSysWin.h"
#include "qCursor.h"
#include "qUrl.h"


namespace qLib
{
    /*******************************************************************************
    * qSysWin::qSysWin
    *******************************************************************************/
    qSysWin::qSysWin(SysWin_t  *_pParent  /* = nullptr */)
    : QWidget(_pParent)
    {
        // delete the window when it is beeing closed
        setAttribute(Qt::WA_DeleteOnClose);

        // no frames
        setWindowFlags(windowFlags() | Qt::FramelessWindowHint);

        // no default background painting
        setAttribute(Qt::WA_NoSystemBackground, true);
        setAttribute(Qt::WA_TranslucentBackground, true);
        //setAttribute(Qt::WA_TransparentForMouseEvents, true);
    } // qSysWin::qSysWin


    /*******************************************************************************
    * qSysWin::~qSysWin
    *******************************************************************************/
    qSysWin::~qSysWin()
    {
    } // qSysWin::~qSysWin


    /*******************************************************************************
    * qSysWin::_CloseWin
    *******************************************************************************/
    bool qSysWin::_CloseWin()
    {
        return close();
    } // qSysWin::_CloseWin


    /*******************************************************************************
    * qSysWin::_Parent
    *******************************************************************************/
    SysWin_t* qSysWin::_Parent() const
    {
        return (parentWidget());
    } // qSysWin::_Parent


    /*******************************************************************************
    * qSysWin::_SetParent
    *******************************************************************************/
    void qSysWin::_SetParent(SysWin_t *_pParent)
    {
        setParent(_pParent);
        setVisible(true);
    } // qSysWin::_SetParent


    /*******************************************************************************
    * qSysWin::_IsVisible
    *******************************************************************************/
    bool qSysWin::_IsVisible() const
    {
        return isVisible();
    } // qSysWin::_IsVisible


    /*******************************************************************************
    * qSysWin::_SetVisible
    *******************************************************************************/
    void qSysWin::_SetVisible(bool _bVisible)
    {
        setVisible(_bVisible);
    } // qSysWin::_SetVisible


    /*******************************************************************************
    * qSysWin::_IsDisabled
    *******************************************************************************/
    bool qSysWin::_IsDisabled() const
    {
        return !isEnabled();
    } // qSysWin::_IsDisabled


    /*******************************************************************************
    * qSysWin::_SetDisabled
    *******************************************************************************/
    void qSysWin::_SetDisabled(bool _bDisabled)
    {
        setDisabled(_bDisabled);
    } // qSysWin::_SetDisabled


    /*******************************************************************************
    * qSysWin::_Geometry
    *******************************************************************************/
    qRect2D<s32> qSysWin::_Geometry() const
    {
        const QRect &r  = this->geometry();

        return qRect2D<s32> (r.x(), r.y(), r.width(), r.height());
    } // qSysWin::_Geometry


    /*******************************************************************************
    * qSysWin::_w
    *******************************************************************************/
    s32 qSysWin::_w() const
    {
        return width();
    } // qSysWin::_w


    /*******************************************************************************
    * qSysWin::_h
    *******************************************************************************/
    s32 qSysWin::_h() const
    {
        return height();
    } // qSysWin::_h


    /*******************************************************************************
    * qSysWin::_SetGeometry
    *******************************************************************************/
    void qSysWin::_SetGeometry(s32 _x,
                               s32 _y,
                               s32 _w,
                               s32 _h)
    {
        setGeometry(_x, _y, _w, _h);
    } // qSysWin::_SetGeometry


    /*******************************************************************************
    * qSysWin::_SetPosition
    *******************************************************************************/
    void qSysWin::_SetPosition(s32 _x,
                               s32 _y)
    {
        move(_x, _y);
    } // qSysWin::_SetPosition


    /*******************************************************************************
    * qSysWin::_ShowMaximized
    *******************************************************************************/
    void qSysWin::_ShowMaximized()
    {
        //setWindowState(this->windowState() ^ Qt::WindowFullScreen);

        showMaximized();
    } // qSysWin::_ShowMaximized


    /*******************************************************************************
    * qSysWin::_ShowMinimized
    *******************************************************************************/
    void qSysWin::_ShowMinimized()
    {
        showMinimized();
    } // qSysWin::_ShowMinimized


    /*******************************************************************************
    * qSysWin::_ShowNormal
    *******************************************************************************/
    void qSysWin::_ShowNormal()
    {
        showNormal();
    } // qSysWin::_ShowNormal


    /*******************************************************************************
    * qSysWin::_IsMaximized
    *******************************************************************************/
    bool qSysWin::_IsMaximized() const
    {
        return isMaximized();
    } // qSysWin::_IsMaximized


    /*******************************************************************************
    * qSysWin::_IsMinimized
    *******************************************************************************/
    bool qSysWin::_IsMinimized() const
    {
        return isMinimized();
    } // qSysWin::_IsMinimized


    /*******************************************************************************
    * qSysWin::_GlobalCursorPos
    *******************************************************************************/
    qVector2D<s32> qSysWin::_GlobalCursorPos()
    {
        QPoint pos = QCursor::pos();

        return qVector2D<s32> (pos.x(), pos.y());
    } // qSysWin::_GlobalCursorPos


    /*******************************************************************************
    * qSysWin::_Modifiers
    *******************************************************************************/
    u32 qSysWin::_Modifiers() const           // e.g. MODIFIER_SHIFT
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
    } // qSysWin::_Modifiers


    /*******************************************************************************
    * qSysWin::_MouseButton
    *******************************************************************************/
    u32 qSysWin::_MouseButton() const
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
    } // qSysWin::_MouseButton


    /*******************************************************************************
    * qSysWin::_MouseButton
    *******************************************************************************/
    u32 qSysWin::_MouseButton(QMouseEvent *_pEvent) const
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
    } // qSysWin::_MouseButton


    /*******************************************************************************
    * qSysWin::_LocalCursorPos
    *******************************************************************************/
    qVector2D<s32> qSysWin::_LocalCursorPos() const
    {
        QPoint pos =this->mapFromGlobal(QCursor::pos());

        return qVector2D<s32> (pos.x(), pos.y());
    } // qSysWin::_LocalCursorPos


    /*******************************************************************************
    * qSysWin::_SetMouseTracking
    *******************************************************************************/
    void qSysWin::_SetMouseTracking(bool _bEnable)
    {
        setMouseTracking(_bEnable);
    } // qSysWin::_SetMouseTracking


    /*******************************************************************************
    * qSysWin::_EnableDrop
    *******************************************************************************/
    void qSysWin::_EnableDrop(bool _bEnable)
    {
        setAcceptDrops(_bEnable);
    } // qSysWin::_EnableDrop


    /*******************************************************************************
    * qSysWin::_SetCursor
    *******************************************************************************/
    void qSysWin::_SetCursor(const qCursor &_cursor)
    {
        return setCursor(_cursor);
    } // qSysWin::_SetCursor


    /*******************************************************************************
    * qSysWin::_Update
    *******************************************************************************/
    void qSysWin::_Update()
    {
        update();
    } // qSysWin::_Update


    /*******************************************************************************
    * qSysWin::_Repaint
    *******************************************************************************/
    void qSysWin::_Repaint()
    {
        repaint();
    } // qSysWin::_Repaint


    /*******************************************************************************
    * qSysWin::resizeEvent
    *******************************************************************************/
    void qSysWin::resizeEvent(QResizeEvent *_pEvent)
    {
        OnOsResize(qDimension2D<s32> (_pEvent->oldSize().width(), _pEvent->oldSize().height()),
                   qDimension2D<s32> (_pEvent->size().width(), _pEvent->size().height()));
    } // qSysWin::resizeEvent


    /*******************************************************************************
    * qSysWin::paintEvent
    *******************************************************************************/
    void qSysWin::paintEvent(QPaintEvent */*_pEvent*/)
    {
        OnOsPaint();
    } // qSysWin::paintEvent


    /*******************************************************************************
    * qSysWin::enterEvent
    *******************************************************************************/
    void qSysWin::enterEvent(QEnterEvent *_pEvent)
    {
        u32             u32Modifiers = _Modifiers();
        qVector2D<s32>  v2dLocal(_pEvent->globalPosition().x(), _pEvent->globalPosition().y());
        qVector2D<s32>  v2dGlobal(_pEvent->position().x(), _pEvent->position().y());

        _pEvent->setAccepted(OnOsEnter(u32Modifiers, v2dLocal, v2dGlobal));
    } // qSysWin::enterEvent


    /*******************************************************************************
    * qSysWin::leaveEvent
    *******************************************************************************/
    void qSysWin::leaveEvent(QEvent *_pEvent)
    {
        u32 u32Modifiers = _Modifiers();

        _pEvent->setAccepted(OnOsLeave(u32Modifiers));
    } // qSysWin::leaveEvent


    /*******************************************************************************
    * qSysWin::wheelEvent
    *******************************************************************************/
    void qSysWin::wheelEvent(QWheelEvent *_pEvent)
    {
        u32             u32Modifiers    = _Modifiers();
        qVector2D<s32>  v2dLocal        = _LocalCursorPos();
        qVector2D<s32>  v2dGlobal       = _GlobalCursorPos();
        s32             s32Degree       = (s32) (((dbl) _pEvent->angleDelta().y()) / 8.);

        _pEvent->setAccepted(OnOsWheel(u32Modifiers, s32Degree, v2dLocal, v2dGlobal));
    } // qSysWin::wheelEvent


    /*******************************************************************************
    * qSysWin::mouseDoubleClickEvent
    *******************************************************************************/
    void qSysWin::mouseDoubleClickEvent(QMouseEvent *_pEvent)
    {
        u32             u32Modifiers    = _Modifiers();
        u32             u32MouseButton	= _MouseButton(_pEvent);
        qVector2D<s32>  v2dLocal        = _LocalCursorPos();
        qVector2D<s32>  v2dGlobal       = _GlobalCursorPos();

        _pEvent->setAccepted(OnOsDoubleClick(u32Modifiers, u32MouseButton, v2dLocal, v2dGlobal));
    } // qSysWin::mouseDoubleClickEvent


    /*******************************************************************************
    * qSysWin::mousePressEvent
    *******************************************************************************/
    void qSysWin::mousePressEvent(QMouseEvent *_pEvent)
    {
        u32             u32Modifiers    = _Modifiers();
        u32             u32MouseButton	= _MouseButton(_pEvent);
        qVector2D<s32>  v2dLocal        = _LocalCursorPos();
        qVector2D<s32>  v2dGlobal       = _GlobalCursorPos();

        _pEvent->setAccepted(OnOsMousePress(u32Modifiers, u32MouseButton, v2dLocal, v2dGlobal));
    } // qSysWin::mousePressEvent


    /*******************************************************************************
    * qSysWin::mouseMoveEvent
    *******************************************************************************/
    void qSysWin::mouseMoveEvent(QMouseEvent *_pEvent)
    {
        u32             u32Modifiers    = _Modifiers();
        u32             u32MouseButton	= _MouseButton(_pEvent);
        qVector2D<s32>  v2dLocal        = _LocalCursorPos();
        qVector2D<s32>  v2dGlobal       = _GlobalCursorPos();

        _pEvent->setAccepted(OnOsMouseMove(u32Modifiers, u32MouseButton, v2dLocal, v2dGlobal));
    } // qSysWin::mouseMoveEvent


    /*******************************************************************************
    * qSysWin::mouseReleaseEvent
    *******************************************************************************/
    void qSysWin::mouseReleaseEvent(QMouseEvent *_pEvent)
    {
        u32             u32Modifiers    = _Modifiers();
        u32             u32MouseButton	= _MouseButton(_pEvent);
        qVector2D<s32>  v2dLocal        = _LocalCursorPos();
        qVector2D<s32>  v2dGlobal       = _GlobalCursorPos();

        _pEvent->setAccepted(OnOsMouseRelease(u32Modifiers, u32MouseButton, v2dLocal, v2dGlobal));
    } // qSysWin::mouseReleaseEvent


    /*******************************************************************************
    * qSysWin::dragEnterEvent
    *******************************************************************************/
    void qSysWin::dragEnterEvent(QDragEnterEvent *_pEvent)
    {
        if (_pEvent->mimeData()->hasUrls())
        {
            _pEvent->acceptProposedAction();
        }
            else
        {
            _pEvent->ignore();
        }
    } // qSysWin::dragEnterEvent


    /*******************************************************************************
    * qSysWin::dragMoveEvent
    *******************************************************************************/
    void qSysWin::dragMoveEvent(QDragMoveEvent *_pEvent)
    {
        if (_pEvent->mimeData()->hasUrls())
        {
            _pEvent->acceptProposedAction();
        }
            else
        {
            _pEvent->ignore();
        }
    } // qSysWin::dragMoveEvent
\

    /*******************************************************************************
    * qSysWin::dropEvent
    *******************************************************************************/
    void qSysWin::dropEvent(QDropEvent   *_pEvent)
    {
        if (_pEvent->mimeData()->hasUrls())
        {
            _pEvent->acceptProposedAction();
    \
            foreach (QUrl url, _pEvent->mimeData()->urls())
            {
               OnOsDropUrl(qUrl(url));
            }
        }
    } // qSysWin::dropEvent


} // namespace qLib

#endif // _USE_QT_
