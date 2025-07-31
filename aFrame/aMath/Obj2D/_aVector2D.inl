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
: m_x(_rhs.m_x),
  m_y(_rhs.m_y)
{
} // aVector2D<T>::aVector2D


template<class T>
/*******************************************************************************
* aVector2D<T>::aVector2D
*******************************************************************************/
aVector2D<T>::aVector2D(T _x,
                               T _y)
: m_x(_x),
  m_y(_y)
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
void aVector2D<T>::set(T _x,
                       T _y)
{
    m_x = _x;
    m_y = _y;
} // aVector2D<T>::set


/*******************************************************************************
* aVector2D<T>::operator=
*******************************************************************************/
template<class T>
aVector2D<T>& aVector2D<T>::operator=(const aVector2D<T> &_rhs)
{
    // avoid selfcopy
    m_x = _rhs.m_x;
    m_y = _rhs.m_y;

    return *this;
} // aVector2D<T>::operator=


/*******************************************************************************
* aVector2D<T>::operator==
*******************************************************************************/
template<class T>
bool aVector2D<T>::operator==(const aVector2D<T>	&_rhs) const
{
    return isEqual(m_x, _rhs.m_x) &&
           isEqual(m_y, _rhs.m_y);
} // aVector2D<T>::operator==


/*******************************************************************************
* aVector2D<T>::operator!=
*******************************************************************************/
template<class T>
bool aVector2D<T>::operator!=(const aVector2D<T>	&_rhs) const
{
    return isUnequal(m_x, _rhs.m_x) ||
           isUnequal(m_y, _rhs.m_y);
} // aVector2D<T>::operator!=


/*******************************************************************************
* aVector2D<T>::operator+
*******************************************************************************/
template<class T>
aVector2D<T> aVector2D<T>::operator+(const aVector2D<T>	&_rhs) const
{
    return	aVector2D<T>(m_x + _rhs.m_x,
                                m_y + _rhs.m_y);
} // aVector2D<T>::operator+


/*******************************************************************************
* aVector2D<T>::operator-
*******************************************************************************/
template<class T>
aVector2D<T> aVector2D<T>::operator-(const aVector2D<T>	&_rhs) const
{
    return aVector2D<T>(m_x - _rhs.m_x,
                               m_y - _rhs.m_y);
} // aVector2D<T>::operator-


/*******************************************************************************
* aVector2D<T>::operator*
*******************************************************************************/
template<class T>
aVector2D<T> aVector2D<T>::operator*(dbl	_t) const
{
    return aVector2D<T>((T) (((dbl) m_x) * _t),
                               (T) (((dbl) m_y) * _t));
} //  aVector2D<T>::operator*


/*******************************************************************************
* aVector2D<T>::operator/
*******************************************************************************/
template<class T>
aVector2D<T> aVector2D<T>::operator/(dbl	_t) const
{
    return aVector2D<T>((T) (((dbl) m_x) / _t),
                               (T) (((dbl) m_y) / _t));
} // aVector2D<T>::operator/


/*******************************************************************************
* aVector2D<T>::operator==
*******************************************************************************/
template<class T>
aVector2D<T>& aVector2D<T>::operator+=(const aVector2D<T>	&_rhs)
{
    m_x += _rhs.m_x;
    m_y += _rhs.m_y;

    return *this;
} // aVector2D<T>::operator==


/*******************************************************************************
* aVector2D<T>::operator-=
*******************************************************************************/
template<class T>
aVector2D<T>& aVector2D<T>::operator-=(const aVector2D<T>	&_rhs)
{
    m_x -= _rhs.m_x;
    m_y -= _rhs.m_y;

    return *this;
} // aVector2D<T>::operator-=


/*******************************************************************************
* aVector2D<T>::operator*=
*******************************************************************************/
template<class T>
aVector2D<T>& aVector2D<T>::operator*=(dbl	_t)
{
    m_x = (T) (((dbl) m_x) * _t);
    m_y = (T) (((dbl) m_y) * _t);

    return *this;
} // aVector2D<T>::operator*=


/*******************************************************************************
* aVector2D<T>::operator/=
*******************************************************************************/
template<class T>
aVector2D<T>& aVector2D<T>::operator/=(dbl _t)
{
    m_x = (T) (((dbl) m_x) / _t);
    m_y = (T) (((dbl) m_y) / _t);

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
    return sqrt(((dbl) m_x) * m_x + ((dbl) m_y) * m_y);
} // aVector2D<T>::norm


/*******************************************************************************
* aVector2D<T>::normSquare
*******************************************************************************/
template<class T>
dbl aVector2D<T>::normSquare() const
{
    return ((dbl) m_x) * m_x + ((dbl) m_y) * m_y;
} // aVector2D<T>::normSquare


/*******************************************************************************
* aVector2D<T>::distance
*******************************************************************************/
// template<class T>
// dbl aVector2D<T>::distance(const aVector2D<T>	&_rhs) const
// {
//     return ((*this) - _rhs).Norm();
// } // aVector2D<T>::distance


/*******************************************************************************
* scalarProduct
*******************************************************************************/
template<class T>
dbl aVector2D<T>::scalarProduct(const aVector2D<T> &_rhs) const
{
    return (dbl) (m_x * _rhs.m_x + m_y * _rhs.m_y);
} // scalarProduct


} // namespace aMath
} // namespace aFrame
