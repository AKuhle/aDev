/*******************************************************************************
* \file aLayerRgba.h
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
#include "aLayer_rgba.h"

using namespace aFrame::aUtil;


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aFrame {
namespace aPic {


/*******************************************************************************
* aLayerRgba::aLayerRgba
*******************************************************************************/
aLayerRgba::aLayerRgba(s32   _s32W,
                       s32   _s32H)
: aLayerI(_s32W, _s32H)
{
    m_pChannelR = make_shared<aChannel8Bit> (_s32W, _s32H);
    m_pChannelG = make_shared<aChannel8Bit> (_s32W, _s32H);
    m_pChannelB = make_shared<aChannel8Bit> (_s32W, _s32H);
} // aLayerRgba::aLayerRgba


/*******************************************************************************
* aLayerRgba::~aLayerRgba
*******************************************************************************/
aLayerRgba::~aLayerRgba()
{
} // aLayerRgba::~aLayerRgba


/*******************************************************************************
* aLayerRgba::setPixel
*******************************************************************************/
void aLayerRgba::setPixel(s32            _x,
                          s32            _y,
                          const aColor   &_col)
{
    m_pChannelR->setValue(_x, _y, _col.r());
    m_pChannelG->setValue(_x, _y, _col.g());
    m_pChannelB->setValue(_x, _y, _col.b());
} // aLayerRgba::setPixel


/*******************************************************************************
* aLayerRgba::pixel
*******************************************************************************/
void aLayerRgba::pixel(s32      _x,
                       s32      _y,
                       aColor   &_col) const
{
    _col.set(m_pChannelR->value(_x, _y),
             m_pChannelG->value(_x, _y),
             m_pChannelB->value(_x, _y));

} // aLayerRgba::pixel


} // namespace aPic
} // namespace aFrame
