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

#ifdef _USE_QT_


/*******************************************************************************
* includes
*******************************************************************************/
#include "aUrl_sysi.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aUtil {


/*******************************************************************************
* class aUrl_sys
*******************************************************************************/
class aUrl_sys : private QUrl,
                 public aUrl_sysi
{
    public:
        aUrl_sys();
        aUrl_sys(const aString  &_sUrl);
        aUrl_sys(const SysUrl  &_url);
        virtual ~aUrl_sys();


    /*******************************************************************************
    * aUrl_sys_sysi interface
    *******************************************************************************/
    protected:
        virtual bool        _isLocalFile() const override;
        virtual aString     _toLocalFile() const override;
}; // class aUrl_sysI


} // namespace aUtil
} // namespace aLib


#endif // _USE_QT_
