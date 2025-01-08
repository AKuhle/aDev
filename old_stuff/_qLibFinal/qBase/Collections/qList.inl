namespace qLib
{
	//! add 1 element
	template <typename T>
    void qList<T>::push_back(const T& _t1)
	{
		m_lst.push_back(_t1);
	}


	//! add 2 elements
	template <typename T>
    void qList<T>::push_back(const T& _t1,
                              const T& _t2)
	{
		m_lst.push_back(_t1);
		m_lst.push_back(_t2);
	}

	//! add 3 elements
	template <typename T>
    void qList<T>::push_back(const T& _t1,
                              const T& _t2,
                              const T& _t3)
	{
		m_lst.push_back(_t1);
		m_lst.push_back(_t2);
		m_lst.push_back(_t3);
	}

	//! Contains
	//!
	//! true if element already in this array
	template <class T>
    bool qList<T>::Contains(const T	&_t) const
	{
		return (std::find(m_lst.begin(), m_lst.end(), _t) != m_lst.end());
	}


	//! PushBackUnique
	//!
	//! push_back the element, if it isn't already in the array
	template <class T>
    void qList<T>::PushBackUnique(const T	&_t)
	{
		if (!Contains(_t))
		{
			m_lst.push_back(_t);
		}
	}


	//! RemoveElement
	//!
	//! removes a specific element
	template <class T>
    bool qList<T>::RemoveElement(const T	&_t)
	{
		iterator		it = std::find(m_lst.begin(), m_lst.end(), _t);

		if (it != m_lst.end())
		{
			m_lst.erase(it);
            return true;
		}

        return false;
	}
} // namespace qLib
