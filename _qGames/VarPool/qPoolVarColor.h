/*******************************************************************************
* \file qPoolVarColor.cpp
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
#include "qColor.h"


/*******************************************************************************
* class qPoolVarColor
*******************************************************************************/
namespace qLib
{
    class qPoolVarColor : public qPoolVarI<qColor>
	{
		public:
            qPoolVarColor() = default;
            qPoolVarColor(const qPoolVarColor &);

            qPoolVarColor(const qColor &_colValue,
                          const qColor &_colDefault);

            qPoolVarColor(const qColor &_colValue,
                          const qColor &_colDefault,
                          const qColor &_colMin,
                          const qColor &_colMax);

            qPoolVarColor&		operator=(const qPoolVarColor &_rhs);
    }; // class qPoolVarColor

} // namespace qLib
