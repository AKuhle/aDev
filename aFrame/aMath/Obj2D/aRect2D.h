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

#include "aMathObj2D.h"
#include "aDimension2D.h"
#include "aPoint2D.h"
#include "aParametricLine2D.h"

#include "aRect.h"

using namespace std;
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
template<class T = dbl>
class aRect2D : public aMathObj2D
{
    private:
        T		m_x     { 0 };
        T		m_y     { 0 };
        T		m_w     { 0 };
        T		m_h     { 0 };

        // member for transformation aRect <--> aRect2D<T>
        aRect	m_rctTransform;
        bool    m_bTransform    { false };


    public:
        aRect2D();

        aRect2D(const aRect2D<T>	&_rhs);

        aRect2D(const aRect	&_rctTransform);

        aRect2D(T	_x,
                T	_y,
                T	_w,
                T	_h);

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
        T                       r() const       { return m_x + m_w; }                   // right
        T                       t() const       { return m_y + m_h; }                   // top
        T                       b() const       { return m_y; }                         // bottom


        aPoint2D<T>            lt() const      { return aPoint2D<T>(l(), t()); }      // left top
        aPoint2D<T>            lb() const      { return aPoint2D<T>(l(), b()); }      // left bottom
        aPoint2D<T>            rt() const      { return aPoint2D<T>(r(), t()); }      // right top
        aPoint2D<T>            rb() const      { return aPoint2D<T>(r(), b()); }      // right bottom

        void					set(T   _x,
                                    T	_y,
                                    T	_w,
                                    T	_h);

        //            void					set(const qlVector2D<T>	&_v2d,
        //										const T				_w,
        //										const T				_h);

        aRect2D<T>&             operator=(const aRect2D<T> &_rhs);

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

        //aRect2D<T>              intersect(const aRect2D<T> &_rhs) const;
        //aRect2D<T>              intersect1(const aRect2D<T> &_rhs) const;

        // calculates the intersection of a given line with this rect.
        // this method is for transformed rects, therefore the result vector
        // is of type aPoint.
        //
        // 0 intersections => line outside the rect
        // 1 intersections => line mets corner point
        // 2 intersections => line cuts rectangle
        // _vIntersect: the intersect points in direction of the line
        void                    intersect(aParametricLine2D<T>  &_line,
                                          vector<aPoint>        &_vIntersect) const;

        // edge include => l() <= x <= r(); b() <= y <= t()
        bool					pointInRect(const aPoint2D<T> &_v2d) const;
        bool                    pointInRect(T _x,
                                            T _y) const;

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


    private:
        T                       win2MathY(T _tY) const;
        T                       math2WinY(T _tY) const;

        aPoint2D<T>             win2MathY(const aPoint &_pnt) const;
        aPoint                  math2WinY(const aPoint2D<T> &_p2d) const;
}; // class aRect2D


} // namespace aMath
} // namespace aFrame


#include "aRect2D.inl"
