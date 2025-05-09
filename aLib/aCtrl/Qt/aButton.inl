/*******************************************************************************
* \file aButton.inl
* \author Andreas Kuhlewind
*
* \brief
*
* $Revision: 69 $
* $LastChangedDate: 2010-08-17 14:10:45 +0200 (Di, 17 Aug 2010) $
* $LastChangedBy: akuhlewi $
*
*  Detailed description starts here.
*******************************************************************************/
#ifdef _USE_QT_


/*******************************************************************************
* includes
*******************************************************************************/


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aWin {


/*******************************************************************************
* aButton<T>::aButton
*******************************************************************************/
template<class T>
aButton<T>::aButton(SysWin *_pParent)
: aCtrl<T>(_pParent)
{
} // aButton<T>::aButton


/*******************************************************************************
* aButton<T>::~aButton
*******************************************************************************/
template<class T>
aButton<T>::~aButton()
{
} // aButton<T>::~aButton


/*******************************************************************************
* aButton<T>::setCtrlChecked
*******************************************************************************/
template<class T>
void aButton<T>::setCtrlChecked(bool _bChecked)
{
    T::setChecked(_bChecked);
} // aButton<T>::setCtrlChecked


/*******************************************************************************
* aButton<T>::setCtrlEnabledChecked
*******************************************************************************/
template<class T>
void aButton<T>::setCtrlEnabledChecked(bool _bEnabled,
                                       bool _bChecked)
{
    T::setEnabled(_bEnabled);
    T::setChecked(_bChecked);
} // aButton<T>::setCtrlEnabledChecked


/*******************************************************************************
* aButton<T>::ctrlChecked
*******************************************************************************/
template<class T>
bool aButton<T>::ctrlChecked() const
{
    return T::isChecked();
} // aButton<T>::ctrlChecked


} // namespace aWin
} // namespace aLib

#endif //_USE_QT_
