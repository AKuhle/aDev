/*******************************************************************************
* \file qRect2D.h
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


//------------------------------------------------------------------------------
// includes
//------------------------------------------------------------------------------
#include "qBaseDefs.h"
#include "qMathObj2D.h"
#include "qVector2D.h"
#include "qDimension2D.h"
#include "qTransform.h"


namespace qLib
{
    //! \class qRect2D
	//! \brief definition of a rect. A rect has an origin and a size
	//!
	//! A size has a width and a height.
    template<class T, class Tprec = double>
    class qRect2D : public qMathObj2D
	{
        private:
            T		m_x { 0 };
            T		m_y { 0 };
            T		m_w { 0 };
            T		m_h { 0 };

		public:
            qRect2D();

            qRect2D(const qRect2D<T, Tprec>	&_rhs);

            qRect2D(const T	_x,
                    const T	_y,
                    const T	_w,
                    const T	_h);

//            qRect2D(const qlVector2D<T>	&_v2dOrigin,
//                    const T                 _w,
//                    const T                 _h);

            qRect2D(const qVector2D<T>& _v2dOrigin,
                    const qVector2D<T>& _v2dOppositCorner);

            virtual ~qRect2D();

            void					Set(const T _x,
                                        const T	_y,
                                        const T	_w,
                                        const T	_h);

            //            void					Set(const qlVector2D<T>	&_v2d,
            //										const T				_w,
            //										const T				_h);

            qRect2D<T, Tprec>&      operator=(const qRect2D<T, Tprec>		&_rhs);

            bool					operator==(const qRect2D<T, Tprec>		&_rhs) const;
            bool 					operator!=(const qRect2D<T, Tprec>		&_rhs) const;

            qDimension2D<s32>       Dimension() const;

            void 					Resize(Tprec _tFactor);

            qVector2D<T>			CenterPoint() const;
//			void					SetCenterPoint(const T		_x,
//												   const T		_y);

            void					SetEmpty();
			bool					IsEmpty() const;

            void                    Shrink(T _tValue);
            void                    Expand(T _tValue);

            qRect2D<T, Tprec>       Intersect(const qRect2D<T, Tprec>& _rhs) const;

            bool					PointInRect(const qVector2D<T>& _v2d) const;

            bool                    PointInRect(const T _x,
                                                const T _y) const;

//            qRect2D<T, Tprec>        FitIntoRect(const qRect2D<T, Tprec>	&_rct2FitInto) const;
			
            qVector2D<T>            Transform(const qRect2D<T, Tprec>&  _rctDst,
                                              const qVector2D<T>&       _v2dTrans) const;

            qRect2D<T, Tprec>       Transform(const qRect2D<T, Tprec>&  _rctDst,
                                              const qRect2D<T, Tprec>&  _r2dTrans) const;

            T                       x() const       { return m_x; }                           // left
            T                       y() const       { return m_y; }                           // top
            T                       w() const       { return m_w; }                           // width
            T                       h() const       { return m_h; }                           // height

            T&                      x()             { return m_x; }                           // left
            T&                      y()             { return m_y; }                           // top
            T&                      w()             { return m_w; }                           // width
            T&                      h()             { return m_h; }                           // height

            // exact math: , the r/b is t/l + w/h
            // for pixels, the r/b is alway t/l + w/h !minus! 1
            T                       l() const       { return m_x; }                           // left
            T                       t() const       { return m_y; }                           // top

            T                       r() const       { return m_x + m_w; }                       // right
            T                       r1() const      { return m_x + m_w - 1; }                   // pixel-right

            T                       b() const       { return m_y + m_h; }                       // bottom
            T                       b1() const      { return m_y + m_h - 1; }                   // pixel-bottom

            qVector2D<T>            lt() const      { return qVector2D<T>(m_x, m_y); }          // left top

            qVector2D<T>            lb() const      { return qVector2D<T>(m_x, b()); }        // left bottom
            qVector2D<T>            lb1() const     { return qVector2D<T>(m_x, b1()); }       // left bottom

            qVector2D<T>            rt() const      { return qVector2D<T>(r(), m_y); }        // right top
            qVector2D<T>            rt1() const     { return qVector2D<T>(r1(), m_y); }       // pixel right top

            qVector2D<T>            rb() const      { return qVector2D<T>(r(), b()); }      // right bottom
            qVector2D<T>            rb1() const     { return qVector2D<T>(r1(), b1()); }    // pixel right bottom


            friend ostream& operator<<(ostream&                     _os,
                                       const qRect2D<T, Tprec>&     _r2d)
            {
                _os << "(x:" << _r2d.x()
                    << ", y:" << _r2d.y()
                    << ", w:" << _r2d.w()
                    << ", h:" << _r2d.h()
                    << ")";
                return _os;
            } // operator<<
    }; // class qRect2D

} // namespace qLib

#include "qRect2D.inl"
