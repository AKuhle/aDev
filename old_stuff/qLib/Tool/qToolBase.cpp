/*******************************************************************************
* \file qToolBase.inl
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


/*******************************************************************************
* includes
*******************************************************************************/
#include "qToolBase.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace qLib {
namespace Tool {


/*******************************************************************************
* qToolBase::qToolBase
*******************************************************************************/
qToolBase::qToolBase(qWin   *_pOwnerWin,
                     u32    _u32ToolId,
                     u64    _u64ToolBaseFunction)
: m_pOwnerWin(_pOwnerWin),
  m_u32ToolId(_u32ToolId),
  m_u64ToolBaseFunction(_u64ToolBaseFunction)
{
} // qToolBase::qToolBase


/*******************************************************************************
* qToolBase::~qToolBase
*******************************************************************************/
qToolBase::~qToolBase()
{
} // qToolBase::~qToolBase


/*******************************************************************************
* qToolBase::ownerWin
*******************************************************************************/
qWin* qToolBase::ownerWin() const
{
    return m_pOwnerWin;
} // qToolBase::ownerWin


/*******************************************************************************
* qToolBase::toolId
*******************************************************************************/
u32 qToolBase::toolId() const
{
    return m_u32ToolId;
} // qToolBase::toolId


/*******************************************************************************
* qToolBase::setCursor
*******************************************************************************/
void qToolBase::setCursor()
{
} // qToolBase::setCursor


/*******************************************************************************
* qToolBase::paintToolMarker
*******************************************************************************/
void qToolBase::paintToolMarker()
{
    // if (m_bDrawXorRect)
    // {
    //     CHECK_PRE_CONDITION_VOID(GetOwnerWin() != nullptr);

    //     qPen        pen(colWhite);
    //     qPainter    p(GetOwnerWin());

    //     p.SetCompositionMode(enumCompositionMode::Xor);
    //     p.DrawRect(m_v2dMoveStartLocal, m_v2dMoveCurrentLocal, &pen);
    // }
} // qToolBase::paintToolMarker


/*******************************************************************************
* qToolBase::moveDeltaLocal
*******************************************************************************/
qVector2D<s32> qToolBase::moveDeltaLocal() const
{
    return m_v2dMoveCurrentLocal - m_v2dMoveStartLocal;
} // qToolBase::moveDeltaLocal


/*******************************************************************************
* qToolBase::moveDeltaGlobal
*******************************************************************************/
qVector2D<s32> qToolBase::moveDeltaGlobal() const
{
    return m_v2dMoveCurrentGlobal - m_v2dMoveStartGlobal;
} // qToolBase::moveDeltaGlobal


/*******************************************************************************
* qToolBase::onToolActivated
*******************************************************************************/
void qToolBase::onToolActivated(bool /*_bActivated*/)
{
} // qToolBase::onToolActivated


/*******************************************************************************
* qToolBase::onXorRect
*******************************************************************************/
void qToolBase::onXorRect(const qRect2D<s32>    &/*_r2dXor*/)
{
} // qToolBase::onXorRect


/*******************************************************************************
* qToolBase::onContextMenu
*******************************************************************************/
enumToolResult qToolBase::onContextMenu(u32                     /*_u32Modifiers*/,
                                        const qVector2D<s32>    &/*_v2dLocal*/,
                                        const qVector2D<s32>    &/*_v2dGlobal*/)
{
    return enumToolResult::Unhandled;
} // qToolBase::onContextMenu


/*******************************************************************************
* qToolBase::onEnter
*******************************************************************************/
enumToolResult qToolBase::onEnter(u32                     /*_u32Modifiers*/,
                                  const qVector2D<s32>    &/*_v2dLocal*/,
                                  const qVector2D<s32>    &/*_v2dGlobal*/)
{
    return enumToolResult::Unhandled;
} // qToolBase::onEnter


/*******************************************************************************
* qToolBase::onLeave
*******************************************************************************/
enumToolResult qToolBase::onLeave(u32 /*_u32Modifiers*/)
{
    return enumToolResult::Unhandled;
} // qToolBase::onLeave


/*******************************************************************************
* qToolBase::onWheel
*******************************************************************************/
enumToolResult qToolBase::onWheel(u32                     /*_u32Modifiers*/,
                                  s32                     /*_s32Degree*/,
                                  const qVector2D<s32>    &/*_v2dLocal*/,
                                  const qVector2D<s32>    &/*_v2dGlobal*/)
{
    return enumToolResult::Unhandled;
} // qToolBase::onWheel


/*******************************************************************************
* qToolBase::onDoubleClick
*******************************************************************************/
enumToolResult qToolBase::onDoubleClick(u32                   /*_u32Modifiers*/,
                                        u32                   /*_u32MouseButton*/,
                                        const qVector2D<s32>  &/*_v2dLocal*/,
                                        const qVector2D<s32>  &/*_v2dGlobal*/)
{
    return enumToolResult::Unhandled;
} // qToolBase::onDoubleClick


/*******************************************************************************
* qToolBase::onLDoubleClick
*******************************************************************************/
enumToolResult qToolBase::onLDoubleClick(u32                     /*_u32Modifiers*/,
                                         const qVector2D<s32>    &/*_v2dLocal*/,
                                         const qVector2D<s32>    &/*_v2dGlobal*/)
{
    return enumToolResult::Unhandled;
} // qToolBase::onLDoubleClick


/*******************************************************************************
* qToolBase::onMDoubleClick
*******************************************************************************/
enumToolResult qToolBase::onMDoubleClick(u32                     /*_u32Modifiers*/,
                                         const qVector2D<s32>    &/*_v2dLocal*/,
                                         const qVector2D<s32>    &/*_v2dGlobal*/)
{
    return enumToolResult::Unhandled;
} // qToolBase::onMDoubleClick


/*******************************************************************************
* qToolBase::onRDoubleClick
*******************************************************************************/
enumToolResult qToolBase::onRDoubleClick(u32                     /*_u32Modifiers*/,
                                         const qVector2D<s32>    &/*_v2dLocal*/,
                                         const qVector2D<s32>    &/*_v2dGlobal*/)
{
    return enumToolResult::Unhandled;
} // qToolBase::onRDoubleClick


/*******************************************************************************
* qToolBase::onMousePress
*******************************************************************************/
enumToolResult qToolBase::onMousePress(u32                   /*_u32Modifiers*/,
                                       u32                   /*_u32MouseButton*/,
                                       const qVector2D<s32>  &/*_v2dLocal*/,
                                       const qVector2D<s32>  &/*_v2dGlobal*/)
{
    return enumToolResult::Unhandled;
} // qToolBase::onMousePress


/*******************************************************************************
* qToolBase::onLMousePress
*******************************************************************************/
enumToolResult qToolBase::onLMousePress(u32                     /*_u32Modifiers*/,
                                        const qVector2D<s32>    &/*_v2dLocal*/,
                                        const qVector2D<s32>    &/*_v2dGlobal*/)
{
    CHECK_PRE_CONDITION(ownerWin() != nullptr, enumToolResult::Unhandled);

    enumToolResult eResult  = enumToolResult::Unhandled;

    // if (MU<s32>::AreBitsSet(GetToolBaseFunction(), TBF_LXOR_RECT))
    // {
    //     // finish xor-rect mode
    //     m_bDrawXorRect = true;

    //     eResult = enumToolResult::Handled;
    // }

    return eResult;
} // qToolBase::onLMousePress


/*******************************************************************************
* qToolBase::onMMousePress
*******************************************************************************/
enumToolResult qToolBase::onMMousePress(u32                     /*_u32Modifiers*/,
                                        const qVector2D<s32>    &/*_v2dLocal*/,
                                        const qVector2D<s32>    &/*_v2dGlobal*/)
{
    return enumToolResult::Unhandled;
} // qToolBase::onMMousePress


/*******************************************************************************
* qToolBase::onRMousePress
*******************************************************************************/
enumToolResult qToolBase::onRMousePress(u32                     /*_u32Modifiers*/,
                                        const qVector2D<s32>    &/*_v2dLocal*/,
                                        const qVector2D<s32>    &/*_v2dGlobal*/)
{
    return enumToolResult::Unhandled;
} // qToolBase::onRMousePress


/*******************************************************************************
* qToolBase::onMouseMove
*******************************************************************************/
enumToolResult qToolBase::onMouseMove(u32                   /*_u32Modifiers*/,
                                      u32                   /*_u32MouseButton*/,
                                      const qVector2D<s32>  &/*_v2dLocal*/,
                                      const qVector2D<s32>  &/*_v2dGlobal*/)
{
    return enumToolResult::Unhandled;
} // qToolBase::onMouseMove


/*******************************************************************************
* qToolBase::onLMouseMove
*******************************************************************************/
enumToolResult qToolBase::onLMouseMove(u32                     /*_u32Modifiers*/,
                                       const qVector2D<s32>    &/*_v2dLocal*/,
                                       const qVector2D<s32>    &/*_v2dGlobal*/)
{
    CHECK_PRE_CONDITION(ownerWin() != nullptr, enumToolResult::Unhandled);

    enumToolResult eResult  = enumToolResult::Unhandled;

    // if (MU<s32>::AreBitsSet(GetToolBaseFunction(), TBF_LXOR_RECT))
    // {

    //     eResult = enumToolResult::Handled;

    //     // repaiunt the owner win to reflect the changes (new xor-rect)
    //     GetOwnerWin()->Update();
    // }

    return eResult;
} // qToolBase::onLMouseMove


/*******************************************************************************
* qToolBase::onMMouseMove
*******************************************************************************/
enumToolResult qToolBase::onMMouseMove(u32                     /*_u32Modifiers*/,
                                       const qVector2D<s32>    &/*_v2dLocal*/,
                                       const qVector2D<s32>    &/*_v2dGlobal*/)
{
    return enumToolResult::Unhandled;
} // qToolBase::onMMouseMove


/*******************************************************************************
* qToolBase::onRMouseMove
*******************************************************************************/
enumToolResult qToolBase::onRMouseMove(u32                     /*_u32Modifiers*/,
                                       const qVector2D<s32>    &/*_v2dLocal*/,
                                       const qVector2D<s32>    &/*_v2dGlobal*/)
{
    return enumToolResult::Unhandled;
} // qToolBase::onRMouseMove


/*******************************************************************************
* qToolBase::onMouseRelease
*******************************************************************************/
enumToolResult qToolBase::onMouseRelease(u32                   /*_u32Modifiers*/,
                                         u32                   /*_u32MouseButton*/,
                                         const qVector2D<s32>  &/*_v2dLocal*/,
                                         const qVector2D<s32>  &/*_v2dGlobal*/)
{
    return enumToolResult::Unhandled;
} // qToolBase::onMouseRelease


/*******************************************************************************
* qToolBase::onLMouseRelease
*******************************************************************************/
enumToolResult qToolBase::onLMouseRelease(u32                     /*_u32Modifiers*/,
                                          const qVector2D<s32>    &/*_v2dLocal*/,
                                          const qVector2D<s32>    &/*_v2dGlobal*/)
{
    CHECK_PRE_CONDITION(ownerWin() != nullptr, enumToolResult::Unhandled);

    enumToolResult eResult  = enumToolResult::Unhandled;

    // if (MU<s32>::AreBitsSet(GetToolBaseFunction(), TBF_LXOR_RECT))
    // {
    //     // finish xor-rect mode
    //     m_bDrawXorRect = false;

    //     // repaiunt the owner win to reflect the changes (new xor-rect)
    //     GetOwnerWin()->Update();

    //     OnXorRect(qRect2D<s32>  (m_v2dMoveStartLocal, m_v2dMoveCurrentLocal));

    //     eResult = enumToolResult::Handled;
    // }

    return eResult;
} // qToolBase::onLMouseRelease


/*******************************************************************************
* qToolBase::onMMouseRelease
*******************************************************************************/
enumToolResult qToolBase::onMMouseRelease(u32                     /*_u32Modifiers*/,
                                          const qVector2D<s32>    &/*_v2dLocal*/,
                                          const qVector2D<s32>    &/*_v2dGlobal*/)
{
    return enumToolResult::Unhandled;
} // qToolBase::onMMouseRelease


/*******************************************************************************
* qToolBase::onRMouseRelease
*******************************************************************************/
enumToolResult qToolBase::onRMouseRelease(u32                     _u32Modifiers,
                                          const qVector2D<s32>    &_v2dLocal,
                                          const qVector2D<s32>    &_v2dGlobal)
{
    CHECK_PRE_CONDITION(ownerWin() != nullptr, enumToolResult::Unhandled);
    enumToolResult eResult  = enumToolResult::Unhandled;


    // probaly show a context menu
    eResult = onContextMenu(_u32Modifiers, _v2dLocal, _v2dGlobal);

    return eResult;
} // qToolBase::onRMouseRelease


/*******************************************************************************
* qToolBase::doEnter
*******************************************************************************/
enumToolResult qToolBase::doEnter(u32                    _u32Modifiers,
                                  const qVector2D<s32>   &_v2dLocal,
                                  const qVector2D<s32>   &_v2dGlobal)
{
    return onEnter(_u32Modifiers, _v2dLocal, _v2dGlobal);
} // qToolBase::doEnter


/*******************************************************************************
* qToolBase::doLeave
*******************************************************************************/
enumToolResult qToolBase::doLeave(u32 _u32Modifiers)
{
    return onLeave(_u32Modifiers);
} // qToolBase::doLeave


/*******************************************************************************
* qToolBase::doWheel
*******************************************************************************/
enumToolResult qToolBase::doWheel(u32                    _u32Modifiers,
                                  s32                    _s32Deree,
                                  const qVector2D<s32>   &_v2dLocal,
                                  const qVector2D<s32>   &_v2dGlobal)
{
    return onWheel(_u32Modifiers, _s32Deree, _v2dLocal, _v2dGlobal);
} // qToolBase::doWheel


/*******************************************************************************
* qToolBase::doDoubleClick
*******************************************************************************/
enumToolResult qToolBase::doDoubleClick(u32                   _u32Modifiers,
                                        u32                   _u32MouseButton,
                                        const qVector2D<s32>  &_v2dLocal,
                                        const qVector2D<s32>  &_v2dGlobal)
{
    enumToolResult eResult  = enumToolResult::Unhandled;

    switch (_u32MouseButton)
    {
        default:
            eResult = onDoubleClick(_u32Modifiers, _u32MouseButton, _v2dLocal, _v2dGlobal);
            break;

        case MOUSE_BTN_LEFT:
            eResult = onLDoubleClick(_u32Modifiers, _v2dLocal, _v2dGlobal);
            break;

        case MOUSE_BTN_MIDDLE:
            eResult = onMDoubleClick(_u32Modifiers, _v2dLocal, _v2dGlobal);
            break;

        case MOUSE_BTN_RIGHT:
            eResult = onRDoubleClick(_u32Modifiers, _v2dLocal, _v2dGlobal);
            break;
        } // switch

        return eResult;
} // qToolBase::doDoubleClick


/*******************************************************************************
* qToolBase::doMousePress
*******************************************************************************/
enumToolResult qToolBase::doMousePress(u32                   _u32Modifiers,
                                       u32                   _u32MouseButton,
                                       const qVector2D<s32>  &_v2dLocal,
                                       const qVector2D<s32>  &_v2dGlobal)
{
    enumToolResult eResult  = enumToolResult::Unhandled;

    m_u32MouseButton = _u32MouseButton;

    // local move values
    m_v2dMoveStartLocal     = _v2dLocal;
    m_v2dMoveCurrentLocal   = _v2dLocal;

    // global move values
    m_v2dMoveStartGlobal    = _v2dGlobal;
    m_v2dMoveCurrentGlobal  = _v2dGlobal;


    switch (m_u32MouseButton)
    {
        default:
            eResult = onMousePress(_u32Modifiers, m_u32MouseButton, _v2dLocal, _v2dGlobal);
            break;

        case MOUSE_BTN_LEFT:
            eResult = onLMousePress(_u32Modifiers, _v2dLocal, _v2dGlobal);
            break;

        case MOUSE_BTN_MIDDLE:
            eResult = onMMousePress(_u32Modifiers, _v2dLocal, _v2dGlobal);
            break;

        case MOUSE_BTN_RIGHT:
            eResult = onRMousePress(_u32Modifiers, _v2dLocal, _v2dGlobal);
            break;
    } // switch

    return eResult;
} // qToolBase::doMousePress


/*******************************************************************************
* qToolBase::doMouseMove
*******************************************************************************/
enumToolResult qToolBase::doMouseMove(u32                   _u32Modifiers,
                                      u32                   _u32MouseButton,
                                      const qVector2D<s32>  &_v2dLocal,
                                      const qVector2D<s32>  &_v2dGlobal)
{
    enumToolResult eResult  = enumToolResult::Unhandled;

    m_v2dMoveCurrentLocal   = _v2dLocal;
    m_v2dMoveCurrentGlobal  = _v2dGlobal;

    switch (m_u32MouseButton)
    {
        default:
            eResult = onMouseMove(_u32Modifiers, _u32MouseButton, _v2dLocal, _v2dGlobal);
            break;

        case MOUSE_BTN_LEFT:
            eResult = onLMouseMove(_u32Modifiers, _v2dLocal, _v2dGlobal);
            break;

        case MOUSE_BTN_MIDDLE:
            eResult = onMMouseMove(_u32Modifiers, _v2dLocal, _v2dGlobal);
            break;

        case MOUSE_BTN_RIGHT:
            eResult = onRMousePress(_u32Modifiers, _v2dLocal, _v2dGlobal);
            break;
    } // switch

    return eResult;
} // qToolBase::doMouseMove


/*******************************************************************************
* qToolBase::doMouseRelease
*******************************************************************************/
enumToolResult qToolBase::doMouseRelease(u32                   _u32Modifiers,
                                         u32                   /*_u32MouseButton*/,
                                         const qVector2D<s32>  &_v2dLocal,
                                         const qVector2D<s32>  &_v2dGlobal)
{
    enumToolResult eResult  = enumToolResult::Unhandled;

    switch (m_u32MouseButton)
    {
        default:
            eResult = onMouseRelease(_u32Modifiers, m_u32MouseButton, _v2dLocal, _v2dGlobal);
            break;

        case MOUSE_BTN_LEFT:
            eResult = onLMouseRelease(_u32Modifiers, _v2dLocal, _v2dGlobal);
            break;

        case MOUSE_BTN_MIDDLE:
            eResult = onMMouseRelease(_u32Modifiers, _v2dLocal, _v2dGlobal);
            break;

        case MOUSE_BTN_RIGHT:
            eResult = onRMouseRelease(_u32Modifiers, _v2dLocal, _v2dGlobal);
            break;
    } // switch

    m_u32MouseButton = MOUSE_BTN_NONE;

    return eResult;
} // qToolBase::doMouseRelease


} // namespace Tool
} // namespace qLib
