/*******************************************************************************
* \file qSpList.inl
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
    * class qPtrList
    *******************************************************************************/
    template <typename T>
    class qPtrList
	{
		public:
            typedef typename std::list<T*>::iterator 			iterator;
            typedef typename std::list<T*>::const_iterator		const_iterator;

            typedef typename std::list<T*>::reference			reference;
            typedef typename std::list<T*>::const_reference		const_reference;

		private:
            std::list<T*>		m_lst;

		public:
            qPtrList()																{ ; }
            virtual ~qPtrList()														{ ; }

			iterator 			begin() 											{ return m_lst.begin(); }
			iterator 			end() 												{ return m_lst.end(); }
			const_iterator		begin() const										{ return m_lst.begin(); }
			const_iterator		end() const											{ return m_lst.end(); }

		    s32					size() const										{ return m_lst.size(); }
            bool				empty() const                                       { return m_lst.empty(); }

            void				push_back(T *_pT1);
            void				push_back(T *_pT1, T *_pT2);
            void				push_back(T *_pT1, T *_pT2, T *_pT3);

            void				push_front(T *_t)                                   { m_lst.push_front(_t); }

            void				pop_back()											{ m_lst.pop_back(); }
			void				pop_front()											{ m_lst.pop_front(); }

			void				clear()												{ m_lst.clear(); }
			iterator			erase(iterator	_it)								{ return m_lst.erase(_it); }

			const_reference		front() const										{ return m_lst.front(); }
			reference			front()												{ return m_lst.front(); }

			const_reference		back() const										{ return m_lst.back(); }
			reference			back()												{ return m_lst.back(); }

            //iterator            find(const T	&_t)                                { return m_lst.find(m_lst.begin(), m_lst.end(), _t); }

            void				sort(bool (*sortFunction) (T*, T*))		{ m_lst.sort(sortFunction); }

            bool				Contains(T	*_pT) const;
            void				PushBackUnique(T	*_pT);
            bool				RemoveElement(T	*_pT);
    }; // class qPtrList

} // namespace qLib

#include "qPtrList.inl"
