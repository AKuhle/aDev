/*******************************************************************************
* \file qString16.cpp
* \brief 16 bit strings in the qFrame library
*
* \author Andreas Kuhlewind
*
* $Revision: 69 $
* $LastChangedDate: 2010-08-17 14:10:45 +0200 (Di, 17 Aug 2010) $
* $LastChangedBy: akuhlewi $
*******************************************************************************/


/*******************************************************************************
* includes
*******************************************************************************/
#include <QString>
#include "qString16.h"

namespace qLib
{
    /*******************************************************************************
    * qString16::qString16
    *******************************************************************************/
    qString16::qString16()
    {
    } // qString16::qString16


    /*******************************************************************************
    * qString16::qString16
    *******************************************************************************/
    qString16::qString16(const char* _pStr)
    {
        std::wstring_convert<std::codecvt_utf8_utf16<char16_t>, char16_t> utf16conv;
        m_str = utf16conv.from_bytes(_pStr);
    } // qString16::qString16


    /*******************************************************************************
    * qString16::qString16
    *******************************************************************************/
    qString16::qString16(const c16* _pStr)
    : m_str(_pStr)
    {
    } // qString16::qString16


    /*******************************************************************************
    * qString16::qString16
    *******************************************************************************/
    qString16::qString16(const std::u16string& _str)
    : m_str(_str)
    {
    } // qString16::qString16


    /*******************************************************************************
    * qString16::~qString16
    *******************************************************************************/
    qString16::~qString16()
    {
    } // qString16::~qString16


    /*******************************************************************************
    * qString16::operator=
    *******************************************************************************/
    qString16& qString16::operator=(const std::u16string& _str)
    {
        m_str += _str;

        return *this;
    } // qString16::operator=


    /*******************************************************************************
    * qString16::operator+=
    *******************************************************************************/
    qString16& qString16::operator+=(const char *_pStr)
    {
        m_str += qString16(_pStr).m_str;

        return *this;
    } // qString16::operator+=


    /*******************************************************************************
    * qString16::operator+=
    *******************************************************************************/
    qString16& qString16::operator+=(const c16 *_pStr)
    {
        m_str += qString16(_pStr).m_str;

        return *this;
    } // qString16::operator+=


    /*******************************************************************************
    * qString16::operator+=
    *******************************************************************************/
    qString16& qString16::operator+=(const qString16 &_str)
    {
        m_str += _str.m_str;

        return *this;
    } // qString16::operator+=


    /*******************************************************************************
    * qString16::operator+
    *******************************************************************************/
    qString16 qString16::operator+(const char *_pStr)
    {
        m_str += qString16(_pStr).m_str;

        return *this;
    } // qString16::operator+


    /*******************************************************************************
    * qString16::operator+
    *******************************************************************************/
    qString16 qString16::operator+(const c16 *_pStr)
    {
        m_str += qString16(_pStr).m_str;

        return *this;
    } // qString16::operator+


    /*******************************************************************************
    * qString16::operator+
    *******************************************************************************/
    qString16 qString16::operator+(const qString16 &_str)
    {
        m_str += _str.m_str;

        return *this;
    } // qString16::operator+


    /*******************************************************************************
    * qString16::operator==
    *******************************************************************************/
    bool qString16::operator==(const char *_rhs) const
    {
        return ToStdString().compare(_rhs) == 0;
    } // qString16::operator==


    /*******************************************************************************
    * qString16::operator==
    *******************************************************************************/
    bool qString16::operator==(const qString16 &_rhs) const
    {
        return ToStdString().compare(_rhs.ToStdString()) == 0;
    } // qString16::operator==


    /*******************************************************************************
    * qString16::operator!=
    *******************************************************************************/
    bool qString16::operator!=(const char *_rhs) const
    {
        return ToStdString().compare(_rhs) != 0;
    } // qString16::operator!=


    /*******************************************************************************
    * qString16::operator!=
    *******************************************************************************/
    bool qString16::operator!=(const qString16 &_rhs) const
    {
        return ToStdString().compare(_rhs.ToStdString()) != 0;
    } // qString16::operator!=


    /*******************************************************************************
    * qString16::FromValue
    *******************************************************************************/
    qString16 qString16::FromValue(s8 _s8Val)
    {
        return std::to_string(_s8Val).c_str();
    } // qString16::FromValue


