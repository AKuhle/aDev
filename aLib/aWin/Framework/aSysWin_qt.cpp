/*******************************************************************************
* \file aSysWinQt.cpp
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
#include <QPaintEvent>

#include "aLib_def.h"
#include "aWin/aWin_def.h"

#include "aGraphic/aCursor.h"

#include "aMath/Obj2D/aDimension2D.h"
#include "aMath/Obj2D/aRect2D.h"

#include "aWin/Framework/aSysWin_qt.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aWin {
namespace SysQt {


/*******************************************************************************
* aSysWinQt::aSysWinQt
*******************************************************************************/
aSysWinQt::aSysWinQt(aSysWinQt  *_pParent  /* = nullptr */)
: QWidget(_pParent)
{
    // delete the window when it is beeing closed
    setAttribute(Qt::WA_DeleteOnClose);

    // no frames
    setWindowFlags(windowFlags() | Qt::FramelessWindowHint);

    // no default background painting
    //setAttribute(Qt::WA_NoSystemBackground, true);
    setAttribute(Qt::WA_TranslucentBackground, true);
    //setAttribute(Qt::WA_TransparentForMouseEvents, true);
} // aSysWinQt::aSysWinQt


/*******************************************************************************
* aSysWinQt::~aSysWinQt
*******************************************************************************/
aSysWinQt::~aSysWinQt()
{
} // aSysWinQt::~aSysWinQt


/*******************************************************************************
* aSysWinQt::_sysWin
*******************************************************************************/
aSysWin_t* aSysWinQt::_sysWin()
{
    return this;
} // aSysWinQt::_sysWin


/*******************************************************************************
* aSysWinQt::_parent
*******************************************************************************/
aSysWin* aSysWinQt::_parent() const
{
    return (static_cast<aSysWin *> (QWidget::parentWidget()));
} // aSysWinQt::_parent


/*******************************************************************************
* aSysWinQt::_setParent
*******************************************************************************/
void aSysWinQt::_setParent(aSysWin *_pParent)
{
    QWidget::setParent(_pParent);
    QWidget::setVisible(true);
} // aSysWinQt::_setParent


/*******************************************************************************
* aSysWinQt::_setCursor
*******************************************************************************/
void aSysWinQt::_setCursor(const aCursor &_cursor)
{
    QWidget::setCursor(_cursor);
} // aSysWinQt::_setCursor


/*******************************************************************************
* aSysWinQt::_setMouseTracking
*******************************************************************************/
void aSysWinQt::_setMouseTracking(bool _bEnable)
{
    QWidget::setMouseTracking(_bEnable);
} // aSysWinQt::_setMouseTracking


/*******************************************************************************
* aSysWinQt::_repaint
*******************************************************************************/
void aSysWinQt::_repaint()
{
    QWidget::repaint();
} // aSysWinQt::_repaint


/*******************************************************************************
* aSysWinQt::_update
*******************************************************************************/
void aSysWinQt::_update()
{
    QWidget::update();
} // aSysWinQt::_update


/*******************************************************************************
* aSysWinQt::getQWidget
*******************************************************************************/
QWidget* aSysWinQt::getQWidget()
{
    return this;
} // aSysWinQt::getQWidget


/*******************************************************************************
* aSysWinQt::_close
*******************************************************************************/
void aSysWinQt::_close()
{
    QWidget::close();
} // aSysWinQt::_close


/*******************************************************************************
* aSysWinQt::_show
*******************************************************************************/
void aSysWinQt::_show()
{
    QWidget::show();
} // aSysWinQt::_show


/*******************************************************************************
* aSysWinQt::_hide
*******************************************************************************/
void aSysWinQt::_hide()
{
    QWidget::hide();
} // aSysWinQt::_hide


/*******************************************************************************
* aSysWinQt::_isVisible
*******************************************************************************/
bool aSysWinQt::_isVisible() const
{
    return QWidget::isVisible();
} // aSysWinQt::_isVisible


/*******************************************************************************
* aSysWinQt::_setEnabled
*******************************************************************************/
void aSysWinQt::_setEnabled(bool _bEnabled)
{
    return QWidget::setEnabled(_bEnabled);
} // aSysWinQt::_setEnabled


