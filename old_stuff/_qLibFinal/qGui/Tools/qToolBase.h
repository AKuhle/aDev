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
#include "qGuiDefs.h"
#include "qVector2D.h"
#include "qRect2D.h"


namespace qLib
{
    /*******************************************************************************
    * forward
    *******************************************************************************/
    class qWin;


    /*******************************************************************************
    * class qToolBase
    *******************************************************************************/
    class qToolBase
    {
        DeclarePtrProperty(qWin, p, OwnerWin)
        DeclareTypeProperty(u32, u32, ToolId, 0)
        DeclareTypeProperty(u64, u64, ToolBaseFunction, TBF_NONE)

        friend class qToolMgr;

        private:
            u32             m_u32MouseButton        { MOUSE_BTN_NONE };

            qVector2D<s32>  m_v2dMoveStartLocal;
            qVector2D<s32>  m_v2dMoveCurrentLocal;
            qVector2D<s32>  m_v2dMoveStartGlobal;
            qVector2D<s32>  m_v2dMoveCurrentGlobal;

            bool            m_bDrawXorRect          { false };

        public:
            virtual ~qToolBase();

        protected:
            qToolBase(qWin  *_pOwnerWin,
                      u32   _u32ToolId,
                      u64   _u64ToolBaseFunction);

            qVector2D<s32>              GetMoveDeltaLocal() const;
            qVector2D<s32>              GetMoveDeltaGlobal() const;


        /*******************************************************************************
        * handler
        *******************************************************************************/
        public:
            virtual void                OnToolActivated(bool _bActivated);  // true/false => activated/deactivated
            virtual void                OnSetCursor();
            virtual void                OnPaintToolMarker();

        protected:
            // xor rect entered
            virtual void                OnXorRect(const qRect2D<s32>    &_r2dXor);

            // OnContextMenu
            virtual enumToolResult      OnContextMenu(u32                   _u32Modifiers,
                                                      const qVector2D<s32>  &_v2dLocal,
                                                      const qVector2D<s32>  &_v2dGlobal);

            // OnEnter
            virtual enumToolResult      OnEnter(u32                   _u32Modifiers,
                                                const qVector2D<s32>  &_v2dLocal,
                                                const qVector2D<s32>  &_v2dGlobal);

            // OnLeave
            virtual enumToolResult      OnLeave(u32 _u32Modifiers);

            // OnWheel
            virtual enumToolResult      OnWheel(u32                     _u32Modifiers,
                                                s32                     _s32Degree,
                                                const qVector2D<s32>    &_v2dLocal,
                                                const qVector2D<s32>    &_v2dGlobal);

            // OnDoubleClick
            virtual enumToolResult      OnDoubleClick(u32                   _u32Modifiers,
                                                      u32                   _u32MouseButton,
                                                      const qVector2D<s32>  &_v2dLocal,
                                                      const qVector2D<s32>  &_v2dGlobal);

            virtual enumToolResult      OnLDoubleClick(u32                     _u32Modifiers,
                                                       const qVector2D<s32>    &_v2dLocal,
                                                       const qVector2D<s32>    &_v2dGlobal);

            virtual enumToolResult      OnMDoubleClick(u32                     _u32Modifiers,
                                                       const qVector2D<s32>    &_v2dLocal,
                                                       const qVector2D<s32>    &_v2dGlobal);

            virtual enumToolResult      OnRDoubleClick(u32                     _u32Modifiers,
                                                       const qVector2D<s32>    &_v2dLocal,
                                                       const qVector2D<s32>    &_v2dGlobal);

            // OnMousePress
            virtual enumToolResult      OnMousePress(u32                   _u32Modifiers,
                                                     u32                   _u32MouseButton,
                                                     const qVector2D<s32>  &_v2dLocal,
                                                     const qVector2D<s32>  &_v2dGlobal);

            virtual enumToolResult      OnLMousePress(u32                     _u32Modifiers,
                                                      const qVector2D<s32>    &_v2dLocal,
                                                      const qVector2D<s32>    &_v2dGlobal);

