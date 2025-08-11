/*******************************************************************************
* \file aMargin.h
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
* \class aMargin
* \brief baseclass for 2D math objects
*******************************************************************************/
class aMargin
{
    private:
        s32     m_l  { 0 };
        s32     m_r  { 0 };
        s32     m_t  { 0 };
        s32     m_b  { 0 };

    public:
        aMargin();

        aMargin(s32 _lrtb);

        aMargin(s32  _l,
                s32  _r,
                s32  _t,
                s32  _b);

        virtual ~aMargin();

        void    set(s32  _lrtb);

        void    set(s32  _l,
                    s32  _r,
                    s32  _t,
                    s32  _b);

        s32     l() const           { return m_l; }
        s32     r() const           { return m_r; }
        s32     t() const           { return m_t; }
        s32     b() const           { return m_b; }

        s32     w() const           { return m_l + m_r; }
        s32     h() const           { return m_t + m_b; }


        friend std::ostream& operator<<(std::ostream    &_os,
                                        const aMargin   &_margin)
        {
            _os << "(l:" << _margin.m_l
                << ", r:" << _margin.m_r
                << ", t:" << _margin.m_t
                << ", b:" << _margin.m_b
                << ")";

            return _os;
        } // operator<<

}; // class aMargin


} // namespace aUtil
} // namespace aFrame
