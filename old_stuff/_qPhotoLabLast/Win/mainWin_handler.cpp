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
#include "qLib.h"
#include "defsPl.h"
#include "mainWin.h"
#include "ui_formMainWin.h"


using namespace qLib;


/*******************************************************************************
* MainWin::OnDropUrl
*******************************************************************************/
void MainWin::OnDropUrl(const qUrl &_url)
{
    if (_url.IsLocalFile())
    {
        OpenFile(_url.ToLocalFile());
    }

} // MainWin::OnDropUrl
