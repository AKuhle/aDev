/*******************************************************************************
* \file GameWin.cpp
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
#include "gameWin.h"


using namespace qLib;


/*******************************************************************************
* GameWin::GameWin
*******************************************************************************/
GameWin::GameWin()
{
} // GameWin::GameWin


/*******************************************************************************
* GameWin::~GameWin
*******************************************************************************/
GameWin::~GameWin()
{
} // ~GameWin::GameWin


/*******************************************************************************
* GameWin::OnCreate
*******************************************************************************/
bool GameWin::OnCreate()
{
    qLayoutMainWin  *pLayout = dynamic_cast<qLayoutMainWin *> (GetLayout());
    CHECK_PRE_CONDITION(pLayout != nullptr, false);

    // set the background to gradient fill
    const qColor   &col1 = GetVarPool().GetColor(ID_VP_GAME_BG_1);
    const qColor   &col2 = GetVarPool().GetColor(ID_VP_GAME_BG_2);
    SetContentFillStyle(make_unique<qStyleFillGradient> (col1, col2));

    // restore the position
    SetMinSize(600, 400);
    SetGeometry(400, 300, GetMinSize().w, GetMinSize().h);

    return true;
} // GameWin::OnCreate
