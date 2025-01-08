/*******************************************************************************
* \file qVarPool.h
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
* include
*******************************************************************************/
#include "qLib.h"


namespace qLib
{
    /*******************************************************************************
    * class VarPool
    *******************************************************************************/
    class VarPool : public qGuiVarPool
	{
        protected:

		public:
            VarPool();
            VarPool(const VarPool &_rhs);
            virtual ~VarPool();

            VarPool&            operator=(const VarPool &_rhs);

    }; // class VarPool

} // namespace qLib
