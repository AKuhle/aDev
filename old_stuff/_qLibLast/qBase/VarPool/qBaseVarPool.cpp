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
#include "qBaseDefs.h"
#include "qJsonFile.h"
#include "qJsonValue.h"

#include "qBaseVarPool.h"

using namespace std;

namespace qLib
{
    /*******************************************************************************
    * qBaseVarPool::qBaseVarPool
    *******************************************************************************/
    qBaseVarPool::qBaseVarPool()
    {
    } // qBaseVarPool::qBaseVarPool


    /*******************************************************************************
    * qBaseVarPool::qBaseVarPool
    *******************************************************************************/
    qBaseVarPool::qBaseVarPool(const qBaseVarPool		&_rhs)
    : m_mapBool(_rhs.m_mapBool),
      m_mapS32(_rhs.m_mapS32),
      m_mapEnum(_rhs.m_mapEnum)
    {
    } // qBaseVarPool::qBaseVarPool


    /*******************************************************************************
    * qBaseVarPool::~qBaseVarPool
    *******************************************************************************/
    qBaseVarPool::~qBaseVarPool()
    {
    } // qBaseVarPool::~qBaseVarPool


    /*******************************************************************************
    * qBaseVarPool::operator=
    *******************************************************************************/
    qBaseVarPool& qBaseVarPool::operator=(const qBaseVarPool	&_rhs)
    {
        // clear the previous stuff
        ClearAllEntries();

        m_mapBool   = _rhs.m_mapBool;
        m_mapS32    = _rhs.m_mapS32;
        m_mapEnum   = _rhs.m_mapEnum;

        return *this;
    } // qBaseVarPool::operator=


    /*******************************************************************************
    * qBaseVarPool::WriteToJsonFile
    *******************************************************************************/
    bool qBaseVarPool::WriteToJsonFile(const qString16 &_sFilename) const
    {
        qJsonFile       jFile(_sFilename);
        bool            bSuccess = false;

        // add the bools
        jFile.OpenLevel();
        for (auto &poolVar : m_mapBool)
        {
            jFile.OpenLevel();

            jFile.Add(qJsonValue("value", poolVar.second.Value()));
            jFile.Add(qJsonValue("default", poolVar.second.Default()));

            // key for this value is the id of this value
            jFile.CloseLevel(qString16::FromValue(poolVar.first));
        }
        jFile.CloseLevel("bool");

        // add the s32
        jFile.OpenLevel();
        for (auto &poolVar : m_mapS32)
        {
            jFile.OpenLevel();

            jFile.Add(qJsonValue("value", poolVar.second.Value()));
            jFile.Add(qJsonValue("default", poolVar.second.Default()));
            jFile.Add(qJsonValue("min", poolVar.second.Min()));
            jFile.Add(qJsonValue("max", poolVar.second.Max()));

            // key for this value is the id of this value
            jFile.CloseLevel(qString16::FromValue(poolVar.first));
        }
        jFile.CloseLevel("s32");

        // add the enums
        jFile.OpenLevel();
        for (auto &poolVar : m_mapEnum)
        {
            jFile.OpenLevel();

            jFile.Add(qJsonValue("value", poolVar.second.Value()));
            jFile.Add(qJsonValue("default", poolVar.second.Default()));

            // key for this value is the id of this value
            jFile.CloseLevel(qString16::FromValue(poolVar.first));
        }
        jFile.CloseLevel("enum");

        // write the file
        bSuccess = jFile.Write2File();

        return bSuccess;
    } // qBaseVarPool::WriteToJsonFile


    /*******************************************************************************
    * qBaseVarPool::ReadFromJsonFile
    *******************************************************************************/
    bool qBaseVarPool::ReadFromJsonFile(const qString16 &_sFilename)
    {
        qJsonFile       jFile(_sFilename);
        bool            bSuccess = false;

        // read all entries
        bSuccess = jFile.ReadAllValues([this](qVec<qString16> &_vecKeys, qJsonValue &_value) {
            this->JsonCallback(_vecKeys, _value);
        });

        return bSuccess;
    } // qBaseVarPool::ReadFromJsonFile


