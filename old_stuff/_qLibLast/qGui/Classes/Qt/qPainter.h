/*******************************************************************************
* \file qPainter.h
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
#ifdef _USE_QT_


/*******************************************************************************
* includes
*******************************************************************************/
#include <QPainter>

#include "qGuiDefs.h"
#include "qRect2D.h"


namespace qLib
{
    /*******************************************************************************
    * forwards
    *******************************************************************************/
    class qPen;
    class qBrush;


    /*******************************************************************************
    * class qPainter
    *******************************************************************************/
    class qPainter : private QPainter
    {
        public:
            qPainter(SysWin_t *_pWin);
            virtual ~qPainter();


            void            SetPen(const qPen *_pPen = nullptr);
            void            SetBrush(const qBrush *_pBrush = nullptr);
            void            SetCompositionMode(enumCompositionMode _eCompositionMode);


       /*******************************************************************************
       * DrawLine
       * uses/sets the current Pen!
       *******************************************************************************/
        public:
             void           DrawLine(const qVector2D<s32>   &_v2dStart,
                                     const qVector2D<s32>   &_v2dEnd,
                                     const qPen             *_pPen = nullptr);

            void            DrawLine(s32         _s32StartX,
                                     s32         _s32StartY,
                                     s32         _s32EndX,
                                     s32         _s32EndY,
                                     const qPen  *_pPen = nullptr);


        /*******************************************************************************
        * DrawRect
        * uses/sets the current Pen!
        *******************************************************************************/
        void                DrawRect(s32         _s32X,
                                     s32         _s32Y,
                                     s32         _s32W,
                                     s32         _s32H,
                                     const qPen  *_pPen = nullptr);

        void                DrawRect(const qVector2D<s32>   &_v2dStart,
                                     const qVector2D<s32>   &_v2dEnd,
                                     const qPen             *_pPen = nullptr);

        void                DrawRect(const qRect2D<s32>  &_r2d,
                                     const qPen          *_pPen = nullptr);


        /*******************************************************************************
        * DrawFilledRect
        * uses/sets the current Brush!
        *******************************************************************************/
        public:
            void            DrawFilledRect(s32          _s32X,
                                           s32          _s32Y,
                                           s32          _s32W,
                                           s32          _s32H,
                                           const qBrush *_pBrush = nullptr);

            void            DrawFilledRect(const qRect2D<s32>   &_r2d,
                                           const qBrush         *_pBrush = nullptr);


        /*******************************************************************************
        * DrawImage
        *******************************************************************************/
        public:
            void            DrawQImg(const QImage   &_img,
                                     s32            _s32X,
                                     s32            _s32Y);

    }; // class qPainter

} // namespace qLib


#endif // _USE_QT_














    // void                SetPen(const qPen &_pen);
            // void                SetBrush(const qBrush &_brush);
//            void                SetFont(const aFont &_font);
//            void                SetCompositionMode(enumCompositionMode	_eCompositionMode);

//            void                SetClipRect(const Rect2D<s32>   &_r2d);


//            /*******************************************************************************
//            * DrawGradientRect
//            *******************************************************************************/
//            void                DrawGradientRect(s32            _s32X,
//                                                 s32            _s32Y,
//                                                 s32            _s32W,
//                                                 s32            _s32H,
//                                                 s32            _s32StartX,
//                                                 s32            _s32StartY,
//                                                 s32            _s32EndX,
//                                                 s32            _s32EndY,
//                                                 const Rgba     &_colStart,
//                                                 const Rgba     &_colEnd);

//            void                DrawGradientRect(const Rect2D<s32>  &_r2d,
//                                                 s32                _s32StartX,
//                                                 s32                _s32StartY,
//                                                 s32                _s32EndX,
//                                                 s32                _s32EndY,
//                                                 const Rgba         &_colStart,
//                                                 const Rgba         &_colEnd);

//            void                DrawGradientRect(const Rect2D<s32>      &_r2d,
//                                                 const Vector2D<s32>    &_v2dStart,
//                                                 const Vector2D<s32>    &_v2dEnd,
//                                                 const Rgba             &_colStart,
//                                                 const Rgba             &_colEnd);

//            /*******************************************************************************
//            * DrawCircle
//            * uses/sets the current Brush!
//            *******************************************************************************/
//            void                DrawCircle(s32		_s32CenterX,
//                                           s32		_s32CenterY,
//                                           s32		_s32Radius,
//                                           const Rgba *_pRgba = nullptr);

//            void                DrawCircle(const Vector2D<s32>    &_v2dCenterPoint,
//                                           s32                    _s32Radius,
//                                           const Rgba             *_pRgba = nullptr);


//            /*******************************************************************************
//            * DrawFilledCircle
//            * uses/sets the current Brush!
//            *******************************************************************************/
//            void                DrawFilledCircle(s32		_s32CenterX,
//                                                 s32		_s32CenterY,
//                                                 s32		_s32Radius,
//                                                 const Rgba *_pRgba = nullptr);

//            void                DrawFilledCircle(const Vector2D<s32>    &_v2dCenterPoint,
//                                                 s32                    _s32Radius,
//                                                 const Rgba             *_pRgba = nullptr);


