/*******************************************************************************
* \file aColor.cpp
* \author Andreas Kuhlewind
*
* \brief
*
*  Detailed description starts here.
*******************************************************************************/


/*******************************************************************************
* includes
*******************************************************************************/
#include "aColor.h"
#include "aHelper.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aUtil {


/*******************************************************************************
* aColor::aColor
*******************************************************************************/
aColor::aColor(const color_t _r,
               const color_t _g,
               const color_t _b,
               const color_t _a)
: m_r(_r),
  m_g(_g),
  m_b(_b),
  m_a(_a)
{
} // aColor::aColor


/*******************************************************************************
* aColor::aColor
*******************************************************************************/
aColor::aColor(const aColor	&_rhs)
{
    m_r = _rhs.m_r;
    m_g = _rhs.m_g;
    m_b = _rhs.m_b;
    m_a = _rhs.m_a;
} // aColor::aColor


/*******************************************************************************
* aColor::aColor
*******************************************************************************/
aColor::aColor(u32   _u32HexValue)
{
    m_r = (color_t) (((_u32HexValue & 0xff0000) >> 16)) / 255.;
    m_g = (color_t) (((_u32HexValue & 0x00ff00) >> 8)) / 255.;
    m_b = (color_t) ((_u32HexValue & 0x0000ff)) / 255.;
    m_a = 1.0;
} // aColor::aColor


/*******************************************************************************
* aColor::fromU8
*******************************************************************************/
aColor aColor::fromU8(u8   _r,
                      u8   _g,
                      u8   _b,
                      u8   _a /*= 255*/)
{
    return aColor(((color_t) _r) / 255.,
                  ((color_t) _g) / 255.,
                  ((color_t) _b) / 255.,
                  ((color_t) _a) / 255.);
} // aColor::fromU8


/*******************************************************************************
* aColor::operator=
*******************************************************************************/
aColor& aColor::operator=(const aColor	&_rhs)
{
    m_r = _rhs.m_r;
    m_g = _rhs.m_g;
    m_b = _rhs.m_b;
    m_a = _rhs.m_a;

    return *this;
} // aColor::operator=


/*******************************************************************************
* aColor::operator==
*******************************************************************************/
bool aColor::operator==(const aColor &_rhs) const
{
    return isEqual<color_t> (m_r, _rhs.m_r) &&
           isEqual<color_t> (m_g, _rhs.m_g) &&
           isEqual<color_t> (m_b, _rhs.m_b) &&
           isEqual<color_t> (m_a, _rhs.m_a);
} // aColor::operator==


/*******************************************************************************
* aColor::operator!=
*******************************************************************************/
bool aColor::operator!=(const aColor &_rhs) const
{
    return isUnequal<color_t> (m_r, _rhs.m_r) ||
           isUnequal<color_t> (m_g, _rhs.m_g) ||
           isUnequal<color_t> (m_b, _rhs.m_b) ||
           isUnequal<color_t> (m_a, _rhs.m_a);
} // aColor::operator!=


/*******************************************************************************
* aColor::operator*
*******************************************************************************/
aColor aColor::operator*(dbl _dMultiplier) const
{
    return aColor(clamp<color_t> (m_r * _dMultiplier, 0, 1),
                  clamp<color_t> (m_g * _dMultiplier, 0, 1),
                  clamp<color_t> (m_b * _dMultiplier, 0, 1),
                  m_a);
} // aColor::operator*=


/*******************************************************************************
* aColor::operator*=
*******************************************************************************/
aColor& aColor::operator*=(dbl    _dMultiplier)
{
    m_r = clamp<color_t> (m_r * _dMultiplier, 0, 1);
    m_g = clamp<color_t> (m_g * _dMultiplier, 0, 1);
    m_b = clamp<color_t> (m_b * _dMultiplier, 0, 1);

    return *this;
} // aColor::operator*=


/*******************************************************************************
* aColor::set
*******************************************************************************/
void aColor::set(const color_t  _r,
                 const color_t  _g,
                 const color_t  _b,
                 const color_t  _a)
{
    m_r = clamp<color_t> (_r, 0, 1);
    m_g = clamp<color_t> (_g, 0, 1);
    m_b = clamp<color_t> (_b, 0, 1);
    m_a = clamp<color_t> (_a, 0, 1);
} // aColor::set


/*******************************************************************************
* aColor::set
*******************************************************************************/
void aColor::set(const color_t  _r,
                 const color_t  _g,
                 const color_t  _b)
{
    m_r = clamp<color_t> (_r, 0, 1);
    m_g = clamp<color_t> (_g, 0, 1);
    m_b = clamp<color_t> (_b, 0, 1);
} // aColor::set


/*******************************************************************************
* aColor::average
*******************************************************************************/
color_t aColor::average() const
{
    return (m_r + m_g + m_b) / 3.;
} // aColor::average


/*******************************************************************************
* aColor::invert
*******************************************************************************/
void aColor::invert()
{
    m_r = 1. - m_r;
    m_g = 1. - m_g;
    m_b = 1. - m_b;
} // aColor::invert


