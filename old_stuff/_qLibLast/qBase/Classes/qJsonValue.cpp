/*******************************************************************************
* \file qJsonValue.cpp
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
#ifdef _USE_QT_


/*******************************************************************************
* includes
*******************************************************************************/
#include <QFile>
#include <QJsonValue>
#include <QJsonDocument>

#include "qBaseDefs.h"
#include "qJsonValue.h"

using namespace std;

namespace qLib
{
    /*******************************************************************************
    * qJsonValue::qJsonValue
    *******************************************************************************/
    qJsonValue::qJsonValue(qString16    _sKey,
                           bool         _bValue)
    : m_sKey(_sKey),
      m_bIsBool(true),
      m_bValue(_bValue)
    {
    } // qJsonValue::qJsonValue


    /*******************************************************************************
    * qJsonValue::qJsonValue
    *******************************************************************************/
    qJsonValue::qJsonValue(qString16    _sKey,
                           s32          _s32Value)
    : m_sKey(_sKey),
      m_bIsS32(true),
      m_s32Value(_s32Value)
    {
    } // qJsonValue::qJsonValue


    /*******************************************************************************
    * qJsonValue::~qJsonValue
    *******************************************************************************/
    qJsonValue::~qJsonValue()
    {
    } // qJsonValue::~qJsonValue


    /*******************************************************************************
    * qJsonValue::Key
    *******************************************************************************/
    const qString16& qJsonValue::Key() const
    {
        return m_sKey;
    } // qJsonValue::Key


    /*******************************************************************************
    * qJsonValue::IsBool
    *******************************************************************************/
    bool qJsonValue::IsBool() const
    {
        return m_bIsBool;
    } // qJsonValue::IsBool


    /*******************************************************************************
    * qJsonValue::ToBool
    *******************************************************************************/
    bool qJsonValue::ToBool() const
    {
        if (IsBool())
        {
            return m_bValue;
        }

        return false;
    } // qJsonValue::ToBool


    /*******************************************************************************
    * qJsonValue::IsS32
    *******************************************************************************/
    bool qJsonValue::IsS32() const
    {
        return m_bIsS32;
    } // qJsonValue::IsS32


    /*******************************************************************************
    * qJsonValue::ToS32
    *******************************************************************************/
    s32 qJsonValue::ToS32() const
    {
        if (IsS32())
        {
            return m_s32Value;
        }

        return 0;
    } // qJsonValue::ToS32

} // namespace qLib

#endif // _USE_QT_

