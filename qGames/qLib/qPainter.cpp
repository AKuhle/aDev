/*******************************************************************************
* \file qPainter.cpp
* \author Andreas Kuhlewind
*
* \brief
*
*  Detailed description starts here.
*******************************************************************************/


/*******************************************************************************
* includes
*******************************************************************************/
#include "qGuiDefs.h"

#include "qMathUtil.h"

#include "qPainter.h"
#include "qBrush.h"
#include "qPen.h"
#include "qFont.h"
#include "qPixmap.h"


namespace qLib
{
    /*******************************************************************************
    * qPainter::qPainter
    *******************************************************************************/
    qPainter::qPainter(SysWin_t *_pWin)
    : QPainter(_pWin)
    {
    } // qPainter::qPainter


    /*******************************************************************************
    * qPainter::~qPainter
    *******************************************************************************/
    qPainter::~qPainter()
    {
    } // qPainter:.~qPainter


    /*******************************************************************************
    * qPainter::SetPen
    *******************************************************************************/
    void qPainter::SetPen(const qPen &_pen)
    {
        setPen(_pen);
    } // qPainter::SetPen


    /*******************************************************************************
    * qPainter::SetBrush
    *******************************************************************************/
    void qPainter::SetBrush(const qBrush  &_brush)
    {
        setBrush(_brush);
    } // qPainter::SetBrush


    /*******************************************************************************
    * qPainter::SetFont
    *******************************************************************************/
    void qPainter::SetFont(const qFont &_font)
    {
        setFont(_font);
    } // qPainter::SetFont


    /*******************************************************************************
    * qPainter::To_QColor
    *******************************************************************************/
    QColor qPainter::To_QColor(const qColor &_col) const
    {
       return QColor::fromRgbF(_col.r, _col.g, _col.b, _col.a);
    } // qPainter::To_QColor


    /*******************************************************************************
    * qPainter::SetCompositionMode
    *******************************************************************************/
    void qPainter::SetCompositionMode(enumCompositionMode _eCompositionMode)
    {
        switch (_eCompositionMode)
        {
            case enumCompositionMode::SourceOver:
                setCompositionMode(qPainter::CompositionMode_SourceOver);
                break;

            case enumCompositionMode::Xor:
                setCompositionMode(qPainter::CompositionMode_Xor);
                break;
        }
    } // qPainter::SetCompositionMode


    /*******************************************************************************
    * qPainter::SetPen
    *******************************************************************************/
    void qPainter::SetPen(const qPen *_pPen)
    {
        if (_pPen != nullptr)
        {
            setPen(*_pPen);
        }
    } // qPainter::SetPen


    /*******************************************************************************
    * qPainter::SetBrush
    *******************************************************************************/
    void qPainter::SetBrush(const qBrush  *_pBrush)
    {
        if (_pBrush != nullptr)
        {
            setBrush(*_pBrush);
        }
    } // qPainter::SetBrush


    /*******************************************************************************
    * qPainter::DrawLine
    *******************************************************************************/
    void qPainter::DrawLine(s32          _s32StartX,
                            s32          _s32StartY,
                            s32          _s32EndX,
                            s32          _s32EndY,
                            const qPen   *_pPen /*= nullptr*/)
    {
        SetPen(_pPen);

        drawLine(_s32StartX, _s32StartY, _s32EndX, _s32EndY);
    } // qPainter::DrawLine


    /*******************************************************************************
    * qPainter::DrawLine
    *******************************************************************************/
    void qPainter::DrawLine(const qVector2D<s32>    &_v2dStart,
                            const qVector2D<s32>    &_v2dEnd,
                            const qPen              *_pPen /*= nullptr*/)
    {
        DrawLine(_v2dStart.x, _v2dStart.y, _v2dEnd.x, _v2dEnd.y, _pPen);
    } // qPainter::DrawLine


    /*******************************************************************************
    * qPainter::DrawRect
    *******************************************************************************/
    void qPainter::DrawRect(s32         _s32X,
                            s32         _s32Y,
                            s32         _s32W,
                            s32         _s32H,
                            const qPen  *_pPen /*= nullptr*/)
    {
        SetPen(_pPen);

        drawRect(_s32X, _s32Y, _s32W, _s32H);

    } // qPainter::_DrawRect


    /*******************************************************************************
    * qPainter::DrawRect
    *******************************************************************************/
    void qPainter::DrawRect(const qVector2D<s32>    &_v2dCorner,
                            const qVector2D<s32>    &_v2dOppositeCorner,
                            const qPen              *_pPen /*= nullptr*/)
    {
        DrawRect(MU<s32>::Min(_v2dCorner.x, _v2dOppositeCorner.x),
                 MU<s32>::Min(_v2dCorner.y, _v2dOppositeCorner.y),
                 MU<s32>::Abs(_v2dCorner.x - _v2dOppositeCorner.x) + 1,
                 MU<s32>::Abs(_v2dCorner.y - _v2dOppositeCorner.y) + 1,
                 _pPen);

    } // qPainter::DrawRect


