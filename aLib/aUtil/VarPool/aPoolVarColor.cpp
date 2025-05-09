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
#include "aPoolVarColor.h"
#include "aJsonFile.h"
#include "aJsonValue.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aUtil {


/*******************************************************************************
* aPoolVarColor::aPoolVarColor
*******************************************************************************/
aPoolVarColor::aPoolVarColor(const aColor	&_rgbaValue,
                             const aColor	&_rgbaDefault)
: aPoolVarBase<aColor>(_rgbaValue, _rgbaDefault)
{
} // aPoolVarColor::aPoolVarColor


/*******************************************************************************
* aPoolVarColor::operator=
*******************************************************************************/
aPoolVarColor& aPoolVarColor::operator=(const aPoolVarColor	&_rhs)
{
    aPoolVarBase<aColor>::operator=(_rhs);

    return *this;
} // aPoolVarColor::operator=


/*******************************************************************************
* aPoolVarColor::add2JsonFile
*******************************************************************************/
void aPoolVarColor::add2JsonFile(aJsonFile  &_jFile,
                                 u32        _u32keyID) const
{
    _jFile.openLevel();

    _jFile.add(aJsonValue("valueR", val().r()));
    _jFile.add(aJsonValue("valueG", val().g()));
    _jFile.add(aJsonValue("valueB", val().b()));
    _jFile.add(aJsonValue("valueA", val().a()));

    _jFile.add(aJsonValue("defaultR", val().r()));
    _jFile.add(aJsonValue("defaultG", val().g()));
    _jFile.add(aJsonValue("defaultB", val().b()));
    _jFile.add(aJsonValue("defaultA", val().a()));

    // key for this value is the id of this value
    _jFile.closeLevel(aString::fromValue(_u32keyID));
} // aPoolVarColor::add2Json

} // namespace aUtil
} // namespace aLib