    /*******************************************************************************
    * qString16::FromValue
    *******************************************************************************/
    qString16 qString16::FromValue(s16 _s16Val)
    {
        return std::to_string(_s16Val).c_str();
    } // qString16::FromValue


    /*******************************************************************************
    * qString16::FromValue
    *******************************************************************************/
    qString16 qString16::FromValue(s32 _s32Val)
    {
        return std::to_string(_s32Val).c_str();
    } // qString16::FromValue


    /*******************************************************************************
    * qString16::FromValue
    *******************************************************************************/
    qString16 qString16::FromValue(s64 _s64Val)
    {
        return std::to_string(_s64Val).c_str();
    } // qString16::FromValue


    /*******************************************************************************
    * qString16::FromValue
    *******************************************************************************/
    qString16 qString16::FromValue(u8 _u8Val)
    {
        return std::to_string(_u8Val).c_str();
    } // qString16::FromValue


    /*******************************************************************************
    * qString16::FromValue
    *******************************************************************************/
    qString16 qString16::FromValue(u16 _u16Val)
    {
        return std::to_string(_u16Val).c_str();
    } // qString16::FromValue


    /*******************************************************************************
    * qString16::FromValue
    *******************************************************************************/
    qString16 qString16::FromValue(u32 _u32Val)
    {
        return std::to_string(_u32Val).c_str();
    } // qString16::FromValue


    /*******************************************************************************
    * qString16::FromValue
    *******************************************************************************/
    qString16 qString16::FromValue(u64 _u64Val)
    {
        return std::to_string(_u64Val).c_str();
    } // qString16::FromValue


    /*******************************************************************************
    * qString16::FromValue
    *******************************************************************************/
    qString16 qString16::FromValue(flt _fVal)
    {
        return std::to_string(_fVal).c_str();
    } // qString16::FromValue


    /*******************************************************************************
    * qString16::FromValue
    *******************************************************************************/
    qString16 qString16::FromValue(dbl _dVal)
    {
        return std::to_string(_dVal).c_str();
    } // qString16::FromValue


    /*******************************************************************************
    * qString16::FromValue
    *******************************************************************************/
    qString16 qString16::FromValue(ldbl _ldVal)
    {
        return std::to_string(_ldVal).c_str();
    } // qString16::FromValue


    /*******************************************************************************
    * qString16::To_s8
    *******************************************************************************/
    s8 qString16::To_s8() const
    {
        return std::stoi(ToStdString());
    } // qString16::To_s8


    /*******************************************************************************
    * qString16::To_s16
    *******************************************************************************/
    s16 qString16::To_s16() const
    {
        return std::stoi(ToStdString());
    } // qString16::To_s16


    /*******************************************************************************
    * qString16::To_s32
    *******************************************************************************/
    s32 qString16::To_s32() const
    {
        return std::stol(ToStdString());
    } // qString16::To_s32


    /*******************************************************************************
    * qString16::To_s64
    *******************************************************************************/
    s64 qString16::To_s64() const
    {
        return std::stoll(ToStdString());
    } // qString16::To_s64


    /*******************************************************************************
    * qString16::To_u8
    *******************************************************************************/
    u8 qString16::To_u8() const
    {
        return std::stoul(ToStdString());
    } // qString16::To_u8


    /*******************************************************************************
    * qString16::To_u16
    *******************************************************************************/
    u16 qString16::To_u16() const
    {
        return std::stoul(ToStdString());
    } // qString16::To_u16


    /*******************************************************************************
    * qString16::To_u32
    *******************************************************************************/
    u32 qString16::To_u32() const
    {
        return std::stoull(ToStdString());
    } // qString16::To_u32


    /*******************************************************************************
    * qString16::To_u64
    *******************************************************************************/
    u64 qString16::To_u64() const
    {
        return std::stoull(ToStdString());
    } // qString16::To_u64


    /*******************************************************************************
    * qString16::To_flt
    *******************************************************************************/
    flt qString16::To_flt() const
    {
        return std::stof(ToStdString());
    } // qString16::To_flt


    /*******************************************************************************
    * qString16::To_dbl
    *******************************************************************************/
    dbl qString16::To_dbl() const
    {
        return std::stod(ToStdString());
    } // qString16::To_dbl


    /*******************************************************************************
    * qString16::To_ldbl
    *******************************************************************************/
    ldbl qString16::To_ldbl() const
    {
        return std::stold(ToStdString());
    } // qString16::To_ldbl


