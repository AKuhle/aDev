/*******************************************************************************
* \file qWin.cpp
* \author Andreas Kuhlewind
*
* \brief
*
*  Detailed description starts here.
*******************************************************************************/


/*******************************************************************************
* includes
*******************************************************************************/
#include "Win/FrameWin/qWin.h"

#include "Graphic/qPainter.h"
#include "Graphic/qPen.h"
#include "Graphic/qBorderObj.h"
#include "Graphic/qFillObj.h"

using namespace qLib::Graphic;


/*******************************************************************************
* namespace
*******************************************************************************/
namespace qLib {
namespace Win {


/*******************************************************************************
* qWin::onSysCreateWin
*******************************************************************************/
bool qWin::onSysCreateWin()
{
    return true;
} // qWin::onSysCreateWin


/*******************************************************************************
* qWin::onCreateWin
*******************************************************************************/
bool qWin::onCreateWin()
{
    return true;
} // qWin::onCreateWin


/*******************************************************************************
* qWin::onSysResize
*******************************************************************************/
void qWin::onSysResize(const qDimension2D<s32> &/*_d2dOld*/,
                       const qDimension2D<s32> &/*_d2dNew*/)
{
    if (m_pLayout != nullptr)
    {
        m_pLayout->arrangeChilds(layoutRect());
    }
} // qWin::onSysResize


/*******************************************************************************
* qWin::onResize
*******************************************************************************/
void qWin::onResize(const qDimension2D<s32> &/*_d2dOld*/,
                    const qDimension2D<s32> &/*_d2dNew*/)
{
} // qWin::onResize


/*******************************************************************************
* qWin::onPaintMargin
*******************************************************************************/
void qWin::onPaintMargin()
{
    // maximized wins don't have a margin
    // => dont draw margin stuff
    if (!isMaximized())
    {
    }
} // qWin::onPaintMargin


/*******************************************************************************
* qWin::onPaintBorder
*******************************************************************************/
void qWin::onPaintBorder()
{
    // maximized wins don't show a border
    // => dont draw border stuff
    if (!isMaximized())
    {
        CHECK_PRE_CONDITION_VOID(m_pWinStyleFactory != nullptr);
        CHECK_PRE_CONDITION_VOID(borderObj() != nullptr);

        qPainter p(this);
        qRect2D<s32> r2dBorder = borderRect();

        // draw the content fill
        borderObj()->draw(p, r2dBorder, border());
    }
} // qWin::onPaintBorder


/*******************************************************************************
* qWin::onPaintPaddingBg
*******************************************************************************/
void qWin::onPaintPaddingBg()
{
} // qWin::onPaintPaddingBg


/*******************************************************************************
* qWin::onPaintPadding
*******************************************************************************/
void qWin::onPaintPadding()
{
} // qWin::onPaintPadding


/*******************************************************************************
* qWin::onPaintContentBg
*******************************************************************************/
void qWin::onPaintContentBg()
{
    CHECK_PRE_CONDITION_VOID(contentObj() != nullptr);

    qRect2D<s32>    r2dContent = contentRect();
    qPainter        p(this);

    // draw the content fill
    contentObj()->draw(p, r2dContent);
} // qWin::onPaintContentBg


/*******************************************************************************
* qWin::onPaintContent
*******************************************************************************/
void qWin::onPaintContent()
{
} // qWin::onPaintContent


/*******************************************************************************
* qWin::onEnter
*******************************************************************************/
bool qWin::onEnter(u32                      /*_u32Modifiers*/,
                   const qVector2D<s32>     &/*_v2dLocal*/,
                   const qVector2D<s32>     &/*_v2dGlobal*/)
{
    return false;
} // qWin::onEnter


/*******************************************************************************
* qWin::onLeave
*******************************************************************************/
bool qWin::onLeave(u32 /*_u32Modifiers*/)
{
    return false;
} // qWin::onLeave


/*******************************************************************************
* qWin::onWheel
*******************************************************************************/
bool qWin::onWheel(u32                  /*_u32Modifiers*/,
                   s32                  /*_s32Degree*/,
                   const qVector2D<s32> &/*_v2dLocal*/,
                   const qVector2D<s32> &/*_v2dGlobal*/)
{
    return false;
} // qWin::onWheel


/*******************************************************************************
* qWin::onDoubleClick
*******************************************************************************/
bool qWin::onDoubleClick(u32                    /*_u32Modifiers*/,
                         u32                    /*_u32MouseButton*/,
                         const qVector2D<s32>   &/*_v2dLocal*/,
                         const qVector2D<s32>   &/*_v2dGlobal*/)
{
    return false;
} // qWin::onDoubleClick


/*******************************************************************************
* qWin::onMousePress
*******************************************************************************/
bool qWin::onMousePress(u32                     /*_u32Modifiers*/,
                        u32                     /*_u32MouseButton*/,
                        const qVector2D<s32>    &/*_v2dLocal*/,
                        const qVector2D<s32>    &/*_v2dGlobal*/)
{
    return false;
} // qWin::onMousePress


/*******************************************************************************
* qWin::onMouseMove
*******************************************************************************/
bool qWin::onMouseMove(u32                  /*_u32Modifiers*/,
                       u32                  /*_u32MouseButton*/,
                       const qVector2D<s32> &/*_v2dLocal*/,
                       const qVector2D<s32> &/*_v2dGlobal*/)
{
    return false;
} // qWin::onMouseMove


/*******************************************************************************
* qWin::onMouseRelease
*******************************************************************************/
bool qWin::onMouseRelease(u32                   /*_u32Modifiers*/,
                          u32                   /*_u32MouseButton*/,
                          const qVector2D<s32>  &/*_v2dLocal*/,
                          const qVector2D<s32>  &/*_v2dGlobal*/)
{
    return false;
} // qWin::onMouseRelease


/*******************************************************************************
* qWin::onResizeEvent
*******************************************************************************/
void qWin::onResizeEvent(const qDimension2D<s32> &_d2dOld,
                         const qDimension2D<s32> &_d2dNew)
{
    onSysResize(_d2dOld, _d2dNew);
    onResize(_d2dOld, _d2dNew);
} // qWin::onResizeEvent


/*******************************************************************************
* qWin::onPaintEvent
*******************************************************************************/
void qWin::onPaintEvent()
{
    onPaintMargin();

    onPaintBorder();

    onPaintPaddingBg();
    onPaintPadding();

    onPaintContentBg();
    onPaintContent();

} // qWin::onPaintEvent


/*******************************************************************************
* qWin::onEnterEvent
*******************************************************************************/
bool qWin::onEnterEvent(u32                     _u32Modifiers,
                        const qVector2D<s32>    &_v2dLocal,
                        const qVector2D<s32>    &_v2dGlobal)
{
    // first call the handler of the tool, than of the win
    return doEnter(_u32Modifiers, _v2dLocal, _v2dGlobal) ||
           onEnter(_u32Modifiers, _v2dLocal, _v2dGlobal);
} // qWin::onEnterEvent


/*******************************************************************************
* qWin::onLeaveEvent
*******************************************************************************/
bool qWin::onLeaveEvent(u32 _u32Modifiers)
{
    // first call the handler of the tool, than of the win
    return doLeave(_u32Modifiers) ||
           onLeave(_u32Modifiers);
} // qWin::onLeaveEvent


/*******************************************************************************
* qWin::onWheelEvent
*******************************************************************************/
bool qWin::onWheelEvent(u32                     _u32Modifiers,
                        s32                     _s32Degree,
                        const qVector2D<s32>    &_v2dLocal,
                        const qVector2D<s32>    &_v2dGlobal)
{
    // first call the handler of the tool, than of the win
    return doWheel(_u32Modifiers, _s32Degree, _v2dLocal, _v2dGlobal) ||
           onWheel(_u32Modifiers, _s32Degree, _v2dLocal, _v2dGlobal);
} // qWin::onWheelEvent


/*******************************************************************************
* qWin::onDoubleClickEvent
*******************************************************************************/
bool qWin::onDoubleClickEvent(u32                   _u32Modifiers,
                              u32                   _u32MouseButton,
                              const qVector2D<s32>  &_v2dLocal,
                              const qVector2D<s32>  &_v2dGlobal)
{
    // first call the handler of the tool, than of the win
    return doDoubleClick(_u32Modifiers, _u32MouseButton, _v2dLocal, _v2dGlobal) ||
           onDoubleClick(_u32Modifiers, _u32MouseButton, _v2dLocal, _v2dGlobal);
} // qWin::onDoubleClickEvent


/*******************************************************************************
* qWin::onMousePressEvent
*******************************************************************************/
bool qWin::onMousePressEvent(u32                    _u32Modifiers,
                             u32                    _u32MouseButton,
                             const qVector2D<s32>   &_v2dLocal,
                             const qVector2D<s32>   &_v2dGlobal)
{
    // first call the handler of the tool, than of the win
    return doMousePress(_u32Modifiers, _u32MouseButton, _v2dLocal, _v2dGlobal) ||
           onMousePress(_u32Modifiers, _u32MouseButton, _v2dLocal, _v2dGlobal);
} // qWin::onMousePressEvent


/*******************************************************************************
* qWin::onMouseMoveEvent
*******************************************************************************/
bool qWin::onMouseMoveEvent(u32                     _u32Modifiers,
                             u32                    _u32MouseButton,
                             const qVector2D<s32>   &_v2dLocal,
                             const qVector2D<s32>   &_v2dGlobal)
{
    // first call the handler of the tool, than of the win
    return doMouseMove(_u32Modifiers, _u32MouseButton, _v2dLocal, _v2dGlobal) ||
           onMouseMove(_u32Modifiers, _u32MouseButton, _v2dLocal, _v2dGlobal);
} // qWin::onMouseMoveEvent


/*******************************************************************************
* qWin::onMouseReleaseEvent
*******************************************************************************/
bool qWin::onMouseReleaseEvent(u32                  _u32Modifiers,
                               u32                  _u32MouseButton,
                               const qVector2D<s32> &_v2dLocal,
                               const qVector2D<s32> &_v2dGlobal)
{
    // first call the handler of the tool, than of the win
    return doMouseRelease(_u32Modifiers, _u32MouseButton, _v2dLocal, _v2dGlobal) ||
           onMouseRelease(_u32Modifiers, _u32MouseButton, _v2dLocal, _v2dGlobal);
} // qWin::onMouseReleaseEvent



} // namespace Win
} // namespace qLib
