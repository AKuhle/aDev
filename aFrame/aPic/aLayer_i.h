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
#include "aPic_def.h"
#include "aColor.h"

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
* aLayerI
*******************************************************************************/
class aLayerI
{
    protected:
        s32         m_s32W;
        s32         m_s32H;


    public:
        virtual ~aLayerI();

        virtual void            setPixel(s32            _x,
                                         s32            _y,
                                         const aColor   &_col) = 0;

        virtual void            pixel(s32       _x,
                                      s32       _y,
                                      aColor    &_col) const = 0;

        virtual void            addToBuffer(aPicBuffer &_buf) const = 0;


    protected:
        aLayerI(s32   _s32W,
                s32   _s32H);

}; // class aLayerI


} // namespace aPic
} // namespace aFrame
