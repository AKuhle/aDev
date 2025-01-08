/*******************************************************************************
* \file qqPoolVarBool.cpp
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
#include "qValue_dbl.h"

namespace qLib {
namespace Object {


/*******************************************************************************
* qValue_dbl::qValue_dbl
*******************************************************************************/
qValue_dbl::qValue_dbl(const dbl		_dblValue,
                       const dbl		_dblDefault)
: qValue<dbl>(_dblValue, _dblDefault)
{
} // qValue_dbl::qValue_dbl


/*******************************************************************************
* qValue_dbl::qValue_dbl
*******************************************************************************/
qValue_dbl::qValue_dbl(const dbl		_dblValue,
                       const dbl		_dblDefault,
                       const dbl		_dblMin,
                       const dbl		_dblMax)
: qValue<dbl>(_dblValue, _dblDefault, _dblMin, _dblMax)
{
} // qValue_dbl::qValue_dbl


/*******************************************************************************
* qValue_dbl::operator=
*******************************************************************************/
qValue_dbl& qValue_dbl::operator=(const qValue_dbl	&_rhs)
{
    qValue::operator=(_rhs);

    return *this;
} // qValue_dbl::operator=


} // namespace Object
} // namespace qLib
