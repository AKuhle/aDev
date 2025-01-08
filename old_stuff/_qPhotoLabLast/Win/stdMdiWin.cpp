/*******************************************************************************
* \file StdMdiWin.cpp
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
#include "StdMdiWin.h"
#include "stdScrollWin.h"
#include "viewStd.h"


using namespace qLib;


/*******************************************************************************
* StdMdiWin::StdMdiWin
*******************************************************************************/
StdMdiWin::StdMdiWin(SysWin_t  *_pParent /*= nullptr*/)
: qMdiWin(_pParent)
{
} // StdMdiWin::StdMdiWin


/*******************************************************************************
* StdMdiWin::~StdMdiWin
*******************************************************************************/
StdMdiWin::~StdMdiWin()
{
} // ~StdMdiWin::StdMdiWin


/*******************************************************************************
* StdMdiWin::OnCreate
*******************************************************************************/
bool StdMdiWin::OnCreate()
{
    // create the scroll win
    StdScrollWin *pScrollWin = new StdScrollWin();
    pScrollWin->CreateWin();
    SetCentralWin(pScrollWin);

    return true;
} // StdMdiWin::OnCreate


/*******************************************************************************
* StdMdiWin::SetView
*******************************************************************************/
void StdMdiWin::SetView(ViewStd *_pView)
{
    StdScrollWin    *pScrollWin =  ScrollWin();

    if (pScrollWin != nullptr)
    {
        pScrollWin->SetCentralWin(_pView);
    }
} // StdMdiWin::SetView


/*******************************************************************************
* StdMdiWin::StdView
*******************************************************************************/
ViewStd* StdMdiWin::StdView() const
{
    StdScrollWin    *pScrollWin =  ScrollWin();

    if (pScrollWin != nullptr)
    {
        return dynamic_cast<ViewStd *> (pScrollWin->CentralWin());
    }
    else
    {
        return nullptr;
    }
} // StdMdiWin::StdView


/*******************************************************************************
* StdMdiWin::ScrollWin
*******************************************************************************/
StdScrollWin* StdMdiWin::ScrollWin() const
{
    return dynamic_cast<StdScrollWin *> (CentralWin());
} // StdMdiWin::ScrollWin