    /*******************************************************************************
    * qPainter::DrawRect
    *******************************************************************************/
    void qPainter::DrawRect(const qRect2D<s32>  &_r2d,
                            const qPen          *_pPen /*= nullptr*/)
    {
        DrawRect(_r2d.x, _r2d.y, _r2d.w, _r2d.h, _pPen);
    } // qPainter::DrawRect


    /*******************************************************************************
    * qPainter::DrawRoundedRect
    *******************************************************************************/
    void qPainter::DrawRoundedRect(s32         _s32X,
                                   s32         _s32Y,
                                   s32         _s32W,
                                   s32         _s32H,
                                   s32         _s32RadiusX,
                                   s32         _s32RadiusY,
                                   const qPen  *_pPen /*= nullptr*/)
    {
        SetPen(_pPen);

        drawRoundedRect(_s32X, _s32Y, _s32W, _s32H, _s32RadiusX, _s32RadiusY);
    } // qPainter::DrawRoundedRect



    /*******************************************************************************
    * qPainter::DrawFilledRect
    *******************************************************************************/
    void qPainter::DrawFilledRect(s32           _s32X,
                                  s32           _s32Y,
                                  s32           _s32W,
                                  s32           _s32H,
                                  const qBrush  *_pBrush /*= nullptr*/)
    {
        setPen(Qt::NoPen);

        if (_pBrush != nullptr)
        {
            setBrush(*_pBrush);
        }

        drawRect(_s32X, _s32Y, _s32W, _s32H);
    } // qPainter::DrawFilledRect


    /*******************************************************************************
    * qPainter::DrawFilledRect
    *******************************************************************************/
    void qPainter::DrawFilledRect(const qRect2D<s32>    &_r2d,
                                  const qBrush          *_pBrush /*= nullptr*/)
    {
        DrawFilledRect(_r2d.x, _r2d.y, _r2d.w, _r2d.h, _pBrush);
    } // qPainter::DrawFilledRect


    /*******************************************************************************
    * qPainter::DrawGradientRect
    *******************************************************************************/
    void qPainter::DrawGradientRect(s32         _s32X,
                                    s32         _s32Y,
                                    s32         _s32W,
                                    s32         _s32H,
                                    s32         _s32GradStartX,
                                    s32         _s32GradStartY,
                                    s32         _s32GradEndX,
                                    s32         _s32GradEndY,
                                    const qColor &_colStart,
                                    const qColor &_colEnd)
    {
       QLinearGradient grad(QPointF(_s32GradStartX, _s32GradStartY), QPointF(_s32GradEndX, _s32GradEndY));
       grad.setColorAt(0, To_QColor(_colStart));
       grad.setColorAt(1, To_QColor(_colEnd));

       fillRect(_s32X, _s32Y, _s32W, _s32H, grad);
    } // qPainter::DrawGradientRect


    /*******************************************************************************
    * qPainter::DrawGradientRect
    *******************************************************************************/
    void qPainter::DrawGradientRect(const qRect2D<s32>  &_r2d,
                                    s32                 _s32StartX,
                                    s32                 _s32StartY,
                                    s32                 _s32EndX,
                                    s32                 _s32EndY,
                                    const qColor         &_colStart,
                                    const qColor         &_colEnd)
    {
       DrawGradientRect(_r2d.x, _r2d.y, _r2d.w, _r2d.h,
                        _s32StartX, _s32StartY,
                        _s32EndX, _s32EndY,
                        _colStart, _colEnd);
    } // qPainter::DrawGradientRect


    /*******************************************************************************
    * qPainter::DrawGradientRect
    *******************************************************************************/
    void qPainter::DrawGradientRect(const qRect2D<s32>      &_r2d,
                                    const qVector2D<s32>    &_v2dGradStart,
                                    const qVector2D<s32>    &_v2dGradEnd,
                                    const qColor             &_colStart,
                                    const qColor             &_colEnd)
    {
       DrawGradientRect(_r2d.x, _r2d.y, _r2d.w, _r2d.h,
                        _v2dGradStart.x, _v2dGradStart.y,
                        _v2dGradEnd.x, _v2dGradEnd.y,
                        _colStart, _colEnd);
    } // qPainter::DrawGradientRect


