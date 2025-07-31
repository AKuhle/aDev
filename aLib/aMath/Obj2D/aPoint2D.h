/*******************************************************************************
* \file aPoint2D.h
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
#include "aLib_def.h"
#include "aHelper.h"

#include "aMathObj2D.h"

using namespace aLib::aUtil;


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aMath {


/*******************************************************************************
* class aPoint2D
*******************************************************************************/
template<class T>
class aPoint2D : public aMathObj2D
{
    private:
        T		m_x	{ 0 };			//!< x-component
        T		m_y	{ 0 };			//!< y-component

    public:
        aPoint2D();

        aPoint2D(const aPoint2D<T>& _rhs);

        aPoint2D(T _x,
                  T _y);

        virtual ~aPoint2D();

        T                       x() const       { return m_x; }
        T                       y() const       { return m_y; }

        T&                      x()             { return m_x; }
        T&                      y()             { return m_y; }

        void					Set(T _x,
                                    T _y);

        aPoint2D<T>&           operator=(const aPoint2D<T> &_rhs);

        bool                    operator==(const aPoint2D<T> &_rhs) const;
        bool                    operator!=(const aPoint2D<T> &_rhs) const;

        aPoint2D<T>            operator+(const aPoint2D<T>	&_rhs) const;
        aPoint2D<T>            operator-(const aPoint2D<T>	&_rhs) const;
        aPoint2D<T>            operator*(dbl _t) const;
        aPoint2D<T>            operator/(dbl _t) const;

        aPoint2D<T>&           operator+=(const aPoint2D<T> &_rhs);
        aPoint2D<T>&           operator-=(const aPoint2D<T> &_rhs);
        aPoint2D<T>&           operator*=(dbl _t);
        aPoint2D<T>&           operator/=(dbl _t);

        void					Normalize();

        dbl                     Norm() const;								//!< absolute value [=sqrt(x*x + y*y)]
        dbl                     NormSquare() const;							//!< square  of the absolute value

        dbl                     Distance(const aPoint2D<T> &_rhs) const;	//!< distance between the two points

        dbl                     ScalarProduct(const aPoint2D<T> &_rhs) const;


        friend std::ostream& operator<<(std::ostream&       _os,
                                        const aPoint2D<T>  &_v2d)
        {
            _os << "(x:" << _v2d.m_x
                << ", y:" << _v2d.m_y
                << ")";
              return _os;
        } // operator<<
}; // class aPoint2D


} // namespace aMath
} // namespace aLib

#include "aPoint2D.inl"
