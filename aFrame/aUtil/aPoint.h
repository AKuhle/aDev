/*******************************************************************************
* \file aPoint.h
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


/*******************************************************************************
* class aPoint
*******************************************************************************/
class aPoint
{
    private:
        s32		m_x	{ 0 };			//!< x-component
        s32 	m_y	{ 0 };			//!< y-component

    public:
        aPoint();

        aPoint(const aPoint& _rhs);

        aPoint(s32    _x,
               s32    _y);

        virtual ~aPoint();

        s32                     x() const       { return m_x; }
        s32                     y() const       { return m_y; }

        s32&                    x()             { return m_x; }
        s32&                    y()             { return m_y; }

        void					set(s32 _x,
                                    s32 _y);

        aPoint&                 operator=(const aPoint &_rhs);

        bool                    operator==(const aPoint &_rhs) const;
        bool                    operator!=(const aPoint &_rhs) const;

        friend std::ostream& operator<<(std::ostream&       _os,
                                        const aPoint  &_v2d)
        {
            _os << "(x:" << _v2d.m_x
                << ", y:" << _v2d.m_y
                << ")";
              return _os;
        } // operator<<
}; // class aPoint


} // namespace aUtil
} // namespace aFrame
