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
#include "aToolBase.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aUtil {


/*******************************************************************************
* aToolBase::aToolBase
*******************************************************************************/
aToolBase::aToolBase(aBaseWinI *_pOwnerWin,
                     u32       _u32ToolId,
                     u64       _u64ToolBaseFunction)
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
aBaseWinI* aToolBase::ownerWin() const
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
* aToolBase::toolBaseFunction
*******************************************************************************/
u64 aToolBase::toolBaseFunction() const
{
    return m_u64ToolBaseFunction;
} // aToolBase::toolBaseFunction


/*******************************************************************************
* aToolBase::onWheel
*******************************************************************************/
enumToolResult aToolBase::onWheel(u32                     /*_u32Modifiers*/,
                                  s32                     /*_s32Degree*/,
                                  const aPoint2D<s32>    &/*_v2dLocal*/,
                                  const aPoint2D<s32>    &/*_v2dGlobal*/)
{
    return enumToolResult::Unhandled;
} // aToolBase::onWheel


/*******************************************************************************
* aToolBase::onToolActivated
*******************************************************************************/
void aToolBase::onToolActivated(bool /*_bActivated*/)
{
} // aToolBase::onToolActivated


/*******************************************************************************
* aToolBase::toolOnWheel
*******************************************************************************/
enumToolResult aToolBase::toolOnWheel(u32                    _u32Modifiers,
                                      s32                    _s32Deree,
                                      const aPoint2D<s32>   &_v2dLocal,
                                      const aPoint2D<s32>   &_v2dGlobal)
{
    return onWheel(_u32Modifiers, _s32Deree, _v2dLocal, _v2dGlobal);
} // aToolBase::toolOnWheel


} // namespace aUtil
} // namespace aLib






// namespace qLib
// {
//
//     /*******************************************************************************
//     * aToolBase::GetMoveDeltaLocal
//     *******************************************************************************/
//     aPoint2D<s32> aToolBase::GetMoveDeltaLocal() const
//     {
//         return m_v2dMoveCurrentLocal - m_v2dMoveStartLocal;
//     } // aToolBase::GetMoveDeltaLocal


//     /*******************************************************************************
//     * aToolBase::GetMoveDeltaGlobal
//     *******************************************************************************/
//     aPoint2D<s32> aToolBase::GetMoveDeltaGlobal() const
//     {
//         return m_v2dMoveCurrentGlobal - m_v2dMoveStartGlobal;
//     } // aToolBase::GetMoveDeltaGlobal


//     /*******************************************************************************
//     * aToolBase::OnSetCursor
//     *******************************************************************************/
//     void aToolBase::OnSetCursor()
//     {
//     } // aToolBase::OnSetCursor


//     /*******************************************************************************
//     * aToolBase::OnPaintToolMarker
//     *******************************************************************************/
//     void aToolBase::OnPaintToolMarker()
//     {
//         if (m_bDrawXorRect)
//         {
//             CHECK_PRE_CONDITION_VOID(GetOwnerWin() != nullptr);

//             qPen        pen(colWhite);
//             qPainter    p(GetOwnerWin());

//             p.SetCompositionMode(enumCompositionMode::Xor);
//             p.DrawRect(m_v2dMoveStartLocal, m_v2dMoveCurrentLocal, &pen);
//         }
//     } // aToolBase::OnPaintToolMarker


//     /*******************************************************************************
//     * aToolBase::OnXorRect
//     *******************************************************************************/
//     void aToolBase::OnXorRect(const qRect2D<s32>    &/*_r2dXor*/)
//     {
//     } // aToolBase::OnXorRect


//     /*******************************************************************************
//     * aToolBase::OnContextMenu
//     *******************************************************************************/
//     enumToolResult aToolBase::OnContextMenu(u32                     /*_u32Modifiers*/,
//                                             const aPoint2D<s32>    &/*_v2dLocal*/,
//                                             const aPoint2D<s32>    &/*_v2dGlobal*/)
//     {
//         return enumToolResult::Unhandled;
//     } // aToolBase::OnContextMenu