/*******************************************************************************
* aColor::toRgbHexValue
*******************************************************************************/
u64 aColor::toRgbHexValue() const
{
    return (((u64) (m_r * 255.)) << 16) +
           (((u64) (m_g * 255.)) << 8) +
             (u64) (m_b * 255.);
} // aColor::toRgbHexValue


/*******************************************************************************
* aColor::isBlack
*******************************************************************************/
bool aColor::isBlack() const
{
    return isEqual<color_t> (m_r, 0) &&
           isEqual<color_t> (m_g, 0) &&
           isEqual<color_t> (m_b, 0);
} // aColor::isBlack


/*******************************************************************************
* aColor::isWhite
*******************************************************************************/
bool aColor::isWhite() const
{
    return isEqual<color_t> (m_r, 1) &&
           isEqual<color_t> (m_g, 1) &&
           isEqual<color_t> (m_b, 1);
} // aColor::isWhite


/*******************************************************************************
* color definitions
*******************************************************************************/
aColor colTransparent(0., 0., 0., 0.005);

aColor colGrey0  (0.00, 0.00, 0.00, 1.00);
aColor colGrey5  (0.05, 0.05, 0.05, 1.00);
aColor colGrey8  (0.08, 0.08, 0.08, 1.00);
aColor colGrey10 (0.10, 0.10, 0.10, 1.00);
aColor colGrey11 (0.11, 0.11, 0.11, 1.00);
aColor colGrey15 (0.15, 0.15, 0.15, 1.00);
aColor colGrey20 (0.20, 0.20, 0.20, 1.00);
aColor colGrey25 (0.25, 0.25, 0.25, 1.00);
aColor colGrey30 (0.30, 0.30, 0.30, 1.00);
aColor colGrey35 (0.35, 0.35, 0.35, 1.00);
aColor colGrey40 (0.40, 0.40, 0.40, 1.00);
aColor colGrey45 (0.45, 0.45, 0.45, 1.00);
aColor colGrey50 (0.50, 0.50, 0.50, 1.00);
aColor colGrey55 (0.55, 0.55, 0.55, 1.00);
aColor colGrey60 (0.60, 0.60, 0.60, 1.00);
aColor colGrey65 (0.65, 0.65, 0.65, 1.00);
aColor colGrey70 (0.70, 0.70, 0.70, 1.00);
aColor colGrey75 (0.75, 0.75, 0.75, 1.00);
aColor colGrey80 (0.80, 0.80, 0.80, 1.00);
aColor colGrey85 (0.85, 0.85, 0.85, 1.00);
aColor colGrey90 (0.90, 0.90, 0.90, 1.00);
aColor colGrey95 (0.95, 0.95, 0.95, 1.00);
aColor colGrey100(1.00, 1.00, 1.00, 1.00);

