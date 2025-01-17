/*******************************************************************************
* \file aHoriSpacer.h
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
#include "aWin/Ctrl/aCtrl.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aWin {


/*******************************************************************************
* class aHoriSpacer
*******************************************************************************/
class aHoriSpacer : public aCtrl
{
    public:
        aHoriSpacer(aBaseWin    *_pParent,
                    u32         _u32Id = CTRL_ID_HORI_SPACER);
        virtual ~aHoriSpacer();

    /*******************************************************************************
    * aLayoutObj interfasce
    *******************************************************************************/
    public:
        virtual bool                isVertExpandable() const { return false; }
}; // class aHoriSpacer


} // namespace aWin
} // namespace aLib
