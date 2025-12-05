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


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aFrame {
namespace aWin {


/*******************************************************************************
* class aMdiArea
*******************************************************************************/
class aMdiArea : public aBaseWin
{
    private:


    /*******************************************************************************
    * con-/destruction
    *******************************************************************************/
    public:
        aMdiArea(aBaseWin *_pParent = nullptr);
        virtual ~aMdiArea();


    public:
        void                    addMdiSubWin(aMdiSubWin *_pWin);


    /*******************************************************************************
    * aBaseWin interface
    *******************************************************************************/
    protected:
        // bool                    onSysCreateWin() override;
        // virtual void            onPaintBorder() override;
        // virtual aRect           paddingRect() const override;

}; // class aMdiArea


} // namespace aWin
} // namespace aFrame
