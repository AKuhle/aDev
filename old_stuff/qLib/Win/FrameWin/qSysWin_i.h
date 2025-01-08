/*******************************************************************************
* \file qSysWin.h
* \author Andreas Kuhlewind
*
* \brief
*
*  Detailed description starts here.
*******************************************************************************/
#pragma once


/*******************************************************************************
* includes
*******************************************************************************/
#include "qLibDefs.h"
#include "Graphic/graphicDefs.h"
#include "Win/winDefs.h"
#include "Math/mathDefs.h"

using namespace qLib::Graphic;
using namespace qLib::Math;


/*******************************************************************************
* namespace
*******************************************************************************/
namespace qLib {
namespace Win {


/*******************************************************************************
* class qSysWinI
*******************************************************************************/
class qSysWinI
{
    /*******************************************************************************
    * public members
    *******************************************************************************/
    public:
        virtual qWin*           parent() const = 0;
        virtual void            setParent(qWin *_pParent) = 0;

        virtual qVector2D<s32>  globalCursorPos() const = 0;
        virtual qVector2D<s32>  localCursorPos() const = 0;
        virtual u32             modifiers() const = 0;
        virtual u32             mouseButton() const = 0;
        virtual void            setMouseTracking(bool _bEnable) = 0;

        virtual void            setCursor(const qCursor &_cursor) = 0;


    /*******************************************************************************
    * win state
    *******************************************************************************/
    public:
        virtual void            show() = 0;
        virtual void            hide() = 0;
        virtual void            setVisible(bool _bVisible) = 0;
        virtual bool            isVisible() const = 0;

        virtual void            showMaximized() = 0;
        virtual void            showMinimized() = 0;
        virtual void            showNormal() = 0;
        virtual bool            isMaximized() const = 0;
        virtual bool            isMinimized() const = 0;


    /*******************************************************************************
    * geometry
    *******************************************************************************/
    public:
        virtual qRect2D<s32>    geometry() const = 0;
        virtual void            setGeometry(const qRect2D<s32> &_r2d) = 0;
        virtual void            setGeometry(s32 _x,
                                            s32 _y,
                                            s32 _w,
                                            s32 _h) = 0;

        virtual s32             w() const = 0;
        virtual s32             h() const = 0;


    /*******************************************************************************
    * events
    *******************************************************************************/
    protected:
        virtual void            onResizeEvent(const qDimension2D<s32> &_d2dOld,
                                              const qDimension2D<s32> &_d2dNew) = 0;

        virtual void            onPaintEvent() = 0;

        virtual bool            onEnterEvent(u32                     _u32Modifiers,
                                             const qVector2D<s32>    &_v2dLocal,
                                             const qVector2D<s32>    &_v2dGlobal) = 0;

        virtual bool            onLeaveEvent(u32 _u32Modifiers) = 0;

        virtual bool            onWheelEvent(u32                    _u32Modifiers,
                                             s32                    _s32Degree,
                                             const qVector2D<s32>   &_v2dLocal,
                                             const qVector2D<s32>   &_v2dGlobal) = 0;

        virtual bool            onDoubleClickEvent(u32                  _u32Modifiers,
                                                   u32                  _u32MouseButton,
                                                   const qVector2D<s32> &_v2dLocal,
                                                   const qVector2D<s32> &_v2dGlobal) = 0;

        virtual bool            onMousePressEvent(u32                   _u32Modifiers,
                                                  u32                   _u32MouseButton,
                                                  const qVector2D<s32>  &_v2dLocal,
                                                  const qVector2D<s32>  &_v2dGlobal) = 0;

        virtual bool            onMouseMoveEvent(u32                    _u32Modifiers,
                                                 u32                    _u32MouseButton,
                                                 const qVector2D<s32>   &_v2dLocal,
                                                 const qVector2D<s32>   &_v2dGlobal) = 0;

        virtual bool            onMouseReleaseEvent(u32                     _u32Modifiers,
                                                    u32                     _u32MouseButton,
                                                    const qVector2D<s32>    &_v2dLocal,
                                                    const qVector2D<s32>    &_v2dGlobal) = 0;


}; // class qSysWinI


} // namespace Win
} // namespace qLib
