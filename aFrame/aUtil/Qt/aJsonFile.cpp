/*******************************************************************************
* \file aJsonFile.cpp
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
#include "aJsonFile.h"
#include "aJsonObj.h"
#include "aJsonValue.h"

using namespace std;

namespace aFrame {
namespace aUtil {


/*******************************************************************************
* aJsonFile::aJsonFile
*******************************************************************************/
aJsonFile::aJsonFile(const aPath    &_sFilePath)
: m_sFilePath(_sFilePath)
{
    // create the first (root) json object for readAllValues
    unique_ptr<QJsonObject> pObj = make_unique<QJsonObject> ();
    m_vecObj.push_back(move(pObj));
    m_vecIdx.push_back(m_vecObj.size() - 1);
} // aJsonFile::aJsonFile


/*******************************************************************************
* aJsonFile::~aJsonFile
*******************************************************************************/
aJsonFile::~aJsonFile()
{
} // aJsonFile::~aJsonFile


/*******************************************************************************
* aJsonFile::openLevel
*******************************************************************************/
void aJsonFile::openLevel()
{
    unique_ptr<QJsonObject> pObj = make_unique<QJsonObject> ();
    m_vecObj.push_back(move(pObj));
    m_vecIdx.push_back(m_vecObj.size() - 1);
} // aJsonFile::openLevel


/*******************************************************************************
* aJsonFile::closeLevel
*******************************************************************************/
void aJsonFile::closeLevel(const aString &_sKey)
{
    unique_ptr<QJsonObject> &pActive = m_vecObj.at(m_vecIdx.back());
    //unique_ptr<QJsonObject> &pActive = m_vecObj.back();

    // skip to previous level
    m_vecIdx.pop_back();
    unique_ptr<QJsonObject> &pPrev = m_vecObj.at(m_vecIdx.back());
    //unique_ptr<QJsonObject> &pPrev = m_vecObj.back();

    pPrev->insert(_sKey.toQString(), *pActive.get());
} // aJsonFile::closeLevel


/*******************************************************************************
* aJsonFile::add
*******************************************************************************/
void aJsonFile::add(const aJsonValue &_val)
{
    unique_ptr<QJsonObject> &pObj = m_vecObj.at(m_vecIdx.back());
    //unique_ptr<QJsonObject> &pObj = m_vecObj.back();

    if (_val.isBool())
    {
        pObj->insert(_val.key().toQString(), QJsonValue(_val.toBool()));
    }

    if (_val.isDbl())
    {
        pObj->insert(_val.key().toQString(), QJsonValue(_val.toDbl()));
    }

    if (_val.isString())
    {
        pObj->insert(_val.key().toQString(), QJsonValue(_val.toString().toQString()));
    }
} // aJsonFile::add


/*******************************************************************************
* aJsonFile::write2File
*******************************************************************************/
bool aJsonFile::write2File()
{
    QFile   file(m_sFilePath.canonicalPath().toQString());
    bool    bSuccess    = false;

    if (file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QJsonDocument jsonDoc(*m_vecObj.at(0));  // root obj at index 0
        file.write(jsonDoc.toJson());
        file.close();

        bSuccess = true;
    }

    return bSuccess;
} // aJsonFile::write2File


/*******************************************************************************
* aJsonFile::readStringValue
*******************************************************************************/
aString aJsonFile::readStringValue(const aString &_sNestedKey)
{
    CHECK_PRE_CONDITION(_sNestedKey != "", "");

    // eg. _sNestedKey = "key1:key2:color"

    aString         sValue;

    if (readJsonDoc()) // is only read once
    {
        aVector<aString>	vecToken;

        // split the keys
        _sNestedKey.splitString(":", vecToken);
        s32 s32KeyCount = vecToken.size();

        // get the root obj
        QJsonObject obj = m_jsonDoc.object();

        // dive into the keys until the last key is reached
        // last key defines the value
        // key1:key2:color => dive int key1 -> key2, color ist the value tag
        for (s32 i = 0; i < s32KeyCount - 1; i++)
        {
            QString sKey = vecToken.at(i).toQString();

            if (!obj.contains(sKey)) {
                //cout << "key >" << _sNestedKey << "< not found" << endl;
                return "";
            }
            else
            {
                obj = obj[sKey].toObject();
            }
        }

        // get the value
        QString sValueKey = vecToken.at(s32KeyCount - 1).toQString();

        if (!obj.contains(sValueKey))
        {
            //cout << "key " << _sNestedKey << " not found" << endl;
            return "";
        }
        else
        {
            sValue = aString::fromQString(obj[sValueKey].toString());
        }

    } // if (!m_jsonDoc.isEmpty())

    return sValue;
} // aJsonFile::readStringValue


