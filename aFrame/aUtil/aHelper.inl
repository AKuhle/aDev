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


/*******************************************************************************
* includes
*******************************************************************************/


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aFrame {
namespace aUtil {


/*******************************************************************************
* min
*******************************************************************************/
template <class T>
T min(const T _t1,
      const T _t2)
{
    return std::min<T>(_t1, _t2);
} // min


/*******************************************************************************
* max
*******************************************************************************/
template <class T>
T max(const T    _t1,
      const T    _t2)
{
    return std::max<T>(_t1, _t2);
} // max


/*******************************************************************************
* clamp
*******************************************************************************/
template <class T>
T clamp(const T _tValue,
        const T	_tMin,
        const T	_tMax)
{
    return (_tValue < _tMin)?   _tMin :
           (_tValue > _tMax)?   _tMax : _tValue;
} // clamp


/*******************************************************************************
* isZero
*******************************************************************************/
template <class T>
bool isZero(const T _t1)
{
    return std::abs(_t1) < std::numeric_limits<T>::epsilon();
} // isZero


/*******************************************************************************
* isEqual
*******************************************************************************/
template <class T>
bool isEqual(const T    _t1,
             const T	_t2)
{
    return std::abs(_t1 - _t2) < std::numeric_limits<T>::epsilon();
} // isEqual


/*******************************************************************************
* isUnequal
*******************************************************************************/
template <class T>
bool isUnequal(const T  _t1,
               const T	_t2)
{
    return std::abs(_t1 - _t2) > std::numeric_limits<T>::epsilon();
} // isUnequal


/*******************************************************************************
* setBits
*******************************************************************************/
template<class T>
void setBits(T			&_tValue,
             const T    _tBits2Set)
{
    _tValue |= _tBits2Set;
} // setBits


/*******************************************************************************
* clearBits
*******************************************************************************/
template<class T>
void clearBits(T		&_tValue,
               const T  _tBits2Clear)
{
    _tValue &= ~_tBits2Clear;
} // clearBits


/*******************************************************************************
* toggleBits
*******************************************************************************/
template<class T>
void toggleBits(T       &_tValue,
                const T	_tBits2Toggle)
{
    _tValue ^= _tBits2Toggle;
} // toggleBits


/*******************************************************************************
* isBitsSet
*******************************************************************************/
template<class T>
bool isBitsSet(const T    _tValue,
               const T    _tBits2Check)
{
    return (_tValue & _tBits2Check) == _tBits2Check;
} // isBitsSet


/*******************************************************************************
* isBitsClear
*******************************************************************************/
template<class T>
bool isBitsClear(const T  _tValue,
                 const T  _tBits2Check)
{
    return (_tValue & _tBits2Check) == 0;
} // isBitsClear


} // namespace aUtil
} // namespace aFrame
