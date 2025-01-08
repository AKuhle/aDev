/*******************************************************************************
* \file qToolButton.h
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
#include "qButtonBase.h"


namespace qLib
{
    /*******************************************************************************
    * class qToolButton
    *******************************************************************************/
    class qToolButton : public qButtonBase
    {
        private:

        public:
            qToolButton(qWin  *_pParent,
                        u32   _u32Id);
            virtual ~qToolButton();


        /*******************************************************************************
        * qWin interface
        *******************************************************************************/
        protected:
            //virtual void                OnPaintMarginBg() override;
            //virtual void                OnPaintBorder() override;
            //virtual void                OnPaintPaddingBg() override;

            virtual void                OnPaintContentBg() override;
            virtual void                OnPaintContent() override;

    }; // class qToolButton

} // namespace qLib
