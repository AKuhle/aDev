/*******************************************************************************
* \file qLayerRgb8.h
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
#include "qLayer_i.h"
#include "qChannel.h"


namespace qLib
{
    /*******************************************************************************
    * class qLayerRgb8
    *******************************************************************************/
    class qLayerRgb8 :  public qLayerI
	{
		private:
            unique_ptr<qChannel<u8>>    m_pR;
            unique_ptr<qChannel<u8>>    m_pG;
            unique_ptr<qChannel<u8>>    m_pB;
            unique_ptr<qChannel<u8>>    m_pA;

		public:
            qLayerRgb8(const qLayerRgb8 &_rhs) = delete;

            qLayerRgb8(const qRect2D<s32> &_rctLayer);		// constructs a layer with unset data

            qLayerRgb8(s32  _s32X,
                       s32	_s32Y,
                       s32	_s32W,
                       s32  _s32H);                         // => new LayerID for new Layer

            qLayerRgb8(s32  _s32W,
                       s32	_s32H);

            virtual ~qLayerRgb8() override;

            virtual enumLayerType           Type() const override;

            // // clone: same LayerID's, Layers copies also the image data on demand
            virtual unique_ptr<qLayerI>		CreateClone(bool    _bSameLayerID,
                                                        bool    _bCopyLayerData) const override;

            // clone: same LayerID's, empty Layers because of different size
            virtual unique_ptr<qLayerI>		CreateCloneSwapWH(bool _bSameLayerID) const override;

            virtual void                    Clear() override;


        /*******************************************************************************
        * pixel access
        *******************************************************************************/
		public:
            virtual void					Pixel(s32   _s32X,
                                                  s32   _s32Y,
                                                  qRgba &_rgba) const override;

            virtual void                    SetPixel(s32            _s32X,
                                                     s32            _s32Y,
                                                     const qRgba    &_rgba) override;

            virtual void                    SetPixel(s32    _s32X,
                                                     s32    _s32Y,
                                                     Rgba_t _r,
                                                     Rgba_t _g,
                                                     Rgba_t _b,
                                                     Rgba_t _a) override;

    }; // class qLayerRgb8

} // namespace qLib
