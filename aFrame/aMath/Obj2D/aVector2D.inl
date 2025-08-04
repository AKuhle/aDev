/*******************************************************************************
* \file aVector2D.inl
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
* aVector2D<T>::aVector2D
*******************************************************************************/
template<class T>
aVector2D<T>::aVector2D()
{
} // aVector2D<T>::aVector2D


/*******************************************************************************
* aVector2D<T>::aVector2D
*******************************************************************************/
template<class T>
aVector2D<T>::aVector2D(const aVector2D<T> &_rhs)
: m_dx(_rhs.m_dx),
  m_dy(_rhs.m_dy)
{
} // aVector2D<T>::aVector2D


template<class T>
/*******************************************************************************
* aVector2D<T>::aVector2D
*******************************************************************************/
aVector2D<T>::aVector2D(T _dx,
                        T _dy)
: m_dx(_dx),
  m_dy(_dy)
{
} // aVector2D<T>::aVector2D


/*******************************************************************************
* aVector2D<T>::~aVector2D
*******************************************************************************/
template<class T>
aVector2D<T>::~aVector2D()
{
} // aVector2D<T>::~aVector2D


/*******************************************************************************
* aVector2D<T>::set
*******************************************************************************/
template<class T>
void aVector2D<T>::set(T _dx,
                       T _dy)
{
    m_dx = _dx;
    m_dy = _dy;
} // aVector2D<T>::set


/*******************************************************************************
* aVector2D<T>::operator=
*******************************************************************************/
template<class T>
aVector2D<T>& aVector2D<T>::operator=(const aVector2D<T> &_rhs)
{
    // avoid selfcopy
    m_dx = _rhs.m_dx;
    m_dy = _rhs.m_dy;

    return *this;
} // aVector2D<T>::operator=


/*******************************************************************************
* aVector2D<T>::operator==
*******************************************************************************/
template<class T>
bool aVector2D<T>::operator==(const aVector2D<T> &_rhs) const
{
    return isEqual(m_dx, _rhs.m_dx) &&
           isEqual(m_dy, _rhs.m_dy);
} // aVector2D<T>::operator==


/*******************************************************************************
* aVector2D<T>::operator!=
*******************************************************************************/
template<class T>
bool aVector2D<T>::operator!=(const aVector2D<T> &_rhs) const
{
    return isUnequal(m_dx, _rhs.m_dx) ||
           isUnequal(m_dy, _rhs.m_dy);
} // aVector2D<T>::operator!=


/*******************************************************************************
* aVector2D<T>::operator+
*******************************************************************************/
template<class T>
aVector2D<T> aVector2D<T>::operator+(const aVector2D<T>	&_rhs) const
{
    return	aVector2D<T>(m_dx + _rhs.m_dx,
                         m_dy + _rhs.m_dy);
} // aVector2D<T>::operator+


/*******************************************************************************
* aVector2D<T>::operator-
*******************************************************************************/
template<class T>
aVector2D<T> aVector2D<T>::operator-(const aVector2D<T>	&_rhs) const
{
    return aVector2D<T>(m_dx - _rhs.m_dx,
                        m_dy - _rhs.m_dy);
} // aVector2D<T>::operator-


/*******************************************************************************
* aVector2D<T>::operator*
*******************************************************************************/
template<class T>
aVector2D<T> aVector2D<T>::operator*(dbl _t) const
{
    return aVector2D<T>(static_cast<T> (m_dx * _t),
                        static_cast<T> (m_dy * _t));
} //  aVector2D<T>::operator*


/*******************************************************************************
* aVector2D<T>::operator/
*******************************************************************************/
template<class T>
aVector2D<T> aVector2D<T>::operator/(dbl _t) const
{
    return aVector2D<T>(static_cast<T> (m_dx / _t),
                        static_cast<T> (m_dy / _t));
} // aVector2D<T>::operator/


/*******************************************************************************
* aVector2D<T>::operator+=
*******************************************************************************/
template<class T>
aVector2D<T>& aVector2D<T>::operator+=(const aVector2D<T> &_rhs)
{
    m_dx += _rhs.m_dx;
    m_dy += _rhs.m_dy;

    return *this;
} // aVector2D<T>::operator+=


/*******************************************************************************
* aVector2D<T>::operator-=
*******************************************************************************/
template<class T>
aVector2D<T>& aVector2D<T>::operator-=(const aVector2D<T> &_rhs)
{
    m_dx -= _rhs.m_dx;
    m_dy -= _rhs.m_dy;

    return *this;
} // aVector2D<T>::operator-=


/*******************************************************************************
* aVector2D<T>::operator*=
*******************************************************************************/
template<class T>
aVector2D<T>& aVector2D<T>::operator*=(dbl	_t)
{
    m_dx = static_cast<T> (m_dx * _t);
    m_dy = static_cast<T> (m_dy * _t);

    return *this;
} // aVector2D<T>::operator*=


/*******************************************************************************
* aVector2D<T>::operator/=
*******************************************************************************/
template<class T>
aVector2D<T>& aVector2D<T>::operator/=(dbl _t)
{
    m_dx = static_cast<T> (m_dx / _t);
    m_dy = static_cast<T> (m_dy / _t);

    return *this;
} // aVector2D<T>::operator/=


/*******************************************************************************
* aVector2D<T>::normalize
*******************************************************************************/
template<class T>
void aVector2D<T>::normalize()
{
    *this /= norm();
} // aVector2D<T>::normalize


/*******************************************************************************
* aVector2D<T>::norm
*******************************************************************************/
template<class T>
dbl aVector2D<T>::norm() const
{
    return sqrt(m_dx * m_dx + m_dy * m_dy);
} // aVector2D<T>::norm


/*******************************************************************************
* aVector2D<T>::normSquare
*******************************************************************************/
template<class T>
dbl aVector2D<T>::normSquare() const
{
    return m_dx * m_dx + m_dy * m_dy;
} // aVector2D<T>::normSquare


/*******************************************************************************
* scalarProduct
*******************************************************************************/
template<class T>
dbl aVector2D<T>::scalarProduct(const aVector2D<T> &_rhs) const
{
    return (m_dx * _rhs.m_dx + m_dy * _rhs.m_dy);
} // scalarProduct


} // namespace aMath
} // namespace aFrame
