/*******************************************************************************
* \file aPoolVarBool.h
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
#include "aPoolVarBase.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aUtil {


/*******************************************************************************
* class aPoolVarBool
*******************************************************************************/
class aPoolVarBool : public aPoolVarBase<bool>
{
    public:
        aPoolVarBool(bool   _bValue,
                     bool	_bDefault);

        aPoolVarBool&		operator=(const aPoolVarBool &_rhs);

        void                add2JsonFile(aJsonFile  &_jFile,
                                         u32        _u32keyID) const override;
}; // class aPoolVarBool


} // namespace aUtil
} // namespace aLib
