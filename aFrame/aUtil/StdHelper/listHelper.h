/*******************************************************************************
* \file aArgument.h
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


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aFrame {
namespace aUtil {


/*******************************************************************************
* findPtrInSharedPtrList
*******************************************************************************/
template <class T>
shared_ptr<T>       findPtrInSharedPtrList(const list<shared_ptr<T>>    &_list,
                                           const T                      *_pT)
{
    shared_ptr<T>   pFound;

    auto it = std::find_if(_list.begin(),
                           _list.end(),
                           [&_pT](const std::shared_ptr<T> &_pShared)
                           {
                               return _pShared.get() == _pT;
                           }
    );

    if (it != _list.end())
    {
        // fouind the pointer
        pFound = *it;

    }

    return pFound;
} // findPtrInSharedPtrList


/*******************************************************************************
* removePtrInSharedPtrList
*******************************************************************************/
template <class T>
void                removePtrInSharedPtrList(list<shared_ptr<T>>    &_list,
                                             const T                *_pT)
{
    _list.remove_if([_pT] (const std::shared_ptr<T> &_pShared)
                    {
                        return _pShared.get() == _pT;
                    });
} // removePtrInSharedPtrList


} // namespace aUtil
} // namespace aFrame
