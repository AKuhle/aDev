/*******************************************************************************
* \file aRect.inl
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
#include "aRect.h"


using namespace std;


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aFrame {
namespace aUtil {


/*******************************************************************************
* aRect::aRect
*******************************************************************************/
aRect::aRect()
{
} // aRect::aRect


/*******************************************************************************
* aRect::aRect
*******************************************************************************/

aRect::aRect(const aRect	&_rhs)
: m_x(_rhs.m_x),
  m_y(_rhs.m_y),
  m_w(_rhs.m_w),
  m_h(_rhs.m_h)
{
} // aRect::aRect


/*******************************************************************************
* aRect::aRect
*******************************************************************************/
aRect::aRect(const s32    _x,
             const s32    _y,
             const s32    _w,
             const s32    _h)
: m_x(_x),
  m_y(_y),
  m_w(_w),
  m_h(_h)
{
} // aRect::aRect


/*******************************************************************************
* aRect::aRect
*******************************************************************************/
aRect::aRect(const aPoint  &_v2dOrigin,
             const s32     _w,
             const s32     _h)
: m_x(_v2dOrigin.x()),
  m_y(_v2dOrigin.y()),
  m_w(_w),
  m_h(_h)
{
} // aRect::aRect


/*******************************************************************************
* aRect::aRect
*******************************************************************************/
aRect::aRect(const aPoint  &_v2dOrigin,
             const aPoint  &_v2dOppositCorner)
: m_x(min(_v2dOrigin.x(), _v2dOppositCorner.x())),
  m_y(min(_v2dOrigin.y(), _v2dOppositCorner.y())),
  m_w(abs(_v2dOppositCorner.x() - _v2dOrigin.x()) + 1),
  m_h(abs(_v2dOppositCorner.y() - _v2dOrigin.y()) + 1)
{
} // aRect::aRect


/*******************************************************************************
* aRect::~aRect()
*******************************************************************************/
aRect::~aRect()
{
} // aRect::~aRect()


/*******************************************************************************
* aRect::set
*******************************************************************************/
void aRect::set(const s32   _x,
                const s32   _y,
                const s32	_w,
                const s32	_h)
{
    m_x = _x;
    m_y = _y;
    m_w = _w;
    m_h = _h;
} // aRect::set


/*******************************************************************************
* aRect::set
*******************************************************************************/
void aRect::set(const aPoint    &_v2dOrigin,
                const s32       _w,
                const s32       _h)
{
    m_x = _v2dOrigin.x();
    m_y = _v2dOrigin.y();
    m_w = _w;
    m_h = _h;
} // aRect::set


/*******************************************************************************
* aRect::operator=
*******************************************************************************/
aRect& aRect::operator=(const aRect	&_rhs)
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
} // aRect::operator=


/*******************************************************************************
* aRect::operator+
*******************************************************************************/
aRect aRect::operator+(const aMargin &_margin) const
{
    return	aRect (m_x - _margin.l(),
                   m_y - _margin.t(),
                   m_w + _margin.w(),
                   m_h + _margin.h());
} // aRect::operator+


/*******************************************************************************
* aRect::operator-
*******************************************************************************/
aRect aRect::operator-(const aMargin &_margin) const
{
    return	aRect (m_x + _margin.l(),
                   m_y + _margin.t(),
                   m_w - _margin.w(),
                   m_h - _margin.h());
} // aRect::operator-


/*******************************************************************************
* aRect::operator+=
*******************************************************************************/
aRect& aRect::operator+=(const aMargin &_margin)
{
    m_x -= _margin.l();
    m_y -= _margin.t();
    m_w += _margin.w();
    m_h += _margin.h();

    return *this;
} // aRect::operator+=


/*******************************************************************************
* aRect::operator-=
*******************************************************************************/
aRect& aRect::operator-=(const aMargin &_margin)
{
    m_x += _margin.l();
    m_y += _margin.t();
    m_w -= _margin.w();
    m_h -= _margin.h();

    return *this;
} // aRect::operator-=


