/*******************************************************************************
* \file qPoolVarS32.cpp
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
* class qPoolVarS32
*******************************************************************************/
namespace qLib
{
    class qPoolVarS32 : public qPoolVarI<s32>
	{
		public:
            qPoolVarS32() = default;

            qPoolVarS32(s32     _s32Value,
                        s32     _s32Default);

            qPoolVarS32(s32     _s32Value,
                        s32     _s32Default,
                        s32     _s32Min,
                        s32     _s32Max);

            qPoolVarS32&		operator=(const qPoolVarS32 &_rhs);
    }; // class qPoolVarS32

} // namespace qLib
