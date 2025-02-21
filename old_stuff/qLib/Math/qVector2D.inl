/*******************************************************************************
* \file qVector2D.inl
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
namespace qLib {
namespace Math {


/*******************************************************************************
* qVector2D<T, Tprec>::qVector2D
*******************************************************************************/
template<class T, class Tprec>
qVector2D<T, Tprec>::qVector2D()
{
} // qVector2D<T, Tprec>::qVector2D


/*******************************************************************************
* qVector2D<T, Tprec>::qVector2D
*******************************************************************************/
template<class T, class Tprec>
qVector2D<T, Tprec>::qVector2D(const qVector2D<T, Tprec> &_rhs)
: m_x(_rhs.m_x),
  m_y(_rhs.m_y)
{
} // qVector2D<T, Tprec>::qVector2D


template<class T, class Tprec>
/*******************************************************************************
* qVector2D<T, Tprec>::qVector2D
*******************************************************************************/
qVector2D<T, Tprec>::qVector2D(T _x,
                               T _y)
: m_x(_x),
  m_y(_y)
{
} // qVector2D<T, Tprec>::qVector2D


template<class T, class Tprec>
qVector2D<T, Tprec>::~qVector2D()
{
}


/*******************************************************************************
* qVector2D<T, Tprec>::Set
*******************************************************************************/
template<class T, class Tprec>
void qVector2D<T, Tprec>::Set(T _x,
                              T _y)
{
    m_x = _x;
    m_y = _y;
} // qVector2D<T, Tprec>::Set


/*******************************************************************************
* qVector2D<T, Tprec>::operator=
*******************************************************************************/
template<class T, class Tprec>
qVector2D<T, Tprec>& qVector2D<T, Tprec>::operator=(const qVector2D<T, Tprec> &_rhs)
{
    // avoid selfcopy
    m_x = _rhs.m_x;
    m_y = _rhs.m_y;

    return *this;
} // qVector2D<T, Tprec>::operator=


/*******************************************************************************
* qVector2D<T, Tprec>::operator==
*******************************************************************************/
template<class T, class Tprec>
bool qVector2D<T, Tprec>::operator==(const qVector2D<T, Tprec>	&_rhs) const
{
    return isEqual(m_x, _rhs.m_x) &&
           isEqual(m_y, _rhs.m_y);
} // qVector2D<T, Tprec>::operator==


/*******************************************************************************
* qVector2D<T, Tprec>::operator!=
*******************************************************************************/
template<class T, class Tprec>
bool qVector2D<T, Tprec>::operator!=(const qVector2D<T, Tprec>	&_rhs) const
{
    return IsUnequal(m_x, _rhs.m_x) ||
           IsUnequal(m_y, _rhs.m_y);
} // qVector2D<T, Tprec>::operator!=


/*******************************************************************************
* qVector2D<T, Tprec>::operator+
*******************************************************************************/
template<class T, class Tprec>
qVector2D<T, Tprec> qVector2D<T, Tprec>::operator+(const qVector2D<T, Tprec>	&_rhs) const
{
    return	qVector2D<T, Tprec>(m_x + _rhs.m_x,
                                m_y + _rhs.m_y);
} // qVector2D<T, Tprec>::operator+


/*******************************************************************************
* qVector2D<T, Tprec>::operator-
*******************************************************************************/
template<class T, class Tprec>
qVector2D<T, Tprec> qVector2D<T, Tprec>::operator-(const qVector2D<T, Tprec>	&_rhs) const
{
    return qVector2D<T, Tprec>(m_x - _rhs.m_x,
                               m_y - _rhs.m_y);
} // qVector2D<T, Tprec>::operator-


/*******************************************************************************
* qVector2D<T, Tprec>::operator*
*******************************************************************************/
template<class T, class Tprec>
qVector2D<T, Tprec> qVector2D<T, Tprec>::operator*(const Tprec	_t) const
{
    return qVector2D<T, Tprec>((T) (((Tprec) m_x) * _t),
                               (T) (((Tprec) m_y) * _t));
} //  qVector2D<T, Tprec>::operator*


