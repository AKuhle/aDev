/*******************************************************************************
* \file qRgba.cpp
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
#include "qRgba.h"


namespace qLib
{
    /*******************************************************************************
    * qRgba::qRgba
    *******************************************************************************/
    qRgba::qRgba(const Rgba_t 	_r,
                 const Rgba_t 	_g,
                 const Rgba_t 	_b,
                 const Rgba_t     _a)
    : r(_r),
      g(_g),
      b(_b),
      a(_a)
    {
    } // qRgba::qRgba


    /*******************************************************************************
    * qRgba::qRgba
    *******************************************************************************/
    qRgba::qRgba(const qRgba	&_rhs)
    {
        r = _rhs.r;
        g = _rhs.g;
        b = _rhs.b;
        a = _rhs.a;
    } // qRgba::qRgba


    /*******************************************************************************
    * qRgba::qRgba
    *******************************************************************************/
    qRgba::qRgba(u32   _u32HexValue)
    {
        r = (Rgba_t) (((_u32HexValue & 0xff0000) >> 16)) / 255.;
        g = (Rgba_t) (((_u32HexValue & 0x00ff00) >> 8)) / 255.;
        b = (Rgba_t) ((_u32HexValue & 0x0000ff)) / 255.;
        a = 1.0;
    } // qRgba::qRgba


    /*******************************************************************************
    * qRgba::FromU8
    *******************************************************************************/
    qRgba qRgba::FromU8(u8   _u8R,
                        u8   _u8G,
                        u8   _u8B,
                        u8   _u8A /*= 255*/)
    {
        return qRgba(((Rgba_t) _u8R) / 255.,
                     ((Rgba_t) _u8G) / 255.,
                     ((Rgba_t) _u8B) / 255.,
                     ((Rgba_t) _u8A) / 255.);
    } // qRgba::FromqRgba


    /*******************************************************************************
    * qRgba::operator=
    *******************************************************************************/
    qRgba& qRgba::operator=(const qRgba	&_rhs)
    {
        r = _rhs.r;
        g = _rhs.g;
        b = _rhs.b;
        a = _rhs.a;

        return *this;
    } // qRgba::operator=


    /*******************************************************************************
    * qRgba::operator==
    *******************************************************************************/
    bool qRgba::operator==(const qRgba &_rhs) const
    {
        return IsEqual (r, _rhs.r) &&
               IsEqual (g, _rhs.g) &&
               IsEqual (b, _rhs.b) &&
               IsEqual (a, _rhs.a);
    } // qRgba::operator==


    /*******************************************************************************
    * qRgba::operator!=
    *******************************************************************************/
    bool qRgba::operator!=(const qRgba &_rhs) const
    {
        return IsUnequal (r, _rhs.r) ||
               IsUnequal (g, _rhs.g) ||
               IsUnequal (b, _rhs.b) ||
               IsUnequal (a, _rhs.a);
    } // qRgba::operator!=


    /*******************************************************************************
    * qRgba::operator*
    *******************************************************************************/
    qRgba qRgba::operator*(dbl    _dMultiplier) const
    {
        return qRgba(Clamp<Rgba_t> (r * _dMultiplier, 0, 1),
                     Clamp<Rgba_t> (g * _dMultiplier, 0, 1),
                     Clamp<Rgba_t> (b * _dMultiplier, 0, 1),
                     a);
    } // qRgba::operator*=


    /*******************************************************************************
    * qRgba::operator*=
    *******************************************************************************/
    qRgba& qRgba::operator*=(dbl    _dMultiplier)
    {
        r = Clamp<Rgba_t> (r * _dMultiplier, 0, 1);
        g = Clamp<Rgba_t> (g * _dMultiplier, 0, 1);
        b = Clamp<Rgba_t> (b * _dMultiplier, 0, 1);

        return *this;
    } // qRgba::operator*=


    /*******************************************************************************
    * qRgba::SetRgba
    *******************************************************************************/
    void qRgba::SetRgba(const Rgba_t   _r,
                        const Rgba_t   _g,
                        const Rgba_t   _b,
                        const Rgba_t   _a)
    {
        r = Clamp<Rgba_t> (_r, 0, 1);
        g = Clamp<Rgba_t> (_g, 0, 1);
        b = Clamp<Rgba_t> (_b, 0, 1);
        a = Clamp<Rgba_t> (_a, 0, 1);
    } // qRgba::SetRgba


    /*******************************************************************************
    * qRgba::SetRgb
    *******************************************************************************/
    void qRgba::SetRgb(const Rgba_t    _r,
                      const Rgba_t    _g,
                      const Rgba_t    _b)
    {
        r = Clamp<Rgba_t> (_r, 0, 1);
        g = Clamp<Rgba_t> (_g, 0, 1);
        b = Clamp<Rgba_t> (_b, 0, 1);
    } // qRgba::SetRgb


    /*******************************************************************************
    * qRgba::GetAverage
    *******************************************************************************/
    Rgba_t qRgba::Average() const
    {
        return (r + g + b) / 3.;
    } // qRgba::GetAverage


    /*******************************************************************************
    * qRgba::Invert
    *******************************************************************************/
    void qRgba::Invert()
    {
        r = 1. - r;
        g = 1. - g;
        b = 1. - b;
    } // qRgba::Invert


    /*******************************************************************************
    * qRgba::ToRgbHexValue
    *******************************************************************************/
    u64 qRgba::ToRgbHexValue() const
    {
        return (((u64) (r * 255.)) << 16) +
               (((u64) (g * 255.)) << 8) +
               (u64) (b * 255.);
    } // qRgba::ToRgbHexValue


    /*******************************************************************************
    * qRgba::IsBlack
    *******************************************************************************/
    bool qRgba::IsBlack() const
    {
        return IsEqual<Rgba_t>(r, 0) && IsEqual<Rgba_t>(g, 0) && IsEqual<Rgba_t>(b, 0);
    } // qRgba::IsBlack


    /*******************************************************************************
    * qRgba::IsWhite
    *******************************************************************************/
    bool qRgba::IsWhite() const
    {
        return IsEqual<Rgba_t>(r, 1) && IsEqual<Rgba_t>(g, 1) && IsEqual<Rgba_t>(b, 1);
    } // qRgba::IsWhite


    /*******************************************************************************
    * qRgba::RandomColor
    *******************************************************************************/
