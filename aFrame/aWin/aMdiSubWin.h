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
#include "aBaseWin.h"
#include "aToolMgr.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aFrame {
namespace aWin {


/*******************************************************************************
* class aMdiSubWin
*******************************************************************************/
class aMdiSubWin : public aBaseWin,
                   public aToolMgr
{
    private:


    /*******************************************************************************
    * con-/destruction
    *******************************************************************************/
    public:
        aMdiSubWin(aBaseWin *_pParent = nullptr);
        virtual ~aMdiSubWin();

    public:
        const aTitleBar*        titleBar() const;
        aTitleBar*              titleBar();


    /*******************************************************************************
    * aBaseWin interface
    *******************************************************************************/
    protected:
        bool                    onSysCreateWin() override;
        // virtual void            onPaintBorder() override;
        // virtual aRect           paddingRect() const override;

}; // class aMdiSubWin


} // namespace aWin
} // namespace aFrame
