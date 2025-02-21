/*******************************************************************************
* \file qqPoolVarS32.cpp
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
#include "qPoolVarS32.h"



namespace qLib
{
    /*******************************************************************************
    * qPoolVarS32::qPoolVarS32
    *******************************************************************************/
    qPoolVarS32::qPoolVarS32(s32	_s32Value,
                             s32    _s32Default)
    : qPoolVarI<s32>(_s32Value, _s32Default)
	{
    } // qPoolVarS32::qPoolVarS32


    /*******************************************************************************
    * qPoolVarS32::qPoolVarS32
    *******************************************************************************/
    qPoolVarS32::qPoolVarS32(s32     _s32Value,
                             s32     _s32Default,
                             s32     _s32Min,
                             s32     _s32Max)
    : qPoolVarI<s32>(_s32Value, _s32Default, _s32Min, _s32Max)
    {
    } // qPoolVarS32::qPoolVarS32


    /*******************************************************************************
    * qPoolVarS32::operator=
    *******************************************************************************/
    qPoolVarS32& qPoolVarS32::operator=(const qPoolVarS32 &_rhs)
	{
        qPoolVarI::operator=(_rhs);

		return *this;
    } // qPoolVarS32::operator=

} // namespace qLib
