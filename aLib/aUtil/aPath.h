/*******************************************************************************
* \file qUrl.h
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
* class aPath
*******************************************************************************/
class aPath : std::filesystem::path
{
    public:
        aPath();
        aPath(const aString  &_sPath);
        virtual ~aPath();

        aPath&          operator=(const char *_pStr);
        aPath&          operator=(const std::u16string &_str);

        aPath&          operator+=(const char *_pStr);
        aPath&          operator+=(const aString &_str);

        aString         canonicalPath() const;

}; // class aPath


} // namespace aUtil
} // namespace aLib
