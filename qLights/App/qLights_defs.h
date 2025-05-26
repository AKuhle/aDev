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

constexpr s32   SCRIBBLE_STRIP_W                = 32;
constexpr s32   SCRIBBLE_STRIP_H                = 32;


/*******************************************************************************
* update commands
*******************************************************************************/
constexpr u64   UPDATE_SYS_BITS             = 0x000000000000ffff;
constexpr u64   UPDATE_USER_BITS            = 0xffffffffffff0000;

constexpr u64   UPDATE_RESET_ALL            = 0x0000000000010000;


/*******************************************************************************
* ctrl-IDs
*******************************************************************************/
constexpr u32   ID_ADD_BANK                     = CTRL_ID_USER + 1;
constexpr u32   ID_ADD_FIXTURE                  = CTRL_ID_USER + 2;
constexpr u32   ID_SAVE_SCENE                   = CTRL_ID_USER + 3;
constexpr u32   ID_RESET_ALL                    = CTRL_ID_USER + 4;

constexpr u32   ID_FIRST_BANK_IDX               = CTRL_ID_USER + 100;
constexpr u32   ID_FIRST_FIXTURE_IDX            = CTRL_ID_USER + 200;
constexpr u32   ID_FIRST_SCENE_IDX              = CTRL_ID_USER + 300;
constexpr u32   ID_FIRST_FADER_IDX              = CTRL_ID_USER + 400;

constexpr u32   ID_MASTER_FADER_IDX             = CTRL_ID_USER + 500;
constexpr u32   ID_BACKOUT_IDX                  = CTRL_ID_USER + 501;


/*******************************************************************************
* channel icons
*******************************************************************************/
#define         CHANNEL_ICN_PAN                 ":/qLights/ChannelIcn/pan.png"
#define         CHANNEL_ICN_PAN_FINE            ":/qLights/ChannelIcn/pan-fine.png"
#define         CHANNEL_ICN_TILT                ":/qLights/ChannelIcn/tilt.png"
#define         CHANNEL_ICN_TILT_FINE           ":/qLights/ChannelIcn/tilt-fine.png"
#define         CHANNEL_ICN_PAN_TILT_SPEED      ":/qLights/ChannelIcn/pan-tilt-speed.png"
#define         CHANNEL_ICN_BRIGHTNESS          ":/qLights/ChannelIcn/brightness.png"
#define         CHANNEL_ICN_BRIGHTNESS_ALL      ":/qLights/ChannelIcn/brightnessAll.png"
#define         CHANNEL_ICN_STROBE              ":/qLights/ChannelIcn/strobe.png"
#define         CHANNEL_ICN_ZOOM                ":/qLights/ChannelIcn/zoom.png"
#define         CHANNEL_ICN_COLOR_SPEED         ":/qLights/ChannelIcn/color-speed.png"
#define         CHANNEL_ICN_RESET               ":/qLights/ChannelIcn/reset.png"
#define         CHANNEL_ICN_COLOR_WHEEL         ":/qLights/ChannelIcn/color-wheel.png"
#define         CHANNEL_ICN_FOCUS               ":/qLights/ChannelIcn/focus.png"
#define         CHANNEL_ICN_PRISMA              ":/qLights/ChannelIcn/prisma.png"

#define         CHANNEL_ICN_RED                 ":/qLights/ChannelIcn/red.png"
#define         CHANNEL_ICN_RED_1               ":/qLights/ChannelIcn/red1.png"
#define         CHANNEL_ICN_RED_2               ":/qLights/ChannelIcn/red2.png"
#define         CHANNEL_ICN_RED_3               ":/qLights/ChannelIcn/red3.png"

#define         CHANNEL_ICN_GREEN               ":/qLights/ChannelIcn/green.png"
#define         CHANNEL_ICN_GREEN_1             ":/qLights/ChannelIcn/green1.png"
#define         CHANNEL_ICN_GREEN_2             ":/qLights/ChannelIcn/green2.png"
#define         CHANNEL_ICN_GREEN_3             ":/qLights/ChannelIcn/green3.png"

#define         CHANNEL_ICN_BLUE                ":/qLights/ChannelIcn/blue.png"
#define         CHANNEL_ICN_BLUE_1              ":/qLights/ChannelIcn/blue1.png"
#define         CHANNEL_ICN_BLUE_2              ":/qLights/ChannelIcn/blue2.png"
#define         CHANNEL_ICN_BLUE_3              ":/qLights/ChannelIcn/blue3.png"

#define         CHANNEL_ICN_WHITE               ":/qLights/ChannelIcn/white.png"
#define         CHANNEL_ICN_WHITE_1             ":/qLights/ChannelIcn/white1.png"
#define         CHANNEL_ICN_WHITE_2             ":/qLights/ChannelIcn/white2.png"
#define         CHANNEL_ICN_WHITE_3             ":/qLights/ChannelIcn/white3.png"

#define         CHANNEL_ICN_FUNCTION_1          ":/qLights/ChannelIcn/function1.png"
#define         CHANNEL_ICN_FUNCTION_2          ":/qLights/ChannelIcn/function2.png"
#define         CHANNEL_ICN_FUNCTION_3          ":/qLights/ChannelIcn/function3.png"
#define         CHANNEL_ICN_FUNCTION_4          ":/qLights/ChannelIcn/function4.png"
#define         CHANNEL_ICN_FUNCTION_5          ":/qLights/ChannelIcn/function5.png"

#define         CHANNEL_ICN_GOBO_ROT_SPEED      ":/qLights/ChannelIcn/gobo_rot_speed.png"

#define         CHANNEL_ICN_GOBO_STAT_01        ":/qLights/ChannelIcn/gobo_stat_01.png"

#define         CHANNEL_ICN_GOBO_ROT_01         ":/qLights/ChannelIcn/gobo_rot_01.png"


/*******************************************************************************
* enums
*******************************************************************************/
enum class enumWorkMode
{
    Play,
    SaveScene
}; // enumMode
