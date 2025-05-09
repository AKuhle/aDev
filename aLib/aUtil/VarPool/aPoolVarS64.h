/*******************************************************************************
* \file aPoolVarS64.h
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
#include "aLib_def.h"
#include "aPoolVarBase.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aUtil {


/*******************************************************************************
* class aPoolVarS64
*******************************************************************************/
class aPoolVarS64 : public aPoolVarBase<s64>
{
    public:
        aPoolVarS64(const s64		_s64Value,
                    const s64		_s64Default);

        aPoolVarS64(const s64		_s64Value,
                    const s64		_s64Default,
                    const s64		_s64Min,
                    const s64		_s64Max);

        aPoolVarS64&        operator=(const aPoolVarS64	&_rhs);

        void                add2JsonFile(aJsonFile  &_jFile,
                                         u32        _u32keyID) const override;
}; // class aPoolVarS64


} // namespace aUtil
} // namespace aLib
