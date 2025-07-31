/*******************************************************************************
* \file aPoint2D.inl
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


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aFrame {
namespace aMath {


/*******************************************************************************
* aPoint2D<T>::aPoint2D
*******************************************************************************/
template<class T>
aPoint2D<T>::aPoint2D()
{
} // aPoint2D<T>::aPoint2D


/*******************************************************************************
* aPoint2D<T>::aPoint2D
*******************************************************************************/
template<class T>
aPoint2D<T>::aPoint2D(const aPoint2D<T> &_rhs)
: m_x(_rhs.m_x),
  m_y(_rhs.m_y)
{
} // aPoint2D<T>::aPoint2D


template<class T>
/*******************************************************************************
* aPoint2D<T>::aPoint2D
*******************************************************************************/
aPoint2D<T>::aPoint2D(T _x,
                      T _y)
: m_x(_x),
  m_y(_y)
{
} // aPoint2D<T>::aPoint2D


/*******************************************************************************
* aPoint2D<T>::~aPoint2D
*******************************************************************************/
template<class T>
aPoint2D<T>::~aPoint2D()
{
} // aPoint2D<T>::~aPoint2D


/*******************************************************************************
* aPoint2D<T>::set
*******************************************************************************/
template<class T>
void aPoint2D<T>::set(T _x,
                      T _y)
{
    m_x = _x;
    m_y = _y;
} // aPoint2D<T>::set


/*******************************************************************************
* aPoint2D<T>::operator=
*******************************************************************************/
template<class T>
aPoint2D<T>& aPoint2D<T>::operator=(const aPoint2D<T> &_rhs)
{
    // avoid selfcopy
    m_x = _rhs.m_x;
    m_y = _rhs.m_y;

    return *this;
} // aPoint2D<T>::operator=


/*******************************************************************************
* aPoint2D<T>::operator==
*******************************************************************************/
template<class T>
bool aPoint2D<T>::operator==(const aPoint2D<T>	&_rhs) const
{
    return isEqual(m_x, _rhs.m_x) &&
           isEqual(m_y, _rhs.m_y);
} // aPoint2D<T>::operator==


/*******************************************************************************
* aPoint2D<T>::operator!=
*******************************************************************************/
template<class T>
bool aPoint2D<T>::operator!=(const aPoint2D<T>	&_rhs) const
{
    return isUnequal(m_x, _rhs.m_x) ||
           isUnequal(m_y, _rhs.m_y);
} // aPoint2D<T>::operator!=



} // namespace aMath
} // namespace aFrame
