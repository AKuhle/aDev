/*******************************************************************************
* \file qPainterQt.cpp
* \author Andreas Kuhlewind
*
* \brief
*
*  Detailed description starts here.
*******************************************************************************/
#ifdef _USE_QT_


/*******************************************************************************
* includes
*******************************************************************************/
#include "Graphic/qPainter_qt.h"
#include "Win/FrameWin/qWin.h"
#include "Math/qRect2D.h"
#include "Object/qColor.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace qLib {
namespace Graphic {
namespace SysQt {


/*******************************************************************************
* qPainterQt::qPainterQt
*******************************************************************************/
qPainterQt::qPainterQt(qWin *_pWin)
: QPainter(_pWin->getQWidget())
{
} // qPainterQt::qPainterQt


/*******************************************************************************
* qPainterQt::~qPainterQt
*******************************************************************************/
qPainterQt::~qPainterQt()
{
} // qPainterQt:.~qPainterQt


/*******************************************************************************
* qPainterQt::drawLine
*******************************************************************************/
void qPainterQt::drawLine(s32          _s32StartX,
                          s32          _s32StartY,
                          s32          _s32EndX,
                          s32          _s32EndY,
                          const qPen   *_pPen /*= nullptr*/)
{
    setPen(_pPen);

    QPainter::drawLine(_s32StartX, _s32StartY, _s32EndX, _s32EndY);
} // qPainterQt::drawLine


/*******************************************************************************
* qPainterQt::drawLine
*******************************************************************************/
void qPainterQt::drawLine(const qVector2D<s32>    &_v2dStart,
                          const qVector2D<s32>    &_v2dEnd,
                          const qPen              *_pPen /*= nullptr*/)
{
    drawLine(_v2dStart.x(), _v2dStart.y(), _v2dEnd.x(), _v2dEnd.y(), _pPen);
} // qPainterQt::drawLine


/*******************************************************************************
* qPainterQt::drawFilledRect
*******************************************************************************/
void qPainterQt::drawFilledRect(s32             _x,
                                s32             _y,
                                s32             _w,
                                s32             _h,
                                const qColor    *_pColor /*= nullptr*/)
{
    QPainter::setPen(Qt::NoPen);
    setBrush(_pColor);

    drawRect(_x, _y, _w, _h);

    // setPen(QPen(Qt::NoPen));
    // QRectF rectangle(0.0, 0.0, 3.0, 3.0);
    // fillRect(_x, _y, _w, _h, toQColor(colLightSeaGreen));
    // setRenderHint(QPainter::Antialiasing, false);
    // fillRect(rectangle, toQColor(colGreenYellow));
} // qPainterQt::drawFilledRect


/*******************************************************************************
* qPainterQt::drawFilledRect
*******************************************************************************/
void qPainterQt::drawFilledRect(const qRect2D<s32>  &_r,
                                const qColor        *_pColor /*= nullptr*/)
{
    drawFilledRect(_r.x(), _r.y(), _r.w(), _r.h(), _pColor);
} // qPainterQt::drawFilledRect


/*******************************************************************************
* qPainterQt::drawGradientRect
*******************************************************************************/
void qPainterQt::drawGradientRect(s32           _s32X,
                                  s32           _s32Y,
                                  s32           _s32W,
                                  s32           _s32H,
                                  s32           _s32GradStartX,
                                  s32           _s32GradStartY,
                                  s32           _s32GradEndX,
                                  s32           _s32GradEndY,
                                  const qColor  &_colStart,
                                  const qColor  &_colEnd)
{
    QLinearGradient grad(QPointF(_s32GradStartX, _s32GradStartY), QPointF(_s32GradEndX, _s32GradEndY));
    grad.setColorAt(0, toQColor(_colStart));
    grad.setColorAt(1, toQColor(_colEnd));

    fillRect(_s32X, _s32Y, _s32W, _s32H, grad);
} // qPainterQt::drawGradientRect


/*******************************************************************************
* qPainterQt::drawGradientRect
*******************************************************************************/
void qPainterQt::drawGradientRect(const qRect2D<s32>    &_r2d,
                                  const qVector2D<s32>  &_v2dGradStart,
                                  const qVector2D<s32>  &_v2dGradEnd,
                                  const qColor          &_colStart,
                                  const qColor          &_colEnd)
{
    drawGradientRect(_r2d.x(), _r2d.y(), _r2d.w(), _r2d.h(),
                     _v2dGradStart.x(), _v2dGradStart.y(),
                     _v2dGradEnd.x(), _v2dGradEnd.y(),
                     _colStart, _colEnd);
} // qPainterQt::drawGradientRect


/*******************************************************************************
* qPainterQt::setPen
*******************************************************************************/
void qPainterQt::setPen(const qPen *_pPen)
{
    CHECK_PRE_CONDITION_VOID(_pPen != nullptr);

    QPainter::setPen(*_pPen);
} // qPainterQt::setPen


/*******************************************************************************
* qPainterQt::setBrush
*******************************************************************************/
void qPainterQt::setBrush(const qColor   *_pColor)
{
    if (_pColor != nullptr)
    {
        QBrush  brush(toQColor(*_pColor));

        QPainter::setBrush(brush);
    }
} // qPainterQt::setBrush


/*******************************************************************************
* qPainterQt::toQColor
*******************************************************************************/
QColor qPainterQt::toQColor(const qColor &_color)
{
    return QColor::fromRgbF(_color.r(),
                            _color.g(),
                            _color.b(),
                            _color.a());
} // qPainterQt::toQColor


} // namespace SysQt
} // namespace qGraphic
} // namespace qLib

