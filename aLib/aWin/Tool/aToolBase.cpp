/*******************************************************************************
* \file aToolBase.inl
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
#include "aWin/Tool/aToolBase.h"
#include "aWin/Framework/aBaseWin.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aWin {


/*******************************************************************************
* aToolBase::aToolBase
*******************************************************************************/
aToolBase::aToolBase(aBaseWin   *_pOwnerWin,
                     u32        _u32ToolId,
                     u64        _u64ToolBaseFunction)
: m_pOwnerWin(_pOwnerWin),
  m_u32ToolId(_u32ToolId),
  m_u64ToolBaseFunction(_u64ToolBaseFunction)
{
} // aToolBase::aToolBase


/*******************************************************************************
* aToolBase::~aToolBase
*******************************************************************************/
aToolBase::~aToolBase()
{
} // aToolBase::~aToolBase


/*******************************************************************************
* aToolBase::ownerWin
*******************************************************************************/
aBaseWin* aToolBase::ownerWin() const
{
    return m_pOwnerWin;
} // aToolBase::ownerWin


/*******************************************************************************
* aToolBase::toolId
*******************************************************************************/
u32 aToolBase::toolId() const
{
    return m_u32ToolId;
} // aToolBase::toolId


/*******************************************************************************
* aToolBase::setCursor
*******************************************************************************/
void aToolBase::setCursor(u32                   /*_u32Modifiers*/,
                          const aVector2D<s32>  &/*_v2dLocal*/,
                          const aVector2D<s32>  &/*_v2dGlobal*/)
{
} // aToolBase::setCursor


// /*******************************************************************************
// * aToolBase::paintToolMarker
// *******************************************************************************/
// void aToolBase::paintToolMarker()
// {
//     // if (m_bDrawXorRect)
//     // {
//     //     CHECK_PRE_CONDITION_VOID(GetOwnerWin() != nullptr);

//     //     qPen        pen(colWhite);
//     //     qPainter    p(GetOwnerWin());

//     //     p.SetCompositionMode(enumCompositionMode::Xor);
//     //     p.DrawRect(m_v2dMoveStartLocal, m_v2dMoveCurrentLocal, &pen);
//     // }
// } // aToolBase::paintToolMarker


/*******************************************************************************
* aToolBase::moveDeltaLocal
*******************************************************************************/
aVector2D<s32> aToolBase::moveDeltaLocal() const
{
    return m_v2dMoveCurrentLocal - m_v2dMoveStartLocal;
} // aToolBase::moveDeltaLocal


/*******************************************************************************
* aToolBase::moveDeltaGlobal
*******************************************************************************/
aVector2D<s32> aToolBase::moveDeltaGlobal() const
{
    return m_v2dMoveCurrentGlobal - m_v2dMoveStartGlobal;
} // aToolBase::moveDeltaGlobal


/*******************************************************************************
* aToolBase::setCursor
*******************************************************************************/
void aToolBase::setCursor()
{
    aBaseWin *pOwner = ownerWin();
    CHECK_PRE_CONDITION_VOID(pOwner != nullptr);

    u32             u32Modifiers    = pOwner->modifiers();
    aVector2D<s32>  v2dLocal        = pOwner->localCursorPos();
    aVector2D<s32>  v2dGlobal       = pOwner->globalCursorPos();

    setCursor(u32Modifiers, v2dLocal, v2dGlobal);
} // aToolBase::setCursor


/*******************************************************************************
* aToolBase::onToolActivated
*******************************************************************************/
void aToolBase::onToolActivated(bool /*_bActivated*/)
{
} // aToolBase::onToolActivated


// /*******************************************************************************
// * aToolBase::onXorRect
// *******************************************************************************/
// void aToolBase::onXorRect(const qRect2D<s32>    &/*_r2dXor*/)
// {
// } // aToolBase::onXorRect


/*******************************************************************************
* aToolBase::onContextMenu
*******************************************************************************/
enumToolResult aToolBase::onContextMenu(u32                     /*_u32Modifiers*/,
                                        const aVector2D<s32>    &/*_v2dLocal*/,
                                        const aVector2D<s32>    &/*_v2dGlobal*/)
{
    return enumToolResult::Unhandled;
} // aToolBase::onContextMenu


/*******************************************************************************
* aToolBase::onEnter
*******************************************************************************/
enumToolResult aToolBase::onEnter(u32                     /*_u32Modifiers*/,
                                  const aVector2D<s32>    &/*_v2dLocal*/,
                                  const aVector2D<s32>    &/*_v2dGlobal*/)
{
    return enumToolResult::Unhandled;
} // aToolBase::onEnter


/*******************************************************************************
* aToolBase::onLeave
*******************************************************************************/
enumToolResult aToolBase::onLeave(u32 /*_u32Modifiers*/)
{
    return enumToolResult::Unhandled;
} // aToolBase::onLeave


/*******************************************************************************
* aToolBase::onWheel
*******************************************************************************/
enumToolResult aToolBase::onWheel(u32                     /*_u32Modifiers*/,
                                  s32                     /*_s32Degree*/,
                                  const aVector2D<s32>    &/*_v2dLocal*/,
                                  const aVector2D<s32>    &/*_v2dGlobal*/)
{
    return enumToolResult::Unhandled;
} // aToolBase::onWheel


