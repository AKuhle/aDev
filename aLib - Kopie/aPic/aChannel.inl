/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aPic {


/*******************************************************************************
* aChannel<T>::aChannel
*******************************************************************************/
template <class T>
aChannel<T>::aChannel(const aDimension2D<s32> &_d2d)
: m_s32W(_d2d.w()),
  m_s32H(_d2d.h()),
  m_u64ChannelSize_byte(static_cast<u64> (sizeof(T)) * _d2d.w() * _d2d.h())
{
    m_pData = new T[m_u64ChannelSize_byte];
} // aChannel<T>::::aChannel


/*******************************************************************************
* aChannel<T>::aChannel
*******************************************************************************/
template <class T>
aChannel<T>::aChannel(s32 _w,
                      s32 _h)
: m_s32W(_w),
  m_s32H(_h),
  m_u64ChannelSize_byte(static_cast<u64> (sizeof(T)) * _w * _h)
{
    m_pData = new T[m_u64ChannelSize_byte];
} // aChannel<T>::::aChannel


/*******************************************************************************
* aChannel<T>::::aChannel
*******************************************************************************/
template <class T>
aChannel<T>::aChannel(const aChannel &_rhs)
: m_s32W(_rhs.m_s32W),
  m_s32H(_rhs.m_s32H),
  m_u64ChannelSize_byte(_rhs.m_u64ChannelSize_byte)
{
    m_pData = new T[m_u64ChannelSize_byte];
    memcpy(m_pData, _rhs.m_pData, m_u64ChannelSize_byte);
} // aChannel<T>::::aChannel


/*******************************************************************************
* aChannel<T>::::~aChannel
*******************************************************************************/
template <class T>
aChannel<T>::~aChannel()
{
    delete m_pData;
} // aChannel<T>::::~aChannel8


/*******************************************************************************
* aChannel<T>::::clear
*******************************************************************************/
template <class T>
void aChannel<T>::clear()
{
    CHECK_PRE_CONDITION_VOID(m_pData != nullptr);

    memset(m_pData, 0, m_u64ChannelSize_byte);
} // // aChannel<T>::::clear


/*******************************************************************************
* aChannel<T>::::copyFromChannel
*******************************************************************************/
template <class T>
void aChannel<T>::copyFromChannel(const std::unique_ptr<aChannel> &_pChannel)
{
    CHECK_PRE_CONDITION_VOID(m_pData != nullptr);
    CHECK_PRE_CONDITION_VOID(_pChannel->m_pData != nullptr);

    memcpy(m_pData, _pChannel->m_pData, m_u64ChannelSize_byte);
} // // aChannel<T>::::copyFromChannel


/*******************************************************************************
* aChannel<T>::::setChannelValue
*******************************************************************************/
template <class T>
void aChannel<T>::setChannelValue(T    _tVal)
{
    CHECK_PRE_CONDITION_VOID(m_pData != nullptr);

    T   *p  = m_pData;

    for (s32 y = 0; y < m_s32H; y++)
    {
        for (s32 x = 0; x < m_s32W; x++)
        {
            *p++ = _tVal;
        }
    }
} // // aChannel<T>::::setChannelValue


} // namespace aPic
} // namespace aLib
