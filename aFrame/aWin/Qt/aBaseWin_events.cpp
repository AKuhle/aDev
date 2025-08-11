/*******************************************************************************
* \file aBaseWin.cpp
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
#include <QPaintEvent>
#include <QResizeEvent>

#include "aBaseWin.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aFrame {
namespace aWin {


/*******************************************************************************
* aBaseWin::eventFilter
*******************************************************************************/
bool aBaseWin::eventFilter(QObject *_pObj,
                           QEvent  *_pEvent)
{
    // resize event
    if (_pObj == this && _pEvent->type() == QEvent::Resize)
    {
        QResizeEvent *pResizeEvent = static_cast<QResizeEvent *>(_pEvent);
        QSize oldSize = pResizeEvent->oldSize();
        QSize newSize = pResizeEvent->size();

        // Call the sys resize handler
        onSysResize(aDimension(oldSize.width(), oldSize.height()),
                    aDimension(newSize.width(), newSize.height()));

        // Call the resize handler
        onResize(aDimension(oldSize.width(), oldSize.height()),
                 aDimension(newSize.width(), newSize.height()));

        return false;
    }

    // paint event
    else if (_pObj == this && _pEvent->type() == QEvent::Paint)
    {
        //QPaintEvent     *pPaintEvent = static_cast<QPaintEvent *>(_pEvent);
        //handleWidgetPaint(pPaintEvent);
        onPaint();

        // true = Event wurde behandelt (stoppt weitere Verarbeitung)
        // false = Event wird normal weiterverarbeitet
        return true; // Meist false, damit das Widget normal gezeichnet wird
    }

    // wheel click events
    else if (_pEvent->type() == QEvent::Wheel)
    {
        QWheelEvent *pEvent         = static_cast<QWheelEvent *>(_pEvent);
        u16         u16Mods         = modifierFromEvent(pEvent);
        s16         _s16Degree      = pEvent->angleDelta().y() / 8;
        aPoint      pntLocal(pEvent->position().x(), pEvent->position().y());
        aPoint      pntGlobal(pEvent->globalPosition().x(), pEvent->globalPosition().y());

        return onWheel(u16Mods, _s16Degree, pntLocal, pntGlobal);
    }

    // double click events
    else if (_pEvent->type() == QEvent::MouseButtonDblClick)
    {
        QMouseEvent *pMouseEvent    = static_cast<QMouseEvent *>(_pEvent);
        u16         u16Mods         = modifierFromEvent(pMouseEvent);
        aPoint      pntLocal(pMouseEvent->pos().x(), pMouseEvent->pos().y());
        aPoint      pntGlobal(pMouseEvent->globalPosition().x(), pMouseEvent->globalPosition().y());

        // Prüfe welche Maustaste doppelgeklickt wurde
        if (pMouseEvent->button() == Qt::LeftButton)
        {
            // true => event handled
            return onLDoubleClick(u16Mods, pntLocal, pntGlobal);
        }
        else if (pMouseEvent->button() == Qt::MiddleButton)
        {
            // true => event handled
            return onMDoubleClick(u16Mods, pntLocal, pntGlobal);
        }
        else if (pMouseEvent->button() == Qt::RightButton)
        {
            // true => event handled
            return onRDoubleClick(u16Mods, pntLocal, pntGlobal);
        }
    }

    // MouseButtonPress events
    else if (_pEvent->type() == QEvent::MouseButtonPress)
    {
        QMouseEvent *pMouseEvent    = static_cast<QMouseEvent *>(_pEvent);
        u16         u16Mods         = modifierFromEvent(pMouseEvent);
        aPoint      pntLocal(pMouseEvent->pos().x(), pMouseEvent->pos().y());
        aPoint      pntGlobal(pMouseEvent->globalPosition().x(), pMouseEvent->globalPosition().y());

        // Prüfe welche Maustaste gedrückt wurde
        if (pMouseEvent->button() == Qt::LeftButton)
        {
            return onLButtonPress(u16Mods, pntLocal, pntGlobal);
        }
        else if (pMouseEvent->button() == Qt::MiddleButton)
        {
            return onMButtonPress(u16Mods, pntLocal, pntGlobal);
        }
        else if (pMouseEvent->button() == Qt::RightButton)
        {
            return onRButtonPress(u16Mods, pntLocal, pntGlobal);
        }
    }

    // MouseMove events
    else if (_pEvent->type() == QEvent::MouseMove)
    {
        QMouseEvent *pMouseEvent    = static_cast<QMouseEvent *>(_pEvent);
        u16         u16Mods         = modifierFromEvent(pMouseEvent);
        aPoint      pntLocal(pMouseEvent->pos().x(), pMouseEvent->pos().y());
        aPoint      pntGlobal(pMouseEvent->globalPosition().x(), pMouseEvent->globalPosition().y());

        // Welche Maustaste(n) sind während der Bewegung gedrückt?
        Qt::MouseButtons buttons = pMouseEvent->buttons();

        bool bLeftPressed   = buttons & Qt::LeftButton;
        bool bMiddlePressed = buttons & Qt::MiddleButton;
        bool bRightPressed  = buttons & Qt::RightButton;

        // if only one button is pressed => call the appriate function
        // else call the onMouseMove with the pressed button info
        if (bLeftPressed && !bMiddlePressed && !bRightPressed)
        {
            // only left button is pressed
            return onLMouseMove(u16Mods, pntLocal, pntGlobal);
        }
        else if (!bLeftPressed && bMiddlePressed && !bRightPressed)
        {
            // only middle button is pressed
            return onMMouseMove(u16Mods, pntLocal, pntGlobal);
        }
        else if (!bLeftPressed && !bMiddlePressed && bRightPressed)
        {
            // only right button is pressed
            return onRMouseMove(u16Mods, pntLocal, pntGlobal);
        }
        else if (!bLeftPressed && !bMiddlePressed && !bRightPressed)
        {
            // no button pressed
            return onMouseMove(u16Mods, pntLocal, pntGlobal);
        }
        else
        {
            // multiple buttons are pressed
            return onMultipleMouseMove(u16Mods, pntLocal, pntGlobal, bLeftPressed, bMiddlePressed, bRightPressed);
        }
    }

    // MouseButtonRelease events
    else if (_pEvent->type() == QEvent::MouseButtonRelease)
    {
        QMouseEvent *pMouseEvent    = static_cast<QMouseEvent *>(_pEvent);
        u16         u16Mods         = modifierFromEvent(pMouseEvent);
        aPoint      pntLocal(pMouseEvent->pos().x(), pMouseEvent->pos().y());
        aPoint      pntGlobal(pMouseEvent->globalPosition().x(), pMouseEvent->globalPosition().y());

        // Prüfe welche Maustaste losgelassen wurde
        if (pMouseEvent->button() == Qt::LeftButton)
        {
            return onLButtonRelease(u16Mods, pntLocal, pntGlobal);
        }
        else if (pMouseEvent->button() == Qt::MiddleButton)
        {
            return onMButtonRelease(u16Mods, pntLocal, pntGlobal);
        }
        else if (pMouseEvent->button() == Qt::RightButton)
        {
            return onRButtonRelease(u16Mods, pntLocal, pntGlobal);
        }
    }

    return QObject::eventFilter(_pObj, _pEvent);
} // aBaseWin::eventFilter


