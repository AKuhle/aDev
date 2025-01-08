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
#include "qPoolVarBool.h"



namespace qLib
{
    /*******************************************************************************
    * qPoolVarBool::qPoolVarBool
    *******************************************************************************/
    qPoolVarBool::qPoolVarBool(const qPoolVarBool &_rhs)
    : qPoolVarI<bool>(_rhs)
	{
    } // qPoolVarBool::qPoolVarBool


    /*******************************************************************************
    * qPoolVarBool::qPoolVarBool
    *******************************************************************************/
    qPoolVarBool::qPoolVarBool(bool	_bValue,
                               bool _bDefault)
    : qPoolVarI<bool>(_bValue, _bDefault)
    {
    } // qPoolVarBool::qPoolVarBool


    /*******************************************************************************
    * qPoolVarBool::operator=
    *******************************************************************************/
    qPoolVarBool& qPoolVarBool::operator=(const qPoolVarBool &_rhs)
	{
        qPoolVarI::operator=(_rhs);

		return *this;
    } // qPoolVarBool::operator=

} // namespace qLib
