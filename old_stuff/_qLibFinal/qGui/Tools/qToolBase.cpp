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
#include "qColor.h"
#include "qPen.h"
#include "qPainter.h"
#include "qWin.h"


namespace qLib
{
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
    * qToolBase::GetMoveDeltaLocal
    *******************************************************************************/
    qVector2D<s32> qToolBase::GetMoveDeltaLocal() const
    {
        return m_v2dMoveCurrentLocal - m_v2dMoveStartLocal;
    } // qToolBase::GetMoveDeltaLocal


    /*******************************************************************************
    * qToolBase::GetMoveDeltaGlobal
    *******************************************************************************/
    qVector2D<s32> qToolBase::GetMoveDeltaGlobal() const
    {
        return m_v2dMoveCurrentGlobal - m_v2dMoveStartGlobal;
    } // qToolBase::GetMoveDeltaGlobal


    /*******************************************************************************
    * qToolBase::OnToolActivated
    *******************************************************************************/
    void qToolBase::OnToolActivated(bool /*_bActivated*/)
    {
    } // qToolBase::OnToolActivated


    /*******************************************************************************
    * qToolBase::OnSetCursor
    *******************************************************************************/
    void qToolBase::OnSetCursor()
    {
    } // qToolBase::OnSetCursor


    /*******************************************************************************
    * qToolBase::OnPaintToolMarker
    *******************************************************************************/
    void qToolBase::OnPaintToolMarker()
    {
        if (m_bDrawXorRect)
        {
            CHECK_PRE_CONDITION_VOID(GetOwnerWin() != nullptr);

            qPen        pen(colWhite);
            qPainter    p(GetOwnerWin());

            p.SetCompositionMode(enumCompositionMode::Xor);
            p.DrawRect(m_v2dMoveStartLocal, m_v2dMoveCurrentLocal, &pen);
        }
    } // qToolBase::OnPaintToolMarker


    /*******************************************************************************
    * qToolBase::OnXorRect
    *******************************************************************************/
    void qToolBase::OnXorRect(const qRect2D<s32>    &/*_r2dXor*/)
    {
    } // qToolBase::OnXorRect


    /*******************************************************************************
    * qToolBase::OnContextMenu
    *******************************************************************************/
    enumToolResult qToolBase::OnContextMenu(u32                     /*_u32Modifiers*/,
                                            const qVector2D<s32>    &/*_v2dLocal*/,
                                            const qVector2D<s32>    &/*_v2dGlobal*/)
    {
        return enumToolResult::Unhandled;
    } // qToolBase::OnContextMenu


    /*******************************************************************************
    * qToolBase::OnEnter
    *******************************************************************************/
    enumToolResult qToolBase::OnEnter(u32                     /*_u32Modifiers*/,
                                      const qVector2D<s32>    &/*_v2dLocal*/,
                                      const qVector2D<s32>    &/*_v2dGlobal*/)
    {
        return enumToolResult::Unhandled;
    } // qToolBase::OnEnter


    /*******************************************************************************
    * qToolBase::OnLeave
    *******************************************************************************/
    enumToolResult qToolBase::OnLeave(u32                     /*_u32Modifiers*/)
    {
        return enumToolResult::Unhandled;
    } // qToolBase::OnLeave


    /*******************************************************************************
    * qToolBase::OnWheel
    *******************************************************************************/
    enumToolResult qToolBase::OnWheel(u32                     /*_u32Modifiers*/,
                                      s32                     /*_s32Degree*/,
                                      const qVector2D<s32>    &/*_v2dLocal*/,
                                      const qVector2D<s32>    &/*_v2dGlobal*/)
    {
        return enumToolResult::Unhandled;
    } // qToolBase::OnWheel


    /*******************************************************************************
    * qToolBase::OnDoubleClick
    *******************************************************************************/
    enumToolResult qToolBase::OnDoubleClick(u32                   /*_u32Modifiers*/,
                                            u32                   /*_u32MouseButton*/,
                                            const qVector2D<s32>  &/*_v2dLocal*/,
                                            const qVector2D<s32>  &/*_v2dGlobal*/)
    {
        return enumToolResult::Unhandled;
    } // qToolBase::OnDoubleClick


    /*******************************************************************************
    * qToolBase::OnLDoubleClick
    *******************************************************************************/
    enumToolResult qToolBase::OnLDoubleClick(u32                     /*_u32Modifiers*/,
                                             const qVector2D<s32>    &/*_v2dLocal*/,
                                             const qVector2D<s32>    &/*_v2dGlobal*/)
    {
        return enumToolResult::Unhandled;
    } // qToolBase::OnLDoubleClick


