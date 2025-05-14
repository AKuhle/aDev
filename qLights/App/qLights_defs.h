/*******************************************************************************
* \file qLights_defs.h
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
* includes
*******************************************************************************/
#include "aLib_def.h"
#include "aWin_def.h"
#include "aString.h"

using namespace aLib;
using namespace aLib::aWin;
using namespace aLib::aUtil;


/*******************************************************************************
* application constants
*******************************************************************************/
constexpr u32   UNIVERSE                        = 1;
constexpr u32   PORT                            = 0;

constexpr s32   BANK_MAX                        = 10;
constexpr s32   FIXTURE_MAX                     = 10;
constexpr s32   SCENE_MAX                       = 30;
constexpr s32   FADER_MAX                       = 24;


/*******************************************************************************
* ctrl-IDs
*******************************************************************************/
constexpr u32   ID_ADD_BANK                     = CTRL_ID_USER + 1;
constexpr u32   ID_ADD_FIXTURE                  = CTRL_ID_USER + 2;

constexpr u32   ID_FIRST_BANK_IDX               = CTRL_ID_USER + 100;
constexpr u32   ID_FIRST_FIXTURE_IDX            = CTRL_ID_USER + 200;
constexpr u32   ID_FIRST_FADER_IDX              = CTRL_ID_USER + 300;


/*******************************************************************************
* enums
*******************************************************************************/
enum class enumWorkMode
{
    Edit,
    Show
}; // enumMode
