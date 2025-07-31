/*******************************************************************************
* \file aRect2D.h
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

#include "aVector.h"

#include "aMathObj2D.h"
#include "aDimension2D.h"
#include "aPoint2D.h"

using namespace aFrame;
using namespace aFrame::aUtil;


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aFrame {
namespace aMath {


/*******************************************************************************
* class aRect2D
*******************************************************************************/
template<class T>
class aRect2D : public aMathObj2D
{
    private:
        T		m_x     { 0 };
        T		m_y     { 0 };
        T		m_w     { 0 };
        T		m_h     { 0 };

    public:
        aRect2D();

        aRect2D(const aRect2D<T>	&_rhs);

        aRect2D(const T	_x,
                const T	_y,
                const T	_w,
                const T	_h);

//            aRect2D(const qlVector2D<T>	&_v2dOrigin,
//                    const T                 _w,
//                    const T                 _h);

        // aRect2D(const aPoint2D<T>& _v2dOrigin,
        //         const aPoint2D<T>& _v2dOppositCorner);

        virtual ~aRect2D();

        T                       x() const       { return m_x; }
        T                       y() const       { return m_y; }
        T                       w() const       { return m_w; }
        T                       h() const       { return m_h; }

        T&                      x()             { return m_x; }
        T&                      y()             { return m_y; }
        T&                      w()             { return m_w; }
        T&                      h()             { return m_h; }

        // exact math: , the r/b is t/l + w/h
        // for pixels, the r/b is alway t/l + w/h minus 1
        T                       l() const       { return m_x; }                         // left
        T                       t() const       { return m_y; }                         // top

        T                       r() const       { return m_x + m_w; }                   // right
        T                       r1() const      { return m_x + m_w - 1; }               // pixel-right

        T                       b() const       { return m_y + m_h; }                   // bottom
        T                       b1() const      { return m_y + m_h - 1; }               // pixel-bottom

        aPoint2D<T>            lt() const      { return aPoint2D<T>(m_x, m_y); }      // left top

        aPoint2D<T>            lb() const      { return aPoint2D<T>(m_x, b()); }      // left bottom
        aPoint2D<T>            lb1() const     { return aPoint2D<T>(m_x, b1()); }     // left bottom

        aPoint2D<T>            rt() const      { return aPoint2D<T>(r(), m_y); }      // right top
        aPoint2D<T>            r1t() const     { return aPoint2D<T>(r1(), m_y); }     // pixel right top

        aPoint2D<T>            rb() const      { return aPoint2D<T>(r(), b()); }      // right bottom
        aPoint2D<T>            r1b1() const     { return aPoint2D<T>(r1(), b1()); }    // pixel right bottom

        void					set(const T _x,
                                    const T	_y,
                                    const T	_w,
                                    const T	_h);

        //            void					Set(const qlVector2D<T>	&_v2d,
        //										const T				_w,
        //										const T				_h);

        aRect2D<T>&             operator=(const aRect2D<T> &_rhs);

        aRect2D<T>              operator+(const aMargin &_margin) const;
        aRect2D<T>              operator-(const aMargin &_margin) const;

        aRect2D<T>&             operator+=(const aMargin &_margin);
        aRect2D<T>&             operator-=(const aMargin &_margin);

        bool					operator==(const aRect2D<T> &_rhs) const;
        bool 					operator!=(const aRect2D<T> &_rhs) const;

        aDimension2D<T>         dimension() const;

        void 					resize(dbl _dFactor);

        aPoint2D<T>             centerPoint() const;
        void					setCenterPoint(const T		_x,
                                               const T		_y);

        void                    setEmpty();
        bool					isEmpty() const;

        void                    shrink(T _tValue);
        void                    expand(T _tValue);

        aRect2D<T>              intersect(const aRect2D<T> &_rhs) const;
        aRect2D<T>              intersect1(const aRect2D<T> &_rhs) const;

        // 0 intersections => line outside the rect
        // 1 intersections => line mets corner point
        // 2 intersections => line cuts rectangle
        // the order of the found points follows the direction of the line
        aVector<aPoint2D<T>>    intersect(const aParametricLine2D<T> &_l) const;

        bool					pointInRect(const aPoint2D<T> &_v2d) const;

        bool                    pointInRect(const T _x,
                                            const T _y) const;

        //            aRect2D<T>        FitIntoRect(const aRect2D<T>	&_rct2FitInto) const;

        // aPoint2D<T>            Transform(const aRect2D<T>&  _rctDst,
        //                                   const aPoint2D<T>&       _v2dTrans) const;

        // aRect2D<T>       Transform(const aRect2D<T>&  _rctDst,
        //                                   const aRect2D<T>&  _r2dTrans) const;

        friend std::ostream& operator<<(std::ostream        &_os,
                                        const aRect2D<T>    &_r2d)
        {
            _os << "(x:" << _r2d.m_x
                << ", y:" << _r2d.m_y
                << ", w:" << _r2d.m_w
                << ", h:" << _r2d.m_h
                << ")";

            return _os;
        } // operator<<

}; // class aRect2D


} // namespace aMath
} // namespace aFrame


#include "aRect2D.inl"