    /*******************************************************************************
    * qBaseVarPool::ClearAllEntries
    *******************************************************************************/
    void qBaseVarPool::ClearAllEntries()
    {
         m_mapBool.clear();
         m_mapS32.clear();
         m_mapEnum.clear();
    } // qBaseVarPool::ClearAllEntries


    /*******************************************************************************
    * qBaseVarPool::HasBool
    *******************************************************************************/
    bool qBaseVarPool::HasBool(u32 _u32ID) const
    {
        return m_mapBool.find(_u32ID) != m_mapBool.end();
    } // qBaseVarPool::HasBool


    /*******************************************************************************
    * qBaseVarPool::AddBool
    *******************************************************************************/
    void qBaseVarPool::AddBool(u32		_u32ID,
                               bool		_bValue,
                               bool		_bDefault)
    {
        if (!HasBool(_u32ID))
        {
            qPoolVarBool    poolVar(_bValue, _bDefault);
            m_mapBool[_u32ID] = poolVar;
        }
    } // qBaseVarPool::AddBool


    /*******************************************************************************
    * qBaseVarPool::GetBool
    *******************************************************************************/
    bool qBaseVarPool::GetBool(u32 _u32ID) const
    {
        std::map<u32, qPoolVarBool>::const_iterator cit;

        if ((cit = m_mapBool.find(_u32ID)) != m_mapBool.end())
        {
            return cit->second.Value();
        }

        return false;
    } // qBaseVarPool::GetBool


    /*******************************************************************************
    * qBaseVarPool::SetBoolValue
    *******************************************************************************/
    void qBaseVarPool::SetBoolValue(u32     _u32ID,
                                    bool    _bValue)
    {
        std::map<u32, qPoolVarBool>::iterator it;

        if ((it = m_mapBool.find(_u32ID)) != m_mapBool.end())
        {
            it->second.Value() = _bValue;
        }
        else
        {
            AddBool(_u32ID, _bValue, _bValue);
        }
    } // qBaseVarPool::SetBoolValue


    /*******************************************************************************
    * qBaseVarPool::SetBoolDefault
    *******************************************************************************/
    void qBaseVarPool::SetBoolDefault(u32   _u32ID,
                                      bool  _bDefault)
    {
        std::map<u32, qPoolVarBool>::iterator it;

        if ((it = m_mapBool.find(_u32ID)) != m_mapBool.end())
        {
            it->second.Default() = _bDefault;
        }
        else
        {
            AddBool(_u32ID, _bDefault, _bDefault);
        }
    } // qBaseVarPool::SetBoolDefault


    /*******************************************************************************
    * qBaseVarPool::HasS32
    *******************************************************************************/
    bool qBaseVarPool::HasS32(u32 _u32ID) const
    {
        return m_mapS32.find(_u32ID) != m_mapS32.end();
    } // qBaseVarPool::HasS32


    /*******************************************************************************
    * qBaseVarPool::AddS32
    *******************************************************************************/
    void qBaseVarPool::AddS32(u32	_u32ID,
                              s32   _s32Value,
                              s32	_s32Default)
    {
        if (!HasS32(_u32ID))
        {
            qPoolVarS32    poolVar(_s32Value, _s32Default);
            m_mapS32[_u32ID] = poolVar;
        }
    } // qBaseVarPool::AddS32


    /*******************************************************************************
    * qBaseVarPool::AddS32
    *******************************************************************************/
    void qBaseVarPool::AddS32(u32	_u32ID,
                              s32   _s32Value,
                              s32	_s32Default,
                              s32	_s32Min,
                              s32	_s32Max)
    {
        if (!HasS32(_u32ID))
        {
            qPoolVarS32    poolVar(_s32Value, _s32Default, _s32Min, _s32Max);
            m_mapS32[_u32ID] = poolVar;
        }
    } // qBaseVarPool::AddS32


    /*******************************************************************************
    * qBaseVarPool::GetS32
    *******************************************************************************/
    s32 qBaseVarPool::GetS32(u32 _u32ID) const
    {
        std::map<u32, qPoolVarS32>::const_iterator cit;

        if ((cit = m_mapS32.find(_u32ID)) != m_mapS32.end())
        {
            return cit->second.Value();
        }

        return 0;
    } // qBaseVarPool::GetS32