#endif // _USE_QT_




//     /*******************************************************************************
//     * qPainterQt::SetBrush
//     *******************************************************************************/
//     void qPainterQt::SetBrush(const qBrush  &_brush)
//     {
//         setBrush(_brush);
//     } // qPainterQt::SetBrush


//     /*******************************************************************************
//     * qPainterQt::SetFont
//     *******************************************************************************/
//     void qPainterQt::SetFont(const qFont &_font)
//     {
//         setFont(_font);
//     } // qPainterQt::SetFont


//     /*******************************************************************************
//     * qPainterQt::To_QColor
//     *******************************************************************************/
//     QColor qPainterQt::To_QColor(const qColor &_col) const
//     {
//        return QColor::fromRgbF(_col.r, _col.g, _col.b, _col.a);
//     } // qPainterQt::To_QColor


//     /*******************************************************************************
//     * qPainterQt::SetCompositionMode
//     *******************************************************************************/
//     void qPainterQt::SetCompositionMode(enumCompositionMode _eCompositionMode)
//     {
//         switch (_eCompositionMode)
//         {
//             case enumCompositionMode::SourceOver:
//                 setCompositionMode(qPainterQt::CompositionMode_SourceOver);
//                 break;

//             case enumCompositionMode::Xor:
//                 setCompositionMode(qPainterQt::CompositionMode_Xor);
//                 break;
//         }
//     } // qPainterQt::SetCompositionMode


//     /*******************************************************************************
//     * qPainterQt::SetBrush
//     *******************************************************************************/
//     void qPainterQt::SetBrush(const qBrush  *_pBrush)
//     {
//         if (_pBrush != nullptr)
//         {
//             setBrush(*_pBrush);
//         }
//     } // qPainterQt::SetBrush


//     /*******************************************************************************
//     * qPainterQt::DrawRect
//     *******************************************************************************/
//     void qPainterQt::DrawRect(s32         _s32X,
//                             s32         _s32Y,
//                             s32         _s32W,
//                             s32         _s32H,
//                             const qPen  *_pPen /*= nullptr*/)
//     {
//         SetPen(_pPen);

//         s32      r = _s32X + _s32W - 1;
//         s32      b = _s32Y + _s32H - 1;

//         DrawLine(_s32X, _s32Y, r, _s32Y);
//         DrawLine(r, _s32Y, r, b);
//         DrawLine(r, b, _s32X, b);
//         DrawLine(_s32X, b, _s32X, _s32Y);

//     } // qPainterQt::_DrawRect


//     /*******************************************************************************
//     * qPainterQt::DrawRect
//     *******************************************************************************/
//     void qPainterQt::DrawRect(const qVector2D<s32>    &_v2dCorner,
//                             const qVector2D<s32>    &_v2dOppositeCorner,
//                             const qPen              *_pPen /*= nullptr*/)
//     {
//         DrawRect(MU<s32>::Min(_v2dCorner.x, _v2dOppositeCorner.x),
//                  MU<s32>::Min(_v2dCorner.y, _v2dOppositeCorner.y),
//                  MU<s32>::Abs(_v2dCorner.x - _v2dOppositeCorner.x) + 1,
//                  MU<s32>::Abs(_v2dCorner.y - _v2dOppositeCorner.y) + 1,
//                  _pPen);

//     } // qPainterQt::DrawRect


//     /*******************************************************************************
//     * qPainterQt::DrawRect
//     *******************************************************************************/
//     void qPainterQt::DrawRect(const qRect2D<s32>  &_r2d,
//                             const qPen          *_pPen /*= nullptr*/)
//     {
//         DrawRect(_r2d.x, _r2d.y, _r2d.w, _r2d.h, _pPen);
//     } // qPainterQt::DrawRect


//     /*******************************************************************************
//     * qPainterQt::DrawFilledRect
//     *******************************************************************************/
//     void qPainterQt::DrawFilledRect(const qRect2D<s32>    &_r2d,
//                                   const qBrush          *_pBrush /*= nullptr*/)
//     {
//         DrawFilledRect(_r2d.x, _r2d.y, _r2d.w, _r2d.h, _pBrush);
//     } // qPainterQt::DrawFilledRect


