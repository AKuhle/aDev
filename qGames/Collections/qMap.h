/*******************************************************************************
* \file qqPoolVarBool.cpp
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
* includes
*******************************************************************************/
#include "qBaseDefs.h"


namespace qLib
{
    /*******************************************************************************
    * \class qMap
    * \brief specialized std::map
    *******************************************************************************/
	template <typename Tkey, typename T2>
    class qMap
	{
		public:
			typedef typename std::map<Tkey, T2>::iterator 			iterator;
			typedef typename std::map<Tkey, T2>::const_iterator		const_iterator;

		private:
			std::map<Tkey, T2>		m_map;

		public:
            qMap()													{ ; }
            virtual ~qMap()											{ ; }

			iterator 			begin() 							{ return m_map.begin(); }
			iterator 			end() 								{ return m_map.end(); }
			const_iterator		begin() const						{ return m_map.begin(); }
			const_iterator		end() const							{ return m_map.end(); }

		    s32					size() const						{ return (s32) m_map.size(); }

			 void				clear()								{ m_map.clear(); }

			 T2&				operator[](const Tkey &_tKey)		{ return m_map[_tKey]; }
			 iterator			find(const Tkey &_tKey)				{ return m_map.find(_tKey); }
			 const_iterator		find(const Tkey &_tKey) const		{ return m_map.find(_tKey); }

//			bool				Contains(const T	&_t) const;
//			void				PushBackUnique(const T	&_t);
    }; // class qMap

} // namespace qLib
