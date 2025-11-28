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
#include "aChannel_i.h"

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
class aChannel8Bit : public aChannelI
{
    protected:
        unsigned char   *m_pData    { nullptr };


    public:
        aChannel8Bit(s32   _s32W,
                     s32   _s32H);

        aChannel8Bit(const aDimension &_dimension) : aChannel8Bit(_dimension.w(),
                                                                  _dimension.h()) {}

        virtual ~aChannel8Bit();

        color_t             value(s32   _s32X,
                                  s32   _s32Y) const override;

        void                setValue(s32       _s32X,
                                     s32       _s32Y,
                                     color_t   _value) override;

}; // class aChannel8Bit


} // namespace aPic
} // namespace aFrame
