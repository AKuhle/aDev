/*******************************************************************************
* \file qPath.cpp
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
#include <QFileInfo>

#include "qPath.h"

using namespace std;

namespace qLib
{
    /*******************************************************************************
    * qPath::qPath
    *******************************************************************************/
    qPath::qPath()
    {
    } // qPath::qPath


    /*******************************************************************************
    * qPath::qPath
    *******************************************************************************/
    qPath::qPath(const qString16  &_sPath)
    : std::filesystem::path(_sPath.ToStdU16String())
    {
    } // qPath::qPath


    /*******************************************************************************
    * qPath::qPath
    *******************************************************************************/
    qPath::qPath(const std::filesystem::path  &_path)
    : std::filesystem::path(_path)
    {
    } // qPath::qPath


    /*******************************************************************************
    * qPath::~qPath
    *******************************************************************************/
    qPath::~qPath()
    {
    } // qPath::~qPath


    /*******************************************************************************
    * qPath::operator=
    *******************************************************************************/
    qPath& qPath::operator=(const char *_pStr)
    {
        *this += _pStr;

        return *this;
    } // qPath::operator=


    /*******************************************************************************
    * qPath::operator=
    *******************************************************************************/
    qPath& qPath::operator=(const std::u16string &_str)
    {
        std::filesystem::path::operator=(_str);

        return *this;
    } // qPath::operator=


    /*******************************************************************************
    * qPath::operator+=
    *******************************************************************************/
    qPath& qPath::operator+=(const char *_pStr)
    {
        std::filesystem::path::operator+=(_pStr);

        return *this;
    } // qPath::operator+=


    /*******************************************************************************
    * qPath::operator+=
    *******************************************************************************/
    qPath& qPath::operator+=(const qString16 &_str)
    {
        std::filesystem::path::operator +=(_str.ToStdU16String());

        return *this;
    } // qPath::operator+=


    /*******************************************************************************
    * qPath::operator+
    *******************************************************************************/
    qPath qPath::operator+(const char *_pStr) const
    {
        filesystem::path p = *this;
        p += _pStr;

        return qPath(p);
    } // qPath::operator+


    /*******************************************************************************
    * qPath::operator+
    *******************************************************************************/
    qPath qPath::operator+(const qString16 &_str) const
    {
        filesystem::path p = *this;
        p += _str.ToStdU16String();

        return qPath(p);
    } // qPath::operator+


    /*******************************************************************************
    * qPath::GetCanonicalPath
    *******************************************************************************/
    qString16 qPath::GetCanonicalPath() const
    {
        //std::string npath = pp.make_preferred().string();

        return std::filesystem::weakly_canonical(*this).u16string();
    } // qPath::GetCanonicalPath

} // namespace qLib
