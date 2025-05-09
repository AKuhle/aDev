/*******************************************************************************
* \file layer_Rgb8.h
* \author Andreas Kuhlewind
*
* \brief
*
*  Detailed description starts here.
*******************************************************************************/


/*******************************************************************************
* includes
*******************************************************************************/
#include "aLayer_rgb8.h"
#include "aColor.h"

using namespace aLib::aUtil;



/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aPic {


/*******************************************************************************
* aLayerRgb8::aLayerRgb8
*******************************************************************************/
aLayerRgb8::aLayerRgb8(const aRect2D<s32>  &_rctGeometry,
                       aString             _sName           /*= ""*/,
                       bool                _bVisible        /*= true*/,
                       dbl                 _dOpacity        /*= 1.*/)
: aLayerI(enumLayerType::Rgb_8, _sName, _rctGeometry, _bVisible, _dOpacity),
  m_pR(new aChannel<u8> (_rctGeometry.dimension())),
  m_pG(new aChannel<u8> (_rctGeometry.dimension())),
  m_pB(new aChannel<u8> (_rctGeometry.dimension())),
  m_pA(new aChannel<u8> (_rctGeometry.dimension()))
{
} // aLayerRgb8::aLayerRgb8


/*******************************************************************************
* aLayerRgb8::aLayerRgb8
*******************************************************************************/
aLayerRgb8::aLayerRgb8(s32                  _w,
                       s32                  _h,
                       aString             _sName           /*= ""*/,
                       bool                _bVisible        /*= true*/,
                       dbl                 _dOpacity        /*= 1.*/)
: aLayerI(enumLayerType::Rgb_8, _sName, aRect2D<s32> (0, 0, _w, _h), _bVisible, _dOpacity),
  m_pR(new aChannel<u8> (_w, _h)),
  m_pG(new aChannel<u8> (_w, _h)),
  m_pB(new aChannel<u8> (_w, _h)),
  m_pA(new aChannel<u8> (_w, _h))
{
} // aLayerRgb8::LayerRgb8




/*******************************************************************************
* aLayerRgb8::aLayerRgb8
*******************************************************************************/
aLayerRgb8::aLayerRgb8(s32                  _x,
                       s32                  _y,
                       s32                  _w,
                       s32                  _h,
                       aString             _sName           /*= ""*/,
                       bool                _bVisible        /*= true*/,
                       dbl                 _dOpacity        /*= 1.*/)
: aLayerI(enumLayerType::Rgb_8, _sName, aRect2D<s32> (_x, _y, _w, _h), _bVisible, _dOpacity),
  m_pR(new aChannel<u8> (_w, _h)),
  m_pG(new aChannel<u8> (_w, _h)),
  m_pB(new aChannel<u8> (_w, _h)),
  m_pA(new aChannel<u8> (_w, _h))
{
} // aLayerRgb8::LayerRgb8


/*******************************************************************************
* aLayerRgb8::~aLayerRgb8
*******************************************************************************/
aLayerRgb8::~aLayerRgb8()
{
} // aLayerRgb8::~aLayerRgb8


/*******************************************************************************
* aLayerRgb8::createClone
*******************************************************************************/
unique_ptr<aLayerI> aLayerRgb8::createClone(bool _bCopyData) const
{
    unique_ptr<aLayerRgb8>	pNew = make_unique<aLayerRgb8> (geometry(), name(), isVisible(), opacity());

    if (_bCopyData)
    {
        pNew->m_pR->copyFromChannel(m_pR);
        pNew->m_pG->copyFromChannel(m_pG);
        pNew->m_pB->copyFromChannel(m_pB);
        pNew->m_pA->copyFromChannel(m_pA);
    }

    return pNew;
} // aLayerRgb8::createClone


/*******************************************************************************
* aLayerRgb8::createClone
*******************************************************************************/
unique_ptr<aLayerI> aLayerRgb8::createClone(s32 _s32NewW,
                                            s32 _s32NewH) const
{
    unique_ptr<aLayerRgb8>	pNew = make_unique<aLayerRgb8> (geometry().x(), geometry().y(), _s32NewW, _s32NewH, name(), isVisible(), opacity());

    return pNew;
} // aLayerRgb8::createClone


/*******************************************************************************
* aLayerRgb8::clear
*******************************************************************************/
void aLayerRgb8::clear()
{
    m_pR->clear();
    m_pG->clear();
    m_pB->clear();
    m_pA->clear();
} // aLayerRgb8::clear


/*******************************************************************************
* aLayerRgb8::pixel
*******************************************************************************/
void aLayerRgb8::pixel(s32       _x,
                       s32       _y,
                       aColor    &_rgba) const
{
    s32		offset = _y * w() + _x;

    _rgba.set(static_cast<color_t> (m_pR->m_pData[offset]) / 0xff,
              static_cast<color_t> (m_pG->m_pData[offset]) / 0xff,
              static_cast<color_t> (m_pB->m_pData[offset]) / 0xff,
              static_cast<color_t> (m_pA->m_pData[offset]) / 0xff);
} // aLayerRgb8::pixel


/*******************************************************************************
* aLayerRgb8::setPixel
*******************************************************************************/
void aLayerRgb8::setPixel(s32            _x,
                          s32            _y,
                          const aColor   &_rgba)
{
    s32		offset = _y * w() + _x;

    m_pR->m_pData[offset] = static_cast<u8> (_rgba.r() * 0xff);
    m_pG->m_pData[offset] = static_cast<u8> (_rgba.g() * 0xff);
    m_pB->m_pData[offset] = static_cast<u8> (_rgba.b() * 0xff);
    m_pA->m_pData[offset] = static_cast<u8> (_rgba.a() * 0xff);
} // aLayerRgb8::setPixel


/*******************************************************************************
* aLayerRgb8::setPixel
*******************************************************************************/
void aLayerRgb8::setPixel(s32       _x,
                          s32       _y,
                          color_t   _r,
                          color_t   _g,
                          color_t   _b,
                          color_t   _a)
{
    s32		offset = _y * w() + _x;

    m_pR->m_pData[offset] = static_cast<u8> (_r * 0xff);
    m_pG->m_pData[offset] = static_cast<u8> (_g * 0xff);
    m_pB->m_pData[offset] = static_cast<u8> (_b * 0xff);
    m_pA->m_pData[offset] = static_cast<u8> (_a * 0xff);
} // aLayerRgb8::setPixel


} // namespace aPic
} // namespace aLib
