/*******************************************************************************
* \file aToolButton.h
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
#include "aWin/Ctrl/aButton.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aWin {


/*******************************************************************************
* class aToolButton
*******************************************************************************/
class aToolButton : public aButton
{
    private:

    public:
        aToolButton(aBaseWin    *_pParent,
                    u32         _u32Id);
        virtual ~aToolButton();


    /*******************************************************************************
    * qWin interface
    *******************************************************************************/
    protected:
        virtual void                onPaintMargin() override;
        virtual void                onPaintBorder() override;
        virtual void                onPaintPaddingBg() override;

        virtual void                onPaintContentBg() override;
        virtual void                onPaintContent() override;

}; // class aToolButton


} // namespace aWin
} // namespace aLib
