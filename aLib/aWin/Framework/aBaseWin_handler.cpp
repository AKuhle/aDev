/*******************************************************************************
* \file aBaseWin.cpp
* \author Andreas Kuhlewind
*
* \brief
*
*  Detailed description starts here.
*******************************************************************************/


/*******************************************************************************
* includes
*******************************************************************************/
#include "aLib_def.h"

#include "aUtil/aColor.h"

#include "aGraphic/aCursor.h"
#include "aGraphic/aPainter.h"

#include "aWin/Framework/aBaseWin.h"

using namespace aLib::aUtil;
using namespace aLib::aGraphic;


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aWin {


/*******************************************************************************
* aBaseWin::onSysCreate
*******************************************************************************/
bool aBaseWin::onSysCreate()
{
    return true;
} // aBaseWin::onSysCreate


/*******************************************************************************
* aBaseWin::onCreate
*******************************************************************************/
bool aBaseWin::onCreate()
{
    return true;
} // aBaseWin::onCreate


/*******************************************************************************
* aBaseWin::onSysResize
*******************************************************************************/
void aBaseWin::onSysResize(const aDimension2D<s32> &/*_d2dOld*/,
                           const aDimension2D<s32> &/*_d2dNew*/)
{
    // arrange the childs inside the content rect of the basewin
    if (m_pLayout != nullptr)
    {
        m_pLayout->arrangeChilds(layoutRect());
    }
} // aBaseWin::onSysResize


/*******************************************************************************
* aBaseWin::onResize
*******************************************************************************/
void aBaseWin::onResize(const aDimension2D<s32> &/*_d2dOld*/,
                        const aDimension2D<s32> &/*_d2dNew*/)
{
} // aBaseWin::onResize


/*******************************************************************************
* aBaseWin::onPaintMargin
*******************************************************************************/
void aBaseWin::onPaintMargin()
{
    // maximized wins don't have a margin
    if (!isMaximized())
    {
        aPainter        p(this);

        p.drawFilledRect(winRect(), &colTransparent);
    }
} // aBaseWin::onPaintMargin


/*******************************************************************************
* aBaseWin::onPaintBorder
*******************************************************************************/
void aBaseWin::onPaintBorder()
{
    CHECK_PRE_CONDITION_VOID(borderObj() != nullptr);

    // maximized wins don't show a border
    if (!isMaximized())
    {
        aPainter        p(this);

        borderObj()->draw(p, borderRect(), border());
    }
} // aBaseWin::onPaintBorder


/*******************************************************************************
* aBaseWin::onPaintPaddingBg
*******************************************************************************/
void aBaseWin::onPaintPaddingBg()
{
} // aBaseWin::onPaintPaddingBg


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
    CHECK_PRE_CONDITION_VOID(contentObj() != nullptr);

    aPainter        p(this);

    contentObj()->draw(p, contentRect());
} // aBaseWin::onPaintContentBg


/*******************************************************************************
* aBaseWin::onEnter
*******************************************************************************/
bool aBaseWin::onEnter(u32                      /*_u32Modifiers*/,
                       const aVector2D<s32>     &/*_v2dLocal*/,
                       const aVector2D<s32>     &/*_v2dGlobal*/)
{
    return false;
} // aBaseWin::onEnter


/*******************************************************************************
* aBaseWin::onLeave
*******************************************************************************/
bool aBaseWin::onLeave(u32 /*_u32Modifiers*/)
{
    return false;
} // aBaseWin::onLeave


/*******************************************************************************
* aBaseWin::onWheel
*******************************************************************************/
bool aBaseWin::onWheel(u32                  /*_u32Modifiers*/,
                       s32                  /*_s32Degree*/,
                       const aVector2D<s32> &/*_v2dLocal*/,
                       const aVector2D<s32> &/*_v2dGlobal*/)
{
    return false;
} // aBaseWin::onWheel


/*******************************************************************************
* aBaseWin::onDoubleClick
*******************************************************************************/
bool aBaseWin::onDoubleClick(u32                    /*_u32Modifiers*/,
                             u32                    /*_u32MouseButton*/,
                             const aVector2D<s32>   &/*_v2dLocal*/,
                             const aVector2D<s32>   &/*_v2dGlobal*/)
{
    return false;
} // aBaseWin::onDoubleClick


/*******************************************************************************
* aBaseWin::onMousePress
*******************************************************************************/
bool aBaseWin::onMousePress(u32                    /*_u32Modifiers*/,
                            u32                    /*_u32MouseButton*/,
                            const aVector2D<s32>   &/*_v2dLocal*/,
                            const aVector2D<s32>   &/*_v2dGlobal*/)
{
    return false;
} // aBaseWin::onMousePress


/*******************************************************************************
* aBaseWin::onMouseMove
*******************************************************************************/
bool aBaseWin::onMouseMove(u32                    /*_u32Modifiers*/,
                           u32                    /*_u32MouseButton*/,
                           const aVector2D<s32>   &/*_v2dLocal*/,
                           const aVector2D<s32>   &/*_v2dGlobal*/)
{
    return false;
} // aBaseWin::onMouseMove


/*******************************************************************************
* aBaseWin::onMouseRelease
*******************************************************************************/
bool aBaseWin::onMouseRelease(u32                    /*_u32Modifiers*/,
                              u32                    /*_u32MouseButton*/,
                              const aVector2D<s32>   &/*_v2dLocal*/,
                              const aVector2D<s32>   &/*_v2dGlobal*/)
{
    return false;
} // aBaseWin::onMouseRelease


