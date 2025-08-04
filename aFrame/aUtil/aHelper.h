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


/*******************************************************************************
* includes
*******************************************************************************/
#include "aFrame_def.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aFrame {
namespace aUtil {


/*******************************************************************************
* global functions
*******************************************************************************/
u32     hardwareConcurrency();


/*******************************************************************************
* templated functions
*******************************************************************************/
template<typename T>
constexpr T min(T a,
                T b);

template<typename T, typename... Args>
constexpr T min(T       first,
                Args... args);

template<typename T>
constexpr T max(T a,
                T b);

template<typename T, typename... Args>
constexpr T max(T       first,
                Args... args);

template <class T>
T       clamp(T	_tValue,
              T	_tMin,
              T _tMax);

template <class T>
bool    isZero(T _t1);

template <class T>
bool    isEqual(T _t1,
                T _t2);

template <class T>
bool    isUnequal(T _t1,
                  T _t2);

template<class T>
void    setBits(T	&_tValue,
                T   _tBits2Set);

template<class T>
void 	clearBits(T	&_tValue,
                  T _tBits2Clear);

template<class T>
void 	toggleBits(T	&_tValue,
                   T    _tBits2Toggle);

template<class T>
bool 	areBitsSet(T	_tValue,
                   T	_tBits2Check);

template<class T>
bool 	areBitsClear(T	_tValue,
                     T	_tBits2Check);

} // namespace aUtil
} // namespace aFrame


#include "aHelper.inl"
