/*******************************************************************************
* \file aUniquePtrVec.h
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
#include "aLib_def.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aUtil {


/*******************************************************************************
* class aUniquePtrVec
*******************************************************************************/
template <typename T>
class aUniquePtrVec
{
    public:
        typedef typename std::vector<std::unique_ptr<T>>::iterator                  iterator;
        typedef typename std::vector<std::unique_ptr<T>>::const_iterator			const_iterator;

        typedef typename std::vector<std::unique_ptr<T>>::reverse_iterator          reverse_iterator;
        typedef typename std::vector<std::unique_ptr<T>>::const_reverse_iterator    const_reverse_iterator;

        typedef typename std::vector<std::unique_ptr<T>>::reference                 reference;
        typedef typename std::vector<std::unique_ptr<T>>::const_reference			const_reference;

    private:
        std::vector<std::unique_ptr<T>>		m_vec;

    public:
        aUniquePtrVec()                                                         { ; }
        virtual ~aUniquePtrVec()												{ ; }

        iterator 					begin() 									{ return m_vec.begin(); }
        iterator 					end() 										{ return m_vec.end(); }
        const_iterator				begin() const								{ return m_vec.begin(); }
        const_iterator				end() const									{ return m_vec.end(); }

        reverse_iterator 			rbegin()                                    { return m_vec.rbegin(); }
        reverse_iterator 			rend()                                      { return m_vec.rend(); }
        const_reverse_iterator		rbegin() const                              { return m_vec.rbegin(); }
        const_reverse_iterator		rend() const                                { return m_vec.rend(); }

        s32							size() const								{ return(s32)  m_vec.size(); }
        bool                        empty() const                               { return m_vec.empty(); }

        void						push_back(std::unique_ptr<T> _t1);

        void						push_back(std::unique_ptr<T> _t1,
                                              std::unique_ptr<T> _t2);

        void						push_back(std::unique_ptr<T> _t1,
                                              std::unique_ptr<T> _t2,
                                              std::unique_ptr<T> _t3);

        void						pop_back()                                  { m_vec.pop_back(); }
        void						pop_front()									{ m_vec.pop_front(); }

        void						clear()										{ m_vec.clear(); }
        iterator					erase(iterator	_it)						{ return m_vec.erase(_it); }

        const_reference				at(s32 _s32Idx) const                       { return m_vec.at(_s32Idx); }
        reference                   at(s32 _s32Idx)                             { return m_vec.at(_s32Idx); }

        const_reference				front() const								{ return m_vec.front(); }
        reference					front()										{ return m_vec.front(); }

        const_reference				back() const								{ return m_vec.back(); }
        reference					back()										{ return m_vec.back(); }

        void						removeElement(T *_pElement);

        std::unique_ptr<T>			getAndPopBack();
        std::unique_ptr<T>			getAndPopFront();
        std::unique_ptr<T>			findAndSteal(T *_pElement);

//            void						sort(bool (*sortFunction) (const std::unique_ptr<T>,
//                                                                   const std::unique_ptr<T>))	{ m_vec.sort(sortFunction); }
}; // class aUniquePtrVec


} // namespace aUtil
} // namespace aLib

#include "aUniquePtrVec.inl"
