/*******************************************************************************
* \file qMathObj.h
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


namespace qLib
{
    //------------------------------------------------------------------------------
    //! \class qMathObj
    //! \brief baseclass for math-objects
    //------------------------------------------------------------------------------
    class qMathObj
	{
		protected:
            qMathObj();

		public:
            virtual ~qMathObj();
    }; // class qMathObj

} // namespace qLib
