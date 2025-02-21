/*******************************************************************************
* \file qFile_Qt.cpp
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
#include "QDir"

#include "qFile.h"
#include "qString16.h"

#include <QFileInfo>
#include <QDir>

using namespace std;


namespace qLib
{
    /*******************************************************************************
    * qFile::SplitPath
    *******************************************************************************/
    void qFile::SplitPath(const qString16   &_sFilename,     // full path, eg: "c:\temp\out\test.txt"
                          qString16         &_sPath,         // _spath, eg: "c:\temp\out\"
                          qString16         &_sName,         // _sname, eg: "test"
                          qString16         &_sSuffix,		// _sext, eg: ".txt"
                          qString16         &_sFullName)     // _sFullName, eg: "test.txt"
    {
        QFileInfo   fi(_sFilename.ToQString());

        _sPath      = (fi.path() + ("/")).toStdU16String();
        _sName      = fi.baseName().toStdU16String();
        _sSuffix	= fi.completeSuffix().toStdU16String();
        _sFullName  = fi.fileName().toStdU16String();
    } // qFile::SplitPath


    /*******************************************************************************
    * qFile::GetFilesInDirectory
    *******************************************************************************/
    void qFile::GetFilesInDirectory(const qString16         &_sDir,
                                    const qList<qString16>  &_lstPattern,
                                    qList<qString16>        &_lstFiles,
                                    bool                    _bFullPath  /*= true*/
                                    /*bool                      _bRecursive  = false*/)
    {
        QDir            dir(_sDir.ToQString());
        QStringList     lstFilters;
        QFileInfoList   lstFileInfo;

        for (const qString16& sPattern : _lstPattern)
        {
            lstFilters << sPattern.ToQString();
        }

        lstFileInfo = dir.entryInfoList(lstFilters);

        for (QFileInfo &fi : lstFileInfo)
        {
            if (_bFullPath)
            {
                _lstFiles.push_back(qString16(fi.absoluteFilePath().toStdU16String()));
                    //fi.absoluteFilePath();
            }
            else
            {
                _lstFiles.push_back(qString16(fi.fileName().toStdU16String()));
            }
        }

//        qString16         sPattern;
//        _finddata_t		findData;
//        intptr_t		lHandle;

//            // set the pattern
//            sPattern = (_sPattern == "")?   "*.*" : _sPattern;

//            // Dateien suchen
//            lHandle = _findfirst((_sDir+sPattern).ToStdString().c_str(), &findData);
//            if (lHandle != -1)
//            {
//                do
//                {
//                    if (_bFullname)
//                        _lstFiles.AddBack(_sDir + nString(findData.name));
//                    else
//                        _lstFiles.AddBack(nString(findData.name));
//                } while (_findnext(lHandle, &findData) == 0);
//            }

//            _findclose(lHandle);
    } // qFile::GetFilesInDirectory

} // namespace qLib


#endif // _USE_QT_
