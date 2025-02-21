/*******************************************************************************
* \file MU.h
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


namespace qLib {
namespace Util {


/*******************************************************************************
* functions
*******************************************************************************/
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


// class MU
// {
//     public:
//         static bool     IsZero(const T		_t1);

//         static T        Abs(const T		_t);

//         static T        Min(const T		_t1,
//                             const T		_t2);

//         static T        Min(const T		_t1,
//                             const T		_t2,
//                             const T		_t3);

//         static  T       Max(const T		_t1,
//                             const T		_t2,
//                             const T		_t3);

//         static  T       Max(const T		_t1,
//                             const T		_t2,
//                             const T		_t3,
//                             const T		_t4);


//         static T        Ceil(const T		_tValue,
//                              const T		_tMultiple);

//         static void     SetBits(T		&_tValue,
//                                 const T	_tBits2Set);

//         static void     ClearBits(T			&_tValue,
//                                   const T	_tBits2Clear);

//         static void     ToggleBits(T		&_tValue,
//                                    const T	_tBits2Toggle);

//         static bool     AreBitsSet(const T	_tValue,
//                                    const T	_tBits2Check);

//         static bool     AreBitsClear(const T	_tValue,
//                                      const T	_tBits2Check);

//         static T        RandomValue(const T		_tMin,
//                                     const T		_tMax);


} // namespace Util
} // namespace qLib


#include "qUtil.inl"
