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
namespace aFrame {
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
* aRect2D<T>::operator+
*******************************************************************************/
template<class T>
aRect2D<T> aRect2D<T>::operator+(const aMargin &_margin) const
{
    return	aRect2D<T> (m_x - _margin.l(),
                        m_y - _margin.t(),
                        m_w + _margin.w(),
                        m_h + _margin.h());
} // aRect2D<T>::operator+


/*******************************************************************************
* aRect2D<T>::operator-
*******************************************************************************/
template<class T>
aRect2D<T> aRect2D<T>::operator-(const aMargin &_margin) const
{
    return	aRect2D<T> (m_x + _margin.l(),
                        m_y + _margin.t(),
                        m_w - _margin.w(),
                        m_h - _margin.h());
} // aRect2D<T>::operator-


/*******************************************************************************
* aRect2D<T>::operator+=
*******************************************************************************/
template<class T>
aRect2D<T>& aRect2D<T>::operator+=(const aMargin &_margin)
{
    m_x -= _margin.l();
    m_y -= _margin.t();
    m_w += _margin.w();
    m_h += _margin.h();

    return *this;
} // aRect2D<T>::operator+=




/*******************************************************************************
* aRect2D<T>::operator-=
*******************************************************************************/
template<class T>
aRect2D<T>& aRect2D<T>::operator-=(const aMargin &_margin)
{
    m_x += _margin.l();
    m_y += _margin.t();
    m_w -= _margin.w();
    m_h -= _margin.h();

    return *this;
} // aRect2D<T>::operator-=


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
* qRect2D<T, Tprec>::dimension
*******************************************************************************/
template<class T>
aDimension2D<T> aRect2D<T>::dimension() const
{
    return aDimension2D<T> (m_w, m_h);
} // qRect2D<T, Tprec>::dimension()


/*******************************************************************************
* qRect2D<T, Tprec>::resize
*******************************************************************************/
template<class T>
void aRect2D<T>::resize(dbl _dFactor)
{
    m_w = (T) (_dFactor * m_w);
    m_h = (T) (_dFactor * m_h);
} // qRect2D<T, Tprec>::resize()


/*******************************************************************************
* qRect2D<T, Tprec>::centerPoint
*******************************************************************************/
template<class T>
aVector2D<T> aRect2D<T>::centerPoint() const
{
    return aVector2D<T> ((T) (((dbl) m_x) + ((dbl) m_w)/2),
                         (T) (((dbl) m_y) + ((dbl) m_h)/2));
} // qRect2D<T, Tprec>::GetCenterPoint()


/*******************************************************************************
* qRect2D<T, Tprec>::setCenterPoint
*******************************************************************************/
template<class T>
void aRect2D<T>::setCenterPoint(const T	_x,
                                const T	_y)
{
    m_x = _x - w/2;
    m_y = _y - h/2;
} // qRect2D<T, Tprec>::setCenterPoint


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
* aRect2D<T, Tprec>::intersect
*******************************************************************************/
template<class T>
aRect2D<T> aRect2D<T>::intersect(const aRect2D<T> &_rhs) const
{
    aRect2D<T>  r2dIntersect;   // initial the rect is empty

    T           tMinX   = aUtil::max<T>(m_x, _rhs.m_x);
    T           tMinY   = aUtil::max<T>(m_y, _rhs.m_y);
    T           tMaxX   = aUtil::min<T>(m_x + m_w, _rhs.m_x + _rhs.m_w);
    T           tMaxY   = aUtil::min<T>(m_y + m_h, _rhs.m_y + _rhs.m_h);

    if ((tMinX <= tMaxX) && tMinY <= tMaxY)
    {
        r2dIntersect.set(tMinX, tMinY, tMaxX-tMinX, tMaxY-tMinY);
    }

    return r2dIntersect;
} // aRect2D<T, Tprec>::intersect


/*******************************************************************************
* aRect2D<T, Tprec>::intersect1
*******************************************************************************/
template<class T>
aRect2D<T> aRect2D<T>::intersect1(const aRect2D<T> &_rhs) const
{
    aRect2D<T>  r2dIntersect;   // initial the rect is empty

    T           tMinX   = aUtil::max<T>(m_x, _rhs.m_x);
    T           tMinY   = aUtil::max<T>(m_y, _rhs.m_y);
    T           tMaxX   = aUtil::min<T>(m_x + m_w, _rhs.m_x + _rhs.m_w);
    T           tMaxY   = aUtil::min<T>(m_y + m_h, _rhs.m_y + _rhs.m_h);

    if ((tMinX <= tMaxX) && tMinY <= tMaxY)
    {
        r2dIntersect.set(tMinX, tMinY, tMaxX-tMinX+1, tMaxY-tMinY+1);
    }

    return r2dIntersect;
} // aRect2D<T, Tprec>::intersect1


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
} // namespace aFrame
