/*******************************************************************************
* \file aBaseWin_sys.cpp
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
#include <QMimeData>

#include "aFrame_def.h"

#include "aString.h"
#include "aRect.h"
#include "aStyleItemBorder.h"

#include "aBaseWin.h"
#include "aLayout_i.h"
#include "aCursor.h"
#include "aUrl.h"

using namespace aFrame::aUtil;



/*******************************************************************************
* namespace
*******************************************************************************/
namespace aFrame {
namespace aWin {


/*******************************************************************************
* aBaseWin_sys::aBaseWin_sys
*******************************************************************************/
aBaseWin_sys::aBaseWin_sys(QWidget *_pParent)
: QWidget(_pParent)
{
    // delete the window when it is beeing closed
    setAttribute(Qt::WA_DeleteOnClose);

    // no background painting
    setAttribute(Qt::WA_NoSystemBackground);
    setAttribute(Qt::WA_TranslucentBackground);

    // Optional: Fenster im Vordergrund halten
    // setWindowFlags(windowFlags() | Qt::WindowStaysOnTopHint);

    // install the event filter
    installEventFilter(this);
} // aBaseWin_sys::aBaseWin_sys


/*******************************************************************************
* aBaseWin_sys::~aBaseWin_sys
*******************************************************************************/
aBaseWin_sys::~aBaseWin_sys()
{
} // aBaseWin_sys::~aBaseWin_sys


/*******************************************************************************
* aBaseWin_sys::className
*******************************************************************************/
aString aBaseWin_sys::className() const
{
    //aString sName = std::type_index(typeid(*pt)).name();
    //std::cout << "class name: " << sName << std::endl;

    const char  *sMangled_name = typeid(*this).name();

    #ifdef __GNUG__
        // GCC/Clang: Namen entmangeln
        int status = 0;
        std::unique_ptr<char, void(*)(void*)> demangled {
            abi::__cxa_demangle(sMangled_name, nullptr, nullptr, &status),
            std::free
        };

        if (status == 0)
        {
            return demangled.get();
        }
    #endif

    // Fallback: Original Name (bei MSVC bereits lesbar)
    return sMangled_name;

} // aBaseWin_sys::className


/*******************************************************************************
* aBaseWin_sys::closeWin
*******************************************************************************/
bool aBaseWin_sys::closeWin()
{
    return QWidget::close();
} // aBaseWin_sys::closeWin


/*******************************************************************************
* aBaseWin_sys::setParent
*******************************************************************************/
void aBaseWin_sys::setParent(aBaseWin *_pParent)
{
    QWidget::setParent(_pParent);
} // aBaseWin_sys::setParent


/*******************************************************************************
* aBaseWin_sys::parent
*******************************************************************************/
aBaseWin* aBaseWin_sys::parent() const
{
    return static_cast<aBaseWin *> (QWidget::parentWidget());
} // aBaseWin_sys::parent


/*******************************************************************************
* aBaseWin_sys::update
*******************************************************************************/
void aBaseWin_sys::update()
{
    QWidget::update();
} // aBaseWin_sys::update


/*******************************************************************************
* aBaseWin_sys::repaint
*******************************************************************************/
void aBaseWin_sys::repaint()
{
    QWidget::repaint();
} // aBaseWin_sys::repaint


/*******************************************************************************
* aBaseWin_sys::setVisible
*******************************************************************************/
void aBaseWin_sys::setVisible(bool _bVisible)
{
    QWidget::setVisible(_bVisible);
} // aBaseWin_sys::setVisible


/*******************************************************************************
* aBaseWin_sys::isVisible
*******************************************************************************/
bool aBaseWin_sys::isVisible() const
{
    return QWidget::isVisible();
} // aBaseWin_sys::isVisible


/*******************************************************************************
* aBaseWin_sys::setEnabled
*******************************************************************************/
void aBaseWin_sys::setEnabled(bool _bEnabled)
{
    QWidget::setEnabled(_bEnabled);
} // aBaseWin_sys::setEnabled


/*******************************************************************************
* aBaseWin_sys::isEnabled
*******************************************************************************/
bool aBaseWin_sys::isEnabled() const
{
    return QWidget::isEnabled();
} // aBaseWin_sys::isEnabled


/*******************************************************************************
* aBaseWin_sys::isMinimized
*******************************************************************************/
bool aBaseWin_sys::isMinimized() const
{
    return (QWidget::windowState() & Qt::WindowMinimized) != 0;
} // aBaseWin_sys::isMinimized


/*******************************************************************************
* aBaseWin_sys::showMinimized
*******************************************************************************/
void aBaseWin_sys::showMinimized()
{
    QWidget::setWindowState(Qt::WindowMinimized);
} // aBaseWin_sys::showMaximized


/*******************************************************************************
* aBaseWin_sys::isMaximized
*******************************************************************************/
bool aBaseWin_sys::isMaximized() const
{
    return (QWidget::windowState() & Qt::WindowMaximized) != 0;
} // aBaseWin_sys::isMaximized


/*******************************************************************************
* aBaseWin_sys::showMaximized
*******************************************************************************/
void aBaseWin_sys::showMaximized()
{
    QWidget::setWindowState(Qt::WindowMaximized);
} // aBaseWin_sys::showMaximized


/*******************************************************************************
* aBaseWin_sys::isFullScreen
*******************************************************************************/
bool aBaseWin_sys::isFullScreen() const
{
    return (QWidget::windowState() & Qt::WindowFullScreen) != 0;
} // aBaseWin_sys::isFullScreen


/*******************************************************************************
* aBaseWin_sys::showFullScreen
*******************************************************************************/
void aBaseWin_sys::showFullScreen()
{
    QWidget::setWindowState(Qt::WindowFullScreen);
} // aBaseWin_sys::showFullScreen


/*******************************************************************************
* aBaseWin_sys::isNormal
*******************************************************************************/
bool aBaseWin_sys::isNormal() const
{
    return (QWidget::windowState() == Qt::WindowNoState);
} // aBaseWin_sys::isNormal


/*******************************************************************************
* aBaseWin_sys::showNormal
*******************************************************************************/
void aBaseWin_sys::showNormal()
{
    QWidget::setWindowState(Qt::WindowNoState);
} // aBaseWin_sys::showNormal


/*******************************************************************************
* aBaseWin_sys::toggleMaximized
*******************************************************************************/
void aBaseWin_sys::toggleMaximized()
{
    if (isMaximized())
    {
        showNormal();
    }
    else
    {
        showMaximized();
    }
} // aBaseWin_sys::toggleMaximized


/*******************************************************************************
* aBaseWin_sys::toggleFullScreen
*******************************************************************************/
void aBaseWin_sys::toggleFullScreen()
{
    if (isFullScreen())
    {
        showNormal();
    }
    else
    {
        showFullScreen();
    }
} // aBaseWin_sys::toggleFullScreen


/*******************************************************************************
* aBaseWin_sys::setMouseTracking
*******************************************************************************/
void aBaseWin_sys::setMouseTracking(bool _bEnable)
{
    return QWidget::setMouseTracking(_bEnable);
} // aBaseWin_sys::setMouseTracking


/*******************************************************************************
* aBaseWin_sys::enableDragDrop
*******************************************************************************/
void aBaseWin_sys::enableDragDrop(bool _bEnable)
{
    return QWidget::setAcceptDrops(_bEnable);
} // aBaseWin_sys::enableDragDrop


/*******************************************************************************
* aBaseWin_sys::setCursor
*******************************************************************************/
void aBaseWin_sys::setCursor(const aCursor &_cursor)
{
    return QWidget::setCursor(_cursor.toQCursor());
} // aBaseWin_sys::setCursor


/*******************************************************************************
* aBaseWin_sys::setMinW
*******************************************************************************/
void aBaseWin_sys::setMinW(s32 _s32MinW)
{
    QWidget::setMinimumWidth(_s32MinW);
} // aBaseWin_sys::setMinW


/*******************************************************************************
* aBaseWin_sys::setMinH
*******************************************************************************/
void aBaseWin_sys::setMinH(s32 _s32MinH)
{
    QWidget::setMinimumHeight(_s32MinH);
} // aBaseWin_sys::setMinH


/*******************************************************************************
* aBaseWin_sys::minW
*******************************************************************************/
s32 aBaseWin_sys::minW() const
{
    return QWidget::minimumWidth();
} // aBaseWin_sys::minW


/*******************************************************************************
* aBaseWin_sys::minH
*******************************************************************************/
s32 aBaseWin_sys::minH() const
{
    return QWidget::minimumHeight();
} // aBaseWin_sys::minH


/*******************************************************************************
* aBaseWin_sys::setMaxW
*******************************************************************************/
void aBaseWin_sys::setMaxW(s32 _s32MaxW)
{
    QWidget::setMaximumWidth(_s32MaxW);
} // aBaseWin_sys::setMaxW


/*******************************************************************************
* aBaseWin_sys::setMaxH
*******************************************************************************/
void aBaseWin_sys::setMaxH(s32 _s32MaxH)
{
    QWidget::setMaximumHeight(_s32MaxH);
} // aBaseWin_sys::setMaxH


/*******************************************************************************
* aBaseWin_sys::maxW
*******************************************************************************/
s32 aBaseWin_sys::maxW() const
{
    return QWidget::maximumWidth();
} // aBaseWin_sys::maxW


/*******************************************************************************
* aBaseWin_sys::maxH
*******************************************************************************/
s32 aBaseWin_sys::maxH() const
{
    return QWidget::maximumHeight();
} // aBaseWin_sys::maxH


/*******************************************************************************
* aBaseWin_sys::setGeometry
*******************************************************************************/
void aBaseWin_sys::setGeometry(s32 _s32X,
                               s32 _s32Y,
                               s32 _s32W,
                               s32 _s32H)
{
    QWidget::setGeometry(_s32X, _s32Y, _s32W, _s32H);
} // aBaseWin_sys::setGeometry


/*******************************************************************************
* aBaseWin_sys::geometryRect
*******************************************************************************/
aRect aBaseWin_sys::geometryRect() const
{
    QRect r = QWidget::frameGeometry();

    return aRect(r.left(), r.top(), r.width(), r.height());
} // aBaseWin_sys::geometryRect




/*******************************************************************************
* aBaseWin_sys::eventFilter
*******************************************************************************/
bool aBaseWin_sys::eventFilter(QObject *_pObj,
                               QEvent  *_pEvent)
{
    // close event
    if (_pObj == this && _pEvent->type() == QEvent::Close)
    {
        QCloseEvent *pCloseEvent = static_cast<QCloseEvent *>(_pEvent);

        if (!onCloseEvent())
        {
            pCloseEvent->ignore();
            return true;
        }
        // else standard implementation at the end of this function
    }

    // resize event
    else if (_pObj == this && _pEvent->type() == QEvent::Resize)
    {
        QResizeEvent *pResizeEvent = static_cast<QResizeEvent *>(_pEvent);
        QSize oldSize = pResizeEvent->oldSize();
        QSize newSize = pResizeEvent->size();

        onResizeEvent(aDimension(oldSize.width(), oldSize.height()),
                      aDimension(newSize.width(), newSize.height()));

        return false;
    }

    // paint event
    else if (_pObj == this && _pEvent->type() == QEvent::Paint)
    {
        //QPaintEvent     *pPaintEvent = static_cast<QPaintEvent *>(_pEvent);
        //handleWidgetPaint(pPaintEvent);
        onPaintEvent();

        // true = Event wurde behandelt (stoppt weitere Verarbeitung)
        // false = Event wird normal weiterverarbeitet
        return true; // Meist false, damit das Widget normal gezeichnet wird
    }

    // enter events
    else if (_pEvent->type() == QEvent::Enter)
    {
        QEnterEvent *pEvent         = static_cast<QEnterEvent *> (_pEvent);
        u16         u16Mods         = modifierFromEvent(pEvent);
        aPoint      pntLocal(pEvent->position().x(), pEvent->position().y());
        aPoint      pntGlobal(pEvent->globalPosition().x(), pEvent->globalPosition().y());

        return onEnterEvent(u16Mods, pntLocal, pntGlobal);
    }

    // leave events
    else if (_pEvent->type() == QEvent::Leave)
    {
        // Note: Leave events don't provide position or modifier information
        // You can get the last known mouse position if needed

        //QEvent *pEvent = static_cast<QEvent *>(_pEvent);

        return onLeaveEvent(currentModifiers());
    }

    // drag enter event
    else if (_pEvent->type() == QEvent::DragEnter)
    {
        QDragEnterEvent *pEvent = static_cast<QDragEnterEvent *> (_pEvent);

        if (pEvent->mimeData()->hasUrls())
        {
            pEvent->acceptProposedAction();
        }
        else
        {
            pEvent->ignore();
        }
    }

    // drag move event
    else if (_pEvent->type() == QEvent::DragMove)
    {
        QDragMoveEvent *pEvent = static_cast<QDragMoveEvent *> (_pEvent);

        if (pEvent->mimeData()->hasUrls())
        {
            pEvent->acceptProposedAction();
        }
        else
        {
            pEvent->ignore();
        }
    }

    // drop event
    else if (_pEvent->type() == QEvent::Drop)
    {
        QDropEvent *pEvent = static_cast<QDropEvent *> (_pEvent);

        if (pEvent->mimeData()->hasUrls())
        {
            pEvent->acceptProposedAction();

            foreach (QUrl url, pEvent->mimeData()->urls())
            {
               onDropUrl(aUrl(url));
            }
        }
    }

    // wheel events
    else if (_pEvent->type() == QEvent::Wheel)
    {
        QWheelEvent *pEvent         = static_cast<QWheelEvent *>(_pEvent);
        u16         u16Mods         = modifierFromEvent(pEvent);
        s16         s16Degree      = pEvent->angleDelta().y() / 8;
        aPoint      pntLocal(pEvent->position().x(), pEvent->position().y());
        aPoint      pntGlobal(pEvent->globalPosition().x(), pEvent->globalPosition().y());

        return onWheelEvent(u16Mods, s16Degree, pntLocal, pntGlobal);
    }

    // double click events
    else if (_pEvent->type() == QEvent::MouseButtonDblClick)
    {
        QMouseEvent *pMouseEvent    = static_cast<QMouseEvent *>(_pEvent);
        u16         u16Mods         = modifierFromEvent(pMouseEvent);
        u16         u16Btn          = buttonsFromEvent(pMouseEvent);
        aPoint      pntLocal(pMouseEvent->pos().x(), pMouseEvent->pos().y());
        aPoint      pntGlobal(pMouseEvent->globalPosition().x(), pMouseEvent->globalPosition().y());

        if (onDoubleClickEvent(u16Mods, u16Btn, pntLocal, pntGlobal))
        {
            _pEvent->accept();
            return true;
        }

        return false;
    }

    // MouseButtonPress events
    else if (_pEvent->type() == QEvent::MouseButtonPress)
    {
        QMouseEvent *pMouseEvent    = static_cast<QMouseEvent *>(_pEvent);
        u16         u16Mods         = modifierFromEvent(pMouseEvent);
        u16         u16Btn          = buttonsFromEvent(pMouseEvent);
        aPoint      pntLocal(pMouseEvent->pos().x(), pMouseEvent->pos().y());
        aPoint      pntGlobal(pMouseEvent->globalPosition().x(), pMouseEvent->globalPosition().y());

        if (onButtonPressEvent(u16Mods, u16Btn, pntLocal, pntGlobal))
        {
            _pEvent->accept();
            return true;
        }

        return false;
    }

    // MouseMove events
    else if (_pEvent->type() == QEvent::MouseMove)
    {
        QMouseEvent *pMouseEvent    = static_cast<QMouseEvent *>(_pEvent);
        u16         u16Mods         = modifierFromEvent(pMouseEvent);
        u16         u16Btn          = buttonsFromEvent(pMouseEvent);
        aPoint      pntLocal(pMouseEvent->pos().x(), pMouseEvent->pos().y());
        aPoint      pntGlobal(pMouseEvent->globalPosition().x(), pMouseEvent->globalPosition().y());

        return onMouseMoveEvent(u16Mods, u16Btn, pntLocal, pntGlobal);
    }

    // MouseButtonRelease events
    else if (_pEvent->type() == QEvent::MouseButtonRelease)
    {
        QMouseEvent *pMouseEvent    = static_cast<QMouseEvent *>(_pEvent);
        u16         u16Mods         = modifierFromEvent(pMouseEvent);
        u16         u16Btn          = buttonsFromEvent(pMouseEvent);
        aPoint      pntLocal(pMouseEvent->pos().x(), pMouseEvent->pos().y());
        aPoint      pntGlobal(pMouseEvent->globalPosition().x(), pMouseEvent->globalPosition().y());

        if (onButtonReleaseEvent(u16Mods, u16Btn, pntLocal, pntGlobal))
        {
            _pEvent->accept();
            return true;
        }

        return false;
    }

    return QObject::eventFilter(_pObj, _pEvent);
} // aBaseWin_sys::eventFilter


/*******************************************************************************
* aBaseWin_sys::currentModifiers
*******************************************************************************/
u16 aBaseWin_sys::currentModifiers() const
{
    return qtModifiers2Modifiers(QApplication::keyboardModifiers());
} // aBaseWin_sys::currentModifiers


/*******************************************************************************
* aBaseWin_sys::modifierFromEvent
*******************************************************************************/
u16 aBaseWin_sys::modifierFromEvent(QSinglePointEvent *_pEvent) const
{
    return qtModifiers2Modifiers(_pEvent->modifiers());
} // aBaseWin_sys::modifierFromEvent


/*******************************************************************************
* aBaseWin_sys::qtModifiers2Modifiers
*******************************************************************************/
u16 aBaseWin_sys::qtModifiers2Modifiers(Qt::KeyboardModifiers _modifiers) const
{
    u16                     u16Mods     = MODIFIER_NONE;

    if (_modifiers & Qt::ControlModifier)
        u16Mods |= MODIFIER_CTRL;

    if (_modifiers & Qt::ShiftModifier)
        u16Mods |= MODIFIER_SHIFT;

    if (_modifiers & Qt::AltModifier)
        u16Mods |= MODIFIER_ALT;

    if (_modifiers & Qt::MetaModifier)
        u16Mods |= MODIFIER_META;

    if (_modifiers & Qt::KeypadModifier)
            u16Mods |= MODIFIER_KEYPAD;

    return u16Mods;
} // aBaseWin_sys::qtModifiers2Modifiers


/*******************************************************************************
* aBaseWin_sys::buttonsFromEvent
*******************************************************************************/
u16 aBaseWin_sys::buttonsFromEvent(QSinglePointEvent *_pEvent) const
{
    u16                 u16Buttons  = MOUSE_BTN_NONE;
    Qt::MouseButtons    buttons     = _pEvent->buttons();

    if (buttons & Qt::LeftButton)
    {
        u16Buttons |= MOUSE_BTN_LEFT;
    }

    if (buttons & Qt::MiddleButton)
    {
        u16Buttons |= MOUSE_BTN_MIDDLE;
    }

    if (buttons & Qt::RightButton)
    {
        u16Buttons |= MOUSE_BTN_RIGHT;
    }

    return u16Buttons;
} // aBaseWin_sys::buttonsFromEvent


} // namespace aWin
} // namespace aFrame


