/*******************************************************************************
* \file qBaseDefs.inl
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
    * IsZero
    *******************************************************************************/
    template <class T>
    bool IsZero(const T		_t1)
    {
        return std::abs(_t1) < std::numeric_limits<T>::epsilon();
    } // IsZero


    /*******************************************************************************
    * IsEqual
    *******************************************************************************/
    template <class T>
    bool IsEqual(const T    _t1,
                 const T	_t2)
	{
		return std::abs(_t1 - _t2) < std::numeric_limits<T>::epsilon();
	} // IsEqual


    /*******************************************************************************
    * IsUnequal
    *******************************************************************************/
    template <class T>
    bool IsUnequal(const T  _t1,
                   const T	_t2)
	{
		return std::abs(_t1 - _t2) > std::numeric_limits<T>::epsilon();
	} // IsUnequal


    /*******************************************************************************
    * Abs
    *******************************************************************************/
    template <class T>
    T Abs(const T   _t)
    {
        return (_t < 0)?	-_t : _t;
    } // Abs


    /*******************************************************************************
    * Min
    *******************************************************************************/
    template <class T>
    T Min(const T   _t1,
          const T	_t2)
    {
        return std::min<T>(_t1, _t2);
    } // Min


    /*******************************************************************************
    * Min
    *******************************************************************************/
    template <class T>
    T Min(const T   _t1,
          const T	_t2,
          const T	_t3)
    {
        return std::min<T>(_t1, std::min<T>(_t2, _t3));
    } // Min


    /*******************************************************************************
    * Max
    *******************************************************************************/
    template <class T>
    T Max(const T   _t1,
          const T	_t2)
    {
        return std::max<T>(_t1, _t2);
    } // Max


    /*******************************************************************************
    * Max
    *******************************************************************************/
    template <class T>
    T Max(const T   _t1,
          const T	_t2,
          const T	_t3)
    {
        return std::max<T> (_t1, std::max<T>(_t2, _t3));
    } // Max


    /*******************************************************************************
    * Clamp
    *******************************************************************************/
    template <class T>
    T Clamp(const T _tValue,
            const T	_tMin,
            const T	_tMax)
	{
		return (_tValue < _tMin)?   _tMin :
			   (_tValue > _tMax)?   _tMax : _tValue;
	} // Clamp


    /*******************************************************************************
    * Ceil
    *******************************************************************************/
    template <class T>
    T Ceil(const T  _tValue,
           const T	_tMultiple)
    {
        return (_tValue % _tMultiple == 0)?   _tValue : _tValue + (_tMultiple - _tValue%_tMultiple);
    } // Ceil


    /*******************************************************************************
    * Swap
    *******************************************************************************/
    template <class T>
    void Swap(T &_tValue1,
              T &_tValue2)
    {
        T   tHelp(_tValue1);

        _tValue1 = _tValue2;
        _tValue2 = tHelp;
    } // Swap


    /*******************************************************************************
    * SetBits
    *******************************************************************************/
    template<class T>
    void SetBits(T			&_tValue,
                 const T    _tBits2Set)
    {
        _tValue |= _tBits2Set;
    } // SetBits


    /*******************************************************************************
    * ClearBits
    *******************************************************************************/
    template<class T>
    void ClearBits(T		&_tValue,
                   const T  _tBits2Clear)
    {
        _tValue &= ~_tBits2Clear;
    } // ClearBits


    /*******************************************************************************
    * ToggleBits
    *******************************************************************************/
    template<class T>
    void ToggleBits(T       &_tValue,
                    const T	_tBits2Toggle)
    {
        _tValue ^= _tBits2Toggle;
    } // ToggleBits


    /*******************************************************************************
    * BitsSet
    *******************************************************************************/
    template<class T>
    bool BitsSet(const T    _tValue,
                 const T    _tBits2Check)
    {
        return (_tValue & _tBits2Check) == _tBits2Check;
    } // BitsSet


    /*******************************************************************************
    * BitsClear
    *******************************************************************************/
    template<class T>
    bool BitsClear(const T  _tValue,
                   const T  _tBits2Check)
    {
        return (_tValue & _tBits2Check) == 0;
    } // BitsClear

} // namespace qLib
