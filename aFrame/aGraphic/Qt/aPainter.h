/*******************************************************************************
* \file aPainter.h
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

#include "aWin_def.h"
#include "aPainterI.h"

using namespace aFrame::aUtil;


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aFrame {
namespace aGraphic {


/*******************************************************************************
* class aPainter
*******************************************************************************/
class aPainter : private QPainter,
                 public aPainterI
{
    public:
        aPainter(SysWin *_pWin);
        virtual ~aPainter();


    /*******************************************************************************
    * drawFilledRect
    * uses/sets the current Pen!
    *******************************************************************************/
    public:
        void            _drawFilledRect(s32          _x,
                                        s32          _y,
                                        s32          _w,
                                        s32          _h,
                                        const aColor *_pColor = nullptr) override;


    /*******************************************************************************
    * drawGradientRect
    * uses/sets the current Brush!
    *******************************************************************************/
    public:
        void            _drawGradientRect(s32           _x,
                                          s32           _y,
                                          s32           _w,
                                          s32           _h,
                                          s32           _s32GradStartX,
                                          s32           _s32GradStartY,
                                          s32           _s32GradEndX,
                                          s32           _s32GradEndY,
                                          const aColor  &_colStart,
                                          const aColor  &_colEnd) override;


    // /*******************************************************************************
    // * drawPixmap
    // *******************************************************************************/
    public:
        void            drawPixmap(const aPixmap  &_pixmap,
                                   s32            _s32X,
                                   s32            _s32Y) override;


    // /*******************************************************************************
    // * drawImage
    // *******************************************************************************/
    public:
        void            drawQImg(const QImage   &_img,
                                 s32            _s32X,
                                 s32            _s32Y) override;


    /*******************************************************************************
    * private members
    *******************************************************************************/
    private:
        //void            setPen(const aPen *_pPen);
        void            setPen(const aColor *_pColor);

        void            setBrush(const aColor *_pColor);

        //void            setFont(const aFont *_pFont);

}; // aPainter


} // namespace aGraphic
} // namespace aFrame

#endif // _USE_QT_
