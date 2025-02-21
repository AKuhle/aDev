/*******************************************************************************
* \file qColor.h
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
#include "qLibDefs.h"


namespace qLib {
namespace Object {


/*******************************************************************************
* class qColor
*******************************************************************************/
class qColor
{
    private:
        color_t  m_r { 0 };        //!< R-value (0.0 ... 1.0)
        color_t  m_g { 0 };        //!< G-value (0.0 ... 1.0)
        color_t  m_b { 0 };        //!< B-value (0.0 ... 1.0)
        color_t  m_a { 1 };        //!< alpha value, default = 1

    public:
        qColor(const color_t    _r,                                     // principal constructor
               const color_t 	_g,
               const color_t 	_b,
               const color_t    _a);

        // sets a to 1
        qColor(const color_t 	_r,                                     // delegation
               const color_t 	_g,
               const color_t 	_b) : qColor(_r, _g, _b, 1) {}

        qColor(): qColor((color_t) 0, 0, 0, 1) {}

        qColor(const qColor &_rhs);

        qColor(u32   _u32HexValue);

        static qColor   fromU8(u8   _r,
                               u8   _g,
                               u8   _b,
                               u8   _a = 255);

        qColor&         operator=(const qColor	&_rhs);

        bool            operator==(const qColor	&_rhs) const;
        bool            operator!=(const qColor	&_rhs) const;

        qColor          operator*(dbl _dMultiplier) const;

        qColor&         operator*=(dbl _dMultiplier);

        color_t         r() const               { return m_r; }
        color_t         g() const               { return m_g; }
        color_t         b() const               { return m_b; }
        color_t         a() const               { return m_a; }

        void            setRgba(const color_t    _r,
                                const color_t    _g,
                                const color_t    _b,
                                const color_t    _a);

        // leaves 'alpha' unchanged
        void            setRgb(const color_t     _r,
                               const color_t     _g,
                               const color_t 	 _b);

        color_t         average() const;

        void            invert();

        u64             toRgbHexValue() const;

        bool            isBlack() const;
        bool            isWhite() const;

//            static qColor    RandomColor();
//            static qColor    RandomBrightColor();


        friend std::ostream& operator<<(std::ostream    &_os,
                                        const qColor    &_col)
        {
            _os << "(r:" << _col.m_r
                << ", g:" << _col.m_g
                << ", b:" << _col.m_b
                << ", a:" << _col.m_a
                << ")";

            return _os;
        } // operator<<

}; // class qColor

extern qColor   colTransparent;

extern qColor   colGrey0;
extern qColor   colGrey5;
extern qColor   colGrey8;
extern qColor   colGrey10;
extern qColor   colGrey11;
extern qColor   colGrey15;
extern qColor   colGrey20;
extern qColor   colGrey25;
extern qColor   colGrey30;
extern qColor   colGrey35;
extern qColor   colGrey40;
extern qColor   colGrey45;
extern qColor   colGrey50;
extern qColor   colGrey55;
extern qColor   colGrey60;
extern qColor   colGrey65;
extern qColor   colGrey70;
extern qColor   colGrey75;
extern qColor   colGrey80;
extern qColor   colGrey85;
extern qColor   colGrey90;
extern qColor   colGrey95;
extern qColor   colGrey100;

