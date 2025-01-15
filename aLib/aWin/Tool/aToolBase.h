/*******************************************************************************
* \file aToolBase.h
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
#include "aMath/Obj2D/aVector2D.h"

#include "aWin/aWin_def.h"

using namespace aLib::aMath;


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aWin {


/*******************************************************************************
* class aToolBase
*******************************************************************************/
class aToolBase
{
    aBaseWin    *m_pOwnerWin            { nullptr };
    u32         m_u32ToolId             { 0 };
    u64         m_u64ToolBaseFunction   { TBF_NONE };

    friend class aToolMgr;

    private:
        u32             m_u32MouseButton        { MOUSE_BTN_NONE };

        aVector2D<s32>  m_v2dMoveStartLocal;
        aVector2D<s32>  m_v2dMoveCurrentLocal;
        aVector2D<s32>  m_v2dMoveStartGlobal;
        aVector2D<s32>  m_v2dMoveCurrentGlobal;

        // bool            m_bDrawXorRect          { false };

    protected:
        aToolBase(aBaseWin  *_pOwnerWin,
                  u32       _u32ToolId,
                  u64       _u64ToolBaseFunction);
    public:
        virtual ~aToolBase();

        aBaseWin*                   ownerWin() const;
        u32                         toolId() const;

        virtual void                setCursor(u32                   _u32Modifiers,
                                              const aVector2D<s32>  &_v2dLocal,
                                              const aVector2D<s32>  &_v2dGlobal);
        // virtual void                paintToolMarker();


    protected:
        aVector2D<s32>              moveDeltaLocal() const;
        aVector2D<s32>              moveDeltaGlobal() const;

    private:
        void                        setCursor();

    /*******************************************************************************
    * handler
    *******************************************************************************/
    protected:
         virtual void               onToolActivated(bool _bActivated);  // true/false => activated/deactivated

        // xor rect entered
        // virtual void                onXorRect(const qRect2D<s32>    &_r2dXor);

        // OnContextMenu
        virtual enumToolResult      onContextMenu(u32                   _u32Modifiers,
                                                  const aVector2D<s32>  &_v2dLocal,
                                                  const aVector2D<s32>  &_v2dGlobal);

        // OnEnter
        virtual enumToolResult      onEnter(u32                   _u32Modifiers,
                                            const aVector2D<s32>  &_v2dLocal,
                                            const aVector2D<s32>  &_v2dGlobal);

        // OnLeave
        virtual enumToolResult      onLeave(u32 _u32Modifiers);

        // OnWheel
        virtual enumToolResult      onWheel(u32                     _u32Modifiers,
                                            s32                     _s32Degree,
                                            const aVector2D<s32>    &_v2dLocal,
                                            const aVector2D<s32>    &_v2dGlobal);

        // OnDoubleClick
        virtual enumToolResult      onDoubleClick(u32                   _u32Modifiers,
                                                  u32                   _u32MouseButton,
                                                  const aVector2D<s32>  &_v2dLocal,
                                                  const aVector2D<s32>  &_v2dGlobal);

        virtual enumToolResult      onLDoubleClick(u32                     _u32Modifiers,
                                                   const aVector2D<s32>    &_v2dLocal,
                                                   const aVector2D<s32>    &_v2dGlobal);

        virtual enumToolResult      onMDoubleClick(u32                     _u32Modifiers,
                                                   const aVector2D<s32>    &_v2dLocal,
                                                   const aVector2D<s32>    &_v2dGlobal);

        virtual enumToolResult      onRDoubleClick(u32                     _u32Modifiers,
                                                   const aVector2D<s32>    &_v2dLocal,
                                                   const aVector2D<s32>    &_v2dGlobal);

        // OnMousePress
        virtual enumToolResult      onMousePress(u32                   _u32Modifiers,
                                                 u32                   _u32MouseButton,
                                                 const aVector2D<s32>  &_v2dLocal,
                                                 const aVector2D<s32>  &_v2dGlobal);

