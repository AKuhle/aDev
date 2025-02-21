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
#include "qValue_u32.h"

namespace qLib {
namespace Object {


/*******************************************************************************
* qValue_u32::qValue_u32
*******************************************************************************/
qValue_u32::qValue_u32(const u32		_u32Value,
                       const u32		_u32Default)
: qValue<u32>(_u32Value, _u32Default)
{
} // qValue_u32::qValue_u32


/*******************************************************************************
* qValue_u32::qValue_u32
*******************************************************************************/
qValue_u32::qValue_u32(const u32		_u32Value,
                       const u32		_u32Default,
                       const u32		_u32Min,
                       const u32		_u32Max)
: qValue<u32>(_u32Value, _u32Default, _u32Min, _u32Max)
{
} // qValue_u32::qValue_u32


/*******************************************************************************
* qValue_u32::operator=
*******************************************************************************/
qValue_u32& qValue_u32::operator=(const qValue_u32	&_rhs)
{
    qValue::operator=(_rhs);

    return *this;
} // qValue_u32::operator=


} // namespace Object
} // namespace qLib
