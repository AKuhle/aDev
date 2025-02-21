/*******************************************************************************
* \file aSysWin.cpp
* \author Andreas Kuhlewind
*
* \brief
*
*  Detailed description starts here.
*******************************************************************************/


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aWin {


/*******************************************************************************
* aSysWin::aSysWin
*******************************************************************************/
template<class T>
aSysWin<T>::aSysWin(SysWinClass *_pParent /*= nullptr*/)
: aSysWin_sys<T>(_pParent)
{
} // aSysWin::aSysWin


/*******************************************************************************
* aSysWin::~aSysWin
*******************************************************************************/
template<class T>
aSysWin<T>::~aSysWin()
{
} // aSysWin::aSysWin


/*******************************************************************************
* aSysWin::create
*******************************************************************************/
template<class T>
bool aSysWin<T>::create()
{
    if (this->onSysCreate() && this->onCreate())
    {
        return true;
    }

    return false;
} // aSysWin::create


/*******************************************************************************
* aSysWin::isVisible
*******************************************************************************/
template<class T>
bool aSysWin<T>::isVisible() const
{
    return this->_isVisible();
} // aSysWin::isVisible


/*******************************************************************************
* aSysWin::setVisible
*******************************************************************************/
template<class T>
void aSysWin<T>::setVisible(bool _bVisible)
{
    this->_setVisible(_bVisible);
} // aSysWin::setVisible


/*******************************************************************************
* aSysWin::show
*******************************************************************************/
template<class T>
void aSysWin<T>::show()
{
    this->_setVisible(true);
} // aSysWin::show


/*******************************************************************************
* aSysWin::hide
*******************************************************************************/
template<class T>
void aSysWin<T>::hide()
{
    this->_setVisible(false);
} // aSysWin::hide


/*******************************************************************************
* aSysWin::onSysCreate
*******************************************************************************/
template<class T>
bool aSysWin<T>::onSysCreate()
{
    return true;
} // aSysWin::onSysCreate


/*******************************************************************************
* aSysWin::onCreate
*******************************************************************************/
template<class T>
bool aSysWin<T>::onCreate()
{
    return true;
} // aSysWin::onCreate


/*******************************************************************************
* aSysWin::onDropUrl
*******************************************************************************/
template<class T>
void aSysWin<T>::onDropUrl(const aUrl  &/*_url*/)
{
} // aSysWin::onDropUrl


/*******************************************************************************
* aSysWin::onOsDropUrl
*******************************************************************************/
template<class T>
void aSysWin<T>::onOsDropUrl(const aUrl  &_url)
{
    onDropUrl(_url);
} // aSysWin::onOsDropUrl


} // namespace aWin
} // namespace aLib
