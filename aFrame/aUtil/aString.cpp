/*******************************************************************************
* \file aString.cpp
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
#include "aString.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aFrame {
namespace aUtil {

using namespace std;


/*******************************************************************************
* aString::aString
*******************************************************************************/
aString::aString()
{
} // aString::aString


/*******************************************************************************
* aString::aString
*******************************************************************************/
aString::aString(const aString &_str)
{
    m_str = _str.m_str;
} // aString::aString


/*******************************************************************************
* aString::aString
*******************************************************************************/
aString::aString(const char *_pStr)
{
    std::wstring_convert<std::codecvt_utf8_utf16<char16_t>, char16_t> utf16conv;
    m_str = utf16conv.from_bytes(_pStr);
} // aString::aString


/*******************************************************************************
* aString::aString
*******************************************************************************/
aString::aString(const c16 *_pStr)
: m_str(_pStr)
{
} // aString::aString


/*******************************************************************************
* aString::aString
*******************************************************************************/
aString::aString(const std::u16string &_str)
: m_str(_str)
{
} // aString::aString


/*******************************************************************************
* aString::aString
*******************************************************************************/
aString::aString(const std::string &_str)
{
    std::wstring_convert<std::codecvt_utf8_utf16<char16_t>, char16_t> converter;
    m_str = converter.from_bytes(_str);
} // aString::aString


/*******************************************************************************
* aString::~aString
*******************************************************************************/
aString::~aString()
{
} // aString::~aString


/*******************************************************************************
* aString::operator=
*******************************************************************************/
aString& aString::operator=(const aString &_str)
{
    m_str = _str.m_str;

    return *this;
} // aString::operator=


/*******************************************************************************
* aString::operator=
*******************************************************************************/
aString& aString::operator=(const std::u16string &_str)
{
    m_str = _str;

    return *this;
} // aString::operator=


/*******************************************************************************
* aString::operator=
*******************************************************************************/
aString& aString::operator=(const std::string &_str)
{
    std::wstring_convert<std::codecvt_utf8_utf16<char16_t>, char16_t> converter;
    m_str = converter.from_bytes(_str);

    return *this;
} // aString::operator=


/*******************************************************************************
* aString::operator=
*******************************************************************************/
aString& aString::operator=(const char *_pStr)
{
    std::wstring_convert<std::codecvt_utf8_utf16<char16_t>, char16_t> converter;
    m_str = converter.from_bytes(_pStr);

    return *this;
} // aString::operator=


/*******************************************************************************
* aString::operator<
*******************************************************************************/
bool aString::operator<(const aString &_str) const
{
    return m_str < _str.m_str;
} // aString::operator<


/*******************************************************************************
* aString::operator+=
*******************************************************************************/
aString& aString::operator+=(const char *_pStr)
{
    m_str += aString(_pStr).m_str;

    return *this;
} // aString::operator+=


/*******************************************************************************
* aString::operator+=
*******************************************************************************/
aString& aString::operator+=(const c16 *_pStr)
{
    m_str += aString(_pStr).m_str;

    return *this;
} // aString::operator+=


/*******************************************************************************
* aString::operator+=
*******************************************************************************/
aString& aString::operator+=(const c16 _c)
{
    m_str += _c;

    return *this;
} // aString::operator+=


/*******************************************************************************
* aString::operator+=
*******************************************************************************/
aString& aString::operator+=(const aString &_str)
{
    m_str += _str.m_str;

    return *this;
} // aString::operator+=


/*******************************************************************************
* aString::operator+
*******************************************************************************/
aString aString::operator+(const char *_pStr) const
{
    return m_str + aString(_pStr).m_str;
} // aString::operator+


/*******************************************************************************
* aString::operator+
*******************************************************************************/
aString aString::operator+(const c16 *_pStr)const
{
    return m_str + aString(_pStr).m_str;
} // aString::operator+


/*******************************************************************************
* aString::operator+
*******************************************************************************/
aString aString::operator+(const aString &_str)const
{
    return m_str + _str.m_str;;
} // aString::operator+


/*******************************************************************************
* aString::operator==
*******************************************************************************/
bool aString::operator==(const aString &_rhs) const
{
    return m_str == _rhs.m_str;
} // aString::operator==


