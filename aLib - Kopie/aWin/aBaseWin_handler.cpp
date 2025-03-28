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
* aBaseWin::onSysCreate
*******************************************************************************/
template<class T>
bool aBaseWin<T>::onSysCreate()
{
    return true;
} // aBaseWin::onSysCreate


/*******************************************************************************
* aBaseWin::onCreate
*******************************************************************************/
template<class T>
bool aBaseWin<T>::onCreate()
{
    return true;
} // aBaseWin::onCreate


/*******************************************************************************
* aBaseWin::onDropUrl
*******************************************************************************/
template<class T>
void aBaseWin<T>::onDropUrl(const aUrl  &/*_url*/)
{
} // aBaseWin::onDropUrl


/*******************************************************************************
* aBaseWin::onPaint
*******************************************************************************/
template<class T>
bool aBaseWin<T>::onPaint()
{
    return false;
} // aBaseWin::onPaint


/*******************************************************************************
* aBaseWin::_onOsDropUrl
*******************************************************************************/
template<class T>
void aBaseWin<T>::_onOsDropUrl(const aUrl  &_url)
{
    onDropUrl(_url);
} // aBaseWin::_onOsDropUrl


/*******************************************************************************
* aBaseWin::_onOsPaint
*******************************************************************************/
template<class T>
bool aBaseWin<T>::_onOsPaint()
{
    return onPaint();
} // aBaseWin::_onOsPaint


} // namespace aWin
} // namespace aLib
