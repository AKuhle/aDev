/*******************************************************************************
* \file SysDlg.cpp
* \author Andreas Kuhlewind
*
* \brief
*
*  Detailed description starts here.
*******************************************************************************/
#ifdef _USE_QT_


/*******************************************************************************
* includes
*******************************************************************************/
#include <QFileDialog>
#include <QString>
#include "qSysDlg.h"
#include "qVec.h"
#include "qString16.h"


namespace qLib
{
    /*******************************************************************************
    * qSysDlg::GetFileOpenName
    *
    *   // sample fpr filter
    *   sFilter		=	"JSON-file (*.json)";
    *
    *   sFilter		=	"JPEG - File (*.jpg)";
    *   sFilter		+=	";;Windows oder OS/2 Bitmap (*.bmp)";
    *   sFilter		+=	";;tagged Image File Format (*.tif)";
    *   sFilter		+=	";;All Files (*.*)";
    *******************************************************************************/
    qString16 qSysDlg::GetFileOpenName(const qString16& _sTitle,
                                       const qString16& _sPath,
                                       const qString16& sFilter)
    {
        QString 	sFileName;

        sFileName = QFileDialog::getOpenFileName(nullptr,
                                                 QString::fromStdU16String(_sTitle.ToStdU16String()),
                                                 QString::fromStdU16String(_sPath.ToStdU16String()),
                                                 QString::fromStdU16String(sFilter.ToStdU16String()));

        return sFileName.toStdU16String();
    } // qSysDlg::GetFileOpenName


    /*******************************************************************************
    * qSysDlg::GetFileOpenNames
    *******************************************************************************/
    qVec<qString16> qSysDlg::GetFileOpenNames(const qString16& _sTitle,
                                              const qString16& _sPath,
                                              const qString16& sFilter)
    {
        QStringList         lstFileNames;
        qVec<qString16>     vecReturn;

        lstFileNames = QFileDialog::getOpenFileNames(nullptr,
                                                     QString::fromStdU16String(_sTitle.ToStdU16String()),
                                                     QString::fromStdU16String(_sPath.ToStdU16String()),
                                                     QString::fromStdU16String(sFilter.ToStdU16String()));

        for (QString    &s : lstFileNames)
        {
            vecReturn.push_back(s.toStdU16String());
        }

        return vecReturn;
    } // qSysDlg::GetFileOpenNames

} // namespace qLib


#endif // _USE_QT_
