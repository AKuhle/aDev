///////////////////////////////////////////////////////////////////////////////
//! \brief specialized std::vector
//!
//! Don't include this file explicit. Include qLib.h instead
//!
//! \author Andreas Kuhlewind
///////////////////////////////////////////////////////////////////////////////
#pragma once


/*******************************************************************************
* includes
*******************************************************************************/
#include "aBaseDefs.h"


namespace aLib
{
	///////////////////////////////////////////////////////////////////////////////
    //! \class aSpVector
	//! \brief specialized std::vector
	///////////////////////////////////////////////////////////////////////////////
	template <typename T>
    class aSpVector
	{
		public:
            typedef typename std::vector<std::shared_ptr<T>>::iterator 			iterator;
            typedef typename std::vector<std::shared_ptr<T>>::const_iterator	const_iterator;

            typedef typename std::vector<std::shared_ptr<T>>::reference			reference;
            typedef typename std::vector<std::shared_ptr<T>>::const_reference	const_reference;

		private:
            std::vector<std::shared_ptr<T>>		m_vec;

		public:
            aSpVector()													{ ; }
            virtual ~aSpVector()											{ ; }

			iterator 			begin() 								{ return m_vec.begin(); }
			iterator 			end() 									{ return m_vec.end(); }
			const_iterator		begin() const							{ return m_vec.begin(); }
			const_iterator		end() const								{ return m_vec.end(); }

            void                resize(s32 _s32Count)                   { m_vec.resize(_s32Count); }

            s32					size() const							{ return (s32) m_vec.size(); }

            void				push_back(const std::shared_ptr<T>& _t1);

            void				push_back(const std::shared_ptr<T>& _t1,
                                          const std::shared_ptr<T>& _t2);

            void				push_back(const std::shared_ptr<T>& _t1,
                                          const std::shared_ptr<T>& _t2,
                                          const std::shared_ptr<T>& _t3);

            void				push_back(const std::shared_ptr<T>& _t1,
                                          const std::shared_ptr<T>& _t2,
                                          const std::shared_ptr<T>& _t3,
                                          const std::shared_ptr<T>& _t4);

            void				push_back(const std::shared_ptr<T>& _t1,
                                          const std::shared_ptr<T>& _t2,
                                          const std::shared_ptr<T>& _t3,
                                          const std::shared_ptr<T>& _t4,
                                          const std::shared_ptr<T>& _t5);

            void				push_back(const std::shared_ptr<T>& _t1,
                                          const std::shared_ptr<T>& _t2,
                                          const std::shared_ptr<T>& _t3,
                                          const std::shared_ptr<T>& _t4,
                                          const std::shared_ptr<T>& _t5,
                                          const std::shared_ptr<T>& _t6);

			const_reference		at(s32	_s32Pos) const					{ return m_vec.at(_s32Pos); }
			reference			at(s32	_s32Pos)						{ return m_vec.at(_s32Pos); }

			const_reference		front() const							{ return m_vec.front(); }
			reference			front()									{ return m_vec.front(); }
            void				pop_front()								{ m_vec.erase(m_vec.begin()); }
            void				pop_front(s32   _s32Count);

			const_reference		back() const							{ return m_vec.back(); }
            reference			back()									{ return m_vec.back(); }
            void				pop_back()								{ m_vec.pop.back(); }

			const_reference		operator[](const s32	_s32Pos) const	{ return m_vec[_s32Pos]; }
			reference			operator[](const s32	_s32Pos)		{ return m_vec[_s32Pos]; }

			void				clear()									{ m_vec.clear(); }
            void                erase(const iterator  &it)              { m_vec.erase(it); }

            bool				Contains(const std::shared_ptr<T>&	_t) const;
            void				PushBackUnique(const std::shared_ptr<T>	&_t);
            void				PushBackUnique(const aSpVector<std::shared_ptr<T>>	&_ar);

            void                Shuffle();

    }; // class aSpVector

} // namespace aLib

#include "aSpVector.inl"
