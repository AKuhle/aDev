/*******************************************************************************
* \file qInterval2D.inl
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
    * qInterval2D<T>::qInterval2D()
    *******************************************************************************/
    template<class T>
    qInterval2D<T>::qInterval2D()
	{
	}


    /*******************************************************************************
    * qInterval2D<T>::qInterval2D()
    *******************************************************************************/
    template<class T>
    qInterval2D<T>::qInterval2D(const qInterval2D<T>	&_rhs)
    : min(_rhs.min),
      max(_rhs.max)
	{
		// don't call operator= to avoid multiple assignments
	}


    /*******************************************************************************
    * qInterval2D<T>::qInterval2D()
    *******************************************************************************/
    template<class T>
    qInterval2D<T>::qInterval2D(const T _min,
                                const T	_max)
    : min(_min),
      max(_max)
	{
	}


    /*******************************************************************************
    * qInterval2D<T>::~qInterval2D()
    *******************************************************************************/
    template<class T>
    qInterval2D<T>::~qInterval2D()
	{
	}


    /*******************************************************************************
    * qInterval2D<T>::operator=
    *******************************************************************************/
    template<class T>
    qInterval2D<T>& qInterval2D<T>::operator=(const qInterval2D<T>	&_rhs)
    {
        // avoid selfcopy
        if (this != &_rhs)
        {
            min = _rhs.min;
            max = _rhs.max;
        }

        return *this;
    } // qInterval2D<T>::operator=


    /*******************************************************************************
    * qInterval2D<T>::operator==
    *******************************************************************************/
    template<class T>
    bool qInterval2D<T>::operator==(const qInterval2D<T>	&_rhs) const
    {
        return MU<T>::IsEqual(min, _rhs.min) &&
               MU<T>::IsEqual(max, _rhs.max);
    } // qInterval2D<T>::operator==


    /*******************************************************************************
    * qInterval2D<T>::operator!=
    *******************************************************************************/
    template<class T>
    bool qInterval2D<T>::operator!=(const qInterval2D<T>	&_rhs) const
    {
        return MU<T>::IsUnequal(min, _rhs.min) ||
               MU<T>::IsUnequal(max, _rhs.max);
    } // qInterval2D<T>::operator!=


    /*******************************************************************************
    * qInterval2D<T>::Set
    *******************************************************************************/
    template<class T>
    void qInterval2D<T>::Set(const T    _min,
                             const T	_max)
    {
        min = _min;
        max = _max;
    } // qInterval2D<T>::Set


    /*******************************************************************************
    * qInterval2D<T>::SetEmpty
    *******************************************************************************/
    template<class T>
    void qInterval2D<T>::SetEmpty()
	{
        min = max = 0;
    } // qInterval2D<T>::SetEmpty


    /*******************************************************************************
    * qInterval2D<T>::IsEmpty
    *******************************************************************************/
    template<class T>
    bool qInterval2D<T>::IsEmpty() const
	{
        return MU<T>::IsZero(min) &&
               MU<T>::IsZero(max);
    } // qInterval2D<T>::IsEmpty

} // namespace qLib
