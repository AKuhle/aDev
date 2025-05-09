/*******************************************************************************
* \file aThreadCb_i.h
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
#include "aWin_def.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aUtil {


/*******************************************************************************
* \class aThreadCb_i
*******************************************************************************/
class aThreadCb_i
{
    public:
        virtual void            onThreadStarted(u32 _u32ThreadId) = 0;
        virtual void            onThreadFinished(u32 _u32ThreadId) = 0;
}; // class aThreadCb_i


} // namespace aUtil
} // namespace aLib
