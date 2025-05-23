/*******************************************************************************
* \file aPath.cpp
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
#include "aPath.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aUtil {


/*******************************************************************************
* aPath::aPath
*******************************************************************************/
aPath::aPath()
{
} // aPath::aPath


/*******************************************************************************
* aPath::aPath
*******************************************************************************/
aPath::aPath(const aPath  &_sPath)
: std::filesystem::path(_sPath)
{
} // aPath::aPath


/*******************************************************************************
* aPath::aPath
*******************************************************************************/
aPath::aPath(const aString  &_sPath)
: std::filesystem::path(_sPath.to_stdU16String())
{
} // aPath::aPath


/*******************************************************************************
* aPath::aPath
*******************************************************************************/
aPath::aPath(const std::filesystem::path  &_path)
: std::filesystem::path(_path)
{
} // aPath::aPath


/*******************************************************************************
* aPath::~aPath
*******************************************************************************/
aPath::~aPath()
{
} // aPath::~aPath


/*******************************************************************************
* aPath::operator=
*******************************************************************************/
aPath& aPath::operator=(const aPath &_path)
{
    *this += _path;

    return *this;
} // aPath::operator=


/*******************************************************************************
* aPath::operator=
*******************************************************************************/
aPath& aPath::operator=(const std::filesystem::path &_path)
{
    *this += _path;

    return *this;
} // aPath::operator=


/*******************************************************************************
* aPath::operator=
*******************************************************************************/
aPath& aPath::operator=(const char *_pStr)
{
    *this += _pStr;

    return *this;
} // aPath::operator=


/*******************************************************************************
* aPath::operator=
*******************************************************************************/
aPath& aPath::operator=(const std::u16string &_str)
{
    std::filesystem::path::operator=(_str);

    return *this;
} // aPath::operator=


/*******************************************************************************
* aPath::operator/
*******************************************************************************/
aPath aPath::operator/(const char *_pStr) const
{
    std::filesystem::path p = *this;
    p.append(_pStr);

    return p;
} // aPath::operator+=


/*******************************************************************************
* aPath::operator/
*******************************************************************************/
aPath aPath::operator/(const aString &_str) const
{
    std::filesystem::path p = *this;
    p.append(_str.to_stdU16String());

    return p;
} // aPath::operator+=


/*******************************************************************************
* aPath::canonicalPath
*******************************************************************************/
aString aPath::canonicalPath() const
{
    //std::string npath = pp.make_preferred().string();

    return std::filesystem::weakly_canonical(*this).u16string();
} // aPath::canonicalPath


/*******************************************************************************
* aPath::splitPath
*******************************************************************************/
void aPath::splitPath(aPath&    _sPath,             // _spath, eg: "\temp\out\"
                      aString&  _sName,             // _sname, eg: "test"
                      aString&  _sExt,              // _sext, eg: ".txt"
                      aString&  _sFullName) const   // _sFullName, eg: "test.txt"
{
    _sPath      = parent_path();            // Pfad zur Applikation
    _sName      = stem().string();          // Applikationsname ohne Extension
    _sExt       = extension().string();     // Extension
    _sFullName  = filename().string();      // Applikationsname mit Extension

} // aPath::splitPath


} // namespace aUtil
} // namespace aLib