/*******************************************************************************
* aRect::operator==
*******************************************************************************/
bool aRect::operator==(const aRect	&_rhs) const
{
    return isEqual(m_x, _rhs.m_x) &&
           isEqual(m_y, _rhs.m_y) &&
           isEqual(m_w, _rhs.m_w) &&
           isEqual(m_h, _rhs.m_h);
} // aRect::operator==


/*******************************************************************************
* aRect::operator!=
*******************************************************************************/
bool aRect::operator!=(const aRect	&_rhs) const
{
    return isUnequal(m_x, _rhs.m_x) ||
           isUnequal(m_y, _rhs.m_y) ||
           isUnequal(m_w, _rhs.m_w) ||
           isUnequal(m_h, _rhs.m_h);
} // aRect::operator!=


/*******************************************************************************
* aRect::dimension
*******************************************************************************/
aDimension aRect::dimension() const
{
    return aDimension(m_w, m_h);
} // aRect::dimension()


/*******************************************************************************
* aRect::resize
*******************************************************************************/
void aRect::resize(dbl _dFactor)
{
    m_w = static_cast<s32> (_dFactor * m_w);
    m_h = static_cast<s32> (_dFactor * m_h);
} // aRect::resize()


/*******************************************************************************
* aRect::centerPoint
*******************************************************************************/
aPoint aRect::centerPoint() const
{
    return aPoint ((m_x + m_w) / 2,
                   (m_y + m_h) / 2);
} // aRect::GetCenterPoint()


/*******************************************************************************
* aRect::setCenterPoint
*******************************************************************************/
void aRect::setCenterPoint(s32 _x,
                           s32 _y)
{
    m_x = _x - m_w / 2;
    m_y = _y - m_h / 2;
} // aRect::setCenterPoint


/*******************************************************************************
* aRect::setEmpty
*******************************************************************************/
void aRect::setEmpty()
{
    m_x = m_y = m_w = m_h = 0;
} // aRect::setEmpty


/*******************************************************************************
* aRect::isEmpty
*******************************************************************************/
bool aRect::isEmpty() const
{
    return isZero(m_x) &&
           isZero(m_y) &&
           isZero(m_w) &&
           isZero(m_h);
} // aRect::isEmpty


/*******************************************************************************
* aRect::shrink
*******************************************************************************/
void aRect::shrink(s32 _value)
{
    m_x += _value;
    m_y += _value;
    m_w -= 2 * _value;
    m_h -= 2 * _value;
} // aRect::shrink


/*******************************************************************************
* aRect::expand
*******************************************************************************/
void aRect::expand(s32 _value)
{
    m_x -= _value;
    m_y -= _value;
    m_w += 2 * _value;
    m_h += 2 * _value;
} // aRect::expand


/*******************************************************************************
* aRect<T, Tprec>::intersect
*******************************************************************************/
// aRect aRect::intersect(const aRect &_rhs) const
// {
//     aRect  r2dIntersect;   // initial the rect is empty

//     T           tMinX   = aUtil::max<T>(m_x, _rhs.m_x);
//     T           tMinY   = aUtil::max<T>(m_y, _rhs.m_y);
//     T           tMaxX   = aUtil::min<T>(m_x + m_w, _rhs.m_x + _rhs.m_w);
//     T           tMaxY   = aUtil::min<T>(m_y + m_h, _rhs.m_y + _rhs.m_h);

//     if ((tMinX <= tMaxX) && tMinY <= tMaxY)
//     {
//         r2dIntersect.set(tMinX, tMinY, tMaxX-tMinX, tMaxY-tMinY);
//     }

//     return r2dIntersect;
// } // aRect<T, Tprec>::intersect


/*******************************************************************************
* aRect<T, Tprec>::intersect1
*******************************************************************************/
// aRect aRect::intersect1(const aRect &_rhs) const
// {
//     aRect  r2dIntersect;   // initial the rect is empty

//     T           tMinX   = aUtil::max<T>(m_x, _rhs.m_x);
//     T           tMinY   = aUtil::max<T>(m_y, _rhs.m_y);
//     T           tMaxX   = aUtil::min<T>(m_x + m_w, _rhs.m_x + _rhs.m_w);
//     T           tMaxY   = aUtil::min<T>(m_y + m_h, _rhs.m_y + _rhs.m_h);

