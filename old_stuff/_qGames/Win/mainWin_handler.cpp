/*******************************************************************************
* \file mainWin.cpp
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
#include "qGamesDefs.h"
#include "mainWin.h"


using namespace qLib;


/*******************************************************************************
* MainWin::OnUpdateCmd
*******************************************************************************/
void MainWin::OnUpdateCmd(u64         _u64Cmd,
                          qDocBase    */*_pDoc*/,
                          qViewBase   */*_pView*/,
                          s64         /*_s64Param1*/,
                          s64         /*_s64Param2*/,
                          u64         /*_u64Param1*/,
                          u64         /*_u64Param2*/,
                          flt         /*_fltParam1*/,
                          flt         /*_fltParam2*/,
                          dbl         /*_dblParam1*/,
                          dbl         /*_dblParam2*/,
                          void        */*_pParam1*/,
                          void        */*_pParam2*/)
{
    // UPDATE_VIEW
    if (MU<u64>::AreBitsSet(_u64Cmd, UPDATE_VIEW))
    {
    }

    // UPDATE_GUI
    if (MU<u64>::AreBitsSet(_u64Cmd, UPDATE_GUI))
    {
    }
} // MainWin::OnUpdateCmd


/*******************************************************************************
* MainWin::OnDropUrl
*******************************************************************************/
void MainWin::OnDropUrl(const qUrl  &_url)
{
    if (_url.IsLocalFile())
    {
        OpenFile(_url.ToLocalFile());
    }
} // MainWin::OnDropUrl
