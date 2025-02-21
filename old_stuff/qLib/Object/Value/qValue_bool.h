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
#include "qValue.h"


namespace qLib {
namespace Object {


/*******************************************************************************
* class qValue_bool
*******************************************************************************/
class qValue_bool : public qValue<bool>
{
    public:
        qValue_bool() = default;

        qValue_bool(bool   _bValue,
                    bool   _bDefault);

        qValue_bool&            operator=(const qValue_bool &_rhs);
}; // class qValue_bool


} // namespace Object
} // namespace qLib
