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
#include "aLayout_i.h"

using namespace std;
using namespace aFrame::aWin;


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aFrame {
namespace aWin {


/*******************************************************************************
* class aLayoutCentralWin
*******************************************************************************/
class aLayoutCentralWin : public aLayout_i
{
    protected:
        aBaseWin    *m_pCentralWin  { nullptr };

    protected:
        aLayoutCentralWin();

    public:
        virtual ~aLayoutCentralWin();

        void                setCentralWin(aBaseWin *_pWin)  { m_pCentralWin = _pWin; }
        const aBaseWin*     centralWin() const              { return m_pCentralWin; }
        aBaseWin*           centralWin()                    { return m_pCentralWin; }

        aDimension          layoutDemand() const override;
        void                arrange(const aRect &_r) override;
}; // class aLayoutCentralWin


} // namespace aWin
} // namespace aFrame
