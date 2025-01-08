/*******************************************************************************
* \file qSysWinQt.cpp
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
#include <QApplication>
#include <QResizeEvent>

#include "Win/winDefs.h"

#include "Math/qDimension2D.h"
#include "Math/qRect2D.h"

#include "Graphic/qCursor.h"

#include "Win/FrameWin/qSysWin_qt.h"
#include "Win/FrameWin/qWin.h"

using namespace qLib::Graphic;
using namespace qLib::Math;


/*******************************************************************************
* namespace
*******************************************************************************/
namespace qLib {
namespace Win {
namespace SysQt {


/*******************************************************************************
* qSysWinQt::qSysWinQt
*******************************************************************************/
qSysWinQt::qSysWinQt(qSysWinQt  *_pParent  /* = nullptr */)
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
} // qSysWinQt::qSysWinQt


/*******************************************************************************
* qSysWinQt::~qSysWinQt
*******************************************************************************/
qSysWinQt::~qSysWinQt()
{
} // qSysWinQt::~qSysWinQt


/*******************************************************************************
* qSysWinQt::parent
*******************************************************************************/
qWin* qSysWinQt::parent() const
{
    return (static_cast<qWin *> (QWidget::parentWidget()));
} // qSysWinQt::parent


/*******************************************************************************
* qSysWinQt::setParent
*******************************************************************************/
void qSysWinQt::setParent(qWin *_pParent)
{
    QWidget::setParent(_pParent);
    QWidget::setVisible(true);
} // qSysWinQt::setParent


/*******************************************************************************
* qSysWinQt::globalCursorPos
*******************************************************************************/
qVector2D<s32> qSysWinQt::globalCursorPos() const
{
    QPoint pos = QCursor::pos();

    return qVector2D<s32> (pos.x(), pos.y());
} // qSysWinQt::globalCursorPos


/*******************************************************************************
* qSysWinQt::localCursorPos
*******************************************************************************/
qVector2D<s32> qSysWinQt::localCursorPos() const
{
    QPoint pos = mapFromGlobal(QCursor::pos());

    return qVector2D<s32> (pos.x(), pos.y());
} // qSysWinQt::localCursorPos


/*******************************************************************************
* qSysWinQt::modifiers
*******************************************************************************/
u32 qSysWinQt::modifiers() const           // e.g. MODIFIER_SHIFT
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
} // qSysWinQt::modifiers


/*******************************************************************************
* qSysWinQt::mouseButton
*******************************************************************************/
u32 qSysWinQt::mouseButton() const
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
} // qSysWinQt::mouseButton


/*******************************************************************************
* qSysWinQt::mouseButton
*******************************************************************************/
u32 qSysWinQt::mouseButton(QMouseEvent *_pEvent) const
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
} // qSysWinQt::mouseButton


/*******************************************************************************
* qSysWinQt::setMouseTracking
*******************************************************************************/
void qSysWinQt::setMouseTracking(bool _bEnable)
{
    QWidget::setMouseTracking(_bEnable);
} // qSysWinQt::setMouseTracking


/*******************************************************************************
* qSysWinQt::setCursor
*******************************************************************************/
void qSysWinQt::setCursor(const qCursor &_cursor)
{
    QWidget::setCursor(_cursor);
} // qSysWinQt::setCursor


/*******************************************************************************
* qSysWinQt::setVisible
*******************************************************************************/
void qSysWinQt::setVisible(bool _bVisible)
{
    QWidget::setVisible(_bVisible);
} // qSysWinQt::setVisible


/*******************************************************************************
* qSysWinQt::isVisible
*******************************************************************************/
bool qSysWinQt::isVisible() const
{
    return QWidget::isVisible();
} // qSysWinQt::isVisible


/*******************************************************************************
* qSysWinQt::show
*******************************************************************************/
void qSysWinQt::show()
{
    QWidget::show();
} // qSysWinQt::show


/*******************************************************************************
* qSysWinQt::hide
*******************************************************************************/
void qSysWinQt::hide()
{
    QWidget::hide();
} // qSysWinQt::hide


