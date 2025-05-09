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
#include <QJsonObject>
#include "aString.h"
#include "aPath.h"
#include "aUniquePtrVec.h"
#include "aVector.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
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
        aUniquePtrVec<QJsonObject>      m_vecObj;
        aVector<s32>                    m_vecIdx;

    public:
        aJsonFile(const aPath  &_sFilePath);
        virtual ~aJsonFile();

        void        openLevel();
        void        closeLevel(const aString &_sKey);

        void        add(const aJsonValue &_val);

        bool        write2File();

        bool        readAllValues(std::function<void(const aVector<aString>&, const aJsonValue&)> _f) const;

    private:
        void        readJsonObj(const QJsonObject                                   &_obj,
                                aVector<aString>                                    &_vecKeys,
                                std::function<void(const aVector<aString>&, const aJsonValue&)> _f) const;
}; // class aJsonFileI


} // namespace aUtil
} // namespace aLib


#endif // _USE_QT_
