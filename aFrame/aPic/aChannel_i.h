/*******************************************************************************
* \file mathDefs.h
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
#include "aDimension.h"

using namespace aFrame::aUtil;


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aFrame {
namespace aPic {


/*******************************************************************************
* const
*******************************************************************************/


/*******************************************************************************
* macros
*******************************************************************************/


/*******************************************************************************
* classes
*******************************************************************************/
class aChannelI
{
    protected:
        s32     m_s32W              { 0 };
        s32     m_s32H              { 0 };

    public:
        virtual ~aChannelI();

        aDimension          dimension() const       { return aDimension(m_s32W, m_s32H); }
        s32                 w() const               { return m_s32W; }
        s32                 h() const               { return m_s32H; }

        virtual color_t     value(s32   _s32X,
                                  s32   _s32Y) const = 0;

        virtual void        setValue(s32       _s32X,
                                     s32       _s32Y,
                                     color_t   _value) = 0;


    protected:
        aChannelI(s32   _s32W,
                  s32   _s32H);
};


} // namespace aPic
} // namespace aFrame
