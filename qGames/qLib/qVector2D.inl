/*******************************************************************************
* \file qVector2D.inl
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
    * qVector2D<T, Tprec>::qVector2D
    *******************************************************************************/
    template<class T, class Tprec>
    qVector2D<T, Tprec>::qVector2D()
	{
    } // qVector2D<T, Tprec>::qVector2D


    /*******************************************************************************
    * qVector2D<T, Tprec>::qVector2D
    *******************************************************************************/
    template<class T, class Tprec>
    qVector2D<T, Tprec>::qVector2D(const qVector2D<T, Tprec> &_rhs)
    : x(_rhs.x),
      y(_rhs.y)
	{
    } // qVector2D<T, Tprec>::qVector2D


	template<class T, class Tprec>
    /*******************************************************************************
    * qVector2D<T, Tprec>::qVector2D
    *******************************************************************************/
    qVector2D<T, Tprec>::qVector2D(T _x,
                                   T _y)
    : x(_x),
      y(_y)
    {
    } // qVector2D<T, Tprec>::qVector2D


    template<class T, class Tprec>
    qVector2D<T, Tprec>::~qVector2D()
	{
	}

	
    /*******************************************************************************
    * qVector2D<T, Tprec>::Set
    *******************************************************************************/
    template<class T, class Tprec>
    void qVector2D<T, Tprec>::Set(T _x,
                                  T _y)
	{
        x = _x;
        y = _y;
    } // qVector2D<T, Tprec>::Set


    /*******************************************************************************
    * qVector2D<T, Tprec>::operator=
    *******************************************************************************/
    template<class T, class Tprec>
    qVector2D<T, Tprec>& qVector2D<T, Tprec>::operator=(const qVector2D<T, Tprec>	&_rhs)
	{
		// avoid selfcopy
        x = _rhs.x;
        y = _rhs.y;

		return *this;
    } // qVector2D<T, Tprec>::operator=


    /*******************************************************************************
    * qVector2D<T, Tprec>::operator==
    *******************************************************************************/
    template<class T, class Tprec>
    bool qVector2D<T, Tprec>::operator==(const qVector2D<T, Tprec>	&_rhs) const
	{
        return MU<T>::IsEqual(x, _rhs.x) &&
               MU<T>::IsEqual(y, _rhs.y);
    } // qVector2D<T, Tprec>::operator==


    /*******************************************************************************
    * qVector2D<T, Tprec>::operator!=
    *******************************************************************************/
    template<class T, class Tprec>
    bool qVector2D<T, Tprec>::operator!=(const qVector2D<T, Tprec>	&_rhs) const
    {
        return MU<T>::IsUnequal(x, _rhs.x) ||
               MU<T>::IsUnequal(y, _rhs.y);
    } // qVector2D<T, Tprec>::operator!=


    /*******************************************************************************
    * qVector2D<T, Tprec>::operator+
    *******************************************************************************/
    template<class T, class Tprec>
    qVector2D<T, Tprec> qVector2D<T, Tprec>::operator+(const qVector2D<T, Tprec>	&_rhs) const
	{
        return	qVector2D<T, Tprec>(x + _rhs.x,
                                    y + _rhs.y);
    } // qVector2D<T, Tprec>::operator+

	
    /*******************************************************************************
    * qVector2D<T, Tprec>::operator-
    *******************************************************************************/
    template<class T, class Tprec>
    qVector2D<T, Tprec> qVector2D<T, Tprec>::operator-(const qVector2D<T, Tprec>	&_rhs) const
	{
        return qVector2D<T, Tprec>(x - _rhs.x,
                                   y - _rhs.y);
    } // qVector2D<T, Tprec>::operator-


    /*******************************************************************************
    * qVector2D<T, Tprec>::operator*
    *******************************************************************************/
    template<class T, class Tprec>
    qVector2D<T, Tprec> qVector2D<T, Tprec>::operator*(const Tprec	_t) const
	{
        return qVector2D<T, Tprec>((T) (((Tprec) x) * _t),
                                   (T) (((Tprec) y) * _t));
    } //  qVector2D<T, Tprec>::operator*


    /*******************************************************************************
    * qVector2D<T, Tprec>::operator/
    *******************************************************************************/
    template<class T, class Tprec>
    qVector2D<T, Tprec> qVector2D<T, Tprec>::operator/(const Tprec	_t) const
	{
        return qVector2D<T, Tprec>((T) (((Tprec) x) / _t),
                                   (T) (((Tprec) y) / _t));
    } // qVector2D<T, Tprec>::operator/


    /*******************************************************************************
    * qVector2D<T, Tprec>::operator==
    *******************************************************************************/
    template<class T, class Tprec>
    qVector2D<T, Tprec>& qVector2D<T, Tprec>::operator+=(const qVector2D<T, Tprec>	&_rhs)
	{
        x += _rhs.x;
        y += _rhs.y;

		return *this;
    } // qVector2D<T, Tprec>::operator==

	
    /*******************************************************************************
    * qVector2D<T, Tprec>::operator-=
    *******************************************************************************/
    template<class T, class Tprec>
    qVector2D<T, Tprec>& qVector2D<T, Tprec>::operator-=(const qVector2D<T, Tprec>	&_rhs)
	{
        x -= _rhs.x;
        y -= _rhs.y;

		return *this;
    } // qVector2D<T, Tprec>::operator-=
	

    /*******************************************************************************
    * qVector2D<T, Tprec>::operator*=
    *******************************************************************************/
    template<class T, class Tprec>
    qVector2D<T, Tprec>& qVector2D<T, Tprec>::operator*=(const Tprec	_t)
	{
        x = (T) (((Tprec) x) * _t);
        y = (T) (((Tprec) y) * _t);

		return *this;
    } // qVector2D<T, Tprec>::operator*=


    /*******************************************************************************
    * qVector2D<T, Tprec>::operator/=
    *******************************************************************************/
    template<class T, class Tprec>
    qVector2D<T, Tprec>& qVector2D<T, Tprec>::operator/=(const Tprec	_t)
	{
        x = (T) (((Tprec) x) / _t);
        y = (T) (((Tprec) y) / _t);

		return *this;
    } // qVector2D<T, Tprec>::operator/=


    /*******************************************************************************
    * qVector2D<T, Tprec>::Normalize
    *******************************************************************************/
    template<class T, class Tprec>
    void qVector2D<T, Tprec>::Normalize()
	{
		*this /= Norm();
    } // qVector2D<T, Tprec>::Normalize


    /*******************************************************************************
    * qVector2D<T, Tprec>::Norm
    *******************************************************************************/
    template<class T, class Tprec>
    Tprec qVector2D<T, Tprec>::Norm() const
	{
        return sqrt(((Tprec) x) * x + ((Tprec) y) * y);
    } // qVector2D<T, Tprec>::Norm


    /*******************************************************************************
    * qVector2D<T, Tprec>::NormSquare
    *******************************************************************************/
    template<class T, class Tprec>
    Tprec qVector2D<T, Tprec>::NormSquare() const
	{
        return ((Tprec) x) * x + ((Tprec) y) * y;
    } // qVector2D<T, Tprec>::NormSquare


    /*******************************************************************************
    * qVector2D<T, Tprec>::Distance
    *******************************************************************************/
    template<class T, class Tprec>
    Tprec qVector2D<T, Tprec>::Distance(const qVector2D<T, Tprec>	&_rhs) const
	{
        return ((*this) - _rhs).Norm();
    } // qVector2D<T, Tprec>::Distance


    /*******************************************************************************
    * ScalarProduct
    *******************************************************************************/
    template<class T, class Tprec>
    dbl qVector2D<T, Tprec>::ScalarProduct(const qVector2D<T, Tprec> &_rhs) const
    {
        return (dbl) (x * _rhs.x + y * _rhs.y);
    } // ScalarProduct

} // namespace qLib