    /*******************************************************************************
    * qPainter::DrawCircle
    *******************************************************************************/
    void qPainter::DrawCircle(s32           _s32CenterX,
                              s32           _s32CenterY,
                              s32           _s32Radius,
                              const qPen    *_pPen /*= nullptr*/)
    {
        SetPen(_pPen);

        // no fill
        setBrush(Qt::NoBrush);

        drawEllipse(_s32CenterX - _s32Radius,
                    _s32CenterY -_s32Radius,
                    _s32Radius * 2,
                    _s32Radius * 2);
    } // qPainter::DrawCircle


    /*******************************************************************************
    * qPainter::DrawCircle
    *******************************************************************************/
    void qPainter::DrawCircle(const qVector2D<s32>  &_v2dCenterPoint,
                             s32                    _s32Radius,
                             const qPen             *_pPen /*= nullptr*/)
    {
       DrawCircle(_v2dCenterPoint.x, _v2dCenterPoint.y, _s32Radius, _pPen);
    } // qPainter::DrawFilledCircle


    /*******************************************************************************
    * qPainter::DrawFilledCircle
    *******************************************************************************/
    void qPainter::DrawFilledCircle(s32         _s32CenterX,
                                    s32         _s32CenterY,
                                    s32         _s32Radius,
                                    const qColor *_pRgba /*= nullptr*/)
    {
        if (_pRgba != nullptr)
        {
            SetPen(qPen(*_pRgba));
            SetBrush(qBrush(*_pRgba));
        }

        drawEllipse(_s32CenterX - _s32Radius,
                    _s32CenterY - _s32Radius,
                    _s32Radius * 2,
                    _s32Radius * 2);
    } // qPainter::DrawFilledCircle


    /*******************************************************************************
    * qPainter::DrawFilledCircle
    *******************************************************************************/
    void qPainter::DrawFilledCircle(const qVector2D<s32>    &_v2dCenter,
                                    s32                     _s32Radius,
                                    const qColor             *_pRgba /*= nullptr*/)
    {
        DrawFilledCircle(_v2dCenter.x, _v2dCenter.y, _s32Radius, _pRgba);
    } // qPainter::DrawFilledCircle


    /*******************************************************************************
    * qPainter::DrawFilledCircle
    *******************************************************************************/
    void qPainter::DrawFilledCircle(const qRect2D<s32>  &_r2dBounding,
                                    const qColor         *_pRgba /*= nullptr*/)
    {
        DrawFilledCircle(_r2dBounding.CenterPoint().x, _r2dBounding.CenterPoint().y,
                         MU<s32>::Min(_r2dBounding.w / 2, _r2dBounding.h/2),
                         _pRgba);
    } // qPainter::DrawFilledCircle


    /*******************************************************************************
    * qPainter::TextSize
    *******************************************************************************/
    qDimension2D<s32> qPainter::TextSize(const qString16    &_sText)
    {
        QRect   r = boundingRect(QRect(),
                                 Qt::AlignLeft | Qt::AlignTop,
                                 _sText.ToQString());

        return qDimension2D<s32> (r.width(), r.height());
    } // qPainter::TextSize


    /*******************************************************************************
    * qPainter::DrawText
    *******************************************************************************/
    void qPainter::DrawText(const qString16 &_sText,
                            qRect2D<s32>    _r2dBoundingBox,
                            u16             _u16Alignment,
                            const qFont     *_pFont             /*= nullptr*/,
                            const qPen      *_pPen              /*= nullptr*/,
                            qRect2D<s32>    *_pRealBoundingRect /*= nullptr*/)
    {
        QRect r2dBound(_r2dBoundingBox.x, _r2dBoundingBox.y, _r2dBoundingBox.w, _r2dBoundingBox.h);

        int iFlags = 0;
        if (MU<u16>::AreBitsSet(_u16Alignment, AlignLeft))
            iFlags += Qt::AlignLeft;
        if (MU<u16>::AreBitsSet(_u16Alignment, AlignRight))
            iFlags += Qt::AlignRight;
        if (MU<u16>::AreBitsSet(_u16Alignment, AlignHCenter))
            iFlags += Qt::AlignHCenter;
        if (MU<u16>::AreBitsSet(_u16Alignment, AlignTop))
            iFlags += Qt::AlignTop;
        if (MU<u16>::AreBitsSet(_u16Alignment, AlignBottom))
            iFlags += Qt::AlignBottom;
        if (MU<u16>::AreBitsSet(_u16Alignment, AlignVCenter))
            iFlags += Qt::AlignVCenter;

        if (_pFont != nullptr)
        {
            SetFont(*_pFont);
        }

        if (_pPen != nullptr)
        {
            SetPen(*_pPen);
        }

        if (_pRealBoundingRect != nullptr)
        {
            QRect   rct;
            drawText(r2dBound, iFlags, _sText.ToQString(), &rct);

            _pRealBoundingRect->Set(rct.x(), rct.y(), rct.width(), rct.height());
        }
        else
        {
            drawText(r2dBound, iFlags, _sText.ToQString());
        }
    } // qPainter::DrawTextCentered


