/*******************************************************************************
* \file qPoolVarBool.cpp
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
#include "qPoolVar_i.h"


/*******************************************************************************
* class qqPoolVarBool
*******************************************************************************/
namespace qLib
{
    class qPoolVarBool : public qPoolVarI<bool>
	{
		public:
            qPoolVarBool() = default;

            qPoolVarBool(bool   _bValue,
                         bool	_bDefault);

            qPoolVarBool&		operator=(const qPoolVarBool &_rhs);
    }; // class qPoolVarBool

} // namespace qLib
