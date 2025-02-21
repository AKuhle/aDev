/*******************************************************************************
* \file qqPoolVarColor.cpp
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
#include "qPoolVarColor.h"



namespace qLib
{
    /*******************************************************************************
    * qPoolVarColor::qPoolVarColor
    *******************************************************************************/
    qPoolVarColor::qPoolVarColor(const qPoolVarColor &_rhs)
    : qPoolVarI<qColor>(_rhs)
    {
    } // qPoolVarColor::qPoolVarColor


    /*******************************************************************************
    * qPoolVarColor::qPoolVarColor
    *******************************************************************************/
    qPoolVarColor::qPoolVarColor(const qColor  &_colValue,
                                 const qColor  &_colDefault)
    : qPoolVarI<qColor>(_colValue, _colDefault)
    {
    } // qPoolVarColor::qPoolVarColor


    /*******************************************************************************
    * qPoolVarColor::qPoolVarColor
    *******************************************************************************/
    qPoolVarColor::qPoolVarColor(const qColor  &_colValue,
                                 const qColor  &_colDefault,
                                 const qColor  &_colMin,
                                 const qColor  &_colMax)
    : qPoolVarI<qColor>(_colValue, _colDefault, _colMin, _colMax)
    {
    } // qPoolVarColor::qPoolVarColor


    /*******************************************************************************
    * qPoolVarColor::operator=
    *******************************************************************************/
    qPoolVarColor& qPoolVarColor::operator=(const qPoolVarColor &_rhs)
	{
        qPoolVarI::operator=(_rhs);

		return *this;
    } // qPoolVarColor::operator=

} // namespace qLib
