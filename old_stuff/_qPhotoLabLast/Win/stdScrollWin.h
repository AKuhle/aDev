/*******************************************************************************
* \file StdScrollWin.h
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
#pragma once

#include "qLib.h"

using namespace qLib;


/*******************************************************************************
* forwards
*******************************************************************************/
class ViewBase;


/*******************************************************************************
* class StdScrollWin
*******************************************************************************/
class StdScrollWin : public qScrollWin
{
    public:
        StdScrollWin(SysWin_t  *_pParent = nullptr);
        ~StdScrollWin();

        ViewBase*           CentralViewBase() const;

        void                UpdateScrollbars();

    /*******************************************************************************
    * qScrollWin interface
    *******************************************************************************/
    protected:
        virtual void        OnHoriScroll(s32 _s32Pos) override;
        virtual void        OnVertScroll(s32 _s32Pos) override;


    /*******************************************************************************
    * qSysWin interface
    *******************************************************************************/
    protected:
        /*******************************************************************************
        * qSysWin interface
        *******************************************************************************/
    protected:
        virtual void        OnResize(const qDimension2D<s32>    &_d2dOld,
                                     const qDimension2D<s32>    &_d2dNew) override;
}; // class StdScrollWin
