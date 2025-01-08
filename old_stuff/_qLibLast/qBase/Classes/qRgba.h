/*******************************************************************************
* \file qRgba.h
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
#include "qBaseDefs.h"


namespace qLib
{
    /*******************************************************************************
    * class qRgba
    *******************************************************************************/
    class qRgba
	{
        public:
            Rgba_t  r { 0 };        //!< R-value (0.0 ... 1.0)
            Rgba_t  g { 0 };        //!< G-value (0.0 ... 1.0)
            Rgba_t  b { 0 };        //!< B-value (0.0 ... 1.0)
            Rgba_t  a { 1 };        //!< alpha value, default = 1

        public:
            qRgba(const Rgba_t  _r,                                     // principal constructor
                  const Rgba_t 	_g,
                  const Rgba_t 	_b,
                  const Rgba_t  _a);

            // sets a to 1
            qRgba(const Rgba_t 	_r,                                     // delegation
                  const Rgba_t 	_g,
                  const Rgba_t 	_b) : qRgba(_r, _g, _b, 1) {}

            qRgba(): qRgba((Rgba_t) 0, 0, 0, 1) {}

            qRgba(const qRgba &_rhs);

            qRgba(u32   _u32HexValue);

            static qRgba     FromU8(u8   _u8R,
                                   u8   _u8G,
                                   u8   _u8B,
                                   u8   _u8A = 255);

            qRgba&          operator=(const qRgba	&_rhs);

            bool            operator==(const qRgba	&_rhs) const;
            bool            operator!=(const qRgba	&_rhs) const;

            qRgba           operator*(dbl    _dMultiplier) const;

            qRgba&          operator*=(dbl    _dMultiplier);


            void            SetRgba(const Rgba_t    _r,
                                    const Rgba_t    _g,
                                    const Rgba_t    _b,
                                    const Rgba_t    _a);

            // leaves a unchanged
            void            SetRgb(const Rgba_t     _r,
                                   const Rgba_t     _g,
                                   const Rgba_t 	_b);

            Rgba_t          Average() const;

            void            Invert();

            u64             ToRgbHexValue() const;

            bool            IsBlack() const;
            bool            IsWhite() const;

//            static qRgba    RandomColor();
//            static qRgba    RandomBrightColor();

    }; // class qRgba

    extern qRgba   rgbaTransparent;

    extern qRgba   rgbaGrey0;
    extern qRgba   rgbaGrey5;
    extern qRgba   rgbaGrey10;
    extern qRgba   rgbaGrey15;
    extern qRgba   rgbaGrey20;
    extern qRgba   rgbaGrey25;
    extern qRgba   rgbaGrey30;
    extern qRgba   rgbaGrey35;
    extern qRgba   rgbaGrey40;
    extern qRgba   rgbaGrey45;
    extern qRgba   rgbaGrey50;
    extern qRgba   rgbaGrey55;
    extern qRgba   rgbaGrey60;
    extern qRgba   rgbaGrey65;
    extern qRgba   rgbaGrey70;
    extern qRgba   rgbaGrey75;
    extern qRgba   rgbaGrey80;
    extern qRgba   rgbaGrey85;
    extern qRgba   rgbaGrey90;
    extern qRgba   rgbaGrey95;
    extern qRgba   rgbaGrey100;

    extern qRgba   rgbaAliceBlue;
    extern qRgba   rgbaAntiqueWhite;
    extern qRgba   rgbaAqua;
    extern qRgba   rgbaAquamarine;
    extern qRgba   rgbaAzure;
    extern qRgba   rgbaBeige;
    extern qRgba   rgbaBisque;
    extern qRgba   rgbaBlack;
    extern qRgba   rgbaBlanchedAlmond;
    extern qRgba   rgbaBlue;
    extern qRgba   rgbaBlueViolet;
    extern qRgba   rgbaBrown;
    extern qRgba   rgbaBurlyWood;
    extern qRgba   rgbaCadetBlue;
    extern qRgba   rgbaChartreuse;
    extern qRgba   rgbaChocolate;
    extern qRgba   rgbaCoral;
    extern qRgba   rgbaCornflowerBlue;
    extern qRgba   rgbaCornsilk;
    extern qRgba   rgbaCrimson;
    extern qRgba   rgbaCyan;
    extern qRgba   rgbaDarkBlue;
    extern qRgba   rgbaDarkCyan;
    extern qRgba   rgbaDarkGoldenRod;
    extern qRgba   rgbaDarkGray;
    extern qRgba   rgbaDarkGreen;
    extern qRgba   rgbaDarkKhaki;
    extern qRgba   rgbaDarkMagenta;
    extern qRgba   rgbaDarkOliveGreen;
    extern qRgba   rgbaDarkOrange;
    extern qRgba   rgbaDarkOrchid;
    extern qRgba   rgbaDarkRed;
    extern qRgba   rgbaDarkSalmon;
    extern qRgba   rgbaDarkSeaGreen;
    extern qRgba   rgbaDarkSlateBlue;
    extern qRgba   rgbaDarkSlateGray;
    extern qRgba   rgbaDarkSlateGrey;
    extern qRgba   rgbaDarkTurquoise;
    extern qRgba   rgbaDarkViolet;
    extern qRgba   rgbaDeepPink;
    extern qRgba   rgbaDeepSkyBlue;
    extern qRgba   rgbaDimGray;
    extern qRgba   rgbaDimGrey;
    extern qRgba   rgbaDodgerBlue;
    extern qRgba   rgbaFireBrick;
    extern qRgba   rgbaFloralWhite;
    extern qRgba   rgbaForestGreen;
    extern qRgba   rgbaFuchsia;
    extern qRgba   rgbaGainsboro;
    extern qRgba   rgbaGhostWhite;
    extern qRgba   rgbaGold;
    extern qRgba   rgbaGray;
    extern qRgba   rgbaGrey;
    extern qRgba   rgbaGreen;
    extern qRgba   rgbaGreenYellow;
    extern qRgba   rgbaHoneyDew;
    extern qRgba   rgbaHotPink;
    extern qRgba   rgbaIndianRed;
    extern qRgba   rgbaIndigo;
    extern qRgba   rgbaIvory;
    extern qRgba   rgbaKhaki;
    extern qRgba   rgbaLavender;
    extern qRgba   rgbaLavenderBlush;
    extern qRgba   rgbaLawnGreen;
    extern qRgba   rgbaLemonChiffon;
    extern qRgba   rgbaLightBlue;
    extern qRgba   rgbaLightCoral;
    extern qRgba   rgbaLightCyan;
    extern qRgba   rgbaLightGoldenRodYellow;
    extern qRgba   rgbaLightGray;
    extern qRgba   rgbaLightGrey;
    extern qRgba   rgbaLightGreen;
    extern qRgba   rgbaLightPink;
    extern qRgba   rgbaLightSalmon;
    extern qRgba   rgbaLightSeaGreen;
    extern qRgba   rgbaLightSkyBlue;
    extern qRgba   rgbaLightSlateGray;
    extern qRgba   rgbaLightSlateGrey;
    extern qRgba   rgbaLightSteelBlue;
    extern qRgba   rgbaLightYellow;
    extern qRgba   rgbaLime;
    extern qRgba   rgbaLimeGreen;
    extern qRgba   rgbaLinen;
    extern qRgba   rgbaMagenta;
    extern qRgba   rgbaMaroon;
    extern qRgba   rgbaMediumAquaMarine;
    extern qRgba   rgbaMediumBlue;
    extern qRgba   rgbaMediumOrchid;
    extern qRgba   rgbaMediumPurple;
    extern qRgba   rgbaMediumSeaGreen;
    extern qRgba   rgbaMediumSlateBlue;
    extern qRgba   rgbaMediumSpringGreen;
    extern qRgba   rgbaMediumTurquoise;
    extern qRgba   rgbaMediumVioletRed;
    extern qRgba   rgbaMidnightBlue;
    extern qRgba   rgbaMintCream;
    extern qRgba   rgbaMistyRose;
    extern qRgba   rgbaMoccasin;
    extern qRgba   rgbaNavajoWhite;
    extern qRgba   rgbaNavy;
    extern qRgba   rgbaOldLace;
    extern qRgba   rgbaOlive;
    extern qRgba   rgbaOliveDrab;
    extern qRgba   rgbaOrange;
    extern qRgba   rgbaOrangeRed;
    extern qRgba   rgbaOrchid;
    extern qRgba   rgbaPaleGoldenRod;
    extern qRgba   rgbaPaleGreen;
    extern qRgba   rgbaPaleTurquoise;
    extern qRgba   rgbaPaleVioletRed;
    extern qRgba   rgbaPapayaWhip;
    extern qRgba   rgbaPeachPuff;
    extern qRgba   rgbaPeru;
    extern qRgba   rgbaPink;
    extern qRgba   rgbaPlum;
    extern qRgba   rgbaPowderBlue;
    extern qRgba   rgbaPurple;
    extern qRgba   rgbaRebeccaPurple;
    extern qRgba   rgbaRed;
    extern qRgba   rgbaRosyBrown;
    extern qRgba   rgbaRoyalBlue;
    extern qRgba   rgbaSaddleBrown;
    extern qRgba   rgbaSalmon;
    extern qRgba   rgbaSandyBrown;
    extern qRgba   rgbaSeaGreen;
    extern qRgba   rgbaSeaShell;
    extern qRgba   rgbaSienna;
    extern qRgba   rgbaSilver;
    extern qRgba   rgbaSkyBlue;
    extern qRgba   rgbaSlateBlue;
    extern qRgba   rgbaSlateGray;
    extern qRgba   rgbaSlateGrey;
    extern qRgba   rgbaSnow;
    extern qRgba   rgbaSpringGreen;
    extern qRgba   rgbaSteelBlue;
    extern qRgba   rgbaTan;
    extern qRgba   rgbaTeal;
    extern qRgba   rgbaThistle;
    extern qRgba   rgbaTomato;
    extern qRgba   rgbaTurquoise;
    extern qRgba   rgbaViolet;
    extern qRgba   rgbaWheat;
    extern qRgba   rgbaWhite;
    extern qRgba   rgbaWhiteSmoke;
    extern qRgba   rgbaYellow;
    extern qRgba   rgbaYellowGreen;
} // namespace qLib
