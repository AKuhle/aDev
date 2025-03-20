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
* namespace
*******************************************************************************/
namespace aLib {
namespace aWin {


/*******************************************************************************
* aBaseWin_sys<T>::aBaseWin_sys
*******************************************************************************/
template<class T>
aBaseWin_sys<T>::aBaseWin_sys(SysWinClass *_pParent)
: T(_pParent)
{
} // aBaseWin_sys<T>::_isVisible


/*******************************************************************************
* aBaseWin_sys<T>::~aBaseWin_sys
*******************************************************************************/
template<class T>
aBaseWin_sys<T>::~aBaseWin_sys()
{
} // aBaseWin_sys<T>::_isVisible


/*******************************************************************************
* aBaseWin_sys<T>::setParent
*******************************************************************************/
template<class T>
void aBaseWin_sys<T>::setParent(SysWinClass *_pParent)
{
    T::setParent(_pParent);
} // aBaseWin_sys<T>::setParent


/*******************************************************************************
* aBaseWin_sys<T>::parent
*******************************************************************************/
template<class T>
SysWinClass* aBaseWin_sys<T>::parent() const
{
    return T::parentWidget();
} // aBaseWin_sys<T>::_parent


/*******************************************************************************
* aBaseWin_sys<T>::setVisible
*******************************************************************************/
template<class T>
void aBaseWin_sys<T>::setVisible(bool _bVisible)
{
    T::setVisible(_bVisible);
} // aBaseWin_sys<T>::setVisible


/*******************************************************************************
* aBaseWin_sys<T>::isVisible
*******************************************************************************/
template<class T>
bool aBaseWin_sys<T>::isVisible() const
{
    return T::isVisible();
} // aBaseWin_sys<T>::isVisible


/*******************************************************************************
* aBaseWin_sys<T>::setMouseTracking
*******************************************************************************/
template<class T>
void aBaseWin_sys<T>::setMouseTracking(bool _bEnable)
{
    T::setMouseTracking(_bEnable);
} // aBaseWin_sys<T>::setMouseTracking


/*******************************************************************************
* aBaseWin_sys<T>::setMinSize
*******************************************************************************/
template<class T>
void aBaseWin_sys<T>::setMinSize(s32  _s32W,
                                 s32  _s32H)
{
    T::setMinimumSize(_s32W, _s32H);
} // aBaseWin_sys<T>::setMinSize


/*******************************************************************************
* aBaseWin_sys<T>::dragEnterEvent
*******************************************************************************/
template<class T>
void aBaseWin_sys<T>::dragEnterEvent(QDragEnterEvent *_pEvent)
{
    if (_pEvent->mimeData()->hasUrls())
    {
        _pEvent->acceptProposedAction();
    }
        else
    {
        _pEvent->ignore();
    }
} // aBaseWin_sys<T>::dragEnterEvent


/*******************************************************************************
* aBaseWin_sys<T>::dragMoveEvent
*******************************************************************************/
template<class T>
void aBaseWin_sys<T>::dragMoveEvent(QDragMoveEvent *_pEvent)
{
    if (_pEvent->mimeData()->hasUrls())
    {
        _pEvent->acceptProposedAction();
    }
        else
    {
        _pEvent->ignore();
    }
} // aBaseWin_sys<T>::dragMoveEvent


/*******************************************************************************
* aBaseWin_sys<T>::dropEvent
*******************************************************************************/
template<class T>
void aBaseWin_sys<T>::dropEvent(QDropEvent *_pEvent)
{
    if (_pEvent->mimeData()->hasUrls())
    {
        _pEvent->acceptProposedAction();

        foreach (QUrl url, _pEvent->mimeData()->urls())
        {
           onSysDropUrl(aUrl(url));
        }
    }
} // aBaseWin_sys<T>::dropEvent


// /*******************************************************************************
// * aBaseWin_sys<T>::paintEvent
// *******************************************************************************/
// template<class T>
// void aBaseWin_sys<T>::paintEvent(QPaintEvent *_pEvent)
// {
//     if (_onOsPaint())
//     {
//         _pEvent->accept();
//     }
//     else
//     {
//         T::paintEvent(_pEvent);
//     }
// } // aBaseWin_sys<T>::paintEvent


} // namespace aWin
} // namespace aLib


#endif //_USE_QT_



// /*******************************************************************************
// * aBaseWin_sys<T>::_update
// *******************************************************************************/
// template<class T>
// void aBaseWin_sys<T>::_update()
// {
//     T::update();
// } // aBaseWin_sys<T>::_update


// /*******************************************************************************
// * aBaseWin_sys<T>::_repaint
// *******************************************************************************/
// template<class T>
// void aBaseWin_sys<T>::_repaint()
// {
//     T::repaint();
// } // aBaseWin_sys<T>::_repaint


// /*******************************************************************************
// * aBaseWin_sys<T>::_setMinSize
// *******************************************************************************/
// template<class T>
// void aBaseWin_sys<T>::_setMinSize(s32  _w,
//                                  s32  _h)
// {
//     T::setMinimumSize(_w, _h);
// } // aBaseWin_sys<T>::_setMinSize


// /*******************************************************************************
// * aBaseWin_sys<T>::_clientRect
// *******************************************************************************/
// template<class T>
// aRect2D<s32> aBaseWin_sys<T>::_clientRect() const
// {
//     QRect r = T::geometry();

//     aRect2D<s32>    r2d(0, 0,r.width(), r.height());

//     return r2d;
// } // aBaseWin_sys<T>::_clientRect
