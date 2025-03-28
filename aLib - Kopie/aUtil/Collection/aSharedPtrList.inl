/*******************************************************************************
* \file aSharedPtrList.inl
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


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aUtil {


/*******************************************************************************
* aSharedPtrList<T>::push_back - 1 element
*******************************************************************************/
template <typename T>
void aSharedPtrList<T>::push_back(const std::shared_ptr<T> &_t1)
{
    m_lst.push_back(std::move(_t1));
} // aSharedPtrList<T>::push_back


/*******************************************************************************
* aSharedPtrList<T>::push_back - 2 elements
*******************************************************************************/
template <typename T>
void aSharedPtrList<T>::push_back(const std::shared_ptr<T> &_t1,
                                  const std::shared_ptr<T> &_t2)
{
    m_lst.push_back(std::move(_t1));
    m_lst.push_back(std::move(_t2));
} // aSharedPtrList<T>::push_back


/*******************************************************************************
* aSharedPtrList<T>::push_back - 3 elements
*******************************************************************************/
template <typename T>
void aSharedPtrList<T>::push_back(const std::shared_ptr<T>& _t1,
                                  const std::shared_ptr<T>& _t2,
                                  const std::shared_ptr<T>& _t3)
{
    m_lst.push_back(std::move(_t1));
    m_lst.push_back(std::move(_t2));
    m_lst.push_back(std::move(_t3));
} // aSharedPtrList<T>::push_back


/*******************************************************************************
* aSharedPtrList<T>::find
*******************************************************************************/
template <class T>
std::shared_ptr<T> aSharedPtrList<T>::find(const T *_pT) const
{
    for (std::shared_ptr<T> pT : m_lst)
    {
        if (pT.get() == _pT)
        {
            return pT;
        }
    }

    return nullptr;
} // aSharedPtrList<T>::find


/*******************************************************************************
* aSharedPtrList<T>::contains
*
* true if element already in this array
*******************************************************************************/
template <class T>
bool aSharedPtrList<T>::contains(const std::shared_ptr<T>	&_t) const
{
    return (std::find(m_lst.begin(), m_lst.end(), _t) != m_lst.end());
} // aSharedPtrList<T>::contains


/*******************************************************************************
* aSharedPtrList<T>::pushBackUnique
*
* push_back the element, if it isn't already in the array
*******************************************************************************/
template <class T>
void aSharedPtrList<T>::pushBackUnique(const std::shared_ptr<T>	&_t)
{
    if (!Contains(_t))
    {
        m_lst.push_back(_t);
    }
} // aSharedPtrList<T>::pushBackUnique


/*******************************************************************************
* aSharedPtrList<T>::removeElement
*******************************************************************************/
template <class T>
void aSharedPtrList<T>::removeElement(std::shared_ptr<T>		&_t)
{
    iterator		it = std::find(m_lst.begin(), m_lst.end(), _t);

    if (it != m_lst.end())
    {
        m_lst.erase(it);
    }
} // aSharedPtrList<T>::removeElement


/*******************************************************************************
* aSharedPtrList<T>::getAndPopBack
*******************************************************************************/
template <typename T>
std::shared_ptr<T> aSharedPtrList<T>::getAndPopBack()
{
    std::shared_ptr<T>  p = std::move(back());
    pop_back();

    return p;
} // aSharedPtrList<T>::getAndPopBack


/*******************************************************************************
* aSharedPtrList<T>::getAndPopFront
*******************************************************************************/
template <typename T>
std::shared_ptr<T> aSharedPtrList<T>::getAndPopFront()
{
    std::shared_ptr<T>  p = std::move(front());
    pop_front();

    return p;
} // aSharedPtrList<T>::getAndPopFront



} // namespace aUtil
} // namespace aLib
