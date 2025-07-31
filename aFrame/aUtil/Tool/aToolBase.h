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
#include "aWin_def.h"
#include "aMath_def.h"
#include "aUtil_def.h"

using namespace aFrame::aWin;
using namespace aFrame::aMath;


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aFrame {
namespace aUtil {


/*******************************************************************************
* forward
*******************************************************************************/
class qWin;


/*******************************************************************************
* class aToolBase
*******************************************************************************/
class aToolBase
{
    friend class aToolMgr;

    private:
        aBaseWin        *m_pOwnerWin                { nullptr };
        u32             m_u32ToolId                 { 0 };
        u64             m_u64ToolBaseFunction       { TBF_NONE };

    protected:
        aToolBase(aBaseWin  *_pOwnerWin,
                  u32       _u32ToolId,
                  u64       _u64ToolBaseFunction);

    public:
        virtual ~aToolBase();

        aBaseWin*                   ownerWin() const;
        u32                         toolId() const;
        u64                         toolBaseFunction() const;


    /*******************************************************************************
    * handler
    *******************************************************************************/
    protected:
        virtual void                onToolActivated(bool _bActivated);

        virtual enumToolResult      onWheel(u32                     _u32Modifiers,
                                            s32                     _s32Degree,
                                            const aPoint2D<s32>    &_v2dLocal,
                                            const aPoint2D<s32>    &_v2dGlobal);


    /*******************************************************************************
    * trigger
    *******************************************************************************/
    private:
        enumToolResult              toolOnWheel(u32                     _u32Modifiers,
                                                s32                     _s32Degree,
                                                const aPoint2D<s32>    &_v2dLocal,
                                                const aPoint2D<s32>    &_v2dGlobal);

    }; // class aToolBase


} // namespace aUtil
} // namespace aFrame



//         private:
//             u32             m_u32MouseButton        { MOUSE_BTN_NONE };

//             aPoint2D<s32>  m_v2dMoveStartLocal;
//             aPoint2D<s32>  m_v2dMoveCurrentLocal;
//             aPoint2D<s32>  m_v2dMoveStartGlobal;
//             aPoint2D<s32>  m_v2dMoveCurrentGlobal;

//             bool            m_bDrawXorRect          { false };

//         protected:
//             aPoint2D<s32>              GetMoveDeltaLocal() const;
//             aPoint2D<s32>              GetMoveDeltaGlobal() const;


//         /*******************************************************************************
//         * handler
//         *******************************************************************************/
//         public:
//             virtual void                OnSetCursor();
//             virtual void                OnPaintToolMarker();

//         protected:
//             // xor rect entered
//             virtual void                OnXorRect(const qRect2D<s32>    &_r2dXor);

//             // OnContextMenu
//             virtual enumToolResult      OnContextMenu(u32                   _u32Modifiers,
//                                                       const aPoint2D<s32>  &_v2dLocal,
//                                                       const aPoint2D<s32>  &_v2dGlobal);

//             // OnEnter
//             virtual enumToolResult      OnEnter(u32                   _u32Modifiers,
//                                                 const aPoint2D<s32>  &_v2dLocal,
//                                                 const aPoint2D<s32>  &_v2dGlobal);

//             // OnLeave
//             virtual enumToolResult      OnLeave(u32 _u32Modifiers);

//             // OnDoubleClick
//             virtual enumToolResult      OnDoubleClick(u32                   _u32Modifiers,
//                                                       u32                   _u32MouseButton,
//                                                       const aPoint2D<s32>  &_v2dLocal,
//                                                       const aPoint2D<s32>  &_v2dGlobal);

//             virtual enumToolResult      OnLDoubleClick(u32                     _u32Modifiers,
//                                                        const aPoint2D<s32>    &_v2dLocal,
//                                                        const aPoint2D<s32>    &_v2dGlobal);

//             virtual enumToolResult      OnMDoubleClick(u32                     _u32Modifiers,
//                                                        const aPoint2D<s32>    &_v2dLocal,
//                                                        const aPoint2D<s32>    &_v2dGlobal);

//             virtual enumToolResult      OnRDoubleClick(u32                     _u32Modifiers,
//                                                        const aPoint2D<s32>    &_v2dLocal,
//                                                        const aPoint2D<s32>    &_v2dGlobal);