/*******************************************************************************
* aToolBase::onDoubleClick
*******************************************************************************/
enumToolResult aToolBase::onDoubleClick(u32                   /*_u32Modifiers*/,
                                        u32                   /*_u32MouseButton*/,
                                        const aVector2D<s32>  &/*_v2dLocal*/,
                                        const aVector2D<s32>  &/*_v2dGlobal*/)
{
    return enumToolResult::Unhandled;
} // aToolBase::onDoubleClick


/*******************************************************************************
* aToolBase::onLDoubleClick
*******************************************************************************/
enumToolResult aToolBase::onLDoubleClick(u32                     /*_u32Modifiers*/,
                                         const aVector2D<s32>    &/*_v2dLocal*/,
                                         const aVector2D<s32>    &/*_v2dGlobal*/)
{
    return enumToolResult::Unhandled;
} // aToolBase::onLDoubleClick


/*******************************************************************************
* aToolBase::onMDoubleClick
*******************************************************************************/
enumToolResult aToolBase::onMDoubleClick(u32                     /*_u32Modifiers*/,
                                         const aVector2D<s32>    &/*_v2dLocal*/,
                                         const aVector2D<s32>    &/*_v2dGlobal*/)
{
    return enumToolResult::Unhandled;
} // aToolBase::onMDoubleClick


/*******************************************************************************
* aToolBase::onRDoubleClick
*******************************************************************************/
enumToolResult aToolBase::onRDoubleClick(u32                     /*_u32Modifiers*/,
                                         const aVector2D<s32>    &/*_v2dLocal*/,
                                         const aVector2D<s32>    &/*_v2dGlobal*/)
{
    return enumToolResult::Unhandled;
} // aToolBase::onRDoubleClick


/*******************************************************************************
* aToolBase::onMousePress
*******************************************************************************/
enumToolResult aToolBase::onMousePress(u32                   /*_u32Modifiers*/,
                                       u32                   /*_u32MouseButton*/,
                                       const aVector2D<s32>  &/*_v2dLocal*/,
                                       const aVector2D<s32>  &/*_v2dGlobal*/)
{
    return enumToolResult::Unhandled;
} // aToolBase::onMousePress


/*******************************************************************************
* aToolBase::onLMousePress
*******************************************************************************/
enumToolResult aToolBase::onLMousePress(u32                     /*_u32Modifiers*/,
                                        const aVector2D<s32>    &/*_v2dLocal*/,
                                        const aVector2D<s32>    &/*_v2dGlobal*/)
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
} // aToolBase::onLMousePress


/*******************************************************************************
* aToolBase::onMMousePress
*******************************************************************************/
enumToolResult aToolBase::onMMousePress(u32                     /*_u32Modifiers*/,
                                        const aVector2D<s32>    &/*_v2dLocal*/,
                                        const aVector2D<s32>    &/*_v2dGlobal*/)
{
    return enumToolResult::Unhandled;
} // aToolBase::onMMousePress


/*******************************************************************************
* aToolBase::onRMousePress
*******************************************************************************/
enumToolResult aToolBase::onRMousePress(u32                     /*_u32Modifiers*/,
                                        const aVector2D<s32>    &/*_v2dLocal*/,
                                        const aVector2D<s32>    &/*_v2dGlobal*/)
{
    return enumToolResult::Unhandled;
} // aToolBase::onRMousePress


/*******************************************************************************
* aToolBase::onMouseMove
*******************************************************************************/
enumToolResult aToolBase::onMouseMove(u32                   /*_u32Modifiers*/,
                                      u32                   /*_u32MouseButton*/,
                                      const aVector2D<s32>  &/*_v2dLocal*/,
                                      const aVector2D<s32>  &/*_v2dGlobal*/)
{
    return enumToolResult::Unhandled;
} // aToolBase::onMouseMove


/*******************************************************************************
* aToolBase::onLMouseMove
*******************************************************************************/
enumToolResult aToolBase::onLMouseMove(u32                     /*_u32Modifiers*/,
                                       const aVector2D<s32>    &/*_v2dLocal*/,
                                       const aVector2D<s32>    &/*_v2dGlobal*/)
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
} // aToolBase::onLMouseMove


/*******************************************************************************
* aToolBase::onMMouseMove
*******************************************************************************/
enumToolResult aToolBase::onMMouseMove(u32                     /*_u32Modifiers*/,
                                       const aVector2D<s32>    &/*_v2dLocal*/,
                                       const aVector2D<s32>    &/*_v2dGlobal*/)
{
    return enumToolResult::Unhandled;
} // aToolBase::onMMouseMove


/*******************************************************************************
* aToolBase::onRMouseMove
*******************************************************************************/
enumToolResult aToolBase::onRMouseMove(u32                     /*_u32Modifiers*/,
                                       const aVector2D<s32>    &/*_v2dLocal*/,
                                       const aVector2D<s32>    &/*_v2dGlobal*/)
{
    return enumToolResult::Unhandled;
} // aToolBase::onRMouseMove


