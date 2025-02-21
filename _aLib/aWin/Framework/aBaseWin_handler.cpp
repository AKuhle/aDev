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

#include "aWin/Framework/aMainWin.h"

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
* aBaseWin::onClose
*******************************************************************************/
bool aBaseWin::onClose()
{
    return true;
} // aBaseWin::onClose


/*******************************************************************************
* aBaseWin::onFocusIn
*******************************************************************************/
void aBaseWin::onFocusIn(enumFocusReason  /*_eReason*/)
{
} // aBaseWin::onFocusIn


/*******************************************************************************
* aBaseWin::onFocusOut
*******************************************************************************/
void aBaseWin::onFocusOut(enumFocusReason  /*_eReason*/)
{
} // aBaseWin::onFocusOut


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

    aRect2D<s32> r;
    if (dynamic_cast<aMainWin *> (this) != nullptr)
    {
        r = contentRect();
    }

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
* aBaseWin::onDropUrl
*******************************************************************************/
void aBaseWin::onDropUrl(const aUrl &/*_url*/)
{
} // aBaseWin::onDropUrl


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
* aBaseWin::onFocusInEvent
*******************************************************************************/
void aBaseWin::onFocusInEvent(enumFocusReason  _eReason)
{
    onFocusIn(_eReason);
} // aBaseWin::onFocusInEvent


/*******************************************************************************
* aBaseWin::onFocusOutEvent
*******************************************************************************/
void aBaseWin::onFocusOutEvent(enumFocusReason  _eReason)
{
    onFocusOut(_eReason);
} // aBaseWin::onFocusOutEvent


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

    bool b1 = onEnter(_u32Modifiers, _v2dLocal, _v2dGlobal);
    bool b2 = doToolMgrEnter(_u32Modifiers, _v2dLocal, _v2dGlobal);

    // first call the handler of the tool, than of the win
    return b1 || b2;
} // aBaseWin::onEnterEvent


/*******************************************************************************
* aBaseWin::onLeaveEvent
*******************************************************************************/
bool aBaseWin::onLeaveEvent(u32 _u32Modifiers)
{
    m_bHover = false;

    bool b1 = onLeave(_u32Modifiers);
    bool b2 = doToolMgrLeave(_u32Modifiers);

    // first call the handler of the tool, than of the win
    return b1 || b2;
} // aBaseWin::onLeaveEvent


/*******************************************************************************
* aBaseWin::onWheelEvent
*******************************************************************************/
bool aBaseWin::onWheelEvent(u32                     _u32Modifiers,
                        s32                     _s32Degree,
                        const aVector2D<s32>    &_v2dLocal,
                        const aVector2D<s32>    &_v2dGlobal)
{
    bool b1 = onWheel(_u32Modifiers, _s32Degree, _v2dLocal, _v2dGlobal);
    bool b2 = doToolMgrWheel(_u32Modifiers, _s32Degree, _v2dLocal, _v2dGlobal);

    // first call the handler of the tool, than of the win
    return b1 || b2;
} // aBaseWin::onWheelEvent


/*******************************************************************************
* aBaseWin::onDoubleClickEvent
*******************************************************************************/
bool aBaseWin::onDoubleClickEvent(u32                   _u32Modifiers,
                                  u32                   _u32MouseButton,
                                  const aVector2D<s32>  &_v2dLocal,
                                  const aVector2D<s32>  &_v2dGlobal)
{
    bool b1 = onDoubleClick(_u32Modifiers, _u32MouseButton, _v2dLocal, _v2dGlobal);
    bool b2 = doToolMgrDoubleClick(_u32Modifiers, _u32MouseButton, _v2dLocal, _v2dGlobal);

    // first call the handler of the tool, than of the win
    return b1 || b2;
} // aBaseWin::onDoubleClickEvent


/*******************************************************************************
* aBaseWin::onMousePressEvent
*******************************************************************************/
bool aBaseWin::onMousePressEvent(u32                   _u32Modifiers,
                                 u32                   _u32MouseButton,
                                 const aVector2D<s32>  &_v2dLocal,
                                 const aVector2D<s32>  &_v2dGlobal)
{
    bool b1 = onMousePress(_u32Modifiers, _u32MouseButton, _v2dLocal, _v2dGlobal);
    bool b2 = doToolMgrMousePress(_u32Modifiers, _u32MouseButton, _v2dLocal, _v2dGlobal);

    // first call the handler of the tool, than of the win
    return b1 || b2;
} // aBaseWin::onMousePressEvent


/*******************************************************************************
* aBaseWin::onMouseMoveEvent
*******************************************************************************/
bool aBaseWin::onMouseMoveEvent(u32                   _u32Modifiers,
                                u32                   _u32MouseButton,
                                const aVector2D<s32>  &_v2dLocal,
                                const aVector2D<s32>  &_v2dGlobal)
{
    bool b1 = onMouseMove(_u32Modifiers, _u32MouseButton, _v2dLocal, _v2dGlobal);
    bool b2 = doToolMgrMouseMove(_u32Modifiers, _u32MouseButton, _v2dLocal, _v2dGlobal);

    // first call the handler of the tool, than of the win
    return b1 || b2;
} // aBaseWin::onMouseMoveEvent


/*******************************************************************************
* aBaseWin::onMouseReleaseEvent
*******************************************************************************/
bool aBaseWin::onMouseReleaseEvent(u32                   _u32Modifiers,
                                   u32                   _u32MouseButton,
                                   const aVector2D<s32>  &_v2dLocal,
                                   const aVector2D<s32>  &_v2dGlobal)
{
    bool b1 = onMouseRelease(_u32Modifiers, _u32MouseButton, _v2dLocal, _v2dGlobal);
    bool b2 = doToolMgrMouseRelease(_u32Modifiers, _u32MouseButton, _v2dLocal, _v2dGlobal);

    // first call the handler of the tool, than of the win
    return b1 || b2;
} // aBaseWin::onMouseReleaseEvent


/*******************************************************************************
* aBaseWin::onDropUrlEvent
*******************************************************************************/
void aBaseWin::onDropUrlEvent(const aUrl &_url)
{
    onDropUrl(_url);
} // aBaseWin::onDropUrlEvent


} // namespace aWin
} // namespace aLib
