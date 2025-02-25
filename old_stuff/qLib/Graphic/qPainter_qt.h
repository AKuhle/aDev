/*******************************************************************************
* \file qPainterQt.h
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


/*******************************************************************************
* includes
*******************************************************************************/
#include <QPainter>

#include "qLibDefs.h"
#include "Graphic/qPen_qt.h"
#include "Win/winDefs.h"
#include "Object/objectDefs.h"
#include "Math/mathDefs.h"

using namespace qLib::Win;
using namespace qLib::Object;
using namespace qLib::Math;


namespace qLib {
namespace Graphic {
namespace SysQt {


/*******************************************************************************
* class qPainterQt
*******************************************************************************/
class qPainterQt : private QPainter
{
    public:
        qPainterQt(qWin *_pWin);
        virtual ~qPainterQt();

        /*******************************************************************************
        * draw line
        * uses/sets the current Pen!
        *******************************************************************************/
        public:
            void            drawLine(s32         _s32StartX,
                                     s32         _s32StartY,
                                     s32         _s32EndX,
                                     s32         _s32EndY,
                                     const qPen  *_pPen = nullptr);

            void            drawLine(const qVector2D<s32>   &_v2dStart,
                                     const qVector2D<s32>   &_v2dEnd,
                                     const qPen             *_pPen = nullptr);


        /*******************************************************************************
        * draw rect
        * uses/sets the current Pen!
        *******************************************************************************/
        public:
            void            drawFilledRect(s32          _x,
                                           s32          _y,
                                           s32          _w,
                                           s32          _h,
                                           const qColor *_pColor = nullptr);

            void            drawFilledRect(const qRect2D<s32>   &_r,
                                           const qColor         *_pColor = nullptr);


        /*******************************************************************************
        * drawGradientRect
        *******************************************************************************/
        public:
            void            drawGradientRect(s32            _s32X,
                                             s32            _s32Y,
                                             s32            _s32W,
                                             s32            _s32H,
                                             s32            _s32GradStartX,
                                             s32            _s32GradStartY,
                                             s32            _s32GradEndX,
                                             s32            _s32GradEndY,
                                             const qColor   &_colStart,
                                             const qColor   &_colEnd);


            void            drawGradientRect(const qRect2D<s32>     &_r2d,
                                             const qVector2D<s32>   &_v2dGradStart,
                                             const qVector2D<s32>   &_v2dGradEnd,
                                             const qColor           &_colStart,
                                             const qColor           &_colEnd);


        private:
            void            setPen(const qPen *_pPen);
            void            setBrush(const qColor   *_pColor);

            QColor          toQColor(const qColor &_color);

}; // qPainterQt


} // namespace SysQt
} // namespace Graphic
} // namespace qLib

#endif // _USE_QT_


// namespace qLib
// {
//     /*******************************************************************************
//     * forwards
//     *******************************************************************************/
//     class qBrush;
//     class qPen;
//     class qPixmap;
//     class qFont;


//     /*******************************************************************************
//     * class qPainterQt
//     *******************************************************************************/
//     class qPainterQt : private qPainterQt
//     {
//         public:
//             qPainterQt(SysWin_t *_pWin);
//             virtual ~qPainterQt();


//         /*******************************************************************************
//         * mode
//         *******************************************************************************/
//         public:
//             void            SetPen(const qPen &_pen);
//             void            SetBrush(const qBrush &_brush);
//             void            SetFont(const qFont &_font);
//             void            SetCompositionMode(enumCompositionMode _eCompositionMode);

//         private:
//             void            SetPen(const qPen *_pPen);
//             void            SetBrush(const qBrush *_pBrush);
//             QColor          To_QColor(const qColor &_col) const;



//         /*******************************************************************************
//         * draw rect
//         * uses/sets the current Pen!
//         *******************************************************************************/
//         public:
//             void            DrawRect(s32         _s32X,
//                                      s32         _s32Y,
//                                      s32         _s32W,
//                                      s32         _s32H,
//                                      const qPen  *_pPen = nullptr);

