/*******************************************************************************
* \file qLayoutScrollWin.h
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
#include "qRect2D.h"
#include "qLayoutCenterWin.h"
#include "qPtrList.h"


namespace qLib
{
    /*******************************************************************************
    * forward
    *******************************************************************************/
    class qScrollBar;


    /*******************************************************************************
    * \class qLayoutScrollWin
    *******************************************************************************/
    class qLayoutScrollWin : public qLayoutCenterWin
	{
        DeclarePtrProperty(qScrollBar, p, HoriSb)
        DeclarePtrProperty(qScrollBar, p, VertSb)
        DeclarePtrProperty(qWin, p, CornerWin)

        public:
            qLayoutScrollWin();
            virtual ~qLayoutScrollWin();

        private:
            s32                         GetItemSize() const;

        /*******************************************************************************
        * qLayoutBase interface
        *******************************************************************************/
        public:
            virtual qDimension2D<s32>   GetMinSize() const override;
            virtual void                ArangeChilds(const qRect2D<s32> &_parentRect) override;

    }; // class qLayoutScrollWin

} // namespace qLib
