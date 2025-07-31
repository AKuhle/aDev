/*******************************************************************************
* \file aParametricLine2D.inl
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
#include "aUtil_def.h"
#include "aFrame_def.h"

using namespace aFrame::aUtil;


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aFrame {
namespace aMath {


/*******************************************************************************
* aParametricLine2D<T>::aParametricLine2D
*******************************************************************************/
template<class T>
aParametricLine2D<T>::aParametricLine2D()
{
} // aParametricLine2D<T>::aParametricLine2D


/*******************************************************************************
* aParametricLine2D<T>::aParametricLine2D
*******************************************************************************/
template<class T>
aParametricLine2D<T>::aParametricLine2D(const aParametricLine2D<T> &_rhs)
: m_p2dSupport(_rhs.m_p2dSupport),
  m_v2dNormDir(_rhs.m_v2dNormDir)
{
} // aParametricLine2D<T>::aParametricLine2D


template<class T>
/*******************************************************************************
* aParametricLine2D<T>::aParametricLine2D
*******************************************************************************/
aParametricLine2D<T>::aParametricLine2D(const aPoint2D<T>     &_p1,
                                        const aPoint2D<T>     &_p2)
{
    // support point = _p1
    m_p2dSupport = _p1;

    // calclulate the normalized direction vector
    m_v2dNormDir.set(_p2.x() - _p1.x(),
                     _p2.y() - _p1.y());
    m_v2dNormDir.normalize();
} // aParametricLine2D<T>::aParametricLine2D


template<class T>
/*******************************************************************************
* aParametricLine2D<T>::aParametricLine2D
*******************************************************************************/
aParametricLine2D<T>::aParametricLine2D(const aPoint2D<T> &_p,
                                        dbl               _dAngle_rad)
{
    // support point = _p1
    m_p2dSupport = _p;

    // calclulate the normalized direction vector
    // y-value is negativ because the win origin is top left
    m_v2dNormDir.set(std::cos(_dAngle_rad),
                     std::sin(_dAngle_rad));
} // aParametricLine2D<T>::aParametricLine2D


template<class T>
/*******************************************************************************
* aParametricLine2D<T>::aParametricLine2D
*******************************************************************************/
aParametricLine2D<T>::aParametricLine2D(T     _x1,
                                        T     _y1,
                                        T     _x2,
                                        T     _y2)
{
    // support point = _p1
    m_p2dSupport.set(_x1, _y1);

    // calclulate the normalized direction vector
    m_v2dNormDir.set(_x2 - _x1,
                     _y2 - _y1);
    m_v2dNormDir.normalize();
} // aParametricLine2D<T>::aParametricLine2D


/*******************************************************************************
* aParametricLine2D<T>::~aParametricLine2D
*******************************************************************************/
template<class T>
aParametricLine2D<T>::~aParametricLine2D()
{
} // aParametricLine2D<T>::~aParametricLine2D


/*******************************************************************************
* aParametricLine2D<T>::operator=
*******************************************************************************/
template<class T>
aParametricLine2D<T>& aParametricLine2D<T>::operator=(const aParametricLine2D<T> &_rhs)
{
    // avoid selfcopy
    m_p2dSupport = _rhs.m_p2dSupport;
    m_v2dNormDir = _rhs.m_v2dNormDir;

    return *this;
} // aParametricLine2D<T>::operator=


/*******************************************************************************
* aParametricLine2D<T>::operator==
*******************************************************************************/
template<class T>
bool aParametricLine2D<T>::operator==(const aParametricLine2D<T>	&_rhs) const
{
    return m_p2dSupport == _rhs.m_p2dSupport &&
           m_v2dNormDir == _rhs.m_v2dNormDir;
} // aParametricLine2D<T>::operator==


/*******************************************************************************
* aParametricLine2D<T>::operator!=
*******************************************************************************/
template<class T>
bool aParametricLine2D<T>::operator!=(const aParametricLine2D<T>	&_rhs) const
{
    return m_p2dSupport != _rhs.m_p2dSupport ||
           m_v2dNormDir != _rhs.m_v2dNormDir;
} // aParametricLine2D<T>::operator!=


/*******************************************************************************
* aParametricLine2D<T>::isHorizontal
*******************************************************************************/
template<class T>
bool aParametricLine2D<T>::isHorizontal() const
{
    return !isZero(m_v2dNormDir.x()) && isZero(m_v2dNormDir.y());
} // aParametricLine2D<T>::isHorizontal


/*******************************************************************************
* aParametricLine2D<T>::isVertical
*******************************************************************************/
template<class T>
bool aParametricLine2D<T>::isVertical() const
{
    return isZero(m_v2dNormDir.x()) && !isZero(m_v2dNormDir.y());
} // aParametricLine2D<T>::isVertical


/*******************************************************************************
* aParametricLine2D<T>::intersect
*******************************************************************************/
template<class T>
std::optional<aPoint2D<T>> aParametricLine2D<T>::intersect(const aPoint2D<T>  &_pSegmentStart,
                                                           const aPoint2D<T>  &_pSegmentEnd,
                                                           dbl                &_tLine,
                                                           dbl                &_tSegment,
                                                           bool               &_bIntersectionPointOnSegment) const
{
    // for better readability
    double x1 = _pSegmentStart.x();
    double y1 = _pSegmentStart.y();
    double dx1 = _pSegmentEnd.x() - _pSegmentStart.x();
    double dy1 = _pSegmentEnd.y() - _pSegmentStart.y();

    double x2 = m_p2dSupport.x();
    double y2 = m_p2dSupport.y();
    double dx2 = m_v2dNormDir.x();
    double dy2 = m_v2dNormDir.y();

    // Berechne Determinante (Nenner)
    double denominator = dx1 * dy2 - dy1 * dx2;

    // check if parallel
    if (isZero(denominator))
    {
        //  lines are parallel, 0 or infinite intersetions
        _tLine = 0.0;
        _tSegment = 0.0;
        _bIntersectionPointOnSegment = false;

        return std::nullopt;
    }

    // Berechne die Parameter t für beide Linien
    double dx = x1 - x2;
    double dy = y1 - y2;

    _tSegment = (dx * dy2 - dy * dx2) / denominator;
    _tLine = (dx * dy1 - dy * dx1) / denominator;

    // check if intersection point is on segment
    _bIntersectionPointOnSegment = (_tSegment >= 0.0) && (_tSegment <= 1.0);

    // calculate and return intersection
    return aPoint2D<T>(static_cast<T>(x1 + _tSegment * dx1),
                       static_cast<T>(y1 + _tSegment * dy1));
} // aParametricLine2D<T>::intersect



} // namespace aMath
} // namespace aFrame
