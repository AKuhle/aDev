namespace qLib
{
	//! add 1 element
	template <typename T>
    void qPtrList<T>::push_back(T* _pT1)
	{
        m_lst.push_back(_pT1);
	}


	//! add 2 elements
	template <typename T>
    void qPtrList<T>::push_back(T* _pT1,
                                T* _pT2)
	{
        m_lst.push_back(_pT1);
        m_lst.push_back(_pT2);
	}

	//! add 3 elements
	template <typename T>
    void qPtrList<T>::push_back(T* _pT1,
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
    bool qPtrList<T>::Contains(T	*_pT) const
	{
        return (std::find(m_lst.begin(), m_lst.end(), _pT) != m_lst.end());
	}


	//! PushBackUnique
	//!
	//! push_back the element, if it isn't already in the array
	template <class T>
    void qPtrList<T>::PushBackUnique(T	*_pT)
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
    bool qPtrList<T>::RemoveElement(T	*_pT)
	{
        iterator		it = std::find(m_lst.begin(), m_lst.end(), _pT);

		if (it != m_lst.end())
		{
			m_lst.erase(it);
            return true;
		}

        return false;
	}
} // namespace qLib
