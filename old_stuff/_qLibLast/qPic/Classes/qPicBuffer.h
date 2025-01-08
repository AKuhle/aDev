/*******************************************************************************
* \file qPicBuffer.h
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
#include <QImage>
#include "qBaseDefs.h"
#include "qPicDefs.h"
#include "qDimension2D.h"
#include "qVector2D.h"


namespace qLib
{
    /*******************************************************************************
    * forwards
    *******************************************************************************/
    class qLayerI;
    class qLayerStack;

    using namespace std;

    /*******************************************************************************
    * class qPicBuffer
    *******************************************************************************/
    class qPicBuffer
	{
        private:
            enumPicBufferFormat     m_ePicBufferFormat          { enumPicBufferFormat::None };
            qDimension2D<s32>       m_d2dBuf;

            u64                     m_u64PixelSize_byte         { 0 };
            u64                     m_s64RowSize_byte			{ 0 };
            u64                     m_u64BufferSize_byte		{ 0 };
            u64                     m_u64MaxBufferSize_byte		{ 0 };
            u8                      *m_pBuffer					{ nullptr };

		public:
            qPicBuffer();
            virtual ~qPicBuffer();

            // existing buffer will be reused
            void                        CreateBuffer(enumPicBufferFormat        _ePicBufferFormat,
                                                     const qDimension2D<s32>    &_d2dBuf);

            void                        CreateBuffer(enumPicBufferFormat  _ePicBufferFormat,
                                                     s32                  _s32W,
                                                     s32                  _s32H);

            void                        ClearBuffer();

            enumPicBufferFormat         BufferFormat() const;
            const qDimension2D<s32>&    Dimension() const;
            s32                         w() const;
            s32                         h() const;

            template <class T>
            T*                          DataPointer() const             { return (T*) (m_pBuffer); }

            template <class T>
            T*                          DataPointer(s32  _s32X,
                                                    s32  _s32Y) const   { return (T*) (m_pBuffer + _s32Y*m_s64RowSize_byte + _s32X*m_u64PixelSize_byte); }

            void                        AddLayer2Buffer(qLayerI                 *_pLayer,                // the layer to add
                                                        const qVector2D<s32>    &_v2dBufOrigin_zoom,    // buf-position within the zoomed pic
                                                        dbl                     _dZoomFactor) const;    // the zoomfactor

            // void                        ToQImage(shared_ptr<qLayerStack>    _pLayerStack,
            //                                      s32                        _s32QImageW,
            //                                      s32                        _s32QImageH,
            //                                      const qVector2D<s32>       &_v2dBufOrigin_zoom,
            //                                      dbl                        _dZoomFactor,
            //                                      QImage                     *&_pImg);

            // void                        ToQImage(shared_ptr<qLayerStack>    _pLayerStack,
            //                                      const qDimension2D<s32>    &_d2dQImage,
            //                                      const qVector2D<s32>       &_v2dBufOrigin_zoom,
            //                                      const dbl                  _dZoomFactor,
            //                                      QImage                     *&_pImg);

            // void                        ToQImage(shared_ptr<qLayerI>    _pLayer,
            //                                      s32                    _s32QImageW,
            //                                      s32                    _s32QImageH,
            //                                      const qVector2D<s32>   &_v2dBufOrigin_zoom,
            //                                      dbl                    _dZoomFactor,
            //                                      QImage                 *&_pImg);

            // void                        ToQImage(shared_ptr<qLayerI>        _pLayer,
            //                                      const qDimension2D<s32>    &_d2dQImage,
            //                                      const qVector2D<s32>       &_v2dBufOrigin_zoom,
            //                                      const dbl                  _dZoomFactor,
            //                                      QImage                     *&_pImg);

            void                        ToQImage(shared_ptr<qLayerStack>    _pLayerStack,
                                                 s32                        _s32QImageW,
                                                 s32                        _s32QImageH,
                                                 const qVector2D<s32>       &_v2dBufOrigin_zoom,
                                                 dbl                        _dZoomFactor,
                                                 QImage                     *&_pImg);
    }; // class qPicBuffer

} // namespace qLib