/*******************************************************************************
* aSysWinQt::_isEnabled
*******************************************************************************/
bool aSysWinQt::_isEnabled() const
{
    return QWidget::isEnabled();
} // aSysWinQt::_isEnabled


/*******************************************************************************
* aSysWinQt::_showMaximized
*******************************************************************************/
void aSysWinQt::_showMaximized()
{
    //setWindowState(this->windowState() ^ Qt::WindowFullScreen);

    QWidget::showMaximized();
} // aSysWinQt::_showMaximized


/*******************************************************************************
* aSysWinQt::_showMinimized
*******************************************************************************/
void aSysWinQt::_showMinimized()
{
    QWidget::showMinimized();
} // aSysWinQt::_showMinimized


/*******************************************************************************
* aSysWinQt::_showNormal
*******************************************************************************/
void aSysWinQt::_showNormal()
{
    QWidget::showNormal();
} // aSysWinQt::_showNormal


/*******************************************************************************
* aSysWinQt::_isMaximized
*******************************************************************************/
bool aSysWinQt::_isMaximized() const
{
    return QWidget::isMaximized();
} // aSysWinQt::_isMaximized


/*******************************************************************************
* aSysWinQt::_isMinimized
*******************************************************************************/
bool aSysWinQt::_isMinimized() const
{
    return QWidget::isMinimized();
} // aSysWinQt::_isMinimized


/*******************************************************************************
* aSysWinQt::_modifiers
*******************************************************************************/
u32 aSysWinQt::_modifiers() const
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
} // aSysWinQt::_modifiers


/*******************************************************************************
* aSysWinQt::_mouseButton
*******************************************************************************/
u32 aSysWinQt::_mouseButton() const
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
} // aSysWinQt::_mouseButton


/*******************************************************************************
* aSysWinQt::_mouseButton
*******************************************************************************/
u32 aSysWinQt::_mouseButton(QMouseEvent *_pEvent) const
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
} // aSysWinQt::_mouseButton


/*******************************************************************************
* aSysWinQt::_localCursorPos
*******************************************************************************/
aVector2D<s32> aSysWinQt::_localCursorPos() const
{
    QPoint pos = mapFromGlobal(QCursor::pos());

    return aVector2D<s32> (pos.x(), pos.y());
} // aSysWinQt::_localCursorPos


/*******************************************************************************
* aSysWinQt::_globalCursorPos
*******************************************************************************/
aVector2D<s32> aSysWinQt::_globalCursorPos() const
{
    QPoint pos = QCursor::pos();

    return aVector2D<s32> (pos.x(), pos.y());
} // aSysWinQt::_globalCursorPos


/*******************************************************************************
* aSysWinQt::_setGeometry
*******************************************************************************/
void aSysWinQt::_setGeometry(s32    _x,
                             s32    _y,
                             s32    _w,
                             s32    _h)
{
    setGeometry(_x, _y, _w, _h);
} // aSysWinQt::_setGeometry


/*******************************************************************************
* aSysWinQt::_geometry
*******************************************************************************/
aRect2D<s32> aSysWinQt::_geometry() const
{
    QRect r = geometry();

    return aRect2D<s32>(r.x(), r.y(), r.width(), r.height());
} // aSysWinQt::_geometry


/*******************************************************************************
* aSysWinQt::_w
*******************************************************************************/
s32 aSysWinQt::_w() const
{
    return width();
} // aSysWinQt::_w


/*******************************************************************************
* aSysWinQt::_h
*******************************************************************************/
s32 aSysWinQt::_h() const
{
    return height();
} // aSysWinQt::_h


/*******************************************************************************
* aSysWinQt::resizeEvent
*******************************************************************************/
void aSysWinQt::resizeEvent(QResizeEvent *_pEvent)
{
    onResizeEvent(aDimension2D<s32> (_pEvent->oldSize().width(), _pEvent->oldSize().height()),
                  aDimension2D<s32> (_pEvent->size().width(), _pEvent->size().height()));
} // aSysWinQt::resizeEvent


/*******************************************************************************
* aSysWinQt::paintEvent
*******************************************************************************/
void aSysWinQt::paintEvent(QPaintEvent *_pEvent)
{
    onPaintEvent();

    _pEvent->accept();
} // aSysWinQt::paintEvent