//     /*******************************************************************************
//     * qPainterQt::DrawGradientRect
//     *******************************************************************************/
//     void qPainterQt::DrawGradientRect(s32         _s32X,
//                                     s32         _s32Y,
//                                     s32         _s32W,
//                                     s32         _s32H,
//                                     s32         _s32GradStartX,
//                                     s32         _s32GradStartY,
//                                     s32         _s32GradEndX,
//                                     s32         _s32GradEndY,
//                                     const qColor &_colStart,
//                                     const qColor &_colEnd)
//     {
//        QLinearGradient grad(QPointF(_s32GradStartX, _s32GradStartY), QPointF(_s32GradEndX, _s32GradEndY));
//        grad.setColorAt(0, To_QColor(_colStart));
//        grad.setColorAt(1, To_QColor(_colEnd));

//        fillRect(_s32X, _s32Y, _s32W, _s32H, grad);
//     } // qPainterQt::DrawGradientRect


//     /*******************************************************************************
//     * qPainterQt::DrawGradientRect
//     *******************************************************************************/
//     void qPainterQt::DrawGradientRect(const qRect2D<s32>  &_r2d,
//                                     s32                 _s32StartX,
//                                     s32                 _s32StartY,
//                                     s32                 _s32EndX,
//                                     s32                 _s32EndY,
//                                     const qColor         &_colStart,
//                                     const qColor         &_colEnd)
//     {
//        DrawGradientRect(_r2d.x, _r2d.y, _r2d.w, _r2d.h,
//                         _s32StartX, _s32StartY,
//                         _s32EndX, _s32EndY,
//                         _colStart, _colEnd);
//     } // qPainterQt::DrawGradientRect


//     /*******************************************************************************
//     * qPainterQt::DrawGradientRect
//     *******************************************************************************/
//     void qPainterQt::DrawGradientRect(const qRect2D<s32>      &_r2d,
//                                     const qVector2D<s32>    &_v2dGradStart,
//                                     const qVector2D<s32>    &_v2dGradEnd,
//                                     const qColor             &_colStart,
//                                     const qColor             &_colEnd)
//     {
//        DrawGradientRect(_r2d.x, _r2d.y, _r2d.w, _r2d.h,
//                         _v2dGradStart.x, _v2dGradStart.y,
//                         _v2dGradEnd.x, _v2dGradEnd.y,
//                         _colStart, _colEnd);
//     } // qPainterQt::DrawGradientRect


//     /*******************************************************************************
//     * qPainterQt::DrawFilledCircle
//     *******************************************************************************/
//     void qPainterQt::DrawFilledCircle(s32         _s32CenterX,
//                                     s32         _s32CenterY,
//                                     s32         _s32Radius,
//                                     const qColor *_pRgba /*= nullptr*/)
//     {
//         if (_pRgba != nullptr)
//         {
//             SetPen(qPen(*_pRgba));
//             SetBrush(qBrush(*_pRgba));
//         }

//         drawEllipse(_s32CenterX-_s32Radius, _s32CenterY-_s32Radius,
//         _s32Radius*2, _s32Radius*2);
//     } // qPainterQt::DrawFilledCircle


//     /*******************************************************************************
//     * qPainterQt::DrawFilledCircle
//     *******************************************************************************/
//     void qPainterQt::DrawFilledCircle(const qVector2D<s32>    &_v2dCenter,
//                                     s32                     _s32Radius,
//                                     const qColor             *_pRgba /*= nullptr*/)
//     {
//         DrawFilledCircle(_v2dCenter.x, _v2dCenter.y, _s32Radius, _pRgba);
//     } // qPainterQt::DrawFilledCircle


//     /*******************************************************************************
//     * qPainterQt::DrawFilledCircle
//     *******************************************************************************/
//     void qPainterQt::DrawFilledCircle(const qRect2D<s32>  &_r2dBounding,
//                                     const qColor         *_pRgba /*= nullptr*/)
//     {
//         DrawFilledCircle(_r2dBounding.CenterPoint().x, _r2dBounding.CenterPoint().y,
//                          MU<s32>::Min(_r2dBounding.w / 2, _r2dBounding.h/2),
//                          _pRgba);
//     } // qPainterQt::DrawFilledCircle


//     /*******************************************************************************
//     * qPainterQt::TextSize
//     *******************************************************************************/
//     qDimension2D<s32> qPainterQt::TextSize(const qString16    &_sText)
//     {
//         QRect   r = boundingRect(QRect(),
//                                  Qt::AlignLeft | Qt::AlignTop,
//                                  _sText.ToQString());

//         return qDimension2D<s32> (r.width(), r.height());
//     } // qPainterQt::TextSize


//     /*******************************************************************************
//     * qPainterQt::DrawText
//     *******************************************************************************/
//     void qPainterQt::DrawText(const qString16 &_sText,
//                             qRect2D<s32>    _r2dBoundingBox,
//                             u16             _u16Alignment,
//                             const qFont     *_pFont         /*= nullptr*/,
//                             const qPen      *_pPen          /*= nullptr*/,
//                             qRect2D<s32>    *_pBoundingRect /*= nullptr*/)
//     {
//         QRect r2dBound(_r2dBoundingBox.x, _r2dBoundingBox.y, _r2dBoundingBox.w, _r2dBoundingBox.h);

