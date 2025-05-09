/*******************************************************************************
* \file aDimension2D.h
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


//! \class aDimension2D
//! \brief definition of a rect. A rect has an origin and a size
//!
//! A size has a width and a height.
template<class T>
class aDimension2D : public aMathObj2D
{
    private:
        T		m_w { 0 };
        T		m_h { 0 };

    public:
        aDimension2D();
        aDimension2D(const aDimension2D<T>	&_rhs);
        aDimension2D(const T _w,
                     const T _h);
        virtual ~aDimension2D();

        aDimension2D<T>&		operator=(const aDimension2D<T> &_rhs);

        bool					operator==(const aDimension2D<T> &_rhs) const;
        bool 					operator!=(const aDimension2D<T> &_rhs) const;

        aDimension2D<T>&        operator+=(const aDimension2D<T> &_rhs);
        aDimension2D<T>&        operator*=(dbl _dMuliplicator);

        aDimension2D<T>         operator*(dbl _dMuliplicator) const;

        T                       w() const;
        T                       h() const;

        T&                      w();
        T&                      h();

        void					set(const T _w,
                                    const T	_h);

        void					setEmpty();
        bool					isEmpty() const;

        aDimension2D<T>         max(const aDimension2D<T> &_rhs) const;

        friend std::ostream& operator<<(std::ostream           &_os,
                                        const aDimension2D<T>  &_d2d)
        {
              _os << "(w:" << _d2d.m_w
                  << ", h:" << _d2d.m_h
                  << ")";

              return _os;
        } // operator<<

}; // class aDimension2D




} // namespace aMath
} // namespace aLib

#include "aDimension2D.inl"