    /*******************************************************************************
    * qPainter::DrawTextMaximizedCentered
    *******************************************************************************/
    void qPainter::DrawTextMaximizedCentered(const qString16    &_sText,
                                             qRect2D<s32>       _r2dBoundingBox,
                                             s32                _s32Margin          /*= 0*/,
                                             const qFont        *_pFont             /*= nullptr*/,
                                             const qPen         *_pPen              /*= nullptr*/,
                                             qRect2D<s32>       *_pRealBoundingRect /*= nullptr*/)
    {
        CHECK_PRE_CONDITION_VOID(_sText != "");

        QRect               r2dBound(_r2dBoundingBox.x + _s32Margin,
                                     _r2dBoundingBox.y + _s32Margin,
                                     _r2dBoundingBox.w - _s32Margin * 2,
                                     _r2dBoundingBox.h - _s32Margin * 2);

        if (_pFont != nullptr)
        {
            SetFont(*_pFont);
        }

        if (_pPen != nullptr)
        {
            SetPen(*_pPen);
        }

        s32                 s32FontSize = 20; // test font size, not to small for better acuracy
        QFont               f = font();
        qDimension2D<s32>   d2dSize;
        dbl                 dScale;

        // set a fontsize, not to small to achieve better proportions
        f.setPointSize(s32FontSize);
        setFont(f);

        QString     fff = font().family();

        QString     fff1 = fontInfo().family();
        QString     fff2 = fontInfo().styleName();

        // get the required size of the text with the selected font
        d2dSize = TextSize(_sText);

        // get the scale factor
        dScale = MU<dbl>::Min (((dbl) r2dBound.width()) / d2dSize.w,
                               ((dbl) r2dBound.height()) / d2dSize.h);

        // set the scaled font size
        f.setPointSize(dScale * s32FontSize);
        setFont(f);

        if (_pRealBoundingRect != nullptr)
        {
            QRect   rct;
            drawText(r2dBound, Qt::AlignHCenter | Qt::AlignVCenter, _sText.ToQString(), &rct);

            _pRealBoundingRect->Set(rct.x(), rct.y(), rct.width(), rct.height());
        }
        else
        {
            drawText(r2dBound, Qt::AlignHCenter | Qt::AlignVCenter, _sText.ToQString());
        }
    } // qPainter::DrawTextMaximizedCentered


    /*******************************************************************************
    * qPainter::DrawPixmap
    *******************************************************************************/
    void qPainter::DrawPixmap(const qPixmap    &_pixmap,
                              s32              _s32X,
                              s32              _s32Y)
    {
        drawPixmap(_s32X, _s32Y, _pixmap);
    } // qPainter::_DrawPixmap


    /*******************************************************************************
     * qPainter::DrawQPixmapCentered
     *******************************************************************************/
    void qPainter::DrawQPixmapCentered(const QPixmap        &_pixmap,
                                       const qRect2D<s32>   &_r2dBoundingBox)
    {
        if (!_pixmap.isNull())
        {
            s32 s32X    = _r2dBoundingBox.l() + (_r2dBoundingBox.w - _pixmap.width()) / 2;
            s32 s32Y    = _r2dBoundingBox.t() + (_r2dBoundingBox.h - _pixmap.height()) / 2;

            // draw the image
            drawPixmap(s32X, s32Y, _pixmap);
        }
    } // qPainter::DrawQPixmapCentered


    /*******************************************************************************
     * qPainter::DrawQPixmapMaximizedCentered
     *******************************************************************************/
    qRect2D<s32> qPainter::DrawQPixmapMaximizedCentered(const QPixmap        &_pixmap,
                                                        const qRect2D<s32>   &_r2dBoundingBox)
    {
        QPixmap      pixmap = _pixmap.scaled(_r2dBoundingBox.w, _r2dBoundingBox.h, Qt::KeepAspectRatio);
        qRect2D<s32> r2dPixmap;

        if (!pixmap.isNull())
        {
            s32 s32X    = _r2dBoundingBox.l() + (_r2dBoundingBox.w - pixmap.width()) / 2;
            s32 s32Y    = _r2dBoundingBox.t() + (_r2dBoundingBox.h - pixmap.height()) / 2;

            // draw the image
            drawPixmap(s32X, s32Y, pixmap);

            r2dPixmap.Set(s32X, s32Y, pixmap.width(), pixmap.height());
        }

        return r2dPixmap;
    } // qPainter::DrawQPixmapMaximizedCentered


