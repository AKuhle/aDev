/*******************************************************************************
* \file aRect2D.inl
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
* includes
*******************************************************************************/


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aMath {


/*******************************************************************************
* aRect2D<T>::aRect2D()
*******************************************************************************/
template<class T>
aRect2D<T>::aRect2D()
{
} // aRect2D<T>::aRect2D()


/*******************************************************************************
* aRect2D<T>::aRect2D()
*******************************************************************************/
template<class T>
aRect2D<T>::aRect2D(const aRect2D<T>	&_rhs)
: m_x(_rhs.m_x),
  m_y(_rhs.m_y),
  m_w(_rhs.m_w),
  m_h(_rhs.m_h)
{
} // aRect2D<T>::aRect2D()


/*******************************************************************************
* aRect2D<T>::aRect2D()
*******************************************************************************/
template<class T>
aRect2D<T>::aRect2D(const T		_x,
                           const T		_y,
                           const T		_w,
                           const T		_h)
: m_x(_x),
  m_y(_y),
  m_w(_w),
  m_h(_h)
{
} // aRect2D<T>::aRect2D()


/*******************************************************************************
* aRect2D<T>::~aRect2D()
*******************************************************************************/
template<class T>
aRect2D<T>::~aRect2D()
{
} // aRect2D<T>::~aRect2D()


/*******************************************************************************
* aRect2D<T>::set
*******************************************************************************/
template<class T>
void aRect2D<T>::set(const T	_x,
                            const T	_y,
                            const T	_w,
                            const T	_h)
{
    m_x = _x;
    m_y = _y;
    m_w = _w;
    m_h = _h;
} // aRect2D<T>::set


/*******************************************************************************
* aRect2D<T>::operator=
*******************************************************************************/
template<class T>
aRect2D<T>& aRect2D<T>::operator=(const aRect2D<T>	&_rhs)
{
    // avoid selfcopy
    if (this != &_rhs)
    {
        m_x = _rhs.m_x;
        m_y = _rhs.m_y;
        m_w = _rhs.m_w;
        m_h = _rhs.m_h;
    }

    return *this;
} // aRect2D<T>::operator=


/*******************************************************************************
* aRect2D<T>::operator==
*******************************************************************************/
template<class T>
bool aRect2D<T>::operator==(const aRect2D<T>	&_rhs) const
{
    return isEqual<T>(m_x, _rhs.m_x) &&
           isEqual<T>(m_y, _rhs.m_y) &&
           isEqual<T>(m_w, _rhs.m_w) &&
           isEqual<T>(m_h, _rhs.m_h);
} // aRect2D<T>::operator==


/*******************************************************************************
* aRect2D<T>::operator!=
*******************************************************************************/
template<class T>
bool aRect2D<T>::operator!=(const aRect2D<T>	&_rhs) const
{
    return isUnequal(m_x, _rhs.m_x) ||
           isUnequal(m_y, _rhs.m_y) ||
           isUnequal(m_w, _rhs.m_w) ||
           isUnequal(m_h, _rhs.m_h);
} // aRect2D<T>::operator!=


/*******************************************************************************
* aRect2D<T>::setEmpty
*******************************************************************************/
template<class T>
void aRect2D<T>::setEmpty()
{
    m_x = m_y = m_w = m_h = 0;
} // aRect2D<T>::setEmpty


/*******************************************************************************
* aRect2D<T>::isEmpty
*******************************************************************************/
template<class T>
bool aRect2D<T>::isEmpty() const
{
    return isZero(m_x) &&
           isZero(m_y) &&
           isZero(m_w) &&
           isZero(m_h);
} // aRect2D<T>::isEmpty


/*******************************************************************************
* aRect2D<T>::shrink
*******************************************************************************/
template<class T>
void aRect2D<T>::shrink(T _tValue)
{
    m_x += _tValue;
    m_y += _tValue;
    m_w -= 2 * _tValue;
    m_h -= 2 * _tValue;
} // aRect2D<T>::shrink


/*******************************************************************************
* aRect2D<T>::expand
*******************************************************************************/
template<class T>
void aRect2D<T>::expand(T _tValue)
{
    m_x -= _tValue;
    m_y -= _tValue;
    m_w += 2 * _tValue;
    m_h += 2 * _tValue;
} // aRect2D<T>::expand


/*******************************************************************************
* aRect2D<T>::pointInRect
*******************************************************************************/
template<class T>
bool aRect2D<T>::pointInRect(const aVector2D<T> &_v2d) const
{
    return pointInRect(_v2d.x(), _v2d.y());
} // aRect2D<T>::pointInRect


/*******************************************************************************
* aRect2D<T>::pointInRect
*******************************************************************************/
template<class T>
bool aRect2D<T>::pointInRect(const T _x,
                                    const T _y) const
{
    return (_x >= m_x) &&
           (_y >= m_y) &&
           (_x < m_x + m_w) &&
           (_y < m_y + m_h);
} // aRect2D<T>::pointInRect


} // namespace aMath
} // namespace aLib