/*******************************************************************************
* \file qVarPool.cpp
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
// #include <QJsonObject>
// #include <QJsonValue>
// #include <QJsonDocument>
// #include <QFile>

 #include "qGuiVarPool.h"


namespace qLib
{
    /*******************************************************************************
    * qGuiVarPool::qGuiVarPool
    *******************************************************************************/
    qGuiVarPool::qGuiVarPool()
    {
    } // qGuiVarPool::qGuiVarPool


    /*******************************************************************************
    * qGuiVarPool::qGuiVarPool
    *******************************************************************************/
    qGuiVarPool::qGuiVarPool(const qGuiVarPool		&_rhs)
    : qBaseVarPool(_rhs)
    {
    } // qGuiVarPool::qGuiVarPool


    /*******************************************************************************
    * qGuiVarPool::~qGuiVarPool
    *******************************************************************************/
    qGuiVarPool::~qGuiVarPool()
    {
    } // qGuiVarPool::~qGuiVarPool


    /*******************************************************************************
    * qGuiVarPool::operator=
    *******************************************************************************/
    qGuiVarPool& qGuiVarPool::operator=(const qGuiVarPool &_rhs)
    {
        // call the baseclass implementation
        qBaseVarPool::operator=(_rhs);

        // clear the previous stuff
        ClearAllEntries();

        return *this;
    } // qGuiVarPool::operator=


    /*******************************************************************************
    * qGuiVarPool::WriteToJsonFile
    *******************************************************************************/
    bool qGuiVarPool::WriteToJsonFile(const qString16 &_sFilename) const
    {
        bool bSuccess = qBaseVarPool::WriteToJsonFile(_sFilename);

        return bSuccess;
    } // qGuiVarPool::WriteToJsonFile


    /*******************************************************************************
    * qGuiVarPool::ReadFromJsonFile
    *******************************************************************************/
    bool qGuiVarPool::ReadFromJsonFile(const qString16 &_sFilename)
    {
        bool bSuccess = qBaseVarPool::ReadFromJsonFile(_sFilename);

        return bSuccess;
    } // qGuiVarPool::ReadFromJsonFile


    /*******************************************************************************
    * qGuiVarPool::ClearAllEntries
    *******************************************************************************/
    void qGuiVarPool::ClearAllEntries()
    {
        // call the baseclass implementation
        qBaseVarPool::ClearAllEntries();

    } // qGuiVarPool::ClearAllEntries
} // namespace qLib
