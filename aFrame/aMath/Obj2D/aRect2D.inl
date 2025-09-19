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
#include "vectorHelper.h"

using namespace std;


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
aRect2D<T>::aRect2D(const aRect	&_rctTransform)
: m_x(_rctTransform.x()),
  m_w(_rctTransform.w()),
  m_h(_rctTransform.h()),
  m_rctTransform(_rctTransform),
  m_bTransform(true)
{
    m_y = win2MathY(_rctTransform.b());
} // aRect2D<T>::aRect2D()


/*******************************************************************************
* aRect2D<T>::aRect2D()
*******************************************************************************/
template<class T>
aRect2D<T>::aRect2D(T   _x,
                    T	_y,
                    T	_w,
                    T	_h)
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
void aRect2D<T>::set(T	_x,
                     T	_y,
                     T	_w,
                     T	_h)
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
    m_x = _rhs.m_x;
    m_y = _rhs.m_y;
    m_w = _rhs.m_w;
    m_h = _rhs.m_h;

    return *this;
} // aRect2D<T>::operator=


/*******************************************************************************
* aRect2D<T>::operator==
*******************************************************************************/
template<class T>
bool aRect2D<T>::operator==(const aRect2D<T>	&_rhs) const
{
    return isEqual(m_x, _rhs.m_x) &&
           isEqual(m_y, _rhs.m_y) &&
           isEqual(m_w, _rhs.m_w) &&
           isEqual(m_h, _rhs.m_h);
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
    return aDimension2D(m_w, m_h);
} // qRect2D<T, Tprec>::dimension()


/*******************************************************************************
* qRect2D<T, Tprec>::resize
*******************************************************************************/
template<class T>
void aRect2D<T>::resize(dbl _dFactor)
{
    m_w = static_cast<T> (_dFactor * m_w);
    m_h = static_cast<T> (_dFactor * m_h);
} // qRect2D<T, Tprec>::resize()


/*******************************************************************************
* qRect2D<T, Tprec>::centerPoint
*******************************************************************************/
template<class T>
aPoint2D<T> aRect2D<T>::centerPoint() const
{
    return aPoint2D<T> ((m_x + m_w) / 2,
                        (m_y + m_h) / 2);
} // qRect2D<T, Tprec>::GetCenterPoint()


