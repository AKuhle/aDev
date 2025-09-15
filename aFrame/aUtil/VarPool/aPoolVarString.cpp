/*******************************************************************************
* \file aPoolVarString.cpp
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
#include "aPoolVarString.h"
#include "aJsonFile.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aFrame {
namespace aUtil {


/*******************************************************************************
* aPoolVarString::aPoolVarString
*******************************************************************************/
aPoolVarString::aPoolVarString(const aString	_sValue,
                               const aString	_sDefault)
: aPoolVarBase<aString>(_sValue, _sDefault)
{
} // aPoolVarString::aPoolVarString


/*******************************************************************************
* aPoolVarString::operator=
*******************************************************************************/
aPoolVarString& aPoolVarString::operator=(const aPoolVarString	&_rhs)
{
    aPoolVarBase<aString>::operator=(_rhs);

    return *this;
} // aPoolVarString::operator=


/*******************************************************************************
* aPoolVarString::add2JsonFile
*******************************************************************************/
void aPoolVarString::add2JsonFile(aJsonFile  &/*_jFile*/,
                                  u32        /*_u32keyID*/) const
{
    // _jFile.openLevel();

    // _jFile.add(aJsonValue("value", val()));
    // _jFile.add(aJsonValue("default", defVal()));

    // // key for this value is the id of this value
    // _jFile.closeLevel(aString::fromValue(_u32keyID));
} // aPoolVarString::add2JsonFile


} // namespace aUtil
} // namespace aFrame
