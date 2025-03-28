/*******************************************************************************
* \file aUrlQt.h
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
#include <QUrl>

#include "aUtil_def.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aUtil {
namespace SysQt {


/*******************************************************************************
* forward
*******************************************************************************/
class qString16;


/*******************************************************************************
* class aUrlQt
*******************************************************************************/
class aUrlQt : public QUrl
{
    public:
        aUrlQt();
        aUrlQt(const aString  &_sUrl);
        aUrlQt(const QUrl  &_url);
        virtual ~aUrlQt();

    public:
        bool            isLocalFile() const;
        aString         toLocalFile() const;
}; // class aUrlQtI


} // namespace SysQt
} // namespace aUtil
} // namespace aLib


#endif // _USE_QT_
