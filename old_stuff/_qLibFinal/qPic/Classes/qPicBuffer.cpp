/*******************************************************************************
* \file qPicBuffer.cpp
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
#include "qPicBuffer.h"
#include "qColor.h"
#include "qRect2D.h"
#include "qLayerBase.h"
#include "qLayerStack.h"


namespace qLib
{
	/*******************************************************************************
    * qPicBuffer::qPicBuffer
	*******************************************************************************/
    qPicBuffer::qPicBuffer()
	{
    } // qPicBuffer::qPicBuffer


    /*******************************************************************************
    * qPicBuffer::~qPicBuffer
    *******************************************************************************/
    qPicBuffer::~qPicBuffer()
	{
		delete m_pBuffer;
    } // qPicBuffer::~qPicBuffer


    /*******************************************************************************
    * qPicBuffer::CreateBuffer
    *******************************************************************************/
    void qPicBuffer::CreateBuffer(enumPicBufferFormat   _ePicBufferFormat,
                                  s32                   _s32W,
                                  s32                   _s32H)
    {
        m_ePicBufferFormat  = _ePicBufferFormat;

        // copy the size of the buffer
        m_d2dBuf.Set(_s32W, _s32H);

        // calculate format specific members
        switch (m_ePicBufferFormat)
        {
            default:
                break;

            case enumPicBufferFormat::ffrrggbb:
            //case enumPicBufferFormat::PicBufFormat_aarrggbb:
            {
                m_u64PixelSize_byte = 4;
                m_s64RowSize_byte   = m_d2dBuf.w * m_u64PixelSize_byte;
                break;
            }

//            case enumPicBufferFormat::PicBufFormat_aaaabbbbggggrrrr:
//            {
//                m_u64PixelSize_byte = 8;
//                m_s64RowSize_byte   = m_s32BufW * m_u64PixelSize_byte;
//                break;
//            }

//            case enumPicBufferFormat::PicBufFormat_graygray:
//            {
//                m_u64PixelSize_byte = 1;
//                m_s64RowSize_byte   = Ceil<s64> (m_s32BufW * m_u64PixelSize_byte, 4);
//                break;
//            }
        } // switch (m_ePicBufferFormat)

        // calculate the required buffe size
        m_u64BufferSize_byte = m_s64RowSize_byte * m_d2dBuf.h;

        // reuse the buffer if the required size fits
        // or create a new bigger one
        if (m_pBuffer == nullptr)
        {
            m_u64MaxBufferSize_byte = m_u64BufferSize_byte;
            m_pBuffer = new u8[m_u64BufferSize_byte];
        }
        else if (m_u64MaxBufferSize_byte < m_u64BufferSize_byte)
        {
            // current buffer is smaller than the new size => create new buffer
            delete[] m_pBuffer;
            m_u64MaxBufferSize_byte = m_u64BufferSize_byte;
            m_pBuffer = new u8[m_u64BufferSize_byte];
        }
    } // qPicBuffer::CreateBuffer


    /*******************************************************************************
    * qPicBuffer::CreateBuffer
    *******************************************************************************/
    void qPicBuffer::CreateBuffer(enumPicBufferFormat       _ePicBufferFormat,
                                  const qDimension2D<s32>   &_d2dBuf)
    {
        CreateBuffer(_ePicBufferFormat, _d2dBuf.w, _d2dBuf.h);
    } // qPicBuffer::CreateBuffer


    /*******************************************************************************
    * qPicBuffer::ClearBuffer
    *******************************************************************************/
    void qPicBuffer::ClearBuffer()
    {
        if (m_pBuffer != nullptr)
        {
            memset(m_pBuffer, 0, m_u64BufferSize_byte);
        }
    } // qPicBuffer::ClearBuffer


    /*******************************************************************************
    * qPicBuffer::BufferFormat
    *******************************************************************************/
    enumPicBufferFormat qPicBuffer::BufferFormat() const
    {
        return m_ePicBufferFormat;
    } // qPicBuffer::BufferFormat


    /*******************************************************************************
    * qPicBuffer::Dimension
    *******************************************************************************/
    const qDimension2D<s32>& qPicBuffer::Dimension() const
    {
        return m_d2dBuf;
    } // qPicBuffer::Dimension


    /*******************************************************************************
    * qPicBuffer::w
    *******************************************************************************/
    s32 qPicBuffer::w() const
    {
        return m_d2dBuf.w;
    } // qPicBuffer::w


    /*******************************************************************************
    * qPicBuffer::h
    *******************************************************************************/
    s32 qPicBuffer::h() const
    {
        return m_d2dBuf.h;
    } // qPicBuffer::h


    /*******************************************************************************
    * qPicBuffer::AddLayer2Buffer
    *******************************************************************************/
    void qPicBuffer::AddLayer2Buffer(qLayerBase             *_pLayer,                // the layer to add
                                     const qVector2D<s32>   &_v2dBufOrigin_zoom,    // buf-position within the zoomed pic
                                     dbl                    _dZoomFactor) const
    {
        s32             s32LayerX, s32LayerY;
        s32             s32BufX, s32BufY;
        dbl             dOpacity			= _pLayer->GetOpacity();
        dbl             dOpacity1			= 1. - _pLayer->GetOpacity();
        qColor          colNew;

        qRect2D<s32>    rctLayer_zoom	= _pLayer->GetGeometry();
        rctLayer_zoom.Resize(_dZoomFactor);

        s32             s32LayerStartX  = MU<s32>::Clamp (_v2dBufOrigin_zoom.x - rctLayer_zoom.x,
                                                          0, rctLayer_zoom.w - 1);

        s32             s32LayerEndX    = MU<s32>::Clamp (_v2dBufOrigin_zoom.x - rctLayer_zoom.x + m_d2dBuf.w,
                                                          0, rctLayer_zoom.w - 1);

        s32             s32LayerStartY  = MU<s32>::Clamp (_v2dBufOrigin_zoom.y - rctLayer_zoom.y,
                                                          0, rctLayer_zoom.h - 1);

        s32             s32LayerEndY    = MU<s32>::Clamp (_v2dBufOrigin_zoom.y - rctLayer_zoom.x + m_d2dBuf.h,
                                                          0, rctLayer_zoom.h - 1);

        // copy the data to the buffer
        // depends on the buffer format
        switch (m_ePicBufferFormat)
        {
            default:
                break;

            //================================
            // format: ffrrggbb for each pixel
            //================================
            case enumPicBufferFormat::ffrrggbb:
            {
                for (s32BufY=0, s32LayerY=s32LayerStartY; s32LayerY<s32LayerEndY; s32BufY++, s32LayerY++)
                {
                    for (s32BufX=0, s32LayerX=s32LayerStartX; s32LayerX<s32LayerEndX; s32BufX++, s32LayerX++)
                    {
                        // get the pixel in the layer
                        _pLayer->Pixel(static_cast<s32> (static_cast<dbl> (s32LayerX) / _dZoomFactor),
                                       static_cast<s32> (static_cast<dbl> (s32LayerY) / _dZoomFactor),
                                       colNew);

                        // take the alpha value of the pixel and the
                        // opacity of the layer into account
                        colNew.r *= colNew.a * dOpacity;
                        colNew.g *= colNew.a * dOpacity;
                        colNew.b *= colNew.a * dOpacity;

                        u32     *pBuf = DataPointer<u32> (s32BufX, s32BufY);

                        u32     u32PrevR = static_cast<u32> (dOpacity1 * ((*pBuf & 0x00ff0000) >> 16));
                        u32     u32PrevG = static_cast<u32> (dOpacity1 * ((*pBuf & 0x0000ff00) >> 8));
                        u32     u32PrevB = static_cast<u32> (dOpacity1 * (*pBuf & 0x000000ff));

                        u32     u32NewR  = u32PrevR + static_cast<u32> (colNew.r * 0xff);
                        u32     u32NewG  = u32PrevG + static_cast<u32> (colNew.g * 0xff);
                        u32     u32NewB  = u32PrevB + static_cast<u32> (colNew.b * 0xff);

                        *pBuf = 0xff000000 +
                                static_cast<u32> (u32NewR << 16) +
                                static_cast<u32> (u32NewG << 8) +
                                u32NewB;
                    } // for (x..
                } // for (y..

                break;
            } // case enumPicBufferFormat::PicBufFormat_ffrrggbb


            //================================
            // format: aaRRGGBB for each pixel
            //================================
//            case enumPicBufferFormat::PicBufFormat_aarrggbb:
//            {
//                for (s32BufY=0, s32LayerY=s32LayerStartY; s32LayerY<s32LayerEndY; s32BufY++, s32LayerY++)
//                {
//                    for (s32BufX=0, s32LayerX=s32LayerStartX; s32LayerX<s32LayerEndX; s32BufX++, s32LayerX++)
//                    {
//                        // get the pixel in the layer
//                        _pLayer->Pixel(static_cast<s32> (static_cast<dbl> (s32LayerX) / _dZoomFactor),
//                                       static_cast<s32> (static_cast<dbl> (s32LayerY) / _dZoomFactor),
//                                       colNew);

//                        // take the alpha value of the pixel and the
//                        // opacity of the layer into account
//                        colNew.r *= colNew.a * dOpacity;
//                        colNew.g *= colNew.a * dOpacity;
//                        colNew.b *= colNew.a * dOpacity;

//                        u32     *pBuf = DataPointer<u32> (s32BufX, s32BufY);

//                        qRgba_t  tPrevA   = (static_cast<qRgba_t> ((*pBuf & 0xff000000) >> 24)) / 255;
//                        u32     u32PrevR = static_cast<u32> (dOpacity1 * ((*pBuf & 0x00ff0000) >> 16));
//                        u32     u32PrevG = static_cast<u32> (dOpacity1 * ((*pBuf & 0x0000ff00) >> 8));
//                        u32     u32PrevB = static_cast<u32> (dOpacity1 * (*pBuf & 0x000000ff));

//                        u32     u32NewR  = u32PrevR + static_cast<u32> (colNew.r * 0xff);
//                        u32     u32NewG  = u32PrevG + static_cast<u32> (colNew.g * 0xff);
//                        u32     u32NewB  = u32PrevB + static_cast<u32> (colNew.b * 0xff);
//                        u32     u32NewA  = static_cast<u32> (tPrevA*(1. - colNew.a) + colNew.a * 255);

//                        *pBuf = 0x00000000 +
//                                static_cast<u32> (u32NewA << 24) +
//                                static_cast<u32> (u32NewR << 16) +
//                                static_cast<u32> (u32NewG << 8) +
//                                u32NewB;
//                    } // for (x..
//                } // for (y..

//                break;
//        } // case enumPicBufferFormat::PicBufFormat_ffrrggbb


        } // switch (m_ePicBufferFormat)

    } // qPicBuffer::AddLayer2Buffer


    /*******************************************************************************
    * qPicBuffer::ToQImage
    *******************************************************************************/
    // void qPicBuffer::ToQImage(shared_ptr<qLayerStack>   _pLayerStack,
    //                           const qDimension2D<s32>&   _d2dQImage,
    //                           const qVector2D<s32>&      _v2dBufOrigin_zoom,
    //                           dbl                        _dZoomFactor,
    //                           QImage                     *&_pImg)
    // {
    //     ToQImage(_pLayerStack, nullptr, _d2dQImage.w(), _d2dQImage.h(), _v2dBufOrigin_zoom, _dZoomFactor, _pImg);
    // } // qPicBuffer::ToQImage


    /*******************************************************************************
    * qPicBuffer::ToQImage
    *******************************************************************************/
    // void qPicBuffer::ToQImage(shared_ptr<qLayerStack>   _pLayerStack,
    //                           s32                       _s32QImageW,
    //                           s32                       _s32QImageH,
    //                           const qVector2D<s32>&     _v2dBufOrigin_zoom,
    //                           dbl                       _dZoomFactor,
    //                           QImage*&                  _pImg)
    // {
    //     ToQImage(_pLayerStack, nullptr, _s32QImageW, _s32QImageH, _v2dBufOrigin_zoom, _dZoomFactor, _pImg);
    // } // qPicBuffer::ToQImage


    /*******************************************************************************
    * qPicBuffer::ToQImage
    *******************************************************************************/
    // void qPicBuffer::ToQImage(shared_ptr<qLayerI>       _pLayer,
    //                           const qDimension2D<s32>&  _d2dQImage,
    //                           const qVector2D<s32>&     _v2dBufOrigin_zoom,
    //                           dbl                       _dZoomFactor,
    //                           QImage*&                  _pImg)
    // {
    //     ToQImage(nullptr, _pLayer, _d2dQImage.w(), _d2dQImage.h(), _v2dBufOrigin_zoom, _dZoomFactor, _pImg);
    // } // qPicBuffer::ToQImage


    /*******************************************************************************
    * qPicBuffer::ToQImage
    *******************************************************************************/
    // void qPicBuffer::ToQImage(shared_ptr<qLayerI>   _pLayer,
    //                          s32                    _s32QImageW,
    //                          s32                    _s32QImageH,
    //                          const qVector2D<s32>&  _v2dBufOrigin_zoom,
    //                          dbl                    _dZoomFactor,
    //                          QImage*&               _pImg)
    // {
    //     ToQImage(nullptr, _pLayer, _s32QImageW, _s32QImageH, _v2dBufOrigin_zoom, _dZoomFactor, _pImg);
    // } // qPicBuffer::ToQImage


    /*******************************************************************************
    * qPicBuffer::ToQImage
    *******************************************************************************/
    void qPicBuffer::ToQImage(shared_ptr<qLayerStack>   _pLayerStack,
                              s32                       _s32QImageW,
                              s32                       _s32QImageH,
                              const qVector2D<s32>      &_v2dBufOrigin_zoom,
                              dbl                       _dZoomFactor,
                              QImage                    *&_pImg)
    {
        bool bValid = true;

        switch (_pLayerStack->Type())
        {
            default:
                bValid = false;
                break;

            case enumLayerType::Rgb_8:
            {
                CreateBuffer(enumPicBufferFormat::ffrrggbb, _s32QImageW, _s32QImageH);
                break;
            } // case enumLayerType::RGB_8

//            case enumLayerType::ARGB_8:
//            {
//                CreateBuffer(enumPicBufferFormat::PicBufFormat_aarrggbb, _s32QImageW, _s32QImageH);
//                break;
//            } // case enumLayerType::RGB_8
        } // switch (eLayerType)

        if (bValid)
        {
            // add the layerstack to the buffer
            // fill the buffer with the current pic data
            for (const unique_ptr<qLayerBase> &pLayer : *_pLayerStack)
            {
                if (pLayer->Visible())
                {
                    AddLayer2Buffer(pLayer.get(), _v2dBufOrigin_zoom, _dZoomFactor);
                }
            }

            // create the QImage
            switch (_pLayerStack->Type())
            {
                default:
                    break;

                case enumLayerType::Rgb_8:
                {
                    _pImg = new QImage(DataPointer<u8>(), _s32QImageW, _s32QImageH, QImage::Format_RGB32);
                    break;
                } // case enumLayerType::RGB_8

//                case enumLayerType::ARGB_8:
//                {
//                    _pImg = new QImage(DataPointer<u8>(), _s32QImageW, _s32QImageH, QImage::Format_ARGB32);
//                    break;
//                } // case enumLayerType::RGB_8
            }
        }
    } // qPicBuffer::ToQImage

} // namespace qLib
