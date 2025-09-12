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
#include "aWin_def.h"
#include "aLayoutCentralWin.h"

using namespace std;
using namespace aFrame::aWin;


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aFrame {
namespace aWin {


/*******************************************************************************
* class aLayoutMainWin
*******************************************************************************/
class aLayoutMainWin : public aLayoutCentralWin
{
    private:
        unique_ptr<aTitleBar>   m_pTitleBar;

    public:
        aLayoutMainWin();
        virtual ~aLayoutMainWin();

        void                setTitleBar(unique_ptr<aTitleBar>   _pTitleBar);

        aDimension          layoutDemand() const override;
        void                arrange(const aRect &_r) override;
}; // class aLayoutMainWin


} // namespace aWin
} // namespace aFrame
