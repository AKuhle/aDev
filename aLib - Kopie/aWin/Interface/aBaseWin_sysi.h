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
* class aBaseWin_sysi
*******************************************************************************/
class aBaseWin_sysi
{
    public:
        virtual void            setParent(SysWinClass *_pParent) = 0;
        virtual SysWinClass*    parent() const = 0;

        virtual void            update() = 0;
        virtual void            repaint() = 0;


    /*******************************************************************************
    * window state
    *******************************************************************************/
    public:
        // visibility
        virtual void            setVisible(bool _bVisible) = 0;
        virtual bool            isVisible() const = 0;

        virtual void            setMouseTracking(bool _bEnable) = 0;


    /*******************************************************************************
    * window geometry
    *******************************************************************************/
    public:
        virtual void            setMinSize(s32  _s32W,
                                           s32  _s32H) = 0;

        virtual aRect2D<s32>    clientRect() const = 0;


    /*******************************************************************************
    * system handler
    *******************************************************************************/
    protected:
        virtual void            onSysDropUrl(const aUrl  &_url) = 0;
        virtual bool            onSysPaint() = 0;

}; // class aBaseWin_sysi


} // namespace aWin
} // namespace aLib
