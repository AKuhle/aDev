/*******************************************************************************
* \file qMdiArea.h
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
#include "qSysWin.h"


namespace qLib
{
    /*******************************************************************************
    * forwards
    *******************************************************************************/
    class qMdiWin;


    /*******************************************************************************
    * class qMdiArea
    *******************************************************************************/
    class qMdiArea : public qSysWin<QMdiArea>
    {
        public:
            qMdiArea(SysWin_t *_pParent = nullptr);
            ~qMdiArea();

            void                AddMdiWin(qMdiWin *_pMdiWin);

            void                GetMdiWinList(qPtrList<qMdiWin> &_lstMdiWin) const;

            qMdiWin*            ActiveMdiWin();
            qMdiWin*            ActiveOrTopmostMdiWin();

    }; // class qMdiArea

} // namespace qLib