//         int iFlags = 0;
//         if (MU<u16>::AreBitsSet(_u16Alignment, AlignLeft))
//             iFlags += Qt::AlignLeft;
//         if (MU<u16>::AreBitsSet(_u16Alignment, AlignRight))
//             iFlags += Qt::AlignRight;
//         if (MU<u16>::AreBitsSet(_u16Alignment, AlignHCenter))
//             iFlags += Qt::AlignHCenter;
//         if (MU<u16>::AreBitsSet(_u16Alignment, AlignTop))
//             iFlags += Qt::AlignTop;
//         if (MU<u16>::AreBitsSet(_u16Alignment, AlignBottom))
//             iFlags += Qt::AlignBottom;
//         if (MU<u16>::AreBitsSet(_u16Alignment, AlignVCenter))
//             iFlags += Qt::AlignVCenter;

//         if (_pFont != nullptr)
//         {
//             SetFont(*_pFont);
//         }

//         if (_pPen != nullptr)
//         {
//             SetPen(*_pPen);
//         }

//         if (_pBoundingRect != nullptr)
//         {
//             QRect   rct;
//             drawText(r2dBound, iFlags, _sText.ToQString(), &rct);

//             _pBoundingRect->Set(rct.x(), rct.y(), rct.width(), rct.height());
//         }
//         else
//         {
//             drawText(r2dBound, iFlags, _sText.ToQString());
//         }
//     } // qPainterQt::DrawTextCentered


//     /*******************************************************************************
//     * qPainterQt::DrawPixmap
//     *******************************************************************************/
//     void qPainterQt::DrawPixmap(const qPixmap    &_pixmap,
//                               s32              _s32X,
//                               s32              _s32Y)
//     {
//         drawPixmap(_s32X, _s32Y, _pixmap);
//     } // qPainterQt::_DrawPixmap


//     /*******************************************************************************
//     * qPainterQt::DrawQImg
//     *******************************************************************************/
//     void qPainterQt::DrawQImg(const QImage    &_img,
//                             s32             _s32X,
//                             s32             _s32Y)
//     {
//         if (!_img.isNull())
//        {
//            // draw the image
//            drawImage(_s32X, _s32Y, _img);
//        }
//    } // qPainterQt::DrawQImg

// } // namespace qLib

// #endif // #ifdef _USE_QT_











//     /*******************************************************************************
//     * qPainterQt::DrawLine
//     *******************************************************************************/
//     // void qPainterQt::DrawLine(const qVector2D<s32>    &_v2dStart,
//     //                         const qVector2D<s32>    &_v2dEnd,
//     //                         const qPen              *_pPen /*= nullptr*/)
//     // {
//     //     DrawLine(_v2dStart.x, _v2dStart.y, _v2dEnd.x, _v2dEnd.y, _pPen);
//     // } // qPainterQt::DrawLine



// //     /*******************************************************************************
// //     * qPainterQt::DrawRect
// //     *******************************************************************************/
// //     void qPainterQt::DrawRect(const qRect2D<s32>  &_r2d,
// //                             const qPen          *_pPen /*= nullptr*/)
// //     {
// //         DrawRect(_r2d.x, _r2d.y, _r2d.w, _r2d.h, _pPen);
// //     }; // qPainterQt::DrawRect


// //     /*******************************************************************************
// //     * qPainterQt::DrawRect
// //     *******************************************************************************/
// //     void qPainterQt::DrawRect(const qVector2D<s32>    &_v2dStart,
// //                             const qVector2D<s32>    &_v2dEnd,
// //                             const qPen              *_pPen /*= nullptr*/)
// //     {
// //         DrawRect(Min(_v2dStart.x, _v2dEnd.x),
// //                  Min(_v2dStart.y, _v2dEnd.y),
// //                  Abs(_v2dStart.x - _v2dEnd.x) + 1,
// //                  Abs(_v2dStart.y - _v2dEnd.y) + 1,
// //                  _pPen);

// //     }; // qPainterQt::DrawRect



// //     /*******************************************************************************
// //     * qPainterQt::DrawFilledRect
// //     *******************************************************************************/
// //     void qPainterQt::DrawFilledRect(const qRect2D<s32>    &_r2d,
// //                                   const qBrush          *_pBrush /*= nullptr*/)
// //     {
// //         DrawFilledRect(_r2d.x, _r2d.y, _r2d.w, _r2d.h, _pBrush);
// //     } // qPainterQt::DrawFilledRect


// //     /*******************************************************************************
// //     * qPainterQt::DrawQImg
// //     *******************************************************************************/
// //     void qPainterQt::DrawQImg(const QImage   &_img,
// //                             s32            _s32X,
// //                             s32            _s32Y)
// //     {
// //         if (!_img.isNull())
// //         {
// //             // draw the image
// //             drawImage(_s32X, _s32Y, _img);
// //         }
// //     } // qPainterQt::DrawQImg


