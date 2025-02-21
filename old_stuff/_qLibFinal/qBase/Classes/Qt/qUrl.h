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

#ifdef _USE_QT_

/*******************************************************************************
* includes
*******************************************************************************/
#include <QUrl>

namespace qLib
{
    /*******************************************************************************
    * forward
    *******************************************************************************/
    class qString16;


    /*******************************************************************************
    * class qUrl
    *******************************************************************************/
    class qUrl : public QUrl
    {
        public:
            qUrl();
            qUrl(const qString16  &_sUrl);
            qUrl(const QUrl  &_url);
            virtual ~qUrl();

        public:
            bool            IsLocalFile() const;
            qString16       ToLocalFile() const;
    }; // class qUrlI

} // namespace qLib

#endif // _USE_QT_
