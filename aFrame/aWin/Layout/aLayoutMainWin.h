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
        unique_ptr<aTitleBar>       m_pTitleBar;
        list<unique_ptr<aToolBar>>  m_lstToolBar;


    public:
        aLayoutMainWin();
        virtual ~aLayoutMainWin();

        void                setTitleBar(unique_ptr<aTitleBar> _pTitleBar);
        const aTitleBar*    titleBar() const;
        aTitleBar*          titleBar();

        void                addToolBar(unique_ptr<aToolBar> _pToolBar);

        void                arrange(const aRect &_r) override;


    protected:
        aDimension          layoutMinDim() const override;
}; // class aLayoutMainWin


} // namespace aWin
} // namespace aFrame