//             void            DrawRect(const qVector2D<s32>   &_v2dCorner,
//                                      const qVector2D<s32>   &_v2dOppositeCorner,
//                                      const qPen             *_pPen = nullptr);

//             void            DrawRect(const qRect2D<s32>  &_r2d,
//                                      const qPen          *_pPen = nullptr);


//         /*******************************************************************************
//         * draw filled rect
//         * uses/sets the current Brush!
//         *******************************************************************************/
//         public:
//             void            DrawFilledRect(s32          _s32X,
//                                            s32          _s32Y,
//                                            s32          _s32W,
//                                            s32          _s32H,
//                                            const qBrush *_pBrush = nullptr);

//             void            DrawFilledRect(const qRect2D<s32>   &_r2d,
//                                            const qBrush         *_pBrush = nullptr);


//             void            DrawGradientRect(const qRect2D<s32> &_r2d,
//                                              s32                _s32GradStartX,
//                                              s32                _s32GradStartY,
//                                              s32                _s32GradEndX,
//                                              s32                _s32GradEndY,
//                                              const qColor        &_colStart,
//                                              const qColor        &_colEnd);


//         /*******************************************************************************
//         * DrawFilledCircle
//         * uses/sets the current pen and brush!
//         *******************************************************************************/
//         public:
//             void            DrawFilledCircle(s32         _s32CenterX,
//                                              s32         _s32CenterY,
//                                              s32         _s32Radius,
//                                              const qColor *_pRgba = nullptr);

//             void            DrawFilledCircle(const qVector2D<s32>    &_v2dCenter,
//                                              s32                     _s32Radius,
//                                              const qColor             *_pRgba = nullptr);

//             void            DrawFilledCircle(const qRect2D<s32>  &_r2dBounding,
//                                              const qColor         *_pRgba = nullptr);


//         /*******************************************************************************
//         * DrawText
//         * uses/sets the current Pen!
//         *******************************************************************************/
//         qDimension2D<s32>   TextSize(const qString16  &_sText);

//         void                DrawText(const qString16    &_sText,
//                                      qRect2D<s32>       _r2dBoundingBox,
//                                      u16                _u16Alignment,
//                                      const qFont        *_pFont         = nullptr,
//                                      const qPen         *_pPen          = nullptr,
//                                      qRect2D<s32>       *_pBoundingRect = nullptr);


//         /*******************************************************************************
//         * draw pixmap
//         *******************************************************************************/
//         public:
//             void            DrawPixmap(const qPixmap    &_pixmap,
//                                        s32              _s32X,
//                                        s32              _s32Y);

//         /*******************************************************************************
//         * draw picture
//         *******************************************************************************/
//        void                 DrawQImg(const QImage   &_img,
//                                      s32            _s32X,
//                                      s32            _s32Y);

//        //void             DrawQImgCentered(const QImage       &_img,
//        //                                  const Rect2D<s32>  &_r2dBoundingBox);

//     }; // class qPainterQt

// } // namespace qLib
















// //            void                SetClipRect(const Rect2D<s32>   &_r2d);


// //            /*******************************************************************************
// //            * DrawCircle
// //            * uses/sets the current Brush!
// //            *******************************************************************************/
// //            void                DrawCircle(s32		_s32CenterX,
// //                                           s32		_s32CenterY,
// //                                           s32		_s32Radius,
// //                                           const Rgba *_pRgba = nullptr);

// //            void                DrawCircle(const Vector2D<s32>    &_v2dCenterPoint,
// //                                           s32                    _s32Radius,
// //                                           const Rgba             *_pRgba = nullptr);


// //            /*******************************************************************************
// //            * DrawArc
// //            * uses/sets the current Pen!
// //            *******************************************************************************/
// //            void                DrawArc(s32		_s32X,
// //                                        s32		_s32Y,
// //                                        s32		_s32W,
// //                                        s32		_s32H,
// //                                        dbl		_dStartAngle,
// //                                        dbl		_dSpawnAngle,
// //                                        const aPen *_pPen = nullptr);

