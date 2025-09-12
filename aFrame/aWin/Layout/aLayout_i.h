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
#include "aWin_def.h"

#include "aRect.h"

using namespace std;
using namespace aFrame::aUtil;
using namespace aFrame::aWin;


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

        virtual aDimension          layoutDemand() const = 0;
        virtual void                arrange(const aRect &_r) = 0;

    protected:
        static aDimension           layoutDemandOfChild(const aBaseWin *_pChild);
}; // class aLayout_i


} // namespace aWin
} // namespace aFrame
