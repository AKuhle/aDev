/*******************************************************************************
* \file aVarPool.h
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
* include
*******************************************************************************/
#include "aUtil_def.h"

#include "aVector.h"

#include "aPoolVarBool.h"
#include "aPoolVarColor.h"
#include "aPoolVarDbl.h"
#include "aPoolVarS64.h"
#include "aPoolVarString.h"
#include "aPoolVarU64.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aUtil {


/*******************************************************************************
* forward
*******************************************************************************/
//class qJsonValue;


/*******************************************************************************
* class aVarPool
*******************************************************************************/
class aVarPool
{
    protected:
        std::map<u32, aPoolVarBool>     m_mapBool;
        std::map<u32, aPoolVarColor>    m_mapColor;
        std::map<u32, aPoolVarDbl>		m_mapDbl;
        std::map<u32, aPoolVarS64>		m_mapS64;
        std::map<u32, aPoolVarString>	m_mapString;
        std::map<u32, aPoolVarU64>      m_mapU64;

    public:
        aVarPool();
        aVarPool(const aVarPool &_rhs);
        virtual ~aVarPool();

        aVarPool&               operator=(const aVarPool &_rhs);

        virtual bool            writeToJsonFile(const aPath &_sFilePath) const;
        virtual bool            readFromJsonFile(const aPath &_sFilePath);

        virtual void            clearAllEntries();

        // has...
        bool                    hasBool(u32 _u32ID) const                                   { return hasVar<aPoolVarBool>   (m_mapBool, _u32ID); }
        bool                    hasColor(u32 _u32ID) const                                  { return hasVar<aPoolVarColor>  (m_mapColor, _u32ID); }
        bool                    hasDbl(u32 _u32ID) const                                    { return hasVar<aPoolVarDbl>    (m_mapDbl, _u32ID); }
        bool                    hasS64(u32 _u32ID) const                                    { return hasVar<aPoolVarS64>    (m_mapS64, _u32ID); }
        bool                    hasString(u32 _u32ID) const                                 { return hasVar<aPoolVarString> (m_mapString, _u32ID); }
        bool                    hasU64(u32 _u32ID) const                                    { return hasVar<aPoolVarU64>    (m_mapU64, _u32ID); }

        // add without min/max...
        void					addBool(u32 _id, bool _val, bool _def)                      { addVal<aPoolVarBool, bool> (m_mapBool, _id, _val, _def); }
        void					addColor(u32 _id, aColor _val, aColor _def)                 { addVal<aPoolVarColor, aColor> (m_mapColor, _id, _val, _def); }
        void					addDbl(u32 _id, dbl _val, dbl _def)                         { addVal<aPoolVarDbl, dbl> (m_mapDbl, _id, _val, _def); }
        void					addS64(u32 _id, s64 _val, s64 _def)                         { addVal<aPoolVarS64, s64> (m_mapS64, _id, _val, _def); }
        void					addString(u32 _id, aString _val, aString _def)              { addVal<aPoolVarString, aString> (m_mapString, _id, _val, _def); }
        void					addU64(u32 _id, u64 _val, u64 _def)                         { addVal<aPoolVarU64, u64> (m_mapU64, _id, _val, _def); }

        // add with min/max...
        void					addDbl(u32 _id, dbl _val, dbl _def, dbl _min, dbl _max)     { addVal<aPoolVarDbl, dbl> (m_mapDbl, _id, _val, _def, _min, _max); }
        void					addS64(u32 _id, s64 _val, s64 _def, s64 _min, s64 _max)     { addVal<aPoolVarS64, s64> (m_mapS64, _id, _val, _def, _min, _max); }
        void					addU64(u32 _id, u64 _val, u64 _def, u64 _min, u64 _max)     { addVal<aPoolVarU64, u64> (m_mapU64, _id, _val, _def, _min, _max); }

