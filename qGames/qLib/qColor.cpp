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
#include "qBaseDefs.h"
#include "qColor.h"
#include "qMathUtil.h"


namespace qLib
{
    /*******************************************************************************
    * qColor::qColor
    *******************************************************************************/
    qColor::qColor(const Rgba_t _r,
                   const Rgba_t _g,
                   const Rgba_t _b,
                   const Rgba_t _a)
    : r(MU<Rgba_t>::Clamp(_r, 0.0, 1.0)),
      g(MU<Rgba_t>::Clamp(_g, 0.0, 1.0)),
      b(MU<Rgba_t>::Clamp(_b, 0.0, 1.0)),
      a(MU<Rgba_t>::Clamp(_a, 0.0, 1.0))
    {
    } // qColor::qColor


    /*******************************************************************************
    * qColor::qColor
    *******************************************************************************/
    qColor::qColor(const qColor	&_rhs)
    {
        r = _rhs.r;
        g = _rhs.g;
        b = _rhs.b;
        a = _rhs.a;
    } // qColor::qColor


    /*******************************************************************************
    * qColor::qColor
    *******************************************************************************/
    qColor::qColor(u32   _u32HexValue)
    {
        r = (Rgba_t) (((_u32HexValue & 0xff0000) >> 16)) / 255.;
        g = (Rgba_t) (((_u32HexValue & 0x00ff00) >> 8)) / 255.;
        b = (Rgba_t) ((_u32HexValue & 0x0000ff)) / 255.;
        a = 1.0;
    } // qColor::qColor


    /*******************************************************************************
    * qColor::FromU8
    *******************************************************************************/
    qColor qColor::FromU8(u8   _u8R,
                            u8   _u8G,
                            u8   _u8B,
                            u8   _u8A /*= 255*/)
    {
        return qColor(((Rgba_t) _u8R) / 255.,
                       ((Rgba_t) _u8G) / 255.,
                       ((Rgba_t) _u8B) / 255.,
                       ((Rgba_t) _u8A) / 255.);
    } // qColor::FromqColor


    /*******************************************************************************
    * qColor::operator=
    *******************************************************************************/
    qColor& qColor::operator=(const qColor	&_rhs)
    {
        r = _rhs.r;
        g = _rhs.g;
        b = _rhs.b;
        a = _rhs.a;

        return *this;
    } // qColor::operator=


    /*******************************************************************************
    * qColor::operator==
    *******************************************************************************/
    bool qColor::operator==(const qColor &_rhs) const
    {
        return MU<Rgba_t>::IsEqual (r, _rhs.r) &&
               MU<Rgba_t>::IsEqual (g, _rhs.g) &&
               MU<Rgba_t>::IsEqual (b, _rhs.b) &&
               MU<Rgba_t>::IsEqual (a, _rhs.a);
    } // qColor::operator==


    /*******************************************************************************
    * qColor::operator!=
    *******************************************************************************/
    bool qColor::operator!=(const qColor &_rhs) const
    {
        return MU<Rgba_t>::IsUnequal (r, _rhs.r) ||
               MU<Rgba_t>::IsUnequal (g, _rhs.g) ||
               MU<Rgba_t>::IsUnequal (b, _rhs.b) ||
               MU<Rgba_t>::IsUnequal (a, _rhs.a);
    } // qColor::operator!=


    /*******************************************************************************
    * qColor::operator*
    *******************************************************************************/
    qColor qColor::operator*(dbl    _dMultiplier) const
    {
        return qColor(MU<Rgba_t>::Clamp(r * _dMultiplier, 0, 1),
                     MU<Rgba_t>::Clamp(g * _dMultiplier, 0, 1),
                     MU<Rgba_t>::Clamp(b * _dMultiplier, 0, 1),
                     a);
    } // qColor::operator*=