/*******************************************************************************
* aString::operator==
*******************************************************************************/
bool aString::operator==(const char *_pStr) const
{
    return to_stdString().compare(_pStr) == 0;
} // aString::operator==


/*******************************************************************************
* aString::operator!=
*******************************************************************************/
bool aString::operator!=(const char *_pStr) const
{
    return to_stdString().compare(_pStr) != 0;
} // aString::operator!=


/*******************************************************************************
* aString::fromValue
*******************************************************************************/
aString aString::fromValue(s8 _s8Val)
{
    return std::to_string(_s8Val).c_str();
} // aString::fromValue


/*******************************************************************************
* aString::fromValue
*******************************************************************************/
aString aString::fromValue(s16 _s16Val)
{
    return std::to_string(_s16Val).c_str();
} // aString::fromValue


/*******************************************************************************
* aString::fromValue
*******************************************************************************/
aString aString::fromValue(s32 _s32Val)
{
    return std::to_string(_s32Val).c_str();
} // aString::fromValue


/*******************************************************************************
* aString::fromValue
*******************************************************************************/
aString aString::fromValue(s64 _s64Val)
{
    return std::to_string(_s64Val).c_str();
} // aString::fromValue


/*******************************************************************************
* aString::fromValue
*******************************************************************************/
aString aString::fromValue(u8 _u8Val)
{
    return std::to_string(_u8Val).c_str();
} // aString::fromValue


/*******************************************************************************
* aString::fromValue
*******************************************************************************/
aString aString::fromValue(u16 _u16Val)
{
    return std::to_string(_u16Val).c_str();
} // aString::fromValue


/*******************************************************************************
* aString::fromValue
*******************************************************************************/
aString aString::fromValue(u32 _u32Val)
{
    return std::to_string(_u32Val).c_str();
} // aString::fromValue


/*******************************************************************************
* aString::fromValue
*******************************************************************************/
aString aString::fromValue(u64 _u64Val)
{
    return std::to_string(_u64Val).c_str();
} // aString::fromValue


/*******************************************************************************
* aString::fromValue
*******************************************************************************/
aString aString::fromValue(flt _fVal)
{
    return std::to_string(_fVal).c_str();
} // aString::fromValue


/*******************************************************************************
* aString::fromValue
*******************************************************************************/
aString aString::fromValue(dbl _dVal)
{
    return std::to_string(_dVal).c_str();
} // aString::fromValue


/*******************************************************************************
* aString::fromValue
*******************************************************************************/
aString aString::fromValue(ldbl _ldVal)
{
    return std::to_string(_ldVal).c_str();
} // aString::fromValue


/*******************************************************************************
* aString::to_s8
*******************************************************************************/
s8 aString::to_s8() const
{
    return std::stoi(to_stdString());
} // aString::to_s8


/*******************************************************************************
* aString::to_s16
*******************************************************************************/
s16 aString::to_s16() const
{
    return std::stoi(to_stdString());
} // aString::to_s16


/*******************************************************************************
* aString::to_s32
*******************************************************************************/
s32 aString::to_s32() const
{
    return std::stol(to_stdString());
} // aString::to_s32


/*******************************************************************************
* aString::to_s64
*******************************************************************************/
s64 aString::to_s64() const
{
    return std::stoll(to_stdString());
} // aString::to_s64


/*******************************************************************************
* aString::to_u8
*******************************************************************************/
u8 aString::to_u8() const
{
    return std::stoul(to_stdString());
} // aString::to_u8


/*******************************************************************************
* aString::to_u16
*******************************************************************************/
u16 aString::to_u16() const
{
    return std::stoul(to_stdString());
} // aString::to_u16


/*******************************************************************************
* aString::to_u32
*******************************************************************************/
u32 aString::to_u32() const
{
    return std::stoull(to_stdString());
} // aString::to_u32


/*******************************************************************************
* aString::to_u64
*******************************************************************************/
u64 aString::to_u64() const
{
    return std::stoull(to_stdString());
} // aString::to_u64


/*******************************************************************************
* aString::to_flt
*******************************************************************************/
flt aString::to_flt() const
{
    return std::stof(to_stdString());
} // aString::to_flt