/*******************************************************************************
* aJsonFile::readAllValues
*******************************************************************************/
bool aJsonFile::readAllValues(std::function<void(const aVector<aString>&, const aJsonValue&)> _f_fVal,
                              std::function<void(const aVector<aString>&, const aJsonObj&)> _fObj) const
{
    QFile               file(m_sFilePath.canonicalPath().toQString());
    QString             sJsonFile;
    bool                bSuccess    = false;
    aVector<aString>    vecKeys;

    if(file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        sJsonFile = file.readAll();
        QJsonDocument jsonDoc = QJsonDocument::fromJson(sJsonFile.toUtf8());

        // find the root object
        if (jsonDoc.isObject())
        {
            // start the iteration
            readJsonObj(jsonDoc.object(), vecKeys, _f_fVal, _fObj);

            bSuccess = true;
        } // if (jsonDoc.isObject())
    }

    return bSuccess;
} // aJsonFile::readAllValues


/*******************************************************************************
* aJsonFile::readJsonDoc
*******************************************************************************/
bool aJsonFile::readJsonDoc()
{
    // read the document in the first call
    if (m_jsonDoc.isEmpty())
    {
        QFile file(m_sFilePath.canonicalPath().toQString());

        // read the json document into the member variable
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            cout << "json file" << m_sFilePath.canonicalPath() << " not found" << endl;
        }
        else
        {
            QByteArray data = file.readAll();
            file.close();

            // JSON parsen
            QJsonParseError parseError;
            m_jsonDoc = QJsonDocument::fromJson(data, &parseError);

            if (parseError.error != QJsonParseError::NoError)
            {
                cout << "JSON Parse Error:" << aString::fromQString(parseError.errorString()) << endl;
            }
        }
    } // if (m_jsonDoc.isEmpty())

    return !m_jsonDoc.isEmpty();
} // aJsonFile::readJsonDoc


/*******************************************************************************
* aJsonFile::readJsonObj
*******************************************************************************/
void aJsonFile::readJsonObj(const QJsonObject                                   &_obj,
                            aVector<aString>                                    &_vecKeys,
                            std::function<void(const aVector<aString>&, const aJsonValue&)> _fVal,
                            std::function<void(const aVector<aString>&, const aJsonObj&)> _fObj) const
{
    QJsonObject::const_iterator     it;

    // iterate over all childs
    for (it = _obj.begin(); it != _obj.end(); it++)
    {
        if (it->isObject())
        {
            // add the key to the vector of keys
            _vecKeys.push_back(aString::fromQString(it.key()));

            // call callback handler for objects
            _fObj(_vecKeys, aJsonObj(it->toObject()));

            // if the child is another json object => next recursion
            readJsonObj(it->toObject(), _vecKeys, _fVal, _fObj);

            // remove the key from the vector of keys
            _vecKeys.pop_back();
        }
        else if (it->isBool())
        {
            aJsonValue  val(aString::fromQString(it.key()), it.value().toBool());
            _fVal(_vecKeys, val);
        }
        else if (it->isDouble())
        {
            aJsonValue  val(aString::fromQString(it.key()), it.value().toDouble());
            _fVal(_vecKeys, val);
        }
        else if (it->isString())
        {
            aJsonValue  val(aString::fromQString(it.key()), aString::fromQString(it.value().toString()));
            _fVal(_vecKeys, val);
        }
    } // for...
} // aJsonFile::readJsonObj


} // namespace aUtil
} // namespace aFrame


#endif // _USE_QT_