    /*******************************************************************************
    * qToolBase::OnMDoubleClick
    *******************************************************************************/
    enumToolResult qToolBase::OnMDoubleClick(u32                     /*_u32Modifiers*/,
                                             const qVector2D<s32>    &/*_v2dLocal*/,
                                             const qVector2D<s32>    &/*_v2dGlobal*/)
    {
        return enumToolResult::Unhandled;
    } // qToolBase::OnMDoubleClick


    /*******************************************************************************
    * qToolBase::OnRDoubleClick
    *******************************************************************************/
    enumToolResult qToolBase::OnRDoubleClick(u32                     /*_u32Modifiers*/,
                                             const qVector2D<s32>    &/*_v2dLocal*/,
                                             const qVector2D<s32>    &/*_v2dGlobal*/)
    {
        return enumToolResult::Unhandled;
    } // qToolBase::OnRDoubleClick


    /*******************************************************************************
    * qToolBase::OnMousePress
    *******************************************************************************/
    enumToolResult qToolBase::OnMousePress(u32                   /*_u32Modifiers*/,
                                           u32                   /*_u32MouseButton*/,
                                           const qVector2D<s32>  &/*_v2dLocal*/,
                                           const qVector2D<s32>  &/*_v2dGlobal*/)
    {
        return enumToolResult::Unhandled;
    } // qToolBase::OnMousePress


    /*******************************************************************************
    * qToolBase::OnLMousePress
    *******************************************************************************/
    enumToolResult qToolBase::OnLMousePress(u32                     /*_u32Modifiers*/,
                                            const qVector2D<s32>    &/*_v2dLocal*/,
                                            const qVector2D<s32>    &/*_v2dGlobal*/)
    {
        enumToolResult eResult  = enumToolResult::Unhandled;

        if (MU<s32>::AreBitsSet(GetToolBaseFunction(), TBF_LXOR_RECT))
        {
            // finish xor-rect mode
            m_bDrawXorRect = true;

            eResult = enumToolResult::Handled;
        }

        return eResult;
    } // qToolBase::OnLMousePress


    /*******************************************************************************
    * qToolBase::OnMMousePress
    *******************************************************************************/
    enumToolResult qToolBase::OnMMousePress(u32                     /*_u32Modifiers*/,
                                            const qVector2D<s32>    &/*_v2dLocal*/,
                                            const qVector2D<s32>    &/*_v2dGlobal*/)
    {
        return enumToolResult::Unhandled;
    } // qToolBase::OnMMousePress


    /*******************************************************************************
    * qToolBase::OnRMousePress
    *******************************************************************************/
    enumToolResult qToolBase::OnRMousePress(u32                     /*_u32Modifiers*/,
                                        const qVector2D<s32>    &/*_v2dLocal*/,
                                        const qVector2D<s32>    &/*_v2dGlobal*/)
    {
        return enumToolResult::Unhandled;
    } // qToolBase::OnRMousePress


    /*******************************************************************************
    * qToolBase::OnMouseMove
    *******************************************************************************/
    enumToolResult qToolBase::OnMouseMove(u32                   /*_u32Modifiers*/,
                                      u32                   /*_u32MouseButton*/,
                                      const qVector2D<s32>  &/*_v2dLocal*/,
                                      const qVector2D<s32>  &/*_v2dGlobal*/)
    {
        return enumToolResult::Unhandled;
    } // qToolBase::OnRMouseMove


    /*******************************************************************************
    * qToolBase::OnLMouseMove
    *******************************************************************************/
    enumToolResult qToolBase::OnLMouseMove(u32                     /*_u32Modifiers*/,
                                           const qVector2D<s32>    &/*_v2dLocal*/,
                                           const qVector2D<s32>    &/*_v2dGlobal*/)
    {
        CHECK_PRE_CONDITION(GetOwnerWin() != nullptr, enumToolResult::Unhandled);
        enumToolResult eResult  = enumToolResult::Unhandled;

        if (MU<s32>::AreBitsSet(GetToolBaseFunction(), TBF_LXOR_RECT))
        {

            eResult = enumToolResult::Handled;

            // repaiunt the owner win to reflect the changes (new xor-rect)
            GetOwnerWin()->Update();
        }

        return eResult;
    } // qToolBase::OnLMouseMove


