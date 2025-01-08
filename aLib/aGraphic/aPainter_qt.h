/*******************************************************************************
* \file aPainterQt.h
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

#include "aLib_def.h"
#include "aUtil/aUtil_def.h"
#include "aMath/aMath_def.h"
#include "aGraphic/aGraphic_def.h"
#include "aWin/aWin_def.h"

using namespace aLib::aUtil;
using namespace aLib::aMath;
using namespace aLib::aWin;


namespace aLib {
namespace aGraphic {
namespace SysQt {


/*******************************************************************************
* class aPainterQt
*******************************************************************************/
class aPainterQt : private QPainter
{
    public:
        aPainterQt(aBaseWin *_pWin);
        virtual ~aPainterQt();

        /*******************************************************************************
        * draw line
        * uses/sets the current Pen!
        *******************************************************************************/
        public:
            void            drawLine(s32         _s32StartX,
                                     s32         _s32StartY,
                                     s32         _s32EndX,
                                     s32         _s32EndY,
                                     const aPen  *_pPen = nullptr);

            void            drawLine(const aVector2D<s32>   &_v2dStart,
                                     const aVector2D<s32>   &_v2dEnd,
                                     const aPen             *_pPen = nullptr);


        /*******************************************************************************
        * draw rect
        * uses/sets the current Pen!
        *******************************************************************************/
        public:
            void            drawFilledRect(s32          _x,
                                           s32          _y,
                                           s32          _w,
                                           s32          _h,
                                           const aColor *_pColor = nullptr);

            void            drawFilledRect(const aRect2D<s32>   &_r,
                                           const aColor         *_pColor = nullptr);


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
                                             const aColor   &_colStart,
                                             const aColor   &_colEnd);


            void            drawGradientRect(const aRect2D<s32>     &_r2d,
                                             const aVector2D<s32>   &_v2dGradStart,
                                             const aVector2D<s32>   &_v2dGradEnd,
                                             const aColor           &_colStart,
                                             const aColor           &_colEnd);


        private:
            void            setPen(const aPen *_pPen);
            void            setBrush(const aColor   *_pColor);

            QColor          to_QColor(const aColor &_color);

}; // aPainterQt


} // namespace SysQt
} // namespace aGraphic
} // namespace aLib

#endif // _USE_QT_
