/*******************************************************************************
* \file aUrl_sys.cpp
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
#ifdef _USE_QT_


/*******************************************************************************
* includes
*******************************************************************************/
#include "aString.h"

#include "aUrl_sys.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aUtil {


/*******************************************************************************
* aUrl_sys::aUrl_sys
*******************************************************************************/
aUrl_sys::aUrl_sys()
{
} // aUrl_sys::aUrl_sys


/*******************************************************************************
* aUrl_sys::aUrl_sys
*******************************************************************************/
aUrl_sys::aUrl_sys(const aString  &_sUrl)
: QUrl(_sUrl.to_stdString().c_str())
{
} // aUrl_sys::aUrl_sys


/*******************************************************************************
* aUrl_sys::aUrl_sys
*******************************************************************************/
aUrl_sys::aUrl_sys(const SysUrl  &_url)
: QUrl(_url)
{
} // aUrl_sys::aUrl_sys


/*******************************************************************************
* aUrl_sys::~aUrl_sys
*******************************************************************************/
aUrl_sys::~aUrl_sys()
{
} // aUrl_sys::~aUrl_sys


/*******************************************************************************
* aUrl_sys::_isLocalFile
*******************************************************************************/
bool aUrl_sys::_isLocalFile() const
{
    return QUrl::isLocalFile();
} // aUrl_sys::_isLocalFile


/*******************************************************************************
* aUrl_sys::_toLocalFile
*******************************************************************************/
aString aUrl_sys::_toLocalFile() const
{
    return QUrl::toLocalFile().toStdString().c_str();
} // aUrl_sys::_toLocalFile


} // namespace aUtil
} // namespace aLib

#endif // _USE_QT_

