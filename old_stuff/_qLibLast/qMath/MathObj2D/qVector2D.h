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
#include "qBaseDefs.h"
#include "qMathObj2D.h"


namespace qLib
{
    using namespace std;

    //! \class qVector2D
	//! \brief 2D-Vectors (x, y)
	//!
	//! this class represents a 2 dimensional vector with a x- and y-component
    template<class T, class Tprec = dbl>
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

            T                       x() const;
            T                       y() const;
            T&                      x();
            T&                      y();

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

            Tprec					Distance(const qVector2D<T, Tprec>& _rhs) const;	//!< distance between the two points

            dbl                     ScalarProduct(const qVector2D<T, Tprec> &_rhs) const;


            friend ostream& operator<<(ostream&             _os,
                                       const qVector2D<T>&  _v2d)
            {
                _os << "(x:" << _v2d.x()
                    << ", y:" << _v2d.y()
                    << ")";
                  return _os;
            } // operator<<
    }; // class qVector2D

} // namespace qLib

#include "qVector2D.inl"
