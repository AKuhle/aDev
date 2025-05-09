/*******************************************************************************
* \file qPicDefs.h
* \author Andreas Kuhlewind
*
* \brief
*
*  Detailed description starts here.
*******************************************************************************/
#pragma once


/*******************************************************************************
* includes
*******************************************************************************/


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aPic {


/*******************************************************************************
* enums
*******************************************************************************/
enum class enumLayerType
{
    None,
    //BITMAP,          // bitmap format
    //GRAYSCALE_8,     // grayscale format, 8 bit
    //GRAYSCALE_16,    // grayscale format, 16 bit
    Rgb_8           // 8 bits per channel
    //ARGB_8        // 8 bits per channel
    //RGB_16           // 16 bit per channel
}; //enum class enumLayerType


enum class enumPicBufferFormat
{
    None,
    ffrrggbb        // 8 bit rgb
//        //PicBufFormat_aarrggbb               // 8 bit argb
//        PicBufFormat_aaaabbbbggggrrrr,      // 16 bit rgb
//        PicBufFormat_graygray,              // 8 bit grayscale
//        //PicBufFormat_graygraygraygray,      // 16 bit grayscale
}; //enum class enumPicBufferFormat


/*******************************************************************************
* classes
*******************************************************************************/
template <typename T> class aChannel;

class aLayerI;
class aLayerRgb8;
class aPicBuffer;
class aLayerStack;

} // namespace aPic
} // namespace aLib