    /*******************************************************************************
    * qPainter::DrawQImg
    *******************************************************************************/
    void qPainter::DrawQImg(const QImage    &_img,
                            s32             _s32X,
                            s32             _s32Y)
    {
        if (!_img.isNull())
       {
           // draw the image
           drawImage(_s32X, _s32Y, _img);
       }
   } // qPainter::DrawQImg


   /*******************************************************************************
    * qPainter::DrawQImgCentered
    *******************************************************************************/
   void qPainter::DrawQImgCentered(const QImage         &_img,
                                   const qRect2D<s32>   &_r2dBoundingBox)
   {
       if (!_img.isNull())
       {
           s32 s32X    = _r2dBoundingBox.l() + (_r2dBoundingBox.w - _img.width()) / 2;
           s32 s32Y    = _r2dBoundingBox.t() + (_r2dBoundingBox.h - _img.height()) / 2;

           // draw the image
           drawImage(s32X, s32Y, _img);
       }
   } // qPainter::DrawQImgCentered


   /*******************************************************************************
    * qPainter::DrawQImgMaximizedCentered
    *******************************************************************************/
   qRect2D<s32> qPainter::DrawQImgMaximizedCentered(const QImage         &_img,
                                                    const qRect2D<s32>   &_r2dBoundingBox)
   {
       QImage       img = _img.scaled(_r2dBoundingBox.w, _r2dBoundingBox.h, Qt::KeepAspectRatio);
       qRect2D<s32> r2dImg;

       if (!img.isNull())
       {
           s32 s32X    = _r2dBoundingBox.l() + (_r2dBoundingBox.w - img.width()) / 2;
           s32 s32Y    = _r2dBoundingBox.t() + (_r2dBoundingBox.h - img.height()) / 2;

           // draw the image
           drawImage(s32X, s32Y, img);

           r2dImg.Set(s32X, s32Y, img.width(), img.height());
       }

       return r2dImg;
   } // qPainter::DrawQImgMaximizedCentered

} // namespace qLib











    /*******************************************************************************
    * qPainter::DrawLine
    *******************************************************************************/
    // void qPainter::DrawLine(const qVector2D<s32>    &_v2dStart,
    //                         const qVector2D<s32>    &_v2dEnd,
    //                         const qPen              *_pPen /*= nullptr*/)
    // {
    //     DrawLine(_v2dStart.x, _v2dStart.y, _v2dEnd.x, _v2dEnd.y, _pPen);
    // } // qPainter::DrawLine



//     /*******************************************************************************
//     * qPainter::DrawRect
//     *******************************************************************************/
//     void qPainter::DrawRect(const qRect2D<s32>  &_r2d,
//                             const qPen          *_pPen /*= nullptr*/)
//     {
//         DrawRect(_r2d.x, _r2d.y, _r2d.w, _r2d.h, _pPen);
//     }; // qPainter::DrawRect


//     /*******************************************************************************
//     * qPainter::DrawRect
//     *******************************************************************************/
//     void qPainter::DrawRect(const qVector2D<s32>    &_v2dStart,
//                             const qVector2D<s32>    &_v2dEnd,
//                             const qPen              *_pPen /*= nullptr*/)
//     {
//         DrawRect(Min(_v2dStart.x, _v2dEnd.x),
//                  Min(_v2dStart.y, _v2dEnd.y),
//                  Abs(_v2dStart.x - _v2dEnd.x) + 1,
//                  Abs(_v2dStart.y - _v2dEnd.y) + 1,
//                  _pPen);

//     }; // qPainter::DrawRect



//     /*******************************************************************************
//     * qPainter::DrawFilledRect
//     *******************************************************************************/
//     void qPainter::DrawFilledRect(const qRect2D<s32>    &_r2d,
//                                   const qBrush          *_pBrush /*= nullptr*/)
//     {
//         DrawFilledRect(_r2d.x, _r2d.y, _r2d.w, _r2d.h, _pBrush);
//     } // qPainter::DrawFilledRect


//     /*******************************************************************************
//     * qPainter::DrawQImg
//     *******************************************************************************/
//     void qPainter::DrawQImg(const QImage   &_img,
//                             s32            _s32X,
//                             s32            _s32Y)
//     {
//         if (!_img.isNull())
//         {
//             // draw the image
//             drawImage(_s32X, _s32Y, _img);
//         }
//     } // qPainter::DrawQImg


