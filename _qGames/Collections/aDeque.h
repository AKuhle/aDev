/*******************************************************************************
* \file aDeque.h
* \author Andreas Kuhlewind
*
* \brief
*
*  Detailed description starts here.
*******************************************************************************/
#pragma once


/*******************************************************************************
* includes
*******************************************************************************/
#include <aBaseDefs.h>


namespace aLib
{
    /*******************************************************************************
    * class aDeque
    *******************************************************************************/
	template <typename T>
    class aDeque
	{
		public:
            typedef typename std::deque<T>::iterator 			iterator;
            typedef typename std::deque<T>::const_iterator      const_iterator;

            typedef typename std::deque<T>::reference			reference;
            typedef typename std::deque<T>::const_reference     const_reference;

		private:
            std::deque<T>		m_deque;

		public:
            aDeque()                                                       { ; }
            virtual ~aDeque()                                              { ; }

            iterator 			begin()                                     { return m_deque.begin(); }
            iterator 			end()                                       { return m_deque.end(); }
            const_iterator		begin() const                               { return m_deque.begin(); }
            const_iterator		end() const                                 { return m_deque.end(); }

            void                resize(s32 _s32Count)                       { m_deque.resize(_s32Count); }

            s32					size() const                                { return (s32) m_deque.size(); }

            void				push_back(const T& _t1)                     { m_deque.push_back(_t1); }
            void				pop_back()                                  { m_deque.pop_back(); }

            void				push_front(const T& _t1)                    { m_deque.push_front(_t1); }
            void				pop_front()                                 { m_deque.pop_front(); }

            const_reference		at(s32	_s32Pos) const                      { return m_deque.at(_s32Pos); }
            reference			at(s32	_s32Pos)                            { return m_deque.at(_s32Pos); }

            const_reference		front() const                               { return m_deque.front(); }
            reference			front()                                     { return m_deque.front(); }

            const_reference		back() const                                { return m_deque.back(); }
            reference			back()                                      { return m_deque.back(); }

            const_reference		operator[](const s32	_s32Pos) const      { return m_deque[_s32Pos]; }
            reference			operator[](const s32	_s32Pos)            { return m_deque[_s32Pos]; }

            void				clear()                                     { m_deque.clear(); }
    }; // class aDeque

} // namespace aLib
