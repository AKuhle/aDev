/*******************************************************************************
* \file aBaseWin.cpp
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
#include "aStyleItemBorder.h"

#include "aBaseWin.h"
#include "aLayout_i.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aFrame {
namespace aWin {


/*******************************************************************************
* aBaseWin::onSysCreateWin
*******************************************************************************/
bool aBaseWin::onSysCreateWin()
{
    return true;
} // aBaseWin::onSysCreateWin


/*******************************************************************************
* aBaseWin::onCreateWin
*******************************************************************************/
bool aBaseWin::onCreateWin()
{
    return true;
} // aBaseWin::onCreateWin


/*******************************************************************************
* aBaseWin::onCreateChilds
*******************************************************************************/
bool aBaseWin::onCreateChilds()
{
    return true;
} // aBaseWin::onCreateChilds


/*******************************************************************************
* aBaseWin::onCloseWin
*******************************************************************************/
bool aBaseWin::onCloseWin()
{
    return true;
} // aBaseWin::onCloseWin


/*******************************************************************************
* aBaseWin::onSysResize
*******************************************************************************/
void aBaseWin::onSysResize(const aDimension   &/*_dOldDim*/,
                           const aDimension   &/*_dNewDim*/)
{
    if (m_pLayout)
    {
        aRect r1 = contentRect();
        aRect r2 = contentRect();
        m_pLayout->arrange(contentRect());
    }
} // aBaseWin::onSysResize


/*******************************************************************************
* aBaseWin::onResize
*******************************************************************************/
void aBaseWin::onResize(const aDimension   &/*_dOldDim*/,
                        const aDimension   &/*_dNewDim*/)
{
} // aBaseWin::onResize


/*******************************************************************************
* aBaseWin::onPaintMargin
*******************************************************************************/
void aBaseWin::onPaintMargin()
{
    aPainter    p(this);

    p.drawFilledRect(marginRect(), &colTransparent);
} // aBaseWin::onPaintMargin


/*******************************************************************************
* aBaseWin::onPaintBorder
*******************************************************************************/
void aBaseWin::onPaintBorder()
{
    // full screen => no border
    if (!isFullScreen())
    {
        if (borderStyle() != nullptr)
        {
            aRect       r = borderRect();
            aPainter    p(this);

            borderStyle()->draw(p, r);
        }
    }
} // aBaseWin::onPaintBorder


/*******************************************************************************
* aBaseWin::onPaintPadding
*******************************************************************************/
void aBaseWin::onPaintPadding()
{
} // aBaseWin::onPaintPadding


/*******************************************************************************
* aBaseWin::onPaintContentBg
*******************************************************************************/
void aBaseWin::onPaintContentBg()
{
    if (bgStyle() != nullptr)
    {
        aRect       r = contentRect();
        aPainter    p(this);

        bgStyle()->draw(p, r);
    }

} // aBaseWin::onPaintContentBg


/*******************************************************************************
* aBaseWin::onPaintContent
*******************************************************************************/
void aBaseWin::onPaintContent()
{
} // aBaseWin::onPaintContent


/*******************************************************************************
* aBaseWin::onEnter
*******************************************************************************/
bool aBaseWin::onEnter(u16             /*_u16Modifier*/,
                       const aPoint    &/*_pntLocal*/,
                       const aPoint    &/*_pntGlobal*/)
{
    return false;
} // aBaseWin::onEnter


/*******************************************************************************
* aBaseWin::onLeave
*******************************************************************************/
bool aBaseWin::onLeave(u16 /*_u16Modifier*/)
{
    return false;
} // aBaseWin::onLeave


/*******************************************************************************
* aBaseWin::onWheel
*******************************************************************************/
bool aBaseWin::onWheel(u16            /*_u16Modifier*/,
                       s16            /*_s16Degree*/,
                       const aPoint   &/*_pntLocal*/,
                       const aPoint   &/*_pntGlobal*/)
{
    return false;
} // aBaseWin::onWheel


/*******************************************************************************
* aBaseWin::onDoubleClick
*******************************************************************************/
bool aBaseWin::onDoubleClick(u16          /*_u16Modifier*/,
                             u16          /*_u16Btn*/,
                             const aPoint &/*_pntLocal*/,
                             const aPoint &/*_pntGlobal*/)
{
    return false;
} // aBaseWin::onDoubleClick


/*******************************************************************************
* aBaseWin::onButtonPress
*******************************************************************************/
bool aBaseWin::onButtonPress(u16          /*_u16Modifier*/,
                             u16          /*_u16Btn*/,
                             const aPoint &/*_pntLocal*/,
                             const aPoint &/*_pntGlobal*/)
{
    return false;
} // aBaseWin::onButtonPress


/*******************************************************************************
* aBaseWin::onMouseMove
*******************************************************************************/
bool aBaseWin::onMouseMove(u16            /*_u16Modifier*/,
                           u16            /*_u16Btn*/,
                           const aPoint   &/*_pntLocal*/,
                           const aPoint   &/*_pntGlobal*/)
{
    return false;
} // aBaseWin::onMouseMove


/*******************************************************************************
* aBaseWin::onButtonRelease
*******************************************************************************/
bool aBaseWin::onButtonRelease(u16            /*_u16Modifier*/,
                               u16            /*_u16Btn*/,
                               const aPoint   &/*_pntLocal*/,
                               const aPoint   &/*_pntGlobal*/)
{
    return false;
} // aBaseWin::onButtonRelease


} // namespace aWin
} // namespace aFrame


#endif //_USE_QT_