// //    /*******************************************************************************
// //    * qPainter::SetCompositionMode
// //    *******************************************************************************/
// //    void qPainter::SetCompositionMode(enumCompositionMode	_eCompositionMode)
// //    {
// //        switch (_eCompositionMode)
// //        {
// //            case enumCompositionMode::SourceOver:
// //                setCompositionMode(qPainter::CompositionMode_SourceOver);
// //                break;

// //            case enumCompositionMode::Xor:
// //                setCompositionMode(qPainter::RasterOp_SourceXorDestination);
// //                break;
// //        } // switch (_eCompositionMode)
// //    } // qPainter::SetCompositionMode


// //    /*******************************************************************************
// //    * qPainter::SetClipRect
// //    *******************************************************************************/
// //    void qPainter::SetClipRect(const Rect2D<s32>   &_r2d)
// //    {
// //        QRect   r(_r2d.x, _r2d.y, _r2d.w, _r2d.h);

// //        setClipRect(r);
// //    } // qPainter::SetClipRect


// //    /*******************************************************************************
// //    * qPainter::DrawLine
// //    *******************************************************************************/
// //    void qPainter::DrawLine(const Vector2D<s32>  &_v2dStart,
// //                            const Vector2D<s32>  &_v2dEnd,
// //                            const aPen           *_pPen /*= nullptr*/)
// //    {
// //        DrawLine(_v2dStart.x, _v2dStart.y, _v2dEnd.x, _v2dEnd.y, _pPen);
// //    } // qPainter::DrawLine


// //    /*******************************************************************************
// //    * qPainter::DrawArc
// //    *******************************************************************************/
// //    void qPainter::DrawArc(s32          _s32X,
// //                           s32          _s32Y,
// //                           s32          _s32W,
// //                           s32          _s32H,
// //                           dbl          _dStartAngle,
// //                           dbl          _dSpawnAngle,
// //                           const aPen   *_pPen /*= nullptr*/)
// //    {
// //        QRect   r(_s32X, _s32Y, _s32W, _s32H);
// //        int     iStart  = _dStartAngle * 16;
// //        int     iSpawn  = _dSpawnAngle * 16;

// //        if (_pPen != nullptr)
// //        {
// //            SetPen(*_pPen);
// //        }

// //        drawArc(r, iStart, iSpawn);
// //    } // qPainter::DrawArc


// //    /*******************************************************************************
// //    * qPainter::DrawArc
// //    *******************************************************************************/
// //    void qPainter::DrawArc(const Rect2D<s32>   &_r2d,
// //                           dbl                 _dStartAngle,
// //                           dbl                 _dSpawnAngle,
// //                           const aPen          *_pPen /*= nullptr*/)
// //    {
// //        DrawArc(_r2d.x, _r2d.y, _r2d.w, _r2d.h, _dStartAngle, _dSpawnAngle, _pPen);
// //    } // qPainter::DrawArc


// //    /*******************************************************************************
// //    * qPainter::DrawBorder
// //    *******************************************************************************/
// //    void qPainter::DrawBorder(enumBorderType       eBorderType,
// //                             const Rect2D<s32>    &_r2dBorder,
// //                             const s32            _s32Thickness,
// //                             const Rgba           &_colBorderDark,
// //                             const Rgba           &_colBorderBright)
// //    {
// //        s32     s32L        = _r2dBorder.l();
// //        s32     s32T        = _r2dBorder.t();
// //        s32     s32W        = _r2dBorder.w;
// //        s32     s32H        = _r2dBorder.h;

// //        s32     s32EdgeL    = _s32Thickness;
// //        s32     s32EdgeT    = _s32Thickness;
// //        s32     s32EdgeR    = _s32Thickness;
// //        s32     s32EdgeB    = _s32Thickness;

// //        switch (eBorderType)
// //        {
// //            case enumBorderType::None:
// //                break;

// //            case enumBorderType::Flat:
// //                // left part
// //                DrawFilledRect(s32L, s32T, s32EdgeL, s32H, &_colBorderDark);
// //                // right part
// //                DrawFilledRect(_r2dBorder.r() - s32EdgeR, s32T, s32EdgeR, s32H);
// //                // top part
// //                DrawFilledRect(s32L, s32T, s32W, s32EdgeT);
// //                // bottom part
// //                DrawFilledRect(s32L, _r2dBorder.b() - s32EdgeB, s32W, s32EdgeB);
// //                break;

// //            case enumBorderType::Gradient:
// //                // left part
// //                DrawGradientRect(s32L, s32T, s32EdgeL, s32H,
// //                                 s32L, _r2dBorder.b(), s32L, s32T,
// //                                 _colBorderDark, _colBorderBright);

