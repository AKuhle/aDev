/*******************************************************************************
* \file aPoolVarS64.cpp
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
#include "aPoolVarS64.h"
#include "aJsonFile.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aFrame {
namespace aUtil {


/*******************************************************************************
* aPoolVarS64::aPoolVarS64
*******************************************************************************/
aPoolVarS64::aPoolVarS64(const s64		_s64Value,
                         const s64		_s64Default)
: aPoolVarBase<s64>(_s64Value, _s64Default)
{
} // aPoolVarS64::aPoolVarS64


/*******************************************************************************
* aPoolVarS64::aPoolVarS64
*******************************************************************************/
aPoolVarS64::aPoolVarS64(const s64		_s64Value,
                         const s64		_s64Default,
                         const s64		_s64Min,
                         const s64		_s64Max)
: aPoolVarBase<s64>(_s64Value, _s64Default, _s64Min, _s64Max)
{
} // aPoolVarS64::aPoolVarS64


/*******************************************************************************
* aPoolVarS64::operator=
*******************************************************************************/
aPoolVarS64& aPoolVarS64::operator=(const aPoolVarS64	&_rhs)
{
    aPoolVarBase<s64>::operator=(_rhs);

    return *this;
} // aPoolVarS64::operator=


/*******************************************************************************
* aPoolVarS64::add2JsonFile
*******************************************************************************/
void aPoolVarS64::add2JsonFile(aJsonFile  &/*_jFile*/,
                               u32        /*_u32keyID*/) const
{
    // _jFile.openLevel();

    // _jFile.add(aJsonValue("value", (dbl) val()));
    // _jFile.add(aJsonValue("default", (dbl) defVal()));
    // _jFile.add(aJsonValue("min", (dbl) minVal()));
    // _jFile.add(aJsonValue("max", (dbl) maxVal()));
    // _jFile.add(aJsonValue("minMax", minMax()));

    // // key for this value is the id of this value
    // _jFile.closeLevel(aString::fromValue(_u32keyID));
} // aPoolVarS64::add2JsonFile


} // namespace aUtil
} // namespace aFrame
