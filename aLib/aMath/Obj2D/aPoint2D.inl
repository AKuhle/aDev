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
namespace aLib {
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


template<class T>
aPoint2D<T>::~aPoint2D()
{
}


/*******************************************************************************
* aPoint2D<T>::Set
*******************************************************************************/
template<class T>
void aPoint2D<T>::Set(T _x,
                              T _y)
{
    m_x = _x;
    m_y = _y;
} // aPoint2D<T>::Set


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


/*******************************************************************************
* aPoint2D<T>::operator+
*******************************************************************************/
template<class T>
aPoint2D<T> aPoint2D<T>::operator+(const aPoint2D<T>	&_rhs) const
{
    return	aPoint2D<T>(m_x + _rhs.m_x,
                                m_y + _rhs.m_y);
} // aPoint2D<T>::operator+


/*******************************************************************************
* aPoint2D<T>::operator-
*******************************************************************************/
template<class T>
aPoint2D<T> aPoint2D<T>::operator-(const aPoint2D<T>	&_rhs) const
{
    return aPoint2D<T>(m_x - _rhs.m_x,
                               m_y - _rhs.m_y);
} // aPoint2D<T>::operator-


/*******************************************************************************
* aPoint2D<T>::operator*
*******************************************************************************/
template<class T>
aPoint2D<T> aPoint2D<T>::operator*(dbl	_t) const
{
    return aPoint2D<T>((T) (((dbl) m_x) * _t),
                               (T) (((dbl) m_y) * _t));
} //  aPoint2D<T>::operator*


/*******************************************************************************
* aPoint2D<T>::operator/
*******************************************************************************/
template<class T>
aPoint2D<T> aPoint2D<T>::operator/(dbl	_t) const
{
    return aPoint2D<T>((T) (((dbl) m_x) / _t),
                               (T) (((dbl) m_y) / _t));
} // aPoint2D<T>::operator/


/*******************************************************************************
* aPoint2D<T>::operator==
*******************************************************************************/
template<class T>
aPoint2D<T>& aPoint2D<T>::operator+=(const aPoint2D<T>	&_rhs)
{
    m_x += _rhs.m_x;
    m_y += _rhs.m_y;

    return *this;
} // aPoint2D<T>::operator==


/*******************************************************************************
* aPoint2D<T>::operator-=
*******************************************************************************/
template<class T>
aPoint2D<T>& aPoint2D<T>::operator-=(const aPoint2D<T>	&_rhs)
{
    m_x -= _rhs.m_x;
    m_y -= _rhs.m_y;

    return *this;
} // aPoint2D<T>::operator-=


/*******************************************************************************
* aPoint2D<T>::operator*=
*******************************************************************************/
template<class T>
aPoint2D<T>& aPoint2D<T>::operator*=(dbl	_t)
{
    m_x = (T) (((dbl) m_x) * _t);
    m_y = (T) (((dbl) m_y) * _t);

    return *this;
} // aPoint2D<T>::operator*=


/*******************************************************************************
* aPoint2D<T>::operator/=
*******************************************************************************/
template<class T>
aPoint2D<T>& aPoint2D<T>::operator/=(dbl _t)
{
    m_x = (T) (((dbl) m_x) / _t);
    m_y = (T) (((dbl) m_y) / _t);

    return *this;
} // aPoint2D<T>::operator/=


/*******************************************************************************
* aPoint2D<T>::Normalize
*******************************************************************************/
template<class T>
void aPoint2D<T>::Normalize()
{
    *this /= Norm();
} // aPoint2D<T>::Normalize


/*******************************************************************************
* aPoint2D<T>::Norm
*******************************************************************************/
template<class T>
dbl aPoint2D<T>::Norm() const
{
    return sqrt(((dbl) m_x) * m_x + ((dbl) m_y) * m_y);
} // aPoint2D<T>::Norm


/*******************************************************************************
* aPoint2D<T>::NormSquare
*******************************************************************************/
template<class T>
dbl aPoint2D<T>::NormSquare() const
{
    return ((dbl) m_x) * m_x + ((dbl) m_y) * m_y;
} // aPoint2D<T>::NormSquare


/*******************************************************************************
* aPoint2D<T>::Distance
*******************************************************************************/
template<class T>
dbl aPoint2D<T>::Distance(const aPoint2D<T>	&_rhs) const
{
    return ((*this) - _rhs).Norm();
} // aPoint2D<T>::Distance


/*******************************************************************************
* ScalarProduct
*******************************************************************************/
template<class T>
dbl aPoint2D<T>::ScalarProduct(const aPoint2D<T> &_rhs) const
{
    return (dbl) (m_x * _rhs.m_x + m_y * _rhs.m_y);
} // ScalarProduct


} // namespace aMath
} // namespace aLib
