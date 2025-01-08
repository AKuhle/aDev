// https://pixabay.com/de/illustrations/search/hase/

/*******************************************************************************
* \file qBaseDefs.h
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
#pragma once


/*******************************************************************************
* include
*******************************************************************************/
#include "qBaseDefs.h"

using namespace qLib;


/*******************************************************************************
* app defines
*******************************************************************************/
#define                     PATH_GAME_DATA              "/GameData"
#define                     PATH_FIGURES                "/Figures"
#define                     PATH_JSON                   "/../qDev/qGames/Json"

#define                     FILENAME_VAR_POOL           "/qGamesVp.json"
#define                     FILENAME_ALL_GAMES          "/allGames.json"
#define                     FILENAME_CURRENT_SESSION    "/currentSession.json"

#define                     GAME_COUNT                  16

#define                     TEAM_NONE                   0
#define                     TEAM_1                      1
#define                     TEAM_2                      2
#define                     TEAM_BOTH                   3


/*******************************************************************************
* size of standard items
*******************************************************************************/
constexpr s32               StdTitleH                   =  60;


/*******************************************************************************
* varpool Id's
*******************************************************************************/
constexpr u32               ID_VP_GAME_BG_1             = 1;
constexpr u32               ID_VP_GAME_BG_2             = 2;


/*******************************************************************************
* enums
*******************************************************************************/
enum class enumPages
{
    PanelFigureTeam_1,
    PanelFigureTeam_2,
    PanelWinners,
    Mosaic
}; // enumPages


enum class enumGameType
{
    Undefined,
    LetterSum,
    Mosaic
}; // enumGameType
