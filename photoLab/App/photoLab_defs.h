/*******************************************************************************
* \file photoLabApp.h
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

using namespace aLib;
using namespace aLib::aWin;


/*******************************************************************************
* application constants
*******************************************************************************/
constexpr dbl   PL_ZOOM_MIN                     = 64.; // 1/64 of the original size
constexpr dbl   PL_ZOOM_MAX                     = 16.; // 16 times of the original size


/*******************************************************************************
* ToolBaseFunctions
*******************************************************************************/
constexpr u64   TBF_WHEEL_ZOOM                  = 0x0000000000010000;
constexpr u64   TBF_LEFT_MOVE                   = 0x0000000000020000;   // move with left mouse button
constexpr u64   TBF_MIDDLE_MOVE                 = 0x0000000000040000;   // move with middle mouse button
constexpr u64   TBF_SECTIONS                    = 0x0000000000080000;   // draw the section marker (golden cut etc.)


/*******************************************************************************
* Tool IDs
*******************************************************************************/
constexpr u32   TOOL_ID_ZOOM                    = 1000;
constexpr u32   TOOL_ID_MOVE                    = 1001;
constexpr u32   TOOL_ID_NAVIGATOR               = 1002;


/*******************************************************************************
* ctrl-IDs
*******************************************************************************/
// stdBar
constexpr u32   ID_FILE_OPEN                    = CTRL_ID_USER + 1;

// imageBar
constexpr u32   ID_IMAGE_FLIP_HORI              = CTRL_ID_USER + 200;
constexpr u32   ID_IMAGE_FLIP_VERT              = CTRL_ID_USER + 201;
constexpr u32   ID_IMAGE_ROTATE_CCW             = CTRL_ID_USER + 203;
constexpr u32   ID_IMAGE_ROTATE_CW              = CTRL_ID_USER + 204;
constexpr u32   ID_IMAGE_ROTATE_180             = CTRL_ID_USER + 202;
constexpr u32   ID_IMAGE_FLIP_INVERT            = CTRL_ID_USER + 205;


/*******************************************************************************
* update commands
*******************************************************************************/
constexpr u64   UPDATE_CMD_PROCESSING_START     = 0x0000000000010000;
constexpr u64   UPDATE_CMD_PROCESSING_END       = 0x0000000000020000;
constexpr u64   UPDATE_CMD_COORDINATES          = 0x0000000000040000;
constexpr u64   UPDATE_CMD_COORDINATES_CLEAR    = 0x0000000000080000;


/*******************************************************************************
* enums
*******************************************************************************/
enum class enumEditMode
{
    None,
    Zoom,
    Move
}; // enumMode
