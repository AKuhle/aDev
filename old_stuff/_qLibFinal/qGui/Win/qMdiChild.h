/*******************************************************************************
* \file qMdiChild.h
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
#include "qWin.h"
#include "qTitleBar.h"


namespace qLib
{
    /*******************************************************************************
    * class qMdiChild
    *******************************************************************************/
    class qMdiChild : public qWin
    {
        public:
            qMdiChild(qWin  *_pParent = nullptr);
            ~qMdiChild();

            qWin*                       GetCenterWin() const;
            void                        SetCenterWin(qWin *_pWin);

            void                        Activate(bool _bActive);


        /*******************************************************************************
        * qWin interface
        *******************************************************************************/
        public:
            virtual bool                OnSysCreate();
            virtual void                OnSetCursor();

    }; // class qMdiChild

} // namespace aLib
