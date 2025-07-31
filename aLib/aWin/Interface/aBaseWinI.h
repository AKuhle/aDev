/*******************************************************************************
* \file qWin.h
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
#include "aWin_def.h"
#include "aUtil_def.h"
#include "aUrl.h"
#include "aRect2D.h"

using namespace aLib::aMath;
using namespace aLib::aUtil;


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aWin {


/*******************************************************************************
* class aBaseWinI
*******************************************************************************/
class aBaseWinI
{
    /*******************************************************************************
    * con-/destruction
    *******************************************************************************/
    public:
        virtual ~aBaseWinI() = default;

        virtual bool            createWin() = 0;
        virtual bool            closeWin() = 0;

    public:
        virtual void            setParent(SysWin *_pParent) = 0;
        virtual SysWin*         parent() const = 0;

        virtual void            update() = 0;
        virtual void            repaint() = 0;


        virtual void            setWinTitle(const aString &_sTitle) = 0;


    /*******************************************************************************
    * window state
    *******************************************************************************/
    public:
        // visibility
        virtual void            setVisible(bool _bVisible) = 0;
        virtual void            show() = 0;
        virtual void            hide() = 0;
        virtual bool            isVisible() const = 0;

        virtual void            setMouseTracking(bool _bEnable) = 0;


    /*******************************************************************************
    * window geometry
    *******************************************************************************/
    public:
        virtual void            setMinSize(const aDimension2D<s32> &_dim) = 0;
        virtual void            setMinSize(s32  _s32W,
                                           s32  _s32H) = 0;
        virtual void            setMinW(s32  _s32W) = 0;
        virtual void            setMinH(s32  _s32H) = 0;
        virtual void            setFixedW(s32  _s32W) = 0;
        virtual void            setFixedH(s32  _s32H) = 0;

        virtual aRect2D<s32>    clientRect() const = 0;
        virtual s32             clientW() const = 0;
        virtual s32             clientH() const = 0;


    /*******************************************************************************
    * handler
    *******************************************************************************/
    protected:
        virtual bool            onSysCreateWin() = 0;
        virtual bool            onCreateWin() = 0;
        virtual bool            onCloseWin() = 0;

        virtual void            onDropUrl(const aUrl  &_url) = 0;
        virtual bool            onPaint() = 0;

        virtual bool            onWheel(u32                  _u32Modifiers,
                                        s32                  _s32Degree,
                                        const aPoint2D<s32> &_v2dLocal,
                                        const aPoint2D<s32> &_v2dGlobal) = 0;
}; // class aBaseWinI


} // namespace aWin
} // namespace aLib
