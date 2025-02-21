namespace aLib
{
	//! add 1 element
    template <typename T>
    void aSpVector<T>::push_back(const std::shared_ptr<T>& _t1)
    {
        m_vec.push_back(_t1);
    }


	//! add 2 elements
    template <typename T>
    void aSpVector<T>::push_back(const std::shared_ptr<T>& _t1,
                                  const std::shared_ptr<T>& _t2)
    {
        m_vec.push_back(_t1);
        m_vec.push_back(_t2);
    }


	//! add 3 elements
    template <typename T>
    void aSpVector<T>::push_back(const std::shared_ptr<T>& _t1,
                                  const std::shared_ptr<T>& _t2,
                                  const std::shared_ptr<T>& _t3)
    {
        m_vec.push_back(_t1);
        m_vec.push_back(_t2);
        m_vec.push_back(_t3);
    }


	//! add 4 elements
    template <typename T>
    void aSpVector<T>::push_back(const std::shared_ptr<T>& _t1,
                                  const std::shared_ptr<T>& _t2,
                                  const std::shared_ptr<T>& _t3,
                                  const std::shared_ptr<T>& _t4)
    {
        m_vec.push_back(_t1);
        m_vec.push_back(_t2);
        m_vec.push_back(_t3);
        m_vec.push_back(_t4);
    }


	//! add 5 elements
    template <typename T>
    void aSpVector<T>::push_back(const std::shared_ptr<T>& _t1,
                                  const std::shared_ptr<T>& _t2,
                                  const std::shared_ptr<T>& _t3,
                                  const std::shared_ptr<T>& _t4,
                                  const std::shared_ptr<T>& _t5)
    {
        m_vec.push_back(_t1);
        m_vec.push_back(_t2);
        m_vec.push_back(_t3);
        m_vec.push_back(_t4);
        m_vec.push_back(_t5);
    }


	//! add 6 elements
    template <typename T>
    void aSpVector<T>::push_back(const std::shared_ptr<T>& _t1,
                                  const std::shared_ptr<T>& _t2,
                                  const std::shared_ptr<T>& _t3,
                                  const std::shared_ptr<T>& _t4,
                                  const std::shared_ptr<T>& _t5,
                                  const std::shared_ptr<T>& _t6)
    {
        m_vec.push_back(_t1);
        m_vec.push_back(_t2);
        m_vec.push_back(_t3);
        m_vec.push_back(_t4);
        m_vec.push_back(_t5);
        m_vec.push_back(_t6);
    }


    //! remove n elements fromt the front
    template <typename T>
    void aSpVector<T>::pop_front(s32   _s32Count)
    {
        for (s32 i = 0; i < _s32Count; i++)
        {
            if (m_vec.size() > 0)
            {
                m_vec.erase(m_vec.begin());
            }
        }
    }


    //! check, whether the element is included in the vector
    template <typename T>
    bool aSpVector<T>::Contains(const std::shared_ptr<T>&	_t) const
    {
        const_iterator		cit = std::find(m_vec.begin(), m_vec.end(), _t);

        return (cit != end());
    }


	//! PushBackUnique
	//!
	//! push_back the element, if it isn't already in the array
    template <typename T>
    void aSpVector<T>::PushBackUnique(const std::shared_ptr<T>	&_t)
    {
        if (!Contains(_t))
        {
            m_vec.push_back(_t);
        }
    }


    //! PushBackUnique for a aSpVector
	//!
	//! push_back the element, if it isn't already in the array
    template <typename T>
    void aSpVector<T>::PushBackUnique(const aSpVector<std::shared_ptr<T>>	&_ar)
    {
        for (const std::shared_ptr<T>&	t : _ar)
        {
            PushBackUnique(t);
        }
    }


    //! Shuffle the aSpVector
    //!
    //! push_back the element, if it isn't already in the array
    template <typename T>
    void aSpVector<T>::Shuffle()
    {
        std::random_device rd;
        auto rng = std::default_random_engine { rd() };
        std::shuffle(std::begin(*this), std::end(*this), rng);
    }

} // namespace aLib
