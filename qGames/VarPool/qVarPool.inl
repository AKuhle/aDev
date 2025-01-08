/*******************************************************************************
* \file qVarPool.inl
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
    * qVarPool::HasEnum
    *******************************************************************************/
    template <class T>
    bool qVarPool::HasEnum(u32 _u32ID) const
    {
        return m_mapEnum.find(_u32ID) != m_mapEnum.end();
    } // qVarPool::HasEnum


    /*******************************************************************************
    * qVarPool::AddEnum
    *******************************************************************************/
    template <class T>
    void qVarPool::AddEnum(u32  _u32ID,
                               T    _tValue,
                               T    _tDefault)
    {
        if (!HasEnum<T>(_u32ID))
        {
            qPoolVarS32    poolVar(static_cast<s32> (_tValue), static_cast<s32> (_tDefault));
            m_mapEnum[_u32ID] = poolVar;
        }
    } // qVarPool::AddEnum


    /*******************************************************************************
    * qVarPool::GetEnum
    *******************************************************************************/
    template <class T>
    T qVarPool::GetEnum(u32 _u32ID) const
    {
        std::map<u32, qPoolVarS32>::const_iterator cit;

        if ((cit = m_mapEnum.find(_u32ID)) != m_mapEnum.end())
        {
            return static_cast<T> (cit->second.Value());
        }

        return static_cast<T> (0);
    } // qVarPool::GetEnum


    /*******************************************************************************
    * qVarPool::SetEnumValue
    *******************************************************************************/
    template <class T>
    void qVarPool::SetEnumValue(u32	_u32ID,
                                    T   _tValue)
    {
        std::map<u32, qPoolVarS32>::iterator it;

        if ((it = m_mapEnum.find(_u32ID)) != m_mapEnum.end())
        {
            it->second.Value() = static_cast<s32> (_tValue);
        }
        else
        {
            AddEnum(_u32ID, static_cast<s32> (_tValue), static_cast<s32> (_tValue));
        }
    } // qVarPool::SetEnumValue


    /*******************************************************************************
    * qVarPool::SetEnumDefault
    *******************************************************************************/
    template <class T>
    void qVarPool::SetEnumDefault(u32	_u32ID,
                                      T     _tDefault)
    {
        std::map<u32, qPoolVarS32>::iterator it;

        if ((it = m_mapEnum.find(_u32ID)) != m_mapEnum.end())
        {
            it->second.Default() = static_cast<s32> (_tDefault);
        }
        else
        {
            AddEnum(_u32ID, static_cast<s32> (_tDefault), static_cast<s32> (_tDefault));
        }
    } // qVarPool::SetEnumDefault

} // namespace qLib
