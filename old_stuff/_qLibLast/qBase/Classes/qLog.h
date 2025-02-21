/*******************************************************************************
* \file qLog.h
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
    * enums
    *******************************************************************************/
    enum class enumCoutColor
    {
        black   = 30,
        red     = 31,
        green   = 32,
        yellow  = 33,
        blue    = 34,
        magenta = 35,
        cyan    = 36,
        white   = 37
    }; // enum class enumCoutColor


    /*******************************************************************************
    * forwards
    *******************************************************************************/
    class qString16;


    /*******************************************************************************
    * class qLog
    *******************************************************************************/
    class qLog
    {
        public:
            static void         Log(const char      *_pFunction);

            static void         Log(const char      *_pFunction,
                                    enumCoutColor   _eCoutColor,
                                    const char      *_pText);

            static void         Log(const char      *_pFunction,
                                    enumCoutColor   _eCoutColor,
                                    const char      *_pText,
                                    u64             _u64Value);

            static void         Log(const char      *_pFunction,
                                    enumCoutColor   _eCoutColor,
                                    const char      *_pText,
                                    void            *_pAdress);

            static void         Log(const char      *_pFunction,
                                    enumCoutColor   _eCoutColor,
                                    const char      *_pText1,
                                    u64             _u64Value1,
                                    const char      *_pText2,
                                    u64             _u64Value2);

            static void         Log(enumCoutColor   _eCoutColor,
                                    const qString16 &_sText);

            static void         LogQuad(enumCoutColor   _eCoutColor,
                                        const qString16 &_sText,
                                        s32             _s32_1,
                                        s32             _s32_2,
                                        s32             _s32_3,
                                        s32             _s32_4);

        private:
            static void         SetColor(enumCoutColor   _eCoutColor);
            static void         SetNormColor();
            static void         CoutFunc(const char      *_pFunction);

    }; // class qLog


    /*******************************************************************************
    * macros
    *******************************************************************************/
    #define LogFunc()\
    qLog::Log(__FUNCTION__);

    #define LogPrettyFunc()\
    qLog::Log(__PRETTY_FUNCTION__);

    #define LogToDo(msg)\
    qLog::Log(__PRETTY_FUNCTION__, enumCoutColor::red, (msg));

} // namespace qLib
