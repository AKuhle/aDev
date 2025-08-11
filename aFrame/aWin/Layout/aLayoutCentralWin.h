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
        SysWin          *m_pCentralWin  { nullptr };

    protected:
        aLayoutCentralWin();

    public:
        virtual ~aLayoutCentralWin();

        void                setCentralWin(SysWin *_pWin)    { m_pCentralWin = _pWin; }
        const SysWin*       centralWin() const              { return m_pCentralWin; }
        SysWin*             centralWin()                    { return m_pCentralWin; }

        void                arrange(const aRect &_r) override;
}; // class aLayoutCentralWin


} // namespace aWin
} // namespace aFrame
