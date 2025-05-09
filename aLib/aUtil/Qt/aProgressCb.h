/*******************************************************************************
* \file qBaseDefs.h
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
#include <QObject>

#include "aLib_def.h"

#include "aString.h"
#include "aProgressCbI.h"

using namespace aLib;


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aUtil {


/*******************************************************************************
* class aProgressCb
*******************************************************************************/
class aProgressCb : public QObject,
                    public aProgressCbI
{
    Q_OBJECT

    public slots:
        void                slotOpenProgressDisplay();
        void                slotCloseProgressDisplay();
        void                slotUpdateProgressDisplay(const QString &_sInfoText);
        void                slotUpdateProgressDisplay(u16 _u16Progress_pml);
}; // class aProgressCb


} // namespace aUtil
} // namespace aLib

#endif // _USE_QT_
