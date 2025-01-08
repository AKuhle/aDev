/*******************************************************************************
* \file aString.h
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
#ifdef _USE_QT_
    #include "QString"
#endif // _USE_QT_

#include "aLib_def.h"
#include "aUtil/aUtil_def.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aUtil {


/*******************************************************************************
* class aString
*******************************************************************************/
class aString
{
    friend std::ostream& operator<<(std::ostream &os, aString const &_str);

    private:
        std::u16string      m_str;

    public:
        aString();
        aString(const char *_pStr);
        aString(const c16 *_pStr);
        aString(const std::u16string &_str);
        virtual ~aString();

        aString&                operator=(const std::u16string &_str);

        bool                    operator<(const aString &_str) const;

        aString&                operator+=(const char *_pStr);
        aString&                operator+=(const c16 *_pStr);
        aString&                operator+=(const c16 _c);
        aString&                operator+=(const aString &_str);

        aString                 operator+(const char *_pStr);
        aString                 operator+(const c16 *_pStr);
        aString                 operator+(const aString &_str);

        bool                    operator==(const char *_pStr) const;

        static aString          from_value(s8 _s8Val);
        static aString          from_value(s16 _s16Val);
        static aString          from_value(s32 _s32Val);
        static aString          from_value(s64 _s64Val);
        static aString          from_value(u8 _u8Val);
        static aString          from_value(u16 _u16Val);
        static aString          from_value(u32 _u32Val);
        static aString          from_value(u64 _u64Val);
        static aString          from_value(flt _fVal);
        static aString          from_value(dbl _dVal);
        static aString          from_value(ldbl _ldVal);

        s8                      to_s8() const;
        s16						to_s16() const;
        s32						to_s32() const;
        s64						to_s64() const;
        u8						to_u8() const;
        u16						to_u16() const;
        u32						to_u32() const;
        u64						to_u64() const;
        flt						to_flt() const;
        dbl						to_dbl() const;
        ldbl					to_ldbl() const;

        const std::u16string&   to_stdU16String() const;

        std::string             to_stdString() const;

        const char*             c_str() const;

        bool                    empty() const;

        s32                     size() const;
        s32                     length() const;

        c16                     at(s32  _s32Pos) const;

        size_t                  find(c16 _c) const;

        void                    splitString(const aString       _sDelim,			//!< could be multiple, e.g. "|@-" => this split at | or @ or -
                                            aVector<aString>	&_vecToken) const;

#ifdef _USE_QT_
            static aString      from_QString(const QString &_str);
            QString             to_QString() const;
        #endif // _USE_QT_
}; // class aString


// global stream member
std::ostream& operator<<(std::ostream &_os,
                         aString const &_str);


} // namespace aUtil
} // namespace aLib
