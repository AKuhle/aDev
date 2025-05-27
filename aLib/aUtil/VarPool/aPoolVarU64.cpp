/*******************************************************************************
* \file aPoolVarU64.cpp
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
* include
*******************************************************************************/
#include "aPoolVarU64.h"
#include "aJsonFile.h"
#include "aJsonValue.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aUtil {


/*******************************************************************************
* aPoolVarU64::aPoolVarU64
*******************************************************************************/
aPoolVarU64::aPoolVarU64(const u64		_u64Value,
                         const u64		_u64Default)
: aPoolVarBase<u64>(_u64Value, _u64Default)
{
} // aPoolVarU64::aPoolVarU64


/*******************************************************************************
* aPoolVarU64::aPoolVarU64
*******************************************************************************/
aPoolVarU64::aPoolVarU64(const u64		_u64Value,
                         const u64		_u64Default,
                         const u64		_u64Min,
                         const u64		_u64Max)
: aPoolVarBase<u64>(_u64Value, _u64Default, _u64Min, _u64Max)
{
} // aPoolVarU64::aPoolVarU64


/*******************************************************************************
* aPoolVarU64::operator=
*******************************************************************************/
aPoolVarU64& aPoolVarU64::operator=(const aPoolVarU64	&_rhs)
{
    aPoolVarBase<u64>::operator=(_rhs);

    return *this;
} // aPoolVarU64::operator=


/*******************************************************************************
* aPoolVarU64::add2JsonFile
*******************************************************************************/
void aPoolVarU64::add2JsonFile(aJsonFile  &_jFile,
                               u32        _u32keyID) const
{
    _jFile.openLevel();

    _jFile.add(aJsonValue("value", (dbl) val()));
    _jFile.add(aJsonValue("default", (dbl) defVal()));
    _jFile.add(aJsonValue("min", (dbl) minVal()));
    _jFile.add(aJsonValue("max", (dbl) maxVal()));
    _jFile.add(aJsonValue("minMax", minMax()));

    // key for this value is the id of this value
    _jFile.closeLevel(aString::fromValue(_u32keyID));
} // aPoolVarU64::add2JsonFile


} // namespace aUtil
} // namespace aLib
