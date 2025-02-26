/*******************************************************************************
* \file aSysWin_sys.cpp
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
* aSysWin_sys<T>::aSysWin_sys
*******************************************************************************/
template<class T>
aSysWin_sys<T>::aSysWin_sys(SysWinClass *_pParent /*= nullptr*/)
: T(_pParent)
{
} // aSysWin_sys<T>::_isVisible


/*******************************************************************************
* aSysWin_sys<T>::~aSysWin_sys
*******************************************************************************/
template<class T>
aSysWin_sys<T>::~aSysWin_sys()
{
} // aSysWin_sys<T>::_isVisible


/*******************************************************************************
* aSysWin_sys<T>::_setParent
*******************************************************************************/
template<class T>
void aSysWin_sys<T>::_setParent(SysWinClass *_pParent)
{
    T::setParent(_pParent);
} // aSysWin_sys<T>::_setParent


/*******************************************************************************
* aSysWin_sys<T>::_parent
*******************************************************************************/
template<class T>
SysWinClass* aSysWin_sys<T>::_parent()
{
    return T::parentWidget();
} // aSysWin_sys<T>::_parent


/*******************************************************************************
* aSysWin_sys<T>::_setMinSize
*******************************************************************************/
template<class T>
void aSysWin_sys<T>::_setMinSize(s32  _w,
                                 s32  _h)
{
    T::setMinimumSize(_w, _h);
} // aSysWin_sys<T>::_setMinSize


/*******************************************************************************
* aSysWin_sys<T>::_isVisible
*******************************************************************************/
template<class T>
bool aSysWin_sys<T>::_isVisible() const
{
    return T::isVisible();
} // aSysWin_sys<T>::_isVisible


/*******************************************************************************
* aSysWin_sys<T>::_setVisible
*******************************************************************************/
template<class T>
void aSysWin_sys<T>::_setVisible(bool _bVisible)
{
    T::setVisible(_bVisible);
} // aSysWin_sys<T>::_setVisible


/*******************************************************************************
* aSysWin_sys<T>::dragEnterEvent
*******************************************************************************/
template<class T>
void aSysWin_sys<T>::dragEnterEvent(QDragEnterEvent *_pEvent)
{
    if (_pEvent->mimeData()->hasUrls())
    {
        _pEvent->acceptProposedAction();
    }
        else
    {
        _pEvent->ignore();
    }
} // aSysWin_sys<T>::dragEnterEvent


/*******************************************************************************
* aSysWin_sys<T>::dragMoveEvent
*******************************************************************************/
template<class T>
void aSysWin_sys<T>::dragMoveEvent(QDragMoveEvent *_pEvent)
{
    if (_pEvent->mimeData()->hasUrls())
    {
        _pEvent->acceptProposedAction();
    }
        else
    {
        _pEvent->ignore();
    }
} // aSysWin_sys<T>::dragMoveEvent


/*******************************************************************************
* aSysWin_sys<T>::dropEvent
*******************************************************************************/
template<class T>
void aSysWin_sys<T>::dropEvent(QDropEvent *_pEvent)
{
    if (_pEvent->mimeData()->hasUrls())
    {
        _pEvent->acceptProposedAction();
\
        foreach (QUrl url, _pEvent->mimeData()->urls())
        {
           _onOsDropUrl(aUrl(url));
        }
    }
} // aSysWin_sys<T>::dropEvent


} // namespace aWin
} // namespace aLib

#endif //_USE_QT_
