/*******************************************************************************
* \file qJsonFile.cpp
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
#include "qJsonFile.h"
#include "qJsonValue.h"

using namespace std;

namespace qLib
{
    /*******************************************************************************
    * qJsonFile::qJsonFile
    *******************************************************************************/
    qJsonFile::qJsonFile(const qString16  &_sFilename)
    : m_sFilename(_sFilename)
    {
        // create the first (root) json object
        unique_ptr<QJsonObject> pObj = make_unique<QJsonObject> ();
        m_vecObj.push_back(move(pObj));
        m_vecIdx.push_back(m_vecObj.size() - 1);
    } // qJsonFile::qJsonFile


    /*******************************************************************************
    * qJsonFile::~qJsonFile
    *******************************************************************************/
    qJsonFile::~qJsonFile()
    {
    } // qJsonFile::~qJsonFile


    /*******************************************************************************
    * qJsonFile::OpenLevel
    *******************************************************************************/
    void qJsonFile::OpenLevel()
    {
        unique_ptr<QJsonObject> pObj = make_unique<QJsonObject> ();
        m_vecObj.push_back(move(pObj));
        m_vecIdx.push_back(m_vecObj.size() - 1);
    } // qJsonFile::OpenLevel


    /*******************************************************************************
    * qJsonFile::CloseLevel
    *******************************************************************************/
    void qJsonFile::CloseLevel(const qString16 &_sKey)
    {
        unique_ptr<QJsonObject> &pActive = m_vecObj.at(m_vecIdx.back());

        // skip to previous level
        m_vecIdx.pop_back();
        unique_ptr<QJsonObject> &pPrev = m_vecObj.at(m_vecIdx.back());

        pPrev->insert(_sKey.ToQString(), *pActive.get());
    } // qJsonFile::CloseLevel


    /*******************************************************************************
    * qJsonFile::Add
    *******************************************************************************/
    void qJsonFile::Add(const qJsonValue &_val)
    {
        unique_ptr<QJsonObject> &pObj = m_vecObj.at(m_vecIdx.back());

        if (_val.IsBool())
        {
            pObj->insert(_val.Key().ToQString(), QJsonValue(_val.ToBool()));
        }

        if (_val.IsS32())
        {
            qString16 s = qString16("s32_") + qString16::FromValue(_val.ToS32());
            pObj->insert(_val.Key().ToQString(), QJsonValue(s.ToQString()));
        }
    } // qJsonFile::Add


    /*******************************************************************************
    * qJsonFile::Write2File
    *******************************************************************************/
    bool qJsonFile::Write2File()
    {
        QFile   file(m_sFilename.ToQString());
        bool    bSuccess    = false;

        if (file.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            QJsonDocument jsonDoc(*m_vecObj.at(0));  // root obj at index 0
            file.write(jsonDoc.toJson());
            file.close();

            bSuccess = true;
        }

        return bSuccess;
    } // qJsonFile::Write2File


    /*******************************************************************************
    * qJsonFile::ReadAllValues
    *******************************************************************************/
    bool qJsonFile::ReadAllValues(std::function<void(qVec<qString16>&, qJsonValue&)> _f) const
    {
        QFile           file(m_sFilename.ToQString());
        QString         sJsonFile;
        bool            bSuccess    = false;
        qVec<qString16> vecKeys;

        if(file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            sJsonFile = file.readAll();
            QJsonDocument jsonDoc = QJsonDocument::fromJson(sJsonFile.toUtf8());

            // find the root object
            if (jsonDoc.isObject())
            {
                // start the iteration
                ReadJsonObj(jsonDoc.object(), vecKeys, _f);

                bSuccess = true;
            } // if (jsonDoc.isObject())
        }

        return bSuccess;
    } // qJsonFile::ReadAllValues


    /*******************************************************************************
    * qJsonFile::ReadJsonObj
    *******************************************************************************/
    void qJsonFile::ReadJsonObj(const QJsonObject                                   &_obj,
                                qVec<qString16>                                     &_vecKeys,
                                std::function<void(qVec<qString16>&, qJsonValue&)>  _f) const
    {
        QJsonObject::const_iterator     it;

        // iterate over all childs
        for (it = _obj.begin(); it != _obj.end(); it++)
        {
            if (it->isObject())
            {
                // if the child is another json object => next recursion
                _vecKeys.push_back(qString16::FromQString(it.key()));
                ReadJsonObj(it->toObject(), _vecKeys, _f);
                _vecKeys.pop_back();
            }

            else if (it->isBool())
            {
                // bool value
                qJsonValue  val(qString16::FromQString(it.key()), it.value().toBool());

                _f(_vecKeys, val);
            }

            else if (it->isDouble())
            {
                // bool value
                qJsonValue  val(qString16::FromQString(it.key()), it.value().toDbl());

                _f(_vecKeys, val);
            }

            // else if (it->isString())
            // {
            //     // string can be several datatypes
            //     qString16   sID     = qString16::FromQString(it.value().toString().left(4));
            //     qString16   sVal    = qString16::FromQString(it.value().toString().mid(4));


            //     // s32 value
            //     if (sID == "s32_")
            //     {
            //         qJsonValue  val(qString16::FromQString(it.key()), sVal.To_s32());
            //         _f(_vecKeys, val);
            //     }
            // } // else if (it->isString())
        } // for...
    } // qJsonFile::ReadJsonObj

} // namespace qLib

#endif // _USE_QT_