/*******************************************************************************
* qSysWinQt::showMaximized
*******************************************************************************/
void qSysWinQt::showMaximized()
{
    //setWindowState(this->windowState() ^ Qt::WindowFullScreen);

    QWidget::showMaximized();
} // qSysWinQt::showMaximized


/*******************************************************************************
* qSysWinQt::showMinimized
*******************************************************************************/
void qSysWinQt::showMinimized()
{
    QWidget::showMinimized();
} // qSysWinQt::showMinimized


/*******************************************************************************
* qSysWinQt::showNormal
*******************************************************************************/
void qSysWinQt::showNormal()
{
    QWidget::showNormal();
} // qSysWinQt::showNormal


/*******************************************************************************
* qSysWinQt::isMaximized
*******************************************************************************/
bool qSysWinQt::isMaximized() const
{
    return QWidget::isMaximized();
} // qSysWinQt::isMaximized


/*******************************************************************************
* qSysWinQt::isMinimized
*******************************************************************************/
bool qSysWinQt::isMinimized() const
{
    return QWidget::isMinimized();
} // qSysWinQt::isMinimized


/*******************************************************************************
* qSysWinQt::geometry
*******************************************************************************/
qRect2D<s32> qSysWinQt::geometry() const
{
    const QRect &r = QWidget::geometry();

    return qRect2D<s32>(r.x(),
                        r.y(),
                        r.width(),
                        r.height());
} // qSysWinQt::geometry


/*******************************************************************************
* qSysWinQt::setGeometry
*******************************************************************************/
void qSysWinQt::setGeometry(s32 _x,
                            s32 _y,
                            s32 _w,
                            s32 _h)
{
    QWidget::setGeometry(_x, _y, _w, _h);
} // qSysWinQt::setGeometry


/*******************************************************************************
* qSysWinQt::setGeometry
*******************************************************************************/
void qSysWinQt::setGeometry(const qRect2D<s32> &_r2d)
{
    QWidget::setGeometry(_r2d.x(), _r2d.y(), _r2d.w(), _r2d.h());
} // qSysWinQt::setGeometry


/*******************************************************************************
* qSysWinQt::w
*******************************************************************************/
s32 qSysWinQt::w() const
{
    return width();
} // qSysWinQt::w


/*******************************************************************************
* qSysWinQt::h
*******************************************************************************/
s32 qSysWinQt::h() const
{
    return height();
} // qSysWinQt::h


/*******************************************************************************
* qSysWinQt::resizeEvent
*******************************************************************************/
void qSysWinQt::resizeEvent(QResizeEvent *_pEvent)
{
    onResizeEvent(qDimension2D<s32> (_pEvent->oldSize().width(), _pEvent->oldSize().height()),
                  qDimension2D<s32> (_pEvent->size().width(), _pEvent->size().height()));
} // resizeEvent::resizeEvent


/*******************************************************************************
* qSysWinQt::paintEvent
*******************************************************************************/
void qSysWinQt::paintEvent(QPaintEvent */*_pEvent*/)
{
    onPaintEvent();
} // qSysWinQt::paintEvent


/*******************************************************************************
* qSysWin::enterEvent
*******************************************************************************/
void qSysWin::enterEvent(QEnterEvent *_pEvent)
{
    u32             u32Modifiers = modifiers();
    qVector2D<s32>  v2dLocal(_pEvent->globalPosition().x(), _pEvent->globalPosition().y());
    qVector2D<s32>  v2dGlobal(_pEvent->position().x(), _pEvent->position().y());

    _pEvent->setAccepted(onEnterEvent(u32Modifiers, v2dLocal, v2dGlobal));
} // qSysWin::enterEvent


/*******************************************************************************
* qSysWin::leaveEvent
*******************************************************************************/
void qSysWin::leaveEvent(QEvent *_pEvent)
{
    u32 u32Modifiers = modifiers();

    _pEvent->setAccepted(onLeaveEvent(u32Modifiers));
} // qSysWin::leaveEvent


/*******************************************************************************
* qSysWinQt::wheelEvent
*******************************************************************************/
void qSysWinQt::wheelEvent(QWheelEvent *_pEvent)
{
    u32             u32Modifiers    = modifiers();
    qVector2D<s32>  v2dLocal        = localCursorPos();
    qVector2D<s32>  v2dGlobal       = globalCursorPos();
    s32             s32Degree       = (s32) (((dbl) _pEvent->angleDelta().y()) / 8.);

    _pEvent->setAccepted(onWheelEvent(u32Modifiers, s32Degree, v2dLocal, v2dGlobal));
} // qSysWinQt::wheelEvent


