/*******************************************************************************
* \file qWin.h
* \author Andreas Kuhlewind
*
* \brief
*
*  Detailed description starts here.
*******************************************************************************/
#pragma once


/*******************************************************************************
* includes
*******************************************************************************/
#include "aFrame_def.h"

#include "aRect.h"

using namespace std;
using namespace aFrame::aUtil;


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aFrame {
namespace aWin {


/*******************************************************************************
* class aLayout_i
*******************************************************************************/
class aLayout_i
{
    protected:
        aLayout_i();

    public:
        virtual ~aLayout_i();

        virtual void                arrange(const aRect &_r) = 0;
}; // class aLayout_i


} // namespace aWin
} // namespace aFrame