    /*******************************************************************************
    * qString16::ToStdU16String
    *******************************************************************************/
    const std::u16string& qString16::ToStdU16String() const
    {
        return m_str;
    } // qString16::ToStdU16String


    /*******************************************************************************
    * qString16::ToStdString
    *******************************************************************************/
    std::string qString16::ToStdString() const
    {
        std::wstring_convert<std::codecvt_utf8_utf16<char16_t>,char16_t> convert;

        return convert.to_bytes(m_str);
    } // qString16::ToStdString


    /*******************************************************************************
    * qString16::c_str
    *******************************************************************************/
    const char* qString16::c_str() const
    {
        std::wstring_convert<std::codecvt_utf8_utf16<char16_t>,char16_t> convert;

        return convert.to_bytes(m_str).c_str();
    } // qString16::c_str


    /*******************************************************************************
    * qString16::FromQString
    *******************************************************************************/
    qString16 qString16::FromQString(const QString &_str)
    {
        return qString16(_str.toStdU16String());
    } // qString16::FromQString


    /*******************************************************************************
    * qString16::ToQString
    *******************************************************************************/
    QString qString16::ToQString() const
    {
        return QString::fromStdU16String(ToStdU16String());
    } // qString16::ToQString


    /*******************************************************************************
    * qString16::Left
    *******************************************************************************/
    qString16 qString16::Left(s32 _s32Len) const
    {
        return m_str.substr(0, _s32Len);
    } // qString16::Left


    /*******************************************************************************
    * qString16::Substr
    *******************************************************************************/
    qString16 qString16::Substr(s32 _s32Pos,
                             s32 _n /*= -1*/) const
    {
        if (_n == -1)
            return m_str.substr(_s32Pos);
        else
            return m_str.substr(_s32Pos, _n);
    } // qString16::Substr


    /*******************************************************************************
    * qString16::Trim
    *******************************************************************************/
    bool qString16::Contains(QChar  _c,
                             bool	_bCaseSensitivity	/*= true*/) const
    {
        if (_bCaseSensitivity)
        {
            return ToQString().contains(_c, Qt::CaseSensitive);
        }
        else
        {
            return ToQString().contains(_c, Qt::CaseInsensitive);
        }
    } // qString16::Contains


    /*******************************************************************************
    * qString16::Trim
    *******************************************************************************/
    void qString16::Trim(const qString16    &_sTrimChars)
    {
        QString s       = ToQString();

        // remove any trim-chars from the beginning
        while (!s.isEmpty() && _sTrimChars.Contains(s.at(0)))
            s.remove(0, 1);

        // remove any trim-chars from the end
        while (!s.isEmpty() && _sTrimChars.Contains(s.at(s.size()-1)))
            s.remove(s.size()-1, 1);
    } // qString16::Trim


    /*******************************************************************************
    * qString16::Trim
    *******************************************************************************/
    u32 qString16::SplitString(const qString16  &_sDelim,			//!< could be multiple, e.g. "|@-" => this split at | or @ or -
                               qVec<qString16>   &_vecToken,
                               bool              _bTrim /*= false*/) const
    {
        QString     s           = ToQString();

        int			iPos		= 0;
        int			iSize		= s.size();

        while (iPos < iSize)
        {
            QString     sToken;

            // set iPos to the next character which is not a delimiter
            while ((iPos < iSize) && (_sDelim.Contains(s.at(iPos))))
                iPos++;

            // leave if end of string is reached
            if (iPos == iSize)
                return _vecToken.size();

            // Save token data
            while ((iPos < iSize) && (!_sDelim.Contains(s.at(iPos))))
                sToken += s.at(iPos++);

            // put valid STR buffer into the supplied list
            if (!sToken.isEmpty())
            {
                qString16   s16Token = qString16::FromQString(sToken);
                if (_bTrim)
                {
                    s16Token.Trim(" ");
                }
                _vecToken.push_back(s16Token);
            }
        } // while (sizLen < sizLen)

        return _vecToken.size();
    } // qString16::SplitString


    /*******************************************************************************
    * operator<<
    *******************************************************************************/
    std::ostream& operator<<(std::ostream       &_os,
                             qString16 const    &_str)
    {
        std::wstring_convert<std::codecvt_utf8<char16_t>, char16_t> utf16conv;

        return _os << utf16conv.to_bytes(_str.m_str);
    } // operator<<

} // namespace qLib