/*******************************************************************************
* qSysWinQt::mouseDoubleClickEvent
*******************************************************************************/
void qSysWinQt::mouseDoubleClickEvent(QMouseEvent *_pEvent)
{
    u32             u32Modifiers	= modifiers();\
    u32             u32MouseButton	= mouseButton(_pEvent);\
    qVector2D<s32>  v2dLocal        = localCursorPos();\
    qVector2D<s32>  v2dGlobal       = globalCursorPos();\

    _pEvent->setAccepted(onDoubleClickEvent(u32Modifiers, u32MouseButton, v2dLocal, v2dGlobal));
} // qSysWinQt::mouseDoubleClickEvent


/*******************************************************************************
* qSysWinQt::mousePressEvent
*******************************************************************************/
void qSysWinQt::mousePressEvent(QMouseEvent *_pEvent)
{
    u32             u32Modifiers	= modifiers();\
        u32             u32MouseButton	= mouseButton(_pEvent);\
        qVector2D<s32>  v2dLocal        = localCursorPos();\
        qVector2D<s32>  v2dGlobal       = globalCursorPos();\

        _pEvent->setAccepted(onMousePressEvent(u32Modifiers, u32MouseButton, v2dLocal, v2dGlobal));
} // qSysWinQt::mousePressEvent


/*******************************************************************************
* qSysWinQt::mouseMoveEvent
*******************************************************************************/
void qSysWinQt::mouseMoveEvent(QMouseEvent *_pEvent)
{
    u32             u32Modifiers	= modifiers();\
        u32             u32MouseButton	= mouseButton(_pEvent);\
        qVector2D<s32>  v2dLocal        = localCursorPos();\
        qVector2D<s32>  v2dGlobal       = globalCursorPos();\

        _pEvent->setAccepted(onMouseMoveEvent(u32Modifiers, u32MouseButton, v2dLocal, v2dGlobal));
} // qSysWinQt::mouseMoveEvent


/*******************************************************************************
* qSysWinQt::mouseReleaseEvent
*******************************************************************************/
void qSysWinQt::mouseReleaseEvent(QMouseEvent *_pEvent)
{
    u32             u32Modifiers	= modifiers();\
        u32             u32MouseButton	= mouseButton(_pEvent);\
        qVector2D<s32>  v2dLocal        = localCursorPos();\
        qVector2D<s32>  v2dGlobal       = globalCursorPos();\

        _pEvent->setAccepted(onMouseReleaseEvent(u32Modifiers, u32MouseButton, v2dLocal, v2dGlobal));
} // qSysWinQt::mouseReleaseEvent


} // namespace SysQt
} // namespace Win
} // namespace qLib


#endif // _USE_QT_









// /*******************************************************************************
// * qSysWinQt::_CloseWin
// *******************************************************************************/
// bool qSysWinQt::_CloseWin()
// {
//     return close();
// } // qSysWinQt::_CloseWin


// /*******************************************************************************
// * qSysWinQt::_IsDisabled
// *******************************************************************************/
// bool qSysWinQt::_IsDisabled() const
// {
//     return !isEnabled();
// } // qSysWinQt::_IsDisabled


// /*******************************************************************************
// * qSysWinQt::_SetDisabled
// *******************************************************************************/
// void qSysWinQt::_SetDisabled(bool _bDisabled)
// {
//     setDisabled(_bDisabled);
// } // qSysWinQt::_SetDisabled


// /*******************************************************************************
// * qSysWinQt::_Geometry
// *******************************************************************************/
// qRect2D<s32> qSysWinQt::_Geometry() const
// {
//     const QRect &r  = this->geometry();

//     return qRect2D<s32> (r.x(), r.y(), r.width(), r.height());
// } // qSysWinQt::_Geometry


// /*******************************************************************************
// * qSysWinQt::_w
// *******************************************************************************/
// s32 qSysWinQt::_w() const
// {
//     return width();
// } // qSysWinQt::_w