// // //    /*******************************************************************************
// // //    * qPainterQt::SetCompositionMode
// // //    *******************************************************************************/
// // //    void qPainterQt::SetCompositionMode(enumCompositionMode	_eCompositionMode)
// // //    {
// // //        switch (_eCompositionMode)
// // //        {
// // //            case enumCompositionMode::SourceOver:
// // //                setCompositionMode(qPainterQt::CompositionMode_SourceOver);
// // //                break;

// // //            case enumCompositionMode::Xor:
// // //                setCompositionMode(qPainterQt::RasterOp_SourceXorDestination);
// // //                break;
// // //        } // switch (_eCompositionMode)
// // //    } // qPainterQt::SetCompositionMode


// // //    /*******************************************************************************
// // //    * qPainterQt::SetClipRect
// // //    *******************************************************************************/
// // //    void qPainterQt::SetClipRect(const Rect2D<s32>   &_r2d)
// // //    {
// // //        QRect   r(_r2d.x, _r2d.y, _r2d.w, _r2d.h);

// // //        setClipRect(r);
// // //    } // qPainterQt::SetClipRect


// // //    /*******************************************************************************
// // //    * qPainterQt::DrawLine
// // //    *******************************************************************************/
// // //    void qPainterQt::DrawLine(const Vector2D<s32>  &_v2dStart,
// // //                            const Vector2D<s32>  &_v2dEnd,
// // //                            const aPen           *_pPen /*= nullptr*/)
// // //    {
// // //        DrawLine(_v2dStart.x, _v2dStart.y, _v2dEnd.x, _v2dEnd.y, _pPen);
// // //    } // qPainterQt::DrawLine


// // //    /*******************************************************************************
// // //    * qPainterQt::DrawCircle
// // //    *******************************************************************************/
// // //    void qPainterQt::DrawCircle(s32         _s32CenterX,
// // //                              s32         _s32CenterY,
// // //                              s32         _s32Radius,
// // //                              const Rgba  *_pRgba /*= nullptr*/)
// // //    {
// // //        if (_pRgba != nullptr)
// // //        {
// // //            aPen p(*_pRgba, 1);
// // //            SetPen(p);

// // //        }

// // //        // no fill
// // //        setBrush(Qt::NoBrush);

// // //        drawEllipse(_s32CenterX-_s32Radius, _s32CenterY-_s32Radius,
// // //                    _s32Radius*2, _s32Radius*2);
// // //    } // qPainterQt::DrawCircle


// // //    /*******************************************************************************
// // //    * qPainterQt::DrawCircle
// // //    *******************************************************************************/
// // //    void qPainterQt::DrawCircle(const Vector2D<s32> &_v2dCenterPoint,
// // //                              s32                 _s32Radius,
// // //                              const Rgba          *_pRgba /*= nullptr*/)
// // //    {
// // //        DrawCircle(_v2dCenterPoint.x, _v2dCenterPoint.y, _s32Radius, _pRgba);
// // //    } // qPainterQt::DrawFilledCircle


// // //    /*******************************************************************************
// // //    * qPainterQt::DrawArc
// // //    *******************************************************************************/
// // //    void qPainterQt::DrawArc(s32          _s32X,
// // //                           s32          _s32Y,
// // //                           s32          _s32W,
// // //                           s32          _s32H,
// // //                           dbl          _dStartAngle,
// // //                           dbl          _dSpawnAngle,
// // //                           const aPen   *_pPen /*= nullptr*/)
// // //    {
// // //        QRect   r(_s32X, _s32Y, _s32W, _s32H);
// // //        int     iStart  = _dStartAngle * 16;
// // //        int     iSpawn  = _dSpawnAngle * 16;

// // //        if (_pPen != nullptr)
// // //        {
// // //            SetPen(*_pPen);
// // //        }

// // //        drawArc(r, iStart, iSpawn);
// // //    } // qPainterQt::DrawArc


// // //    /*******************************************************************************
// // //    * qPainterQt::DrawArc
// // //    *******************************************************************************/
// // //    void qPainterQt::DrawArc(const Rect2D<s32>   &_r2d,
// // //                           dbl                 _dStartAngle,
// // //                           dbl                 _dSpawnAngle,
// // //                           const aPen          *_pPen /*= nullptr*/)
// // //    {
// // //        DrawArc(_r2d.x, _r2d.y, _r2d.w, _r2d.h, _dStartAngle, _dSpawnAngle, _pPen);
// // //    } // qPainterQt::DrawArc


// // //    /*******************************************************************************
// // //    * qPainterQt::DrawBorder
// // //    *******************************************************************************/
// // //    void qPainterQt::DrawBorder(enumBorderType       eBorderType,
// // //                             const Rect2D<s32>    &_r2dBorder,
// // //                             const s32            _s32Thickness,
// // //                             const Rgba           &_colBorderDark,
// // //                             const Rgba           &_colBorderBright)
// // //    {
// // //        s32     s32L        = _r2dBorder.l();
// // //        s32     s32T        = _r2dBorder.t();
// // //        s32     s32W        = _r2dBorder.w;
// // //        s32     s32H        = _r2dBorder.h;

