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


/*******************************************************************************
* includes
*******************************************************************************/
#include <QObject>

#include "aLib_def.h"
#include "aUtil_def.h"

#include "aString.h"

using namespace aLib;


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aUtil {


/*******************************************************************************
* class aProgressMgrI
*******************************************************************************/
class aProgressMgrI
{
    public:
        virtual void        setProgressCb(aProgressCb *_pProgressCb) = 0;

        // member for displaying a progress text
        virtual bool        openDisplay(const aString &_sInfoText) = 0;

        // member for displaying a progress text and a value
        virtual bool        openDisplay(const aString   &_sInfoText,
                                        s64             _s64MinValue,
                                        s64             _s64MaxValue) = 0;

        virtual void        closeDisplay() = 0;

        // changes the values while the display is open
        virtual void        changeValues(s64   _s64MinValue,
                                         s64   _s64MaxValue,
                                         s64   _s64CurrentValue) = 0;

        virtual void        setInfo(const QString &_sInfoText) = 0;

        virtual void        setProgress(s64 _s64CurrentValue) = 0;

        virtual void        incrementProgress(s64 _s64Step = 1) = 0;

        virtual void        setUpdateDisplayDelta_pml(s16 _u16UpdateDisplayDelta_pml) = 0;
}; // class aProgressMgrI


} // namespace aUtil
} // namespace aLib

