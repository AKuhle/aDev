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
#include "qLibDefs.h"
#include "Util/utilDefs.h"
#include "Math/qMathObj2D.h"

using namespace qLib::Util;


/*******************************************************************************
* namespace
*******************************************************************************/
namespace qLib {
namespace Math {


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
        qDimension2D<T>&        operator*=(double _dMuliplicator);

        qDimension2D<T>         operator*(double _dMuliplicator) const;

        T                       w() const;
        T                       h() const;

        T&                      w();
        T&                      h();

        void					set(const T _w,
                                    const T	_h);

        void					setEmpty();
        bool					isEmpty() const;

        friend std::ostream& operator<<(std::ostream           &_os,
                                        const qDimension2D<T>  &_d2d)
        {
              _os << "(w:" << _d2d.m_w
                  << ", h:" << _d2d.m_h
                  << ")";

              return _os;
        } // operator<<

}; // class qDimension2D




} // namespace Math
} // namespace qLib

#include "qDimension2D.inl"