// /*******************************************************************************
// * qSysWinQt::_h
// *******************************************************************************/
// s32 qSysWinQt::_h() const
// {
//     return height();
// } // qSysWinQt::_h


// /*******************************************************************************
// * qSysWinQt::_SetGeometry
// *******************************************************************************/
// void qSysWinQt::_SetGeometry(s32 _x,
//                            s32 _y,
//                            s32 _w,
//                            s32 _h)
// {
//     setGeometry(_x, _y, _w, _h);
// } // qSysWinQt::_SetGeometry


// /*******************************************************************************
// * qSysWinQt::_SetPosition
// *******************************************************************************/
// void qSysWinQt::_SetPosition(s32 _x,
//                            s32 _y)
// {
//     move(_x, _y);
// } // qSysWinQt::_SetPosition


// /*******************************************************************************
// * qSysWinQt::_GlobalCursorPos
// *******************************************************************************/
// qVector2D<s32> qSysWinQt::_GlobalCursorPos()
// {
//     QPoint pos = QCursor::pos();

//     return qVector2D<s32> (pos.x(), pos.y());
// } // qSysWinQt::_GlobalCursorPos



// /*******************************************************************************
// * qSysWinQt::_EnableDrop
// *******************************************************************************/
// void qSysWinQt::_EnableDrop(bool _bEnable)
// {
//     setAcceptDrops(_bEnable);
// } // qSysWinQt::_EnableDrop


// /*******************************************************************************
// * qSysWinQt::_SetCursor
// *******************************************************************************/
// void qSysWinQt::_SetCursor(const qCursor &_cursor)
// {
//     return setCursor(_cursor);
// } // qSysWinQt::_SetCursor


// /*******************************************************************************
// * qSysWinQt::_Update
// *******************************************************************************/
// void qSysWinQt::_Update()
// {
//     update();
// } // qSysWinQt::_Update


// /*******************************************************************************
// * qSysWinQt::_Repaint
// *******************************************************************************/
// void qSysWinQt::_Repaint()
// {
//     repaint();
// } // qSysWinQt::_Repaint


// /*******************************************************************************
// * qSysWinQt::resizeEvent
// *******************************************************************************/
// void qSysWinQt::resizeEvent(QResizeEvent *_pEvent)
// {
//     OnOsResize(qDimension2D<s32> (_pEvent->oldSize().width(), _pEvent->oldSize().height()),
//                qDimension2D<s32> (_pEvent->size().width(), _pEvent->size().height()));
// } // qSysWinQt::resizeEvent


// /*******************************************************************************
// * qSysWinQt::enterEvent
// *******************************************************************************/
// void qSysWinQt::enterEvent(QEnterEvent *_pEvent)
// {
//     u32             u32Modifiers = _Modifiers();
//     qVector2D<s32>  v2dLocal(_pEvent->globalPosition().x(), _pEvent->globalPosition().y());
//     qVector2D<s32>  v2dGlobal(_pEvent->position().x(), _pEvent->position().y());

//     _pEvent->setAccepted(OnOsEnter(u32Modifiers, v2dLocal, v2dGlobal));
// } // qSysWinQt::enterEvent


// /*******************************************************************************
// * qSysWinQt::leaveEvent
// *******************************************************************************/
// void qSysWinQt::leaveEvent(QEvent *_pEvent)
// {
//     u32 u32Modifiers = _Modifiers();

//     _pEvent->setAccepted(OnOsLeave(u32Modifiers));
// } // qSysWinQt::leaveEvent


// /*******************************************************************************
// * qSysWinQt::wheelEvent
// *******************************************************************************/
// void qSysWinQt::wheelEvent(QWheelEvent *_pEvent)
// {
//     u32             u32Modifiers    = _Modifiers();
//     qVector2D<s32>  v2dLocal        = _LocalCursorPos();
//     qVector2D<s32>  v2dGlobal       = _GlobalCursorPos();
//     s32             s32Degree       = (s32) (((dbl) _pEvent->angleDelta().y()) / 8.);

//     _pEvent->setAccepted(OnOsWheel(u32Modifiers, s32Degree, v2dLocal, v2dGlobal));
// } // qSysWinQt::wheelEvent


