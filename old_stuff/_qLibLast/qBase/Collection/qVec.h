/*******************************************************************************
* \file qVec.h
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
    * class qVec
    *******************************************************************************/
    template <typename T>
    class qVec
	{
		public:
			typedef typename std::vector<T>::iterator 			iterator;
			typedef typename std::vector<T>::const_iterator		const_iterator;

			typedef typename std::vector<T>::reference			reference;
			typedef typename std::vector<T>::const_reference	const_reference;

		private:
			std::vector<T>		m_vec;

		public:
            qVec()													{ ; }
            virtual ~qVec()											{ ; }

			iterator 			begin() 								{ return m_vec.begin(); }
			iterator 			end() 									{ return m_vec.end(); }
			const_iterator		begin() const							{ return m_vec.begin(); }
			const_iterator		end() const								{ return m_vec.end(); }

            s32					size() const							{ return (s32) m_vec.size(); }
            bool				empty() const							{ return m_vec.empty(); }

			void				push_back(const T& _t1);
			void				push_back(const T& _t1, const T& _t2);
			void				push_back(const T& _t1, const T& _t2, const T& _t3);
			void				push_back(const T& _t1, const T& _t2, const T& _t3, const T& _t4);
			void				push_back(const T& _t1, const T& _t2, const T& _t3, const T& _t4, const T& _t5);
			void				push_back(const T& _t1, const T& _t2, const T& _t3, const T& _t4, const T& _t5, const T& _t6);

            const_reference		at(s32	_s32Pos) const					{ return m_vec.at(_s32Pos); }
			reference			at(s32	_s32Pos)						{ return m_vec.at(_s32Pos); }

			const_reference		front() const							{ return m_vec.front(); }
			reference			front()									{ return m_vec.front(); }
            void				pop_front()								{ m_vec.erase(m_vec.begin()); }
            void				pop_front(s32   _s32Count);

			const_reference		back() const							{ return m_vec.back(); }
			reference			back()									{ return m_vec.back(); }
            void				pop_back()								{ m_vec.pop_back(); }

            iterator            erase(iterator _it)                     { return m_vec.erase(_it); }
            iterator            erase(const_iterator _it)               { return m_vec.erase(_it); }

            iterator            erase(iterator _itFirst,
                                      iterator _itLast)                 { return m_vec.erase(_itFirst, _itLast); }

            iterator            erase(const_iterator _itFirst,
                                      const_iterator _itLast)           { return m_vec.erase(_itFirst, _itLast); }

            const_reference		operator[](const s32	_s32Pos) const	{ return m_vec[_s32Pos]; }
			reference			operator[](const s32	_s32Pos)		{ return m_vec[_s32Pos]; }

			void				clear()									{ m_vec.clear(); }

			bool				Contains(const T&	_t) const;
			void				PushBackUnique(const T	&_t);
            void				PushBackUnique(const qVec<T>	&_ar);


            void                Shuffle();
    }; // class qVec

} // namespace qLib

#include "qVec.inl"
