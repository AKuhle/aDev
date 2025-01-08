/*******************************************************************************
* \file qDimension2D.h
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
    //! \class qDimension2D
	//! \brief definition of a rect. A rect has an origin and a size
	//!
	//! A size has a width and a height.
	template<class T>
    class qDimension2D : public qMathObj2D
	{
        private:
            T		m_w { 0 };
            T		m_h { 0 };

		public:
            qDimension2D();
            qDimension2D(const qDimension2D<T>	&_rhs);
            qDimension2D(const T _w,
                         const T _h);
            virtual ~qDimension2D();

            qDimension2D<T>&		operator=(const qDimension2D<T> &_rhs);

            bool					operator==(const qDimension2D<T> &_rhs) const;
            bool 					operator!=(const qDimension2D<T> &_rhs) const;

            qDimension2D<T>&        operator+=(const qDimension2D<T> &_rhs);
            qDimension2D<T>&        operator*=(double _dblMuliplicator);

            qDimension2D<T>         operator*(double _dblMuliplicator) const;

            T                       w() const;
            T                       h() const;

            T&                      w();
            T&                      h();

            void					Set(const T _w,
										const T	_h);

			void					SetEmpty();
			bool					IsEmpty() const;

    }; // class qDimension2D


    // global stream member
    template <class T>
    std::ostream& operator<<(std::ostream           &_os,
                             const qDimension2D<T>  &_s2d)
    {
          _os << "(w:" << _s2d.w << ", h:" << _s2d.h << ")";

          return _os;
    } // operator<<

} // namespace qLib

#include "qDimension2D.inl"