    /*******************************************************************************
    * qToolBase::OnMMouseMove
    *******************************************************************************/
    enumToolResult qToolBase::OnMMouseMove(u32                     /*_u32Modifiers*/,
                                       const qVector2D<s32>    &/*_v2dLocal*/,
                                       const qVector2D<s32>    &/*_v2dGlobal*/)
    {
        return enumToolResult::Unhandled;
    } // qToolBase::OnMMouseMove


    /*******************************************************************************
    * qToolBase::OnRMouseMove
    *******************************************************************************/
    enumToolResult qToolBase::OnRMouseMove(u32                     /*_u32Modifiers*/,
                                       const qVector2D<s32>    &/*_v2dLocal*/,
                                       const qVector2D<s32>    &/*_v2dGlobal*/)
    {
        return enumToolResult::Unhandled;
    } // qToolBase::OnRMouseMove


    /*******************************************************************************
    * qToolBase::OnMouseRelease
    *******************************************************************************/
    enumToolResult qToolBase::OnMouseRelease(u32                   /*_u32Modifiers*/,
                                         u32                   /*_u32MouseButton*/,
                                         const qVector2D<s32>  &/*_v2dLocal*/,
                                         const qVector2D<s32>  &/*_v2dGlobal*/)
    {
        return enumToolResult::Unhandled;
    } // qToolBase::OnMouseRelease


    /*******************************************************************************
    * qToolBase::OnLMouseRelease
    *******************************************************************************/
    enumToolResult qToolBase::OnLMouseRelease(u32                     /*_u32Modifiers*/,
                                          const qVector2D<s32>    &/*_v2dLocal*/,
                                          const qVector2D<s32>    &/*_v2dGlobal*/)
    {
        CHECK_PRE_CONDITION(GetOwnerWin() != nullptr, enumToolResult::Unhandled);
        enumToolResult eResult  = enumToolResult::Unhandled;

        if (MU<s32>::AreBitsSet(GetToolBaseFunction(), TBF_LXOR_RECT))
        {
            // finish xor-rect mode
            m_bDrawXorRect = false;

            // repaiunt the owner win to reflect the changes (new xor-rect)
            GetOwnerWin()->Update();

            OnXorRect(qRect2D<s32>  (m_v2dMoveStartLocal, m_v2dMoveCurrentLocal));

            eResult = enumToolResult::Handled;
        }

        return eResult;
    } // qToolBase::OnLMouseRelease


    /*******************************************************************************
    * qToolBase::OnMMouseRelease
    *******************************************************************************/
    enumToolResult qToolBase::OnMMouseRelease(u32                     /*_u32Modifiers*/,
                                          const qVector2D<s32>    &/*_v2dLocal*/,
                                          const qVector2D<s32>    &/*_v2dGlobal*/)
    {
        return enumToolResult::Unhandled;
    } // qToolBase::OnMMouseRelease


    /*******************************************************************************
    * qToolBase::OnRMouseRelease
    *******************************************************************************/
    enumToolResult qToolBase::OnRMouseRelease(u32                     _u32Modifiers,
                                          const qVector2D<s32>    &_v2dLocal,
                                          const qVector2D<s32>    &_v2dGlobal)
    {
        CHECK_PRE_CONDITION(GetOwnerWin() != nullptr, enumToolResult::Unhandled);
        enumToolResult eResult  = enumToolResult::Unhandled;


        // probaly show a context menu
        eResult = OnContextMenu(_u32Modifiers, _v2dLocal, _v2dGlobal);

        return eResult;
    } // qToolBase::OnRMouseRelease


    /*******************************************************************************
    * qToolBase::ToolOnEnter
    *******************************************************************************/
    enumToolResult qToolBase::ToolOnEnter(u32                    _u32Modifiers,
                                          const qVector2D<s32>   &_v2dLocal,
                                          const qVector2D<s32>   &_v2dGlobal)
    {
        return OnEnter(_u32Modifiers, _v2dLocal, _v2dGlobal);
    } // qToolBase::ToolOnEnter


    /*******************************************************************************
    * qToolBase::ToolOnLeave
    *******************************************************************************/
    enumToolResult qToolBase::ToolOnLeave(u32                    _u32Modifiers)
    {
        return OnLeave(_u32Modifiers);
    } // qToolBase::ToolOnLeave


    /*******************************************************************************
    * qToolBase::ToolOnWheel
    *******************************************************************************/
    enumToolResult qToolBase::ToolOnWheel(u32                    _u32Modifiers,
                                      s32                    _s32Deree,
                                      const qVector2D<s32>   &_v2dLocal,
                                      const qVector2D<s32>   &_v2dGlobal)
    {
        return OnWheel(_u32Modifiers, _s32Deree, _v2dLocal, _v2dGlobal);
    } // qToolBase::ToolOnWheel


