/*******************************************************************************
* \file aVector2D.h
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

using namespace aFrame::aUtil;


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aFrame {
namespace aMath {


/*******************************************************************************
* class aVector2D
*******************************************************************************/
template<class T>
class aVector2D : public aMathObj2D
{
    private:
        T		m_x	{ 0 };			//!< x-component
        T		m_y	{ 0 };			//!< y-component

    public:
        aVector2D();

        aVector2D(const aVector2D<T>& _rhs);

        aVector2D(T _x,
                  T _y);

        virtual ~aVector2D();

        T                       x() const       { return m_x; }
        T                       y() const       { return m_y; }

        T&                      x()             { return m_x; }
        T&                      y()             { return m_y; }

        void					Set(T _x,
                                    T _y);

        aVector2D<T>&           operator=(const aVector2D<T> &_rhs);

        bool                    operator==(const aVector2D<T> &_rhs) const;
        bool                    operator!=(const aVector2D<T> &_rhs) const;

        aVector2D<T>            operator+(const aVector2D<T>	&_rhs) const;
        aVector2D<T>            operator-(const aVector2D<T>	&_rhs) const;
        aVector2D<T>            operator*(dbl _t) const;
        aVector2D<T>            operator/(dbl _t) const;

        aVector2D<T>&           operator+=(const aVector2D<T> &_rhs);
        aVector2D<T>&           operator-=(const aVector2D<T> &_rhs);
        aVector2D<T>&           operator*=(dbl _t);
        aVector2D<T>&           operator/=(dbl _t);

        void					Normalize();

        dbl                     Norm() const;								//!< absolute value [=sqrt(x*x + y*y)]
        dbl                     NormSquare() const;							//!< square  of the absolute value

        dbl                     Distance(const aVector2D<T> &_rhs) const;	//!< distance between the two points

        dbl                     ScalarProduct(const aVector2D<T> &_rhs) const;


        friend std::ostream& operator<<(std::ostream&       _os,
                                        const aVector2D<T>  &_v2d)
        {
            _os << "(x:" << _v2d.m_x
                << ", y:" << _v2d.m_y
                << ")";
              return _os;
        } // operator<<
}; // class aVector2D


} // namespace aMath
} // namespace aFrame

#include "aVector2D.inl"
