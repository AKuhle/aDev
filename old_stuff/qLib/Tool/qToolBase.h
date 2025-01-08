/*******************************************************************************
* \file qToolBase.h
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
#pragma once



/*******************************************************************************
* includes
*******************************************************************************/
#include "Tool/toolDefs.h"
#include "Win/winDefs.h"

#include "Math/qVector2D.h"

using namespace qLib::Win;
using namespace qLib::Math;


namespace qLib {
namespace Tool {


/*******************************************************************************
* class qToolBase
*******************************************************************************/
class qToolBase
{
    qWin        *m_pOwnerWin            { nullptr };
    u32         m_u32ToolId             { 0 };
    u64         m_u64ToolBaseFunction   { TBF_NONE };

    friend class qToolMgr;

    private:
        u32             m_u32MouseButton        { MOUSE_BTN_NONE };

        qVector2D<s32>  m_v2dMoveStartLocal;
        qVector2D<s32>  m_v2dMoveCurrentLocal;
        qVector2D<s32>  m_v2dMoveStartGlobal;
        qVector2D<s32>  m_v2dMoveCurrentGlobal;

        bool            m_bDrawXorRect          { false };

    protected:
        qToolBase(qWin  *_pOwnerWin,
                  u32   _u32ToolId,
                  u64   _u64ToolBaseFunction);
    public:
        virtual ~qToolBase();

        qWin*                       ownerWin() const;
        u32                         toolId() const;

        virtual void                setCursor();
        virtual void                paintToolMarker();


    protected:
        qVector2D<s32>              moveDeltaLocal() const;
        qVector2D<s32>              moveDeltaGlobal() const;


    /*******************************************************************************
    * handler
    *******************************************************************************/
    public:
        virtual void                onToolActivated(bool _bActivated);  // true/false => activated/deactivated

    protected:
        // xor rect entered
        virtual void                onXorRect(const qRect2D<s32>    &_r2dXor);

        // OnContextMenu
        virtual enumToolResult      onContextMenu(u32                   _u32Modifiers,
                                                  const qVector2D<s32>  &_v2dLocal,
                                                  const qVector2D<s32>  &_v2dGlobal);

        // OnEnter
        virtual enumToolResult      onEnter(u32                   _u32Modifiers,
                                            const qVector2D<s32>  &_v2dLocal,
                                            const qVector2D<s32>  &_v2dGlobal);

        // OnLeave
        virtual enumToolResult      onLeave(u32 _u32Modifiers);

        // OnWheel
        virtual enumToolResult      onWheel(u32                     _u32Modifiers,
                                            s32                     _s32Degree,
                                            const qVector2D<s32>    &_v2dLocal,
                                            const qVector2D<s32>    &_v2dGlobal);

        // OnDoubleClick
        virtual enumToolResult      onDoubleClick(u32                   _u32Modifiers,
                                                  u32                   _u32MouseButton,
                                                  const qVector2D<s32>  &_v2dLocal,
                                                  const qVector2D<s32>  &_v2dGlobal);

        virtual enumToolResult      onLDoubleClick(u32                     _u32Modifiers,
                                                   const qVector2D<s32>    &_v2dLocal,
                                                   const qVector2D<s32>    &_v2dGlobal);

        virtual enumToolResult      onMDoubleClick(u32                     _u32Modifiers,
                                                   const qVector2D<s32>    &_v2dLocal,
                                                   const qVector2D<s32>    &_v2dGlobal);

        virtual enumToolResult      onRDoubleClick(u32                     _u32Modifiers,
                                                   const qVector2D<s32>    &_v2dLocal,
                                                   const qVector2D<s32>    &_v2dGlobal);

        // OnMousePress
        virtual enumToolResult      onMousePress(u32                   _u32Modifiers,
                                                 u32                   _u32MouseButton,
                                                 const qVector2D<s32>  &_v2dLocal,
                                                 const qVector2D<s32>  &_v2dGlobal);

