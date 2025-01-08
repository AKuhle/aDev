/*******************************************************************************
* \file qMainWinMdi.h
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
#include "qMainWin.h"


namespace qLib
{
    /*******************************************************************************
    * forward
    *******************************************************************************/
    class qMdiWin;
    class qMdiChild;


    /*******************************************************************************
    * class qMainWinMdi
    *******************************************************************************/
    class qMainWinMdi : public qMainWin
    {
        protected:
            qMainWinMdi(qWin  *_pParent = nullptr);
            ~qMainWinMdi();

            void                AddMdiChild(qMdiChild *_pChild);

        private:
            qMdiWin*            GetMdiWin();
            void                ActivateMdiChild(qMdiChild *_pChild);

        /*******************************************************************************
        * qWin interface
        *******************************************************************************/
        public:
            virtual bool        OnSysCreate();

    }; // class qMainWinMdi

} // namespace aLib
