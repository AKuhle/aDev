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
// #include "poolVar_bool.h"
// #include "poolVar_rgba.h"
// #include "poolVar_dbl.h"
// #include "poolVar_s32.h"
// #include "poolVar_string.h"
// #include "poolVar_u32.h"


namespace qLib
{
    /*******************************************************************************
    * forward
    *******************************************************************************/
    class qJsonValue;

    /*******************************************************************************
    * class qBaseVarPool
    *******************************************************************************/
    class qBaseVarPool
	{
        protected:
            qMap<u32, qPoolVarBool>         m_mapBool;
            qMap<u32, qPoolVarS32>          m_mapS32;
            qMap<u32, qPoolVarS32>          m_mapEnum;
            // std::map<u32, PoolVarU32>		m_mapU32;
            // std::map<u32, PoolVarDbl>		m_mapDbl;
            // std::map<u32, PoolVarRgba>	    m_mapRgba;
            // std::map<u32, PoolVarString>	m_mapString;

		public:
            qBaseVarPool();
            qBaseVarPool(const qBaseVarPool &_rhs);
            virtual ~qBaseVarPool();

            qBaseVarPool&           operator=(const qBaseVarPool &_rhs);

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

        private:
            virtual void            JsonCallback(qVec<qString16>    &_vecKeys,
                                                 qJsonValue         &_value);
    }; // class qBaseVarPool

} // namespace qLib

#include "qBaseVarPool.inl"
