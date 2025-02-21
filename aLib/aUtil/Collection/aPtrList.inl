/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aUtil {


//! add 1 element
template <typename T>
void aPtrList<T>::push_back(T* _pT1)
{
    m_lst.push_back(_pT1);
}


//! add 2 elements
template <typename T>
void aPtrList<T>::push_back(T* _pT1,
                            T* _pT2)
{
    m_lst.push_back(_pT1);
    m_lst.push_back(_pT2);
}

//! add 3 elements
template <typename T>
void aPtrList<T>::push_back(T* _pT1,
                            T* _pT2,
                            T* _pT3)
{
    m_lst.push_back(_pT1);
    m_lst.push_back(_pT2);
    m_lst.push_back(_pT3);
}

//! Contains
//!
//! true if element already in this array
template <class T>
bool aPtrList<T>::contains(T	*_pT) const
{
    return (std::find(m_lst.begin(), m_lst.end(), _pT) != m_lst.end());
}


//! PushBackUnique
//!
//! push_back the element, if it isn't already in the array
template <class T>
void aPtrList<T>::pushBackUnique(T	*_pT)
{
    if (!Contains(_pT))
    {
        m_lst.push_back(_pT);
    }
}


//! RemoveElement
//!
//! removes a specific element
template <class T>
bool aPtrList<T>::removeElement(T	*_pT)
{
    iterator		it = std::find(m_lst.begin(), m_lst.end(), _pT);

    if (it != m_lst.end())
    {
        m_lst.erase(it);
        return true;
    }

    return false;
}


/*******************************************************************************
* aPtrList<T>::moveToBegin
*******************************************************************************/
template <class T>
void aPtrList<T>::moveToBegin(T	*_pT)
{
    iterator it;

    for (it = m_lst.begin(); it != m_lst.end(); it++)
    {
        if (*it == _pT)
        {
            m_lst.splice(m_lst.begin(), m_lst, it);
        }
    }
} // aPtrList<T>::moveToBegin


} // namespace aUtil
} // namespace aLib
