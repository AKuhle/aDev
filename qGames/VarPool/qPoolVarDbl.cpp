/*******************************************************************************
* \file qqPoolVarDbl.cpp
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
#include "qPoolVarDbl.h"



namespace qLib
{
    /*******************************************************************************
    * qPoolVarDbl::qPoolVarDbl
    *******************************************************************************/
    qPoolVarDbl::qPoolVarDbl(const qPoolVarDbl &_rhs)
    : qPoolVarI<dbl>(_rhs)
    {
    } // qPoolVarDbl::qPoolVarDbl


    /*******************************************************************************
    * qPoolVarDbl::qPoolVarDbl
    *******************************************************************************/
    qPoolVarDbl::qPoolVarDbl(dbl	_dValue,
                             dbl    _dDefault)
    : qPoolVarI<dbl>(_dValue, _dDefault)
	{
    } // qPoolVarDbl::qPoolVarDbl


    /*******************************************************************************
    * qPoolVarDbl::qPoolVarDbl
    *******************************************************************************/
    qPoolVarDbl::qPoolVarDbl(dbl    _dValue,
                             dbl    _dDefault,
                             dbl    _dMin,
                             dbl    _dMax)
    : qPoolVarI<dbl>(_dValue, _dDefault, _dMin, _dMax)
    {
    } // qPoolVarDbl::qPoolVarDbl


    /*******************************************************************************
    * qPoolVarDbl::operator=
    *******************************************************************************/
    qPoolVarDbl& qPoolVarDbl::operator=(const qPoolVarDbl &_rhs)
	{
        qPoolVarI::operator=(_rhs);

		return *this;
    } // qPoolVarDbl::operator=

} // namespace qLib
