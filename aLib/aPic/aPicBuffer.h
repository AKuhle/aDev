/*******************************************************************************
* \file aPicBuffer.h
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
#ifdef _USE_QT_
    #include "QImage"
#endif // _USE_QT_


#include "aLib_def.h"
#include "qPicDefs.h"

#include "aDimension2D.h"
#include "aPoint2D.h"

using namespace std;
using namespace aLib::aMath;


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aPic {



/*******************************************************************************
* class aPicBuffer
*******************************************************************************/
class aPicBuffer
{
    private:
        enumPicBufferFormat     m_ePicBufferFormat          { enumPicBufferFormat::None };
        aDimension2D<s32>       m_d2dBuf;

        u64                     m_u64PixelSize_byte         { 0 };
        u64                     m_s64RowSize_byte			{ 0 };
        u64                     m_u64BufferSize_byte		{ 0 };
        u64                     m_u64MaxBufferSize_byte		{ 0 };
        u8                      *m_pBuffer					{ nullptr };

    public:
        aPicBuffer();
        virtual ~aPicBuffer();

        // existing buffer will be reused
        void                        createBuffer(enumPicBufferFormat  _ePicBufferFormat,
                                                 s32                  _s32W,
                                                 s32                  _s32H);

        void                        createBuffer(enumPicBufferFormat        _ePicBufferFormat,
                                                 const aDimension2D<s32>    &_d2dBuf);

        void                        clearBuffer();

        enumPicBufferFormat         bufferFormat() const;
        const aDimension2D<s32>&    dimension() const;
        s32                         w() const;
        s32                         h() const;

        template <class T>
        T*                          dataPointer() const;

        template <class T>
        T*                          dataPointer(s32  _s32X,
                                                s32  _s32Y) const;

        void                        addLayer2Buffer(aLayerI                 *_pLayer,                // the layer to add
                                                    const aPoint2D<s32>    &_v2dBufOrigin_zoom,    // buf-position within the zoomed pic
                                                    dbl                     _dZoomFactor) const;    // the zoomfactor

        // void                        ToQImage(shared_ptr<qLayerStack>    _pLayerStack,
        //                                      s32                        _s32QImageW,
        //                                      s32                        _s32QImageH,
        //                                      const aPoint2D<s32>       &_v2dBufOrigin_zoom,
        //                                      dbl                        _dZoomFactor,
        //                                      QImage                     *&_pImg);

        // void                        ToQImage(shared_ptr<qLayerStack>    _pLayerStack,
        //                                      const aDimension2D<s32>    &_d2dQImage,
        //                                      const aPoint2D<s32>       &_v2dBufOrigin_zoom,
        //                                      const dbl                  _dZoomFactor,
        //                                      QImage                     *&_pImg);

        // void                        ToQImage(shared_ptr<aLayerI>    _pLayer,
        //                                      s32                    _s32QImageW,
        //                                      s32                    _s32QImageH,
        //                                      const aPoint2D<s32>   &_v2dBufOrigin_zoom,
        //                                      dbl                    _dZoomFactor,
        //                                      QImage                 *&_pImg);

        // void                        ToQImage(shared_ptr<aLayerI>        _pLayer,
        //                                      const aDimension2D<s32>    &_d2dQImage,
        //                                      const aPoint2D<s32>       &_v2dBufOrigin_zoom,
        //                                      const dbl                  _dZoomFactor,
        //                                      QImage                     *&_pImg);

        #ifdef _USE_QT_
        void                        toQImage(shared_ptr<aLayerStack>    _pLayerStack,
                                             s32                        _s32QImageW,
                                             s32                        _s32QImageH,
                                             const aPoint2D<s32>       &_v2dBufOrigin_zoom,
                                             dbl                        _dZoomFactor,
                                             QImage                     *&_pImg);
        #endif // _USE_QT_

}; // class aPicBuffer


} // namespace aPic
} // namespace aLib
