/*******************************************************************************
* \file qValue_bool.cpp
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
#pragma once


/*******************************************************************************
* includes
*******************************************************************************/
#include "qLibDefs.h"

#include "qValue.h"


namespace qLib {
namespace Object {


class qValue_dbl : public qValue<dbl>
{
    public:
        qValue_dbl() = default;

        qValue_dbl(const dbl		_dValue,
                   const dbl		_dDefault);

        qValue_dbl(const dbl		_dValue,
                   const dbl		_dDefault,
                   const dbl		_dMin,
                   const dbl		_dMax);

        qValue_dbl&		operator=(const qValue_dbl	&_rhs);
}; // class qValue_dbl


} // namespace Object
} // namespace qLib
