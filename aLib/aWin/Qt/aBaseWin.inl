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
* namespace
*******************************************************************************/
namespace aLib {
namespace aWin {


/*******************************************************************************
* aBaseWin<T>::aBaseWin
*******************************************************************************/
template<class T>
aBaseWin<T>::aBaseWin(SysWin *_pParent)
: T(_pParent)
{
} // aBaseWin<T>::_isVisible


/*******************************************************************************
* aBaseWin<T>::~aBaseWin
*******************************************************************************/
template<class T>
aBaseWin<T>::~aBaseWin()
{
} // aBaseWin<T>::~aBaseWin


/*******************************************************************************
* aBaseWin<T>::create
*******************************************************************************/
template<class T>
bool aBaseWin<T>::create()
{
    if (onSysCreate() && onCreate())
    {
        return true;
    }

    return false;
} // aBaseWin<T>::create


/*******************************************************************************
* aBaseWin<T>::setParent
*******************************************************************************/
template<class T>
void aBaseWin<T>::setParent(SysWin *_pParent)
{
    T::setParent(_pParent);
} // aBaseWin<T>::setParent


/*******************************************************************************
* aBaseWin<T>::parent
*******************************************************************************/
template<class T>
SysWin* aBaseWin<T>::parent() const
{
    return T::parentWidget();
} // aBaseWin<T>::_parent


/*******************************************************************************
* aBaseWin<T>::update
*******************************************************************************/
template<class T>
void aBaseWin<T>::update()
{
    T::update();
} // aBaseWin<T>::update


/*******************************************************************************
* aBaseWin<T>::repaint
*******************************************************************************/
template<class T>
void aBaseWin<T>::repaint()
{
    T::repaint();
} // aBaseWin<T>::repaint


/*******************************************************************************
* aBaseWin<T>::setVisible
*******************************************************************************/
template<class T>
void aBaseWin<T>::setVisible(bool _bVisible)
{
    T::setVisible(_bVisible);
} // aBaseWin<T>::setVisible


/*******************************************************************************
* aBaseWin<T>::show
*******************************************************************************/
template<class T>
void aBaseWin<T>::show()
{
    T::show();
} // aBaseWin<T>::show


/*******************************************************************************
* aBaseWin<T>::hide
*******************************************************************************/
template<class T>
void aBaseWin<T>::hide()
{
    T::hide();
} // aBaseWin<T>::hide


/*******************************************************************************
* aBaseWin<T>::isVisible
*******************************************************************************/
template<class T>
bool aBaseWin<T>::isVisible() const
{
    return T::isVisible();
} // aBaseWin<T>::isVisible


/*******************************************************************************
* aBaseWin<T>::setMouseTracking
*******************************************************************************/
template<class T>
void aBaseWin<T>::setMouseTracking(bool _bEnable)
{
    T::setMouseTracking(_bEnable);
} // aBaseWin<T>::setMouseTracking


/*******************************************************************************
* aBaseWin<T>::setMinSize
*******************************************************************************/
template<class T>
void aBaseWin<T>::setMinSize(const aDimension2D<s32> &_dim)
{
    T::setMinimumSize(_dim.w(), _dim.h());
} // aBaseWin<T>::setMinSize


/*******************************************************************************
* aBaseWin<T>::setMinSize
*******************************************************************************/
template<class T>
void aBaseWin<T>::setMinSize(s32  _s32W,
                             s32  _s32H)
{
    T::setMinimumSize(_s32W, _s32H);
} // aBaseWin<T>::setMinSize


/*******************************************************************************
* aBaseWin<T>::clientRect
*******************************************************************************/
template<class T>
aRect2D<s32> aBaseWin<T>::clientRect() const
{
    QRect r = T::geometry();

    aRect2D<s32>    r2d(0, 0,r.width(), r.height());

    return r2d;
} // aBaseWin<T>::clientRect


/*******************************************************************************
* aBaseWin<T>::clientW
*******************************************************************************/
template<class T>
s32 aBaseWin<T>::clientW() const
{
    return T::geometry().width();
} // aBaseWin<T>::clientW


/*******************************************************************************
* aBaseWin<T>::clientH
*******************************************************************************/
template<class T>
s32 aBaseWin<T>::clientH() const
{
    return T::geometry().height();
} // aBaseWin<T>::clientH


/*******************************************************************************
* aBaseWin<T>::dragEnterEvent
*******************************************************************************/
template<class T>
void aBaseWin<T>::dragEnterEvent(QDragEnterEvent *_pEvent)
{
    if (_pEvent->mimeData()->hasUrls())
    {
        _pEvent->acceptProposedAction();
    }
        else
    {
        _pEvent->ignore();
    }
} // aBaseWin<T>::dragEnterEvent


/*******************************************************************************
* aBaseWin<T>::dragMoveEvent
*******************************************************************************/
template<class T>
void aBaseWin<T>::dragMoveEvent(QDragMoveEvent *_pEvent)
{
    if (_pEvent->mimeData()->hasUrls())
    {
        _pEvent->acceptProposedAction();
    }
        else
    {
        _pEvent->ignore();
    }
} // aBaseWin<T>::dragMoveEvent


/*******************************************************************************
* aBaseWin<T>::dropEvent
*******************************************************************************/
template<class T>
void aBaseWin<T>::dropEvent(QDropEvent *_pEvent)
{
    if (_pEvent->mimeData()->hasUrls())
    {
        _pEvent->acceptProposedAction();

        foreach (QUrl url, _pEvent->mimeData()->urls())
        {
           onDropUrl(aUrl(url));
        }
    }
} // aBaseWin<T>::dropEvent


/*******************************************************************************
* aBaseWin<T>::paintEvent
*******************************************************************************/
template<class T>
void aBaseWin<T>::paintEvent(QPaintEvent *_pEvent)
{
    if (onPaint())
    {
        _pEvent->accept();
    }
    else
    {
        T::paintEvent(_pEvent);
    }
} // aBaseWin<T>::paintEvent


} // namespace aWin
} // namespace aLib


#endif //_USE_QT_
