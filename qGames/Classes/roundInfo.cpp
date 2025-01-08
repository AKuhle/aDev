/*******************************************************************************
* \file RoundInfo.cpp
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
#include "roundInfo.h"

using namespace qLib;


/*******************************************************************************
* RoundInfo::RoundInfo
*******************************************************************************/
RoundInfo::RoundInfo(const qPath &_sGameDataPath)
: m_sGameDataPath(_sGameDataPath + "/")
{
} // RoundInfo::RoundInfo


/*******************************************************************************
* RoundInfo::~RoundInfo
*******************************************************************************/
RoundInfo::~RoundInfo()
{
} // RoundInfo::~RoundInfo


/*******************************************************************************
* RoundInfo::SetImage
*******************************************************************************/
void RoundInfo::SetImage(const qString16 &_sImage)
{
    qPath       s1 = m_sGameDataPath;
    qPath       s2 = s1 + _sImage;
    qString16   s3 = s2.GetCanonicalPath();
    QString     s4 = s3.ToQString();

    m_img.load(s4);
} // RoundInfo::SetImage
