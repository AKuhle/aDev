/*******************************************************************************
* \file aParametricLine2D.h
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
#pragma once


/*******************************************************************************
* includes
*******************************************************************************/
#include "aFrame_def.h"
#include "aHelper.h"

#include "aPoint2D.h"
#include "aVector2D.h"

using namespace aFrame::aUtil;


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aFrame {
namespace aMath {


/*******************************************************************************
* class aParametricLine2D
*******************************************************************************/
template<class T>
class aParametricLine2D : public aMathObj2D
{
    private:
        aPoint2D<T>     m_p2dSupport;   // support point (x₀, y₀)
        aVector2D<dbl>  m_v2dNormDir;   // normalized direction (a, b)

    public:
        aParametricLine2D();

        aParametricLine2D(const aParametricLine2D<T>& _rhs);

        aParametricLine2D(const aPoint2D<T>     &_p1,
                          const aPoint2D<T>     &_p2);

        aParametricLine2D(const aPoint2D<T>     &_p,
                          dbl                   _dAngle_rad);

        aParametricLine2D(T     _x1,
                          T     _y1,
                          T     _x2,
                          T     _y2);

        virtual ~aParametricLine2D();

        aParametricLine2D<T>&           operator=(const aParametricLine2D<T> &_rhs);

        bool                            operator==(const aParametricLine2D<T> &_rhs) const;
        bool                            operator!=(const aParametricLine2D<T> &_rhs) const;

        aPoint2D<T>                     supportPoint() const    { return m_p2dSupport; }
        aVector2D<dbl>                  direction() const       { return m_v2dNormDir;}

        bool                            isHorizontal() const;
        bool                            isVertical() const;

        /**
         * @brief find the intersection of this line with line segment
         *
         * @param _pStart startpoint of the line segment
         * @param _pEnd endpoint of the line segment
         * @param _tLine _t for the intersection point on this line
         * @param _tSegment _t for the intersection point on the segment
         * @param _bIntersectionPointOnSegment true => intersection point is within the segment
         *
         * @return intersection point or empty object
         */
        std::optional<aPoint2D<T>>      intersect(const aPoint2D<T>  &_pSegmentStart,
                                                  const aPoint2D<T>  &_pSegmentEnd,
                                                  dbl                &_tLine,
                                                  dbl                &_tSegment,
                                                  bool               &_bIntersectionPointOnSegment) const;

        friend std::ostream& operator<<(std::ostream&               _os,
                                        const aParametricLine2D<T>  &_l2d)
        {
            _os << "l = " << _l2d.m_p2dSupport <<
                   " + r" << _l2d.m_v2dNormDir;
              return _os;
        } // operator<<
}; // class aParametricLine2D


} // namespace aMath
} // namespace aFrame

#include "aParametricLine2D.inl"
