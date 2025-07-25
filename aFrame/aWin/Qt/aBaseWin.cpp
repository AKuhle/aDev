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

#include "aBaseWin.h"
#include "aRect2D.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aFrame {
namespace aWin {


/*******************************************************************************
* aBaseWin::aBaseWin
*******************************************************************************/
aBaseWin::aBaseWin(SysWin *_pWin)
{
    m_pWin = _pWin;

    // delete the window when it is beeing closed
    m_pWin->setAttribute(Qt::WA_DeleteOnClose);

    // no background painting
    m_pWin->setAttribute(Qt::WA_NoSystemBackground);
    m_pWin->setAttribute(Qt::WA_TranslucentBackground);

    // install the event filter
    m_pWin->installEventFilter(this);
} // aBaseWin::aBaseWin


/*******************************************************************************
* aBaseWin::~aBaseWin
*******************************************************************************/
aBaseWin::~aBaseWin()
{
} // aBaseWin::~aBaseWin


/*******************************************************************************
* aBaseWin::sysWinPtr
*******************************************************************************/
SysWin* aBaseWin::sysWinPtr()
{
    return m_pWin;
} // aBaseWin::sysWinPtr


/*******************************************************************************
* aBaseWin::setVisible
*******************************************************************************/
void aBaseWin::setVisible(bool _bVisible)
{
    m_pWin->setVisible(_bVisible);
} // aBaseWin::setVisible


/*******************************************************************************
* aBaseWin::isVisible
*******************************************************************************/
bool aBaseWin::isVisible() const
{
    return m_pWin->isVisible();
} // aBaseWin::isVisible


/*******************************************************************************
* aBaseWin::setMinW
*******************************************************************************/
void aBaseWin::setMinW(s32 _s32MinW)
{
    m_pWin->setMinimumWidth(_s32MinW);
} // aBaseWin::setMinW


/*******************************************************************************
* aBaseWin::setMinH
*******************************************************************************/
void aBaseWin::setMinH(s32 _s32MinH)
{
    m_pWin->setMinimumHeight(_s32MinH);
} // aBaseWin::setMinH


/*******************************************************************************
* aBaseWin::setMaxW
*******************************************************************************/
void aBaseWin::setMaxW(s32 _s32MaxW)
{
    m_pWin->setMaximumWidth(_s32MaxW);
} // aBaseWin::setMaxW


/*******************************************************************************
* aBaseWin::setMaxH
*******************************************************************************/
void aBaseWin::setMaxH(s32 _s32MaxH)
{
    m_pWin->setMaximumHeight(_s32MaxH);
} // aBaseWin::setMaxH


/*******************************************************************************
* aBaseWin::geometryRect
*******************************************************************************/
aRect2D<s32> aBaseWin::geometryRect() const
{
    QRect r = m_pWin->frameGeometry();

    return aRect2D<s32> (r.left(), r.right(), r.width(), r.height());
} // aBaseWin::geometryRect


/*******************************************************************************
* aBaseWin::geometryW
*******************************************************************************/
s32 aBaseWin::geometryW() const
{
    return m_pWin->frameGeometry().width();
} // aBaseWin::geometryW


/*******************************************************************************
* aBaseWin::geometryH
*******************************************************************************/
s32 aBaseWin::geometryH() const
{
    return m_pWin->frameGeometry().height();
} // aBaseWin::geometryH


/*******************************************************************************
* aBaseWin::eventFilter
*******************************************************************************/
bool aBaseWin::eventFilter(QObject *_pObj,
                           QEvent  *_pEvent)
{
    if (_pObj == m_pWin && _pEvent->type() == QEvent::Paint)
    {
        //QPaintEvent     *pPaintEvent = static_cast<QPaintEvent *>(_pEvent);
        //handleWidgetPaint(pPaintEvent);
        onPaint();

        // true = Event wurde behandelt (stoppt weitere Verarbeitung)
        // false = Event wird normal weiterverarbeitet
        return true; // Meist false, damit das Widget normal gezeichnet wird
    }

    return QObject::eventFilter(_pObj, _pEvent);
} // aBaseWin::eventFilter
















// /*******************************************************************************
// * aBaseWin::closeWin
// *******************************************************************************/
// template<class T>
// bool aBaseWin::closeWin()
// {
//     if (onCloseWin())
//     {
//         T::close();

//         return true;
//     }

//     return false;
// } // aBaseWin::closeWin


// /*******************************************************************************
// * aBaseWin::setParent
// *******************************************************************************/
// template<class T>
// void aBaseWin::setParent(SysWin *_pParent)
// {
//     T::setParent(_pParent);
// } // aBaseWin::setParent


// /*******************************************************************************
// * aBaseWin::parent
// *******************************************************************************/
// template<class T>
// SysWin* aBaseWin::parent() const
// {
//     return T::parentWidget();
// } // aBaseWin::_parent


// /*******************************************************************************
// * aBaseWin::update
// *******************************************************************************/
// template<class T>
// void aBaseWin::update()
// {
//     T::update();
// } // aBaseWin::update


// /*******************************************************************************
// * aBaseWin::repaint
// *******************************************************************************/
// template<class T>
// void aBaseWin::repaint()
// {
//     T::repaint();
// } // aBaseWin::repaint


// /*******************************************************************************
// * aBaseWin::setWinTitle
// *******************************************************************************/
// template<class T>
// void aBaseWin::setWinTitle(const aString &_sTitle)
// {
//     T::setWindowTitle(_sTitle.toQString());
// } // aBaseWin::setWinTitle


// /*******************************************************************************
// * aBaseWin::setMouseTracking
// *******************************************************************************/
// template<class T>
// void aBaseWin::setMouseTracking(bool _bEnable)
// {
//     T::setMouseTracking(_bEnable);
// } // aBaseWin::setMouseTracking


// /*******************************************************************************
// * aBaseWin::setMinSize
// *******************************************************************************/
// template<class T>
// void aBaseWin::setMinSize(const aDimension2D<s32> &_dim)
// {
//     T::setMinimumSize(_dim.w(), _dim.h());
// } // aBaseWin::setMinSize


// /*******************************************************************************
// * aBaseWin::setMinSize
// *******************************************************************************/
// template<class T>
// void aBaseWin::setMinSize(s32  _s32W,
//                              s32  _s32H)
// {
//     T::setMinimumSize(_s32W, _s32H);
// } // aBaseWin::setMinSize


// /*******************************************************************************
// * aBaseWin::setMinW
// *******************************************************************************/
// template<class T>
// void aBaseWin::setMinW(s32  _s32W)
// {
//     T::setMinimumWidth(_s32W);
// } // aBaseWin::setMinW


// /*******************************************************************************
// * aBaseWin::setMinH
// *******************************************************************************/
// template<class T>
// void aBaseWin::setMinH(s32  _s32H)
// {
//     T::setMinimumHeight(_s32H);
// } // aBaseWin::setMinH


// /*******************************************************************************
// * aBaseWin::setFixedW
// *******************************************************************************/
// template<class T>
// void aBaseWin::setFixedW(s32  _s32W)
// {
//     T::setFixedWidth(_s32W);
// } // aBaseWin::setFixedW


// /*******************************************************************************
// * aBaseWin::setFixedH
// *******************************************************************************/
// template<class T>
// void aBaseWin::setFixedH(s32  _s32H)
// {
//     T::setFixedHeight(_s32H);
// } // aBaseWin::setFixedH


// /*******************************************************************************
// * aBaseWin::clientRect
// *******************************************************************************/
// template<class T>
// aRect2D<s32> aBaseWin::clientRect() const
// {
//     QRect r = T::geometry();

//     aRect2D<s32>    r2d(0, 0,r.width(), r.height());

//     return r2d;
// } // aBaseWin::clientRect


// /*******************************************************************************
// * aBaseWin::clientW
// *******************************************************************************/
// template<class T>
// s32 aBaseWin::clientW() const
// {
//     return T::geometry().width();
// } // aBaseWin::clientW


// /*******************************************************************************
// * aBaseWin::clientH
// *******************************************************************************/
// template<class T>
// s32 aBaseWin::clientH() const
// {
//     return T::geometry().height();
// } // aBaseWin::clientH


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
//     aVector2D<s32>  v2dLocal;//        = _LocalCursorPos();
//     aVector2D<s32>  v2dGlobal;//       = _GlobalCursorPos();
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

} // namespace aWin
} // namespace aFrame


#endif //_USE_QT_
