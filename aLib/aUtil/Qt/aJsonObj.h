/*******************************************************************************
* \file aJsonObj.h
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
#pragma once

#ifdef _USE_QT_

/*******************************************************************************
* includes
*******************************************************************************/
#include <QJsonObject>

#include "aString.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aUtil {


/*******************************************************************************
* class aJsonObj
*******************************************************************************/
class aJsonObj : public QJsonObject
{
    public:
        aJsonObj();
        aJsonObj(const QJsonObject  &_rhs);

        virtual ~aJsonObj();


        aString         findString(const aString &_sKey) const;     // empty string for invalid strings
        s32             findS32(const aString &_sKey) const;        // 0 for invalid strings
        bool            findBool(const aString &_sKey) const;       // false for invalid strings

}; // class aJsonObjI


} // namespace aUtil
} // namespace aLib

#endif // _USE_QT_
