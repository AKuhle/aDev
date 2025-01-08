/*******************************************************************************
* \file qVersionInfo.cpp
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
#include "qVersionInfo.h"


namespace qLib {
namespace Object {


/*******************************************************************************
* qVersionInfo::qVersionInfo
*******************************************************************************/
qVersionInfo::qVersionInfo(const u32		_u32Major,
                           const u32		_u32Minor,
                           const u32		_u32Revision,
                           const u32		_u32Build)
: m_u32Major(_u32Major),
  m_u32Minor(_u32Minor),
  m_u32Revision(_u32Revision),
  m_u32Build(_u32Build)
{
} // qVersionInfo::qVersionInfo


/*******************************************************************************
* qVersionInfo::VersionString
*******************************************************************************/
qString16 qVersionInfo::VersionString() const
{
    qString16	sVersion;

    sVersion = qString16("V:") + qString16::FromValue(m_u32Major) +
               qString16(".") + qString16::FromValue(m_u32Minor) +
               qString16(".") + qString16::FromValue(m_u32Revision);

    if (m_u32Build > 0)
    {
        sVersion += qString16("-") + qString16::FromValue(m_u32Build);
    }

    return sVersion;
} // qVersionInfo::VersionString


} // namespace Object
} // namespace qLib
