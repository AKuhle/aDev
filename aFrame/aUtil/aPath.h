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
#include "aFrame_def.h"

#include "aString.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aFrame {
namespace aUtil {


/*******************************************************************************
* class aPath
*******************************************************************************/
class aPath : std::filesystem::path
{
    public:
        aPath();
        aPath(const aPath  &_sPath);
        aPath(const aString  &_sPath);
        aPath(const std::string  &_sPath);
        aPath(const std::filesystem::path &_path);
        aPath(const char *_pStr);
        virtual ~aPath();

        aPath&          operator=(const aPath &_path);
        aPath&          operator=(const std::filesystem::path &_path);
        aPath&          operator=(const char *_pStr);
        aPath&          operator=(const std::u16string &_str);

        aPath           operator/(const char *_pStr) const;
        aPath           operator/(const aString &_str) const;

        void            append(const aString &_str);

        aString         canonicalPath() const;

        void            splitPath(aPath&    _sPath,             // _spath, eg: "\temp\out\"
                                  aString&  _sName,             // _sname, eg: "test"
                                  aString&  _sExt,              // _sext, eg: ".txt"
                                  aString&  _sFullName) const;  // _sFullName, eg: "test.txt"
}; // class aPath


} // namespace aUtil
} // namespace aFrame