//     /*******************************************************************************
//     * aToolBase::OnEnter
//     *******************************************************************************/
//     enumToolResult aToolBase::OnEnter(u32                     /*_u32Modifiers*/,
//                                       const aPoint2D<s32>    &/*_v2dLocal*/,
//                                       const aPoint2D<s32>    &/*_v2dGlobal*/)
//     {
//         return enumToolResult::Unhandled;
//     } // aToolBase::OnEnter


//     /*******************************************************************************
//     * aToolBase::OnLeave
//     *******************************************************************************/
//     enumToolResult aToolBase::OnLeave(u32                     /*_u32Modifiers*/)
//     {
//         return enumToolResult::Unhandled;
//     } // aToolBase::OnLeave


//     /*******************************************************************************
//     * aToolBase::OnDoubleClick
//     *******************************************************************************/
//     enumToolResult aToolBase::OnDoubleClick(u32                   /*_u32Modifiers*/,
//                                             u32                   /*_u32MouseButton*/,
//                                             const aPoint2D<s32>  &/*_v2dLocal*/,
//                                             const aPoint2D<s32>  &/*_v2dGlobal*/)
//     {
//         return enumToolResult::Unhandled;
//     } // aToolBase::OnDoubleClick


//     /*******************************************************************************
//     * aToolBase::OnLDoubleClick
//     *******************************************************************************/
//     enumToolResult aToolBase::OnLDoubleClick(u32                     /*_u32Modifiers*/,
//                                              const aPoint2D<s32>    &/*_v2dLocal*/,
//                                              const aPoint2D<s32>    &/*_v2dGlobal*/)
//     {
//         return enumToolResult::Unhandled;
//     } // aToolBase::OnLDoubleClick


//     /*******************************************************************************
//     * aToolBase::OnMDoubleClick
//     *******************************************************************************/
//     enumToolResult aToolBase::OnMDoubleClick(u32                     /*_u32Modifiers*/,
//                                              const aPoint2D<s32>    &/*_v2dLocal*/,
//                                              const aPoint2D<s32>    &/*_v2dGlobal*/)
//     {
//         return enumToolResult::Unhandled;
//     } // aToolBase::OnMDoubleClick


//     /*******************************************************************************
//     * aToolBase::OnRDoubleClick
//     *******************************************************************************/
//     enumToolResult aToolBase::OnRDoubleClick(u32                     /*_u32Modifiers*/,
//                                              const aPoint2D<s32>    &/*_v2dLocal*/,
//                                              const aPoint2D<s32>    &/*_v2dGlobal*/)
//     {
//         return enumToolResult::Unhandled;
//     } // aToolBase::OnRDoubleClick


//     /*******************************************************************************
//     * aToolBase::OnMousePress
//     *******************************************************************************/
//     enumToolResult aToolBase::OnMousePress(u32                   /*_u32Modifiers*/,
//                                            u32                   /*_u32MouseButton*/,
//                                            const aPoint2D<s32>  &/*_v2dLocal*/,
//                                            const aPoint2D<s32>  &/*_v2dGlobal*/)
//     {
//         return enumToolResult::Unhandled;
//     } // aToolBase::OnMousePress


//     /*******************************************************************************
//     * aToolBase::OnLMousePress
//     *******************************************************************************/
//     enumToolResult aToolBase::OnLMousePress(u32                     /*_u32Modifiers*/,
//                                             const aPoint2D<s32>    &/*_v2dLocal*/,
//                                             const aPoint2D<s32>    &/*_v2dGlobal*/)
//     {
//         enumToolResult eResult  = enumToolResult::Unhandled;

//         if (MU<s32>::AreBitsSet(GetToolBaseFunction(), TBF_LXOR_RECT))
//         {
//             // finish xor-rect mode
//             m_bDrawXorRect = true;

//             eResult = enumToolResult::Handled;
//         }

//         return eResult;
//     } // aToolBase::OnLMousePress


//     /*******************************************************************************
//     * aToolBase::OnMMousePress
//     *******************************************************************************/
//     enumToolResult aToolBase::OnMMousePress(u32                     /*_u32Modifiers*/,
//                                             const aPoint2D<s32>    &/*_v2dLocal*/,
//                                             const aPoint2D<s32>    &/*_v2dGlobal*/)
//     {
//         return enumToolResult::Unhandled;
//     } // aToolBase::OnMMousePress