//             // OnMousePress
//             virtual enumToolResult      OnMousePress(u32                   _u32Modifiers,
//                                                      u32                   _u32MouseButton,
//                                                      const aPoint2D<s32>  &_v2dLocal,
//                                                      const aPoint2D<s32>  &_v2dGlobal);

//             virtual enumToolResult      OnLMousePress(u32                     _u32Modifiers,
//                                                       const aPoint2D<s32>    &_v2dLocal,
//                                                       const aPoint2D<s32>    &_v2dGlobal);

//             virtual enumToolResult      OnMMousePress(u32                     _u32Modifiers,
//                                                       const aPoint2D<s32>    &_v2dLocal,
//                                                       const aPoint2D<s32>    &_v2dGlobal);

//             virtual enumToolResult      OnRMousePress(u32                     _u32Modifiers,
//                                                       const aPoint2D<s32>    &_v2dLocal,
//                                                       const aPoint2D<s32>    &_v2dGlobal);

//             // OnMouseMove
//             virtual enumToolResult      OnMouseMove(u32                   _u32Modifiers,
//                                                     u32                   _u32MouseButton,
//                                                     const aPoint2D<s32>  &_v2dLocal,
//                                                     const aPoint2D<s32>  &_v2dGlobal);

//             virtual enumToolResult      OnLMouseMove(u32                     _u32Modifiers,
//                                                      const aPoint2D<s32>    &_v2dLocal,
//                                                      const aPoint2D<s32>    &_v2dGlobal);

//             virtual enumToolResult      OnMMouseMove(u32                     _u32Modifiers,
//                                                      const aPoint2D<s32>    &_v2dLocal,
//                                                      const aPoint2D<s32>    &_v2dGlobal);

//             virtual enumToolResult      OnRMouseMove(u32                     _u32Modifiers,
//                                                      const aPoint2D<s32>    &_v2dLocal,
//                                                      const aPoint2D<s32>    &_v2dGlobal);

//             // OnMouseRelease
//             virtual enumToolResult      OnMouseRelease(u32                   _u32Modifiers,
//                                                        u32                   _u32MouseButton,
//                                                        const aPoint2D<s32>  &_v2dLocal,
//                                                        const aPoint2D<s32>  &_v2dGlobal);

//             virtual enumToolResult      OnLMouseRelease(u32                     _u32Modifiers,
//                                                         const aPoint2D<s32>    &_v2dLocal,
//                                                         const aPoint2D<s32>    &_v2dGlobal);

//             virtual enumToolResult      OnMMouseRelease(u32                     _u32Modifiers,
//                                                         const aPoint2D<s32>    &_v2dLocal,
//                                                         const aPoint2D<s32>    &_v2dGlobal);

//             virtual enumToolResult      OnRMouseRelease(u32                     _u32Modifiers,
//                                                         const aPoint2D<s32>    &_v2dLocal,
//                                                         const aPoint2D<s32>    &_v2dGlobal);

//         private:
//             enumToolResult              ToolOnEnter(u32                   _u32Modifiers,
//                                                     const aPoint2D<s32>  &_v2dLocal,
//                                                     const aPoint2D<s32>  &_v2dGlobal);

//             enumToolResult              ToolOnLeave(u32 _u32Modifiers);

//             enumToolResult              ToolOnDoubleClick(u32                   _u32Modifiers,
//                                                           u32                   _u32MouseButton,
//                                                           const aPoint2D<s32>  &_v2dLocal,
//                                                           const aPoint2D<s32>  &_v2dGlobal);

//             enumToolResult              ToolOnMousePress(u32                   _u32Modifiers,
//                                                          u32                   _u32MouseButton,
//                                                          const aPoint2D<s32>  &_v2dLocal,
//                                                          const aPoint2D<s32>  &_v2dGlobal);

//             enumToolResult              ToolOnMouseMove(u32                   _u32Modifiers,
//                                                         u32                   _u32MouseButton,
//                                                         const aPoint2D<s32>  &_v2dLocal,
//                                                         const aPoint2D<s32>  &_v2dGlobal);

//             enumToolResult              ToolOnMouseRelease(u32                   _u32Modifiers,
//                                                            u32                   _u32MouseButton,
//                                                            const aPoint2D<s32>  &_v2dLocal,
//                                                            const aPoint2D<s32>  &_v2dGlobal);
