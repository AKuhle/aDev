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
#include "aString.h"

using namespace aLib;
using namespace aLib::aUtil;
using namespace aLib::aWin;


/*******************************************************************************
* application constants
*******************************************************************************/
constexpr dbl   PL_ZOOM_MIN                     = 64.; // 1/64 of the original size
constexpr dbl   PL_ZOOM_MAX                     = 16.; // 16 times of the original size
const aString   COMPANY_NAME                    { "qSoft" };
const aString   APP_NAME                        { "qPhotoLab" };


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
constexpr u32   ID_FILE_OPEN                    = CTRL_ID_USER + 1;
constexpr u32   ID_EXIT                         = CTRL_ID_USER + 2;
constexpr u32   ID_UNDO                         = CTRL_ID_USER + 3;
constexpr u32   ID_REDO                         = CTRL_ID_USER + 4;

// view
constexpr u32   ID_VIEW_TOOLBOX                 = CTRL_ID_USER + 1000;
constexpr u32   ID_VIEW_NAVIGATOR               = CTRL_ID_USER + 1001;
constexpr u32   ID_VIEW_PROTOCOL                = CTRL_ID_USER + 1002;
constexpr u32   ID_VIEW_STATUSBAR               = CTRL_ID_USER + 1003;

// image processing
constexpr u32   ID_IMAGE_FLIP_HORI              = CTRL_ID_USER + 2000;
constexpr u32   ID_IMAGE_FLIP_VERT              = CTRL_ID_USER + 2001;
constexpr u32   ID_IMAGE_ROTATE_CCW             = CTRL_ID_USER + 2003;
constexpr u32   ID_IMAGE_ROTATE_CW              = CTRL_ID_USER + 2004;
constexpr u32   ID_IMAGE_ROTATE_180             = CTRL_ID_USER + 2002;
constexpr u32   ID_IMAGE_FLIP_INVERT            = CTRL_ID_USER + 2005;

// tool windows
constexpr u32   ID_ZOOM_FIT                     = CTRL_ID_USER + 3000;
constexpr u32   ID_ZOOM_100_PCNT                = CTRL_ID_USER + 3001;
constexpr u32   ID_ZOOM_200_PCNT                = CTRL_ID_USER + 3002;


/*******************************************************************************
* update commands
*******************************************************************************/
constexpr u64   UPDATE_CMD_PROCESSING_START     = 0x0000000000010000;
constexpr u64   UPDATE_CMD_PROCESSING_END       = 0x0000000000020000;
constexpr u64   UPDATE_CMD_COORDINATES          = 0x0000000000040000;
constexpr u64   UPDATE_CMD_COORDINATES_CLEAR    = 0x0000000000080000;
constexpr u64   UPDATE_CMD_VIEW_ACTIVATED       = 0x0000000000100000;

constexpr u64   UPDATE_CMD_NAVIGATOR            = 0x0001000000000000;
constexpr u64   UPDATE_CMD_TOOL_WIN             = 0x0001000000000000;


/*******************************************************************************
* enums
*******************************************************************************/
enum class enumEditMode
{
    None,
    Zoom,
    Move
}; // enumMode
