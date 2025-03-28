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


} // namespace aWin
} // namespace aLib

#endif //_USE_QT_
