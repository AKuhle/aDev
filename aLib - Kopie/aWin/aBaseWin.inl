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
* aBaseWin<T>::aBaseWin
*******************************************************************************/
template<class T>
aBaseWin<T>::aBaseWin(SysWinClass    *_pParent)
: aBaseWin_sys<T>(_pParent)
{
} // aBaseWin<T>::aBaseWin


/*******************************************************************************
* aBaseWin<T>::~aBaseWin
*******************************************************************************/
template<class T>
aBaseWin<T>::~aBaseWin()
{
} // aBaseWin<T>::aBaseWin


/*******************************************************************************
* aBaseWin<T>::create
*******************************************************************************/
template<class T>
bool aBaseWin<T>::create()
{
    if (onSysCreate() && onCreate())
    {
        return true;
    }

    return false;
} // aBaseWin<T>::create


/*******************************************************************************
* aBaseWin<T>::setParent
*******************************************************************************/
template<class T>
void aBaseWin<T>::setParent(SysWinClass *_pParent)
{
    aBaseWin_sys<T>::setParent(_pParent);
} // aBaseWin<T>::setParent


/*******************************************************************************
* aBaseWin<T>::parent
*******************************************************************************/
template<class T>
SysWinClass* aBaseWin<T>::parent() const
{
    return aBaseWin_sys<T>::parent();
} // aBaseWin<T>::parent


/*******************************************************************************
* aBaseWin<T>::update
*******************************************************************************/
template<class T>
void aBaseWin<T>::update()
{
    aBaseWin_sys<T>::update();
} // aBaseWin<T>::update


/*******************************************************************************
* aBaseWin<T>::repaint
*******************************************************************************/
template<class T>
void aBaseWin<T>::repaint()
{
    aBaseWin_sys<T>::repaint();
} // aBaseWin<T>::repaint


/*******************************************************************************
* aBaseWin<T>::setVisible
*******************************************************************************/
template<class T>
void aBaseWin<T>::setVisible(bool _bVisible)
{
    aBaseWin_sys<T>::setVisible(_bVisible);
} // aBaseWin<T>::setVisible


/*******************************************************************************
* aBaseWin<T>::show
*******************************************************************************/
template<class T>
void aBaseWin<T>::show()
{
    aBaseWin_sys<T>::setVisible(true);
} // aBaseWin<T>::show


/*******************************************************************************
* aBaseWin<T>::hide
*******************************************************************************/
template<class T>
void aBaseWin<T>::hide()
{
    aBaseWin_sys<T>::setVisible(false);
} // aBaseWin<T>::hide


/*******************************************************************************
* aBaseWin<T>::isVisible
*******************************************************************************/
template<class T>
bool aBaseWin<T>::isVisible() const
{
    return aBaseWin_sys<T>::isVisible();
} // aBaseWin<T>::isVisible


/*******************************************************************************
* aBaseWin<T>::setMouseTracking
*******************************************************************************/
template<class T>
void aBaseWin<T>::setMouseTracking(bool _bEnable)
{
    aBaseWin_sys<T>::setMouseTracking(_bEnable);
} // aBaseWin<T>::setMouseTracking


/*******************************************************************************
* aBaseWin<T>::setMinSize
*******************************************************************************/
template<class T>
void aBaseWin<T>::setMinSize(s32  _w,
                             s32  _h)
{
    aBaseWin_sys<T>::setMinSize(_w, _h);
} // aBaseWin<T>::setMinSize


/*******************************************************************************
* aBaseWin<T>::clientRect
*******************************************************************************/
template<class T>
aRect2D<s32> aBaseWin<T>::clientRect() const
{
    return aBaseWin_sys<T>::clientRect();
} // aBaseWin<T>::clientRect


/*******************************************************************************
* aBaseWin<T>::clientW
*******************************************************************************/
template<class T>
s32 aBaseWin<T>::clientW() const
{
    return aBaseWin_sys<T>::clientRect().w();
} // aBaseWin<T>::clientW


/*******************************************************************************
* aBaseWin<T>::clientH
*******************************************************************************/
template<class T>
s32 aBaseWin<T>::clientH() const
{
    return aBaseWin_sys<T>::clientRect().h();
} // aBaseWin<T>::clientH


/*******************************************************************************
* aBaseWin<T>::setMinSize
*******************************************************************************/
template<class T>
void aBaseWin<T>::setMinSize(const aDimension2D<s32> &_dim)
{
    aBaseWin_sys<T>::setMinSize(_dim.w(), _dim.h());
} // aBaseWin<T>::setMinSize


} // namespace aWin
} // namespace aLib




// /*******************************************************************************
// * aBaseWin<T>::isVisible
// *******************************************************************************/
// template<class T>
// bool aBaseWin<T>::isVisible() const
// {
//     return this->_isVisible();
// } // aBaseWin<T>::isVisible
