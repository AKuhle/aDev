/*******************************************************************************
* \file aColor.h
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
    #include <QColor>
#endif // _USE_QT_

#include "aLib_def.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aUtil {


/*******************************************************************************
* class aColor
*******************************************************************************/
class aColor
{
    private:
        color_t  m_r { 0 };        //!< R-value (0.0 ... 1.0)
        color_t  m_g { 0 };        //!< G-value (0.0 ... 1.0)
        color_t  m_b { 0 };        //!< B-value (0.0 ... 1.0)
        color_t  m_a { 1 };        //!< alpha value, default = 1

    public:
        aColor(const color_t    _r,                                     // principal constructor
               const color_t 	_g,
               const color_t 	_b,
               const color_t    _a);

        // sets a to 1
        aColor(const color_t 	_r,                                     // delegation
               const color_t 	_g,
               const color_t 	_b) : aColor(_r, _g, _b, 1) {}

        aColor(): aColor((color_t) 0, 0, 0, 1) {}

        aColor(const aColor &_rhs);

        aColor(u32   _u32HexValue);

        #ifdef _USE_QT_
                aColor(const QColor &_rhs);
        #endif // _USE_QT_

        static aColor   fromU8(u8   _r,
                               u8   _g,
                               u8   _b,
                               u8   _a = 255);

        aColor&         operator=(const aColor	&_rhs);

        bool            operator==(const aColor	&_rhs) const;
        bool            operator!=(const aColor	&_rhs) const;

        aColor          operator*(dbl _dMultiplier) const;

        aColor&         operator*=(dbl _dMultiplier);

        color_t         r() const               { return m_r; }
        color_t         g() const               { return m_g; }
        color_t         b() const               { return m_b; }
        color_t         a() const               { return m_a; }

        color_t&        r()                     { return m_r; }
        color_t&        g()                     { return m_g; }
        color_t&        b()                     { return m_b; }
        color_t&        a()                     { return m_a; }

        void            set(const color_t    _r,
                            const color_t    _g,
                            const color_t    _b,
                            const color_t    _a);

        // leaves 'alpha' unchanged
        void            set(const color_t   _r,
                            const color_t   _g,
                            const color_t   _b);

        color_t         average() const;

        void            invert();

        u64             toRgbHexValue() const;

        bool            isBlack() const;
        bool            isWhite() const;

        #ifdef _USE_QT_
            QColor      toQColor() const;
        #endif // _USE_QT_


        friend std::ostream& operator<<(std::ostream    &_os,
                                        const aColor    &_col)
        {
            _os << "(r:" << _col.m_r
                << ", g:" << _col.m_g
                << ", b:" << _col.m_b
                << ", a:" << _col.m_a
                << ")";

            return _os;
        } // operator<<

}; // class aColor


extern aColor   colTransparent;

extern aColor   colGrey0;
extern aColor   colGrey5;
extern aColor   colGrey8;
extern aColor   colGrey10;
extern aColor   colGrey11;
extern aColor   colGrey15;
extern aColor   colGrey20;
extern aColor   colGrey25;
extern aColor   colGrey30;
extern aColor   colGrey35;
extern aColor   colGrey40;
extern aColor   colGrey45;
extern aColor   colGrey50;
extern aColor   colGrey55;
extern aColor   colGrey60;
extern aColor   colGrey65;
extern aColor   colGrey70;
extern aColor   colGrey75;
extern aColor   colGrey80;
extern aColor   colGrey85;
extern aColor   colGrey90;
extern aColor   colGrey95;
extern aColor   colGrey100;