//     if ((tMinX <= tMaxX) && tMinY <= tMaxY)
//     {
//         r2dIntersect.set(tMinX, tMinY, tMaxX-tMinX+1, tMaxY-tMinY+1);
//     }

//     return r2dIntersect;
// } // aRect<T, Tprec>::intersect1


/*******************************************************************************
* aRect<T, Tprec>::intersect
*******************************************************************************/
// aVector<aPoint2D<T>> aRect::intersect(const aParametricLine2D<T> &_l) const
// {
//     aVector<aPoint2D<T>>    vFound;

//     aVector<std::optional<aPoint2D<T>>> vInter;
//     aVector<dbl>                        vT;
//     dbl                                 tMin = __DBL_MAX__;
//     dbl                                 tLine, tSegment;
//     bool                                bIntersectionPointOnSegment;

//     std::cout << "_l: os=" << _l.supportPoint() << ", dir=" << _l.direction() << endl;

//     // top edge
//     std::optional<aPoint2D<T>> p1 = _l.intersect(aPoint2D<s32> (l(), t()),
//                                                  aPoint2D<s32> (r1(), t()),
//                                                  tLine, tSegment,
//                                                  bIntersectionPointOnSegment);
//     if (p1.has_value() && bIntersectionPointOnSegment)
//     {
//         std::cout << "top edge: " << p1.value() << ", tLine=" << tLine << ", tSegment=" << tSegment << endl;
//         vInter.push_back(p1);
//         vT.push_back(tLine);
//     }

//     // bottom edge
//     std::optional<aPoint2D<T>> p2 = _l.intersect(aPoint2D<s32> (l(), b1()),
//                                                  aPoint2D<s32> (r1(), b1()),
//                                                  tLine, tSegment,
//                                                  bIntersectionPointOnSegment);
//     if (p2.has_value() && bIntersectionPointOnSegment)
//     {
//         std::cout << "bottom edge: " << p2.value() << ", tLine=" << tLine << ", tSegment=" << tSegment << endl;
//         vInter.push_back(p2);
//         vT.push_back(tLine);
//     }

//     // left edge
//     std::optional<aPoint2D<T>> p3 = _l.intersect(aPoint2D<s32> (l(), t()),
//                                                  aPoint2D<s32> (l(), b1()),
//                                                  tLine, tSegment,
//                                                  bIntersectionPointOnSegment);
//     if (p3.has_value() && bIntersectionPointOnSegment)
//     {
//         std::cout << "left edge: " << p3.value() << ", tLine=" << tLine << ", tSegment=" << tSegment << endl;
//         vInter.push_back(p3);
//         vT.push_back(tLine);
//     }

//     // right edge
//     std::optional<aPoint2D<T>> p4 = _l.intersect(aPoint2D<s32> (r1(), t()),
//                                                  aPoint2D<s32> (r1(), b1()),
//                                                  tLine, tSegment,
//                                                  bIntersectionPointOnSegment);
//     if (p4.has_value() && bIntersectionPointOnSegment)
//     {
//         std::cout << "right edge: " << p4.value() << ", tLine=" << tLine << ", tSegment=" << tSegment << endl;
//         vInter.push_back(p4);
//         vT.push_back(tLine);
//     }

//     for (s32 i = vInter.size()-1; i >= 0; i--)
//     {
//         if (vT.at(i) < tMin)
//         {
//             vFound.push_front(vInter.at(i).value());
//             tMin = vT.at(i);
//         }
//         else
//         {
//             vFound.push_back(vInter.at(i).value());
//         }
//     }

//     return vFound;
// } // aRect<T, Tprec>::intersect


/*******************************************************************************
* aRect::pointInRect
*******************************************************************************/
bool aRect::pointInRect(const aPoint &_p2d) const
{
    return pointInRect(_p2d.x(), _p2d.y());
} // aRect::pointInRect


/*******************************************************************************
* aRect::pointInRect
*******************************************************************************/
bool aRect::pointInRect(s32 _x,
                        s32 _y) const
{
    return _x >= l() && _x <= r() &&
           _y >= t() && _y <= b();
} // aRect::pointInRect


} // namespace aUtil
} // namespace aFrame
