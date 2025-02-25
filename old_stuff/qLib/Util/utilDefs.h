/*******************************************************************************
* \file mathDefs.h
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


/*******************************************************************************
* includes
*******************************************************************************/


/*******************************************************************************
* namespace
*******************************************************************************/
namespace qLib {
namespace Util {


template <class T>
T       min(const T		_t1,
            const T		_t2);


template <class T>
T       max(const T		_t1,
            const T		_t2);


template <class T>
T       clamp(const T		_tValue,
              const T		_tMin,
              const T		_tMax);


template <class T>
bool    isZero(const T		_t1);


template <class T>
bool    isEqual(const T		_t1,
                const T		_t2);


template <class T>
bool    isUnequal(const T		_t1,
                  const T		_t2);


} // namespace Util
} // namespace qLib