//    qRgba qRgba::RandomColor()
//    {
//        return qRgba(RandomValue<double> (0, 1),
//                     RandomValue<double> (0, 1),
//                     RandomValue<double> (0, 1),
//                     1);
//    } // qRgba::RandomColor


    /*******************************************************************************
    * qRgba::RandomBrightColor
    *******************************************************************************/
//    qRgba qRgba::RandomBrightColor()
//    {
//        return qRgba(RandomValue<double> (0.5, 1),
//                     RandomValue<double> (0.5, 1),
//                     RandomValue<double> (0.5, 1),
//                     1);
//    } // qRgba::RandomBrightColor


    /*******************************************************************************
    * color definitions
    *******************************************************************************/
    qRgba rgbaTransparent(0., 0., 0., 0.);

    qRgba rgbaGrey0  (0.00, 0.00, 0.00, 1.00);
    qRgba rgbaGrey5  (0.05, 0.05, 0.05, 1.00);
    qRgba rgbaGrey10 (0.10, 0.10, 0.10, 1.00);
    qRgba rgbaGrey15 (0.15, 0.15, 0.15, 1.00);
    qRgba rgbaGrey20 (0.20, 0.20, 0.20, 1.00);
    qRgba rgbaGrey25 (0.25, 0.25, 0.25, 1.00);
    qRgba rgbaGrey30 (0.30, 0.30, 0.30, 1.00);
    qRgba rgbaGrey35 (0.35, 0.35, 0.35, 1.00);
    qRgba rgbaGrey40 (0.40, 0.40, 0.40, 1.00);
    qRgba rgbaGrey45 (0.45, 0.45, 0.45, 1.00);
    qRgba rgbaGrey50 (0.50, 0.50, 0.50, 1.00);
    qRgba rgbaGrey55 (0.55, 0.55, 0.55, 1.00);
    qRgba rgbaGrey60 (0.60, 0.60, 0.60, 1.00);
    qRgba rgbaGrey65 (0.65, 0.65, 0.65, 1.00);
    qRgba rgbaGrey70 (0.70, 0.70, 0.70, 1.00);
    qRgba rgbaGrey75 (0.75, 0.75, 0.75, 1.00);
    qRgba rgbaGrey80 (0.80, 0.80, 0.80, 1.00);
    qRgba rgbaGrey85 (0.85, 0.85, 0.85, 1.00);
    qRgba rgbaGrey90 (0.90, 0.90, 0.90, 1.00);
    qRgba rgbaGrey95 (0.95, 0.95, 0.95, 1.00);
    qRgba rgbaGrey100(1.00, 1.00, 1.00, 1.00);

    // named HTML colors
    qRgba rgbaAliceBlue(0xF0F8FF);
    qRgba rgbaAntiqueWhite(0xFAEBD7);
    qRgba rgbaAqua(0x00FFFF);
    qRgba rgbaAquamarine(0x7FFFD4);
    qRgba rgbaAzure(0xF0FFFF);
    qRgba rgbaBeige(0xF5F5DC);
    qRgba rgbaBisque(0xFFE4C4);
    qRgba rgbaBlack(0x000000);
    qRgba rgbaBlanchedAlmond(0xFFEBCD);
    qRgba rgbaBlue(0x0000FF);
    qRgba rgbaBlueViolet(0x8A2BE2);
    qRgba rgbaBrown(0xA52A2A);
    qRgba rgbaBurlyWood(0xDEB887);
    qRgba rgbaCadetBlue(0x5F9EA0);
    qRgba rgbaChartreuse(0x7FFF00);
    qRgba rgbaChocolate(0xD2691E);
    qRgba rgbaCoral(0xFF7F50);
    qRgba rgbaCornflowerBlue(0x6495ED);
    qRgba rgbaCornsilk(0xFFF8DC);
    qRgba rgbaCrimson(0xDC143C);
    qRgba rgbaCyan(0x00FFFF);
    qRgba rgbaDarkBlue(0x00008B);
    qRgba rgbaDarkCyan(0x008B8B);
    qRgba rgbaDarkGoldenRod(0xB8860B);
    qRgba rgbaDarkGray(0xA9A9A9);
    qRgba rgbaDarkGrey(0xA9A9A9);
    qRgba rgbaDarkGreen(0x006400);
    qRgba rgbaDarkKhaki(0xBDB76B);
    qRgba rgbaDarkMagenta(0x8B008B);
    qRgba rgbaDarkOliveGreen(0x556B2F);
    qRgba rgbaDarkOrange(0xFF8C00);
    qRgba rgbaDarkOrchid(0x9932CC);
    qRgba rgbaDarkRed(0x8B0000);
    qRgba rgbaDarkSalmon(0xE9967A);
    qRgba rgbaDarkSeaGreen(0x8FBC8F);
    qRgba rgbaDarkSlateBlue(0x483D8B);
    qRgba rgbaDarkSlateGray(0x2F4F4F);
    qRgba rgbaDarkSlateGrey(0x2F4F4F);
    qRgba rgbaDarkTurquoise(0x00CED1);
    qRgba rgbaDarkViolet(0x9400D3);
    qRgba rgbaDeepPink(0xFF1493);
    qRgba rgbaDeepSkyBlue(0x00BFFF);
    qRgba rgbaDimGray(0x696969);
    qRgba rgbaDimGrey(0x696969);
    qRgba rgbaDodgerBlue(0x1E90FF);
    qRgba rgbaFireBrick(0xB22222);
    qRgba rgbaFloralWhite(0xFFFAF0);
    qRgba rgbaForestGreen(0x228B22);
    qRgba rgbaFuchsia(0xFF00FF);
    qRgba rgbaGainsboro(0xDCDCDC);
    qRgba rgbaGhostWhite(0xF8F8FF);
    qRgba rgbaGold(0xFFD700);
    qRgba rgbaGoldenRod(0xDAA520);
    qRgba rgbaGray(0x808080);
    qRgba rgbaGrey(0x808080);
    qRgba rgbaGreen(0x008000);
    qRgba rgbaGreenYellow(0xADFF2F);
    qRgba rgbaHoneyDew(0xF0FFF0);
    qRgba rgbaHotPink(0xFF69B4);
    qRgba rgbaIndianRed(0xCD5C5C);
    qRgba rgbaIndigo(0x4B0082);
    qRgba rgbaIvory(0xFFFFF0);
    qRgba rgbaKhaki(0xF0E68C);
    qRgba rgbaLavender(0xE6E6FA);
    qRgba rgbaLavenderBlush(0xFFF0F5);
    qRgba rgbaLawnGreen(0x7CFC00);
    qRgba rgbaLemonChiffon(0xFFFACD);
    qRgba rgbaLightBlue(0xADD8E6);
    qRgba rgbaLightCoral(0xF08080);
    qRgba rgbaLightCyan(0xE0FFFF);
    qRgba rgbaLightGoldenRodYellow(0xFAFAD2);
    qRgba rgbaLightGray(0xD3D3D3);
    qRgba rgbaLightGrey(0xD3D3D3);
    qRgba rgbaLightGreen(0x90EE90);
    qRgba rgbaLightPink(0xFFB6C1);
    qRgba rgbaLightSalmon(0xFFA07A);
    qRgba rgbaLightSeaGreen(0x20B2AA);
    qRgba rgbaLightSkyBlue(0x87CEFA);
    qRgba rgbaLightSlateGray(0x778899);
    qRgba rgbaLightSlateGrey(0x778899);
    qRgba rgbaLightSteelBlue(0xB0C4DE);
    qRgba rgbaLightYellow(0xFFFFE0);
    qRgba rgbaLime(0x00FF00);
    qRgba rgbaLimeGreen(0x32CD32);
    qRgba rgbaLinen(0xFAF0E6);
    qRgba rgbaMagenta(0xFF00FF);
    qRgba rgbaMaroon(0x800000);
    qRgba rgbaMediumAquaMarine(0x66CDAA);
    qRgba rgbaMediumBlue(0x0000CD);
    qRgba rgbaMediumOrchid(0xBA55D3);
    qRgba rgbaMediumPurple(0x9370DB);
    qRgba rgbaMediumSeaGreen(0x3CB371);
    qRgba rgbaMediumSlateBlue(0x7B68EE);
    qRgba rgbaMediumSpringGreen(0x00FA9A);
    qRgba rgbaMediumTurquoise(0x48D1CC);
    qRgba rgbaMediumVioletRed(0xC71585);
    qRgba rgbaMidnightBlue(0x191970);
    qRgba rgbaMintCream(0xF5FFFA);
    qRgba rgbaMistyRose(0xFFE4E1);
    qRgba rgbaMoccasin(0xFFE4B5);
    qRgba rgbaNavajoWhite(0xFFDEAD);
    qRgba rgbaNavy(0x000080);
    qRgba rgbaOldLace(0xFDF5E6);
    qRgba rgbaOlive(0x808000);
    qRgba rgbaOliveDrab(0x6B8E23);
    qRgba rgbaOrange(0xFFA500);
    qRgba rgbaOrangeRed(0xFF4500);
    qRgba rgbaOrchid(0xDA70D6);
    qRgba rgbaPaleGoldenRod(0xEEE8AA);
    qRgba rgbaPaleGreen(0x98FB98);
    qRgba rgbaPaleTurquoise(0xAFEEEE);
    qRgba rgbaPaleVioletRed(0xDB7093);
    qRgba rgbaPapayaWhip(0xFFEFD5);
    qRgba rgbaPeachPuff(0xFFDAB9);
    qRgba rgbaPeru(0xCD853F);
    qRgba rgbaPink(0xFFC0CB);
    qRgba rgbaPlum(0xDDA0DD);
    qRgba rgbaPowderBlue(0xB0E0E6);
    qRgba rgbaPurple(0x800080);
    qRgba rgbaRebeccaPurple(0x663399);
    qRgba rgbaRed(0xFF0000);
    qRgba rgbaRosyBrown(0xBC8F8F);
    qRgba rgbaRoyalBlue(0x4169E1);
    qRgba rgbaSaddleBrown(0x8B4513);
    qRgba rgbaSalmon(0xFA8072);
    qRgba rgbaSandyBrown(0xF4A460);
    qRgba rgbaSeaGreen(0x2E8B57);
    qRgba rgbaSeaShell(0xFFF5EE);
    qRgba rgbaSienna(0xA0522D);
    qRgba rgbaSilver(0xC0C0C0);
    qRgba rgbaSkyBlue(0x87CEEB);
    qRgba rgbaSlateBlue(0x6A5ACD);
    qRgba rgbaSlateGray(0x708090);
    qRgba rgbaSlateGrey(0x708090);
    qRgba rgbaSnow(0xFFFAFA);
    qRgba rgbaSpringGreen(0x00FF7F);
    qRgba rgbaSteelBlue(0x4682B4);
    qRgba rgbaTan(0xD2B48C);
    qRgba rgbaTeal(0x008080);
    qRgba rgbaThistle(0xD8BFD8);
    qRgba rgbaTomato(0xFF6347);
    qRgba rgbaTurquoise(0x40E0D0);
    qRgba rgbaViolet(0xEE82EE);
    qRgba rgbaWheat(0xF5DEB3);
    qRgba rgbaWhite(0xFFFFFF);
    qRgba rgbaWhiteSmoke(0xF5F5F5);
    qRgba rgbaYellow(0xFFFF00);
    qRgba rgbaYellowGreen(0x9ACD32);

} // namespace qLib
