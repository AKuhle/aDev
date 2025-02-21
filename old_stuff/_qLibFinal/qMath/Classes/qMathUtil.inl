/*******************************************************************************
* \file MU.inl
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
    * MU<T>::IsZero
    *******************************************************************************/
    template <class T>
    bool MU<T>::IsZero(const T		_t1)
    {
        return std::abs(_t1) < std::numeric_limits<T>::epsilon();
    } // MU<T>::IsZero


    /*******************************************************************************
    * MU<T>::IsEqual
    *******************************************************************************/
    template <class T>
    bool MU<T>::IsEqual(const T    _t1,
                        const T	_t2)
	{
		return std::abs(_t1 - _t2) < std::numeric_limits<T>::epsilon();
    } // MU<T>::IsEqual


    /*******************************************************************************
    * MU<T>::IsUnequal
    *******************************************************************************/
    template <class T>
    bool MU<T>::IsUnequal(const T  _t1,
                          const T	_t2)
	{
		return std::abs(_t1 - _t2) > std::numeric_limits<T>::epsilon();
    } // MU<T>::IsUnequal


    /*******************************************************************************
    * MU<T>::Abs
    *******************************************************************************/
    template <class T>
    T MU<T>::Abs(const T   _t)
    {
        return (_t < 0)?	-_t : _t;
    } // MU<T>::Abs


    /*******************************************************************************
    * MU<T>::Min
    *******************************************************************************/
    template <class T>
    T MU<T>::Min(const T _t1,
                 const T	_t2)
    {
        return std::min<T>(_t1, _t2);
    } // MU<T>::Min


    /*******************************************************************************
    * MU<T>::Min
    *******************************************************************************/
    template <class T>
    T MU<T>::Min(const T    _t1,
                 const T	_t2,
                 const T	_t3)
    {
        return std::min<T>(_t1, std::min<T>(_t2, _t3));
    } // MU<T>::Min


    /*******************************************************************************
    * MU<T>::Max
    *******************************************************************************/
    template <class T>
    T MU<T>::Max(const T    _t1,
                 const T    _t2)
    {
        return std::max<T>(_t1, _t2);
    } // MU<T>::Max


    /*******************************************************************************
    * MU<T>::Max
    *******************************************************************************/
    template <class T>
    T MU<T>::Max(const T    _t1,
                 const T	_t2,
                 const T	_t3)
    {
        return std::max<T> (_t1, std::max<T>(_t2, _t3));
    } // MU<T>::Max


    /*******************************************************************************
    * MU<T>::Max
    *******************************************************************************/
    template <class T>
    T MU<T>::Max(const T    _t1,
                 const T	_t2,
                 const T	_t3,
                 const T	_t4)
    {
        return std::max<T> (_t1, std::max<T>(_t2, std::max<T>(_t3, _t4)));
    } // MU<T>::Max


    /*******************************************************************************
    * MU<T>::Clamp
    *******************************************************************************/
    template <class T>
    T MU<T>::Clamp(const T _tValue,
                   const T	_tMin,
                   const T	_tMax)
	{
		return (_tValue < _tMin)?   _tMin :
			   (_tValue > _tMax)?   _tMax : _tValue;
    } // MU<T>::Clamp


    /*******************************************************************************
    * MU<T>::Ceil
    *******************************************************************************/
    template <class T>
    T MU<T>::Ceil(const T  _tValue,
                  const T	_tMultiple)
    {
        return (_tValue % _tMultiple == 0)?   _tValue : _tValue + (_tMultiple - _tValue%_tMultiple);
    } // MU<T>::Ceil


    /*******************************************************************************
    * MU<T>::SetBits
    *******************************************************************************/
    template<class T>
    void MU<T>::SetBits(T		&_tValue,
                        const T  _tBits2Set)
    {
        _tValue |= _tBits2Set;
    } // MU<T>::SetBits


    /*******************************************************************************
    * MU<T>::ClearBits
    *******************************************************************************/
    template<class T>
    void MU<T>::ClearBits(T          &_tValue,
                          const T    _tBits2Clear)
    {
        _tValue &= ~_tBits2Clear;
    } // MU<T>::ClearBits


    /*******************************************************************************
    * MU<T>::ToggleBits
    *******************************************************************************/
    template<class T>
    void MU<T>::ToggleBits(T         &_tValue,
                           const T   _tBits2Toggle)
    {
        _tValue ^= _tBits2Toggle;
    } // MU<T>::ToggleBits


    /*******************************************************************************
    * MU<T>::AreBitsSet
    *******************************************************************************/
    template<class T>
    bool MU<T>::AreBitsSet(const T    _tValue,
                          const T    _tBits2Check)
    {
        return (_tValue & _tBits2Check) == _tBits2Check;
    } // MU<T>::AreBitsSet


    /*******************************************************************************
    * MU<T>::AreBitsClear
    *******************************************************************************/
    template<class T>
    bool MU<T>::AreBitsClear(const T    _tValue,
                            const T    _tBits2Check)
    {
        return (_tValue & _tBits2Check) == 0;
    } // MU<T>::AreBitsClear

} // namespace qLib
