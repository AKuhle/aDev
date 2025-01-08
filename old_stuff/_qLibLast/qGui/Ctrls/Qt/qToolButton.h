/*******************************************************************************
* \file qToolButton.h
* \author Andreas Kuhlewind
*
* \brief
*
*  Detailed description starts here.
*******************************************************************************/
#pragma once

#ifdef _USE_QT_


/*******************************************************************************
* includes
*******************************************************************************/
#include "qButtonBase.h"


namespace qLib
{
    /*******************************************************************************
    * \class qToolButton
    *******************************************************************************/
    class qToolButton : public qButtonBase<QToolButton>
    {
        Q_OBJECT

        public:
            qToolButton(SysWin_t *_pParent = nullptr);
            virtual ~qToolButton();


        /*******************************************************************************
        * slots
        *******************************************************************************/
        private slots:
            void            SlotClicked(bool _bChecked);
    }; // class qToolButton

} // namespace qLib

#endif // _USE_QT_
