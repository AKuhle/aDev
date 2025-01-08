/*******************************************************************************
* \file qDimension2D.inl
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
    * qDimension2D<T>::qDimension2D()
    *******************************************************************************/
    template<class T>
    qDimension2D<T>::qDimension2D()
	{
	}


    /*******************************************************************************
    * qDimension2D<T>::qDimension2D()
    *******************************************************************************/
    template<class T>
    qDimension2D<T>::qDimension2D(const qDimension2D<T>	&_rhs)
    : w(_rhs.w),
      h(_rhs.h)
	{
		// don't call operator= to avoid multiple assignments
	}


    /*******************************************************************************
    * qDimension2D<T>::qDimension2D()
    *******************************************************************************/
    template<class T>
    qDimension2D<T>::qDimension2D(const T		_w,
                                  const T		_h)
    : w(_w),
      h(_h)
	{
	}


    /*******************************************************************************
    * qDimension2D<T>::~qDimension2D()
    *******************************************************************************/
    template<class T>
    qDimension2D<T>::~qDimension2D()
	{
	}


    /*******************************************************************************
    * qDimension2D<T>::operator=
    *******************************************************************************/
    template<class T>
    qDimension2D<T>& qDimension2D<T>::operator=(const qDimension2D<T>	&_rhs)
    {
        // avoid selfcopy
        if (this != &_rhs)
        {
            w = _rhs.w;
            h = _rhs.h;
        }

        return *this;
    } // qDimension2D<T>::operator=


    /*******************************************************************************
    * qDimension2D<T>::operator==
    *******************************************************************************/
    template<class T>
    bool qDimension2D<T>::operator==(const qDimension2D<T>	&_rhs) const
    {
        return MU<T>::IsEqual(w, _rhs.w) &&
               MU<T>::IsEqual(h, _rhs.h);
    } // qDimension2D<T>::operator==


    /*******************************************************************************
    * qDimension2D<T>::operator!=
    *******************************************************************************/
    template<class T>
    bool qDimension2D<T>::operator!=(const qDimension2D<T>	&_rhs) const
    {
        return MU<T>::IsUnequal(w, _rhs.w) ||
               MU<T>::IsUnequal(h, _rhs.h);
    } // qDimension2D<T>::operator!=


    /*******************************************************************************
    * qDimension2D<T>::operator+=
    *******************************************************************************/
    template<class T>
    qDimension2D<T>& qDimension2D<T>::operator+=(const qDimension2D<T> &_rhs)
    {
        w += _rhs.w;
        h += _rhs.h;

        return *this;
    } // qDimension2D<T>::operator+=


    /*******************************************************************************
    * qDimension2D<T>::operator*=
    *******************************************************************************/
    template<class T>
    qDimension2D<T>& qDimension2D<T>::operator*=(double _dblMuliplicator)
    {
        w *= _dblMuliplicator;
        h *= _dblMuliplicator;

        return *this;
    } // qDimension2D<T>::operator*=


    /*******************************************************************************
    * qDimension2D<T>::operator*
    *******************************************************************************/
    template<class T>
    qDimension2D<T> qDimension2D<T>::operator*(double	_dblMuliplicator) const
    {
        return qDimension2D<T> ((T) (((dbl) w) * _dblMuliplicator),
                                (T) (((dbl) h) * _dblMuliplicator));
    } // qDimension2D<T>::operator*


    /*******************************************************************************
    * qDimension2D<T>::Set
    *******************************************************************************/
    template<class T>
    void qDimension2D<T>::Set(const T		_w,
                              const T		_h)
    {
        w = _w;
        h = _h;
    } // qDimension2D<T>::Set


    /*******************************************************************************
    * qDimension2D<T>::SetEmpty
    *******************************************************************************/
    template<class T>
    void qDimension2D<T>::SetEmpty()
	{
        w = h = 0;
    } // qDimension2D<T>::SetEmpty


    /*******************************************************************************
    * qDimension2D<T>::IsEmpty
    *******************************************************************************/
    template<class T>
    bool qDimension2D<T>::IsEmpty() const
	{
        return MU<T>::IsZero(w) &&
               MU<T>::IsZero(h);
    } // qDimension2D<T>::IsEmpty

} // namespace qLib