// //                // right part
// //                DrawGradientRect(_r2dBorder.r() - s32EdgeR, s32T, s32EdgeR, s32H,
// //                                 _r2dBorder.r(), _r2dBorder.b(), _r2dBorder.r(), s32T,
// //                                 _colBorderDark, _colBorderBright);

// //                // top part
// //                DrawFilledRect(s32L, s32T, s32W, s32EdgeT, &_colBorderBright);

// //                // bottom part
// //                DrawFilledRect(s32L, _r2dBorder.b() - s32EdgeB, s32W, s32EdgeB, &_colBorderDark);
// //                break;

// //            case enumBorderType::Raised:
// //                // right part
// //                DrawFilledRect(_r2dBorder.r() - s32EdgeR, s32T, s32EdgeR, s32H, &_colBorderDark);
// //                // bottom part
// //                DrawFilledRect(s32L, _r2dBorder.b() - s32EdgeB, s32W, s32EdgeB);

// //                // left part
// //                DrawFilledRect(s32L, s32T, s32EdgeL, s32H, &_colBorderBright);
// //                // top part
// //                DrawFilledRect(s32L, s32T, s32W, s32EdgeT);
// //                break;

// //            case enumBorderType::Sunken:
// //                // right part
// //                DrawFilledRect(_r2dBorder.r() - s32EdgeR, s32T, s32EdgeR, s32H, &_colBorderBright);
// //                // bottom part
// //                DrawFilledRect(s32L, _r2dBorder.b() - s32EdgeB, s32W, s32EdgeB);

// //                // left part
// //                DrawFilledRect(s32L, s32T, s32EdgeL, s32H, &_colBorderDark);
// //                // top part
// //                DrawFilledRect(s32L, s32T, s32W, s32EdgeT);
// //                break;

// //        } // switch (eBorderType)
// //    } // qPainter::DrawBorder


// //    /*******************************************************************************
// //    * qPainter::DrawFilledPie
// //    *******************************************************************************/
// //    void qPainter::DrawFilledPie(const s32		_s32CenterX,
// //                                 const s32		_s32CenterY,
// //                                 const s32		_s32RadiusW,
// //                                 const s32		_s32RadiusH,
// //                                 const flt      _fltAngleStart, // 2*Pi => full angle
// //                                 const flt      _fltAngleSpan,
// //                                 const Rgba     *_pRgbPen      /*= nullptr*/,
// //                                 const Rgba     *_pRgbBrush	/*= nullptr*/)
// //    {
// //        if (_pRgbPen != nullptr)
// //        {
// //            aPen p(*_pRgbPen, 1);
// //            SetPen(p);
// //        }

// //        if (_pRgbBrush != nullptr)
// //        {
// //            aBrush b(*_pRgbBrush);
// //            SetBrush(b);
// //        }

// //        drawPie(_s32CenterX-_s32RadiusW, _s32CenterY-_s32RadiusH,
// //                2*_s32RadiusW, 2*_s32RadiusH,
// //                _fltAngleStart / M_PI * 2880.,
// //                _fltAngleSpan / M_PI * 2880);
// //    } // qlPainter::DrawFilledPie


// //    /*******************************************************************************
// //    * qPainter::DrawText
// //    *******************************************************************************/
// //    void qPainter::DrawText(const aString   &_sText,
// //                            const s32       _s32X,
// //                            const s32       _s32Y,
// //                            const aFont     *_pFont /*= nullptr*/,
// //                            const Rgba      *_pRgba /*= nullptr*/)
// //    {
// //        if (_pFont != nullptr)
// //        {
// //            SetFont(*_pFont);
// //        }

// //        if (_pRgba != nullptr)
// //        {
// //            SetPen(aPen(*_pRgba, 1));
// //        }

// //        drawText(_s32X, _s32Y, _sText);
// //    } // qPainter::DrawText


// //    /*******************************************************************************
// //    * qPainter::DrawText
// //    *******************************************************************************/
// //    void qPainter::DrawText(const aString      &_sText,
// //                            const s32          _s32BoundingX,
// //                            const s32          _s32BoundingY,
// //                            const s32          _s32BoundingW,
// //                            const s32          _s32BoundingH,
// //                            enumAlignmentHori  _eAlignmentH,
// //                            enumAlignmentVert  _eAlignmentV,
// //                            const aFont        *_pFont /*= nullptr*/,
// //                            const Rgba         *_pRgba /*= nullptr*/,
// //                            Rect2D<s32>        *pBoundingRect /*= nullptr*/)
// //     {
// //        if (_pFont != nullptr)
// //        {
// //            SetFont(*_pFont);
// //        }

// //        if (_pRgba != nullptr)
// //        {
// //            SetPen(aPen(*_pRgba, 1));
// //        }

