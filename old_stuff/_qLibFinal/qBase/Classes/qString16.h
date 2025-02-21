/*******************************************************************************
* \file qString16.h
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

#ifdef _USE_QT_
    #include "QString"
#endif // _USE_QT_


namespace qLib
{
    /*******************************************************************************
    * class qString16
    *******************************************************************************/
    class qString16
    {
        friend std::ostream& operator<<(std::ostream &os, qString16 const &_str);

        private:
            std::u16string      m_str;

        public:
            qString16();
            qString16(const char *_pStr);
            qString16(const c16 *_pStr);
            qString16(const std::u16string &_str);
            virtual ~qString16();

            qString16&              operator=(const std::u16string &_str);

            qString16&              operator+=(const char *_pStr);
            qString16&              operator+=(const c16 *_pStr);
            qString16&              operator+=(const qString16 &_str);

            qString16               operator+(const char *_pStr);
            qString16               operator+(const c16 *_pStr);
            qString16               operator+(const qString16 &_str);

            bool                    operator==(const char *_pStr) const;

            static qString16        FromValue(s8 _s8Val);
            static qString16        FromValue(s16 _s16Val);
            static qString16        FromValue(s32 _s32Val);
            static qString16        FromValue(s64 _s64Val);
            static qString16        FromValue(u8 _u8Val);
            static qString16        FromValue(u16 _u16Val);
            static qString16        FromValue(u32 _u32Val);
            static qString16        FromValue(u64 _u64Val);
            static qString16        FromValue(flt _fVal);
            static qString16        FromValue(dbl _dVal);
            static qString16        FromValue(ldbl _ldVal);

            s8                      To_s8() const;
            s16						To_s16() const;
            s32						To_s32() const;
            s64						To_s64() const;
            u8						To_u8() const;
            u16						To_u16() const;
            u32						To_u32() const;
            u64						To_u64() const;
            flt						To_flt() const;
            dbl						To_dbl() const;
            ldbl					To_ldbl() const;

            const std::u16string&   ToStdU16String() const;

            std::string             ToStdString() const;

            const char*             c_str() const;

            #ifdef _USE_QT_
                static qString16    FromQString(const QString &_str);
                QString             ToQString() const;
            #endif // _USE_QT_
    }; // class qString16


    // global stream member
    std::ostream& operator<<(std::ostream &_os,
                             qString16 const &_str);
} // namespace qLib
