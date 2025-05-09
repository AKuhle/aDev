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
#include "aLib_def.h"
#include "aPoolVarBase.h"
#include "aString.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aUtil {


/*******************************************************************************
* class aPoolVarString
*******************************************************************************/
class aPoolVarString : public aPoolVarBase<aString>
{
    public:
        aPoolVarString(const aString	_sValue,
                       const aString    _sDefault);

        aPoolVarString&		operator=(const aPoolVarString	&_rhs);

        void                add2JsonFile(aJsonFile  &_jFile,
                                         u32        _u32keyID) const override;
}; // class aPoolVarString


} // namespace aUtil
} // namespace aLib