// //            void                DrawArc(const Rect2D<s32>   &_r2d,
// //                                        dbl                 _dStartAngle,
// //                                        dbl                 _dSpawnAngle,
// //                                        const aPen          *_pPen = nullptr);


// //            /*******************************************************************************
// //            * DrawBorder
// //            * uses/sets the current Brush!
// //            *******************************************************************************/
// //            void                DrawBorder(enumBorderType       _eBorderType,
// //                                           const Rect2D<s32>    &_r2dBorder,
// //                                           const s32            _s32Thickness,
// //                                           const Rgba           &_colBorderDark,
// //                                           const Rgba           &_colBorderBright);


// //            /*******************************************************************************
// //            * DrawArc
// //            * uses/sets the current Brush!
// //            *
// //            * The pen is used for the border
// //            * the brush is used to fill the arc
// //            *******************************************************************************/
// ////            void                DrawArc(qlRect2D<s32>   _r2dBoundingBox,
// ////                                        const dbl       _dStartAngle,
// ////                                        const dbl       _dDegree,
// ////                                        const Rgba    &_colBorder,
// ////                                        const Rgba    &_colFill);


// //            /*******************************************************************************
// //            * DrawPie
// //            * uses/sets the current Pen/Brush!
// //            *******************************************************************************/
// //            void                DrawFilledPie(const s32		_s32CenterX,
// //                                              const s32		_s32CenterY,
// //                                              const s32		_s32RadiusW,
// //                                              const s32		_s32RadiusH,
// //                                              const flt     _fltAngleStart, // 2*Pi => full angle
// //                                              const flt     _fltAngleSpan,
// //                                              const Rgba	*_pRgbPen   = nullptr,
// //                                              const Rgba	*_pRgbBrush	= nullptr);


// //            /*******************************************************************************
// //            * DrawText
// //            * uses/sets the current Pen!
// //            *******************************************************************************/
// //            void                DrawText(const aString  &_sText,
// //                                         const s32      _s32X,
// //                                         const s32      _s32Y,
// //                                         const aFont    *_pFont = nullptr,
// //                                         const Rgba     *_pRgba = nullptr);

// //            void                DrawText(const aString      &_sText,
// //                                         const s32          _s32BoundingX,
// //                                         const s32          _s32BoundingY,
// //                                         const s32          _s32BoundingW,
// //                                         const s32          _s32BoundingH,
// //                                         enumAlignmentHori  _eAlignmentH,
// //                                         enumAlignmentVert  _eAlignmentV,
// //                                         const aFont        *_pFont = nullptr,
// //                                         const Rgba         *_pRgba = nullptr,
// //                                         Rect2D<s32>        *pBoundingRect = nullptr);

// //            void                DrawTextMaximizedCentered(const aString &_sText,
// //                                                          Rect2D<s32>   _r2dBoundingBox,
// //                                                          const aFont   *_pFont = nullptr,
// //                                                          const Rgba    *_pRgba = nullptr,
// //                                                          Rect2D<s32>   *pBoundingRect = nullptr);


//             /*******************************************************************************
//             * DrawIcon
//             *******************************************************************************/
//             // void                DrawIcon(const qIcon&   _icn,
//             //                              s32            _s32X,
//             //                              s32            _s32Y);

//             // // draw the icon centered in the given rect
//             // void                DrawIconCentered(const qIcon&           _icn,
//             //                                      const qRect2D<s32>&    _r2d);


// //            /*******************************************************************************
// //            * DrawPic (aPicture)
// //            *******************************************************************************/
// //            void                DrawPicCentered(const aPicture      &_pic,
// //                                                const Rect2D<s32>   &_r2dBoundingBox);



// //        private:
// //            qPainterQt(const qPainterQt&	_rhs)                           = delete;
// //            qPainterQt(qPainterQt&&	_rhs)                               = delete;
// //            qPainterQt&             operator=(const qPainterQt&	_rhs)	= delete;
// //            qPainterQt&             operator=(qPainterQt&&	_rhs)		= delete;
