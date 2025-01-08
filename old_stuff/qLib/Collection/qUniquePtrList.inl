/*******************************************************************************
* \file qUniquePtrList.inl
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
namespace qLib {
namespace Collection {


/*******************************************************************************
* qUniquePtrList<T>::push_back - 1 element
*******************************************************************************/
template <typename T>
void qUniquePtrList<T>::push_back(std::unique_ptr<T> _t1)
{
    m_lst.push_back(std::move(_t1));
} // qUniquePtrList<T>::push_back


/*******************************************************************************
* qUniquePtrList<T>::push_back - 2 elements
*******************************************************************************/
template <typename T>
void qUniquePtrList<T>::push_back(std::unique_ptr<T> _t1,
                                  std::unique_ptr<T> _t2)
{
    m_lst.push_back(std::move(_t1));
    m_lst.push_back(std::move(_t2));
} // qUniquePtrList<T>::push_back


/*******************************************************************************
* qUniquePtrList<T>::push_back - 3 elements
*******************************************************************************/
template <typename T>
void qUniquePtrList<T>::push_back(std::unique_ptr<T> _t1,
                                  std::unique_ptr<T> _t2,
                                  std::unique_ptr<T> _t3)
{
    m_lst.push_back(std::move(_t1));
    m_lst.push_back(std::move(_t2));
    m_lst.push_back(std::move(_t3));
} // qUniquePtrList<T>::push_back


/*******************************************************************************
* qUniquePtrList<T>::RemoveElement
*******************************************************************************/
template <class T>
void qUniquePtrList<T>::RemoveElement(T *_pElement)
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
} // qUniquePtrList<T>::RemoveElement


/*******************************************************************************
* qUniquePtrList<T>::GetAndPopBack
*******************************************************************************/
template <typename T>
std::unique_ptr<T> qUniquePtrList<T>::GetAndPopBack()
{
    std::unique_ptr<T>  p = std::move(back());
    pop_back();

    return p;
} // qUniquePtrList<T>::GetAndPopBack


/*******************************************************************************
* qUniquePtrList<T>::GetAndPopFront
*******************************************************************************/
template <typename T>
std::unique_ptr<T> qUniquePtrList<T>::GetAndPopFront()
{
    std::unique_ptr<T>  p = std::move(front());
    pop_front();

    return p;
} // qUniquePtrList<T>::GetAndPopFront


/*******************************************************************************
* qUniquePtrList<T>::FindAndRemove
*******************************************************************************/
template <class T>
std::unique_ptr<T> qUniquePtrList<T>::FindAndRemove(T *_pElement)
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
} // qUniquePtrList<T>::FindAndRemove

} // namespace Math
} // namespace qLib
