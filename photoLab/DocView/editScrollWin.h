/*******************************************************************************
* \file BaseApp.h
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
#include "aLib_def.h"
#include "aScrollWin.h"

class ViewBase;

using namespace aLib;
using namespace aLib::aWin;



/*******************************************************************************
* class EditScrollWin
*******************************************************************************/
class EditScrollWin : public aScrollWin
{
    public:
        EditScrollWin(SysWin *_pParent = nullptr);
        ~EditScrollWin();

        ViewBase*       viewBase();

        void            updateScrollBars();


    /*******************************************************************************
    * BaseWin interface
    *******************************************************************************/
    protected:
        bool            onCreateWin() override;
        bool            onPaint() override;


    /*******************************************************************************
    * handler to redirect the event to the viewport
    *******************************************************************************/
    protected:
        bool            onWheel(u32                  _u32Modifiers,
                                s32                  _s32Degree,
                                const aVector2D<s32> &_v2dLocal,
                                const aVector2D<s32> &_v2dGlobal) override;

}; // class EditScrollWin
