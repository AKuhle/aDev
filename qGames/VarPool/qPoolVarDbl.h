/*******************************************************************************
* \file qPoolVarDbl.cpp
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
#include "qBaseDefs.h"
#include "qPoolVar_i.h"


/*******************************************************************************
* class qPoolVarDbl
*******************************************************************************/
namespace qLib
{
    class qPoolVarDbl : public qPoolVarI<dbl>
	{
		public:
            qPoolVarDbl() = default;
            qPoolVarDbl(const qPoolVarDbl &);

            qPoolVarDbl(dbl     _dValue,
                        dbl     _dDefault);

            qPoolVarDbl(dbl     _dValue,
                        dbl     _dDefault,
                        dbl     _dMin,
                        dbl     _dMax);

            qPoolVarDbl&		operator=(const qPoolVarDbl &_rhs);
    }; // class qPoolVarDbl

} // namespace qLib