        virtual enumToolResult      onLMousePress(u32                     _u32Modifiers,
                                                  const aVector2D<s32>    &_v2dLocal,
                                                  const aVector2D<s32>    &_v2dGlobal);

        virtual enumToolResult      onMMousePress(u32                     _u32Modifiers,
                                                  const aVector2D<s32>    &_v2dLocal,
                                                  const aVector2D<s32>    &_v2dGlobal);

        virtual enumToolResult      onRMousePress(u32                     _u32Modifiers,
                                                  const aVector2D<s32>    &_v2dLocal,
                                                  const aVector2D<s32>    &_v2dGlobal);

        // OnMouseMove
        virtual enumToolResult      onMouseMove(u32                   _u32Modifiers,
                                                u32                   _u32MouseButton,
                                                const aVector2D<s32>  &_v2dLocal,
                                                const aVector2D<s32>  &_v2dGlobal);

        virtual enumToolResult      onLMouseMove(u32                     _u32Modifiers,
                                                 const aVector2D<s32>    &_v2dLocal,
                                                 const aVector2D<s32>    &_v2dGlobal);

        virtual enumToolResult      onMMouseMove(u32                     _u32Modifiers,
                                                 const aVector2D<s32>    &_v2dLocal,
                                                 const aVector2D<s32>    &_v2dGlobal);

        virtual enumToolResult      onRMouseMove(u32                     _u32Modifiers,
                                                 const aVector2D<s32>    &_v2dLocal,
                                                 const aVector2D<s32>    &_v2dGlobal);

        // OnMouseRelease
        virtual enumToolResult      onMouseRelease(u32                   _u32Modifiers,
                                                   u32                   _u32MouseButton,
                                                   const aVector2D<s32>  &_v2dLocal,
                                                   const aVector2D<s32>  &_v2dGlobal);

        virtual enumToolResult      onLMouseRelease(u32                     _u32Modifiers,
                                                    const aVector2D<s32>    &_v2dLocal,
                                                    const aVector2D<s32>    &_v2dGlobal);

        virtual enumToolResult      onMMouseRelease(u32                     _u32Modifiers,
                                                    const aVector2D<s32>    &_v2dLocal,
                                                    const aVector2D<s32>    &_v2dGlobal);

        virtual enumToolResult      onRMouseRelease(u32                     _u32Modifiers,
                                                    const aVector2D<s32>    &_v2dLocal,
                                                    const aVector2D<s32>    &_v2dGlobal);

    private:
        enumToolResult              doToolEnter(u32                   _u32Modifiers,
                                                const aVector2D<s32>  &_v2dLocal,
                                                const aVector2D<s32>  &_v2dGlobal);

        enumToolResult              doToolLeave(u32 _u32Modifiers);

        enumToolResult              doToolWheel(u32                     _u32Modifiers,
                                                s32                     _s32Degree,
                                                const aVector2D<s32>    &_v2dLocal,
                                                const aVector2D<s32>    &_v2dGlobal);

        enumToolResult              doToolDoubleClick(u32                   _u32Modifiers,
                                                      u32                   _u32MouseButton,
                                                      const aVector2D<s32>  &_v2dLocal,
                                                      const aVector2D<s32>  &_v2dGlobal);

        enumToolResult              doToolMousePress(u32                   _u32Modifiers,
                                                     u32                   _u32MouseButton,
                                                     const aVector2D<s32>  &_v2dLocal,
                                                     const aVector2D<s32>  &_v2dGlobal);

        enumToolResult              doToolMouseMove(u32                   _u32Modifiers,
                                                    u32                   _u32MouseButton,
                                                    const aVector2D<s32>  &_v2dLocal,
                                                    const aVector2D<s32>  &_v2dGlobal);

        enumToolResult              doToolMouseRelease(u32                   _u32Modifiers,
                                                       u32                   _u32MouseButton,
                                                       const aVector2D<s32>  &_v2dLocal,
                                                       const aVector2D<s32>  &_v2dGlobal);

}; // class aToolBase


} // namespace aWin
} // namespace aLib
