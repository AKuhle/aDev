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
#include "qValue_bool.h"


namespace qLib {
namespace Object {


/*******************************************************************************
* qValue_bool::qValue_bool
*******************************************************************************/
qValue_bool::qValue_bool(bool _bValue,
                         bool _bDefault)
: qValue<bool>(_bValue, _bDefault)
{
} // qValue_bool::qValue_bool


/*******************************************************************************
* qValue_bool::operator=
*******************************************************************************/
qValue_bool& qValue_bool::operator=(const qValue_bool &_rhs)
{
    qValue<bool>::operator=(_rhs);

    return *this;
} // qValue_bool::operator=


} // namespace Object
} // namespace qLib
