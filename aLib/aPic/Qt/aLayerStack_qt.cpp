/*******************************************************************************
* \file aLayerStack_Qt.cpp
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
#include <QImage>

#include "aLayerStack.h"
#include "aLayer_rgb8.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aPic {


/*******************************************************************************
* aLayerStack::loadFromFile
*******************************************************************************/
bool aLayerStack::loadFromFile(const aString &_sFileName)
//                                   qProgress*      _pProgressCb /* = nullptr*/)
{
    QImage              img;
    bool                bSuccess;
    enumLayerType       eLayerType { enumLayerType::None };

    aString             sPath;
    aString             sExt;
    aString             sFullName;

    // if (_pProgressCb != nullptr)
    // {
    //     _pProgressCb->OpenProgressDisplay("loading file...");
    // }

    // split the filename
    //qFile::SplitPath(_sFileName, sPath, m_sName, sExt, sFullName);

    // load the file
    QString qs = _sFileName.toQString();
    bSuccess = img.load(qs);

    // if the picture could be loaded successfully => generate layers
    if (bSuccess)
    {
        switch (img.format())
        {
            default:                                        eLayerType = enumLayerType::None;       break;
            case QImage::Format_Invalid:                    eLayerType = enumLayerType::None;       break;
            case QImage::Format_Mono:                       eLayerType = enumLayerType::None;       break;
            case QImage::Format_MonoLSB:                    eLayerType = enumLayerType::None;       break;
            case QImage::Format_Indexed8:                   eLayerType = enumLayerType::None;       break;
            case QImage::Format_RGB32:                      eLayerType = enumLayerType::Rgb_8;      break;
            case QImage::Format_ARGB32:                     eLayerType = enumLayerType::None;       break;
            case QImage::Format_ARGB32_Premultiplied:       eLayerType = enumLayerType::None;       break;
            case QImage::Format_RGB16:                      eLayerType = enumLayerType::None;       break;
            case QImage::Format_ARGB8565_Premultiplied:     eLayerType = enumLayerType::None;       break;
            case QImage::Format_RGB666:                     eLayerType = enumLayerType::None;       break;
            case QImage::Format_ARGB6666_Premultiplied:     eLayerType = enumLayerType::None;       break;
            case QImage::Format_RGB555:                     eLayerType = enumLayerType::None;       break;
            case QImage::Format_ARGB8555_Premultiplied:     eLayerType = enumLayerType::None;       break;
            case QImage::Format_RGB888:                     eLayerType = enumLayerType::None;       break;
            case QImage::Format_RGB444:                     eLayerType = enumLayerType::None;       break;
            case QImage::Format_ARGB4444_Premultiplied:     eLayerType = enumLayerType::None;       break;
            case QImage::Format_RGBX8888:                   eLayerType = enumLayerType::None;       break;
            case QImage::Format_RGBA8888:                   eLayerType = enumLayerType::None;       break;
            case QImage::Format_RGBA8888_Premultiplied:     eLayerType = enumLayerType::None;       break;
            case QImage::Format_BGR30:                      eLayerType = enumLayerType::None;       break;
            case QImage::Format_A2BGR30_Premultiplied:      eLayerType = enumLayerType::None;       break;
            case QImage::Format_RGB30:                      eLayerType = enumLayerType::None;       break;
            case QImage::Format_A2RGB30_Premultiplied:      eLayerType = enumLayerType::None;       break;
            case QImage::Format_Alpha8:                     eLayerType = enumLayerType::None;       break;
            case QImage::Format_Grayscale8:                 eLayerType = enumLayerType::None;       break;
            case QImage::Format_Grayscale16:                eLayerType = enumLayerType::None;       break;
            case QImage::Format_RGBX64:                     eLayerType = enumLayerType::None;       break;
            case QImage::Format_RGBA64:                     eLayerType = enumLayerType::None;       break;
            case QImage::Format_RGBA64_Premultiplied:       eLayerType = enumLayerType::None;       break;
            case QImage::Format_BGR888:                     eLayerType = enumLayerType::None;       break;
        } // switch (img.format())

        switch (eLayerType)
        {
            default:
                break;

            case enumLayerType::Rgb_8:
            {
                // clear this layer stack
                removeAllLayers();

                m_eType = enumLayerType::Rgb_8;
                m_d2dDimension.set(img.width(), img.height());

                unique_ptr<aLayerRgb8>  pLayer = make_unique<aLayerRgb8> (w(), h());
                QColor                  col;
                s32                     x, y;

                // if (_pProgressCb != nullptr)
                // {
                //     _pProgressCb->ChangeProgressValues(0, h(), 0);
                // }

                for (y = 0; y < h(); y++)
                {
                    for (x = 0; x < w(); x++)
                    {
                        col = img.pixelColor(x, y);

                        pLayer->setPixel(x, y,
                                         col.redF(), col.greenF(), col.blueF(), 1);
                    } // for (x=0; x<w; x++)

                    // if (_pProgressCb != nullptr)
                    // {
                    //     _pProgressCb->IncrementProgressValue(1);
                    //     for (int i = 0; i < 30000; i++)
                    //     {
                    //         for (int j = Min(i, 1); j < 10; j++)
                    //         {
                    //             if (i == j)
                    //             {
                    //                 y = y + Min(y, 0);
                    //             }
                    //         }
                    //     }
                    // }
                } // for (y=0; y<h; y++)

                addLayer(std::move(pLayer));
                break;
            }

//                case enumLayerType::ARGB_8:
//                {
//                    // clear this layer stack
//                    Clear();

//                    m_eLayerType = enumLayerType::ARGB_8;
//                    m_s2dDimension.Set(img.width(), img.height());

//                    shared_ptr<LayerRgb8>   pLayer(new LayerRgb8(W(), H()));
//                    QColor                  col;
//                    s32                     x, y;

//                    for (y = 0; y < H(); y++)
//                    {
//                        for (x = 0; x < W(); x++)
//                        {
//                            col = img.pixelColor(x, y);

//                            //pLayer->SetPixel(x, y,
//                            //                 col.redF(), col.greenF(), col.blueF(), 1.);
//                            pLayer->SetPixel(x, y,
//                                             col.redF(), col.greenF(), col.blueF(), col.alphaF());
//                        } // for (x=0; x<w; x++)
//                    } // for (y=0; y<h; y++)

//                    AddLayer(pLayer);
//                    break;
//                }
        } // switch

    } // if (bSuccess)

    // if (_pProgressCb != nullptr)
    // {
    //     _pProgressCb->CloseProgressDisplay();
    // }

    return bSuccess;
} // aLayerStack::loadFromFile


} // namespace aPic
} // namespace aLib

#endif // _USE_QT_
