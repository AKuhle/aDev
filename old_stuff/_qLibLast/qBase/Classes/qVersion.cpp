///////////////////////////////////////////////////////////////////////////////
//! \file qVersion.cpp
//! \brief verion info in the qFrame library
//!
//!	\author Andreas Kuhlewind
//
// $Revision: 69 $
// $LastChangedDate: 2010-08-17 14:10:45 +0200 (Di, 17 Aug 2010) $
// $LastChangedBy: akuhlewi $
///////////////////////////////////////////////////////////////////////////////


//------------------------------------------------------------------------------
// includes
//------------------------------------------------------------------------------
#include "qVersion.h"
#include "qString16.h"


namespace qLib
{
    /*******************************************************************************
    * qVersion::qVersion
    *******************************************************************************/
    qVersion::qVersion(const u32		_u32Major,
                     const u32		_u32Minor,
                     const u32		_u32Revision,
                     const u32		_u32Build)
    : m_u32Major(_u32Major),
      m_u32Minor(_u32Minor),
      m_u32Revision(_u32Revision),
      m_u32Build(_u32Build)
    {
    } // qVersion::qVersion


    /*******************************************************************************
    * qVersion::VersionString
    *******************************************************************************/
    qString16 qVersion::VersionString() const
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
    } // qVersion::VersionString

} // namespace qLib