/*******************************************************************************
* qVector2D<T, Tprec>::operator/
*******************************************************************************/
template<class T, class Tprec>
qVector2D<T, Tprec> qVector2D<T, Tprec>::operator/(const Tprec	_t) const
{
    return qVector2D<T, Tprec>((T) (((Tprec) m_x) / _t),
                               (T) (((Tprec) m_y) / _t));
} // qVector2D<T, Tprec>::operator/


/*******************************************************************************
* qVector2D<T, Tprec>::operator==
*******************************************************************************/
template<class T, class Tprec>
qVector2D<T, Tprec>& qVector2D<T, Tprec>::operator+=(const qVector2D<T, Tprec>	&_rhs)
{
    m_x += _rhs.m_x;
    m_y += _rhs.m_y;

    return *this;
} // qVector2D<T, Tprec>::operator==


/*******************************************************************************
* qVector2D<T, Tprec>::operator-=
*******************************************************************************/
template<class T, class Tprec>
qVector2D<T, Tprec>& qVector2D<T, Tprec>::operator-=(const qVector2D<T, Tprec>	&_rhs)
{
    m_x -= _rhs.m_x;
    m_y -= _rhs.m_y;

    return *this;
} // qVector2D<T, Tprec>::operator-=


/*******************************************************************************
* qVector2D<T, Tprec>::operator*=
*******************************************************************************/
template<class T, class Tprec>
qVector2D<T, Tprec>& qVector2D<T, Tprec>::operator*=(const Tprec	_t)
{
    m_x = (T) (((Tprec) m_x) * _t);
    m_y = (T) (((Tprec) m_y) * _t);

    return *this;
} // qVector2D<T, Tprec>::operator*=


/*******************************************************************************
* qVector2D<T, Tprec>::operator/=
*******************************************************************************/
template<class T, class Tprec>
qVector2D<T, Tprec>& qVector2D<T, Tprec>::operator/=(const Tprec _t)
{
    m_x = (T) (((Tprec) m_x) / _t);
    m_y = (T) (((Tprec) m_y) / _t);

    return *this;
} // qVector2D<T, Tprec>::operator/=


/*******************************************************************************
* qVector2D<T, Tprec>::Normalize
*******************************************************************************/
template<class T, class Tprec>
void qVector2D<T, Tprec>::Normalize()
{
    *this /= Norm();
} // qVector2D<T, Tprec>::Normalize


/*******************************************************************************
* qVector2D<T, Tprec>::Norm
*******************************************************************************/
template<class T, class Tprec>
Tprec qVector2D<T, Tprec>::Norm() const
{
    return sqrt(((Tprec) m_x) * m_x + ((Tprec) m_y) * m_y);
} // qVector2D<T, Tprec>::Norm


/*******************************************************************************
* qVector2D<T, Tprec>::NormSquare
*******************************************************************************/
template<class T, class Tprec>
Tprec qVector2D<T, Tprec>::NormSquare() const
{
    return ((Tprec) m_x) * m_x + ((Tprec) m_y) * m_y;
} // qVector2D<T, Tprec>::NormSquare


/*******************************************************************************
* qVector2D<T, Tprec>::Distance
*******************************************************************************/
template<class T, class Tprec>
Tprec qVector2D<T, Tprec>::Distance(const qVector2D<T, Tprec>	&_rhs) const
{
    return ((*this) - _rhs).Norm();
} // qVector2D<T, Tprec>::Distance


/*******************************************************************************
* ScalarProduct
*******************************************************************************/
template<class T, class Tprec>
dbl qVector2D<T, Tprec>::ScalarProduct(const qVector2D<T, Tprec> &_rhs) const
{
    return (dbl) (m_x * _rhs.m_x + m_y * _rhs.m_y);
} // ScalarProduct


} // namespace Math
} // namespace qLib