//     /*******************************************************************************
//     * aToolBase::OnRMousePress
//     *******************************************************************************/
//     enumToolResult aToolBase::OnRMousePress(u32                     /*_u32Modifiers*/,
//                                         const aPoint2D<s32>    &/*_v2dLocal*/,
//                                         const aPoint2D<s32>    &/*_v2dGlobal*/)
//     {
//         return enumToolResult::Unhandled;
//     } // aToolBase::OnRMousePress


//     /*******************************************************************************
//     * aToolBase::OnMouseMove
//     *******************************************************************************/
//     enumToolResult aToolBase::OnMouseMove(u32                   /*_u32Modifiers*/,
//                                       u32                   /*_u32MouseButton*/,
//                                       const aPoint2D<s32>  &/*_v2dLocal*/,
//                                       const aPoint2D<s32>  &/*_v2dGlobal*/)
//     {
//         return enumToolResult::Unhandled;
//     } // aToolBase::OnRMouseMove


//     /*******************************************************************************
//     * aToolBase::OnLMouseMove
//     *******************************************************************************/
//     enumToolResult aToolBase::OnLMouseMove(u32                     /*_u32Modifiers*/,
//                                            const aPoint2D<s32>    &/*_v2dLocal*/,
//                                            const aPoint2D<s32>    &/*_v2dGlobal*/)
//     {
//         CHECK_PRE_CONDITION(GetOwnerWin() != nullptr, enumToolResult::Unhandled);
//         enumToolResult eResult  = enumToolResult::Unhandled;

//         if (MU<s32>::AreBitsSet(GetToolBaseFunction(), TBF_LXOR_RECT))
//         {

//             eResult = enumToolResult::Handled;

//             // repaiunt the owner win to reflect the changes (new xor-rect)
//             GetOwnerWin()->Update();
//         }

//         return eResult;
//     } // aToolBase::OnLMouseMove


//     /*******************************************************************************
//     * aToolBase::OnMMouseMove
//     *******************************************************************************/
//     enumToolResult aToolBase::OnMMouseMove(u32                     /*_u32Modifiers*/,
//                                        const aPoint2D<s32>    &/*_v2dLocal*/,
//                                        const aPoint2D<s32>    &/*_v2dGlobal*/)
//     {
//         return enumToolResult::Unhandled;
//     } // aToolBase::OnMMouseMove


//     /*******************************************************************************
//     * aToolBase::OnRMouseMove
//     *******************************************************************************/
//     enumToolResult aToolBase::OnRMouseMove(u32                     /*_u32Modifiers*/,
//                                        const aPoint2D<s32>    &/*_v2dLocal*/,
//                                        const aPoint2D<s32>    &/*_v2dGlobal*/)
//     {
//         return enumToolResult::Unhandled;
//     } // aToolBase::OnRMouseMove


//     /*******************************************************************************
//     * aToolBase::OnMouseRelease
//     *******************************************************************************/
//     enumToolResult aToolBase::OnMouseRelease(u32                   /*_u32Modifiers*/,
//                                          u32                   /*_u32MouseButton*/,
//                                          const aPoint2D<s32>  &/*_v2dLocal*/,
//                                          const aPoint2D<s32>  &/*_v2dGlobal*/)
//     {
//         return enumToolResult::Unhandled;
//     } // aToolBase::OnMouseRelease


//     /*******************************************************************************
//     * aToolBase::OnLMouseRelease
//     *******************************************************************************/
//     enumToolResult aToolBase::OnLMouseRelease(u32                     /*_u32Modifiers*/,
//                                           const aPoint2D<s32>    &/*_v2dLocal*/,
//                                           const aPoint2D<s32>    &/*_v2dGlobal*/)
//     {
//         CHECK_PRE_CONDITION(GetOwnerWin() != nullptr, enumToolResult::Unhandled);
//         enumToolResult eResult  = enumToolResult::Unhandled;