// //        int             iFlags  = 0;
// //        QRect           rect(_s32BoundingX, _s32BoundingY, _s32BoundingW, _s32BoundingH);

// //        switch (_eAlignmentH)
// //        {
// //            case enumAlignmentHori::AlignLeft:
// //                iFlags += Qt::AlignLeft;
// //                break;

// //            case enumAlignmentHori::AlignHCenter:
// //                iFlags += Qt::AlignHCenter;
// //                break;

// //            case enumAlignmentHori::AlignRight:
// //                iFlags += Qt::AlignRight;
// //                break;
// //        } // switch (_eAlignmentH)

// //        switch (_eAlignmentV)
// //        {
// //            case enumAlignmentVert::AlignTop:
// //                iFlags += Qt::AlignTop;
// //                break;

// //            case enumAlignmentVert::AlignVCenter:
// //                iFlags += Qt::AlignVCenter;
// //                break;

// //            case enumAlignmentVert::AlignBottom:
// //                iFlags += Qt::AlignBottom;
// //        } // switch (_eAlignmentH)

// //        if (pBoundingRect != nullptr)
// //        {
// //            QRect   rct;
// //            drawText(rect, iFlags, _sText, &rct);

// //            pBoundingRect->Set(rct.x, rct.y, rct.width(), rct.height());
// //        }
// //        else
// //        {
// //            drawText(rect, iFlags, _sText);
// //        }
// //     } // qPainter::DrawText


// //    /*******************************************************************************
// //    * qPainter::DrawText
// //    *******************************************************************************/
// //    void qPainter::DrawText(const aString      &_sText,
// //                            Rect2D<s32>        _r2dBoundingBox,
// //                            enumAlignmentHori  _eAlignmentH,
// //                            enumAlignmentVert  _eAlignmentV,
// //                            const aFont        *_pFont /*= nullptr*/,
// //                            const Rgba         *_pRgba /*= nullptr*/,
// //                            Rect2D<s32>        *pBoundingRect  /*= nullptr*/)
// //    {
// //        DrawText(_sText,
// //                 _r2dBoundingBox.x, _r2dBoundingBox.y, _r2dBoundingBox.w, _r2dBoundingBox.h,
// //                 _eAlignmentH, _eAlignmentV, _pFont, _pRgba, pBoundingRect);
// //    } // qPainter::DrawText


// ////    /*******************************************************************************
// ////    * qPainter::DrawArc
// ////    *******************************************************************************/
// ////    void qPainter::DrawArc(qlRect2D<s32>   _r2dBoundingBox,
// ////                            const dbl       _dStartAngle,
// ////                            const dbl       _dDegree,
// ////                            const qlRgba    &_colBorder,
// ////                            const qlRgba    &_colFill)
// ////    {
// ////        QRectF  r(_r2dBoundingBox.x, _r2dBoundingBox.y,
// ////                  _r2dBoundingBox.w, _r2dBoundingBox.h);

// ////        SetPen(Pen(_colBorder, 1));
// ////        SetBrush(Brush(_colFill));

// ////        drawPie(r,
// ////                _dStartAngle * 16,
// ////                _dDegree * 16);
// ////    } // qPainter::DrawArc


// ////    /*******************************************************************************
// ////    * qPainter::DrawText
// ////    *******************************************************************************/
// ////    void qPainter::DrawText(const qlString     &_sText,
// ////                             const s32          _s32X,
// ////                             const s32          _s32Y,
// ////                             const qlRgba       &_col)
// ////    {
// ////        SetPen(Pen(_col, 1));

// ////        drawText(_s32X, _s32Y, _sText.To_QString());
// ////    } // qPainter::DrawText




//     /*******************************************************************************
//     * qPainter::DrawIcon
//     *******************************************************************************/
//     // void qPainter::DrawIcon(const qIcon&    _icn,
//     //                         s32             _s32X,
//     //                         s32             _s32Y)
//     // {
//     //     if (_icn.IsValid())
//     //     {
//     //         drawPixmap(_s32X, _s32Y, _icn);
//     //     }
//     // } // qPainter::DrawIcon


//     /*******************************************************************************
//     * qPainter::DrawIconCentered
//     *******************************************************************************/
//     // void qPainter::DrawIconCentered(const qIcon&        _icn,
//     //                                 const qRect2D<s32>& _r2d)
//     // {
//     //     if (_icn.IsValid())
//     //     {
//     //         drawPixmap(_r2d.x + (_r2d.w - _icn.w) / 2,
//     //                    _r2d.y + (_r2d.h - _icn.h) / 2,
//     //                    _icn);
//     //     }
//     // } // qPainter::DrawIconCentered