// // //        s32     s32EdgeL    = _s32Thickness;
// // //        s32     s32EdgeT    = _s32Thickness;
// // //        s32     s32EdgeR    = _s32Thickness;
// // //        s32     s32EdgeB    = _s32Thickness;

// // //        switch (eBorderType)
// // //        {
// // //            case enumBorderType::None:
// // //                break;

// // //            case enumBorderType::Flat:
// // //                // left part
// // //                DrawFilledRect(s32L, s32T, s32EdgeL, s32H, &_colBorderDark);
// // //                // right part
// // //                DrawFilledRect(_r2dBorder.r() - s32EdgeR, s32T, s32EdgeR, s32H);
// // //                // top part
// // //                DrawFilledRect(s32L, s32T, s32W, s32EdgeT);
// // //                // bottom part
// // //                DrawFilledRect(s32L, _r2dBorder.b() - s32EdgeB, s32W, s32EdgeB);
// // //                break;

// // //            case enumBorderType::Gradient:
// // //                // left part
// // //                DrawGradientRect(s32L, s32T, s32EdgeL, s32H,
// // //                                 s32L, _r2dBorder.b(), s32L, s32T,
// // //                                 _colBorderDark, _colBorderBright);

// // //                // right part
// // //                DrawGradientRect(_r2dBorder.r() - s32EdgeR, s32T, s32EdgeR, s32H,
// // //                                 _r2dBorder.r(), _r2dBorder.b(), _r2dBorder.r(), s32T,
// // //                                 _colBorderDark, _colBorderBright);

// // //                // top part
// // //                DrawFilledRect(s32L, s32T, s32W, s32EdgeT, &_colBorderBright);

// // //                // bottom part
// // //                DrawFilledRect(s32L, _r2dBorder.b() - s32EdgeB, s32W, s32EdgeB, &_colBorderDark);
// // //                break;

// // //            case enumBorderType::Raised:
// // //                // right part
// // //                DrawFilledRect(_r2dBorder.r() - s32EdgeR, s32T, s32EdgeR, s32H, &_colBorderDark);
// // //                // bottom part
// // //                DrawFilledRect(s32L, _r2dBorder.b() - s32EdgeB, s32W, s32EdgeB);

// // //                // left part
// // //                DrawFilledRect(s32L, s32T, s32EdgeL, s32H, &_colBorderBright);
// // //                // top part
// // //                DrawFilledRect(s32L, s32T, s32W, s32EdgeT);
// // //                break;

// // //            case enumBorderType::Sunken:
// // //                // right part
// // //                DrawFilledRect(_r2dBorder.r() - s32EdgeR, s32T, s32EdgeR, s32H, &_colBorderBright);
// // //                // bottom part
// // //                DrawFilledRect(s32L, _r2dBorder.b() - s32EdgeB, s32W, s32EdgeB);

// // //                // left part
// // //                DrawFilledRect(s32L, s32T, s32EdgeL, s32H, &_colBorderDark);
// // //                // top part
// // //                DrawFilledRect(s32L, s32T, s32W, s32EdgeT);
// // //                break;

// // //        } // switch (eBorderType)
// // //    } // qPainterQt::DrawBorder


// // //    /*******************************************************************************
// // //    * qPainterQt::DrawFilledPie
// // //    *******************************************************************************/
// // //    void qPainterQt::DrawFilledPie(const s32		_s32CenterX,
// // //                                 const s32		_s32CenterY,
// // //                                 const s32		_s32RadiusW,
// // //                                 const s32		_s32RadiusH,
// // //                                 const flt      _fltAngleStart, // 2*Pi => full angle
// // //                                 const flt      _fltAngleSpan,
// // //                                 const Rgba     *_pRgbPen      /*= nullptr*/,
// // //                                 const Rgba     *_pRgbBrush	/*= nullptr*/)
// // //    {
// // //        if (_pRgbPen != nullptr)
// // //        {
// // //            aPen p(*_pRgbPen, 1);
// // //            SetPen(p);
// // //        }

// // //        if (_pRgbBrush != nullptr)
// // //        {
// // //            aBrush b(*_pRgbBrush);
// // //            SetBrush(b);
// // //        }

// // //        drawPie(_s32CenterX-_s32RadiusW, _s32CenterY-_s32RadiusH,
// // //                2*_s32RadiusW, 2*_s32RadiusH,
// // //                _fltAngleStart / M_PI * 2880.,
// // //                _fltAngleSpan / M_PI * 2880);
// // //    } // qlPainter::DrawFilledPie


// // //    /*******************************************************************************
// // //    * qPainterQt::DrawText
// // //    *******************************************************************************/
// // //    void qPainterQt::DrawText(const aString   &_sText,
// // //                            const s32       _s32X,
// // //                            const s32       _s32Y,
// // //                            const aFont     *_pFont /*= nullptr*/,
// // //                            const Rgba      *_pRgba /*= nullptr*/)
// // //    {
// // //        if (_pFont != nullptr)
// // //        {
// // //            SetFont(*_pFont);
// // //        }

// // //        if (_pRgba != nullptr)
// // //        {
// // //            SetPen(aPen(*_pRgba, 1));
// // //        }

