/*******************************************************************************
* \file aPicBuffer.cpp
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
#include "aColor.h"

#include "aRect2D.h"

#include "aLayer_i.h"
#include "aPicBuffer.h"
#include "aLayerStack.h"

using namespace aLib::aUtil;


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aPic {


/*******************************************************************************
* aPicBuffer::aPicBuffer
*******************************************************************************/
aPicBuffer::aPicBuffer()
{
} // aPicBuffer::aPicBuffer


/*******************************************************************************
* aPicBuffer::~aPicBuffer
*******************************************************************************/
aPicBuffer::~aPicBuffer()
{
    delete m_pBuffer;
} // aPicBuffer::~aPicBuffer


/*******************************************************************************
* aPicBuffer::createBuffer
*******************************************************************************/
void aPicBuffer::createBuffer(enumPicBufferFormat   _ePicBufferFormat,
                              s32                   _s32W,
                              s32                   _s32H)
{
    m_ePicBufferFormat  = _ePicBufferFormat;

    // copy the size of the buffer
    m_d2dBuf.set(_s32W, _s32H);

    // calculate format specific members
    switch (m_ePicBufferFormat)
    {
        default:
            break;

        case enumPicBufferFormat::ffrrggbb:
        //case enumPicBufferFormat::PicBufFormat_aarrggbb:
        {
            m_u64PixelSize_byte = 4;
            m_s64RowSize_byte   = m_d2dBuf.w() * m_u64PixelSize_byte;
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
    m_u64BufferSize_byte = m_s64RowSize_byte * m_d2dBuf.h();

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
} // aPicBuffer::createBuffer


/*******************************************************************************
* aPicBuffer::createBuffer
*******************************************************************************/
void aPicBuffer::createBuffer(enumPicBufferFormat       _ePicBufferFormat,
                              const aDimension2D<s32>   &_d2dBuf)
{
    createBuffer(_ePicBufferFormat, _d2dBuf.w(), _d2dBuf.h());
} // aPicBuffer::createBuffer


/*******************************************************************************
* aPicBuffer::clearBuffer
*******************************************************************************/
void aPicBuffer::clearBuffer()
{
    if (m_pBuffer != nullptr)
    {
        memset(m_pBuffer, 0, m_u64BufferSize_byte);
    }
} // aPicBuffer::clearBuffer


/*******************************************************************************
* aPicBuffer::bufferFormat
*******************************************************************************/
enumPicBufferFormat aPicBuffer::bufferFormat() const
{
    return m_ePicBufferFormat;
} // aPicBuffer::bufferFormat


/*******************************************************************************
* aPicBuffer::dimension
*******************************************************************************/
const aDimension2D<s32>& aPicBuffer::dimension() const
{
    return m_d2dBuf;
} // aPicBuffer::dimension


/*******************************************************************************
* aPicBuffer::w
*******************************************************************************/
s32 aPicBuffer::w() const
{
    return m_d2dBuf.w();
} // aPicBuffer::w


/*******************************************************************************
* aPicBuffer::h
*******************************************************************************/
s32 aPicBuffer::h() const
{
    return m_d2dBuf.h();
} // aPicBuffer::h


/*******************************************************************************
* aPicBuffer::dataPointer
*******************************************************************************/
template <class T>
T* aPicBuffer::dataPointer() const
{
    return (T*) (m_pBuffer);
} // aPicBuffer::dataPointer


/*******************************************************************************
* aPicBuffer::dataPointer
*******************************************************************************/
template <class T>
T* aPicBuffer::dataPointer(s32  _s32X,
                           s32  _s32Y) const
{
    return (T*) (m_pBuffer + _s32Y*m_s64RowSize_byte + _s32X*m_u64PixelSize_byte);
} // aPicBuffer::dataPointer


/*******************************************************************************
* aPicBuffer::addLayer2Buffer
*******************************************************************************/
void aPicBuffer::addLayer2Buffer(aLayerI                *_pLayer,                // the layer to add
                                 const aPoint2D<s32>   &_v2dBufOrigin_zoom,    // buf-position within the zoomed pic
                                 dbl                    _dZoomFactor) const
{
    s32             s32LayerX, s32LayerY;
    s32             s32BufX, s32BufY;
    dbl             dOpacity			= _pLayer->opacity();
    dbl             dOpacity1			= 1. - _pLayer->opacity();
    aColor          rgbaNew;

    aRect2D<s32>    rctLayer_zoom	= _pLayer->geometry();
    rctLayer_zoom.resize(_dZoomFactor);

    s32             s32LayerStartX  = aUtil::clamp<s32> (_v2dBufOrigin_zoom.x() - rctLayer_zoom.x(),
                                                         0, rctLayer_zoom.w() - 1);

    s32             s32LayerEndX    = aUtil::clamp<s32> (_v2dBufOrigin_zoom.x() - rctLayer_zoom.x() + m_d2dBuf.w(),
                                                         0, rctLayer_zoom.w() - 1);

    s32             s32LayerStartY  = aUtil::clamp<s32> (_v2dBufOrigin_zoom.y() - rctLayer_zoom.y(),
                                                         0, rctLayer_zoom.h() - 1);

    s32             s32LayerEndY    = aUtil::clamp<s32> (_v2dBufOrigin_zoom.y() - rctLayer_zoom.x() + m_d2dBuf.h(),
                                                         0, rctLayer_zoom.h() - 1);

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
                    _pLayer->pixel(static_cast<s32> (static_cast<dbl> (s32LayerX) / _dZoomFactor),
                                   static_cast<s32> (static_cast<dbl> (s32LayerY) / _dZoomFactor),
                                   rgbaNew);

                    // take the alpha value of the pixel and the
                    // opacity of the layer into account
                    rgbaNew *= dOpacity;

                    u32     *pBuf = dataPointer<u32> (s32BufX, s32BufY);

                    u32     u32PrevR = static_cast<u32> (dOpacity1 * ((*pBuf & 0x00ff0000) >> 16));
                    u32     u32PrevG = static_cast<u32> (dOpacity1 * ((*pBuf & 0x0000ff00) >> 8));
                    u32     u32PrevB = static_cast<u32> (dOpacity1 * (*pBuf & 0x000000ff));

                    u32     u32NewR  = u32PrevR + static_cast<u32> (rgbaNew.r() * 0xff);
                    u32     u32NewG  = u32PrevG + static_cast<u32> (rgbaNew.g() * 0xff);
                    u32     u32NewB  = u32PrevB + static_cast<u32> (rgbaNew.b() * 0xff);

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
//                                       qRgbaNew);

//                        // take the alpha value of the pixel and the
//                        // opacity of the layer into account
//                        qRgbaNew.r *= qRgbaNew.a * dOpacity;
//                        qRgbaNew.g *= qRgbaNew.a * dOpacity;
//                        qRgbaNew.b *= qRgbaNew.a * dOpacity;

//                        u32     *pBuf = DataPointer<u32> (s32BufX, s32BufY);

//                        qRgba_t  tPrevA   = (static_cast<qRgba_t> ((*pBuf & 0xff000000) >> 24)) / 255;
//                        u32     u32PrevR = static_cast<u32> (dOpacity1 * ((*pBuf & 0x00ff0000) >> 16));
//                        u32     u32PrevG = static_cast<u32> (dOpacity1 * ((*pBuf & 0x0000ff00) >> 8));
//                        u32     u32PrevB = static_cast<u32> (dOpacity1 * (*pBuf & 0x000000ff));

//                        u32     u32NewR  = u32PrevR + static_cast<u32> (qRgbaNew.r * 0xff);
//                        u32     u32NewG  = u32PrevG + static_cast<u32> (qRgbaNew.g * 0xff);
//                        u32     u32NewB  = u32PrevB + static_cast<u32> (qRgbaNew.b * 0xff);
//                        u32     u32NewA  = static_cast<u32> (tPrevA*(1. - qRgbaNew.a) + qRgbaNew.a * 255);

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

} // aPicBuffer::addLayer2Buffer


/*******************************************************************************
* aPicBuffer::ToQImage
*******************************************************************************/
// void aPicBuffer::ToQImage(shared_ptr<qLayerStack>   _pLayerStack,
//                           const aDimension2D<s32>&   _d2dQImage,
//                           const aPoint2D<s32>&      _v2dBufOrigin_zoom,
//                           dbl                        _dZoomFactor,
//                           QImage                     *&_pImg)
// {
//     ToQImage(_pLayerStack, nullptr, _d2dQImage.w(), _d2dQImage.h(), _v2dBufOrigin_zoom, _dZoomFactor, _pImg);
// } // aPicBuffer::ToQImage


/*******************************************************************************
* aPicBuffer::ToQImage
*******************************************************************************/
// void aPicBuffer::ToQImage(shared_ptr<qLayerStack>   _pLayerStack,
//                           s32                       _s32QImageW,
//                           s32                       _s32QImageH,
//                           const aPoint2D<s32>&     _v2dBufOrigin_zoom,
//                           dbl                       _dZoomFactor,
//                           QImage*&                  _pImg)
// {
//     ToQImage(_pLayerStack, nullptr, _s32QImageW, _s32QImageH, _v2dBufOrigin_zoom, _dZoomFactor, _pImg);
// } // aPicBuffer::ToQImage


/*******************************************************************************
* aPicBuffer::ToQImage
*******************************************************************************/
// void aPicBuffer::ToQImage(shared_ptr<aLayerI>       _pLayer,
//                           const aDimension2D<s32>&  _d2dQImage,
//                           const aPoint2D<s32>&     _v2dBufOrigin_zoom,
//                           dbl                       _dZoomFactor,
//                           QImage*&                  _pImg)
// {
//     ToQImage(nullptr, _pLayer, _d2dQImage.w(), _d2dQImage.h(), _v2dBufOrigin_zoom, _dZoomFactor, _pImg);
// } // aPicBuffer::ToQImage


/*******************************************************************************
* aPicBuffer::ToQImage
*******************************************************************************/
// void aPicBuffer::ToQImage(shared_ptr<aLayerI>   _pLayer,
//                          s32                    _s32QImageW,
//                          s32                    _s32QImageH,
//                          const aPoint2D<s32>&  _v2dBufOrigin_zoom,
//                          dbl                    _dZoomFactor,
//                          QImage*&               _pImg)
// {
//     ToQImage(nullptr, _pLayer, _s32QImageW, _s32QImageH, _v2dBufOrigin_zoom, _dZoomFactor, _pImg);
// } // aPicBuffer::ToQImage


/*******************************************************************************
* aPicBuffer::toQImage
*******************************************************************************/
void aPicBuffer::toQImage(shared_ptr<aLayerStack>   _pLayerStack,
                          s32                       _s32QImageW,
                          s32                       _s32QImageH,
                          const aPoint2D<s32>      &_v2dBufOrigin_zoom,
                          dbl                       _dZoomFactor,
                          QImage                    *&_pImg)
{
    bool bValid = true;

    switch (_pLayerStack->type())
    {
        default:
            bValid = false;
            break;

        case enumLayerType::Rgb_8:
        {
            createBuffer(enumPicBufferFormat::ffrrggbb, _s32QImageW, _s32QImageH);
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
        for (const unique_ptr<aLayerI> &pLayer : *_pLayerStack)
        {
            if (pLayer->isVisible())
            {
                addLayer2Buffer(pLayer.get(), _v2dBufOrigin_zoom, _dZoomFactor);
            }
        }

        // create the QImage
        switch (_pLayerStack->type())
        {
            default:
                break;

            case enumLayerType::Rgb_8:
            {
                _pImg = new QImage(dataPointer<u8>(), _s32QImageW, _s32QImageH, QImage::Format_RGB32);
                break;
            } // case enumLayerType::RGB_8

//                case enumLayerType::ARGB_8:
//                {
//                    _pImg = new QImage(DataPointer<u8>(), _s32QImageW, _s32QImageH, QImage::Format_ARGB32);
//                    break;
//                } // case enumLayerType::RGB_8
        }
    }
} // aPicBuffer::toQImage


} // namespace aPic
} // namespace aLib
