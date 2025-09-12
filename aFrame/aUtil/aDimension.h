/*******************************************************************************
* \file aDimension.h
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



/*******************************************************************************
* namespace
*******************************************************************************/
namespace aFrame {
namespace aUtil {


//! \class aDimension
//! \brief definition of a rect. A rect has an origin and a size
//!
//! A size has a width and a height.
class aDimension
{
    private:
        s32		m_w { 0 };
        s32		m_h { 0 };

    public:
        aDimension();
        aDimension(const aDimension	&_rhs);
        aDimension(s32 _w,
                     s32 _h);
        virtual ~aDimension();

        aDimension&             operator=(const aDimension &_rhs);

        bool					operator==(const aDimension &_rhs) const;
        bool 					operator!=(const aDimension &_rhs) const;

        aDimension&             operator+=(const aDimension &_rhs);
        aDimension&             operator*=(dbl _dMuliplicator);

        aDimension              operator*(dbl _dMuliplicator) const;

        s32                     w() const;
        s32                     h() const;

        s32&                    w();
        s32&                    h();

        void					set(const s32 _w,
                                    const s32	_h);

        void					setEmpty();
        bool					isEmpty() const;

        aDimension              max(const aDimension &_rhs) const;

        static aDimension       max(const aDimension &_dim1,
                                    const aDimension &_dim2);

        friend std::ostream& operator<<(std::ostream        &_os,
                                        const aDimension    &_d2d)
        {
              _os << "(w:" << _d2d.m_w
                  << ", h:" << _d2d.m_h
                  << ")";

              return _os;
        } // operator<<

}; // class aDimension




} // namespace aUtil
} // namespace aFrame
