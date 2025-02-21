/*******************************************************************************
* \file qThreadCb.h
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
#include "qBaseDefs.h"


namespace qLib
{
    /*******************************************************************************
    * \class qThreadCb
    *******************************************************************************/
    class qThreadCb
    {
        friend class qThread;

        protected:
            virtual void            OnThreadStarted(u32 _u32ThreadId);
            virtual void            OnThreadFinished(u32 _u32ThreadId);
    }; // class qThreadCb

} // namespace qLib
