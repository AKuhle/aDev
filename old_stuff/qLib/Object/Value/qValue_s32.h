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


class qValue_s32 : public qValue<s32>
{
    public:
        qValue_s32() = default;

        qValue_s32(const s32		_s32Value,
                   const s32		_s32Default);

        qValue_s32(const s32		_s32Value,
                   const s32		_s32Default,
                   const s32		_s32Min,
                   const s32		_s32Max);

        qValue_s32&		operator=(const qValue_s32	&_rhs);
}; // class qValue_s32


} // namespace Object
} // namespace qLib