extern aColor   colAliceBlue;
extern aColor   colAntiqueWhite;
extern aColor   colAqua;
extern aColor   colAquamarine;
extern aColor   colAzure;
extern aColor   colBeige;
extern aColor   colBisque;
extern aColor   colBlack;
extern aColor   colBlanchedAlmond;
extern aColor   colBlue;
extern aColor   colBlueViolet;
extern aColor   colBrown;
extern aColor   colBurlyWood;
extern aColor   colCadetBlue;
extern aColor   colChartreuse;
extern aColor   colChocolate;
extern aColor   colCoral;
extern aColor   colCornflowerBlue;
extern aColor   colCornsilk;
extern aColor   colCrimson;
extern aColor   colCyan;
extern aColor   colDarkBlue;
extern aColor   colDarkCyan;
extern aColor   colDarkGoldenRod;
extern aColor   colDarkGray;
extern aColor   colDarkGreen;
extern aColor   colDarkKhaki;
extern aColor   colDarkMagenta;
extern aColor   colDarkOliveGreen;
extern aColor   colDarkOrange;
extern aColor   colDarkOrchid;
extern aColor   colDarkRed;
extern aColor   colDarkSalmon;
extern aColor   colDarkSeaGreen;
extern aColor   colDarkSlateBlue;
extern aColor   colDarkSlateGray;
extern aColor   colDarkSlateGrey;
extern aColor   colDarkTurquoise;
extern aColor   colDarkViolet;
extern aColor   colDeepPink;
extern aColor   colDeepSkyBlue;
extern aColor   colDimGray;
extern aColor   colDimGrey;
extern aColor   colDodgerBlue;
extern aColor   colFireBrick;
extern aColor   colFloralWhite;
extern aColor   colForestGreen;
extern aColor   colFuchsia;
extern aColor   colGainsboro;
extern aColor   colGhostWhite;
extern aColor   colGold;
extern aColor   colGray;
extern aColor   colGrey;
extern aColor   colGreen;
extern aColor   colGreenYellow;
extern aColor   colHoneyDew;
extern aColor   colHotPink;
extern aColor   colIndianRed;
extern aColor   colIndigo;
extern aColor   colIvory;
extern aColor   colKhaki;
extern aColor   colLavender;
extern aColor   colLavenderBlush;
extern aColor   colLawnGreen;
extern aColor   colLemonChiffon;
extern aColor   colLightBlue;
extern aColor   colLightCoral;
extern aColor   colLightCyan;
extern aColor   colLightGoldenRodYellow;
extern aColor   colLightGray;
extern aColor   colLightGrey;
extern aColor   colLightGreen;
extern aColor   colLightPink;
extern aColor   colLightSalmon;
extern aColor   colLightSeaGreen;
extern aColor   colLightSkyBlue;
extern aColor   colLightSlateGray;
extern aColor   colLightSlateGrey;
extern aColor   colLightSteelBlue;
extern aColor   colLightYellow;
extern aColor   colLime;
extern aColor   colLimeGreen;
extern aColor   colLinen;
extern aColor   colMagenta;
extern aColor   colMaroon;
extern aColor   colMediumAquaMarine;
extern aColor   colMediumBlue;
extern aColor   colMediumOrchid;
extern aColor   colMediumPurple;
extern aColor   colMediumSeaGreen;
extern aColor   colMediumSlateBlue;
extern aColor   colMediumSpringGreen;
extern aColor   colMediumTurquoise;
extern aColor   colMediumVioletRed;
extern aColor   colMidnightBlue;
extern aColor   colMintCream;
extern aColor   colMistyRose;
extern aColor   colMoccasin;
extern aColor   colNavajoWhite;
extern aColor   colNavy;
extern aColor   colOldLace;
extern aColor   colOlive;
extern aColor   colOliveDrab;
extern aColor   colOrange;
extern aColor   colOrangeRed;
extern aColor   colOrchid;
extern aColor   colPaleGoldenRod;
extern aColor   colPaleGreen;
extern aColor   colPaleTurquoise;
extern aColor   colPaleVioletRed;
extern aColor   colPapayaWhip;
extern aColor   colPeachPuff;
extern aColor   colPeru;
extern aColor   colPink;
extern aColor   colPlum;
extern aColor   colPowderBlue;
extern aColor   colPurple;
extern aColor   colRebeccaPurple;
extern aColor   colRed;
extern aColor   colRosyBrown;
extern aColor   colRoyalBlue;
extern aColor   colSaddleBrown;
extern aColor   colSalmon;
extern aColor   colSandyBrown;
extern aColor   colSeaGreen;
extern aColor   colSeaShell;
extern aColor   colSienna;
extern aColor   colSilver;
extern aColor   colSkyBlue;
extern aColor   colSlateBlue;
extern aColor   colSlateGray;
extern aColor   colSlateGrey;
extern aColor   colSnow;
extern aColor   colSpringGreen;
extern aColor   colSteelBlue;
extern aColor   colDarkSteelBlue;
extern aColor   colTan;
extern aColor   colTeal;
extern aColor   colThistle;
extern aColor   colTomato;
extern aColor   colTurquoise;
extern aColor   colViolet;
extern aColor   colWheat;
extern aColor   colWhite;
extern aColor   colWhiteSmoke;
extern aColor   colYellow;
extern aColor   colYellowGreen;


} // namespace aUtil
} // namespace aLib
