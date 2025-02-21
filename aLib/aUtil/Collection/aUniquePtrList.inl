/*******************************************************************************
* \file aUniquePtrList.inl
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
* aUniquePtrList<T>::push_back - 1 element
*******************************************************************************/
template <typename T>
void aUniquePtrList<T>::push_back(std::unique_ptr<T> _t1)
{
    m_lst.push_back(std::move(_t1));
} // aUniquePtrList<T>::push_back


/*******************************************************************************
* aUniquePtrList<T>::push_back - 2 elements
*******************************************************************************/
template <typename T>
void aUniquePtrList<T>::push_back(std::unique_ptr<T> _t1,
                                  std::unique_ptr<T> _t2)
{
    m_lst.push_back(std::move(_t1));
    m_lst.push_back(std::move(_t2));
} // aUniquePtrList<T>::push_back


/*******************************************************************************
* aUniquePtrList<T>::push_back - 3 elements
*******************************************************************************/
template <typename T>
void aUniquePtrList<T>::push_back(std::unique_ptr<T> _t1,
                                  std::unique_ptr<T> _t2,
                                  std::unique_ptr<T> _t3)
{
    m_lst.push_back(std::move(_t1));
    m_lst.push_back(std::move(_t2));
    m_lst.push_back(std::move(_t3));
} // aUniquePtrList<T>::push_back


/*******************************************************************************
* aUniquePtrList<T>::removeElement
*******************************************************************************/
template <class T>
void aUniquePtrList<T>::removeElement(T *_pElement)
{
    iterator		it;

    for (it = m_lst.begin(); it != m_lst.end(); it++)
    {
        if (it->get() == _pElement)
        {
            m_lst.erase(it);
            return;
        }
    } // for...
} // aUniquePtrList<T>::removeElement


/*******************************************************************************
* aUniquePtrList<T>::getAndPopBack
*******************************************************************************/
template <typename T>
std::unique_ptr<T> aUniquePtrList<T>::getAndPopBack()
{
    std::unique_ptr<T>  p = std::move(back());
    pop_back();

    return p;
} // aUniquePtrList<T>::getAndPopBack


/*******************************************************************************
* aUniquePtrList<T>::getAndPopFront
*******************************************************************************/
template <typename T>
std::unique_ptr<T> aUniquePtrList<T>::getAndPopFront()
{
    std::unique_ptr<T>  p = std::move(front());
    pop_front();

    return p;
} // aUniquePtrList<T>::getAndPopFront


/*******************************************************************************
* aUniquePtrList<T>::findAndSteal
*******************************************************************************/
template <class T>
std::unique_ptr<T> aUniquePtrList<T>::findAndSteal(T *_pElement)
{
    iterator		it;

    for (it = m_lst.begin(); it != m_lst.end(); it++)
    {
        if (it->get() == _pElement)
        {
            std::unique_ptr<T> p = std::move(*it);
            m_lst.erase(it);

            return p;
        }
    } // for...

    return nullptr;
} // aUniquePtrList<T>::findAndSteal

} // namespace aUtil
} // namespace aLib
