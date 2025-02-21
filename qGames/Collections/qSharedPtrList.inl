/*******************************************************************************
* \file qSharedPtrList.inl
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
    * qSharedPtrList<T>::push_back - 1 element
    *******************************************************************************/
	template <typename T>
    void qSharedPtrList<T>::push_back(const std::shared_ptr<T> &_t1)
	{
        m_lst.push_back(_t1);
    } // qSharedPtrList<T>::push_back


    /*******************************************************************************
    * qSharedPtrList<T>::push_back - 2 elements
    *******************************************************************************/
    template <typename T>
    void qSharedPtrList<T>::push_back(const std::shared_ptr<T> &_t1,
                                      const std::shared_ptr<T> &_t2)
	{
        m_lst.push_back(_t1);
        m_lst.push_back(_t2);
    } // qSharedPtrList<T>::push_back


    /*******************************************************************************
    * qSharedPtrList<T>::push_back - 3 elements
    *******************************************************************************/
    template <typename T>
    void qSharedPtrList<T>::push_back(const std::shared_ptr<T>& _t1,
                                      const std::shared_ptr<T>& _t2,
                                      const std::shared_ptr<T>& _t3)
	{
        m_lst.push_back(_t1);
        m_lst.push_back(_t2);
        m_lst.push_back(_t3);
    } // qSharedPtrList<T>::push_back


    /*******************************************************************************
    * qSharedPtrList<T>::Contains
    *
    * true if element already in this array
    *******************************************************************************/
    template <class T>
    bool qSharedPtrList<T>::Contains(const std::shared_ptr<T>	&_t) const
	{
		return (std::find(m_lst.begin(), m_lst.end(), _t) != m_lst.end());
    } // qSharedPtrList<T>::Contains


    /*******************************************************************************
    * qSharedPtrList<T>::PushBackUnique
    *
    * push_back the element, if it isn't already in the array
    *******************************************************************************/
    template <class T>
    void qSharedPtrList<T>::PushBackUnique(const std::shared_ptr<T>	&_t)
	{
		if (!Contains(_t))
		{
			m_lst.push_back(_t);
		}
    } // qSharedPtrList<T>::PushBackUnique


    /*******************************************************************************
    * qSharedPtrList<T>::RemoveElement
    *******************************************************************************/
    template <class T>
    void qSharedPtrList<T>::RemoveElement(std::shared_ptr<T>		&_t)
	{
		iterator		it = std::find(m_lst.begin(), m_lst.end(), _t);

		if (it != m_lst.end())
		{
			m_lst.erase(it);
		}
    } // qSharedPtrList<T>::RemoveElement
} // namespace qLib
