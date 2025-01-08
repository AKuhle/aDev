/*******************************************************************************
* \file qVector2D.h
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
#include "qLibDefs.h"
#include "Util/utilDefs.h"
#include "Math/mathDefs.h"

#include "Math/qMathObj2D.h"

using namespace qLib::Util;

/*******************************************************************************
* namespace
*******************************************************************************/
namespace qLib {
namespace Math {


/*******************************************************************************
* class qVector2D
*******************************************************************************/
template<class T, class Tprec>
class qVector2D : public qMathObj2D
{
    private:
        T		m_x	{ 0 };			//!< x-component
        T		m_y	{ 0 };			//!< y-component

    public:
        qVector2D();

        qVector2D(const qVector2D<T, Tprec>& _rhs);

        qVector2D(T _x,
                  T _y);

        virtual ~qVector2D();

        T                       x() const       { return m_x; }
        T                       y() const       { return m_y; }

        T&                      x()             { return m_x; }
        T&                      y()             { return m_y; }

        void					Set(T _x,
                                    T _y);

        qVector2D<T, Tprec>&	operator=(const qVector2D<T, Tprec> &_rhs);

        bool                    operator==(const qVector2D<T, Tprec> &_rhs) const;
        bool                    operator!=(const qVector2D<T, Tprec> &_rhs) const;

        qVector2D<T, Tprec>     operator+(const qVector2D<T, Tprec>	&_rhs) const;
        qVector2D<T, Tprec>     operator-(const qVector2D<T, Tprec>	&_rhs) const;
        qVector2D<T, Tprec>     operator*(const Tprec _t) const;
        qVector2D<T, Tprec>     operator/(const Tprec _t) const;

        qVector2D<T, Tprec>&    operator+=(const qVector2D<T, Tprec> &_rhs);
        qVector2D<T, Tprec>&    operator-=(const qVector2D<T, Tprec> &_rhs);
        qVector2D<T, Tprec>&    operator*=(const Tprec _t);
        qVector2D<T, Tprec>&    operator/=(const Tprec _t);

        void					Normalize();

        Tprec					Norm() const;								//!< absolute value [=sqrt(x*x + y*y)]
        Tprec					NormSquare() const;							//!< square  of the absolute value

        Tprec					Distance(const qVector2D<T, Tprec> &_rhs) const;	//!< distance between the two points

        dbl                     ScalarProduct(const qVector2D<T, Tprec> &_rhs) const;


        friend std::ostream& operator<<(std::ostream&             _os,
                                        const qVector2D<T>   &_v2d)
        {
            _os << "(x:" << _v2d.m_x
                << ", y:" << _v2d.m_y
                << ")";
              return _os;
        } // operator<<
}; // class qVector2D


} // namespace Math
} // namespace qLib

#include "qVector2D.inl"
