/*******************************************************************************
* \file aPainter.cpp
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
#include "aPainter.h"
#include "aColor.h"
#include "aRect2D.h"

using namespace aLib::aUtil;



/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aGraphic {


/*******************************************************************************
* aPainter::aPainter
*******************************************************************************/
aPainter::aPainter(SysWin *_pWin)
: QPainter(_pWin)
{
} // aPainter::aPainter


/*******************************************************************************
* aPainter::~aPainter
*******************************************************************************/
aPainter::~aPainter()
{
} // aPainter:.~aPainter


/*******************************************************************************
* aPainter::drawFilledRect
*******************************************************************************/
void aPainter::drawFilledRect(s32           _x,
                              s32           _y,
                              s32           _w,
                              s32           _h,
                              const aColor  *_pColor /*= nullptr*/)
{
    QPainter::setPen(Qt::NoPen);
    setBrush(_pColor);

    QPainter::drawRect(_x, _y, _w, _h);

    // setPen(aPen(Qt::NoPen));
    // QRectF rectangle(0.0, 0.0, 3.0, 3.0);
    // fillRect(_x, _y, _w, _h, toaColor(colLightSeaGreen));
    // setRenderHint(QPainter::Antialiasing, false);
    // fillRect(rectangle, toaColor(colGreenYellow));
} // aPainter::drawFilledRect


/*******************************************************************************
* aPainter::drawFilledRect
*******************************************************************************/
void aPainter::drawFilledRect(const aRect2D<s32>  &_r2d,
                                const aColor        *_pColor /*= nullptr*/)
{
    drawFilledRect(_r2d.x(), _r2d.y(), _r2d.w(), _r2d.h(), _pColor);
} // aPainter::drawFilledRect


/*******************************************************************************
* aPainter::drawQImg
*******************************************************************************/
void aPainter::drawQImg(const QImage    &_img,
                        s32             _s32X,
                        s32             _s32Y)
{
    if (!_img.isNull())
    {
        // draw the image
        QPainter::drawImage(_s32X, _s32Y, _img);
    }
} // aPainter::drawQImg


/*******************************************************************************
* aPainter::setPen
*******************************************************************************/
// void aPainter::setPen(const aPen *_pPen)
// {
//     CHECK_PRE_CONDITION_VOID(_pPen != nullptr);

//     QPainter::setPen(*_pPen);
// } // aPainter::setPen


/*******************************************************************************
* aPainter::setPen
*******************************************************************************/
void aPainter::setPen(const aColor *_pColor)
{
    CHECK_PRE_CONDITION_VOID(_pColor != nullptr);

    QPainter::setPen(QPen(to_QColor(*_pColor)));
} // aPainter::setPen


/*******************************************************************************
* aPainter::setBrush
******************************************B*************************************/
void aPainter::setBrush(const aColor *_pColor)
{
    if (_pColor != nullptr)
    {
        QBrush  brush(to_QColor(*_pColor));

        QPainter::setBrush(brush);
    }
} // aPainter::setBrush


// /*******************************************************************************
// * aPainter::setFont
// *******************************************************************************/
// void aPainter::setFont(const aFont *_pFont)
// {
//     if (_pFont != nullptr)
//     {
//         QPainter::setFont(*_pFont);
//     }
// } // aPainter::setFont


/*******************************************************************************
* aPainter::toaColor
*******************************************************************************/
QColor aPainter::to_QColor(const aColor &_color)
{
    return QColor::fromRgbF(_color.r(),
                            _color.g(),
                            _color.b(),
                            _color.a());
} // aPainter::toaColor


} // namespace aGraphic
} // namespace aLib

#endif // _USE_QT_



// /*******************************************************************************
// * aPainter::drawLine
// *******************************************************************************/
// void aPainter::drawLine(s32          _startX,
//                           s32          _startY,
//                           s32          _endX,
//                           s32          _endY,
//                           const aPen   *_pPen /*= nullptr*/)
// {
//     setPen(_pPen);

//     QPainter::drawLine(_startX, _startY, _endX, _endY);
// } // aPainter::drawLine


// /*******************************************************************************
// * aPainter::drawLine
// *******************************************************************************/
// void aPainter::drawLine(const aVector2D<s32>    &_v2dStart,
//                           const aVector2D<s32>    &_v2dEnd,
//                           const aPen              *_pPen /*= nullptr*/)
// {
//     drawLine(_v2dStart.x(), _v2dStart.y(), _v2dEnd.x(), _v2dEnd.y(), _pPen);
// } // aPainter::drawLine


