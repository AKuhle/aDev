/*******************************************************************************
* \file aPainterQt.cpp
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
#include "aGraphic/aPen.h"
#include "aGraphic/aPainter.h"

#include "aMath/Obj2D/aVector2D.h"

#include "aUtil/aColor.h"

#include "aWin/Framework/aBaseWin.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aGraphic {
namespace SysQt {


/*******************************************************************************
* aPainterQt::aPainterQt
*******************************************************************************/
aPainterQt::aPainterQt(aBaseWin *_pWin)
: QPainter(_pWin->getQWidget())
{
} // aPainterQt::aPainterQt


/*******************************************************************************
* aPainterQt::~aPainterQt
*******************************************************************************/
aPainterQt::~aPainterQt()
{
} // aPainterQt:.~aPainterQt


/*******************************************************************************
* aPainterQt::drawLine
*******************************************************************************/
void aPainterQt::drawLine(s32          _s32StartX,
                          s32          _s32StartY,
                          s32          _s32EndX,
                          s32          _s32EndY,
                          const aPen   *_pPen /*= nullptr*/)
{
    setPen(_pPen);

    QPainter::drawLine(_s32StartX, _s32StartY, _s32EndX, _s32EndY);
} // aPainterQt::drawLine


/*******************************************************************************
* aPainterQt::drawLine
*******************************************************************************/
void aPainterQt::drawLine(const aVector2D<s32>    &_v2dStart,
                          const aVector2D<s32>    &_v2dEnd,
                          const aPen              *_pPen /*= nullptr*/)
{
    drawLine(_v2dStart.x(), _v2dStart.y(), _v2dEnd.x(), _v2dEnd.y(), _pPen);
} // aPainterQt::drawLine


/*******************************************************************************
* aPainterQt::drawFilledRect
*******************************************************************************/
void aPainterQt::drawFilledRect(s32             _x,
                                s32             _y,
                                s32             _w,
                                s32             _h,
                                const aColor    *_pColor /*= nullptr*/)
{
    QPainter::setPen(Qt::NoPen);
    setBrush(_pColor);

    drawRect(_x, _y, _w, _h);

    // setPen(aPen(Qt::NoPen));
    // QRectF rectangle(0.0, 0.0, 3.0, 3.0);
    // fillRect(_x, _y, _w, _h, toaColor(colLightSeaGreen));
    // setRenderHint(QPainter::Antialiasing, false);
    // fillRect(rectangle, toaColor(colGreenYellow));
} // aPainterQt::drawFilledRect


/*******************************************************************************
* aPainterQt::drawFilledRect
*******************************************************************************/
void aPainterQt::drawFilledRect(const aRect2D<s32>  &_r,
                                const aColor        *_pColor /*= nullptr*/)
{
    drawFilledRect(_r.x(), _r.y(), _r.w(), _r.h(), _pColor);
} // aPainterQt::drawFilledRect


/*******************************************************************************
* aPainterQt::drawGradientRect
*******************************************************************************/
void aPainterQt::drawGradientRect(s32           _s32X,
                                  s32           _s32Y,
                                  s32           _s32W,
                                  s32           _s32H,
                                  s32           _s32GradStartX,
                                  s32           _s32GradStartY,
                                  s32           _s32GradEndX,
                                  s32           _s32GradEndY,
                                  const aColor  &_colStart,
                                  const aColor  &_colEnd)
{
    QLinearGradient grad(QPointF(_s32GradStartX, _s32GradStartY), QPointF(_s32GradEndX, _s32GradEndY));
    grad.setColorAt(0, to_QColor(_colStart));
    grad.setColorAt(1, to_QColor(_colEnd));

    fillRect(_s32X, _s32Y, _s32W, _s32H, grad);
} // aPainterQt::drawGradientRect


/*******************************************************************************
* aPainterQt::drawGradientRect
*******************************************************************************/
void aPainterQt::drawGradientRect(const aRect2D<s32>    &_r2d,
                                  const aVector2D<s32>  &_v2dGradStart,
                                  const aVector2D<s32>  &_v2dGradEnd,
                                  const aColor          &_colStart,
                                  const aColor          &_colEnd)
{
    drawGradientRect(_r2d.x(), _r2d.y(), _r2d.w(), _r2d.h(),
                     _v2dGradStart.x(), _v2dGradStart.y(),
                     _v2dGradEnd.x(), _v2dGradEnd.y(),
                     _colStart, _colEnd);
} // aPainterQt::drawGradientRect


/*******************************************************************************
* aPainterQt::setPen
*******************************************************************************/
void aPainterQt::setPen(const aPen *_pPen)
{
    CHECK_PRE_CONDITION_VOID(_pPen != nullptr);

    QPainter::setPen(*_pPen);
} // aPainterQt::setPen


/*******************************************************************************
* aPainterQt::setBrush
*******************************************************************************/
void aPainterQt::setBrush(const aColor   *_pColor)
{
    if (_pColor != nullptr)
    {
        QBrush  brush(to_QColor(*_pColor));

        QPainter::setBrush(brush);
    }
} // aPainterQt::setBrush


/*******************************************************************************
* aPainterQt::toaColor
*******************************************************************************/
QColor aPainterQt::to_QColor(const aColor &_color)
{
    return QColor::fromRgbF(_color.r(),
                            _color.g(),
                            _color.b(),
                            _color.a());
} // aPainterQt::toaColor


} // namespace SysQt
} // namespace aGraphic
} // namespace aLib

#endif // _USE_QT_
