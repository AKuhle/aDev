/*******************************************************************************
* \file qVarPool.h
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
#include "qMap.h"
#include "qVec.h"
#include "qString16.h"

#include "qPoolVarBool.h"
#include "qPoolVarS32.h"
#include "qPoolVarDbl.h"
#include "qPoolVarColor.h"
// #include "poolVar_string.h"
// #include "poolVar_u32.h"


namespace qLib
{
    /*******************************************************************************
    * forward
    *******************************************************************************/
    class qJsonValue;

    /*******************************************************************************
    * class qVarPool
    *******************************************************************************/
    class qVarPool
	{
        protected:
            qMap<u32, qPoolVarBool>     m_mapBool;
            qMap<u32, qPoolVarS32>      m_mapS32;
            qMap<u32, qPoolVarDbl>      m_mapDbl;
            qMap<u32, qPoolVarS32>      m_mapEnum;
            qMap<u32, qPoolVarColor>    m_mapColor;
            // std::map<u32, PoolVarU32>		m_mapU32;
            // std::map<u32, PoolVarString>	m_mapString;

		public:
            qVarPool();
            qVarPool(const qVarPool &_rhs);
            virtual ~qVarPool();

            qVarPool&           operator=(const qVarPool &_rhs);

            virtual bool            WriteToJsonFile(const qString16 &_sFilename) const;
            virtual bool            ReadFromJsonFile(const qString16 &_sFilename);

            virtual void            ClearAllEntries();

            // member for bool-variables
            bool                    HasBool(u32 _u32ID) const;    // true if poolvariable exists

            void					AddBool(u32     _u32ID,
                                            bool    _bValue,
                                            bool	_bDefault);

            bool					GetBool(u32 _u32ID) const;    // false, if poolvariable not exists

            void					SetBoolValue(u32	_u32ID,
                                                 bool  _bValue);

            void					SetBoolDefault(u32	_u32ID,
                                                   bool   _bDefault);

            // member for s32-variables
            bool                    HasS32(u32 _u32ID) const;    // true if poolvariable exists

            void					AddS32(u32	_u32ID,
                                           s32  _s32Value,
                                           s32	_s32Default);

            void					AddS32(u32	_u32ID,
                                           s32  _s32Value,
                                           s32	_s32Default,
                                           s32	_s32Min,
                                           s32	_s32Max);

            s32                     GetS32(u32 _u32ID) const;    // 0, if poolvariable not exists

            void					SetS32Value(u32	_u32ID,
                                                s32   _s32Value);

            void					SetS32Default(u32	_u32ID,
                                                  s32   _s32Default);

            void					SetS32Min(u32	_u32ID,
                                              s32   _s32Min);

            void					SetS32Max(u32	_u32ID,
                                              s32   _s32Max);

            // member for dbl-variables
            bool                    HasDbl(u32 _u32ID) const;    // true if poolvariable exists

            void					AddDbl(u32	_u32ID,
                                           dbl  _dValue,
                                           dbl	_dDefault);

            void					AddDbl(u32	_u32ID,
                                           dbl  _dValue,
                                           dbl	_dDefault,
                                           dbl	_dMin,
                                           dbl	_dMax);

            dbl                     GetDbl(u32 _u32ID) const;    // 0, if poolvariable not exists

            void					SetDblValue(u32	_u32ID,
                                                dbl   _dValue);

            void					SetDblDefault(u32	_u32ID,
                                                  dbl   _dDefault);

            void					SetDblMin(u32	_u32ID,
                                              dbl   _dMin);

            void					SetDblMax(u32	_u32ID,
                                              dbl   _dMax);

            // member for enums
            template <class T>
            bool                    HasEnum(u32 _u32ID) const;    // true if poolvariable exists

            template <class T>
            void                    AddEnum(u32 _u32ID,
                                            T   _tValue,
                                            T   _tDefault);

            template <class T>
            T                       GetEnum(u32 _u32ID) const;    // 0, if poolvariable not exists

            template <class T>
            void					SetEnumValue(u32    _u32ID,
                                                 T      _tValue);

            template <class T>
            void					SetEnumDefault(u32  _u32ID,
                                                   T    _tDefault);

            // member for Color-variables
            bool                    HasColor(u32 _u32ID) const;    // true if poolvariable exists

            void					AddColor(u32            _u32ID,
                                             const qColor   &_colValue,
                                             const qColor   &_colDefault);

            void					AddColor(u32            _u32ID,
                                             const qColor   &_colValue,
                                             const qColor   &_colDefault,
                                             const qColor   &_colMin,
                                             const qColor   &_colMax);

            const qColor&           GetColor(u32 _u32ID) const;    // 0, if poolvariable not exists

            void					SetColorValue(u32       _u32ID,
                                                  Rgba_t    _r,         // if <0 => ignore
                                                  Rgba_t    _g,         // if <0 => ignore
                                                  Rgba_t    _b,         // if <0 => ignore
                                                  Rgba_t    _a);        // if <0 => ignore

            void					SetColorDefault(u32     _u32ID,
                                                    Rgba_t  _r,         // if <0 => ignore
                                                    Rgba_t  _g,         // if <0 => ignore
                                                    Rgba_t  _b,         // if <0 => ignore
                                                    Rgba_t  _a);        // if <0 => ignore

            void					SetColorMin(u32     _u32ID,
                                                Rgba_t  _r,         // if <0 => ignore
                                                Rgba_t  _g,         // if <0 => ignore
                                                Rgba_t  _b,         // if <0 => ignore
                                                Rgba_t  _a);

            void					SetColorMax(u32     _u32ID,
                                                Rgba_t  _r,         // if <0 => ignore
                                                Rgba_t  _g,         // if <0 => ignore
                                                Rgba_t  _b,         // if <0 => ignore
                                                Rgba_t  _a);

        private:
            virtual void            JsonCallback(qVec<qString16>    &_vecKeys,
                                                 qJsonValue         &_value);
    }; // class qVarPool

} // namespace qLib

#include "qVarPool.inl"