// /*******************************************************************************
// * aPainter::drawFilledRect
// *******************************************************************************/
// void aPainter::drawFilledRect(s32             _x,
//                                 s32             _y,
//                                 s32             _w,
//                                 s32             _h,
//                                 const aColor    *_pColor /*= nullptr*/)
// {
//     QPainter::setPen(Qt::NoPen);
//     setBrush(_pColor);

//     drawRect(_x, _y, _w, _h);

//     // setPen(aPen(Qt::NoPen));
//     // QRectF rectangle(0.0, 0.0, 3.0, 3.0);
//     // fillRect(_x, _y, _w, _h, toaColor(colLightSeaGreen));
//     // setRenderHint(QPainter::Antialiasing, false);
//     // fillRect(rectangle, toaColor(colGreenYellow));
// } // aPainter::drawFilledRect


// /*******************************************************************************
// * aPainter::drawFilledRect
// *******************************************************************************/
// void aPainter::drawFilledRect(const aRect2D<s32>  &_r2d,
//                                 const aColor        *_pColor /*= nullptr*/)
// {
//     drawFilledRect(_r2d.x(), _r2d.y(), _r2d.w(), _r2d.h(), _pColor);
// } // aPainter::drawFilledRect


// /*******************************************************************************
// * aPainter::drawGradientRect
// *******************************************************************************/
// void aPainter::drawGradientRect(s32           _x,
//                                   s32           _y,
//                                   s32           _w,
//                                   s32           _h,
//                                   s32           _s32GradStartX,
//                                   s32           _s32GradStartY,
//                                   s32           _s32GradEndX,
//                                   s32           _s32GradEndY,
//                                   const aColor  &_colStart,
//                                   const aColor  &_colEnd)
// {
//     QLinearGradient grad(QPointF(_s32GradStartX, _s32GradStartY), QPointF(_s32GradEndX, _s32GradEndY));
//     grad.setColorAt(0, to_QColor(_colStart));
//     grad.setColorAt(1, to_QColor(_colEnd));

//     QPainter::fillRect(_x, _y, _w, _h, grad);
// } // aPainter::drawGradientRect


// /*******************************************************************************
// * aPainter::drawGradientRect
// *******************************************************************************/
// void aPainter::drawGradientRect(const aRect2D<s32>    &_r2d,
//                                   const aVector2D<s32>  &_v2dGradStart,
//                                   const aVector2D<s32>  &_v2dGradEnd,
//                                   const aColor          &_colStart,
//                                   const aColor          &_colEnd)
// {
//     drawGradientRect(_r2d.x(), _r2d.y(), _r2d.w(), _r2d.h(),
//                      _v2dGradStart.x(), _v2dGradStart.y(),
//                      _v2dGradEnd.x(), _v2dGradEnd.y(),
//                      _colStart, _colEnd);
// } // aPainter::drawGradientRect


// /*******************************************************************************
// * aPainter::drawFilledCircle
// *******************************************************************************/
// void aPainter::drawFilledCircle(s32            _centerX,
//                                   s32            _centerY,
//                                   s32            _radius,
//                                   const aColor   *_pColor /*= nullptr*/)
// {
//     setPen(_pColor);
//     setBrush(_pColor);

//     QPainter::drawEllipse(_centerX-_radius, _centerY-_radius,
//                           _radius*2, _radius*2);
// } // aPainter::drawFilledCircle


// /*******************************************************************************
// * aPainter::drawFilledCircle
// *******************************************************************************/
// void aPainter::drawFilledCircle(const aVector2D<s32>   &_v2dCenter,
//                                   s32                    _radius,
//                                   const aColor           *_pColor /*= nullptr*/)
// {
//     drawFilledCircle(_v2dCenter.x(), _v2dCenter.y(), _radius, _pColor);
// } // aPainter::drawFilledCircle


// /*******************************************************************************
// * aPainter::drawFilledCircle
// *******************************************************************************/
// void aPainter::drawFilledCircle(const aRect2D<s32>   &_r2dBounding,
//                                   const aColor         *_pColor /*= nullptr*/)
// {
//     drawFilledCircle(_r2dBounding.centerPoint().x(), _r2dBounding.centerPoint().y(),
//                      aUtil::min<s32>(_r2dBounding.w() / 2, _r2dBounding.h() / 2),
//                      _pColor);
// } // aPainter::drawFilledCircle


// /*******************************************************************************
// * aPainter::drawText
// *******************************************************************************/
// void aPainter::drawText(const aString  &_sText,
//                           const s32      _x,
//                           const s32      _y,
//                           const aFont    *_pFont     /*= nullptr*/,
//                           const aColor   *_pColor    /*= nullptr*/)
// {
//     setFont(_pFont);
//     setPen(_pColor);