    /*******************************************************************************
    * qColor::operator*=
    *******************************************************************************/
    qColor& qColor::operator*=(dbl    _dMultiplier)
    {
        r = MU<Rgba_t>::Clamp(r * _dMultiplier, 0, 1);
        g = MU<Rgba_t>::Clamp(g * _dMultiplier, 0, 1);
        b = MU<Rgba_t>::Clamp(b * _dMultiplier, 0, 1);

        return *this;
    } // qColor::operator*=


    /*******************************************************************************
    * qColor::SetRgba
    *******************************************************************************/
    void qColor::SetRgba(const Rgba_t   _r,
                         const Rgba_t   _g,
                         const Rgba_t   _b,
                         const Rgba_t   _a)
    {
        r = MU<Rgba_t>::Clamp(_r, 0, 1);
        g = MU<Rgba_t>::Clamp(_g, 0, 1);
        b = MU<Rgba_t>::Clamp(_b, 0, 1);
        a = MU<Rgba_t>::Clamp(_a, 0, 1);
    } // qColor::SetRgba


    /*******************************************************************************
    * qColor::SetRgb
    *******************************************************************************/
    void qColor::SetRgb(const Rgba_t    _r,
                        const Rgba_t    _g,
                        const Rgba_t    _b)
    {
        r = MU<Rgba_t>::Clamp(_r, 0, 1);
        g = MU<Rgba_t>::Clamp(_g, 0, 1);
        b = MU<Rgba_t>::Clamp(_b, 0, 1);
    } // qColor::SetRgb


    /*******************************************************************************
    * qColor::GetAverage
    *******************************************************************************/
    Rgba_t qColor::Average() const
    {
        return (r + g + b) / 3.;
    } // qColor::GetAverage


    /*******************************************************************************
    * qColor::Invert
    *******************************************************************************/
    void qColor::Invert()
    {
        r = 1. - r;
        g = 1. - g;
        b = 1. - b;
    } // qColor::Invert


    /*******************************************************************************
    * qColor::ToRgbHexValue
    *******************************************************************************/
    u64 qColor::ToRgbHexValue() const
    {
        return (((u64) (r * 255.)) << 16) +
               (((u64) (g * 255.)) << 8) +
                 (u64) (b * 255.);
    } // qColor::ToRgbHexValue


    /*******************************************************************************
    * qColor::ToQColor
    *******************************************************************************/
    QColor qColor::ToQColor() const
    {
        return QColor::fromRgbF(r, g, b, a);
    } // qColor::ToQColor


    /*******************************************************************************
    * qColor::IsBlack
    *******************************************************************************/
    bool qColor::IsBlack() const
    {
        return MU<Rgba_t>::IsEqual(r, 0) &&
               MU<Rgba_t>::IsEqual(g, 0) &&
               MU<Rgba_t>::IsEqual(b, 0);
    } // qColor::IsBlack


    /*******************************************************************************
    * qColor::IsWhite
    *******************************************************************************/
    bool qColor::IsWhite() const
    {
        return MU<Rgba_t>::IsEqual(r, 1) &&
               MU<Rgba_t>::IsEqual(g, 1) &&
               MU<Rgba_t>::IsEqual(b, 1);
    } // qColor::IsWhite


    /*******************************************************************************
    * qColor::GetColorInBetween
    *******************************************************************************/
    qColor qColor::GetColorInBetween(const qColor  &_col,
                                     float         _pcnt) const
    {
        return qColor(r + (_col.r - r) * _pcnt,
                      g + (_col.g - g) * _pcnt,
                      b + (_col.b - b) * _pcnt,
                      a + (_col.a - a) * _pcnt);
    } // qColor::GetColorInBetween


    /*******************************************************************************
    * qColor::RandomColor
    *******************************************************************************/
   qColor qColor::RandomColor(flt _fBrightness_pcnt)
   {
       return qColor(MU<Rgba_t>::RandomValue (0, 1) * _fBrightness_pcnt,
                     MU<Rgba_t>::RandomValue (0, 1) * _fBrightness_pcnt,
                     MU<Rgba_t>::RandomValue (0, 1) * _fBrightness_pcnt,
                     1);
   } // qColor::RandomColor


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

} // namespace qLib
