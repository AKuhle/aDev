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
#include "aPixmap.h"

using namespace aFrame::aUtil;



/*******************************************************************************
* namespace
*******************************************************************************/
namespace aFrame {
namespace aGraphic {


/*******************************************************************************
* aPainterI::aPainterI
*******************************************************************************/
aPainterI::aPainterI()
{
} // aPainterI::aPainterI


/*******************************************************************************
* aPainterI::~aPainterI
*******************************************************************************/
aPainterI::~aPainterI()
{
} // aPainterI:.~aPainterI


/*******************************************************************************
* aPainter::drawRect
*******************************************************************************/
void aPainterI::drawRect(s32        _x,
                         s32        _y,
                         s32        _w,
                         s32        _h,
                         const aPen *_pPen /*= nullptr*/)
{
    _drawRect(_x, _y, _w, _h, _pPen);
} // aPainterI::drawRect


/*******************************************************************************
* aPainter::drawRect
*******************************************************************************/
void aPainterI::drawRect(const aRect  &_r,
                         const aPen *_pPen /*= nullptr*/)
{
    _drawRect(_r.x(), _r.y(), _r.w(), _r.h(), _pPen);
} // aPainterI::drawRect


/*******************************************************************************
* aPainter::drawFilledRect
*******************************************************************************/
void aPainterI::drawFilledRect(s32           _x,
                               s32           _y,
                               s32           _w,
                               s32           _h,
                               const aColor  *_pColor /*= nullptr*/)
{
    _drawFilledRect(_x, _y, _w, _h, _pColor);
} // aPainterI::drawFilledRect


/*******************************************************************************
* aPainterI::drawFilledRect
*******************************************************************************/
void aPainterI::drawFilledRect(const aRect  &_r,
                               const aColor *_pColor /*= nullptr*/)
{
    _drawFilledRect(_r.x(), _r.y(), _r.w(), _r.h(), _pColor);
} // aPainterI::drawFilledRect


/*******************************************************************************
* aPainterI::drawGradientRect
*******************************************************************************/
void aPainterI::drawGradientRect(s32           _x,
                                 s32           _y,
                                 s32           _w,
                                 s32           _h,
                                 s32           _s32GradStartX,
                                 s32           _s32GradStartY,
                                 s32           _s32GradEndX,
                                 s32           _s32GradEndY,
                                 const aColor  &_colStart,
                                 const aColor  &_colEnd)
{
    _drawGradientRect(_x, _y, _w, _h,
                      _s32GradStartX, _s32GradStartY,
                      _s32GradEndX, _s32GradEndY,
                      _colStart, _colEnd);
} // aPainterI::drawGradientRect


/*******************************************************************************
* aPainterI::drawGradientRect
*******************************************************************************/
void aPainterI::drawGradientRect(s32            _x,
                                 s32            _y,
                                 s32            _w,
                                 s32            _h,
                                 const aPoint   &_pntGradStart,
                                 const aPoint   &_pntGradEnd,
                                 const aColor   &_colStart,
                                 const aColor   &_colEnd)
{
    _drawGradientRect(_x, _y, _w, _h,
                      _pntGradStart.x(), _pntGradStart.y(),
                      _pntGradEnd.x(), _pntGradEnd.y(),
                      _colStart, _colEnd);
} // aPainterI::drawGradientRect


/*******************************************************************************
* aPainterI::drawGradientRect
*******************************************************************************/
void aPainterI::drawGradientRect(const aRect    &_r,
                                 const aPoint   &_pntGradStart,
                                 const aPoint   &_pntGradEnd,
                                 const aColor   &_colStart,
                                 const aColor   &_colEnd)
{
    _drawGradientRect(_r.x(), _r.y(), _r.w(), _r.h(),
                      _pntGradStart.x(), _pntGradStart.y(),
                      _pntGradEnd.x(), _pntGradEnd.y(),
                      _colStart, _colEnd);
} // aPainterI::drawGradientRect



} // namespace aGraphic
} // namespace aFrame

#endif // _USE_QT_
