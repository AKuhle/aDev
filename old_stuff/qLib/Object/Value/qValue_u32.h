/*******************************************************************************
* \file qValue_bool.cpp
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
#include "qLibDefs.h"

#include "qValue.h"


namespace qLib {
namespace Object {


class qValue_u32 : public qValue<u32>
{
    public:
        qValue_u32() = default;

        qValue_u32(const u32		_u32Value,
                   const u32		_u32Default);

        qValue_u32(const u32		_u32Value,
                   const u32		_u32Default,
                   const u32		_u32Min,
                   const u32		_u32Max);

        qValue_u32&		operator=(const qValue_u32	&_rhs);
}; // class qValue_u32


} // namespace Object
} // namespace qLib
