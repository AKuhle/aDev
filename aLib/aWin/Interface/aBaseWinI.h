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

        virtual bool            create() = 0;

    public:
        virtual void            setParent(SysWin *_pParent) = 0;
        virtual SysWin*         parent() const = 0;

        virtual void            update() = 0;
        virtual void            repaint() = 0;


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

        virtual aRect2D<s32>    clientRect() const = 0;
        virtual s32             clientW() const = 0;
        virtual s32             clientH() const = 0;


    /*******************************************************************************
    * handler
    *******************************************************************************/
    protected:
        virtual bool            onSysCreate() = 0;
        virtual bool            onCreate() = 0;

        virtual void            onDropUrl(const aUrl  &_url) = 0;
        virtual bool            onPaint() = 0;

}; // class aBaseWinI


} // namespace aWin
} // namespace aLib