//         if (MU<s32>::AreBitsSet(GetToolBaseFunction(), TBF_LXOR_RECT))
//         {
//             // finish xor-rect mode
//             m_bDrawXorRect = false;

//             // repaiunt the owner win to reflect the changes (new xor-rect)
//             GetOwnerWin()->Update();

//             OnXorRect(qRect2D<s32>  (m_v2dMoveStartLocal, m_v2dMoveCurrentLocal));

//             eResult = enumToolResult::Handled;
//         }

//         return eResult;
//     } // aToolBase::OnLMouseRelease


//     /*******************************************************************************
//     * aToolBase::OnMMouseRelease
//     *******************************************************************************/
//     enumToolResult aToolBase::OnMMouseRelease(u32                     /*_u32Modifiers*/,
//                                           const aPoint2D<s32>    &/*_v2dLocal*/,
//                                           const aPoint2D<s32>    &/*_v2dGlobal*/)
//     {
//         return enumToolResult::Unhandled;
//     } // aToolBase::OnMMouseRelease


//     /*******************************************************************************
//     * aToolBase::OnRMouseRelease
//     *******************************************************************************/
//     enumToolResult aToolBase::OnRMouseRelease(u32                     _u32Modifiers,
//                                           const aPoint2D<s32>    &_v2dLocal,
//                                           const aPoint2D<s32>    &_v2dGlobal)
//     {
//         CHECK_PRE_CONDITION(GetOwnerWin() != nullptr, enumToolResult::Unhandled);
//         enumToolResult eResult  = enumToolResult::Unhandled;


//         // probaly show a context menu
//         eResult = OnContextMenu(_u32Modifiers, _v2dLocal, _v2dGlobal);

//         return eResult;
//     } // aToolBase::OnRMouseRelease


//     /*******************************************************************************
//     * aToolBase::ToolOnEnter
//     *******************************************************************************/
//     enumToolResult aToolBase::ToolOnEnter(u32                    _u32Modifiers,
//                                           const aPoint2D<s32>   &_v2dLocal,
//                                           const aPoint2D<s32>   &_v2dGlobal)
//     {
//         return OnEnter(_u32Modifiers, _v2dLocal, _v2dGlobal);
//     } // aToolBase::ToolOnEnter


//     /*******************************************************************************
//     * aToolBase::ToolOnLeave
//     *******************************************************************************/
//     enumToolResult aToolBase::ToolOnLeave(u32                    _u32Modifiers)
//     {
//         return OnLeave(_u32Modifiers);
//     } // aToolBase::ToolOnLeave


//     /*******************************************************************************
//     * aToolBase::ToolOnDoubleClick
//     *******************************************************************************/
//     enumToolResult aToolBase::ToolOnDoubleClick(u32                   _u32Modifiers,
//                                             u32                   _u32MouseButton,
//                                             const aPoint2D<s32>  &_v2dLocal,
//                                             const aPoint2D<s32>  &_v2dGlobal)
//     {
//         enumToolResult eResult  = enumToolResult::Unhandled;

//         switch (_u32MouseButton)
//         {
//             default:
//                 eResult = OnDoubleClick(_u32Modifiers, _u32MouseButton, _v2dLocal, _v2dGlobal);
//                 break;

//             case MOUSE_BTN_LEFT:
//                 eResult = OnLDoubleClick(_u32Modifiers, _v2dLocal, _v2dGlobal);
//                 break;

//             case MOUSE_BTN_MIDDLE:
//                 eResult = OnMDoubleClick(_u32Modifiers, _v2dLocal, _v2dGlobal);
//                 break;

//             case MOUSE_BTN_RIGHT:
//                 eResult = OnRDoubleClick(_u32Modifiers, _v2dLocal, _v2dGlobal);
//                 break;
//             } // switch

//             return eResult;
//     } // aToolBase::ToolOnDoubleClick


//     /*******************************************************************************
//     * aToolBase::ToolOnMousePress
//     *******************************************************************************/
//     enumToolResult aToolBase::ToolOnMousePress(u32                   _u32Modifiers,
//                                                u32                   _u32MouseButton,
//                                                const aPoint2D<s32>  &_v2dLocal,
//                                                const aPoint2D<s32>  &_v2dGlobal)
//     {
//         enumToolResult eResult  = enumToolResult::Unhandled;

