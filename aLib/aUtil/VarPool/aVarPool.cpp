/*******************************************************************************
* \file qVarPool.cpp
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
#include "aVarPool.h"
#include "aJsonFile.h"
#include "aJsonValue.h"
#include "aString.h"
#include "aColor.h"

using namespace std;


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aUtil {


/*******************************************************************************
* aVarPool::aVarPool
*******************************************************************************/
aVarPool::aVarPool()
{
} // aVarPool::aVarPool


/*******************************************************************************
* aVarPool::aVarPool
*******************************************************************************/
aVarPool::aVarPool(const aVarPool &_rhs)
: m_mapBool(_rhs.m_mapBool),
  m_mapColor(_rhs.m_mapColor),
  m_mapDbl(_rhs.m_mapDbl),
  m_mapS64(_rhs.m_mapS64),
  m_mapString(_rhs.m_mapString),
  m_mapU64(_rhs.m_mapU64)
{
} // aVarPool::aVarPool


/*******************************************************************************
* aVarPool::~aVarPool
*******************************************************************************/
aVarPool::~aVarPool()
{
} // aVarPool::~aVarPool


/*******************************************************************************
* aVarPool::operator=
*******************************************************************************/
aVarPool& aVarPool::operator=(const aVarPool &_rhs)
{
    // clear the previous stuff
    clearAllEntries();

    m_mapBool   = _rhs.m_mapBool;
    m_mapColor  = _rhs.m_mapColor;
    m_mapDbl    = _rhs.m_mapDbl;
    m_mapS64    = _rhs.m_mapS64;
    m_mapString = _rhs.m_mapString;
    m_mapU64    = _rhs.m_mapU64;

    return *this;
} // aVarPool::operator=


/*******************************************************************************
* aVarPool::writeToJsonFile
*******************************************************************************/
bool aVarPool::writeToJsonFile(const aPath &_sFilePath) const
{
    aJsonFile       jFile(_sFilePath);
    bool            bSuccess = false;

    // add the bools
    jFile.openLevel();
    for (auto &poolVar : m_mapBool)
    {
        poolVar.second.add2JsonFile(jFile, poolVar.first);
    }
    jFile.closeLevel("bool");

    // add the s64
    jFile.openLevel();
    for (auto &poolVar : m_mapS64)
    {
        poolVar.second.add2JsonFile(jFile, poolVar.first);
    }
    jFile.closeLevel("s64");

    // add the u64
    jFile.openLevel();
    for (auto &poolVar : m_mapU64)
    {
        poolVar.second.add2JsonFile(jFile, poolVar.first);
    }
    jFile.closeLevel("u64");

    // add the dbl
    jFile.openLevel();
    for (auto &poolVar : m_mapDbl)
    {
        poolVar.second.add2JsonFile(jFile, poolVar.first);
    }
    jFile.closeLevel("dbl");

    // add the strings
    jFile.openLevel();
    for (auto &poolVar : m_mapString)
    {
        poolVar.second.add2JsonFile(jFile, poolVar.first);
    }
    jFile.closeLevel("string");

    // add the color
    jFile.openLevel();
    for (auto &poolVar : m_mapColor)
    {
        poolVar.second.add2JsonFile(jFile, poolVar.first);
    }
    jFile.closeLevel("color");

    // write the file
    bSuccess = jFile.write2File();

    return bSuccess;
} // aVarPool::writeToJsonFile


/*******************************************************************************
* aVarPool::readFromJsonFile
*******************************************************************************/
 bool aVarPool::readFromJsonFile(const aPath &_sFilePath)
 {
    aJsonFile       jFile(_sFilePath);
    bool            bSuccess = false;

    // read all entries
    bSuccess = jFile.readAllValues([this](const aVector<aString> &_vecKeys, const aJsonValue &_value) {
        this->JsonCallback(_vecKeys, _value);
    });

    return bSuccess;
} // aVarPool::readFromJsonFile


/*******************************************************************************
* aVarPool::clearAllEntries
*******************************************************************************/
void aVarPool::clearAllEntries()
{
    m_mapBool.clear();
    m_mapColor.clear();
    m_mapDbl.clear();
    m_mapS64.clear();
    m_mapString.clear();
    m_mapU64.clear();
} // aVarPool::clearAllEntries


/*******************************************************************************
* aVarPool::JsonCallback
*******************************************************************************/
void aVarPool::JsonCallback(const aVector<aString> &_vecKeys,
                            const aJsonValue       &_value)
{
    s32     s32Size = _vecKeys.size();

//     // format, e.g.: bool -> valueID -> valueKey -> value
//     // => keys must be al least e.g. bool -> vlaueID
    if (s32Size == 2)
    {
        u32 id = _vecKeys.at(1).to_u32();

        // check for bool
        if (_vecKeys.at(0) == "bool")
        {
            if (_value.key() == "value")
                setVal(id, _value.toBool());
            else if (_value.key() == "default")
                setDefVal(id, _value.toBool());
        }

        // check for color
        if (_vecKeys.at(0) == "color")
        {
            if (_value.key() == "valueR")
                setValR(id, _value.toDbl());
            else if (_value.key() == "valueG")
                setValG(id, _value.toDbl());
            else if (_value.key() == "valueB")
                setValB(id, _value.toDbl());
            else if (_value.key() == "valueA")
                setValA(id, _value.toDbl());

            else if (_value.key() == "defaultR")
                setDefR(id, _value.toDbl());
            else if (_value.key() == "defaultG")
                setDefG(id, _value.toDbl());
            else if (_value.key() == "defaultB")
                setDefB(id, _value.toDbl());
            else if (_value.key() == "defaultA")
                setDefA(id, _value.toDbl());
        }

        // check for dbl
        else if (_vecKeys.at(0) == "dbl")
        {
            if (_value.key() == "value")
                setVal(id, _value.toDbl());
            else if (_value.key() == "default")
                setDefVal(id, _value.toDbl());
            else if (_value.key() == "min")
                setMinVal(id, _value.toDbl());
            else if (_value.key() == "max")
                setMaxVal(id, _value.toDbl());
            else if (_value.key() == "minMax")
                setDblMinMax(id, _value.toBool());
        }

        // check for s64
        else if (_vecKeys.at(0) == "s64")
        {
            if (_value.key() == "value")
                setVal(id, _value.toS64());
            else if (_value.key() == "default")
                setDefVal(id, _value.toS64());
            else if (_value.key() == "min")
                setMinVal(id, _value.toS64());
            else if (_value.key() == "max")
                setMaxVal(id, _value.toS64());
            else if (_value.key() == "minMax")
                setS64MinMax(id, _value.toBool());
        }

        // check for string
        else if (_vecKeys.at(0) == "string")
        {
            if (_value.key() == "value")
                setVal(id, _value.toString());
            else if (_value.key() == "default")
                setDefVal(id, _value.toString());
        }

        // check for u64
        else if (_vecKeys.at(0) == "u64")
        {
            if (_value.key() == "value")
                setVal(id, _value.toU64());
            else if (_value.key() == "default")
                setDefVal(id, _value.toU64());
            else if (_value.key() == "min")
                setMinVal(id, _value.toU64());
            else if (_value.key() == "max")
                setMaxVal(id, _value.toU64());
            else if (_value.key() == "minMax")
                setU64MinMax(id, _value.toBool());
        }

    } // if...

} // aVarPool::JsonCallback


} // namespace aUtil
} // namespace aLib
