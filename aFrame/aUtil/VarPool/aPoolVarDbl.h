/*******************************************************************************
* \file aPoolVarBase.h
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
* class aPoolVarDbl
*******************************************************************************/
class aPoolVarDbl : public aPoolVarBase<dbl>
{
    public:
        aPoolVarDbl(const dbl		_dblValue,
                    const dbl		_dblDefault);

        aPoolVarDbl(const dbl		_dblValue,
                    const dbl		_dblDefault,
                    const dbl		_dblMin,
                    const dbl		_dblMax);

        aPoolVarDbl&        operator=(const aPoolVarDbl	&_rhs);

        void                add2JsonFile(aJsonFile  &_jFile,
                                         u32        _u32keyID) const override;
}; // class PoolVarDbl


} // namespace aUtil
} // namespace aFrame
