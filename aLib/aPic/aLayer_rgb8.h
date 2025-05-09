/*******************************************************************************
* \file aLayerRgb8.h
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
#include "aLayer_i.h"
#include "aChannel.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aPic {


/*******************************************************************************
* class aLayerRgb8
*******************************************************************************/
class aLayerRgb8 :  public aLayerI
{
    private:
        unique_ptr<aChannel<u8>>    m_pR;
        unique_ptr<aChannel<u8>>    m_pG;
        unique_ptr<aChannel<u8>>    m_pB;
        unique_ptr<aChannel<u8>>    m_pA;


    private:
        aLayerRgb8(const aLayerRgb8 &_rhs);


    public:
        aLayerRgb8(const aRect2D<s32>  &_rctGeometry,
                   aString             _sName           = "",
                   bool                _bVisible        = true,
                   dbl                 _dOpacity        = 1.);

        aLayerRgb8(s32                  _w,
                   s32                  _h,
                   aString             _sName           = "",
                   bool                _bVisible        = true,
                   dbl                 _dOpacity        = 1.);


        aLayerRgb8(s32                  _x,
                   s32                  _y,
                   s32                  _w,
                   s32                  _h,
                   aString             _sName           = "",
                   bool                _bVisible        = true,
                   dbl                 _dOpacity        = 1.);

        ~aLayerRgb8() override;

        // clone: Layers copies also the image data on demand
        unique_ptr<aLayerI>             createClone(bool    _bCopyData) const override;

        virtual unique_ptr<aLayerI>		createClone(s32 _s32NewW,
                                                    s32 _s32NewH) const override;

        void                            clear() override;


    /*******************************************************************************
    * pixel access
    *******************************************************************************/
    public:
        void                            pixel(s32       _x,
                                              s32       _y,
                                              aColor    &_rgba) const override;

        void                            setPixel(s32            _x,
                                                 s32            _y,
                                                 const aColor   &_rgba) override;

        void                            setPixel(s32        _x,
                                                 s32        _y,
                                                 color_t    _r,
                                                 color_t    _g,
                                                 color_t    _b,
                                                 color_t    _a) override;

}; // class aLayerRgb8


} // namespace aPic
} // namespace aLib
