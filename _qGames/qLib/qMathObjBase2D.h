/*******************************************************************************
* \file qMathObjBase2D.h
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
#include "qMathObjBase.h"


namespace qLib
{
    /*******************************************************************************
    * \class qMathObjBase2D
    * \brief baseclass for 2D math objects
    *******************************************************************************/
    class qMathObjBase2D : public qMathObjBase
    {
        protected:
            qMathObjBase2D();

        public:
            virtual ~qMathObjBase2D();
    }; // class qMathObjBase2D

} // namespace qLib
