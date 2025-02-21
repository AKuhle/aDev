/*******************************************************************************
* \file aThreadCb.h
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
#include "aWin/aWin_def.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aUtil {


/*******************************************************************************
* \class aThreadCb
*******************************************************************************/
class aThreadCb
{
    public:
        virtual void            onThreadStarted(u32 _u32ThreadId);
        virtual void            onThreadFinished(u32 _u32ThreadId);
}; // class aThreadCb


} // namespace aUtil
} // namespace aLib
