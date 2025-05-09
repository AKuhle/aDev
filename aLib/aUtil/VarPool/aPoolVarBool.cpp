/*******************************************************************************
* \file aPoolVarBool.cpp
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


/*******************************************************************************
* includes
*******************************************************************************/
#include "aPoolVarBool.h"
#include "aJsonFile.h"
#include "aJsonValue.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aUtil {


/*******************************************************************************
* aPoolVarBool::aPoolVarBool
*******************************************************************************/
aPoolVarBool::aPoolVarBool(bool	_bValue,
                           bool _bDefault)
: aPoolVarBase<bool>(_bValue, _bDefault)
{
} // aPoolVarBool::aPoolVarBool


/*******************************************************************************
* aPoolVarBool::operator=
*******************************************************************************/
aPoolVarBool& aPoolVarBool::operator=(const aPoolVarBool &_rhs)
{
    aPoolVarBase<bool>::operator=(_rhs);

    return *this;
} // aPoolVarBool::operator=


/*******************************************************************************
* aPoolVarBool::add2JsonFile
*******************************************************************************/
void aPoolVarBool::add2JsonFile(aJsonFile  &_jFile,
                                u32        _u32keyID) const
{
    _jFile.openLevel();

    _jFile.add(aJsonValue("value", val()));
    _jFile.add(aJsonValue("default", defVal()));

    // key for this value is the id of this value
    _jFile.closeLevel(aString::fromValue(_u32keyID));
} // aPoolVarBool::add2JsonFile


} // namespace aUtil
} // namespace aLib
