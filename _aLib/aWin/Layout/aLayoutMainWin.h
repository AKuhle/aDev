/*******************************************************************************
* \file aLayoutMainWin.h
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
#include "aWin/aWin_def.h"

#include "aWin/Layout/aLayoutCentralWin.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aWin {


/*******************************************************************************
* class aLayoutMainWin
*******************************************************************************/
class aLayoutMainWin : public aLayoutCentralWin
{
    private:
        aTitleBar   *m_pTitleBar    { nullptr };
        aStatusBar   *m_pStatusBar  { nullptr };

    public:
        aLayoutMainWin();
        ~aLayoutMainWin();

        void                        setTitleBar(aTitleBar *_pBar);
        aTitleBar*                  titleBar() const;

        void                        setStatusBar(aStatusBar *_pBar);
        aStatusBar*                 statusBar() const;
}; // class aLayoutMainWin


} // namespace aWin
} // namespace aLib
