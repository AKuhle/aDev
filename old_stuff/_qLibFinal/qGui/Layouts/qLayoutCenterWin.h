/*******************************************************************************
* \file qLayoutCenterWin.h
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
#include "qLayoutObj.h"


namespace qLib
{
    /*******************************************************************************
    * forward
    *******************************************************************************/
    class qWin;


    /*******************************************************************************
    * \class qLayoutCenterWin
    *******************************************************************************/
    class qLayoutCenterWin : public qLayoutObj
	{
        DeclarePtrProperty(qWin, p, CenterWin)

        public:
            qLayoutCenterWin();
            virtual ~qLayoutCenterWin();


        /*******************************************************************************
        * qLayoutBase interface
        *******************************************************************************/
        public:
            virtual qDimension2D<s32>   GetMinSize() const override;
            virtual void                ArangeChilds(const qRect2D<s32> &_parentRect) override;
    }; // class qLayoutCenterWin

} // namespace qLib