#endif //_USE_QT_


// /*******************************************************************************
// * aBaseWin::dragEnterEvent
// *******************************************************************************/
// template<class T>
// void aBaseWin::dragEnterEvent(QDragEnterEvent *_pEvent)
// {
//     if (_pEvent->mimeData()->hasUrls())
//     {
//         _pEvent->acceptProposedAction();
//     }
//         else
//     {
//         _pEvent->ignore();
//     }
// } // aBaseWin::dragEnterEvent


// /*******************************************************************************
// * aBaseWin::dragMoveEvent
// *******************************************************************************/
// template<class T>
// void aBaseWin::dragMoveEvent(QDragMoveEvent *_pEvent)
// {
//     if (_pEvent->mimeData()->hasUrls())
//     {
//         _pEvent->acceptProposedAction();
//     }
//         else
//     {
//         _pEvent->ignore();
//     }
// } // aBaseWin::dragMoveEvent


// /*******************************************************************************
// * aBaseWin::dropEvent
// *******************************************************************************/
// template<class T>
// void aBaseWin::dropEvent(QDropEvent *_pEvent)
// {
//     if (_pEvent->mimeData()->hasUrls())
//     {
//         _pEvent->acceptProposedAction();

//         foreach (QUrl url, _pEvent->mimeData()->urls())
//         {
//            onDropUrl(aUrl(url));
//         }
//     }
// } // aBaseWin::dropEvent
