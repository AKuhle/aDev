/*******************************************************************************
* \file aVersionInfo.cpp
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
#include "aVersionInfo.h"


namespace aLib {
namespace aUtil {


/*******************************************************************************
* aVersionInfo::aVersionInfo
*******************************************************************************/
aVersionInfo::aVersionInfo(const u32		_u32Major,
                           const u32		_u32Minor,
                           const u32		_u32Revision,
                           const u32		_u32Build)
: m_u32Major(_u32Major),
  m_u32Minor(_u32Minor),
  m_u32Revision(_u32Revision),
  m_u32Build(_u32Build)
{
} // aVersionInfo::aVersionInfo


/*******************************************************************************
* aVersionInfo::versionString
*******************************************************************************/
aString aVersionInfo::versionString() const
{
    aString sVersion;

    sVersion = aString("V:") + aString::fromValue(m_u32Major) +
               aString(".") + aString::fromValue(m_u32Minor) +
               aString(".") + aString::fromValue(m_u32Revision);

    if (m_u32Build > 0)
    {
        sVersion += aString("-") + aString::fromValue(m_u32Build);
    }

    return sVersion;
} // aVersionInfo::versionString


} // namespace aUtil
} // namespace aLib