        virtual enumToolResult      onLMousePress(u32                     _u32Modifiers,
                                                  const qVector2D<s32>    &_v2dLocal,
                                                  const qVector2D<s32>    &_v2dGlobal);

        virtual enumToolResult      onMMousePress(u32                     _u32Modifiers,
                                                  const qVector2D<s32>    &_v2dLocal,
                                                  const qVector2D<s32>    &_v2dGlobal);

        virtual enumToolResult      onRMousePress(u32                     _u32Modifiers,
                                                  const qVector2D<s32>    &_v2dLocal,
                                                  const qVector2D<s32>    &_v2dGlobal);

        // OnMouseMove
        virtual enumToolResult      onMouseMove(u32                   _u32Modifiers,
                                                u32                   _u32MouseButton,
                                                const qVector2D<s32>  &_v2dLocal,
                                                const qVector2D<s32>  &_v2dGlobal);

        virtual enumToolResult      onLMouseMove(u32                     _u32Modifiers,
                                                 const qVector2D<s32>    &_v2dLocal,
                                                 const qVector2D<s32>    &_v2dGlobal);

        virtual enumToolResult      onMMouseMove(u32                     _u32Modifiers,
                                                 const qVector2D<s32>    &_v2dLocal,
                                                 const qVector2D<s32>    &_v2dGlobal);

        virtual enumToolResult      onRMouseMove(u32                     _u32Modifiers,
                                                 const qVector2D<s32>    &_v2dLocal,
                                                 const qVector2D<s32>    &_v2dGlobal);

        // OnMouseRelease
        virtual enumToolResult      onMouseRelease(u32                   _u32Modifiers,
                                                   u32                   _u32MouseButton,
                                                   const qVector2D<s32>  &_v2dLocal,
                                                   const qVector2D<s32>  &_v2dGlobal);

        virtual enumToolResult      onLMouseRelease(u32                     _u32Modifiers,
                                                    const qVector2D<s32>    &_v2dLocal,
                                                    const qVector2D<s32>    &_v2dGlobal);

        virtual enumToolResult      onMMouseRelease(u32                     _u32Modifiers,
                                                    const qVector2D<s32>    &_v2dLocal,
                                                    const qVector2D<s32>    &_v2dGlobal);

        virtual enumToolResult      onRMouseRelease(u32                     _u32Modifiers,
                                                    const qVector2D<s32>    &_v2dLocal,
                                                    const qVector2D<s32>    &_v2dGlobal);

    private:
        enumToolResult              doEnter(u32                   _u32Modifiers,
                                            const qVector2D<s32>  &_v2dLocal,
                                            const qVector2D<s32>  &_v2dGlobal);

        enumToolResult              doLeave(u32 _u32Modifiers);

        enumToolResult              doWheel(u32                     _u32Modifiers,
                                            s32                     _s32Degree,
                                            const qVector2D<s32>    &_v2dLocal,
                                            const qVector2D<s32>    &_v2dGlobal);

        enumToolResult              doDoubleClick(u32                   _u32Modifiers,
                                                  u32                   _u32MouseButton,
                                                  const qVector2D<s32>  &_v2dLocal,
                                                  const qVector2D<s32>  &_v2dGlobal);

        enumToolResult              doMousePress(u32                   _u32Modifiers,
                                                 u32                   _u32MouseButton,
                                                 const qVector2D<s32>  &_v2dLocal,
                                                 const qVector2D<s32>  &_v2dGlobal);

        enumToolResult              doMouseMove(u32                   _u32Modifiers,
                                                u32                   _u32MouseButton,
                                                const qVector2D<s32>  &_v2dLocal,
                                                const qVector2D<s32>  &_v2dGlobal);

        enumToolResult              doMouseRelease(u32                   _u32Modifiers,
                                                   u32                   _u32MouseButton,
                                                   const qVector2D<s32>  &_v2dLocal,
                                                   const qVector2D<s32>  &_v2dGlobal);

}; // class qToolBase


} // namespace Tool
} // namespace qLib