/*******************************************************************************
* aSysWinQt::enterEvent
*******************************************************************************/
void aSysWinQt::enterEvent(QEnterEvent *_pEvent)
{
    u32             u32Modifiers = _modifiers();
    aVector2D<s32>  v2dLocal(_pEvent->position().x(), _pEvent->position().y());
    aVector2D<s32>  v2dGlobal(_pEvent->globalPosition().x(), _pEvent->globalPosition().y());

    onEnterEvent(u32Modifiers, v2dLocal, v2dGlobal);
    //_pEvent->setAccepted(onEnterEvent(u32Modifiers, v2dLocal, v2dGlobal));
} // aSysWinQt::enterEvent


/*******************************************************************************
* aSysWinQt::leaveEvent
*******************************************************************************/
void aSysWinQt::leaveEvent(QEvent *_pEvent)
{
    u32 u32Modifiers = _modifiers();

    _pEvent->setAccepted(onLeaveEvent(u32Modifiers));
} // aSysWinQt::leaveEvent


/*******************************************************************************
* aSysWinQtQt::wheelEvent
*******************************************************************************/
void aSysWinQt::wheelEvent(QWheelEvent *_pEvent)
{
    u32             u32Modifiers    = _modifiers();
    aVector2D<s32>  v2dLocal        = _localCursorPos();
    aVector2D<s32>  v2dGlobal       = _globalCursorPos();
    s32             s32Degree       = (s32) (((dbl) _pEvent->angleDelta().y()) / 8.);

    _pEvent->setAccepted(onWheelEvent(u32Modifiers, s32Degree, v2dLocal, v2dGlobal));
} // aSysWinQtQt::wheelEvent


/*******************************************************************************
* aSysWinQt::mouseDoubleClickEvent
*******************************************************************************/
void aSysWinQt::mouseDoubleClickEvent(QMouseEvent *_pEvent)
{
    u32             u32Modifiers	= _modifiers();
    u32             u32MouseButton	= _mouseButton(_pEvent);
    aVector2D<s32>  v2dLocal        = _localCursorPos();
    aVector2D<s32>  v2dGlobal       = _globalCursorPos();

    _pEvent->setAccepted(onDoubleClickEvent(u32Modifiers, u32MouseButton, v2dLocal, v2dGlobal));
} // aSysWinQt::mouseDoubleClickEvent


/*******************************************************************************
* aSysWinQt::mousePressEvent
*******************************************************************************/
void aSysWinQt::mousePressEvent(QMouseEvent *_pEvent)
{
    u32             u32Modifiers	= _modifiers();
    u32             u32MouseButton	= _mouseButton(_pEvent);
    aVector2D<s32>  v2dLocal        = _localCursorPos();
    aVector2D<s32>  v2dGlobal       = _globalCursorPos();

    _pEvent->setAccepted(onMousePressEvent(u32Modifiers, u32MouseButton, v2dLocal, v2dGlobal));
} // aSysWinQt::mousePressEvent


/*******************************************************************************
* aSysWinQt::mouseMoveEvent
*******************************************************************************/
void aSysWinQt::mouseMoveEvent(QMouseEvent *_pEvent)
{
    u32             u32Modifiers	= _modifiers();\
    u32             u32MouseButton	= _mouseButton(_pEvent);
    aVector2D<s32>  v2dLocal        = _localCursorPos();
    aVector2D<s32>  v2dGlobal       = _globalCursorPos();

    _pEvent->setAccepted(onMouseMoveEvent(u32Modifiers, u32MouseButton, v2dLocal, v2dGlobal));
} // aSysWinQt::mouseMoveEvent


/*******************************************************************************
* aSysWinQt::mouseReleaseEvent
*******************************************************************************/
void aSysWinQt::mouseReleaseEvent(QMouseEvent *_pEvent)
{
    u32             u32Modifiers	= _modifiers();\
    u32             u32MouseButton	= _mouseButton(_pEvent);
    aVector2D<s32>  v2dLocal        = _localCursorPos();
    aVector2D<s32>  v2dGlobal       = _globalCursorPos();

    _pEvent->setAccepted(onMouseReleaseEvent(u32Modifiers, u32MouseButton, v2dLocal, v2dGlobal));
} // aSysWinQt::mouseReleaseEvent


} // namespace SysQt
} // namespace aWin
} // namespace aLib


#endif // _USE_QT_
