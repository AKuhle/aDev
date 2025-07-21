/*******************************************************************************
* \file aJsonValue.cpp
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

#include "aFrame_def.h"
#include "aJsonValue.h"

using namespace std;

/*******************************************************************************
* namespace
*******************************************************************************/
namespace aFrame {
namespace aUtil {


/*******************************************************************************
* aJsonValue::aJsonValue
*******************************************************************************/
aJsonValue::aJsonValue(aString  _sKey,
                       bool     _bValue)
: m_sKey(_sKey),
  m_bIsBool(true),
  m_bValue(_bValue)
{
} // aJsonValue::aJsonValue


/*******************************************************************************
* aJsonValue::aJsonValue
*******************************************************************************/
aJsonValue::aJsonValue(aString  _sKey,
                       dbl      _dblValue)
: m_sKey(_sKey),
  m_bIsDbl(true),
  m_dblValue(_dblValue)
{
} // aJsonValue::aJsonValue


/*******************************************************************************
* aJsonValue::aJsonValue
*******************************************************************************/
aJsonValue::aJsonValue(aString          _sKey,
                       const aString    &_sValue)
: m_sKey(_sKey),
  m_bIsString(true),
  m_sValue(_sValue)
{
} // aJsonValue::aJsonValue


/*******************************************************************************
* aJsonValue::~aJsonValue
*******************************************************************************/
aJsonValue::~aJsonValue()
{
} // aJsonValue::~aJsonValue


/*******************************************************************************
* aJsonValue::key
*******************************************************************************/
const aString& aJsonValue::key() const
{
    return m_sKey;
} // aJsonValue::key


/*******************************************************************************
* aJsonValue::isBool
*******************************************************************************/
bool aJsonValue::isBool() const
{
    return m_bIsBool;
} // aJsonValue::isBool


/*******************************************************************************
* aJsonValue::toBool
*******************************************************************************/
bool aJsonValue::toBool() const
{
    if (isBool())
    {
        return m_bValue;
    }

    return false;
} // aJsonValue::toBool


/*******************************************************************************
* aJsonValue::isDbl
*******************************************************************************/
bool aJsonValue::isDbl() const
{
    return m_bIsDbl;
} // aJsonValue::isDbl


/*******************************************************************************
* aJsonValue::toDbl
*******************************************************************************/
dbl aJsonValue::toDbl() const
{
    if (isDbl())
    {
        return m_dblValue;
    }

    return 0;
} // aJsonValue::toDbl


/*******************************************************************************
* aJsonValue::isString
*******************************************************************************/
bool aJsonValue::isString() const
{
    return m_bIsString;
} // aJsonValue::isString


/*******************************************************************************
* aJsonValue::toString
*******************************************************************************/
aString aJsonValue::toString() const
{
    if (isString())
    {
        return m_sValue;
    }

    return {};
} // aJsonValue::toString


} // namespace aUtil
} // namespace aFrame


#endif // _USE_QT_