// /*******************************************************************************
// * qSysWinQt::mouseDoubleClickEvent
// *******************************************************************************/
// void qSysWinQt::mouseDoubleClickEvent(QMouseEvent *_pEvent)
// {
//     u32             u32Modifiers    = _Modifiers();
//     u32             u32MouseButton	= _MouseButton(_pEvent);
//     qVector2D<s32>  v2dLocal        = _LocalCursorPos();
//     qVector2D<s32>  v2dGlobal       = _GlobalCursorPos();

//     _pEvent->setAccepted(OnOsDoubleClick(u32Modifiers, u32MouseButton, v2dLocal, v2dGlobal));
// } // qSysWinQt::mouseDoubleClickEvent


// /*******************************************************************************
// * qSysWinQt::mousePressEvent
// *******************************************************************************/
// void qSysWinQt::mousePressEvent(QMouseEvent *_pEvent)
// {
//     u32             u32Modifiers    = _Modifiers();
//     u32             u32MouseButton	= _MouseButton(_pEvent);
//     qVector2D<s32>  v2dLocal        = _LocalCursorPos();
//     qVector2D<s32>  v2dGlobal       = _GlobalCursorPos();

//     _pEvent->setAccepted(OnOsMousePress(u32Modifiers, u32MouseButton, v2dLocal, v2dGlobal));
// } // qSysWinQt::mousePressEvent


// /*******************************************************************************
// * qSysWinQt::mouseMoveEvent
// *******************************************************************************/
// void qSysWinQt::mouseMoveEvent(QMouseEvent *_pEvent)
// {
//     u32             u32Modifiers    = _Modifiers();
//     u32             u32MouseButton	= _MouseButton(_pEvent);
//     qVector2D<s32>  v2dLocal        = _LocalCursorPos();
//     qVector2D<s32>  v2dGlobal       = _GlobalCursorPos();

//     _pEvent->setAccepted(OnOsMouseMove(u32Modifiers, u32MouseButton, v2dLocal, v2dGlobal));
// } // qSysWinQt::mouseMoveEvent


// /*******************************************************************************
// * qSysWinQt::mouseReleaseEvent
// *******************************************************************************/
// void qSysWinQt::mouseReleaseEvent(QMouseEvent *_pEvent)
// {
//     u32             u32Modifiers    = _Modifiers();
//     u32             u32MouseButton	= _MouseButton(_pEvent);
//     qVector2D<s32>  v2dLocal        = _LocalCursorPos();
//     qVector2D<s32>  v2dGlobal       = _GlobalCursorPos();

//     _pEvent->setAccepted(OnOsMouseRelease(u32Modifiers, u32MouseButton, v2dLocal, v2dGlobal));
// } // qSysWinQt::mouseReleaseEvent


// /*******************************************************************************
// * qSysWinQt::dragEnterEvent
// *******************************************************************************/
// void qSysWinQt::dragEnterEvent(QDragEnterEvent *_pEvent)
// {
//     if (_pEvent->mimeData()->hasUrls())
//     {
//         _pEvent->acceptProposedAction();
//     }
//         else
//     {
//         _pEvent->ignore();
//     }
// } // qSysWinQt::dragEnterEvent


// /*******************************************************************************
// * qSysWinQt::dragMoveEvent
// *******************************************************************************/
// void qSysWinQt::dragMoveEvent(QDragMoveEvent *_pEvent)
// {
//     if (_pEvent->mimeData()->hasUrls())
//     {
//         _pEvent->acceptProposedAction();
//     }
//         else
//     {
//         _pEvent->ignore();
//     }
// } // qSysWinQt::dragMoveEvent
//

// /*******************************************************************************
// * qSysWinQt::dropEvent
// *******************************************************************************/
// void qSysWinQt::dropEvent(QDropEvent   *_pEvent)
// {
//     if (_pEvent->mimeData()->hasUrls())
//     {
//         _pEvent->acceptProposedAction();
//
//         foreach (QUrl url, _pEvent->mimeData()->urls())
//         {
//            OnOsDropUrl(qUrl(url));
//         }
//     }
// } // qSysWinQt::dropEvent
