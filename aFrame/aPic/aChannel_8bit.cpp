/*******************************************************************************
* \file aChannel8Bit.h
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



/*******************************************************************************
* includes
*******************************************************************************/
#include "aChannel_8Bit.h"

using namespace aFrame::aUtil;


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aFrame {
namespace aPic {


/*******************************************************************************
* aChannel8Bit::aChannel8Bit
*******************************************************************************/
aChannel8Bit::aChannel8Bit(s32   _s32W,
                           s32   _s32H)
: aChannelI(_s32W, _s32H)
{
    m_pData = new unsigned char[m_s32W * _s32H];
} // aChannel8Bit::aChannel8Bit


/*******************************************************************************
* aChannel8Bit::~aChannel8Bit
*******************************************************************************/
aChannel8Bit::~aChannel8Bit()
{
} // aChannel8Bit::~aChannel8Bit


/*******************************************************************************
* aChannel8Bit::value
*******************************************************************************/
color_t aChannel8Bit::value(s32   _s32X,
                            s32   _s32Y) const
{
    return (static_cast<color_t> (m_pData[m_s32W * _s32Y + _s32X])) / 255;
} // aChannel8Bit::value


/*******************************************************************************
* aChannel8Bit::setValue
*******************************************************************************/
void aChannel8Bit::setValue(s32     _s32X,
                            s32     _s32Y,
                            color_t _value)
{
    m_pData[m_s32W * _s32Y + _s32X] = static_cast<unsigned char> (_value * 255);
} // aChannel8Bit::setValue


} // namespace aPic
} // namespace aFrame
