namespace qLib
{
    /*******************************************************************************
    * qChannel<T>::qChannel
    *******************************************************************************/
    template <class T>
    qChannel<T>::qChannel(const qDimension2D<s32> &_d2d)
    : m_s32W(_d2d.w()),
      m_s32H(_d2d.h()),
      m_u64ChannelSize_byte(static_cast<u64> (sizeof(T)) * _d2d.w() * _d2d.h())
    {
        m_pData = new T[m_u64ChannelSize_byte];
    } // qChannel<T>::::qChannel


    /*******************************************************************************
    * qChannel<T>::qChannel
    *******************************************************************************/
    template <class T>
    qChannel<T>::qChannel(s32 _s32W,
                          s32 _s32H)
        : m_s32W(_s32W),
        m_s32H(_s32H),
        m_u64ChannelSize_byte(static_cast<u64> (sizeof(T)) * _s32W * _s32H)
    {
        m_pData = new T[m_u64ChannelSize_byte];
    } // qChannel<T>::::qChannel


    /*******************************************************************************
    * qChannel<T>::::qChannel
    *******************************************************************************/
    template <class T>
    qChannel<T>::qChannel(const qChannel &_rhs)
    : m_s32W(_rhs.m_s32W),
      m_s32H(_rhs.m_s32H),
      m_u64ChannelSize_byte(_rhs.m_u64ChannelSize_byte)
    {
        m_pData = new T[m_u64ChannelSize_byte];
        memcpy(m_pData, _rhs.m_pData, m_u64ChannelSize_byte);
    } // qChannel<T>::::qChannel


    /*******************************************************************************
    * qChannel<T>::::~qChannel
    *******************************************************************************/
    template <class T>
    qChannel<T>::~qChannel()
    {
        delete m_pData;
    } // qChannel<T>::::~qChannel8


    /*******************************************************************************
    * qChannel<T>::::ClearChannel
    *******************************************************************************/
    template <class T>
    void qChannel<T>::ClearChannel()
    {
        CHECK_PRE_CONDITION_VOID(m_pData != nullptr);

        memset(m_pData, 0, m_u64ChannelSize_byte);
    } // // qChannel<T>::::ClearChannel


    /*******************************************************************************
    * qChannel<T>::::CopyFromChannel
    *******************************************************************************/
    template <class T>
    void qChannel<T>::CopyFromChannel(const std::unique_ptr<qChannel> &_pChannel)
    {
        CHECK_PRE_CONDITION_VOID(m_pData != nullptr);
        CHECK_PRE_CONDITION_VOID(_pChannel->m_pData != nullptr);

        memcpy(m_pData, _pChannel->m_pData, m_u64ChannelSize_byte);
    } // // qChannel<T>::::CopyFromChannel


    /*******************************************************************************
    * qChannel<T>::::SetChannelValue
    *******************************************************************************/
    template <class T>
    void qChannel<T>::SetChannelValue(T    _tVal)
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
    } // // qChannel<T>::::SetChannelValue

} // namespace qLib
