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
#include "qValue_s32.h"

namespace qLib {
namespace Object {


/*******************************************************************************
* qValue_s32::qValue_s32
*******************************************************************************/
qValue_s32::qValue_s32(const s32		_s32Value,
                       const s32		_s32Default)
: qValue<s32>(_s32Value, _s32Default)
{
} // qValue_s32::qValue_s32


/*******************************************************************************
* qValue_s32::qValue_s32
*******************************************************************************/
qValue_s32::qValue_s32(const s32		_s32Value,
                       const s32		_s32Default,
                       const s32		_s32Min,
                       const s32		_s32Max)
: qValue<s32>(_s32Value, _s32Default, _s32Min, _s32Max)
{
} // qValue_s32::qValue_s32


/*******************************************************************************
* qValue_s32::operator=
*******************************************************************************/
qValue_s32& qValue_s32::operator=(const qValue_s32	&_rhs)
{
    qValue::operator=(_rhs);

    return *this;
} // qValue_s32::operator=


} // namespace Object
} // namespace qLib
