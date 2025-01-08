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
* MainWin::OnRegisterCtrl
*******************************************************************************/
void MainWin::OnRegisterCtrl()
{
} // MainWin::OnRegisterCtrl


/*******************************************************************************
* MainWin::OnUpdateCtrl
*******************************************************************************/
void MainWin::OnUpdateCtrl(qCtrlBase */*_pCtrl*/)
{
} // MainWin::OnUpdateCtrl


/*******************************************************************************
* MainWin::OnCtrlClicked
*******************************************************************************/
void MainWin::OnCtrlClicked(qCtrlBase *_pCtrl)
{
    switch (_pCtrl->GetCtrlId())
    {
        case ID_FILE_OPEN:
            OpenFile();
    }
} // MainWin::OnCtrlClicked