//         m_u32MouseButton = _u32MouseButton;

//         // local move values
//         m_v2dMoveStartLocal     = _v2dLocal;
//         m_v2dMoveCurrentLocal   = _v2dLocal;

//         // global move values
//         m_v2dMoveStartGlobal    = _v2dGlobal;
//         m_v2dMoveCurrentGlobal  = _v2dGlobal;


//         switch (m_u32MouseButton)
//         {
//             default:
//                 eResult = OnMousePress(_u32Modifiers, m_u32MouseButton, _v2dLocal, _v2dGlobal);
//                 break;

//             case MOUSE_BTN_LEFT:
//                 eResult = OnLMousePress(_u32Modifiers, _v2dLocal, _v2dGlobal);
//                 break;

//             case MOUSE_BTN_MIDDLE:
//                 eResult = OnMMousePress(_u32Modifiers, _v2dLocal, _v2dGlobal);
//                 break;

//             case MOUSE_BTN_RIGHT:
//                 eResult = OnRMousePress(_u32Modifiers, _v2dLocal, _v2dGlobal);
//                 break;
//         } // switch

//         return eResult;
//     } // aToolBase::ToolOnMousePress


//     /*******************************************************************************
//     * aToolBase::ToolOnMouseMove
//     *******************************************************************************/
//     enumToolResult aToolBase::ToolOnMouseMove(u32                   _u32Modifiers,
//                                               u32                   _u32MouseButton,
//                                               const aPoint2D<s32>  &_v2dLocal,
//                                               const aPoint2D<s32>  &_v2dGlobal)
//     {
//         enumToolResult eResult  = enumToolResult::Unhandled;

//         m_v2dMoveCurrentLocal   = _v2dLocal;
//         m_v2dMoveCurrentGlobal  = _v2dGlobal;

//         switch (m_u32MouseButton)
//         {
//             default:
//                 eResult = OnMouseMove(_u32Modifiers, _u32MouseButton, _v2dLocal, _v2dGlobal);
//                 break;

//             case MOUSE_BTN_LEFT:
//                 eResult = OnLMouseMove(_u32Modifiers, _v2dLocal, _v2dGlobal);
//                 break;

//             case MOUSE_BTN_MIDDLE:
//                 eResult = OnMMouseMove(_u32Modifiers, _v2dLocal, _v2dGlobal);
//                 break;

//             case MOUSE_BTN_RIGHT:
//                 eResult = OnRMousePress(_u32Modifiers, _v2dLocal, _v2dGlobal);
//                 break;
//         } // switch

//         return eResult;
//     } // aToolBase::ToolOnMouseMove


//     /*******************************************************************************
//     * aToolBase::ToolOnMouseRelease
//     *******************************************************************************/
//     enumToolResult aToolBase::ToolOnMouseRelease(u32                   _u32Modifiers,
//                                              u32                   /*_u32MouseButton*/,
//                                              const aPoint2D<s32>  &_v2dLocal,
//                                              const aPoint2D<s32>  &_v2dGlobal)
//     {
//         enumToolResult eResult  = enumToolResult::Unhandled;

//         switch (m_u32MouseButton)
//         {
//             default:
//                 eResult = OnMouseRelease(_u32Modifiers, m_u32MouseButton, _v2dLocal, _v2dGlobal);
//                 break;

//             case MOUSE_BTN_LEFT:
//                 eResult = OnLMouseRelease(_u32Modifiers, _v2dLocal, _v2dGlobal);
//                 break;

//             case MOUSE_BTN_MIDDLE:
//                 eResult = OnMMouseRelease(_u32Modifiers, _v2dLocal, _v2dGlobal);
//                 break;

//             case MOUSE_BTN_RIGHT:
//                 eResult = OnRMouseRelease(_u32Modifiers, _v2dLocal, _v2dGlobal);
//                 break;
//         } // switch

//         m_u32MouseButton = MOUSE_BTN_NONE;

//         return eResult;
//     } // aToolBase::ToolOnMouseRelease

// } // namespace qLib
