/*******************************************************************************
* \file aPoolVarU64.h
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
#include "aFrame_def.h"
#include "aPoolVarBase.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aFrame {
namespace aUtil {


/*******************************************************************************
* class aPoolVarU64
*******************************************************************************/
class aPoolVarU64 : public aPoolVarBase<u64>
{
    public:
        aPoolVarU64(const u64		_s64Value,
                    const u64		_s64Default);

        aPoolVarU64(const u64		_s64Value,
                    const u64		_s64Default,
                    const u64		_s64Min,
                    const u64		_s64Max);

        aPoolVarU64&		operator=(const aPoolVarU64	&_rhs);

        void                add2JsonFile(aJsonFile  &_jFile,
                                         u32        _u32keyID) const override;
}; // class aPoolVarU64


} // namespace aUtil
} // namespace aFrame