// named HTML colors
aColor colAliceBlue(0xF0F8FF);
aColor colAntiqueWhite(0xFAEBD7);
aColor colAqua(0x00FFFF);
aColor colAquamarine(0x7FFFD4);
aColor colAzure(0xF0FFFF);
aColor colBeige(0xF5F5DC);
aColor colBisque(0xFFE4C4);
aColor colBlack(0x000000);
aColor colBlanchedAlmond(0xFFEBCD);
aColor colBlue(0x0000FF);
aColor colBlueViolet(0x8A2BE2);
aColor colBrown(0xA52A2A);
aColor colBurlyWood(0xDEB887);
aColor colCadetBlue(0x5F9EA0);
aColor colChartreuse(0x7FFF00);
aColor colChocolate(0xD2691E);
aColor colCoral(0xFF7F50);
aColor colCornflowerBlue(0x6495ED);
aColor colCornsilk(0xFFF8DC);
aColor colCrimson(0xDC143C);
aColor colCyan(0x00FFFF);
aColor colDarkBlue(0x00008B);
aColor colDarkCyan(0x008B8B);
aColor colDarkGoldenRod(0xB8860B);
aColor colDarkGray(0xA9A9A9);
aColor colDarkGrey(0xA9A9A9);
aColor colDarkGreen(0x006400);
aColor colDarkKhaki(0xBDB76B);
aColor colDarkMagenta(0x8B008B);
aColor colDarkOliveGreen(0x556B2F);
aColor colDarkOrange(0xFF8C00);
aColor colDarkOrchid(0x9932CC);
aColor colDarkRed(0x8B0000);
aColor colDarkSalmon(0xE9967A);
aColor colDarkSeaGreen(0x8FBC8F);
aColor colDarkSlateBlue(0x483D8B);
aColor colDarkSlateGray(0x2F4F4F);
aColor colDarkSlateGrey(0x2F4F4F);
aColor colDarkTurquoise(0x00CED1);
aColor colDarkViolet(0x9400D3);
aColor colDeepPink(0xFF1493);
aColor colDeepSkyBlue(0x00BFFF);
aColor colDimGray(0x696969);
aColor colDimGrey(0x696969);
aColor colDodgerBlue(0x1E90FF);
aColor colFireBrick(0xB22222);
aColor colFloralWhite(0xFFFAF0);
aColor colForestGreen(0x228B22);
aColor colFuchsia(0xFF00FF);
aColor colGainsboro(0xDCDCDC);
aColor colGhostWhite(0xF8F8FF);
aColor colGold(0xFFD700);
aColor colGoldenRod(0xDAA520);
aColor colGray(0x808080);
aColor colGrey(0x808080);
aColor colGreen(0x008000);
aColor colGreenYellow(0xADFF2F);
aColor colHoneyDew(0xF0FFF0);
aColor colHotPink(0xFF69B4);
aColor colIndianRed(0xCD5C5C);
aColor colIndigo(0x4B0082);
aColor colIvory(0xFFFFF0);
aColor colKhaki(0xF0E68C);
aColor colLavender(0xE6E6FA);
aColor colLavenderBlush(0xFFF0F5);
aColor colLawnGreen(0x7CFC00);
aColor colLemonChiffon(0xFFFACD);
aColor colLightBlue(0xADD8E6);
aColor colLightCoral(0xF08080);
aColor colLightCyan(0xE0FFFF);
aColor colLightGoldenRodYellow(0xFAFAD2);
aColor colLightGray(0xD3D3D3);
aColor colLightGrey(0xD3D3D3);
aColor colLightGreen(0x90EE90);
aColor colLightPink(0xFFB6C1);
aColor colLightSalmon(0xFFA07A);
aColor colLightSeaGreen(0x20B2AA);
aColor colLightSkyBlue(0x87CEFA);
aColor colLightSlateGray(0x778899);
aColor colLightSlateGrey(0x778899);
aColor colLightSteelBlue(0xB0C4DE);
aColor colLightYellow(0xFFFFE0);
aColor colLime(0x00FF00);
aColor colLimeGreen(0x32CD32);
aColor colLinen(0xFAF0E6);
aColor colMagenta(0xFF00FF);
aColor colMaroon(0x800000);
aColor colMediumAquaMarine(0x66CDAA);
aColor colMediumBlue(0x0000CD);
aColor colMediumOrchid(0xBA55D3);
aColor colMediumPurple(0x9370DB);
aColor colMediumSeaGreen(0x3CB371);
aColor colMediumSlateBlue(0x7B68EE);
aColor colMediumSpringGreen(0x00FA9A);
aColor colMediumTurquoise(0x48D1CC);
aColor colMediumVioletRed(0xC71585);
aColor colMidnightBlue(0x191970);
aColor colMintCream(0xF5FFFA);
aColor colMistyRose(0xFFE4E1);
aColor colMoccasin(0xFFE4B5);
aColor colNavajoWhite(0xFFDEAD);
aColor colNavy(0x000080);
aColor colOldLace(0xFDF5E6);
aColor colOlive(0x808000);
aColor colOliveDrab(0x6B8E23);
aColor colOrange(0xFFA500);
aColor colOrangeRed(0xFF4500);
aColor colOrchid(0xDA70D6);
aColor colPaleGoldenRod(0xEEE8AA);
aColor colPaleGreen(0x98FB98);
aColor colPaleTurquoise(0xAFEEEE);
aColor colPaleVioletRed(0xDB7093);
aColor colPapayaWhip(0xFFEFD5);
aColor colPeachPuff(0xFFDAB9);
aColor colPeru(0xCD853F);
aColor colPink(0xFFC0CB);
aColor colPlum(0xDDA0DD);
aColor colPowderBlue(0xB0E0E6);
aColor colPurple(0x800080);
aColor colRebeccaPurple(0x663399);
aColor colRed(0xFF0000);
aColor colRosyBrown(0xBC8F8F);
aColor colRoyalBlue(0x4169E1);
aColor colSaddleBrown(0x8B4513);
aColor colSalmon(0xFA8072);
aColor colSandyBrown(0xF4A460);
aColor colSeaGreen(0x2E8B57);
aColor colSeaShell(0xFFF5EE);
aColor colSienna(0xA0522D);
aColor colSilver(0xC0C0C0);
aColor colSkyBlue(0x87CEEB);
aColor colSlateBlue(0x6A5ACD);
aColor colSlateGray(0x708090);
aColor colSlateGrey(0x708090);
aColor colSnow(0xFFFAFA);
aColor colSpringGreen(0x00FF7F);
aColor colSteelBlue(0x4682B4);
aColor colDarkSteelBlue(0x24425C);
aColor colTan(0xD2B48C);
aColor colTeal(0x008080);
aColor colThistle(0xD8BFD8);
aColor colTomato(0xFF6347);
aColor colTurquoise(0x40E0D0);
aColor colViolet(0xEE82EE);
aColor colWheat(0xF5DEB3);
aColor colWhite(0xFFFFFF);
aColor colWhiteSmoke(0xF5F5F5);
aColor colYellow(0xFFFF00);
aColor colYellowGreen(0x9ACD32);


} // namespace aUtil
} // namespace aLib