// // //        drawText(_s32X, _s32Y, _sText);
// // //    } // qPainterQt::DrawText


// // //    /*******************************************************************************
// // //    * qPainterQt::DrawText
// // //    *******************************************************************************/
// // //    void qPainterQt::DrawText(const aString      &_sText,
// // //                            const s32          _s32BoundingX,
// // //                            const s32          _s32BoundingY,
// // //                            const s32          _s32BoundingW,
// // //                            const s32          _s32BoundingH,
// // //                            enumAlignmentHori  _eAlignmentH,
// // //                            enumAlignmentVert  _eAlignmentV,
// // //                            const aFont        *_pFont /*= nullptr*/,
// // //                            const Rgba         *_pRgba /*= nullptr*/,
// // //                            Rect2D<s32>        *pBoundingRect /*= nullptr*/)
// // //     {
// // //        if (_pFont != nullptr)
// // //        {
// // //            SetFont(*_pFont);
// // //        }

// // //        if (_pRgba != nullptr)
// // //        {
// // //            SetPen(aPen(*_pRgba, 1));
// // //        }

// // //        int             iFlags  = 0;
// // //        QRect           rect(_s32BoundingX, _s32BoundingY, _s32BoundingW, _s32BoundingH);

// // //        switch (_eAlignmentH)
// // //        {
// // //            case enumAlignmentHori::AlignLeft:
// // //                iFlags += Qt::AlignLeft;
// // //                break;

// // //            case enumAlignmentHori::AlignHCenter:
// // //                iFlags += Qt::AlignHCenter;
// // //                break;

// // //            case enumAlignmentHori::AlignRight:
// // //                iFlags += Qt::AlignRight;
// // //                break;
// // //        } // switch (_eAlignmentH)

// // //        switch (_eAlignmentV)
// // //        {
// // //            case enumAlignmentVert::AlignTop:
// // //                iFlags += Qt::AlignTop;
// // //                break;

// // //            case enumAlignmentVert::AlignVCenter:
// // //                iFlags += Qt::AlignVCenter;
// // //                break;

// // //            case enumAlignmentVert::AlignBottom:
// // //                iFlags += Qt::AlignBottom;
// // //        } // switch (_eAlignmentH)

// // //        if (pBoundingRect != nullptr)
// // //        {
// // //            QRect   rct;
// // //            drawText(rect, iFlags, _sText, &rct);

// // //            pBoundingRect->Set(rct.x, rct.y, rct.width(), rct.height());
// // //        }
// // //        else
// // //        {
// // //            drawText(rect, iFlags, _sText);
// // //        }
// // //     } // qPainterQt::DrawText


// // //    /*******************************************************************************
// // //    * qPainterQt::DrawText
// // //    *******************************************************************************/
// // //    void qPainterQt::DrawText(const aString      &_sText,
// // //                            Rect2D<s32>        _r2dBoundingBox,
// // //                            enumAlignmentHori  _eAlignmentH,
// // //                            enumAlignmentVert  _eAlignmentV,
// // //                            const aFont        *_pFont /*= nullptr*/,
// // //                            const Rgba         *_pRgba /*= nullptr*/,
// // //                            Rect2D<s32>        *pBoundingRect  /*= nullptr*/)
// // //    {
// // //        DrawText(_sText,
// // //                 _r2dBoundingBox.x, _r2dBoundingBox.y, _r2dBoundingBox.w, _r2dBoundingBox.h,
// // //                 _eAlignmentH, _eAlignmentV, _pFont, _pRgba, pBoundingRect);
// // //    } // qPainterQt::DrawText


// // //    /*******************************************************************************
// // //    * qPainterQt::DrawTextMaximizedCentered
// // //    *******************************************************************************/
// // //    void qPainterQt::DrawTextMaximizedCentered(const aString  &_sText,
// // //                                             Rect2D<s32>    _r2dBoundingBox,
// // //                                             const aFont    *_pFont /*= nullptr*/,
// // //                                             const Rgba     *_pRgba /*= nullptr*/,
// // //                                             Rect2D<s32>    *pBoundingRect /*= nullptr*/)
// // //    {
// // //        CHECK_PRE_CONDITION_VOID(_sText != "");

// // //        if (_pFont != nullptr)
// // //        {
// // //            SetFont(*_pFont);
// // //        }

// // //        if (_pRgba != nullptr)
// // //        {
// // //            SetPen(aPen(*_pRgba, 1));
// // //        }

// // //        QRect               rect(_r2dBoundingBox.x, _r2dBoundingBox.y, _r2dBoundingBox.w, _r2dBoundingBox.h);
// // //        s32                 s32FontSize = 20; // test font size, not to small for better acuracy
// // //        aFont               f = font();
// // //        Dimension2D<s32>    d2dSize;
// // //        dbl                 dScale;

// // //        // set a fontsize, not to small to achieve better proportions
// // //        f.setPointSize(s32FontSize);
// // //        setFont(f);

// // //        // get the required size of the text with the selected font
// // //        d2dSize = TextSize(_sText);