/*******************************************************************************
* aBaseWin::modifierFromEvent
*******************************************************************************/
u16 aBaseWin::modifierFromEvent(QInputEvent *_pMouseEvent) const
{
    u16                     u16Mods     = MODIFIER_NONE;
    Qt::KeyboardModifiers   modifiers   = _pMouseEvent->modifiers();

    if (_pMouseEvent->modifiers() & Qt::ControlModifier)
        u16Mods |= MODIFIER_CTRL;

    if (modifiers & Qt::ShiftModifier)
        u16Mods |= MODIFIER_SHIFT;

    if (modifiers & Qt::AltModifier)
        u16Mods |= MODIFIER_ALT;

    if (modifiers & Qt::MetaModifier)
        u16Mods |= MODIFIER_META;

    if (modifiers & Qt::KeypadModifier)
            u16Mods |= MODIFIER_KEYPAD;

    return u16Mods;
} // aBaseWin::modifierFromEvent


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


// /*******************************************************************************
// * qSysWin::wheelEvent
// *******************************************************************************/
// template<class T>
// void aBaseWin::wheelEvent(QWheelEvent *_pEvent)
// {
//     u32             u32Modifiers    = 0;//_Modifiers();
//     aPoint2D<s32>  v2dLocal;//        = _LocalCursorPos();
//     aPoint2D<s32>  v2dGlobal;//       = _GlobalCursorPos();
//     s32             s32Degree       = (s32) (((dbl) _pEvent->angleDelta().y()) / 8.);
//     bool            bHandled        = false;

//     aToolMgr *pMgr = dynamic_cast<aToolMgr *> (this);
//     if (pMgr != nullptr)
//     {
//         bHandled = pMgr->toolMgrOnWheel(u32Modifiers, s32Degree, v2dLocal, v2dGlobal);
//     }

//     bHandled |= onWheel(u32Modifiers, s32Degree, v2dLocal, v2dGlobal);

//     _pEvent->setAccepted(bHandled);
// } // qSysWin::wheelEvent
