/*******************************************************************************
* \file BaseApp.h
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
#include "mainWin.h"
#include "ctrlPanel.h"

using namespace aLib::aWin;
using namespace std;


/*******************************************************************************
* MainWin::onUpdateCmd
*******************************************************************************/
void MainWin::onUpdateCmd(u64     _u64Cmd,
                          aDoc    */*_pDoc*/,
                          aView   */*_pView*/,
                          s64     /*_s64Param1*/,
                          s64     /*_s64Param2*/,
                          u64     /*_u64Param1*/,
                          u64     /*_u64Param2*/,
                          flt     /*_fltParam1*/,
                          flt     /*_fltParam2*/,
                          dbl     /*_dblParam1*/,
                          dbl     /*_dblParam2*/,
                          void    */*_pParam1*/,
                          void    */*_pParam2*/)
{
    // UPDATE_RESET_ALL
    if (isBitsSet(_u64Cmd, UPDATE_RESET_ALL))
    {
        if (m_pCtrlPanel != nullptr)
        {
            m_pCtrlPanel->resetAllChannels();

            _u64Cmd |= UPDATE_GUI;
        }
    }

    // UPDATE_GUI
    if (isBitsSet(_u64Cmd, UPDATE_GUI))
    {
        if (m_pCtrlPanel != nullptr)
        {
            m_pCtrlPanel->updateGui();
            updateAllCtrls();
        }
    }
} // MainWin::onUpdateCmd
