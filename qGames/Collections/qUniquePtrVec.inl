/*******************************************************************************
* \file qUniquePtrVec.inl
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


namespace qLib
{
    /*******************************************************************************
    * qUniquePtrVec<T>::push_back - 1 element
    *******************************************************************************/
	template <typename T>
    void qUniquePtrVec<T>::push_back(std::unique_ptr<T> _t1)
	{
        m_vec.push_back(std::move(_t1));
    } // qUniquePtrVec<T>::push_back


    /*******************************************************************************
    * qUniquePtrVec<T>::push_back - 2 elements
    *******************************************************************************/
    template <typename T>
    void qUniquePtrVec<T>::push_back(std::unique_ptr<T> _t1,
                                      std::unique_ptr<T> _t2)
    {
        m_vec.push_back(std::move(_t1));
        m_vec.push_back(std::move(_t2));
    } // qUniquePtrVec<T>::push_back


    /*******************************************************************************
    * qUniquePtrVec<T>::push_back - 3 elements
    *******************************************************************************/
    template <typename T>
    void qUniquePtrVec<T>::push_back(std::unique_ptr<T> _t1,
                                      std::unique_ptr<T> _t2,
                                      std::unique_ptr<T> _t3)
	{
        m_vec.push_back(std::move(_t1));
        m_vec.push_back(std::move(_t2));
        m_vec.push_back(std::move(_t3));
    } // qUniquePtrVec<T>::push_back


    /*******************************************************************************
    * qUniquePtrVec<T>::RemoveElement
    *******************************************************************************/
    template <class T>
    void qUniquePtrVec<T>::RemoveElement(T *_pElement)
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
    } // qUniquePtrVec<T>::RemoveElement


    /*******************************************************************************
    * qUniquePtrVec<T>::GetAndPopBack
    *******************************************************************************/
    template <typename T>
    std::unique_ptr<T> qUniquePtrVec<T>::GetAndPopBack()
    {
        std::unique_ptr<T>  p = std::move(back());
        pop_back();

        return p;
    } // qUniquePtrVec<T>::GetAndPopBack



} // namespace qLib
