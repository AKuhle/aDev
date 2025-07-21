/*******************************************************************************
* \file qSynchronize.h
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
#include "aFrame_def.h"

using namespace std;


namespace aFrame {
namespace aUtil {


/*******************************************************************************
* forward
*******************************************************************************/
template <class Sync>
class aExclusiveAccessor;

template <class Sync>
class aSharedAccessor;



/*******************************************************************************
* class aSynchronized
*******************************************************************************/
template <class T>
class aSynchronized
{
    public:
        using           ValueType = T;

    private:
        friend class    aExclusiveAccessor<aSynchronized>;
        friend class    aSharedAccessor<aSynchronized>;

        T               m_instance;
        mutable         shared_mutex m_mutex;

    public:
        template <typename... Targs>
        aSynchronized(Targs&&... args) : m_instance{std::forward<Targs>(args)...}
        {
        }
}; // class aSynchronized



/*******************************************************************************
* class aExclusiveAccessor
*
* @brief Locks aSynchronized object instance for exclusive (write) access
*
* @tparam Sync The aSynchronized templated type of the type to be wrapped
*******************************************************************************/
template <class Sync>
class aExclusiveAccessor
{
    public:
        using T = typename Sync::ValueType;

    private:
        //lock_guard<shared_mutex>    m_guard;
        unique_lock<shared_mutex>   m_guard;
        T                           &m_instance;

    public:
        explicit aExclusiveAccessor(aSynchronized<T> &_resource)
        : m_guard(_resource.m_mutex), m_instance(_resource.m_instance)
        {
        }

        T&          get() const             { return m_instance; }
        T&          operator*() const       { return m_instance; }
        T*          operator->() const      { return &m_instance; }
}; // class aExclusiveAccessor



/*******************************************************************************
* class aSharedAccessor
*
* @brief Locks aSynchronized object instance for shared (read) access
*
* @tparam Sync The aSynchronized templated type of the type to be wrapped
*******************************************************************************/
template <class Sync>
class aSharedAccessor
{
    public:
        using T = typename Sync::ValueType;

    private:
        shared_lock<shared_mutex>   m_guard;
        const T                     &m_instance;

    public:
        explicit aSharedAccessor(const aSynchronized<T> &_resource)
        : m_guard(_resource.m_mutex), m_instance(_resource.m_instance)
        {
        }

        const T&    get() const             { return m_instance; }
        const T&    operator*() const       { return m_instance; }
        const T*    operator->() const      { return &m_instance; }

}; // class aSharedAccessor



} // namespace aUtil
} // namespace aFrame