    /*******************************************************************************
    * qBaseVarPool::SetS32Value
    *******************************************************************************/
    void qBaseVarPool::SetS32Value(u32	_u32ID,
                                   s32  _s32Value)
    {
        std::map<u32, qPoolVarS32>::iterator it;

        if ((it = m_mapS32.find(_u32ID)) != m_mapS32.end())
        {
            it->second.Value() = _s32Value;
        }
        else
        {
            AddS32(_u32ID, _s32Value, _s32Value);
        }
    } // qBaseVarPool::SetS32Value


    /*******************************************************************************
    * qBaseVarPool::SetS32Default
    *******************************************************************************/
    void qBaseVarPool::SetS32Default(u32	_u32ID,
                                     s32    _s32Default)
    {
        std::map<u32, qPoolVarS32>::iterator it;

        if ((it = m_mapS32.find(_u32ID)) != m_mapS32.end())
        {
            it->second.Default() = _s32Default;
        }
        else
        {
            AddS32(_u32ID, _s32Default, _s32Default);
        }
    } // qBaseVarPool::SetS32Default


    /*******************************************************************************
    * qBaseVarPool::SetS32Min
    *******************************************************************************/
    void qBaseVarPool::SetS32Min(u32    _u32ID,
                                 s32    _s32Min)
    {
        std::map<u32, qPoolVarS32>::iterator it;

        if ((it = m_mapS32.find(_u32ID)) != m_mapS32.end())
        {
            it->second.Min()    = _s32Min;
            it->second.MinMax() = true;
        }
        else
        {
            AddS32(_u32ID, _s32Min, _s32Min, _s32Min, _s32Min);
        }
    } // qBaseVarPool::SetS32Min


    /*******************************************************************************
    * qBaseVarPool::SetS32Max
    *******************************************************************************/
    void qBaseVarPool::SetS32Max(u32    _u32ID,
                                 s32    _s32Max)
    {
        std::map<u32, qPoolVarS32>::iterator it;

        if ((it = m_mapS32.find(_u32ID)) != m_mapS32.end())
        {
            it->second.Max()    = _s32Max;
            it->second.MinMax() = true;
        }
        else
        {
            AddS32(_u32ID, _s32Max, _s32Max, _s32Max, _s32Max);
        }
    } // qBaseVarPool::SetS32Max


    /*******************************************************************************
    * qBaseVarPool::JsonCallback
    *******************************************************************************/
    void qBaseVarPool::JsonCallback(qVec<qString16>    &_vecKeys,
                                    qJsonValue         &_value)
    {
        s32     s32Size = _vecKeys.size();

        // format, e.g.: bool -> valueID -> valueKey -> value
        // => keys must be al least e.g. bool -> vlaueID
        if (s32Size >= 2)
        {
            s32 id = _vecKeys.at(s32Size - 1).To_u32();

            // check for bool
            if (_vecKeys.at(s32Size - 2) == "bool")
            {
                if (_value.Key() == "value")
                    SetBoolValue(id, _value.ToBool());
                else if (_value.Key() == "default")
                    SetBoolDefault(id, _value.ToBool());
            }

            // check for s32
            if (_vecKeys.at(s32Size - 2) == "s32")
            {
                if (_value.Key() == "value")
                    SetS32Value(id, _value.ToS32());
                else if (_value.Key() == "default")
                    SetS32Default(id, _value.ToS32());
                else if (_value.Key() == "min")
                    SetS32Min(id, _value.ToS32());
                else if (_value.Key() == "max")
                    SetS32Max(id, _value.ToS32());
            }

            // check for enums
            if (_vecKeys.at(s32Size - 2) == "enum")
            {
                if (_value.Key() == "value")
                    SetEnumValue<s32> (id, _value.ToS32());
                else if (_value.Key() == "default")
                    SetEnumDefault<s32> (id, _value.ToS32());
            }
        }
    } // qBaseVarPool::JsonCallback


} // namespace qLib
