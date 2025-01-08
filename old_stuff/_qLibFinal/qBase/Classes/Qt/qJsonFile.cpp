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
        //unique_ptr<QJsonObject> &pActive = m_vecObj.back();

        // skip to previous level
        m_vecIdx.pop_back();
        unique_ptr<QJsonObject> &pPrev = m_vecObj.at(m_vecIdx.back());
        //unique_ptr<QJsonObject> &pPrev = m_vecObj.back();

        pPrev->insert(_sKey.ToQString(), *pActive.get());
    } // qJsonFile::CloseLevel


    /*******************************************************************************
    * qJsonFile::Add
    *******************************************************************************/
    void qJsonFile::Add(const qJsonValue &_val)
    {
        unique_ptr<QJsonObject> &pObj = m_vecObj.at(m_vecIdx.back());
        //unique_ptr<QJsonObject> &pObj = m_vecObj.back();

        if (_val.IsBool())
        {
            pObj->insert(_val.Key().ToQString(), QJsonValue(_val.ToBool()));
        }

        if (_val.IsS32())
        {
            pObj->insert(_val.Key().ToQString(), QJsonValue(_val.ToS32()));
        }

        if (_val.IsDbl())
        {
            pObj->insert(_val.Key().ToQString(), QJsonValue(_val.ToDbl()));
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
            s32     s32KeySize = _vecKeys.size();

            if (it->isObject())
            {
                // if the child is another json object => next recursion
                _vecKeys.push_back(qString16::FromQString(it.key()));
                ReadJsonObj(it->toObject(), _vecKeys, _f);
                _vecKeys.pop_back();
            }

            else if (s32KeySize >= 2)
            {
                if (_vecKeys.at(s32KeySize - 2) == "bool")
                {
                    // bool value
                    qJsonValue  val(qString16::FromQString(it.key()),
                                    it.value().toBool());

                    // call the callback function
                    _f(_vecKeys, val);
                }

                else if (_vecKeys.at(s32KeySize - 2) == "s32")
                {
                    // s32 value
                    qJsonValue  val(qString16::FromQString(it.key()),
                                    static_cast<s32> (it.value().toInteger()));

                    // call the callback function
                    _f(_vecKeys, val);
                } // else if (it->isString())

                else if (_vecKeys.at(s32KeySize - 2) == "enum")
                {
                    // enum value
                    qJsonValue  val(qString16::FromQString(it.key()),
                                    static_cast<s32> (it.value().toInteger()));

                    // call the callback function
                    _f(_vecKeys, val);
                } // else if (it->isString())

                else if (_vecKeys.at(s32KeySize - 2) == "color")
                {
                    // enum value
                    qJsonValue  val(qString16::FromQString(it.key()),
                                    it.value().toDouble());

                    // call the callback function
                    _f(_vecKeys, val);
                } // else if (it->isString())

            } // else if (s32KeySize >= 2)
        } // for...
    } // qJsonFile::ReadJsonObj

} // namespace qLib

#endif // _USE_QT_

