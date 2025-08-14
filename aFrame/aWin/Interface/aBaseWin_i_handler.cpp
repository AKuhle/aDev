/*******************************************************************************
* \file aBaseWin_i.cpp
* \author Andreas Kuhlewind
*
* \brief
*
*  Detailed description starts here.
*******************************************************************************/


/*******************************************************************************
* includes
*******************************************************************************/
#include "aMath_def.h"

#include "aRect2D.h"

#include "aPainter.h"
#include "aStyleItemBorder.h"

#include "aBaseWin_i.h"
#include "aLayout_i.h"

using namespace aFrame::aUtil;
using namespace aFrame::aMath;
using namespace aFrame::aGraphic;


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aFrame {
namespace aWin {


/*******************************************************************************
* namespace
*******************************************************************************/


/*******************************************************************************
* aBaseWin_i::onSysCreateWin
*******************************************************************************/
bool aBaseWin_i::onSysCreateWin()
{
    return true;
} // aBaseWin_i::onSysCreateWin


/*******************************************************************************
* aBaseWin_i::onCreateWin
*******************************************************************************/
bool aBaseWin_i::onCreateWin()
{
    return true;
} // aBaseWin_i::onCreateWin


/*******************************************************************************
* aBaseWin_i::onSysResize
*******************************************************************************/
void aBaseWin_i::onSysResize(const aDimension   &/*_dOldDim*/,
                             const aDimension   &/*_dNewDim*/)
{
    if (m_pLayout)
    {
        m_pLayout->arrange(contentRect());
    }
} // aBaseWin_i::onSysResize


/*******************************************************************************
* aBaseWin_i::onResize
*******************************************************************************/
void aBaseWin_i::onResize(const aDimension   &/*_dOldDim*/,
                          const aDimension   &/*_dNewDim*/)
{
} // aBaseWin_i::onResize


/*******************************************************************************
* aBaseWin_i::onPaint
*******************************************************************************/
void aBaseWin_i::onPaint()
{
    onPaintMargin();
    onPaintBorder();
    onPaintPadding();
    onPaintContentBg();
    onPaintContent();
} // aBaseWin_i::onPaint


/*******************************************************************************
* aBaseWin_i::onPaintMargin
*******************************************************************************/
void aBaseWin_i::onPaintMargin()
{
    aPainter    p(m_pWinInstance);

    p.drawFilledRect(marginRect(), &colTransparent);
} // aBaseWin_i::onPaintMargin


/*******************************************************************************
* aBaseWin_i::onPaintBorder
*******************************************************************************/
void aBaseWin_i::onPaintBorder()
{
    // full screen => no border
    if (!isFullScreen())
    {
        if (borderStyle() != nullptr)
        {
            aRect       r = borderRect();
            aPainter    p(m_pWinInstance);

            borderStyle()->draw(p, r);
        }
    }
} // aBaseWin_i::onPaintBorder


/*******************************************************************************
* aBaseWin_i::onPaintPadding
*******************************************************************************/
void aBaseWin_i::onPaintPadding()
{
} // aBaseWin_i::onPaintPadding


/*******************************************************************************
* aBaseWin_i::onPaintContentBg
*******************************************************************************/
void aBaseWin_i::onPaintContentBg()
{
    if (bgStyle() != nullptr)
    {
        aRect       r = contentRect();
        aPainter    p(m_pWinInstance);

        bgStyle()->draw(p, r);
    }

} // aBaseWin_i::onPaintContentBg


/*******************************************************************************
* aBaseWin_i::onPaintContent
*******************************************************************************/
void aBaseWin_i::onPaintContent()
{
} // aBaseWin_i::onPaintContent


/*******************************************************************************
* aBaseWin_i::onWheel
*******************************************************************************/
bool aBaseWin_i::onWheel(u16            /*_u16Modifier*/,
                         s16            /*_s16Degree*/,
                         const aPoint   &/*_pntLocal*/,
                         const aPoint   &/*_pntGlobal*/)
{
    return false;
} // aBaseWin_i::onWheel


/*******************************************************************************
* aBaseWin_i::onDoubleClick
*******************************************************************************/
bool aBaseWin_i::onDoubleClick(u16          /*_u16Modifier*/,
                               u16          /*_u16Btn*/,
                               const aPoint &/*_pntLocal*/,
                               const aPoint &/*_pntGlobal*/)
{
    return false;
} // aBaseWin_i::onDoubleClick


/*******************************************************************************
* aBaseWin_i::onButtonPress
*******************************************************************************/
bool aBaseWin_i::onButtonPress(u16          /*_u16Modifier*/,
                               u16          /*_u16Btn*/,
                               const aPoint &/*_pntLocal*/,
                               const aPoint &/*_pntGlobal*/)
{
    return false;
} // aBaseWin_i::onButtonPress


/*******************************************************************************
* aBaseWin_i::onMouseMove
*******************************************************************************/
bool aBaseWin_i::onMouseMove(u16            /*_u16Modifier*/,
                             u16            /*_u16Btn*/,
                             const aPoint   &/*_pntLocal*/,
                             const aPoint   &/*_pntGlobal*/)
{
    return false;
} // aBaseWin_i::onMouseMove


/*******************************************************************************
* aBaseWin_i::onButtonRelease
*******************************************************************************/
bool aBaseWin_i::onButtonRelease(u16            /*_u16Modifier*/,
                                 u16            /*_u16Btn*/,
                                 const aPoint   &/*_pntLocal*/,
                                 const aPoint   &/*_pntGlobal*/)
{
    return false;
} // aBaseWin_i::onButtonRelease


} // namespace aWin
} // namespace aFrame