//            /*******************************************************************************
//            * DrawArc
//            * uses/sets the current Pen!
//            *******************************************************************************/
//            void                DrawArc(s32		_s32X,
//                                        s32		_s32Y,
//                                        s32		_s32W,
//                                        s32		_s32H,
//                                        dbl		_dStartAngle,
//                                        dbl		_dSpawnAngle,
//                                        const aPen *_pPen = nullptr);

//            void                DrawArc(const Rect2D<s32>   &_r2d,
//                                        dbl                 _dStartAngle,
//                                        dbl                 _dSpawnAngle,
//                                        const aPen          *_pPen = nullptr);


//            /*******************************************************************************
//            * DrawBorder
//            * uses/sets the current Brush!
//            *******************************************************************************/
//            void                DrawBorder(enumBorderType       _eBorderType,
//                                           const Rect2D<s32>    &_r2dBorder,
//                                           const s32            _s32Thickness,
//                                           const Rgba           &_rgbaBorderDark,
//                                           const Rgba           &_rgbaBorderBright);


//            /*******************************************************************************
//            * DrawArc
//            * uses/sets the current Brush!
//            *
//            * The pen is used for the border
//            * the brush is used to fill the arc
//            *******************************************************************************/
////            void                DrawArc(qlRect2D<s32>   _r2dBoundingBox,
////                                        const dbl       _dStartAngle,
////                                        const dbl       _dDegree,
////                                        const Rgba    &_rgbaBorder,
////                                        const Rgba    &_rgbaFill);


//            /*******************************************************************************
//            * DrawPie
//            * uses/sets the current Pen/Brush!
//            *******************************************************************************/
//            void                DrawFilledPie(const s32		_s32CenterX,
//                                              const s32		_s32CenterY,
//                                              const s32		_s32RadiusW,
//                                              const s32		_s32RadiusH,
//                                              const flt     _fltAngleStart, // 2*Pi => full angle
//                                              const flt     _fltAngleSpan,
//                                              const Rgba	*_pRgbPen   = nullptr,
//                                              const Rgba	*_pRgbBrush	= nullptr);


//            /*******************************************************************************
//            * DrawText
//            * uses/sets the current Pen!
//            *******************************************************************************/
//            Dimension2D<s32>    TextSize(const aString  &_sText);

//            void                DrawText(const aString  &_sText,
//                                         const s32      _s32X,
//                                         const s32      _s32Y,
//                                         const aFont    *_pFont = nullptr,
//                                         const Rgba     *_pRgba = nullptr);

//            void                DrawText(const aString      &_sText,
//                                         const s32          _s32BoundingX,
//                                         const s32          _s32BoundingY,
//                                         const s32          _s32BoundingW,
//                                         const s32          _s32BoundingH,
//                                         enumAlignmentHori  _eAlignmentH,
//                                         enumAlignmentVert  _eAlignmentV,
//                                         const aFont        *_pFont = nullptr,
//                                         const Rgba         *_pRgba = nullptr,
//                                         Rect2D<s32>        *pBoundingRect = nullptr);

//            void                DrawText(const aString      &_sText,
//                                         Rect2D<s32>        _r2dBoundingBox,
//                                         enumAlignmentHori  _eAlignmentH,
//                                         enumAlignmentVert  _eAlignmentV,
//                                         const aFont        *_pFont = nullptr,
//                                         const Rgba         *_pRgba = nullptr,
//                                         Rect2D<s32>        *pBoundingRect  = nullptr);

//            void                DrawTextCentered(const aString  &_sText,
//                                                 Rect2D<s32>    _r2dBoundingBox,
//                                                 const aFont    *_pFont = nullptr,
//                                                 const Rgba     *_pRgba = nullptr,
//                                                 Rect2D<s32>    *pBoundingRect = nullptr);

//            void                DrawTextMaximizedCentered(const aString &_sText,
//                                                          Rect2D<s32>   _r2dBoundingBox,
//                                                          const aFont   *_pFont = nullptr,
//                                                          const Rgba    *_pRgba = nullptr,
//                                                          Rect2D<s32>   *pBoundingRect = nullptr);


            /*******************************************************************************
            * DrawIcon
            *******************************************************************************/
            // void                DrawIcon(const qIcon&   _icn,
            //                              s32            _s32X,
            //                              s32            _s32Y);

            // // draw the icon centered in the given rect
            // void                DrawIconCentered(const qIcon&           _icn,
            //                                      const qRect2D<s32>&    _r2d);


//            /*******************************************************************************
//            * DrawPic (aPicture)
//            *******************************************************************************/
//            void                DrawPicCentered(const aPicture      &_pic,
//                                                const Rect2D<s32>   &_r2dBoundingBox);

//            void                DrawQImgCentered(const QImage       &_img,
//                                                 const Rect2D<s32>  &_r2dBoundingBox);


//        private:
//            QColor              To_QColor(const Rgba    &_rgba) const;

//        private:
//            qPainter(const qPainter&	_rhs)                           = delete;
//            qPainter(qPainter&&	_rhs)                               = delete;
//            qPainter&             operator=(const qPainter&	_rhs)	= delete;
//            qPainter&             operator=(qPainter&&	_rhs)		= delete;
