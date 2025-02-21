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

#include "qVarPool.h"

using namespace std;

namespace qLib
{
    /*******************************************************************************
    * qVarPool::qVarPool
    *******************************************************************************/
    qVarPool::qVarPool()
    {
    } // qVarPool::qVarPool


    /*******************************************************************************
    * qVarPool::qVarPool
    *******************************************************************************/
    qVarPool::qVarPool(const qVarPool		&_rhs)
    : m_mapBool(_rhs.m_mapBool),
      m_mapS32(_rhs.m_mapS32),
      m_mapDbl(_rhs.m_mapDbl),
      m_mapEnum(_rhs.m_mapEnum),
      m_mapColor(_rhs.m_mapColor)
    {
    } // qVarPool::qVarPool


    /*******************************************************************************
    * qVarPool::~qVarPool
    *******************************************************************************/
    qVarPool::~qVarPool()
    {
    } // qVarPool::~qVarPool


    /*******************************************************************************
    * qVarPool::operator=
    *******************************************************************************/
    qVarPool& qVarPool::operator=(const qVarPool	&_rhs)
    {
        // clear the previous stuff
        ClearAllEntries();

        m_mapBool   = _rhs.m_mapBool;
        m_mapS32    = _rhs.m_mapS32;
        m_mapDbl    = _rhs.m_mapDbl;
        m_mapEnum   = _rhs.m_mapEnum;
        m_mapEnum   = _rhs.m_mapEnum;
        m_mapColor  = _rhs.m_mapColor;

        return *this;
    } // qVarPool::operator=


    /*******************************************************************************
    * qVarPool::WriteToJsonFile
    *******************************************************************************/
    bool qVarPool::WriteToJsonFile(const qString16 &_sFilename) const
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

        // add the dbl
        jFile.OpenLevel();
        for (auto &poolVar : m_mapDbl)
        {
            jFile.OpenLevel();

            jFile.Add(qJsonValue("value", poolVar.second.Value()));
            jFile.Add(qJsonValue("default", poolVar.second.Default()));
            jFile.Add(qJsonValue("min", poolVar.second.Min()));
            jFile.Add(qJsonValue("max", poolVar.second.Max()));

            // key for this value is the id of this value
            jFile.CloseLevel(qString16::FromValue(poolVar.first));
        }
        jFile.CloseLevel("dbl");

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

        // add the Color
        jFile.OpenLevel();
        for (auto &poolVar : m_mapColor)
        {
            jFile.OpenLevel();

            jFile.Add(qJsonValue("valueR", poolVar.second.Value().r));
            jFile.Add(qJsonValue("valueG", poolVar.second.Value().g));
            jFile.Add(qJsonValue("valueB", poolVar.second.Value().b));
            jFile.Add(qJsonValue("valueA", poolVar.second.Value().a));

            jFile.Add(qJsonValue("defaultR", poolVar.second.Default().r));
            jFile.Add(qJsonValue("defaultG", poolVar.second.Default().g));
            jFile.Add(qJsonValue("defaultB", poolVar.second.Default().b));
            jFile.Add(qJsonValue("defaultA", poolVar.second.Default().a));

            jFile.Add(qJsonValue("minR", poolVar.second.Min().r));
            jFile.Add(qJsonValue("minG", poolVar.second.Min().g));
            jFile.Add(qJsonValue("minB", poolVar.second.Min().b));
            jFile.Add(qJsonValue("minA", poolVar.second.Min().a));

            jFile.Add(qJsonValue("maxR", poolVar.second.Max().r));
            jFile.Add(qJsonValue("maxG", poolVar.second.Max().g));
            jFile.Add(qJsonValue("maxB", poolVar.second.Max().b));
            jFile.Add(qJsonValue("maxA", poolVar.second.Max().a));

            // key for this value is the id of this value
            jFile.CloseLevel(qString16::FromValue(poolVar.first));
        }
        jFile.CloseLevel("color");

        // write the file
        bSuccess = jFile.Write2File();