/*******************************************************************************
* qRect2D<T, Tprec>::setCenterPoint
*******************************************************************************/
template<class T>
void aRect2D<T>::setCenterPoint(const T	_x,
                                const T	_y)
{
    m_x = _x - w / 2;
    m_y = _y - h / 2;
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
// template<class T>
// aRect2D<T> aRect2D<T>::intersect(const aRect2D<T> &_rhs) const
// {
//     aRect2D<T>  r2dIntersect;   // initial the rect is empty

//     T           tMinX   = aUtil::max<T>(m_x, _rhs.m_x);
//     T           tMinY   = aUtil::max<T>(m_y, _rhs.m_y);
//     T           tMaxX   = aUtil::min<T>(m_x + m_w, _rhs.m_x + _rhs.m_w);
//     T           tMaxY   = aUtil::min<T>(m_y + m_h, _rhs.m_y + _rhs.m_h);

//     if ((tMinX <= tMaxX) && tMinY <= tMaxY)
//     {
//         r2dIntersect.set(tMinX, tMinY, tMaxX-tMinX, tMaxY-tMinY);
//     }

//     return r2dIntersect;
// } // aRect2D<T, Tprec>::intersect


/*******************************************************************************
* aRect2D<T, Tprec>::intersect1
*******************************************************************************/
// template<class T>
// aRect2D<T> aRect2D<T>::intersect1(const aRect2D<T> &_rhs) const
// {
//     aRect2D<T>  r2dIntersect;   // initial the rect is empty

//     T           tMinX   = aUtil::max<T>(m_x, _rhs.m_x);
//     T           tMinY   = aUtil::max<T>(m_y, _rhs.m_y);
//     T           tMaxX   = aUtil::min<T>(m_x + m_w, _rhs.m_x + _rhs.m_w);
//     T           tMaxY   = aUtil::min<T>(m_y + m_h, _rhs.m_y + _rhs.m_h);

//     if ((tMinX <= tMaxX) && tMinY <= tMaxY)
//     {
//         r2dIntersect.set(tMinX, tMinY, tMaxX-tMinX+1, tMaxY-tMinY+1);
//     }

//     return r2dIntersect;
// } // aRect2D<T, Tprec>::intersect1


/*******************************************************************************
* aRect2D<T, Tprec>::intersect
*******************************************************************************/
template<class T>
void aRect2D<T>::intersect(aParametricLine2D<T> &_line,
                           vector<aPoint>       &_vIntersect) const
{
    dbl     tMin = __DBL_MAX__;
    dbl     tLine, tSegment;
    bool    bOnSeg;

    // top edge
    std::optional<aPoint2D<T>> p1 = _line.intersect(lt(), rt(), tLine, tSegment, bOnSeg);
    if (p1.has_value() && bOnSeg)
    {
        if (tLine < tMin)
        {
            push_front(_vIntersect, math2WinY(p1.value()));
        }
        else
        {
            _vIntersect.push_back(math2WinY(p1.value()));
        }
    }

    // bottom edge
    std::optional<aPoint2D<T>> p2 = _line.intersect(lb(), rb(), tLine, tSegment, bOnSeg);
    if (p2.has_value() && bOnSeg)
    {
        if (tLine < tMin)
        {
            push_front(_vIntersect, math2WinY(p2.value()));
            tMin = tLine;
        }
        else
        {
            _vIntersect.push_back(math2WinY(p2.value()));
        }
    }

    // left edge
    std::optional<aPoint2D<T>> p3 = _line.intersect(lt(), lb(), tLine, tSegment, bOnSeg);
    if (p3.has_value() && bOnSeg)
    {
        if (tLine < tMin)
        {
            push_front(_vIntersect, math2WinY(p3.value()));
            tMin = tLine;
        }
        else
        {
            _vIntersect.push_back(math2WinY(p3.value()));
        }
    }

    // right edge
    std::optional<aPoint2D<T>> p4 = _line.intersect(rt(), rb(), tLine, tSegment, bOnSeg);
    if (p4.has_value() && bOnSeg)
    {
        if (tLine < tMin)
        {
            push_front(_vIntersect, math2WinY(p4.value()));
            tMin = tLine;
        }
        else
        {
            _vIntersect.push_back(math2WinY(p4.value()));
        }
    }
} // aRect2D<T, Tprec>::intersect


/*******************************************************************************
* aRect2D<T>::pointInRect
*******************************************************************************/
template<class T>
bool aRect2D<T>::pointInRect(const aPoint2D<T> &_v2d) const
{
    return pointInRect(_v2d.x(), _v2d.y());
} // aRect2D<T>::pointInRect


/*******************************************************************************
* aRect2D<T>::pointInRect
*******************************************************************************/
template<class T>
bool aRect2D<T>::pointInRect(T _x,
                             T _y) const
{
    return (_x >= m_x) &&
           (_y >= m_y) &&
           (_x <= m_x + m_w) &&
           (_y <= m_y + m_h);
} // aRect2D<T>::pointInRect


/*******************************************************************************
* aRect2D<T>::win2MathY
*******************************************************************************/
template<class T>
T aRect2D<T>::win2MathY(T _tY) const
{
    if (m_bTransform)
    {
        return m_rctTransform.y() + m_rctTransform.b() - _tY;
    }
    else
    {
        cout << "error: no transform rect in win2MathY" << endl;
    }

    return _tY;
} // aRect2D<T>::win2MathY


/*******************************************************************************
* aRect2D<T>::math2WinY
*******************************************************************************/
template<class T>
T aRect2D<T>::math2WinY(T _tY) const
{
    if (m_bTransform)
    {
        return m_rctTransform.t() + m_rctTransform.b() - _tY;
    }
    else
    {
        cout << "error: no transform rect in math2WinY" << endl;
    }

    return _tY;
} // aRect2D<T>::math2WinY


/*******************************************************************************
* aRect2D<T>::win2MathY
*******************************************************************************/
template<class T>
aPoint2D<T> aRect2D<T>::win2MathY(const aPoint &_pnt) const
{
    if (m_bTransform)
    {
        return aPoint2D<T> (_pnt.x(), win2MathY(_pnt.y()));
    }
    else
    {
        cout << "error: no transform rect in win2MathY" << endl;
    }

    return aPoint2D<T> (_pnt.x(), _pnt.y());
} // aRect2D<T>::win2MathY


/*******************************************************************************
* aRect2D<T>::math2WinY
*******************************************************************************/
template<class T>
aPoint aRect2D<T>::math2WinY(const aPoint2D<T> &_p2d) const
{
    if (m_bTransform)
    {
        return aPoint(_p2d.x(), math2WinY(_p2d.y()));
    }
    else
    {
        cout << "error: no transform rect in math2WinY" << endl;
    }

    return aPoint(_p2d.x(), _p2d.y());
} // aRect2D<T>::math2WinY


} // namespace aMath
} // namespace aFrame
