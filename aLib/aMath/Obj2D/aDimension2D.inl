/*******************************************************************************
* \file aDimension2D.inl
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
* aDimension2D<T>::aDimension2D()
*******************************************************************************/
template<class T>
aDimension2D<T>::aDimension2D()
{
}


/*******************************************************************************
* aDimension2D<T>::aDimension2D()
*******************************************************************************/
template<class T>
aDimension2D<T>::aDimension2D(const aDimension2D<T>	&_rhs)
: m_w(_rhs.m_w),
  m_h(_rhs.m_h)
{
    // don't call operator= to avoid multiple assignments
}


/*******************************************************************************
* aDimension2D<T>::aDimension2D()
*******************************************************************************/
template<class T>
aDimension2D<T>::aDimension2D(const T   _w,
                              const T	_h)
: m_w(_w),
  m_h(_h)
{
}


/*******************************************************************************
* aDimension2D<T>::~aDimension2D()
*******************************************************************************/
template<class T>
aDimension2D<T>::~aDimension2D()
{
}


/*******************************************************************************
* aDimension2D<T>::operator=
*******************************************************************************/
template<class T>
aDimension2D<T>& aDimension2D<T>::operator=(const aDimension2D<T>	&_rhs)
{
    // avoid selfcopy
    if (this != &_rhs)
    {
        m_w = _rhs.m_w;
        m_h = _rhs.m_h;
    }

    return *this;
} // aDimension2D<T>::operator=


/*******************************************************************************
* aDimension2D<T>::operator==
*******************************************************************************/
template<class T>
bool aDimension2D<T>::operator==(const aDimension2D<T>	&_rhs) const
{
    return isEqual<T>(m_w, _rhs.m_w) &&
           isEqual<T>(m_h, _rhs.m_h);
} // aDimension2D<T>::operator==


/*******************************************************************************
* aDimension2D<T>::operator!=
*******************************************************************************/
template<class T>
bool aDimension2D<T>::operator!=(const aDimension2D<T>	&_rhs) const
{
    return isUnequal<T>(m_w, _rhs.m_w) ||
           isUnequal<T>(m_h, _rhs.m_h);
} // aDimension2D<T>::operator!=


/*******************************************************************************
* aDimension2D<T>::operator+=
*******************************************************************************/
template<class T>
aDimension2D<T>& aDimension2D<T>::operator+=(const aDimension2D<T> &_rhs)
{
    m_w += _rhs.m_w;
    m_h += _rhs.m_h;

    return *this;
} // aDimension2D<T>::operator+=


/*******************************************************************************
* aDimension2D<T>::operator*=
*******************************************************************************/
template<class T>
aDimension2D<T>& aDimension2D<T>::operator*=(dbl _dMuliplicator)
{
    m_w *= _dMuliplicator;
    m_h *= _dMuliplicator;

    return *this;
} // aDimension2D<T>::operator*=


/*******************************************************************************
* aDimension2D<T>::operator*
*******************************************************************************/
template<class T>
aDimension2D<T> aDimension2D<T>::operator*(dbl	_dMuliplicator) const
{
    return aDimension2D<T> ((T) (((dbl) m_w) * _dMuliplicator),
                            (T) (((dbl) m_h) * _dMuliplicator));
} // aDimension2D<T>::operator*


/*******************************************************************************
* aDimension2D<T>::w
*******************************************************************************/
template<class T>
T aDimension2D<T>::w() const
{
    return m_w;
} // aDimension2D<T>::w


/*******************************************************************************
* aDimension2D<T>::h
*******************************************************************************/
template<class T>
T aDimension2D<T>::h() const
{
    return m_h;
} // aDimension2D<T>::h


/*******************************************************************************
* aDimension2D<T>::w
*******************************************************************************/
template<class T>
T& aDimension2D<T>::w()
{
    return m_w;
} // aDimension2D<T>::w


/*******************************************************************************
* aDimension2D<T>::h
*******************************************************************************/
template<class T>
T& aDimension2D<T>::h()
{
    return m_h;
} // aDimension2D<T>::h


/*******************************************************************************
* aDimension2D<T>::set
*******************************************************************************/
template<class T>
void aDimension2D<T>::set(const T		_w,
                          const T		_h)
{
    m_w = _w;
    m_h = _h;
} // aDimension2D<T>::set


/*******************************************************************************
* aDimension2D<T>::setEmpty
*******************************************************************************/
template<class T>
void aDimension2D<T>::setEmpty()
{
    m_w = m_h = 0;
} // aDimension2D<T>::setEmpty


/*******************************************************************************
* aDimension2D<T>::isEmpty
*******************************************************************************/
template<class T>
bool aDimension2D<T>::isEmpty() const
{
    return isZero<T>(m_w) && isZero<T>(m_h);
} // aDimension2D<T>::isEmpty


/*******************************************************************************
* aDimension2D<T>::max
*******************************************************************************/
template<class T>
aDimension2D<T> aDimension2D<T>::max(const aDimension2D<T> &_rhs) const
{
    return aDimension2D<T> (aUtil::max<T> (m_w, _rhs.m_w),
                            aUtil::max<T> (m_h, _rhs.m_h));
} // aDimension2D<T>::max


} // namespace aMath
} // namespace aLib
