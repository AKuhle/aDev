/*******************************************************************************
* \file aCtrl.inl
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
* aCtrl<T>::aCtrl
*******************************************************************************/
template<class T>
aCtrl<T>::aCtrl(SysWin *_pParent)
: aBaseWin<T>(_pParent)
{
} // aCtrl<T>::aCtrl


/*******************************************************************************
* aCtrl<T>::~aCtrl
*******************************************************************************/
template<class T>
aCtrl<T>::~aCtrl()
{
} // aCtrl<T>::~aCtrl


/*******************************************************************************
* aCtrl<T>::setCtrlId
*******************************************************************************/
template<class T>
void aCtrl<T>::setCtrlId(s32 _s32CtrlID)
{
    m_s32CtrlID = _s32CtrlID;
} // aCtrl<T>::setCtrlId


/*******************************************************************************
* aCtrl<T>::ctrlId
*******************************************************************************/
template<class T>
s32 aCtrl<T>::ctrlId() const
{
    return m_s32CtrlID;
} // aCtrl<T>::ctrlId


/*******************************************************************************
* aCtrl<T>::setCtrlMgr
*******************************************************************************/
template<class T>
void aCtrl<T>::setCtrlMgr(aCtrlMgr *_pCtrlMgr)
{
    m_pCtrlMgr = _pCtrlMgr;
} // aCtrl<T>::setCtrlMgr


/*******************************************************************************
* aCtrl<T>::ctrlMgr
*******************************************************************************/
template<class T>
aCtrlMgr* aCtrl<T>::ctrlMgr() const
{
    return m_pCtrlMgr;
} // aCtrl<T>::ctrlMgr


/*******************************************************************************
* aCtrl<T>::setCtrlEnabled
*******************************************************************************/
template<class T>
void aCtrl<T>::setCtrlEnabled(bool _bEnabled)
{
    T::setEnabled(_bEnabled);
} // aCtrl<T>::setCtrlEnabled


/*******************************************************************************
* aCtrl<T>::ctrlEnabled
*******************************************************************************/
template<class T>
bool aCtrl<T>::ctrlEnabled() const
{
    return T::isEnabled();
} // aCtrl<T>::ctrlEnabled


/*******************************************************************************
* aCtrl<T>::ctrlEnabled
*******************************************************************************/
template<class T>
void aCtrl<T>::setBackgroundColor(const aColor &_color)
{
    QPalette pal = T::palette();
    pal.setColor(QPalette::Button, _color.toQColor());
    T::setAutoFillBackground(true);
    T::setPalette(pal);
    T::update();
} // aCtrl<T>::setBackgroundColor


/*******************************************************************************
* aCtrl<T>::ctrlEnabled
*******************************************************************************/
template<class T>
aColor aCtrl<T>::backgroundColor() const
{
    QPalette pal = T::palette();

    return pal.color(QPalette::Button);
} // aCtrl<T>::backgroundColor


} // namespace aWin
} // namespace aLib

#endif //_USE_QT_
