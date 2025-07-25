/*******************************************************************************
* \file aJsonFile.h
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
#include <QJsonDocument>
#include <QJsonObject>
#include "aString.h"
#include "aPath.h"
#include "aUniquePtrVec.h"
#include "aVector.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aFrame {
namespace aUtil {


/*******************************************************************************
* class aJsonFile
*******************************************************************************/
class aJsonValue;


/*******************************************************************************
* class aJsonFile
*******************************************************************************/
class aJsonFile
{
    private:
        aPath                           m_sFilePath;
        QJsonDocument                   m_jsonDoc;
        aUniquePtrVec<QJsonObject>      m_vecObj;
        aVector<s32>                    m_vecIdx;

    public:
        aJsonFile(const aPath  &_sFilePath);
        virtual ~aJsonFile();


        // write member
        void        openLevel();
        void        closeLevel(const aString &_sKey);

        void        add(const aJsonValue &_val);

        bool        write2File();


        // read member
        aString     readStringValue(const aString     &_sNestedKey);    // eg. "key1:key2:color"

        bool        readAllValues(std::function<void(const aVector<aString>&, const aJsonValue&)> _fVal,
                                  std::function<void(const aVector<aString>&, const aJsonObj&)> _fObj) const;

    private:
        bool        readJsonDoc();

        void        readJsonObj(const QJsonObject                                   &_obj,
                                aVector<aString>                                    &_vecKeys,
                                std::function<void(const aVector<aString>&, const aJsonValue&)> _fVal,
                                std::function<void(const aVector<aString>&, const aJsonObj&)> _fObj) const;
}; // class aJsonFileI


} // namespace aUtil
} // namespace aFrame


#endif // _USE_QT_
