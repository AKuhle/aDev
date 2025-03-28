/*******************************************************************************
* \file aSharedPtrList.h
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
* class aSharedPtrList
*******************************************************************************/
template <typename T>
class aSharedPtrList
{
    public:
        typedef typename std::list<std::shared_ptr<T>>::iterator 				iterator;
        typedef typename std::list<std::shared_ptr<T>>::const_iterator			const_iterator;

        typedef typename std::list<std::shared_ptr<T>>::reverse_iterator 		reverse_iterator;
        typedef typename std::list<std::shared_ptr<T>>::const_reverse_iterator	const_reverse_iterator;

        typedef typename std::list<std::shared_ptr<T>>::reference				reference;
        typedef typename std::list<std::shared_ptr<T>>::const_reference			const_reference;

    private:
        std::list<std::shared_ptr<T>>		m_lst;

    public:
        aSharedPtrList()														{ ; }
        virtual ~aSharedPtrList()												{ ; }

        iterator 					begin() 									{ return m_lst.begin(); }
        iterator 					end() 										{ return m_lst.end(); }
        const_iterator				begin() const								{ return m_lst.begin(); }
        const_iterator				end() const									{ return m_lst.end(); }

        reverse_iterator 			rbegin() { return m_lst.rbegin(); }
        reverse_iterator 			rend() { return m_lst.rend(); }
        const_reverse_iterator		rbegin() const { return m_lst.rbegin(); }
        const_reverse_iterator		rend() const { return m_lst.rend(); }

        s32							size() const								{ return(s32)  m_lst.size(); }

        void						push_back(const std::shared_ptr<T> &_t1);

        void						push_back(const std::shared_ptr<T> &_t1,
                                              const std::shared_ptr<T> &_t2);

        void						push_back(const std::shared_ptr<T> &_t1,
                                              const std::shared_ptr<T> &_t2,
                                              const std::shared_ptr<T> &_t3);

        void						pop_back()                                  { m_lst.pop_back(); }
        void						pop_front()									{ m_lst.pop_front(); }

        void						clear()										{ m_lst.clear(); }
        iterator					erase(iterator	_it)						{ return m_lst.erase(_it); }

        const_reference				front() const								{ return m_lst.front(); }
        reference					front()										{ return m_lst.front(); }

        const_reference				back() const								{ return m_lst.back(); }
        reference					back()										{ return m_lst.back(); }

        std::shared_ptr<T>          find(const T *_pT) const;
        bool						contains(const std::shared_ptr<T>	&_t) const;
        void						pushBackUnique(const std::shared_ptr<T>	&_t);
        void						removeElement(std::shared_ptr<T>		&_t);

        std::shared_ptr<T>			getAndPopBack();
        std::shared_ptr<T>			getAndPopFront();

        void						sort(bool (*sortFunction) (const std::shared_ptr<T>,
                                                               const std::shared_ptr<T>))	{ m_lst.sort(sortFunction); }

}; // class aSharedPtrList


} // namespace aUtil
} // namespace aLib

#include "aSharedPtrList.inl"