//     QPainter::drawText(_x, _y, _sText.toQString());
// } // aPainter::drawText


// /*******************************************************************************
// * aPainter::drawText
// *******************************************************************************/
// void aPainter::drawText(const aString     &_sText,
//                           aRect2D<s32>       _r2dBoundingBox,
//                           enumAlignmentHori _eAlignmentH,
//                           enumAlignmentVert _eAlignmentV,
//                           const aFont       *_pFont         /*= nullptr*/,
//                           const aColor      *_pColor        /*= nullptr*/,
//                           aRect2D<s32>      *pBoundingRect  /*= nullptr*/)
// {
//     drawText(_sText,
//              _r2dBoundingBox.x(), _r2dBoundingBox.y(),
//              _r2dBoundingBox.w(), _r2dBoundingBox.h(),
//              _eAlignmentH, _eAlignmentV,
//              _pFont, _pColor,
//              pBoundingRect);
// } // aPainter::drawText



// /*******************************************************************************
// * aPainter::drawText
// *******************************************************************************/
// void aPainter::drawText(const aString     &_sText,
//                           const s32         _s32BoundingX,
//                           const s32         _s32BoundingY,
//                           const s32         _s32BoundingW,
//                           const s32         _s32BoundingH,
//                           enumAlignmentHori _eAlignmentH,
//                           enumAlignmentVert _eAlignmentV,
//                           const aFont       *_pFont         /*= nullptr*/,
//                           const aColor      *_pColor        /*= nullptr*/,
//                           aRect2D<s32>      *pBoundingRect  /*= nullptr*/)
// {
//     setFont(_pFont);
//     setPen(_pColor);

//     int             iFlags  = 0;
//     QRect           rect(_s32BoundingX, _s32BoundingY, _s32BoundingW, _s32BoundingH);

//     switch (_eAlignmentH)
//     {
//         case enumAlignmentHori::AlignLeft:
//             iFlags += Qt::AlignLeft;
//             break;

//         case enumAlignmentHori::AlignHCenter:
//             iFlags += Qt::AlignHCenter;
//             break;

//         case enumAlignmentHori::AlignRight:
//             iFlags += Qt::AlignRight;
//             break;
//     } // switch (_eAlignmentH)

//     switch (_eAlignmentV)
//     {
//         case enumAlignmentVert::AlignTop:
//             iFlags += Qt::AlignTop;
//             break;

//         case enumAlignmentVert::AlignVCenter:
//             iFlags += Qt::AlignVCenter;
//             break;

//         case enumAlignmentVert::AlignBottom:
//             iFlags += Qt::AlignBottom;
//             break;
//     } // switch (_eAlignmentH)

//     if (pBoundingRect != nullptr)
//     {
//         QRect   rct;
//         QPainter::drawText(rect, iFlags, _sText.toQString(), &rct);

//         pBoundingRect->set(rct.x(), rct.y(), rct.width(), rct.height());
//     }
//     else
//     {
//         QPainter::drawText(rect, iFlags, _sText.toQString());
//     }
// } // aPainter::drawText


// /*******************************************************************************
// * qPainter::drawTextCentered
// *******************************************************************************/
// void aPainter::drawTextCentered(const aString &_sText,
//                                   aRect2D<s32>  _r2dBoundingBox,
//                                   const aFont   *_pFont         /*= nullptr*/,
//                                   const aColor  *_pColor        /*= nullptr*/,
//                                   aRect2D<s32>  *pBoundingRect  /*= nullptr*/)
// {
//     QRect rect(_r2dBoundingBox.x(), _r2dBoundingBox.y(), _r2dBoundingBox.w(), _r2dBoundingBox.h());

//     setFont(_pFont);

//     setPen(_pColor);

//     // get the required size of the text with the selected font
//     //aDimension2D<s32>    dimText = aPainter::textSize(_sText);

//     if (pBoundingRect != nullptr)
//     {
//         QRect   rct;
//         QPainter::drawText(rect, Qt::AlignHCenter | Qt::AlignVCenter, _sText.toQString(), &rct);

//         pBoundingRect->set(rct.x(), rct.y(), rct.width(), rct.height());
//     }
//     else
//     {
//         QPainter:: drawText(rect, Qt::AlignHCenter | Qt::AlignVCenter, _sText.toQString());
//     }
// } // aPainter::drawTextCentered


// /*******************************************************************************
// * aPainter::drawPixmap
// *******************************************************************************/
// void aPainter::drawPixmap(const aPixmap   &_pixmap,
//                             s32             _x,
//                             s32             _y)
// {
//     QPainter::drawPixmap(_x, _y, _pixmap);
// } // aPainter::drawPixmap
