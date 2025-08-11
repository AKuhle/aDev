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
* aBaseWin_i::onLDoubleClick
*******************************************************************************/
bool aBaseWin_i::onLDoubleClick(u16          /*_u16Modifier*/,
                                const aPoint &/*_pntLocal*/,
                                const aPoint &/*_pntGlobal*/)
{
    return false;
} // aBaseWin_i::onLDoubleClick


/*******************************************************************************
* aBaseWin_i::onMDoubleClick
*******************************************************************************/
bool aBaseWin_i::onMDoubleClick(u16          /*_u16Modifier*/,
                                const aPoint &/*_pntLocal*/,
                                const aPoint &/*_pntGlobal*/)
{
    return false;
} // aBaseWin_i::onMDoubleClick


/*******************************************************************************
* aBaseWin_i::onRDoubleClick
*******************************************************************************/
bool aBaseWin_i::onRDoubleClick(u16          /*_u16Modifier*/,
                                const aPoint &/*_pntLocal*/,
                                const aPoint &/*_pntGlobal*/)
{
    return false;
} // aBaseWin_i::onRDoubleClick


/*******************************************************************************
* aBaseWin_i::onLButtonPress
*******************************************************************************/
bool aBaseWin_i::onLButtonPress(u16          /*_u16Modifier*/,
                                const aPoint &/*_pntLocal*/,
                                const aPoint &/*_pntGlobal*/)
{
    return false;
} // aBaseWin_i::onLButtonPress


/*******************************************************************************
* aBaseWin_i::onMButtonPress
*******************************************************************************/
bool aBaseWin_i::onMButtonPress(u16          /*_u16Modifier*/,
                                const aPoint &/*_pntLocal*/,
                                const aPoint &/*_pntGlobal*/)
{
    return false;
} // aBaseWin_i::onMButtonPress


/*******************************************************************************
* aBaseWin_i::onRButtonPress
*******************************************************************************/
bool aBaseWin_i::onRButtonPress(u16          /*_u16Modifier*/,
                                const aPoint &/*_pntLocal*/,
                                const aPoint &/*_pntGlobal*/)
{
    return false;
} // aBaseWin_i::onRButtonPress


/*******************************************************************************
* aBaseWin_i::onLMouseMove
*******************************************************************************/
bool aBaseWin_i::onLMouseMove(u16          /*_u16Modifier*/,
                              const aPoint &/*_pntLocal*/,
                              const aPoint &/*_pntGlobal*/)
{
    return false;
} // aBaseWin_i::onLMouseMove


/*******************************************************************************
* aBaseWin_i::onMMouseMove
*******************************************************************************/
bool aBaseWin_i::onMMouseMove(u16          /*_u16Modifier*/,
                                const aPoint &/*_pntLocal*/,
                                const aPoint &/*_pntGlobal*/)
{
    return false;
} // aBaseWin_i::onMMouseMove


/*******************************************************************************
* aBaseWin_i::onRMouseMove
*******************************************************************************/
bool aBaseWin_i::onRMouseMove(u16          /*_u16Modifier*/,
                                const aPoint &/*_pntLocal*/,
                                const aPoint &/*_pntGlobal*/)
{
    return false;
} // aBaseWin_i::onRMouseMove


/*******************************************************************************
* aBaseWin_i::onMouseMove
*******************************************************************************/
bool aBaseWin_i::onMouseMove(u16          /*_u16Modifier*/,
                             const aPoint &/*_pntLocal*/,
                             const aPoint &/*_pntGlobal*/)
{
    return false;
} // aBaseWin_i::onMouseMove


/*******************************************************************************
* aBaseWin_i::onMultipleMouseMove
*******************************************************************************/
bool aBaseWin_i::onMultipleMouseMove(u16            /*_u16Modifier*/,
                                     const aPoint   &/*_pntLocal*/,
                                     const aPoint   &/*_pntGlobal*/,
                                     bool           /*_bLBtn*/,
                                     bool           /*_bMBtn*/,
                                     bool           /*_bRBtn*/)
{
    return false;
} // aBaseWin_i::onMultipleMouseMove


/*******************************************************************************
* aBaseWin_i::onLButtonRelease
*******************************************************************************/
bool aBaseWin_i::onLButtonRelease(u16          /*_u16Modifier*/,
                                  const aPoint &/*_pntLocal*/,
                                  const aPoint &/*_pntGlobal*/)
{
    return false;
} // aBaseWin_i::onLButtonRelease


/*******************************************************************************
* aBaseWin_i::onMButtonRelease
*******************************************************************************/
bool aBaseWin_i::onMButtonRelease(u16          /*_u16Modifier*/,
                                  const aPoint &/*_pntLocal*/,
                                  const aPoint &/*_pntGlobal*/)
{
    return false;
} // aBaseWin_i::onMButtonRelease


/*******************************************************************************
* aBaseWin_i::onRButtonRelease
*******************************************************************************/
bool aBaseWin_i::onRButtonRelease(u16          /*_u16Modifier*/,
                                  const aPoint &/*_pntLocal*/,
                                  const aPoint &/*_pntGlobal*/)
{
    return false;
} // aBaseWin_i::onRButtonRelease


/*******************************************************************************
* aBaseWin_i::onSysResize
*******************************************************************************/
void aBaseWin_i::onSysResize(const aDimension   &_dOldDim,
                             const aDimension   &_dNewDim)
{
    if (m_pLayout)
    {
        m_pLayout->arrange(contentRect());
    }

    onResize(_dOldDim, _dNewDim);
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
} // aBaseWin_i::onPaintMargin


/*******************************************************************************
* aBaseWin_i::onPaintBorder
*******************************************************************************/
void aBaseWin_i::onPaintBorder()
{
    if (borderStyle() != nullptr)
    {
        aRect       r = borderRect();
        aPainter    p(m_pWinInstance);

        borderStyle()->draw(p, r);
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


} // namespace aWin
} // namespace aFrame
