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
#include "editScrollWin.h"

#include "editScrollWin.h"

using namespace aLib::aWin;

/*******************************************************************************
* EditScrollWin::EditScrollWin
*******************************************************************************/
EditScrollWin::EditScrollWin(SysWinClass *_pParent /*= nullptr*/)
: aScrollWin(_pParent)
{
} // EditScrollWin::EditScrollWin


/*******************************************************************************
* EditScrollWin::~EditScrollWin
*******************************************************************************/
EditScrollWin::~EditScrollWin()
{
} // EditScrollWin::~EditScrollWin


/*******************************************************************************
* EditScrollWin::onCreate
*******************************************************************************/
bool EditScrollWin::onCreate()
{
    //setScrollBarPolicy(ScrollBarPolicy::ScrollBarAlwaysOn);

    return true;
} // EditScrollWin::onCreate