        // get...
        bool					getBool(u32 _u32ID) const                                   { return getVal<aPoolVarBool, bool> (m_mapBool, _u32ID, false); }
        aColor					getColor(u32 _u32ID) const                                  { return getVal<aPoolVarColor, aColor> (m_mapColor, _u32ID, colBlack); }
        dbl                     getDbl(u32 _u32ID) const                                    { return getVal<aPoolVarDbl, dbl> (m_mapDbl, _u32ID, 0); }
        s64                     getS64(u32 _u32ID) const                                    { return getVal<aPoolVarS64, s32> (m_mapS64, _u32ID, 0); }
        aString					getString(u32 _u32ID) const                                 { return getVal<aPoolVarString, aString> (m_mapString, _u32ID, ""); }
        u64                     getU64(u32 _u32ID) const                                    { return getVal<aPoolVarU64, u32> (m_mapU64, _u32ID, 0); }

    private:
        // set value
        void                    setVal(u32 _id, bool _val)                                  { setValue<aPoolVarBool, bool> (m_mapBool, _id, _val); }
        void                    setVal(u32 _id, dbl _val)                                   { setValue<aPoolVarDbl, dbl> (m_mapDbl, _id, _val); }
        void                    setVal(u32 _id, s64 _val)                                   { setValue<aPoolVarS64, s64> (m_mapS64, _id, _val); }
        void                    setVal(u32 _id, aString _val)                               { setValue<aPoolVarString, aString> (m_mapString, _id, _val); }
        void                    setVal(u32 _id, u64 _val)                                   { setValue<aPoolVarU64, u64> (m_mapU64, _id, _val); }

        // set default value
        void                    setDefVal(u32 _id, bool _def)                               { setDefValue<aPoolVarBool, bool> (m_mapBool, _id, _def); }
        void                    setDefVal(u32 _id, dbl _val)                                { setDefValue<aPoolVarDbl, dbl> (m_mapDbl, _id, _val); }
        void                    setDefVal(u32 _id, s64 _val)                                { setDefValue<aPoolVarS64, s64> (m_mapS64, _id, _val); }
        void                    setDefVal(u32 _id, aString _def)                            { setDefValue<aPoolVarString, aString> (m_mapString, _id, _def); }
        void                    setDefVal(u32 _id, u64 _val)                                { setDefValue<aPoolVarU64, u64> (m_mapU64, _id, _val); }

        // set min value
        void                    setMinVal(u32 _id, dbl _val)                                { setMinValue<aPoolVarDbl, dbl> (m_mapDbl, _id, _val); }
        void                    setMinVal(u32 _id, s64 _val)                                { setMinValue<aPoolVarS64, s64> (m_mapS64, _id, _val); }
        void                    setMinVal(u32 _id, u64 _val)                                { setMinValue<aPoolVarU64, u64> (m_mapU64, _id, _val); }

        // set max value
        void                    setMaxVal(u32 _id, dbl _val)                                { setMaxValue<aPoolVarDbl, dbl> (m_mapDbl, _id, _val); }
        void                    setMaxVal(u32 _id, s64 _val)                                { setMaxValue<aPoolVarS64, s64> (m_mapS64, _id, _val); }
        void                    setMaxVal(u32 _id, u64 _val)                                { setMaxValue<aPoolVarU64, u64> (m_mapU64, _id, _val); }

        // set minMax value
        void                    setDblMinMax(u32 _id, bool _val)                            { setMinMax<aPoolVarDbl> (m_mapDbl, _id, _val); }
        void                    setS64MinMax(u32 _id, bool _val)                            { setMinMax<aPoolVarS64> (m_mapS64, _id, _val); }
        void                    setU64MinMax(u32 _id, bool _val)                            { setMinMax<aPoolVarU64> (m_mapU64, _id, _val); }

        // col values
        void                    setValR(u32 _id, dbl _val)                                  { createColor(_id); m_mapColor.find(_id)->second.val().r() = _val;}
        void                    setValG(u32 _id, dbl _val)                                  { createColor(_id); m_mapColor.find(_id)->second.val().g() = _val;}
        void                    setValB(u32 _id, dbl _val)                                  { createColor(_id); m_mapColor.find(_id)->second.val().b() = _val;}
        void                    setValA(u32 _id, dbl _val)                                  { createColor(_id); m_mapColor.find(_id)->second.val().a() = _val;}

        void                    setDefR(u32 _id, dbl _val)                                  { createColor(_id); m_mapColor.find(_id)->second.defVal().r() = _val;}
        void                    setDefG(u32 _id, dbl _val)                                  { createColor(_id); m_mapColor.find(_id)->second.defVal().g() = _val;}
        void                    setDefB(u32 _id, dbl _val)                                  { createColor(_id); m_mapColor.find(_id)->second.defVal().b() = _val;}
        void                    setDefA(u32 _id, dbl _val)                                  { createColor(_id); m_mapColor.find(_id)->second.defVal().a() = _val;}

