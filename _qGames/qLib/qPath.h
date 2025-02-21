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
#include "qString16.h"


namespace qLib
{
    /*******************************************************************************
    * class qPath
    *******************************************************************************/
    class qPath : std::filesystem::path
    {
        public:
            qPath();
            qPath(const qString16  &_sPath);
            qPath(const std::filesystem::path  &_path);
            virtual ~qPath();

            qPath&          operator=(const char *_pStr);
            qPath&          operator=(const std::u16string &_str);

            qPath&          operator+=(const char *_pStr);
            qPath&          operator+=(const qString16 &_str);

            qPath           operator+(const char *_pStr) const;
            qPath           operator+(const qString16 &_str) const;

            qString16      GetCanonicalPath() const;

    }; // class qPath

} // namespace qLib
