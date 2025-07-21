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
#include "aColor.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aFrame {
namespace aUtil {


/*******************************************************************************
* class aPoolVarColor
*******************************************************************************/
class aPoolVarColor : public aPoolVarBase<aColor>
{
    public:
        aPoolVarColor(const aColor	&_rgbaValue,
                      const aColor	&_rgbaDefault);

        aPoolVarColor&		operator=(const aPoolVarColor	&_rhs);

        void                add2JsonFile(aJsonFile  &_jFile,
                                         u32        _u32keyID) const override;
}; // class aPoolVarColor


} // namespace aUtil
} // namespace aFrame
