/*******************************************************************************
* \file aThread_i.h
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
#include "aFrame_def.h"

using namespace aFrame;


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aFrame {
namespace aUtil {


/*******************************************************************************
* class aThread_i
*******************************************************************************/
class aThread_i
{
    public:
        virtual u32             id() const = 0;
        virtual void            sleep_ms(u32 _u32SleepTime_ms) const = 0;

        virtual void            startThread() = 0;

    protected:
        virtual void            onRun() = 0;

}; // class aThread_i


} // namespace aUtil
} // namespace aFrame
