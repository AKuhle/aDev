/*******************************************************************************
* \file aJsonFile.cpp
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
#ifdef _USE_QT_


/*******************************************************************************
* includes
*******************************************************************************/
#include "aJsonFile.h"
#include <fstream>
#include <sstream>

using namespace std;

namespace aFrame {
namespace aUtil {


/*******************************************************************************
* aJsonFile::aJsonFile
*******************************************************************************/
aJsonFile::aJsonFile()
{
} // aJsonFile::aJsonFile


/*******************************************************************************
* aJsonFile::~aJsonFile
*******************************************************************************/
aJsonFile::~aJsonFile()
{
} // aJsonFile::~aJsonFile


/*******************************************************************************
* aJsonFile::addValue
*******************************************************************************/
void aJsonFile::addValue(const aString  &_sKey,
                         int            _iValue)
{
    auto keys = splitKey(_sKey.to_stdString());

    *getOrCreate(keys) = _iValue;
} // aJsonFile::addValue


/*******************************************************************************
* aJsonFile::addValue
*******************************************************************************/
void aJsonFile::addValue(const aString  &_sKey,
                         double         _dValue)
{
    auto keys = splitKey(_sKey.to_stdString());

    *getOrCreate(keys) = _dValue;
} // aJsonFile::addValue


/*******************************************************************************
* aJsonFile::addValue
*******************************************************************************/
void aJsonFile::addValue(const aString  &_sKey,
                         const aString  &_sValue)
{
    auto keys = splitKey(_sKey.to_stdString());

    *getOrCreate(keys) = _sValue.to_stdString();
} // aJsonFile::addValue


/*******************************************************************************
* aJsonFile::addValue
*******************************************************************************/
void aJsonFile::addValue(const aString              &_sKey,
                         const std::vector<aString> &_vValue)
{
    std::vector<std::string>    vStrings;

    for (auto s : _vValue)
    {
        vStrings.push_back(s.to_stdString());
    }

    auto keys = splitKey(_sKey.to_stdString());

    *getOrCreate(keys) = vStrings;
} // aJsonFile::addValue


/*******************************************************************************
* aJsonFile::readIntValue
*******************************************************************************/
int aJsonFile::readIntValue(const aString  &_sKey) const
{
    auto keys = splitKey(_sKey.to_stdString());

    const Value* v = getValue(keys);

    if (v && std::holds_alternative<int>(*v))
    {
        return std::get<int>(*v);
    }

    return 0;
} // aJsonFile::readIntValue


/*******************************************************************************
* aJsonFile::readDoubleValue
*******************************************************************************/
double aJsonFile::readDoubleValue(const aString  &_sKey) const
{
    auto keys = splitKey(_sKey.to_stdString());

    const Value* v = getValue(keys);

    if (v && std::holds_alternative<double>(*v))
    {
        return std::get<double>(*v);
    }

    return 0.0;
} // aJsonFile::readDoubleValue


/*******************************************************************************
* aJsonFile::readStringValue
*******************************************************************************/
aString aJsonFile::readStringValue(const aString  &_sKey) const
{
    auto keys = splitKey(_sKey.to_stdString());

    const Value *v = getValue(keys);

    if (v && std::holds_alternative<std::string>(*v))
    {
        return std::get<std::string>(*v);
    }

    return "";
} // aJsonFile::readStringValue


/*******************************************************************************
* aJsonFile::readVectorValue
*******************************************************************************/
std::vector<aString> aJsonFile::readVectorValue(const aString  &_sKey) const
{
    auto keys = splitKey(_sKey.to_stdString());

    const Value* v = getValue(keys);

    if (v && std::holds_alternative<std::vector<std::string>>(*v))
    {
        std::vector<std::string>    vS = std::get<std::vector<std::string>>(*v);
        std::vector<aString>        vReturn;

        for (auto s : vS)
        {
            vReturn.push_back(s);
        }

        return vReturn;
    }

    return {};
} // aJsonFile::readVectorValue


/*******************************************************************************
* aJsonFile::writeJsonFile
*******************************************************************************/
bool aJsonFile::writeJsonFile(const aPath &_sPath) const
{
    string sss = _sPath.canonicalPath().to_stdString();
    std::ofstream file(sss);

    if (!file.is_open())
    {
        return false;
    }

    writeJson(file, m_root, 0);
    file.close();

    return true;
} // aJsonFile::writeJsonFile


/*******************************************************************************
* aJsonFile::convertJsonToValue
*******************************************************************************/
namespace {
Value convertJsonToValue(const nlohmann::json& j)
{
    if (j.is_object()) {
        Object obj;
        for (auto it = j.begin(); it != j.end(); ++it)
            obj[it.key()] = convertJsonToValue(it.value());
        return obj;
    } else if (j.is_array()) {
        std::vector<std::string> vec;
        for (const auto& el : j)
            vec.push_back(el.get<std::string>());
        return vec;
    } else if (j.is_string()) {
        return j.get<std::string>();
    } else if (j.is_number_integer()) {
        return j.get<int>();
    } else if (j.is_number_float()) {
        return j.get<double>();
    }
    return {};
}
}


/*******************************************************************************
* aJsonFile::readJsonFile
*******************************************************************************/
bool aJsonFile::readJsonFile(const aPath &_sPath)
{
    std::ifstream file(_sPath.canonicalPath().to_stdString());

    if (!file.is_open())
    {
        return false;
    }

    nlohmann::json j;

    try
    {
        file >> j;
    }
    catch (...)
    {
        file.close();
        return false;
    }

    file.close();

    if (j.is_object())
        m_root = std::get<Object>(convertJsonToValue(j));
    else
        m_root.clear(); // oder Fehlerbehandlung

    return true;
} // aJsonFile::readJsonFile



/*******************************************************************************
* aJsonFile::splitKey
*******************************************************************************/
std::vector<std::string> aJsonFile::splitKey(const std::string &_key)
{
    std::vector<std::string>    result;
    size_t                      start = 0;
    size_t                      end = 0;

    while ((end = _key.find(':', start)) != std::string::npos)
    {
        result.push_back(_key.substr(start, end - start));
        start = end + 1;
    }

    result.push_back(_key.substr(start));

    return result;
} // aJsonFile::splitKey


/*******************************************************************************
* aJsonFile::getOrCreate
*******************************************************************************/
Value* aJsonFile::getOrCreate(std::vector<std::string> &_vKeys)
{
    std::map<std::string, Value>* current = &m_root;

    for (size_t i = 0; i < _vKeys.size() - 1; ++i)
    {
        auto &val = (*current)[_vKeys[i]];

        if (!std::holds_alternative<std::map<std::string, Value>>(val))
        {
            val = std::map<std::string, Value>{};
        }

        current = &std::get<std::map<std::string, Value>>(val);
    }

    return &(*current) [_vKeys.back()];
} // aJsonFile::getOrCreate


/*******************************************************************************
* aJsonFile::getValue
*******************************************************************************/
const Value* aJsonFile::getValue(const std::vector<std::string> &_vKeys) const
{
    const std::map<std::string, Value>* current = &m_root;

    for (size_t i = 0; i < _vKeys.size() - 1; ++i)
    {
        auto it = current->find(_vKeys[i]);

        if (it == current->end() || !std::holds_alternative<std::map<std::string, Value>>(it->second))
        {
            return nullptr;
        }

        current = &std::get<std::map<std::string, Value>>(it->second);
    }

    auto it = current->find(_vKeys.back());

    if (it == current->end())
    {
        return nullptr;
    }

    return &it->second;
} // aJsonFile::getValue


/*******************************************************************************
* aJsonFile::writeJson
*******************************************************************************/
void aJsonFile::writeJson(std::ostream  &os,
                          const Value   &value,
                          int           indent /*= 0*/) const
{
    std::string ind(indent, ' ');
    if (std::holds_alternative<int>(value)) {
        os << std::get<int>(value);
    } else if (std::holds_alternative<double>(value)) {
        os << std::get<double>(value);
    } else if (std::holds_alternative<std::string>(value)) {
        os << '"' << std::get<std::string>(value) << '"';
    } else if (std::holds_alternative<std::vector<std::string>>(value)) {
        os << "[";
        const auto& vec = std::get<std::vector<std::string>>(value);
        for (size_t i = 0; i < vec.size(); ++i) {
            os << '"' << vec[i] << '"';
            if (i + 1 < vec.size()) os << ", ";
        }
        os << "]";
    } else if (std::holds_alternative<std::map<std::string, Value>>(value)) {
        os << "{\n";
        const auto& obj = std::get<std::map<std::string, Value>>(value);
        size_t count = 0;
        for (const auto& pair : obj) {
            os << ind << "  \"" << pair.first << "\": ";
            writeJson(os, pair.second, indent + 2);
            if (++count < obj.size()) os << ",\n";
            else os << "\n";
        }
        os << ind << "}";
    }
} // aJsonFile::writeJson


} // namespace aUtil
} // namespace aFrame


#endif // _USE_QT_

