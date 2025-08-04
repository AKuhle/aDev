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
template<class T = dbl>
class aVector2D : public aMathObj2D
{
    private:
        T		m_dx	{ 0 };			//!< x-component
        T		m_dy	{ 0 };			//!< y-component

    public:
        aVector2D();

        aVector2D(const aVector2D<T>& _rhs);

        aVector2D(T _dx,
                  T _dy);

        virtual ~aVector2D();

        T                       dx() const       { return m_dx; }
        T                       dy() const       { return m_dy; }

        T&                      dx()             { return m_dx; }
        T&                      dy()             { return m_dy; }

        void					set(T _dx,
                                    T _dy);

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

        void					normalize();

        dbl                     norm() const;								//!< absolute value [=sqrt(x*x + y*y)]
        dbl                     normSquare() const;							//!< square  of the absolute value

        dbl                     scalarProduct(const aVector2D<T> &_rhs) const;


        friend std::ostream& operator<<(std::ostream&       _os,
                                        const aVector2D<T>  &_v2d)
        {
            _os << "(x:" << _v2d.m_dx
                << ", y:" << _v2d.m_dy
                << ")";
              return _os;
        } // operator<<
}; // class aVector2D


} // namespace aMath
} // namespace aFrame

#include "aVector2D.inl"
