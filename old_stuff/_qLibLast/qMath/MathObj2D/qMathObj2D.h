/*******************************************************************************
* \file qMathObj2D.h
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


//------------------------------------------------------------------------------
// includes
//------------------------------------------------------------------------------
#include "qMathObj.h"


namespace qLib
{
    //------------------------------------------------------------------------------
    //! \class MathObj
    //! \brief baseclass for 2D math-objects
    //------------------------------------------------------------------------------
    class qMathObj2D : public qMathObj
	{
		protected:
            qMathObj2D();

		public:
            virtual ~qMathObj2D();
    }; // class qMathObj2D

} // namespace qLib
