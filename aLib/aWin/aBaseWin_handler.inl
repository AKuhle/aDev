/*******************************************************************************
* \file aBaseWin.cpp
* \author Andreas Kuhlewind
*
* \brief
*
*  Detailed description starts here.
*******************************************************************************/


/*******************************************************************************
* includes
*******************************************************************************/


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aWin {


/*******************************************************************************
* aBaseWin<T>::onSysCreate
*******************************************************************************/
template<class T>
bool aBaseWin<T>::onSysCreate()
{
    return true;
} // aBaseWin<T>::onSysCreate


/*******************************************************************************
* aBaseWin<T>::onCreate
*******************************************************************************/
template<class T>
bool aBaseWin<T>::onCreate()
{
    return true;
} // aBaseWin<T>::onCreate


/*******************************************************************************
* aBaseWin<T>::onDropUrl
*******************************************************************************/
template<class T>
void aBaseWin<T>::onDropUrl(const aUrl  &/*_url*/)
{
} // aBaseWin<T>::onDropUrl


/*******************************************************************************
* aBaseWin<T>::onSysDropUrl
*******************************************************************************/
template<class T>
void aBaseWin<T>::onSysDropUrl(const aUrl  &_url)
{
    onDropUrl(_url);
} // aBaseWin<T>::onSysDropUrl


} // namespace aWin
} // namespace aLib