/*******************************************************************************
* aBaseWin::onPaintContent
*******************************************************************************/
void aBaseWin::onPaintContent()
{
} // aBaseWin::onPaintContent


/*******************************************************************************
* aBaseWin::onResizeEvent
*******************************************************************************/
void aBaseWin::onResizeEvent(const aDimension2D<s32> &_d2dOld,
                             const aDimension2D<s32> &_d2dNew)
{
    onSysResize(_d2dOld, _d2dNew);
    onResize(_d2dOld, _d2dNew);
} // aBaseWin::onResizeEvent


/*******************************************************************************
* aBaseWin::onPaintEvent
*******************************************************************************/
void aBaseWin::onPaintEvent()
{
    onPaintMargin();

    onPaintBorder();

    onPaintPaddingBg();
    onPaintPadding();

    onPaintContentBg();
    onPaintContent();

} // aBaseWin::onPaintEvent


/*******************************************************************************
* aBaseWin::onEnterEvent
*******************************************************************************/
bool aBaseWin::onEnterEvent(u32                     _u32Modifiers,
                            const aVector2D<s32>    &_v2dLocal,
                            const aVector2D<s32>    &_v2dGlobal)
{
    m_bHover = true;

    setCursor(aCursor(enumCursorShape::Arrow));

    // first call the handler of the tool, than of the win
    return doToolMgrEnter(_u32Modifiers, _v2dLocal, _v2dGlobal) ||
           onEnter(_u32Modifiers, _v2dLocal, _v2dGlobal);
} // aBaseWin::onEnterEvent


/*******************************************************************************
* aBaseWin::onLeaveEvent
*******************************************************************************/
bool aBaseWin::onLeaveEvent(u32 _u32Modifiers)
{
    m_bHover = false;

    // first call the handler of the tool, than of the win
    return doToolMgrLeave(_u32Modifiers) ||
           onLeave(_u32Modifiers);
} // aBaseWin::onLeaveEvent


/*******************************************************************************
* aBaseWin::onWheelEvent
*******************************************************************************/
bool aBaseWin::onWheelEvent(u32                     _u32Modifiers,
                        s32                     _s32Degree,
                        const aVector2D<s32>    &_v2dLocal,
                        const aVector2D<s32>    &_v2dGlobal)
{
    // first call the handler of the tool, than of the win
    return doToolMgrWheel(_u32Modifiers, _s32Degree, _v2dLocal, _v2dGlobal) ||
           onWheel(_u32Modifiers, _s32Degree, _v2dLocal, _v2dGlobal);
} // aBaseWin::onWheelEvent


/*******************************************************************************
* aBaseWin::onDoubleClickEvent
*******************************************************************************/
bool aBaseWin::onDoubleClickEvent(u32                   _u32Modifiers,
                                  u32                   _u32MouseButton,
                                  const aVector2D<s32>  &_v2dLocal,
                                  const aVector2D<s32>  &_v2dGlobal)
{
    // first call the handler of the tool, than of the win
    return doToolMgrDoubleClick(_u32Modifiers, _u32MouseButton, _v2dLocal, _v2dGlobal) ||
           onDoubleClick(_u32Modifiers, _u32MouseButton, _v2dLocal, _v2dGlobal);

} // aBaseWin::onDoubleClickEvent


/*******************************************************************************
* aBaseWin::onMousePressEvent
*******************************************************************************/
bool aBaseWin::onMousePressEvent(u32                   _u32Modifiers,
                                 u32                   _u32MouseButton,
                                 const aVector2D<s32>  &_v2dLocal,
                                 const aVector2D<s32>  &_v2dGlobal)
{
    // first call the handler of the tool, than of the win
    return doToolMgrMousePress(_u32Modifiers, _u32MouseButton, _v2dLocal, _v2dGlobal) ||
           onMousePress(_u32Modifiers, _u32MouseButton, _v2dLocal, _v2dGlobal);

} // aBaseWin::onMousePressEvent


/*******************************************************************************
* aBaseWin::onMouseMoveEvent
*******************************************************************************/
bool aBaseWin::onMouseMoveEvent(u32                   _u32Modifiers,
                                u32                   _u32MouseButton,
                                const aVector2D<s32>  &_v2dLocal,
                                const aVector2D<s32>  &_v2dGlobal)
{
    // first call the handler of the tool, than of the win
    return doToolMgrMouseMove(_u32Modifiers, _u32MouseButton, _v2dLocal, _v2dGlobal) ||
           onMouseMove(_u32Modifiers, _u32MouseButton, _v2dLocal, _v2dGlobal);

} // aBaseWin::onMouseMoveEvent


/*******************************************************************************
* aBaseWin::onMouseReleaseEvent
*******************************************************************************/
bool aBaseWin::onMouseReleaseEvent(u32                   _u32Modifiers,
                                   u32                   _u32MouseButton,
                                   const aVector2D<s32>  &_v2dLocal,
                                   const aVector2D<s32>  &_v2dGlobal)
{
    // first call the handler of the tool, than of the win
    return doToolMgrMouseRelease(_u32Modifiers, _u32MouseButton, _v2dLocal, _v2dGlobal) ||
           onMouseRelease(_u32Modifiers, _u32MouseButton, _v2dLocal, _v2dGlobal);

} // aBaseWin::onMouseReleaseEvent


} // namespace aWin
} // namespace aLib
