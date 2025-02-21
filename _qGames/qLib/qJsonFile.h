/*******************************************************************************
* \file qJsonFile.h
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


/*******************************************************************************
* includes
*******************************************************************************/
#include <QJsonObject>
#include "qString16.h"
#include "qUniquePtrVec.h"
#include "qVec.h"


namespace qLib
{
    /*******************************************************************************
    * class qJsonFile
    *******************************************************************************/
    class qJsonValue;


    /*******************************************************************************
    * class qJsonFile
    *******************************************************************************/
    class qJsonFile
    {
        private:
            qString16                       m_sFilename;
            qUniquePtrVec<QJsonObject>      m_vecObj;
            qVec<s32>                       m_vecIdx;

        public:
            qJsonFile(const qString16  &_sFilename);
            virtual ~qJsonFile();

            void        OpenLevel();
            void        CloseLevel(const qString16 &_sKey);

            void        Add(const qJsonValue &_val);

            bool        Write2File();

            bool        ReadAllValues(std::function<void(qVec<qString16>&, const QJsonValue&)> _f) const;

            // vor varppol
            bool        ReadAndParseAllValues(std::function<void(qVec<qString16>&, qJsonValue&)> _f) const;


        private:
            // vor varppol
            void        ReadJsonObj(const QJsonObject                                   &_obj,
                                    qVec<qString16>                                     &_vecKeys,
                                    std::function<void(qVec<qString16>&, const QJsonValue&)>  _f) const;

            // vor varppol
            void        ReadAndParseJsonObj(const QJsonObject                                   &_obj,
                                            qVec<qString16>                                     &_vecKeys,
                                            std::function<void(qVec<qString16>&, qJsonValue&)>  _f) const;
    }; // class qJsonFileI

} // namespace qLib