/*******************************************************************************
* aString::to_dbl
*******************************************************************************/
dbl aString::to_dbl() const
{
    return std::stod(to_stdString());
} // aString::to_dbl


/*******************************************************************************
* aString::to_ldbl
*******************************************************************************/
ldbl aString::to_ldbl() const
{
    return std::stold(to_stdString());
} // aString::to_ldbl


/*******************************************************************************
* aString::to_stdU16String
*******************************************************************************/
const std::u16string& aString::to_stdU16String() const
{
    return m_str;
} // aString::to_stdU16String


/*******************************************************************************
* aString::to_stdString
*******************************************************************************/
std::string aString::to_stdString() const
{
    std::wstring_convert<std::codecvt_utf8_utf16<char16_t>,char16_t> convert;

    return convert.to_bytes(m_str);
} // aString::to_stdString


/*******************************************************************************
* aString::c_str
*******************************************************************************/
const char* aString::c_str() const
{
    std::wstring_convert<std::codecvt_utf8_utf16<char16_t>,char16_t> convert;

    return convert.to_bytes(m_str).c_str();
} // aString::c_str


/*******************************************************************************
* aString::empty
*******************************************************************************/
bool aString::empty() const
{
    return m_str.empty();
} // aString::empty


/*******************************************************************************
* aString::size
*******************************************************************************/
s32 aString::size() const
{
    return m_str.length();
} // aString::size


/*******************************************************************************
* aString::length
*******************************************************************************/
s32 aString::length() const
{
    return m_str.length();
} // aString::length


/*******************************************************************************
* aString::at
*******************************************************************************/
c16 aString::at(s32  _s32Pos) const
{
    return m_str.at(_s32Pos);
} // aString::at


/*******************************************************************************
* aString::left
*******************************************************************************/
aString aString::left(s32  _n) const
{
    return m_str.substr(0, _n);
} // aString::left


/*******************************************************************************
* aString::find
*******************************************************************************/
size_t aString::find(c16 _c) const
{
    return m_str.find(_c);
} // aString::find


/*******************************************************************************
* aString::contains
*******************************************************************************/
bool aString::contains(const char *_pSubStr) const
{
    // UTF-8 zu UTF-16 Konvertierung
    std::wstring_convert<std::codecvt_utf8_utf16<char16_t>, char16_t> converter;
    std::u16string u16SubStr = converter.from_bytes(_pSubStr);

    return m_str.find(u16SubStr) != std::u16string::npos;
} // aString::contains


/*******************************************************************************
* aString::splitString
*******************************************************************************/
void aString::splitString(const aString     _sDelim, // e.g. "|@-" => this split at | or @ or -
                          vector<aString>   &_vecToken) const
{
    aString 				sToken;
    string::size_type		pos			= 0;
    string::size_type		sizLen		= m_str.size();

    while (pos < sizLen)
    {
        sToken = ""; // init/clear the token buffer

        // copy character until delimiter or end of string is reached
        while ((pos < sizLen) && (_sDelim.find(at(pos)) == std::string::npos))
        {
            sToken += at(pos);
            pos++;
        }

        // at this point pos points to a delimiter or to npos
        pos++;

        // sToken could just be a delimiter
        if (sToken.size() > 0)
        {
            _vecToken.push_back(sToken);
        }
    } // while (pos < sizLen)

} // qString::splitString


#ifdef _USE_QT_
    /*******************************************************************************
    * aString::fromQString
    *******************************************************************************/
    aString aString::fromQString(const QString &_str)
    {
        return aString(_str.toStdU16String());
    } // aString::fromQString


    /*******************************************************************************
    * aString::toQString
    *******************************************************************************/
    QString aString::toQString() const
    {
        return QString::fromStdU16String(to_stdU16String());
    } // aString::toQString
#endif // _USE_QT_


/*******************************************************************************
* operator<<
*******************************************************************************/
std::ostream& operator<<(std::ostream       &_os,
                         aString const    &_str)
{
    std::wstring_convert<std::codecvt_utf8<char16_t>, char16_t> utf16conv;

    return _os << utf16conv.to_bytes(_str.m_str);
} // operator<<


} // namespace aUtil
} // namespace aFrame
