/*******************************************************************************
* \file aScrollBar.h
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
#include "aWin/aWin_def.h"
#include "aWin/Ctrl/aCtrl.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aWin {


/*******************************************************************************
* class aScrollBar
*******************************************************************************/
class aScrollBar : public aCtrl
{
    private:

    public:
        aScrollBar(aBaseWin    *_pParent,
                   u32         _u32Id);
        virtual ~aScrollBar();


    /*******************************************************************************
    * qWin interface
    *******************************************************************************/
    public:
        virtual bool            onSysCreate() override;

}; // class aScrollBar


} // namespace aWin
} // namespace aLib
