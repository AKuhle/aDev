/*******************************************************************************
* \file qStyleItemBase.h
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
#include "qGuiDefs.h"
#include "qRect2D.h"
#include "qEdges.h"


namespace qLib
{
    /*******************************************************************************
    * forwards
    *******************************************************************************/
    class qPainter;


    /*******************************************************************************
    * class qStyleItemBase
    *******************************************************************************/
    class qStyleItemBase
	{
        public:
            qStyleItemBase();
            virtual ~qStyleItemBase();

    }; // class qStyleItemBase

} // namespace qLib