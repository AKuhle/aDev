/*******************************************************************************
* \file aBaseWin.cpp
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
* aBaseWin::aBaseWin
*******************************************************************************/
template<class T>
aBaseWin<T>::aBaseWin(SysWinClass *_pParent /*= nullptr*/)
: aSysWin_sys<T>(_pParent)
{
} // aBaseWin::aBaseWin


/*******************************************************************************
* aBaseWin::~aBaseWin
*******************************************************************************/
template<class T>
aBaseWin<T>::~aBaseWin()
{
} // aBaseWin::aBaseWin


/*******************************************************************************
* aBaseWin::create
*******************************************************************************/
template<class T>
bool aBaseWin<T>::create()
{
    if (this->onSysCreate() && this->onCreate())
    {
        return true;
    }

    return false;
} // aBaseWin::create


/*******************************************************************************
* aBaseWin::setMinSize
*******************************************************************************/
template<class T>
void aBaseWin<T>::setMinSize(aDimension2D<s32>  _dim)
{
    this->_setMinSize(_dim.w(), _dim.h());
} // aBaseWin::setMinSize


/*******************************************************************************
* aBaseWin::setParent
*******************************************************************************/
template<class T>
void aBaseWin<T>::setParent(SysWinClass *_pParent)
{
    this->_setParent(_pParent);
} // aBaseWin::setParent


/*******************************************************************************
* aBaseWin::parent
*******************************************************************************/
template<class T>
SysWinClass* aBaseWin<T>::parent() const
{
    return this->_parent();
} // aBaseWin::parent


/*******************************************************************************
* aBaseWin::setMinSize
*******************************************************************************/
template<class T>
void aBaseWin<T>::setMinSize(s32  _w,
                             s32  _h)
{
    this->_setMinSize(_w, _h);
} // aBaseWin::setMinSize


/*******************************************************************************
* aBaseWin::isVisible
*******************************************************************************/
template<class T>
bool aBaseWin<T>::isVisible() const
{
    return this->_isVisible();
} // aBaseWin::isVisible


/*******************************************************************************
* aBaseWin::setVisible
*******************************************************************************/
template<class T>
void aBaseWin<T>::setVisible(bool _bVisible)
{
    this->_setVisible(_bVisible);
} // aBaseWin::setVisible


/*******************************************************************************
* aBaseWin::show
*******************************************************************************/
template<class T>
void aBaseWin<T>::show()
{
    this->_setVisible(true);
} // aBaseWin::show


/*******************************************************************************
* aBaseWin::hide
*******************************************************************************/
template<class T>
void aBaseWin<T>::hide()
{
    this->_setVisible(false);
} // aBaseWin::hide


/*******************************************************************************
* aBaseWin::_onOsDropUrl
*******************************************************************************/
template<class T>
void aBaseWin<T>::_onOsDropUrl(const aUrl  &_url)
{
    onDropUrl(_url);
} // aBaseWin::_onOsDropUrl


} // namespace aWin
} // namespace aLib
