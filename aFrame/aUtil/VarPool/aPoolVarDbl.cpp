/*******************************************************************************
* \file aPoolVarDbl.cpp
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
#include "aPoolVarDbl.h"
#include "aJsonFile.h"
#include "aJsonValue.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aFrame {
namespace aUtil {


/*******************************************************************************
* aPoolVarDbl::aPoolVarDbl
*******************************************************************************/
aPoolVarDbl::aPoolVarDbl(const dbl		_dblValue,
                         const dbl		_dblDefault)
: aPoolVarBase<dbl>(_dblValue, _dblDefault)
{
} // aPoolVarDbl::aPoolVarDbl


/*******************************************************************************
* aPoolVarDbl::aPoolVarDbl
*******************************************************************************/
aPoolVarDbl::aPoolVarDbl(const dbl		_dblValue,
                         const dbl		_dblDefault,
                         const dbl		_dblMin,
                         const dbl		_dblMax)
: aPoolVarBase<dbl>(_dblValue, _dblDefault, _dblMin, _dblMax)
{
} // aPoolVarDbl::aPoolVarDbl


/*******************************************************************************
* aPoolVarDbl::add2JsonFile
*******************************************************************************/
void aPoolVarDbl::add2JsonFile(aJsonFile  &_jFile,
                               u32        _u32keyID) const
{
    _jFile.openLevel();

    _jFile.add(aJsonValue("value", val()));
    _jFile.add(aJsonValue("default", defVal()));
    _jFile.add(aJsonValue("min", minVal()));
    _jFile.add(aJsonValue("max", maxVal()));
    _jFile.add(aJsonValue("minMax", minMax()));

    // key for this value is the id of this value
    _jFile.closeLevel(aString::fromValue(_u32keyID));
} // aPoolVarDbl::add2JsonFile


/*******************************************************************************
* aPoolVarDbl::operator=
*******************************************************************************/
aPoolVarDbl& aPoolVarDbl::operator=(const aPoolVarDbl &_rhs)
{
    aPoolVarBase<dbl>::operator=(_rhs);

    return *this;
} // aPoolVarDbl::operator=


} // namespace aUtil
} // namespace aFrame