        virtual void            JsonCallback(const aVector<aString> &_vecKeys,
                                             const aJsonValue       &_value);

        template <class poolVarT>
        bool hasVar(const std::map<u32, poolVarT>   &_map,
                    u32                             _id) const
        {
            return _map.find(_id) != _map.end();
        }

        template <class poolVarT, class valT>
        void addVal(std::map<u32, poolVarT> &_map,
                    u32                     _id,
                    const valT              &_val,
                    const valT              &_def)
        {
            if (!hasVar(_map, _id))
            {
                _map.insert(std::make_pair(_id, poolVarT(_val, _def)));
            }
        }

        template <class poolVarT, class valT>
        void addVal(std::map<u32, poolVarT> &_map,
                    u32                     _id,
                    const valT              &_val,
                    const valT              &_def,
                    const valT              &_min,
                    const valT              &_max)
        {
            if (!hasVar(_map, _id))
            {
                _map.insert(std::make_pair(_id, poolVarT(_val, _def, _min, _max)));
            }
        }

        template <class poolVarT, class valT>
        void setValue(std::map<u32, poolVarT> &_map,
                      u32                     _id,
                      const valT              &_val)
        {
            auto cit = _map.find(_id);

            if (cit != _map.end())
            {
                // pool var exists => change the value
                cit->second.val() = _val;
            }
            else
            {
                // pool var doesn't exist => create a new one
                _map.insert(std::make_pair(_id, poolVarT(_val, _val)));
            }
        }

        template <class poolVarT, class valT>
        void setDefValue(std::map<u32, poolVarT> &_map,
                         u32                     _id,
                         const valT              &_def)
        {
            auto cit = _map.find(_id);

            if (cit != _map.end())
            {
                // pool var exists => change the value
                cit->second.defVal() = _def;
            }
            else
            {
                // pool var doesn't exist => create a new one
                _map.insert(std::make_pair(_id, poolVarT(_def, _def)));
            }
        }

        template <class poolVarT, class valT>
        void setMinValue(std::map<u32, poolVarT> &_map,
                         u32                     _id,
                         const valT              &_min)
        {
            auto cit = _map.find(_id);

            if (cit != _map.end())
            {
                // pool var exists => change the value
                cit->second.minVal() = _min;
            }
            else
            {
                // pool var doesn't exist => create a new one
                _map.insert(std::make_pair(_id, poolVarT(_min, _min, _min, _min)));
            }
        }

        template <class poolVarT, class valT>
        void setMaxValue(std::map<u32, poolVarT> &_map,
                         u32                     _id,
                         const valT              &_max)
        {
            auto cit = _map.find(_id);

            if (cit != _map.end())
            {
                // pool var exists => change the value
                cit->second.minVal() = _max;
            }
            else
            {
                // pool var doesn't exist => create a new one
                _map.insert(std::make_pair(_id, poolVarT(_max, _max, _max, _max)));
            }
        }

        template <class poolVarT>
        void setMinMax(std::map<u32, poolVarT>  &_map,
                       u32                      _id,
                       const bool               &_bMinMax)
        {
            auto cit = _map.find(_id);

            if (cit != _map.end())
            {
                // pool var exists => change the value
                cit->second.minMax() = _bMinMax;
            }
            else
            {
                // pool var doesn't exist => create a new one
                _map.insert(std::make_pair(_id, poolVarT(0, 0, 0, 0)));
            }
        }

        void createColor(u32 _id)
        {
            if (m_mapColor.find(_id) == m_mapColor.end())
            {
                m_mapColor.insert(std::make_pair(_id, aPoolVarColor(colBlack, colBlack)));
            }
        }

        template <class poolVarT, class valT>
        valT getVal(const std::map<u32, poolVarT>   &_map,
                    u32                             _id,
                    const valT                      &_def) const
        {
            auto cit = _map.find(_id);

            if (cit != _map.end())
            {
                return cit->second.val();
            }

            return _def;
        }

}; // class aVarPool


} // namespace aUtil
} // namespace aLib
