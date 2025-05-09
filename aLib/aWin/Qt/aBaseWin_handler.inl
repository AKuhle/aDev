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
* aBaseWin::onSysCreateWin
*******************************************************************************/
template<class T>
bool aBaseWin<T>::onSysCreateWin()
{
    return true;
} // aBaseWin::onSysCreateWin


/*******************************************************************************
* aBaseWin::onCreateWin
*******************************************************************************/
template<class T>
bool aBaseWin<T>::onCreateWin()
{
    return true;
} // aBaseWin::onCreateWin


/*******************************************************************************
* aBaseWin::onCloseWin
*******************************************************************************/
template<class T>
bool aBaseWin<T>::onCloseWin()
{
    return true;
} // aBaseWin::onCloseWin


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
* aBaseWin::onWheel
*******************************************************************************/
template<class T>
bool aBaseWin<T>::onWheel(u32                  /*_u32Modifiers*/,
                          s32                  /*_s32Degree*/,
                          const aVector2D<s32> &/*_v2dLocal*/,
                          const aVector2D<s32> &/*_v2dGlobal*/)
{
    return false;
} // aBaseWin::onWheel


} // namespace aWin
} // namespace aLib

#endif //_USE_QT_