        return bSuccess;
    } // qVarPool::WriteToJsonFile


    /*******************************************************************************
    * qVarPool::ReadFromJsonFile
    *******************************************************************************/
    bool qVarPool::ReadFromJsonFile(const qString16 &_sFilename)
    {
        qJsonFile       jFile(_sFilename);
        bool            bSuccess = false;

        // read all entries
        bSuccess = jFile.ReadAndParseAllValues([this](qVec<qString16> &_vecKeys, qJsonValue &_value) {
            this->JsonCallback(_vecKeys, _value);
        });

        return bSuccess;
    } // qVarPool::ReadFromJsonFile


    /*******************************************************************************
    * qVarPool::ClearAllEntries
    *******************************************************************************/
    void qVarPool::ClearAllEntries()
    {
         m_mapBool.clear();
         m_mapS32.clear();
         m_mapDbl.clear();
         m_mapEnum.clear();
         m_mapColor.clear();
    } // qVarPool::ClearAllEntries


    /*******************************************************************************
    * qVarPool::HasBool
    *******************************************************************************/
    bool qVarPool::HasBool(u32 _u32ID) const
    {
        return m_mapBool.find(_u32ID) != m_mapBool.end();
    } // qVarPool::HasBool


    /*******************************************************************************
    * qVarPool::AddBool
    *******************************************************************************/
    void qVarPool::AddBool(u32		_u32ID,
                               bool		_bValue,
                               bool		_bDefault)
    {
        if (!HasBool(_u32ID))
        {
            qPoolVarBool    poolVar(_bValue, _bDefault);
            m_mapBool[_u32ID] = poolVar;
        }
    } // qVarPool::AddBool


    /*******************************************************************************
    * qVarPool::GetBool
    *******************************************************************************/
    bool qVarPool::GetBool(u32 _u32ID) const
    {
        std::map<u32, qPoolVarBool>::const_iterator cit;

        if ((cit = m_mapBool.find(_u32ID)) != m_mapBool.end())
        {
            return cit->second.Value();
        }

        return false;
    } // qVarPool::GetBool


    /*******************************************************************************
    * qVarPool::SetBoolValue
    *******************************************************************************/
    void qVarPool::SetBoolValue(u32     _u32ID,
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
    } // qVarPool::SetBoolValue


    /*******************************************************************************
    * qVarPool::SetBoolDefault
    *******************************************************************************/
    void qVarPool::SetBoolDefault(u32   _u32ID,
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
    } // qVarPool::SetBoolDefault


    /*******************************************************************************
    * qVarPool::HasS32
    *******************************************************************************/
    bool qVarPool::HasS32(u32 _u32ID) const
    {
        return m_mapS32.find(_u32ID) != m_mapS32.end();
    } // qVarPool::HasS32


    /*******************************************************************************
    * qVarPool::AddS32
    *******************************************************************************/
    void qVarPool::AddS32(u32	_u32ID,
                              s32   _s32Value,
                              s32	_s32Default)
    {
        if (!HasS32(_u32ID))
        {
            qPoolVarS32    poolVar(_s32Value, _s32Default);
            m_mapS32[_u32ID] = poolVar;
        }
    } // qVarPool::AddS32


    /*******************************************************************************
    * qVarPool::AddS32
    *******************************************************************************/
    void qVarPool::AddS32(u32	_u32ID,
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
    } // qVarPool::AddS32


    /*******************************************************************************
    * qVarPool::GetS32
    *******************************************************************************/
    s32 qVarPool::GetS32(u32 _u32ID) const
    {
        std::map<u32, qPoolVarS32>::const_iterator cit;

        if ((cit = m_mapS32.find(_u32ID)) != m_mapS32.end())
        {
            return cit->second.Value();
        }

        return 0;
    } // qVarPool::GetS32


    /*******************************************************************************
    * qVarPool::SetS32Value
    *******************************************************************************/
    void qVarPool::SetS32Value(u32	_u32ID,
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
    } // qVarPool::SetS32Value


    /*******************************************************************************
    * qVarPool::SetS32Default
    *******************************************************************************/
    void qVarPool::SetS32Default(u32	_u32ID,
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
    } // qVarPool::SetS32Default


    /*******************************************************************************
    * qVarPool::SetS32Min
    *******************************************************************************/
    void qVarPool::SetS32Min(u32    _u32ID,
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
    } // qVarPool::SetS32Min


    /*******************************************************************************
    * qVarPool::SetS32Max
    *******************************************************************************/
    void qVarPool::SetS32Max(u32    _u32ID,
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
    } // qVarPool::SetS32Max


    /*******************************************************************************
    * qVarPool::HasDbl
    *******************************************************************************/
    bool qVarPool::HasDbl(u32 _u32ID) const
    {
        return m_mapDbl.find(_u32ID) != m_mapDbl.end();
    } // qVarPool::HasDbl


    /*******************************************************************************
    * qVarPool::AddDbl
    *******************************************************************************/
    void qVarPool::AddDbl(u32	_u32ID,
                              dbl   _dValue,
                              dbl	_dDefault)
    {
        if (!HasDbl(_u32ID))
        {
            qPoolVarDbl    poolVar(_dValue, _dDefault);
            m_mapDbl[_u32ID] = poolVar;
        }
    } // qVarPool::AddDbl


    /*******************************************************************************
    * qVarPool::AddDbl
    *******************************************************************************/
    void qVarPool::AddDbl(u32	_u32ID,
                              dbl   _dValue,
                              dbl	_dDefault,
                              dbl	_dMin,
                              dbl	_dMax)
    {
        if (!HasDbl(_u32ID))
        {
            qPoolVarDbl    poolVar(_dValue, _dDefault, _dMin, _dMax);
            m_mapDbl[_u32ID] = poolVar;
        }
    } // qVarPool::AddDbl


    /*******************************************************************************
    * qVarPool::GetDbl
    *******************************************************************************/
    dbl qVarPool::GetDbl(u32 _u32ID) const
    {
        std::map<u32, qPoolVarDbl>::const_iterator cit;

        if ((cit = m_mapDbl.find(_u32ID)) != m_mapDbl.end())
        {
            return cit->second.Value();
        }

        return 0;
    } // qVarPool::GetDbl


    /*******************************************************************************
    * qVarPool::SetDblValue
    *******************************************************************************/
    void qVarPool::SetDblValue(u32	_u32ID,
                                   dbl  _dValue)
    {
        std::map<u32, qPoolVarDbl>::iterator it;

        if ((it = m_mapDbl.find(_u32ID)) != m_mapDbl.end())
        {
            it->second.Value() = _dValue;
        }
        else
        {
            AddDbl(_u32ID, _dValue, _dValue);
        }
    } // qVarPool::SetDblValue


    /*******************************************************************************
    * qVarPool::SetDblDefault
    *******************************************************************************/
    void qVarPool::SetDblDefault(u32	_u32ID,
                                     dbl   _dDefault)
    {
        std::map<u32, qPoolVarDbl>::iterator it;

        if ((it = m_mapDbl.find(_u32ID)) != m_mapDbl.end())
        {
            it->second.Default() = _dDefault;
        }
        else
        {
            AddDbl(_u32ID, _dDefault, _dDefault);
        }
    } // qVarPool::SetDblDefault


    /*******************************************************************************
    * qVarPool::SetDblMin
    *******************************************************************************/
    void qVarPool::SetDblMin(u32    _u32ID,
                                 dbl    _dMin)
    {
        std::map<u32, qPoolVarDbl>::iterator it;

        if ((it = m_mapDbl.find(_u32ID)) != m_mapDbl.end())
        {
            it->second.Min()    = _dMin;
            it->second.MinMax() = true;
        }
        else
        {
            AddDbl(_u32ID, _dMin, _dMin, _dMin, _dMin);
        }
    } // qVarPool::SetDblMin


    /*******************************************************************************
    * qVarPool::SetDblMax
    *******************************************************************************/
    void qVarPool::SetDblMax(u32    _u32ID,
                                 dbl    _dMax)
    {
        std::map<u32, qPoolVarDbl>::iterator it;

        if ((it = m_mapDbl.find(_u32ID)) != m_mapDbl.end())
        {
            it->second.Max()    = _dMax;
            it->second.MinMax() = true;
        }
        else
        {
            AddDbl(_u32ID, _dMax, _dMax, _dMax, _dMax);
        }
    } // qVarPool::SetDblMax


    /*******************************************************************************
    * qVarPool::HasColor
    *******************************************************************************/
    bool qVarPool::HasColor(u32 _u32ID) const
    {
        return m_mapColor.find(_u32ID) != m_mapColor.end();
    } // qVarPool::HasColor


    /*******************************************************************************
    * qVarPool::AddColor
    *******************************************************************************/
    void qVarPool::AddColor(u32             _u32ID,
                                const qColor   &_colValue,
                                const qColor   &_colDefault)
    {
        if (!HasColor(_u32ID))
        {
            qPoolVarColor   poolVar(_colValue, _colDefault);
            m_mapColor[_u32ID] = poolVar;
        }
    } // qVarPool::AddColor


    /*******************************************************************************
    * qVarPool::AddColor
    *******************************************************************************/
    void qVarPool::AddColor(u32             _u32ID,
                                const qColor    &_colValue,
                                const qColor    &_colDefault,
                                const qColor    &_colMin,
                                const qColor    &_colMax)
    {
        if (!HasColor(_u32ID))
        {
            qPoolVarColor    poolVar(_colValue, _colDefault, _colMin, _colMax);
            m_mapColor[_u32ID] = poolVar;
        }
    } // qVarPool::AddColor


    /*******************************************************************************
    * qVarPool::GetColor
    *******************************************************************************/
    const qColor& qVarPool::GetColor(u32 _u32ID) const
    {
        static qColor                                Color0;
        std::map<u32, qPoolVarColor>::const_iterator cit;

        if ((cit = m_mapColor.find(_u32ID)) != m_mapColor.end())
        {
            return cit->second.Value();
        }

        return Color0;
    } // qVarPool::GetColor


    /*******************************************************************************
    * qVarPool::SetColorValue
    *******************************************************************************/
    void qVarPool::SetColorValue(u32    _u32ID,
                                     Rgba_t _r,         // if <-1>0 => ignore
                                     Rgba_t _g,
                                     Rgba_t _b,
                                     Rgba_t _a)
    {
        std::map<u32, qPoolVarColor>::iterator  it;

        // create a new color, if it doesn't exist
        if ((it = m_mapColor.find(_u32ID)) == m_mapColor.end())
        {
            AddColor(_u32ID, qColor(), qColor());
        }

        if (_r >= 0)
            it->second.Value().r = _r;

        if (_g >= 0)
            it->second.Value().g = _g;

        if (_b >= 0)
            it->second.Value().b = _b;

        if (_a >= 0)
            it->second.Value().a = _a;
    } // qVarPool::SetColorValue


    /*******************************************************************************
    * qVarPool::SetColorDefault
    *******************************************************************************/
    void qVarPool::SetColorDefault(u32    _u32ID,
                                       Rgba_t _r,         // if <-1>0 => ignore
                                       Rgba_t _g,
                                       Rgba_t _b,
                                       Rgba_t _a)
    {
        std::map<u32, qPoolVarColor>::iterator  it;

        // create a new color, if it doesn't exist
        if ((it = m_mapColor.find(_u32ID)) == m_mapColor.end())
        {
            AddColor(_u32ID, qColor(), qColor());
        }

        if (_r >= 0)
            it->second.Default().r = _r;

        if (_g >= 0)
            it->second.Default().g = _g;

        if (_b >= 0)
            it->second.Default().b = _b;

        if (_a >= 0)
            it->second.Default().a = _a;
    } // qVarPool::SetColorDefault


    /*******************************************************************************
    * qVarPool::SetColorMin
    *******************************************************************************/
    void qVarPool::SetColorMin(u32      _u32ID,
                                   Rgba_t   _r,         // if <-1>0 => ignore
                                   Rgba_t   _g,
                                   Rgba_t   _b,
                                   Rgba_t   _a)
    {
        std::map<u32, qPoolVarColor>::iterator  it;

        // create a new color, if it doesn't exist
        if ((it = m_mapColor.find(_u32ID)) == m_mapColor.end())
        {
            AddColor(_u32ID, qColor(), qColor(), qColor(), qColor());
        }

        if (_r >= 0)
        {
            it->second.Min().r = _r;
            it->second.MinMax() = true;
        }

        if (_g >= 0)
        {
            it->second.Min().g = _g;
            it->second.MinMax() = true;
        }

        if (_b >= 0)
        {
            it->second.Min().b = _b;
            it->second.MinMax() = true;
        }

        if (_a >= 0)
        {
            it->second.Min().a = _a;
            it->second.MinMax() = true;
        }
    } // qVarPool::SetColorMin


    /*******************************************************************************
    * qVarPool::SetColorMax
    *******************************************************************************/
    void qVarPool::SetColorMax(u32      _u32ID,
                                   Rgba_t   _r,         // if <-1>0 => ignore
                                   Rgba_t   _g,
                                   Rgba_t   _b,
                                   Rgba_t   _a)
    {
        std::map<u32, qPoolVarColor>::iterator  it;

        // create a new color, if it doesn't exist
        if ((it = m_mapColor.find(_u32ID)) == m_mapColor.end())
        {
            AddColor(_u32ID, qColor(), qColor(), qColor(), qColor());
        }

        if (_r >= 0)
        {
            it->second.Max().r = _r;
            it->second.MinMax() = true;
        }

        if (_g >= 0)
        {
            it->second.Max().g = _g;
            it->second.MinMax() = true;
        }

        if (_b >= 0)
        {
            it->second.Max().b = _b;
            it->second.MinMax() = true;
        }

        if (_a >= 0)
        {
            it->second.Max().a = _a;
            it->second.MinMax() = true;
        }
    } // qVarPool::SetColorMax


    /*******************************************************************************
    * qVarPool::JsonCallback
    *******************************************************************************/
    void qVarPool::JsonCallback(qVec<qString16>    &_vecKeys,
                                qJsonValue         &_value)
    {
        s32     s32KeySize = _vecKeys.size();

        // format, e.g.: bool -> valueID -> valueKey -> value
        // => keys must be al least e.g. bool -> vlaueID
        if (s32KeySize >= 2)
        {
            s32 id = _vecKeys.at(s32KeySize - 1).To_u32();

            // check for bool
            if (_vecKeys.at(s32KeySize - 2) == "bool")
            {
                if (_value.Key() == "value")
                    SetBoolValue(id, _value.ToBool());
                else if (_value.Key() == "default")
                    SetBoolDefault(id, _value.ToBool());
            }

            // check for s32
            if (_vecKeys.at(s32KeySize - 2) == "s32")
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

            // check for dbl
            if (_vecKeys.at(s32KeySize - 2) == "dbl")
            {
                if (_value.Key() == "value")
                    SetDblValue(id, _value.ToDbl());
                else if (_value.Key() == "default")
                    SetDblDefault(id, _value.ToDbl());
                else if (_value.Key() == "min")
                    SetDblMin(id, _value.ToDbl());
                else if (_value.Key() == "max")
                    SetDblMax(id, _value.ToDbl());
            }

            // check for color
            if (_vecKeys.at(s32KeySize - 2) == "color")
            {
                if (_value.Key() == "valueR")
                    SetColorValue(id, _value.ToDbl(), -1, -1, -1);
                else if (_value.Key() == "valueG")
                    SetColorValue(id, -1, _value.ToDbl(), -1, -1);
                else if (_value.Key() == "valueB")
                    SetColorValue(id, -1, -1, _value.ToDbl(), -1);
                else if (_value.Key() == "valueA")
                    SetColorValue(id, -1, -1, -1, _value.ToDbl());

                else if (_value.Key() == "defaultR")
                    SetColorDefault(id, _value.ToDbl(), -1, -1, -1);
                else if (_value.Key() == "defaultG")
                    SetColorDefault(id, -1, _value.ToDbl(), -1, -1);
                else if (_value.Key() == "defaultB")
                    SetColorDefault(id, -1, -1, _value.ToDbl(), -1);
                else if (_value.Key() == "defaultA")
                    SetColorDefault(id, -1, -1, -1, _value.ToDbl());

                else if (_value.Key() == "minR")
                    SetColorMin(id, _value.ToDbl(), -1, -1, -1);
                else if (_value.Key() == "minG")
                    SetColorMin(id, -1, _value.ToDbl(), -1, -1);
                else if (_value.Key() == "minB")
                    SetColorMin(id, -1, -1, _value.ToDbl(), -1);
                else if (_value.Key() == "minA")
                    SetColorMin(id, -1, -1, -1, _value.ToDbl());

                else if (_value.Key() == "maxR")
                    SetColorMax(id, _value.ToDbl(), -1, -1, -1);
                else if (_value.Key() == "maxG")
                    SetColorMax(id, -1, _value.ToDbl(), -1, -1);
                else if (_value.Key() == "maxB")
                    SetColorMax(id, -1, -1, _value.ToDbl(), -1);
                else if (_value.Key() == "maxA")
                    SetColorMax(id, -1, -1, -1, _value.ToDbl());
            }
        }
    } // qVarPool::JsonCallback


} // namespace qLib
