/*******************************************************************************
* \file qInterval2D.h
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
#include "qMathObjBase2D.h"
#include "qMathUtil.h"


namespace qLib
{
    //! \class qInterval2D
	//! \brief definition of a rect. A rect has an origin and a size
	//!
	//! A size has a width and a height.
	template<class T>
    class qInterval2D : public qMathObjBase2D
	{
        public:
            T		min { 0 };
            T		max { 0 };

		public:
            qInterval2D();
            qInterval2D(const qInterval2D<T>	&_rhs);
            qInterval2D(const T _min,
                        const T _max);
            virtual ~qInterval2D();

            qInterval2D<T>&         operator=(const qInterval2D<T> &_rhs);

            bool					operator==(const qInterval2D<T> &_rhs) const;
            bool 					operator!=(const qInterval2D<T> &_rhs) const;

            void					Set(const T _min,
                                        const T	_max);

			void					SetEmpty();
			bool					IsEmpty() const;

    }; // class qInterval2D


    // global stream member
    template <class T>
    std::ostream& operator<<(std::ostream           &_os,
                             const qInterval2D<T>   &_i2d)
    {
          _os << "([" << _i2d.min << ", " << _i2d.max << "]";

          return _os;
    } // operator<<

} // namespace qLib

#include "qInterval2D.inl"
