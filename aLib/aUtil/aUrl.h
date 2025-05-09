/*******************************************************************************
* \file aUrl_sys.h
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
#include "aUtil_def.h"
#include "aUrl_sys.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aUtil {


/*******************************************************************************
* class aUrl
*******************************************************************************/
class aUrl : public aUrl_sys
{
    public:
        aUrl();
        aUrl(const aString  &_sUrl);
        aUrl(const SysUrl  &_url);
        virtual ~aUrl();

    public:
        bool            isLocalFile() const;
        aString         toLocalFile() const;

}; // class aUrl


} // namespace aUtil
} // namespace aLib
