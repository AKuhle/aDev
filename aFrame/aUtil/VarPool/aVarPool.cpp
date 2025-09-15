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
#include "aString.h"
#include "aColor.h"

using namespace std;


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aFrame {
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
bool aVarPool::writeToJsonFile(const aPath &/*_sFilePath*/) const
{
    return false;

    // aJsonFile       jFile(_sFilePath);
    // bool            bSuccess = false;

    // // add the bools
    // jFile.openLevel();
    // for (auto &poolVar : m_mapBool)
    // {
    //     poolVar.second.add2JsonFile(jFile, poolVar.first);
    // }
    // jFile.closeLevel("bool");

    // // add the s64
    // jFile.openLevel();
    // for (auto &poolVar : m_mapS64)
    // {
    //     poolVar.second.add2JsonFile(jFile, poolVar.first);
    // }
    // jFile.closeLevel("s64");

    // // add the u64
    // jFile.openLevel();
    // for (auto &poolVar : m_mapU64)
    // {
    //     poolVar.second.add2JsonFile(jFile, poolVar.first);
    // }
    // jFile.closeLevel("u64");

    // // add the dbl
    // jFile.openLevel();
    // for (auto &poolVar : m_mapDbl)
    // {
    //     poolVar.second.add2JsonFile(jFile, poolVar.first);
    // }
    // jFile.closeLevel("dbl");

    // // add the strings
    // jFile.openLevel();
    // for (auto &poolVar : m_mapString)
    // {
    //     poolVar.second.add2JsonFile(jFile, poolVar.first);
    // }
    // jFile.closeLevel("string");

    // // add the color
    // jFile.openLevel();
    // for (auto &poolVar : m_mapColor)
    // {
    //     poolVar.second.add2JsonFile(jFile, poolVar.first);
    // }
    // jFile.closeLevel("color");

    // // write the file
    // bSuccess = jFile.write2File();

    // return bSuccess;
} // aVarPool::writeToJsonFile


/*******************************************************************************
* aVarPool::readFromJsonFile
*******************************************************************************/
 bool aVarPool::readFromJsonFile(const aPath &/*_sFilePath*/)
 {
     return false;

    // aJsonFile       jFile(_sFilePath);
    // bool            bSuccess = false;

    // // read all entries
    // bSuccess = jFile.readAllValues([this](const aVector<aString> &_vecKeys, const aJsonValue &_value) { this->JsonValCallback(_vecKeys, _value); },
    //                                [this](const aVector<aString> &_vecKeys, const aJsonObj &_obj) { this->JsonObjCallback(_vecKeys, _obj); }
    // );

    // return bSuccess;
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


} // namespace aUtil
} // namespace aFrame
