/*******************************************************************************
* \file qDimension2D.inl
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
* qDimension2D<T>::qDimension2D()
*******************************************************************************/
template<class T>
qDimension2D<T>::qDimension2D()
{
}


/*******************************************************************************
* qDimension2D<T>::qDimension2D()
*******************************************************************************/
template<class T>
qDimension2D<T>::qDimension2D(const qDimension2D<T>	&_rhs)
: m_w(_rhs.m_w),
  m_h(_rhs.m_h)
{
    // don't call operator= to avoid multiple assignments
}


/*******************************************************************************
* qDimension2D<T>::qDimension2D()
*******************************************************************************/
template<class T>
qDimension2D<T>::qDimension2D(const T   _w,
                              const T	_h)
: m_w(_w),
  m_h(_h)
{
}


/*******************************************************************************
* qDimension2D<T>::~qDimension2D()
*******************************************************************************/
template<class T>
qDimension2D<T>::~qDimension2D()
{
}


/*******************************************************************************
* qDimension2D<T>::operator=
*******************************************************************************/
template<class T>
qDimension2D<T>& qDimension2D<T>::operator=(const qDimension2D<T>	&_rhs)
{
    // avoid selfcopy
    if (this != &_rhs)
    {
        m_w = _rhs.m_w;
        m_h = _rhs.m_h;
    }

    return *this;
} // qDimension2D<T>::operator=


/*******************************************************************************
* qDimension2D<T>::operator==
*******************************************************************************/
template<class T>
bool qDimension2D<T>::operator==(const qDimension2D<T>	&_rhs) const
{
    return isEqual<T>(m_w, _rhs.m_w) &&
           isEqual<T>(m_h, _rhs.m_h);
} // qDimension2D<T>::operator==


/*******************************************************************************
* qDimension2D<T>::operator!=
*******************************************************************************/
template<class T>
bool qDimension2D<T>::operator!=(const qDimension2D<T>	&_rhs) const
{
    return isUnequal<T>(m_w, _rhs.m_w) ||
           isUnequal<T>(m_h, _rhs.m_h);
} // qDimension2D<T>::operator!=


/*******************************************************************************
* qDimension2D<T>::operator+=
*******************************************************************************/
template<class T>
qDimension2D<T>& qDimension2D<T>::operator+=(const qDimension2D<T> &_rhs)
{
    m_w += _rhs.m_w;
    m_h += _rhs.m_h;

    return *this;
} // qDimension2D<T>::operator+=


/*******************************************************************************
* qDimension2D<T>::operator*=
*******************************************************************************/
template<class T>
qDimension2D<T>& qDimension2D<T>::operator*=(double _dMuliplicator)
{
    m_w *= _dMuliplicator;
    m_h *= _dMuliplicator;

    return *this;
} // qDimension2D<T>::operator*=


/*******************************************************************************
* qDimension2D<T>::operator*
*******************************************************************************/
template<class T>
qDimension2D<T> qDimension2D<T>::operator*(double	_dMuliplicator) const
{
    return qDimension2D<T> ((T) (((dbl) m_w) * _dMuliplicator),
                            (T) (((dbl) m_h) * _dMuliplicator));
} // qDimension2D<T>::operator*


/*******************************************************************************
* qDimension2D<T>::w
*******************************************************************************/
template<class T>
T qDimension2D<T>::w() const
{
    return m_w;
} // qDimension2D<T>::w


/*******************************************************************************
* qDimension2D<T>::h
*******************************************************************************/
template<class T>
T qDimension2D<T>::h() const
{
    return m_h;
} // qDimension2D<T>::h


/*******************************************************************************
* qDimension2D<T>::w
*******************************************************************************/
template<class T>
T& qDimension2D<T>::w()
{
    return m_w;
} // qDimension2D<T>::w


/*******************************************************************************
* qDimension2D<T>::h
*******************************************************************************/
template<class T>
T& qDimension2D<T>::h()
{
    return m_h;
} // qDimension2D<T>::h


/*******************************************************************************
* qDimension2D<T>::set
*******************************************************************************/
template<class T>
void qDimension2D<T>::set(const T		_w,
                          const T		_h)
{
    m_w = _w;
    m_h = _h;
} // qDimension2D<T>::set


/*******************************************************************************
* qDimension2D<T>::setEmpty
*******************************************************************************/
template<class T>
void qDimension2D<T>::setEmpty()
{
    m_w = m_h = 0;
} // qDimension2D<T>::setEmpty


/*******************************************************************************
* qDimension2D<T>::isEmpty
*******************************************************************************/
template<class T>
bool qDimension2D<T>::isEmpty() const
{
    return isZero<T>(m_w) && isZero<T>(m_h);
} // qDimension2D<T>::isEmpty


} // namespace Math
} // namespace qLib