// // //        // get the scale factor
// // //        dScale = Min<dbl> (((dbl) _r2dBoundingBox.w) / d2dSize.w,
// // //                           ((dbl) _r2dBoundingBox.h) / d2dSize.h);

// // //        // set the scaled font size
// // //        f.setPointSize(dScale * s32FontSize);
// // //        setFont(f);

// // //        if (pBoundingRect != nullptr)
// // //        {
// // //            QRect   rct;
// // //            drawText(rect, Qt::AlignHCenter | Qt::AlignVCenter, _sText, &rct);

// // //            pBoundingRect->Set(rct.x, rct.y, rct.width(), rct.height());
// // //        }
// // //        else
// // //        {
// // //            drawText(rect, Qt::AlignHCenter | Qt::AlignVCenter, _sText);
// // //        }
// // //    } // qPainterQt::DrawTextMaximizedCentered


// // ////    /*******************************************************************************
// // ////    * qPainterQt::DrawArc
// // ////    *******************************************************************************/
// // ////    void qPainterQt::DrawArc(qlRect2D<s32>   _r2dBoundingBox,
// // ////                            const dbl       _dStartAngle,
// // ////                            const dbl       _dDegree,
// // ////                            const qlRgba    &_colBorder,
// // ////                            const qlRgba    &_colFill)
// // ////    {
// // ////        QRectF  r(_r2dBoundingBox.x, _r2dBoundingBox.y,
// // ////                  _r2dBoundingBox.w, _r2dBoundingBox.h);

// // ////        SetPen(Pen(_colBorder, 1));
// // ////        SetBrush(Brush(_colFill));

// // ////        drawPie(r,
// // ////                _dStartAngle * 16,
// // ////                _dDegree * 16);
// // ////    } // qPainterQt::DrawArc


// // ////    /*******************************************************************************
// // ////    * qPainterQt::DrawText
// // ////    *******************************************************************************/
// // ////    void qPainterQt::DrawText(const qlString     &_sText,
// // ////                             const s32          _s32X,
// // ////                             const s32          _s32Y,
// // ////                             const qlRgba       &_col)
// // ////    {
// // ////        SetPen(Pen(_col, 1));

// // ////        drawText(_s32X, _s32Y, _sText.To_QString());
// // ////    } // qPainterQt::DrawText




// //     /*******************************************************************************
// //     * qPainterQt::DrawIcon
// //     *******************************************************************************/
// //     // void qPainterQt::DrawIcon(const qIcon&    _icn,
// //     //                         s32             _s32X,
// //     //                         s32             _s32Y)
// //     // {
// //     //     if (_icn.IsValid())
// //     //     {
// //     //         drawPixmap(_s32X, _s32Y, _icn);
// //     //     }
// //     // } // qPainterQt::DrawIcon


// //     /*******************************************************************************
// //     * qPainterQt::DrawIconCentered
// //     *******************************************************************************/
// //     // void qPainterQt::DrawIconCentered(const qIcon&        _icn,
// //     //                                 const qRect2D<s32>& _r2d)
// //     // {
// //     //     if (_icn.IsValid())
// //     //     {
// //     //         drawPixmap(_r2d.x + (_r2d.w - _icn.w) / 2,
// //     //                    _r2d.y + (_r2d.h - _icn.h) / 2,
// //     //                    _icn);
// //     //     }
// //     // } // qPainterQt::DrawIconCentered


// // //    /*******************************************************************************
// // //    * qPainterQt::DrawPicCentered
// // //    *******************************************************************************/
// // //    void qPainterQt::DrawPicCentered(const aPicture       &_pic,
// // //                                   const Rect2D<s32>    &_r2dBoundingBox)
// // //    {
// // //        const QImage  *pImg = _pic.GetQImage(_r2dBoundingBox.w, _r2dBoundingBox.h);

// // //        if (pImg != nullptr && !pImg->isNull())
// // //        {
// // //            s32 s32X    = _r2dBoundingBox.l() + (_r2dBoundingBox.w - pImg->width()) / 2;
// // //            s32 s32Y    = _r2dBoundingBox.t() + (_r2dBoundingBox.h - pImg->height()) / 2;

// // //            // draw the image
// // //            drawImage(s32X, s32Y, *pImg);
// // //        }
// // //    } // qPainterQt::DrawPicCentered


// // //    /*******************************************************************************
// // //    * qPainterQt::DrawQImgCentered
// // //    *******************************************************************************/
// // //    void qPainterQt::DrawQImgCentered(const QImage        &_img,
// // //                                    const Rect2D<s32>   &_r2dBoundingBox)
// // //    {
// // //        if (!_img.isNull())
// // //        {
// // //            s32 s32X    = _r2dBoundingBox.l() + (_r2dBoundingBox.w - _img.width()) / 2;
// // //            s32 s32Y    = _r2dBoundingBox.t() + (_r2dBoundingBox.h - _img.height()) / 2;

// // //            // draw the image
// // //            drawImage(s32X, s32Y, _img);
// // //        }
// // //    } // qPainterQt::DrawQImgCentered




