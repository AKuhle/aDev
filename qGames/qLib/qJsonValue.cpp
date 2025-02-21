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
    * qJsonValue::qJsonValue
    *******************************************************************************/
    qJsonValue::qJsonValue(qString16    _sKey,
                           dbl          _dblValue)
    : m_sKey(_sKey),
      m_bIsDbl(true),
      m_dblValue(_dblValue)
    {
    } // qJsonValue::qJsonValue


    /*******************************************************************************
    * qJsonValue::qJsonValue
    *******************************************************************************/
    qJsonValue::qJsonValue(qString16    _sKey,
                           const qColor &_colValue)
    : m_sKey(_sKey),
      m_bIsColor(true),
      m_colValue(_colValue)
    {
    } // qJsonValue::qJsonValue


    /*******************************************************************************
    * qJsonValue::qJsonValue
    *******************************************************************************/
    qJsonValue::qJsonValue(qString16        _sKey,
                           const qString16  &_sValue)
    : m_sKey(_sKey),
      m_bIsString(true),
      m_sValue(_sValue)
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


    /*******************************************************************************
    * qJsonValue::IsDbl
    *******************************************************************************/
    bool qJsonValue::IsDbl() const
    {
        return m_bIsDbl;
    } // qJsonValue::IsDbl


    /*******************************************************************************
    * qJsonValue::ToDbl
    *******************************************************************************/
    dbl qJsonValue::ToDbl() const
    {
        if (IsDbl())
        {
            return m_dblValue;
        }

        return 0;
    } // qJsonValue::ToDbl


    /*******************************************************************************
    * qJsonValue::IsColor
    *******************************************************************************/
    bool qJsonValue::IsColor() const
    {
        return m_bIsColor;
    } // qJsonValue::IsColor


    /*******************************************************************************
    * qJsonValue::ToColor
    *******************************************************************************/
    qColor qJsonValue::ToColor() const
    {
        if (IsColor())
        {
            return m_colValue;
        }

        return qColor();
    } // qJsonValue::ToColor


    /*******************************************************************************
    * qJsonValue::IsString
    *******************************************************************************/
    bool qJsonValue::IsString() const
    {
        return m_bIsString;
    } // qJsonValue::IsString


    /*******************************************************************************
    * qJsonValue::ToString
    *******************************************************************************/
    qString16 qJsonValue::ToString() const
    {
        if (IsString())
        {
            return m_sValue;
        }

        return "";
    } // qJsonValue::ToString
} // namespace qLib