/*******************************************************************************
* aToolBase::onMouseRelease
*******************************************************************************/
enumToolResult aToolBase::onMouseRelease(u32                   /*_u32Modifiers*/,
                                         u32                   /*_u32MouseButton*/,
                                         const aVector2D<s32>  &/*_v2dLocal*/,
                                         const aVector2D<s32>  &/*_v2dGlobal*/)
{
    return enumToolResult::Unhandled;
} // aToolBase::onMouseRelease


/*******************************************************************************
* aToolBase::onLMouseRelease
*******************************************************************************/
enumToolResult aToolBase::onLMouseRelease(u32                     /*_u32Modifiers*/,
                                          const aVector2D<s32>    &/*_v2dLocal*/,
                                          const aVector2D<s32>    &/*_v2dGlobal*/)
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
} // aToolBase::onLMouseRelease


/*******************************************************************************
* aToolBase::onMMouseRelease
*******************************************************************************/
enumToolResult aToolBase::onMMouseRelease(u32                     /*_u32Modifiers*/,
                                          const aVector2D<s32>    &/*_v2dLocal*/,
                                          const aVector2D<s32>    &/*_v2dGlobal*/)
{
    return enumToolResult::Unhandled;
} // aToolBase::onMMouseRelease


/*******************************************************************************
* aToolBase::onRMouseRelease
*******************************************************************************/
enumToolResult aToolBase::onRMouseRelease(u32                     _u32Modifiers,
                                          const aVector2D<s32>    &_v2dLocal,
                                          const aVector2D<s32>    &_v2dGlobal)
{
    CHECK_PRE_CONDITION(ownerWin() != nullptr, enumToolResult::Unhandled);
    enumToolResult eResult  = enumToolResult::Unhandled;


    // probaly show a context menu
    eResult = onContextMenu(_u32Modifiers, _v2dLocal, _v2dGlobal);

    return eResult;
} // aToolBase::onRMouseRelease


/*******************************************************************************
* aToolBase::doToolEnter
*******************************************************************************/
enumToolResult aToolBase::doToolEnter(u32                    _u32Modifiers,
                                      const aVector2D<s32>   &_v2dLocal,
                                      const aVector2D<s32>   &_v2dGlobal)
{
    setCursor(_u32Modifiers, _v2dLocal, _v2dGlobal);

    return onEnter(_u32Modifiers, _v2dLocal, _v2dGlobal);
} // aToolBase::doToolEnter


/*******************************************************************************
* aToolBase::doToolLeave
*******************************************************************************/
enumToolResult aToolBase::doToolLeave(u32 _u32Modifiers)
{
    return onLeave(_u32Modifiers);
} // aToolBase::doToolLeave


/*******************************************************************************
* aToolBase::doToolWheel
*******************************************************************************/
enumToolResult aToolBase::doToolWheel(u32                    _u32Modifiers,
                                      s32                    _s32Deree,
                                      const aVector2D<s32>   &_v2dLocal,
                                      const aVector2D<s32>   &_v2dGlobal)
{
    return onWheel(_u32Modifiers, _s32Deree, _v2dLocal, _v2dGlobal);
} // aToolBase::doToolWheel


/*******************************************************************************
* aToolBase::doToolDoubleClick
*******************************************************************************/
enumToolResult aToolBase::doToolDoubleClick(u32                   _u32Modifiers,
                                            u32                   _u32MouseButton,
                                            const aVector2D<s32>  &_v2dLocal,
                                            const aVector2D<s32>  &_v2dGlobal)
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
} // aToolBase::doToolDoubleClick


/*******************************************************************************
* aToolBase::doToolMousePress
*******************************************************************************/
enumToolResult aToolBase::doToolMousePress(u32                   _u32Modifiers,
                                           u32                   _u32MouseButton,
                                           const aVector2D<s32>  &_v2dLocal,
                                           const aVector2D<s32>  &_v2dGlobal)
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
} // aToolBase::doToolMousePress


/*******************************************************************************
* aToolBase::doToolMouseMove
*******************************************************************************/
enumToolResult aToolBase::doToolMouseMove(u32                   _u32Modifiers,
                                          u32                   _u32MouseButton,
                                          const aVector2D<s32>  &_v2dLocal,
                                          const aVector2D<s32>  &_v2dGlobal)
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
} // aToolBase::doToolMouseMove


/*******************************************************************************
* aToolBase::doToolMouseRelease
*******************************************************************************/
enumToolResult aToolBase::doToolMouseRelease(u32                   _u32Modifiers,
                                             u32                   _u32MouseButton,
                                             const aVector2D<s32>  &_v2dLocal,
                                             const aVector2D<s32>  &_v2dGlobal)
{
    enumToolResult eResult  = enumToolResult::Unhandled;

    switch (m_u32MouseButton)
    {
        default:
            eResult = onMouseRelease(_u32Modifiers, _u32MouseButton, _v2dLocal, _v2dGlobal);
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
} // aToolBase::doToolMouseRelease


} // namespace aWin
} // namespace aLib
