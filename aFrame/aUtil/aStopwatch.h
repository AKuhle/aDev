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


/*******************************************************************************
* includes
*******************************************************************************/
#include "aFrame_def.h"

#include "aString.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aFrame {
namespace aUtil {


/*******************************************************************************
* class aStopwatch
*******************************************************************************/
class aStopwatch : std::filesystem::path
{
    private:
        std::chrono::time_point<std::chrono::high_resolution_clock>     m_start;

    public:
        aStopwatch();
        virtual ~aStopwatch();

        void            start();

        // returns the time between start and stop
        u32             stop();

}; // class aStopwatch


} // namespace aUtil
} // namespace aFrame
