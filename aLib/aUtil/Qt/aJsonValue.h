/*******************************************************************************
* \file aJsonValue.h
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
#include "aUniquePtrVec.h"
#include "aVector.h"
#include "aColor.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aUtil {


/*******************************************************************************
* class aJsonValue
*******************************************************************************/
class aJsonValue
{
    private:
        aString       m_sKey;

        bool            m_bIsBool       { false };
        bool            m_bValue        { false };

        bool            m_bIsDbl        { false };
        dbl             m_dblValue      { 0 };

        bool            m_bIsString     { false };
        aString         m_sValue;


    public:
        aJsonValue(aString  _sKey,
                   bool     _bValue);

        aJsonValue(aString  _sKey,
                   dbl      _dblValue);

        aJsonValue(aString          _sKey,
                   const aString    &_sValue);

        virtual ~aJsonValue();

        const aString&          key() const;

        bool                    isBool() const;
        bool                    toBool() const;

        bool                    isDbl() const;
        dbl                     toDbl() const;

        bool                    isString() const;
        aString                 toString() const;
}; // class aJsonValueI


} // namespace aUtil
} // namespace aLib

#endif // _USE_QT_
