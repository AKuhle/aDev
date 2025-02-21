/*******************************************************************************
* \file aStopwatch.cpp
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


/*******************************************************************************
* includes
*******************************************************************************/
#include "aStopwatch.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aUtil {


/*******************************************************************************
* aStopwatch::aStopwatch
*******************************************************************************/
aStopwatch::aStopwatch()
{
} // aStopwatch::aStopwatch


/*******************************************************************************
* aStopwatch::~aStopwatch
*******************************************************************************/
aStopwatch::~aStopwatch()
{
} // aStopwatch::~aStopwatch


/*******************************************************************************
* aStopwatch::start
*******************************************************************************/
void aStopwatch::start()
{
    m_start = std::chrono::high_resolution_clock::now();
} // aStopwatch::start


/*******************************************************************************
* aStopwatch::stop
*******************************************************************************/
u32 aStopwatch::stop()
{
    std::chrono::time_point<std::chrono::high_resolution_clock> end = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - m_start);

    return duration.count();
} // aStopwatch::stop


} // namespace aUtil
} // namespace aLib
