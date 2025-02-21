/*******************************************************************************
* \file qBaseDefs.h
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
* stl includes
*******************************************************************************/
#include <codecvt>
#include <cstdint>
#include <filesystem>
#include <functional>
#include <iostream>
#include <locale>
#include <memory>
#include <string>
#include <cstring>
#include <fstream>
#include <random>

#include <algorithm>
#include <deque>
#include <list>
#include <map>
#include <vector>


namespace qLib
{
    /*******************************************************************************
    * datatypes
    *******************************************************************************/
    using	s8				= std::int8_t;		//!< must be 1 bytes			-128 to 127
	using	s16				= std::int16_t;		//!< must be 2 bytes			-32.768 to 32.767
	using	s32				= std::int32_t;		//!< must be 4 bytes			-2.147.483.648 to 2.147.483.647
	using	s64 			= std::int64_t;		//!< must be 8 bytes			-9.223.372.036.854.775.808 to 9.223.372.036.854.775.807

	using	u8				= std::uint8_t;		//!< must be 1 bytes			0 to 255
	using	u16 			= std::uint16_t;	//!< must be 2 bytes			0 to 65.535
	using	u32 			= std::uint32_t;	//!< must be 4 bytes			0 to 4.294.967.295
	using	u64 			= std::uint64_t;	//!< must be 8 bytes			0 to 18.446.744.073.709.551.615

    using	flt				= float;			//!< must be >= 4 bytes
	using	dbl				= double;			//!< must be >= 8 bytes
    using	ldbl			= long double;		//!< must be >= 12 bytes

	using	c8				= char;				//!< character, must be 1 byte
    using	c16				= char16_t;			//!< must be 2 bytes
    using	c32				= char32_t;			//!< must be 4 bytes

	using	Rgba_t			= float;			//!> data type for class Rgb


    /*******************************************************************************
    * const
    *******************************************************************************/
    #define S8_MIN                  -128
    #define S8_MAX                  127
    #define S16_MIN                 -32768
    #define S16_MAX                 32767
    #define S32_MIN                 -2147483648
    #define S32_MAX                 2147483647
    #define S64_MIN                 -9223372036854775808
    #define S64_MAX                 9223372036854775807

    #define U8_MIN                  o
    #define U8_MAX                  255
    #define U16_MIN                 0
    #define U16_MAX                 65535
    #define U32_MIN                 0
    #define U32_MAX                 4294967295
    #define U64_MIN                 0
    #define U64_MAX                 18446744073709551615

    #define TWO_PI                  6.283185307179586476    // 2 * Pi
    #define PI                      3.141592653589793238    // Pi
    #define PI_2                    1.570796326794896619    // Pi / 2
    #define PI_3                    1.047197551196597746    // Pi / 3
    #define PI_4                    0.785398163397448309    // Pi / 4


    /*******************************************************************************
    * modifiers
    *******************************************************************************/
    #define MODIFIER_NONE			0x0000
    #define MODIFIER_SHIFT			0x0001
    #define MODIFIER_CTRL			0x0002
    #define MODIFIER_ALT			0x0004
    #define MODIFIER_KEYPAD			0x0008


    /*******************************************************************************
    * enums
    *******************************************************************************/
    enum class enumCmdType
    {
        CMD_TYPE_UNDO,                  ///< Commando can be undone
        CMD_TYPE_NO_UNDO				///< Commando can't be undone
    }; // enum class enumCmdType

    enum class enumCmdMsg
    {
        Prepare,
        Do,
        Undo,
        Redo
    };


    /*******************************************************************************
    * macros
    *******************************************************************************/
    #define DELETE0(a)\
    {\
            delete (a);\
            (a) = nullptr;\
    }

    #define CHECK_PRE_CONDITION_VOID(b)\
    {\
            if (!(b))\
        {\
                return;\
        }\
    }

    #define CHECK_PRE_CONDITION(b, r)\
    {\
            if (!(b))\
        {\
                return r;\
        }\
    }


    /*******************************************************************************
    * globale functions
    *******************************************************************************/
    template <class T>
    bool            IsZero(const T		_t1);

    template <class T>
    bool			IsEqual(const T		_t1,
                            const T		_t2);

    template <class T>
    bool			IsUnequal(const T		_t1,
                              const T		_t2);

    template <class T>
    T               Abs(const T		_t);

    template <class T>
    T               Min(const T		_t1,
                        const T		_t2);

    template <class T>
    T               Min(const T		_t1,
                        const T		_t2,
                        const T		_t3);

    template <class T>
    T               Max(const T		_t1,
                        const T		_t2);

    template <class T>
    T               Max(const T		_t1,
                        const T		_t2,
                        const T		_t3);

    template <class T>
    T				Clamp(const T		_tValue,
                          const T		_tMin,
                          const T		_tMax);

    template <class T>
    T				Ceil(const T		_tValue,
                         const T		_tMultiple);

    template <class T>
    void			Swap(T		&_tValue1,
                         T		&_tValue2);

    template<class T>
    void 			SetBits(T		&_tValue,
                            const T	_tBits2Set);

    template<class T>
    void 			ClearBits(T			&_tValue,
                              const T	_tBits2Clear);

    template<class T>
    void 			ToggleBits(T		&_tValue,
                               const T	_tBits2Toggle);

    template<class T>
    bool 			BitsSet(const T	_tValue,
                            const T	_tBits2Check);

    template<class T>
    bool 			BitsClear(const T	_tValue,
                              const T	_tBits2Check);

} // namespace qLib

#include "qBaseDefs.inl"
