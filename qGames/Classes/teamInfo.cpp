/*******************************************************************************
* \file teamInfo.cpp
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


/*******************************************************************************
* includes
*******************************************************************************/
#include "teamInfo.h"
#include "qFile.h"

using namespace qLib;


/*******************************************************************************
* TeamInfo::TeamInfo
*******************************************************************************/
TeamInfo::TeamInfo()
{
} // TeamInfo::TeamInfo


/*******************************************************************************
* TeamInfo::~TeamInfo
*******************************************************************************/
TeamInfo::~TeamInfo()
{
} // TeamInfo::~TeamInfo


/*******************************************************************************
* TeamInfo::SetFigureFileName
*******************************************************************************/
void TeamInfo::SetFigureFileName(const qString16 &_sFile)
{
    qString16   sPath;
    qString16   sExt;
    qString16   sFullName;

    m_sFigureFileName = _sFile;

    qFile::SplitPath(m_sFigureFileName, sPath, m_sName, sExt, sFullName);

    m_pixmap.load(m_sFigureFileName.ToQString());

} // TeamInfo::SetFigureFileName
