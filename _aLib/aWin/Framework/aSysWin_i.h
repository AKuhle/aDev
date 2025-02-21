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
#include "aLib_def.h"
#include "aUtil/aUtil_def.h"
#include "aMath/aMath_def.h"
#include "aGraphic/aGraphic_def.h"
#include "aWin/aWin_def.h"

using namespace aLib::aUtil;
using namespace aLib::aGraphic;
using namespace aLib::aMath;


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aWin {


/*******************************************************************************
* class aSysWinI
*******************************************************************************/
class aSysWinI
{
    protected:
        virtual aSysWin_t*          _sysWin() = 0;

        virtual aSysWin*            _parent() const = 0;
        virtual void                _setParent(aSysWin *_pParent) = 0;

        virtual void                _setCursor(const aCursor &_cursor) = 0;

        virtual void                _setFont(const aFont &_font) = 0;
        virtual aFont               _font() const = 0;

        virtual void                _setFocusPolicy(enumFocusPolicy _policy) = 0;
        virtual void                _setFocus() = 0;
        virtual bool                _hasFocus() const = 0;

        virtual void                _setMouseTracking(bool _bEnable) = 0;

        // Raises this widget to the top of the parent widget's stack.
        virtual void                _raise() = 0;

        // Lowers the widget to the bottom of the parent widget's stack.
        virtual void                _lower() = 0;

        virtual void                _enableDrop(bool _bEnable) = 0;

        virtual void                _repaint() = 0;
        virtual void                _update() = 0;


    /*******************************************************************************
    * win state
    *******************************************************************************/
    protected:
        virtual void                _close() = 0;

        virtual void                _show() = 0;
        virtual void                _hide() = 0;
        virtual bool                _isVisible() const = 0;

        virtual void                _setEnabled(bool _bEnabled) = 0;
        virtual bool                _isEnabled() const = 0;

        virtual void                _showMaximized() = 0;
        virtual void                _showMinimized() = 0;
        virtual void                _showNormal() = 0;
        virtual bool                _isMaximized() const = 0;
        virtual bool                _isMinimized() const = 0;

        virtual u32                 _modifiers() const = 0;
        virtual u32                 _mouseButton() const = 0;
        virtual aVector2D<s32>      _localCursorPos() const = 0;
        virtual aVector2D<s32>      _globalCursorPos() const = 0;


    /*******************************************************************************
    * geometry
    *******************************************************************************/
    protected:
        virtual void                _setGeometry(s32    _x,
                                                 s32    _y,
                                                 s32    _w,
                                                 s32    _h) = 0;

        virtual aRect2D<s32>        _geometry() const = 0;

        virtual s32                 _w() const = 0;
        virtual s32                 _h() const = 0;


    /*******************************************************************************
    * events
    *******************************************************************************/
    protected:
        virtual void                onFocusInEvent(enumFocusReason  _eReason) = 0;
        virtual void                onFocusOutEvent(enumFocusReason  _eReason) = 0;

        virtual void                onResizeEvent(const aDimension2D<s32> &_d2dOld,
                                                  const aDimension2D<s32> &_d2dNew) = 0;

        virtual void                onPaintEvent() = 0;

        virtual bool                onEnterEvent(u32                     _u32Modifiers,
                                                 const aVector2D<s32>    &_v2dLocal,
                                                 const aVector2D<s32>    &_v2dGlobal) = 0;

        virtual bool                onLeaveEvent(u32 _u32Modifiers) = 0;

        virtual bool                onWheelEvent(u32                    _u32Modifiers,
                                                 s32                    _s32Degree,
                                                 const aVector2D<s32>   &_v2dLocal,
                                                 const aVector2D<s32>   &_v2dGlobal) = 0;

        virtual bool                onDoubleClickEvent(u32                  _u32Modifiers,
                                                       u32                  _u32MouseButton,
                                                       const aVector2D<s32> &_v2dLocal,
                                                       const aVector2D<s32> &_v2dGlobal) = 0;

    virtual bool                    onMousePressEvent(u32                   _u32Modifiers,
                                                      u32                   _u32MouseButton,
                                                      const aVector2D<s32>  &_v2dLocal,
                                                      const aVector2D<s32>  &_v2dGlobal) = 0;

    virtual bool                    onMouseMoveEvent(u32                    _u32Modifiers,
                                                     u32                    _u32MouseButton,
                                                     const aVector2D<s32>   &_v2dLocal,
                                                     const aVector2D<s32>   &_v2dGlobal) = 0;

    virtual bool                    onMouseReleaseEvent(u32                     _u32Modifiers,
                                                        u32                     _u32MouseButton,
                                                        const aVector2D<s32>    &_v2dLocal,
                                                        const aVector2D<s32>    &_v2dGlobal) = 0;

    virtual void                    onDropUrlEvent(const aUrl &_url) = 0;
}; // class aSysWinI


} // namespace aWin
} // namespace aLib
