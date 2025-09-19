/*******************************************************************************
* \file aUniquePtrVec.inl
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
namespace aFrame {
namespace aUtil {


/*******************************************************************************
* aUniquePtrVec<T>::push_back - 1 element
*******************************************************************************/
template <typename T>
void aUniquePtrVec<T>::push_back(std::unique_ptr<T> _t1)
{
    m_vec.push_back(std::move(_t1));
} // aUniquePtrVec<T>::push_back


/*******************************************************************************
* aUniquePtrVec<T>::push_back - 2 elements
*******************************************************************************/
template <typename T>
void aUniquePtrVec<T>::push_back(std::unique_ptr<T> _t1,
                                  std::unique_ptr<T> _t2)
{
    m_vec.push_back(std::move(_t1));
    m_vec.push_back(std::move(_t2));
} // aUniquePtrVec<T>::push_back


/*******************************************************************************
* aUniquePtrVec<T>::push_back - 3 elements
*******************************************************************************/
template <typename T>
void aUniquePtrVec<T>::push_back(std::unique_ptr<T> _t1,
                                  std::unique_ptr<T> _t2,
                                  std::unique_ptr<T> _t3)
{
    m_vec.push_back(std::move(_t1));
    m_vec.push_back(std::move(_t2));
    m_vec.push_back(std::move(_t3));
} // aUniquePtrVec<T>::push_back


/*******************************************************************************
* aUniquePtrVec<T>::removeElement
*******************************************************************************/
template <class T>
void aUniquePtrVec<T>::removeElement(T *_pElement)
{
    iterator		it;

    for (it = m_vec.begin(); it != m_vec.end(); it++)
    {
        if (it->get() == _pElement)
        {
            m_vec.erase(it);
            return;
        }
    } // for...
} // aUniquePtrVec<T>::removeElement


/*******************************************************************************
* aUniquePtrVec<T>::getAndPopBack
*******************************************************************************/
template <typename T>
std::unique_ptr<T> aUniquePtrVec<T>::getAndPopBack()
{
    std::unique_ptr<T>  p = std::move(back());
    pop_back();

    return p;
} // aUniquePtrVec<T>::getAndPopBack


/*******************************************************************************
* aUniquePtrVec<T>::getAndPopFront
*******************************************************************************/
template <typename T>
std::unique_ptr<T> aUniquePtrVec<T>::getAndPopFront()
{
    std::unique_ptr<T>  p = std::move(front());
    pop_front();

    return p;
} // aUniquePtrVec<T>::getAndPopFront


/*******************************************************************************
* aUniquePtrVec<T>::findAndSteal
*******************************************************************************/
template <class T>
std::unique_ptr<T> aUniquePtrVec<T>::findAndSteal(T *_pElement)
{
    iterator		it;

    for (it = m_vec.begin(); it != m_vec.end(); it++)
    {
        if (it->get() == _pElement)
        {
            std::unique_ptr<T> p = std::move(*it);
            m_vec.erase(it);

            return p;
        }
    } // for...

    return nullptr;
} // aUniquePtrVec<T>::findAndSteal


} // namespace aUtil
} // namespace aFrame
