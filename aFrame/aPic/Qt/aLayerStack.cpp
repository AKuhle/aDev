/*******************************************************************************
* \file aLayerStack.h
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
#ifdef _USE_QT_



/*******************************************************************************
* includes
*******************************************************************************/
#include "aLayerStack.h"
#include "aPath.h"
#include "aLayer_rgba.h"

using namespace aFrame::aUtil;


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aFrame {
namespace aPic {


/*******************************************************************************
* aLayerStack::aLayerStack
*******************************************************************************/
aLayerStack::aLayerStack()
{
} // aLayerStack::aLayerStack


/*******************************************************************************
* aLayerStack::~aLayerStack
*******************************************************************************/
aLayerStack::~aLayerStack()
{
} // aLayerStack::~aLayerStack


/*******************************************************************************
* aLayerStack::load
*******************************************************************************/
bool aLayerStack::load(const aPath  &_sFileName)
{
    QImage  img;
    QColor  col;

    // try to load the image
    img.load(_sFileName.canonicalPath().toQString());

    switch (img.format())
    {
        default:                                        return false;

        case QImage::Format_Invalid:                    return false;
        case QImage::Format_Mono:                       return false;
        case QImage::Format_MonoLSB:                    return false;
        case QImage::Format_Indexed8:                   return false;
        case QImage::Format_RGB32:                      return loadRgb_8bit(img);
        case QImage::Format_ARGB32:                     return false;
        case QImage::Format_ARGB32_Premultiplied:       return false;
        case QImage::Format_RGB16:                      return false;
        case QImage::Format_ARGB8565_Premultiplied:     return false;
        case QImage::Format_RGB666:                     return false;
        case QImage::Format_ARGB6666_Premultiplied:     return false;
        case QImage::Format_RGB555:                     return false;
        case QImage::Format_ARGB8555_Premultiplied:     return false;
        case QImage::Format_RGB888:                     return false;
        case QImage::Format_RGB444:                     return false;
        case QImage::Format_ARGB4444_Premultiplied:     return false;
        case QImage::Format_RGBA8888_Premultiplied :    return false;
        case QImage::Format_A2BGR30_Premultiplied:      return false;
        case QImage::Format_RGB30:                      return false;
        case QImage::Format_A2RGB30_Premultiplied:      return false;
        case QImage::Format_Grayscale8:                 return false;
        case QImage::Format_Grayscale16:                return false;
        case QImage::Format_RGBX64:                     return false;
        case QImage::Format_RGBA64:                     return false;
        case QImage::Format_RGBA64_Premultiplied:       return false;
        case QImage::Format_BGR888:                     return false;
        case QImage::Format_RGBX16FPx4:                 return false;
        case QImage::Format_RGBA16FPx4:                 return false;
        case QImage::Format_RGBA16FPx4_Premultiplied:   return false;
        case QImage::Format_RGBX32FPx4:                 return false;
        case QImage::Format_RGBA32FPx4:                 return false;
        case QImage::Format_RGBA32FPx4_Premultiplied:   return false;
    } // switch (img.format())

    return false;
} // aLayerStack::load


/*******************************************************************************
* aLayerStack::loadRgb_8bit
*******************************************************************************/
bool aLayerStack::loadRgb_8bit(const QImage &_img)
{
    s32                     s32W    = _img.width();
    s32                     s32H    = _img.height();
    shared_ptr<aLayerRgba>  pLayer  = make_shared<aLayerRgba> (s32W, s32H);
    QColor                  col;

    for (s32 y = 0; y < s32H; y++)
    {
        if (y % 100 == 0)
        {
            if (y == 50000)
                y = y + 1;
        }

        for (s32 x = 0; x < s32W; x++)
        {
            col = _img.pixel(x, y);
        }
    }

    return true;
} // aLayerStack::loadRgb_8bit


/*******************************************************************************
* aLayerStack::getQImage
*******************************************************************************/
shared_ptr<QImage> aLayerStack::getQImage() const
{
    return nullptr;
} // aLayerStack::getQImage


} // namespace aPic
} // namespace aFrame


#endif // _USE_QT_
