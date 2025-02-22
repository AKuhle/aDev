///////////////////////////////////////////////////////////////////////////////
// include
///////////////////////////////////////////////////////////////////////////////
#include "qlBaseDefs.h"
#include "poolVar_string.h"

namespace qlBase
{
	///////////////////////////////////////////////////////////////////////////////
    // PoolVarString::PoolVarString
	///////////////////////////////////////////////////////////////////////////////
    PoolVarString::PoolVarString(const qlStringU	_sValue,
                                 const qlStringU	_sDefault)
    : PoolVarI<qlStringU>(_sValue, _sDefault)
	{
    } // PoolVarString::PoolVarString


	/////////////////////////////////////////////////////////////////////////////
    // PoolVarString::operator=
	/////////////////////////////////////////////////////////////////////////////
    PoolVarString& PoolVarString::operator=(const PoolVarString	&_rhs)
	{
		PoolVarI::operator=(_rhs);

		return *this;
    } // PoolVarString::operator=

} // namespace qlBase
