/*******************************************************************************
* \file qColor.cpp
* \author Andreas Kuhlewind
*
* \brief
*
*  Detailed description starts here.
*******************************************************************************/


/*******************************************************************************
* includes
*******************************************************************************/
#include "qLibDefs.h"
#include "Object/qColor.h"
#include "Util/qUtil.h"

using namespace qLib::Util;


/*******************************************************************************
* namespace
*******************************************************************************/
namespace qLib {
namespace Object {


/*******************************************************************************
* qColor::qColor
*******************************************************************************/
qColor::qColor(const color_t _r,
               const color_t _g,
               const color_t _b,
               const color_t _a)
: m_r(_r),
  m_g(_g),
  m_b(_b),
  m_a(_a)
{
} // qColor::qColor


/*******************************************************************************
* qColor::qColor
*******************************************************************************/
qColor::qColor(const qColor	&_rhs)
{
    m_r = _rhs.m_r;
    m_g = _rhs.m_g;
    m_b = _rhs.m_b;
    m_a = _rhs.m_a;
} // qColor::qColor


/*******************************************************************************
* qColor::qColor
*******************************************************************************/
qColor::qColor(u32   _u32HexValue)
{
    m_r = (color_t) (((_u32HexValue & 0xff0000) >> 16)) / 255.;
    m_g = (color_t) (((_u32HexValue & 0x00ff00) >> 8)) / 255.;
    m_b = (color_t) ((_u32HexValue & 0x0000ff)) / 255.;
    m_a = 1.0;
} // qColor::qColor


/*******************************************************************************
* qColor::fromU8
*******************************************************************************/
qColor qColor::fromU8(u8   _r,
                      u8   _g,
                      u8   _b,
                      u8   _a /*= 255*/)
{
    return qColor(((color_t) _r) / 255.,
                   ((color_t) _g) / 255.,
                   ((color_t) _b) / 255.,
                   ((color_t) _a) / 255.);
} // qColor::fromU8


/*******************************************************************************
* qColor::operator=
*******************************************************************************/
qColor& qColor::operator=(const qColor	&_rhs)
{
    m_r = _rhs.m_r;
    m_g = _rhs.m_g;
    m_b = _rhs.m_b;
    m_a = _rhs.m_a;

    return *this;
} // qColor::operator=


/*******************************************************************************
* qColor::operator==
*******************************************************************************/
bool qColor::operator==(const qColor &_rhs) const
{
    return isEqual<color_t> (m_r, _rhs.m_r) &&
           isEqual<color_t> (m_g, _rhs.m_g) &&
           isEqual<color_t> (m_b, _rhs.m_b) &&
           isEqual<color_t> (m_a, _rhs.m_a);
} // qColor::operator==


/*******************************************************************************
* qColor::operator!=
*******************************************************************************/
bool qColor::operator!=(const qColor &_rhs) const
{
    return isUnequal<color_t> (m_r, _rhs.m_r) ||
           isUnequal<color_t> (m_g, _rhs.m_g) ||
           isUnequal<color_t> (m_b, _rhs.m_b) ||
           isUnequal<color_t> (m_a, _rhs.m_a);
} // qColor::operator!=


/*******************************************************************************
* qColor::operator*
*******************************************************************************/
qColor qColor::operator*(dbl _dMultiplier) const
{
    return qColor(clamp<color_t> (m_r * _dMultiplier, 0, 1),
                  clamp<color_t> (m_g * _dMultiplier, 0, 1),
                  clamp<color_t> (m_b * _dMultiplier, 0, 1),
                  m_a);
} // qColor::operator*=


/*******************************************************************************
* qColor::operator*=
*******************************************************************************/
qColor& qColor::operator*=(dbl    _dMultiplier)
{
    m_r = clamp<color_t> (m_r * _dMultiplier, 0, 1);
    m_g = clamp<color_t> (m_g * _dMultiplier, 0, 1);
    m_b = clamp<color_t> (m_b * _dMultiplier, 0, 1);

    return *this;
} // qColor::operator*=


/*******************************************************************************
* qColor::setRgba
*******************************************************************************/
void qColor::setRgba(const color_t   _r,
                     const color_t   _g,
                     const color_t   _b,
                     const color_t   _a)
{
    m_r = clamp<color_t> (_r, 0, 1);
    m_g = clamp<color_t> (_g, 0, 1);
    m_b = clamp<color_t> (_b, 0, 1);
    m_a = clamp<color_t> (_a, 0, 1);
} // qColor::setRgba


/*******************************************************************************
* qColor::setRgb
*******************************************************************************/
void qColor::setRgb(const color_t    _r,
                    const color_t    _g,
                    const color_t    _b)
{
    m_r = clamp<color_t> (_r, 0, 1);
    m_g = clamp<color_t> (_g, 0, 1);
    m_b = clamp<color_t> (_b, 0, 1);
} // qColor::setRgb


/*******************************************************************************
* qColor::average
*******************************************************************************/
color_t qColor::average() const
{
    return (m_r + m_g + m_b) / 3.;
} // qColor::average


/*******************************************************************************
* qColor::invert
*******************************************************************************/
void qColor::invert()
{
    m_r = 1. - m_r;
    m_g = 1. - m_g;
    m_b = 1. - m_b;
} // qColor::invert


/*******************************************************************************
* qColor::toRgbHexValue
*******************************************************************************/
u64 qColor::toRgbHexValue() const
{
    return (((u64) (m_r * 255.)) << 16) +
           (((u64) (m_g * 255.)) << 8) +
             (u64) (m_b * 255.);
} // qColor::toRgbHexValue


/*******************************************************************************
* qColor::isBlack
*******************************************************************************/
bool qColor::isBlack() const
{
    return isEqual<color_t> (m_r, 0) &&
           isEqual<color_t> (m_g, 0) &&
           isEqual<color_t> (m_b, 0);
} // qColor::isBlack


/*******************************************************************************
* qColor::isWhite
*******************************************************************************/
bool qColor::isWhite() const
{
    return isEqual<color_t> (m_r, 1) &&
           isEqual<color_t> (m_g, 1) &&
           isEqual<color_t> (m_b, 1);
} // qColor::isWhite


/*******************************************************************************
* qColor::RandomColor
*******************************************************************************/
//    qColor qColor::RandomColor()
//    {
//        return qColor(RandomValue<double> (0, 1),
//                     RandomValue<double> (0, 1),
//                     RandomValue<double> (0, 1),
//                     1);
//    } // qColor::RandomColor


/*******************************************************************************
* qColor::RandomBrightColor
*******************************************************************************/
//    qColor qColor::RandomBrightColor()
//    {
//        return qColor(RandomValue<double> (0.5, 1),
//                     RandomValue<double> (0.5, 1),
//                     RandomValue<double> (0.5, 1),
//                     1);
//    } // qColor::RandomBrightColor


/*******************************************************************************
* color definitions
*******************************************************************************/
qColor colTransparent(0., 0., 0., 0.01);

qColor colGrey0  (0.00, 0.00, 0.00, 1.00);
qColor colGrey5  (0.05, 0.05, 0.05, 1.00);
qColor colGrey8  (0.08, 0.08, 0.08, 1.00);
qColor colGrey10 (0.10, 0.10, 0.10, 1.00);
qColor colGrey11 (0.11, 0.11, 0.11, 1.00);
qColor colGrey15 (0.15, 0.15, 0.15, 1.00);
qColor colGrey20 (0.20, 0.20, 0.20, 1.00);
qColor colGrey25 (0.25, 0.25, 0.25, 1.00);
qColor colGrey30 (0.30, 0.30, 0.30, 1.00);
qColor colGrey35 (0.35, 0.35, 0.35, 1.00);
qColor colGrey40 (0.40, 0.40, 0.40, 1.00);
qColor colGrey45 (0.45, 0.45, 0.45, 1.00);
qColor colGrey50 (0.50, 0.50, 0.50, 1.00);
qColor colGrey55 (0.55, 0.55, 0.55, 1.00);
qColor colGrey60 (0.60, 0.60, 0.60, 1.00);
qColor colGrey65 (0.65, 0.65, 0.65, 1.00);
qColor colGrey70 (0.70, 0.70, 0.70, 1.00);
qColor colGrey75 (0.75, 0.75, 0.75, 1.00);
qColor colGrey80 (0.80, 0.80, 0.80, 1.00);
qColor colGrey85 (0.85, 0.85, 0.85, 1.00);
qColor colGrey90 (0.90, 0.90, 0.90, 1.00);
qColor colGrey95 (0.95, 0.95, 0.95, 1.00);
qColor colGrey100(1.00, 1.00, 1.00, 1.00);

// named HTML colors
qColor colAliceBlue(0xF0F8FF);
qColor colAntiqueWhite(0xFAEBD7);
qColor colAqua(0x00FFFF);
qColor colAquamarine(0x7FFFD4);
qColor colAzure(0xF0FFFF);
qColor colBeige(0xF5F5DC);
qColor colBisque(0xFFE4C4);
qColor colBlack(0x000000);
qColor colBlanchedAlmond(0xFFEBCD);
qColor colBlue(0x0000FF);
qColor colBlueViolet(0x8A2BE2);
qColor colBrown(0xA52A2A);
qColor colBurlyWood(0xDEB887);
qColor colCadetBlue(0x5F9EA0);
qColor colChartreuse(0x7FFF00);
qColor colChocolate(0xD2691E);
qColor colCoral(0xFF7F50);
qColor colCornflowerBlue(0x6495ED);
qColor colCornsilk(0xFFF8DC);
qColor colCrimson(0xDC143C);
qColor colCyan(0x00FFFF);
qColor colDarkBlue(0x00008B);
qColor colDarkCyan(0x008B8B);
qColor colDarkGoldenRod(0xB8860B);
qColor colDarkGray(0xA9A9A9);
qColor colDarkGrey(0xA9A9A9);
qColor colDarkGreen(0x006400);
qColor colDarkKhaki(0xBDB76B);
qColor colDarkMagenta(0x8B008B);
qColor colDarkOliveGreen(0x556B2F);
qColor colDarkOrange(0xFF8C00);
qColor colDarkOrchid(0x9932CC);
qColor colDarkRed(0x8B0000);
qColor colDarkSalmon(0xE9967A);
qColor colDarkSeaGreen(0x8FBC8F);
qColor colDarkSlateBlue(0x483D8B);
qColor colDarkSlateGray(0x2F4F4F);
qColor colDarkSlateGrey(0x2F4F4F);
qColor colDarkTurquoise(0x00CED1);
qColor colDarkViolet(0x9400D3);
qColor colDeepPink(0xFF1493);
qColor colDeepSkyBlue(0x00BFFF);
qColor colDimGray(0x696969);
qColor colDimGrey(0x696969);
qColor colDodgerBlue(0x1E90FF);
qColor colFireBrick(0xB22222);
qColor colFloralWhite(0xFFFAF0);
qColor colForestGreen(0x228B22);
qColor colFuchsia(0xFF00FF);
qColor colGainsboro(0xDCDCDC);
qColor colGhostWhite(0xF8F8FF);
qColor colGold(0xFFD700);
qColor colGoldenRod(0xDAA520);
qColor colGray(0x808080);
qColor colGrey(0x808080);
qColor colGreen(0x008000);
qColor colGreenYellow(0xADFF2F);
qColor colHoneyDew(0xF0FFF0);
qColor colHotPink(0xFF69B4);
qColor colIndianRed(0xCD5C5C);
qColor colIndigo(0x4B0082);
qColor colIvory(0xFFFFF0);
qColor colKhaki(0xF0E68C);
qColor colLavender(0xE6E6FA);
qColor colLavenderBlush(0xFFF0F5);
qColor colLawnGreen(0x7CFC00);
qColor colLemonChiffon(0xFFFACD);
qColor colLightBlue(0xADD8E6);
qColor colLightCoral(0xF08080);
qColor colLightCyan(0xE0FFFF);
qColor colLightGoldenRodYellow(0xFAFAD2);
qColor colLightGray(0xD3D3D3);
qColor colLightGrey(0xD3D3D3);
qColor colLightGreen(0x90EE90);
qColor colLightPink(0xFFB6C1);
qColor colLightSalmon(0xFFA07A);
qColor colLightSeaGreen(0x20B2AA);
qColor colLightSkyBlue(0x87CEFA);
qColor colLightSlateGray(0x778899);
qColor colLightSlateGrey(0x778899);
qColor colLightSteelBlue(0xB0C4DE);
qColor colLightYellow(0xFFFFE0);
qColor colLime(0x00FF00);
qColor colLimeGreen(0x32CD32);
qColor colLinen(0xFAF0E6);
qColor colMagenta(0xFF00FF);
qColor colMaroon(0x800000);
qColor colMediumAquaMarine(0x66CDAA);
qColor colMediumBlue(0x0000CD);
qColor colMediumOrchid(0xBA55D3);
qColor colMediumPurple(0x9370DB);
qColor colMediumSeaGreen(0x3CB371);
qColor colMediumSlateBlue(0x7B68EE);
qColor colMediumSpringGreen(0x00FA9A);
qColor colMediumTurquoise(0x48D1CC);
qColor colMediumVioletRed(0xC71585);
qColor colMidnightBlue(0x191970);
qColor colMintCream(0xF5FFFA);
qColor colMistyRose(0xFFE4E1);
qColor colMoccasin(0xFFE4B5);
qColor colNavajoWhite(0xFFDEAD);
qColor colNavy(0x000080);
qColor colOldLace(0xFDF5E6);
qColor colOlive(0x808000);
qColor colOliveDrab(0x6B8E23);
qColor colOrange(0xFFA500);
qColor colOrangeRed(0xFF4500);
qColor colOrchid(0xDA70D6);
qColor colPaleGoldenRod(0xEEE8AA);
qColor colPaleGreen(0x98FB98);
qColor colPaleTurquoise(0xAFEEEE);
qColor colPaleVioletRed(0xDB7093);
qColor colPapayaWhip(0xFFEFD5);
qColor colPeachPuff(0xFFDAB9);
qColor colPeru(0xCD853F);
qColor colPink(0xFFC0CB);
qColor colPlum(0xDDA0DD);
qColor colPowderBlue(0xB0E0E6);
qColor colPurple(0x800080);
qColor colRebeccaPurple(0x663399);
qColor colRed(0xFF0000);
qColor colRosyBrown(0xBC8F8F);
qColor colRoyalBlue(0x4169E1);
qColor colSaddleBrown(0x8B4513);
qColor colSalmon(0xFA8072);
qColor colSandyBrown(0xF4A460);
qColor colSeaGreen(0x2E8B57);
qColor colSeaShell(0xFFF5EE);
qColor colSienna(0xA0522D);
qColor colSilver(0xC0C0C0);
qColor colSkyBlue(0x87CEEB);
qColor colSlateBlue(0x6A5ACD);
qColor colSlateGray(0x708090);
qColor colSlateGrey(0x708090);
qColor colSnow(0xFFFAFA);
qColor colSpringGreen(0x00FF7F);
qColor colSteelBlue(0x4682B4);
qColor colDarkSteelBlue(0x24425C);
qColor colTan(0xD2B48C);
qColor colTeal(0x008080);
qColor colThistle(0xD8BFD8);
qColor colTomato(0xFF6347);
qColor colTurquoise(0x40E0D0);
qColor colViolet(0xEE82EE);
qColor colWheat(0xF5DEB3);
qColor colWhite(0xFFFFFF);
qColor colWhiteSmoke(0xF5F5F5);
qColor colYellow(0xFFFF00);
qColor colYellowGreen(0x9ACD32);


} // namespace Object
} // namespace qLib
