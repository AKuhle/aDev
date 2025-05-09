/*******************************************************************************
* \file aVersionInfo.h
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
#pragma once


/*******************************************************************************
* includes
*******************************************************************************/
#include "aLib_def.h"
#include "aString.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aUtil {


/*******************************************************************************
* class aVersionInfo
*******************************************************************************/
class aVersionInfo
{
    private:
        u32			m_u32Major;
        u32			m_u32Minor;
        u32			m_u32Revision;
        u32			m_u32Build;

    public:
        aVersionInfo(const u32		_u32Major,
                     const u32		_u32Minor,
                     const u32		_u32Revision,
                     const u32		_u32Build);

        aString             versionString() const;
}; // class aVersionInfo


} // namespace aUtil
} // namespace aLib
