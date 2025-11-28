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
#include "aChannel_8bit.h"
#include "aLayer_i.h"

using namespace std;
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
* aLayerRgba
*******************************************************************************/
class aLayerRgba : aLayerI
{
    private:
        shared_ptr<aChannel8Bit>    m_pChannelR;
        shared_ptr<aChannel8Bit>    m_pChannelG;
        shared_ptr<aChannel8Bit>    m_pChannelB;

    public:
        aLayerRgba(s32   _s32W,
                   s32   _s32H);

        aLayerRgba(const aDimension &_dimension) : aLayerRgba(_dimension.w(),
                                                              _dimension.h()) {}

        virtual ~aLayerRgba();

        void                    setPixel(s32            _x,
                                         s32            _y,
                                         const aColor   &_col) override;

        void                    pixel(s32       _x,
                                      s32       _y,
                                      aColor    &_col) const override;

}; // class aLayerRgba


} // namespace aPic
} // namespace aFrame
