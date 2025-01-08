/*******************************************************************************
* \file qMdiWin.h
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
#include "qPtrList.h"
#include "qWin.h"


namespace qLib
{
    /*******************************************************************************
    * forward
    *******************************************************************************/
    class qMdiChild;


    /*******************************************************************************
    * class qMdiWin
    *******************************************************************************/
    class qMdiWin : public qWin
    {
        private:
            qPtrList<qMdiChild>     m_lstChilds;

        public:
            qMdiWin(qWin  *_pParent = nullptr);
            ~qMdiWin();

        public:
            void                AddMdiChild(qMdiChild *_pChild);
            void                ActivateMdiChild(qMdiChild *_pChild);

    }; // class qMdiWin

} // namespace aLib
