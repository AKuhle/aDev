/*******************************************************************************
* \file aRect.h
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
#include "aMargin.h"

#include "aMathObj2D.h"
#include "aDimension.h"
#include "aPoint.h"

using namespace aFrame;


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aFrame {
namespace aUtil {


/*******************************************************************************
* class aRect
*******************************************************************************/
class aRect
{
    private:
        s32		m_x     { 0 };
        s32		m_y     { 0 };
        s32		m_w     { 0 };
        s32		m_h     { 0 };

    public:
        aRect();

        aRect(const aRect	&_rhs);

        aRect(const s32	_x,
              const s32	_y,
              const s32	_w,
              const s32	_h);

        aRect(const aPoint  &_v2dOrigin,
              const s32     _w,
              const s32     _h);

        aRect(const aPoint  &_v2dOrigin,
              const aPoint  &_v2dOppositCorner);

        virtual ~aRect();

        s32                     x() const       { return m_x; }
        s32                     y() const       { return m_y; }
        s32                     w() const       { return m_w; }
        s32                     h() const       { return m_h; }

        s32&                    x()             { return m_x; }
        s32&                    y()             { return m_y; }
        s32&                    w()             { return m_w; }
        s32&                    h()             { return m_h; }

        // exact math: , the r/b is t/l + w/h
        // for pixels, the r/b is alway t/l + w/h minus 1
        s32                     l() const       { return m_x; }                         // left
        s32                     t() const       { return m_y; }                         // top
        s32                     r() const       { return m_x + m_w - 1; }               // pixel-right
        s32                     b() const       { return m_y + m_h - 1; }               // pixel-bottom

        aPoint                  lt() const      { return aPoint(m_x, m_y); }      // left top
        aPoint                  lb() const      { return aPoint(m_x, b()); }     // left bottom
        aPoint                  rt() const      { return aPoint(r(), m_y); }      // right top
        aPoint                  rb() const      { return aPoint(r(), b()); }      // right bottom

        void					set(const s32   _x,
                                    const s32	_y,
                                    const s32	_w,
                                    const s32	_h);

       void                     set(const aPoint    &_v2dOrigin,
                                    const s32		_w,
                                    const s32		_h);

        aRect&                  operator=(const aRect &_rhs);

        aRect                   operator+(const aMargin &_margin) const;
        aRect                   operator-(const aMargin &_margin) const;

        aRect&                  operator+=(const aMargin &_margin);
        aRect&                  operator-=(const aMargin &_margin);

        bool                    operator==(const aRect &_rhs) const;
        bool                    operator!=(const aRect &_rhs) const;

        aDimension              dimension() const;

        void                    resize(dbl _dFactor);

        aPoint                  centerPoint() const;
        void                    setCenterPoint(s32 _x,
                                               s32 _y);

        void                    setEmpty();
        bool                    isEmpty() const;

        void                    shrink(s32 _value);
        void                    expand(s32 _value);

        // aRect                   intersect(const aRect &_rhs) const;
        // aRect                   intersect1(const aRect &_rhs) const;

        // 0 intersections => line outside the rect
        // 1 intersections => line mets corner point
        // 2 intersections => line cuts rectangle
        // the order of the found points follows the direction of the line
        //aVector<aPoint>         intersect(const aParametricLine2D<T> &_l) const;

        bool                    pointInRect(const aPoint &_p2d) const;

        bool                    pointInRect(s32 _x,
                                            s32 _y) const;

        //            aRect        FitIntoRect(const aRect	&_rct2FitInto) const;

        // aPoint            Transform(const aRect&  _rctDst,
        //                                   const aPoint&       _v2dTrans) const;

        // aRect       Transform(const aRect&  _rctDst,
        //                                   const aRect&  _r2dTrans) const;

        friend std::ostream&    operator<<(std::ostream        &_os,
                                        const aRect    &_r2d)
        {
            _os << "(x:" << _r2d.m_x
                << ", y:" << _r2d.m_y
                << ", w:" << _r2d.m_w
                << ", h:" << _r2d.m_h
                << ")";

            return _os;
        } // operator<<

}; // class aRect


} // namespace aUtil
} // namespace aFrame
