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
#include "qBaseDefs.h"


namespace qLib
{
    /*******************************************************************************
    * \class MU
    * \brief baseclass for 2D math objects
    *******************************************************************************/
    template <class T>
    class MU
    {
        public:
            static bool     IsZero(const T		_t1);

            static bool     IsEqual(const T		_t1,
                                    const T		_t2);

            static bool     IsUnequal(const T		_t1,
                                      const T		_t2);

            static T        Abs(const T		_t);

            static T        Min(const T		_t1,
                                const T		_t2);

            static T        Min(const T		_t1,
                                const T		_t2,
                                const T		_t3);

            static T        Max(const T		_t1,
                                const T		_t2);

            static  T       Max(const T		_t1,
                                const T		_t2,
                                const T		_t3);

            static  T       Max(const T		_t1,
                                const T		_t2,
                                const T		_t3,
                                const T		_t4);

            static T        Clamp(const T		_tValue,
                                  const T		_tMin,
                                  const T		_tMax);

            static T        Ceil(const T		_tValue,
                                 const T		_tMultiple);

            static void     SetBits(T		&_tValue,
                                    const T	_tBits2Set);

            static void     ClearBits(T			&_tValue,
                                      const T	_tBits2Clear);

            static void     ToggleBits(T		&_tValue,
                                       const T	_tBits2Toggle);

            static bool     AreBitsSet(const T	_tValue,
                                       const T	_tBits2Check);

            static bool     AreBitsClear(const T	_tValue,
                                         const T	_tBits2Check);

    // delete function
    private:
        MU() = delete;
    }; // class MU

} // namespace qLib

#include "qMathUtil.inl"