    /*******************************************************************************
    * qToolBase::ToolOnDoubleClick
    *******************************************************************************/
    enumToolResult qToolBase::ToolOnDoubleClick(u32                   _u32Modifiers,
                                            u32                   _u32MouseButton,
                                            const qVector2D<s32>  &_v2dLocal,
                                            const qVector2D<s32>  &_v2dGlobal)
    {
        enumToolResult eResult  = enumToolResult::Unhandled;

        switch (_u32MouseButton)
        {
            default:
                eResult = OnDoubleClick(_u32Modifiers, _u32MouseButton, _v2dLocal, _v2dGlobal);
                break;

            case MOUSE_BTN_LEFT:
                eResult = OnLDoubleClick(_u32Modifiers, _v2dLocal, _v2dGlobal);
                break;

            case MOUSE_BTN_MIDDLE:
                eResult = OnMDoubleClick(_u32Modifiers, _v2dLocal, _v2dGlobal);
                break;

            case MOUSE_BTN_RIGHT:
                eResult = OnRDoubleClick(_u32Modifiers, _v2dLocal, _v2dGlobal);
                break;
            } // switch

            return eResult;
    } // qToolBase::ToolOnDoubleClick


    /*******************************************************************************
    * qToolBase::ToolOnMousePress
    *******************************************************************************/
    enumToolResult qToolBase::ToolOnMousePress(u32                   _u32Modifiers,
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
                eResult = OnMousePress(_u32Modifiers, m_u32MouseButton, _v2dLocal, _v2dGlobal);
                break;

            case MOUSE_BTN_LEFT:
                eResult = OnLMousePress(_u32Modifiers, _v2dLocal, _v2dGlobal);
                break;

            case MOUSE_BTN_MIDDLE:
                eResult = OnMMousePress(_u32Modifiers, _v2dLocal, _v2dGlobal);
                break;

            case MOUSE_BTN_RIGHT:
                eResult = OnRMousePress(_u32Modifiers, _v2dLocal, _v2dGlobal);
                break;
        } // switch

        return eResult;
    } // qToolBase::ToolOnMousePress


    /*******************************************************************************
    * qToolBase::ToolOnMouseMove
    *******************************************************************************/
    enumToolResult qToolBase::ToolOnMouseMove(u32                   _u32Modifiers,
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
                eResult = OnMouseMove(_u32Modifiers, _u32MouseButton, _v2dLocal, _v2dGlobal);
                break;

            case MOUSE_BTN_LEFT:
                eResult = OnLMouseMove(_u32Modifiers, _v2dLocal, _v2dGlobal);
                break;

            case MOUSE_BTN_MIDDLE:
                eResult = OnMMouseMove(_u32Modifiers, _v2dLocal, _v2dGlobal);
                break;

            case MOUSE_BTN_RIGHT:
                eResult = OnRMousePress(_u32Modifiers, _v2dLocal, _v2dGlobal);
                break;
        } // switch

        return eResult;
    } // qToolBase::ToolOnMouseMove


    /*******************************************************************************
    * qToolBase::ToolOnMouseRelease
    *******************************************************************************/
    enumToolResult qToolBase::ToolOnMouseRelease(u32                   _u32Modifiers,
                                             u32                   /*_u32MouseButton*/,
                                             const qVector2D<s32>  &_v2dLocal,
                                             const qVector2D<s32>  &_v2dGlobal)
    {
        enumToolResult eResult  = enumToolResult::Unhandled;

        switch (m_u32MouseButton)
        {
            default:
                eResult = OnMouseRelease(_u32Modifiers, m_u32MouseButton, _v2dLocal, _v2dGlobal);
                break;

            case MOUSE_BTN_LEFT:
                eResult = OnLMouseRelease(_u32Modifiers, _v2dLocal, _v2dGlobal);
                break;

            case MOUSE_BTN_MIDDLE:
                eResult = OnMMouseRelease(_u32Modifiers, _v2dLocal, _v2dGlobal);
                break;

            case MOUSE_BTN_RIGHT:
                eResult = OnRMouseRelease(_u32Modifiers, _v2dLocal, _v2dGlobal);
                break;
        } // switch

        m_u32MouseButton = MOUSE_BTN_NONE;

        return eResult;
    } // qToolBase::ToolOnMouseRelease

} // namespace qLib