extern qColor   colAliceBlue;
extern qColor   colAntiqueWhite;
extern qColor   colAqua;
extern qColor   colAquamarine;
extern qColor   colAzure;
extern qColor   colBeige;
extern qColor   colBisque;
extern qColor   colBlack;
extern qColor   colBlanchedAlmond;
extern qColor   colBlue;
extern qColor   colBlueViolet;
extern qColor   colBrown;
extern qColor   colBurlyWood;
extern qColor   colCadetBlue;
extern qColor   colChartreuse;
extern qColor   colChocolate;
extern qColor   colCoral;
extern qColor   colCornflowerBlue;
extern qColor   colCornsilk;
extern qColor   colCrimson;
extern qColor   colCyan;
extern qColor   colDarkBlue;
extern qColor   colDarkCyan;
extern qColor   colDarkGoldenRod;
extern qColor   colDarkGray;
extern qColor   colDarkGreen;
extern qColor   colDarkKhaki;
extern qColor   colDarkMagenta;
extern qColor   colDarkOliveGreen;
extern qColor   colDarkOrange;
extern qColor   colDarkOrchid;
extern qColor   colDarkRed;
extern qColor   colDarkSalmon;
extern qColor   colDarkSeaGreen;
extern qColor   colDarkSlateBlue;
extern qColor   colDarkSlateGray;
extern qColor   colDarkSlateGrey;
extern qColor   colDarkTurquoise;
extern qColor   colDarkViolet;
extern qColor   colDeepPink;
extern qColor   colDeepSkyBlue;
extern qColor   colDimGray;
extern qColor   colDimGrey;
extern qColor   colDodgerBlue;
extern qColor   colFireBrick;
extern qColor   colFloralWhite;
extern qColor   colForestGreen;
extern qColor   colFuchsia;
extern qColor   colGainsboro;
extern qColor   colGhostWhite;
extern qColor   colGold;
extern qColor   colGray;
extern qColor   colGrey;
extern qColor   colGreen;
extern qColor   colGreenYellow;
extern qColor   colHoneyDew;
extern qColor   colHotPink;
extern qColor   colIndianRed;
extern qColor   colIndigo;
extern qColor   colIvory;
extern qColor   colKhaki;
extern qColor   colLavender;
extern qColor   colLavenderBlush;
extern qColor   colLawnGreen;
extern qColor   colLemonChiffon;
extern qColor   colLightBlue;
extern qColor   colLightCoral;
extern qColor   colLightCyan;
extern qColor   colLightGoldenRodYellow;
extern qColor   colLightGray;
extern qColor   colLightGrey;
extern qColor   colLightGreen;
extern qColor   colLightPink;
extern qColor   colLightSalmon;
extern qColor   colLightSeaGreen;
extern qColor   colLightSkyBlue;
extern qColor   colLightSlateGray;
extern qColor   colLightSlateGrey;
extern qColor   colLightSteelBlue;
extern qColor   colLightYellow;
extern qColor   colLime;
extern qColor   colLimeGreen;
extern qColor   colLinen;
extern qColor   colMagenta;
extern qColor   colMaroon;
extern qColor   colMediumAquaMarine;
extern qColor   colMediumBlue;
extern qColor   colMediumOrchid;
extern qColor   colMediumPurple;
extern qColor   colMediumSeaGreen;
extern qColor   colMediumSlateBlue;
extern qColor   colMediumSpringGreen;
extern qColor   colMediumTurquoise;
extern qColor   colMediumVioletRed;
extern qColor   colMidnightBlue;
extern qColor   colMintCream;
extern qColor   colMistyRose;
extern qColor   colMoccasin;
extern qColor   colNavajoWhite;
extern qColor   colNavy;
extern qColor   colOldLace;
extern qColor   colOlive;
extern qColor   colOliveDrab;
extern qColor   colOrange;
extern qColor   colOrangeRed;
extern qColor   colOrchid;
extern qColor   colPaleGoldenRod;
extern qColor   colPaleGreen;
extern qColor   colPaleTurquoise;
extern qColor   colPaleVioletRed;
extern qColor   colPapayaWhip;
extern qColor   colPeachPuff;
extern qColor   colPeru;
extern qColor   colPink;
extern qColor   colPlum;
extern qColor   colPowderBlue;
extern qColor   colPurple;
extern qColor   colRebeccaPurple;
extern qColor   colRed;
extern qColor   colRosyBrown;
extern qColor   colRoyalBlue;
extern qColor   colSaddleBrown;
extern qColor   colSalmon;
extern qColor   colSandyBrown;
extern qColor   colSeaGreen;
extern qColor   colSeaShell;
extern qColor   colSienna;
extern qColor   colSilver;
extern qColor   colSkyBlue;
extern qColor   colSlateBlue;
extern qColor   colSlateGray;
extern qColor   colSlateGrey;
extern qColor   colSnow;
extern qColor   colSpringGreen;
extern qColor   colSteelBlue;
extern qColor   colDarkSteelBlue;
extern qColor   colTan;
extern qColor   colTeal;
extern qColor   colThistle;
extern qColor   colTomato;
extern qColor   colTurquoise;
extern qColor   colViolet;
extern qColor   colWheat;
extern qColor   colWhite;
extern qColor   colWhiteSmoke;
extern qColor   colYellow;
extern qColor   colYellowGreen;


} // namespace Object
} // namespace qLib