            virtual enumToolResult      OnMMousePress(u32                     _u32Modifiers,
                                                      const qVector2D<s32>    &_v2dLocal,
                                                      const qVector2D<s32>    &_v2dGlobal);

            virtual enumToolResult      OnRMousePress(u32                     _u32Modifiers,
                                                      const qVector2D<s32>    &_v2dLocal,
                                                      const qVector2D<s32>    &_v2dGlobal);

            // OnMouseMove
            virtual enumToolResult      OnMouseMove(u32                   _u32Modifiers,
                                                    u32                   _u32MouseButton,
                                                    const qVector2D<s32>  &_v2dLocal,
                                                    const qVector2D<s32>  &_v2dGlobal);

            virtual enumToolResult      OnLMouseMove(u32                     _u32Modifiers,
                                                     const qVector2D<s32>    &_v2dLocal,
                                                     const qVector2D<s32>    &_v2dGlobal);

            virtual enumToolResult      OnMMouseMove(u32                     _u32Modifiers,
                                                     const qVector2D<s32>    &_v2dLocal,
                                                     const qVector2D<s32>    &_v2dGlobal);

            virtual enumToolResult      OnRMouseMove(u32                     _u32Modifiers,
                                                     const qVector2D<s32>    &_v2dLocal,
                                                     const qVector2D<s32>    &_v2dGlobal);

            // OnMouseRelease
            virtual enumToolResult      OnMouseRelease(u32                   _u32Modifiers,
                                                       u32                   _u32MouseButton,
                                                       const qVector2D<s32>  &_v2dLocal,
                                                       const qVector2D<s32>  &_v2dGlobal);

            virtual enumToolResult      OnLMouseRelease(u32                     _u32Modifiers,
                                                        const qVector2D<s32>    &_v2dLocal,
                                                        const qVector2D<s32>    &_v2dGlobal);

            virtual enumToolResult      OnMMouseRelease(u32                     _u32Modifiers,
                                                        const qVector2D<s32>    &_v2dLocal,
                                                        const qVector2D<s32>    &_v2dGlobal);

            virtual enumToolResult      OnRMouseRelease(u32                     _u32Modifiers,
                                                        const qVector2D<s32>    &_v2dLocal,
                                                        const qVector2D<s32>    &_v2dGlobal);

        private:
            enumToolResult              ToolOnEnter(u32                   _u32Modifiers,
                                                    const qVector2D<s32>  &_v2dLocal,
                                                    const qVector2D<s32>  &_v2dGlobal);

            enumToolResult              ToolOnLeave(u32 _u32Modifiers);

            enumToolResult              ToolOnWheel(u32                     _u32Modifiers,
                                                    s32                     _s32Degree,
                                                    const qVector2D<s32>    &_v2dLocal,
                                                    const qVector2D<s32>    &_v2dGlobal);

            enumToolResult              ToolOnDoubleClick(u32                   _u32Modifiers,
                                                          u32                   _u32MouseButton,
                                                          const qVector2D<s32>  &_v2dLocal,
                                                          const qVector2D<s32>  &_v2dGlobal);

            enumToolResult              ToolOnMousePress(u32                   _u32Modifiers,
                                                         u32                   _u32MouseButton,
                                                         const qVector2D<s32>  &_v2dLocal,
                                                         const qVector2D<s32>  &_v2dGlobal);

            enumToolResult              ToolOnMouseMove(u32                   _u32Modifiers,
                                                        u32                   _u32MouseButton,
                                                        const qVector2D<s32>  &_v2dLocal,
                                                        const qVector2D<s32>  &_v2dGlobal);

            enumToolResult              ToolOnMouseRelease(u32                   _u32Modifiers,
                                                           u32                   _u32MouseButton,
                                                           const qVector2D<s32>  &_v2dLocal,
                                                           const qVector2D<s32>  &_v2dGlobal);

    }; // class qToolBase

} // namespace qLib
