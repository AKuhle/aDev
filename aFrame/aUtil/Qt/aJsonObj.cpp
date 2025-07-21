/*******************************************************************************
* \file aJsonObj.cpp
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
#include "aJsonObj.h"

using namespace std;

namespace aFrame {
namespace aUtil {


/*******************************************************************************
* aJsonObj::aJsonObj
*******************************************************************************/
aJsonObj::aJsonObj()
{
} // aJsonObj::aJsonObj


/*******************************************************************************
* aJsonObj::aJsonObj
*******************************************************************************/
aJsonObj::aJsonObj(const QJsonObject  &_rhs)
: QJsonObject(_rhs)
{
} // aJsonObj::aJsonObj


/*******************************************************************************
* aJsonObj::~aJsonObj
*******************************************************************************/
aJsonObj::~aJsonObj()
{
} // aJsonObj::~aJsonObj


/*******************************************************************************
* aJsonObj::findString
*******************************************************************************/
aString aJsonObj::findString(const aString &_sKey) const
{
    QString     key = _sKey.toQString();
    aString     sVal;

    if (contains(key) && value(key).isString())
    {
        sVal = aString::fromQString(value(key).toString());
    }

    return sVal;
} // aJsonObj::findString


/*******************************************************************************
* aJsonObj::findS32
*******************************************************************************/
s32 aJsonObj::findS32(const aString &_sKey) const
{
    QString     key     = _sKey.toQString();
    s32         s32Val  = 0;

    if (contains(key) && value(key).isDouble())
    {
        s32Val = value(key).toInt(0);
    }

    return s32Val;
} // aJsonObj::findS32


/*******************************************************************************
* aJsonObj::findBool
*******************************************************************************/
bool aJsonObj::findBool(const aString &_sKey) const
{
    QString     key     = _sKey.toQString();
    bool        bVal    = false;

    if (contains(key) && value(key).isBool())
    {
        bVal = value(key).toBool(false);
    }

    return bVal;
} // aJsonObj::findBool


} // namespace aUtil
} // namespace aFrame


#endif // _USE_QT_

