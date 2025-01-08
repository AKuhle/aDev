/*******************************************************************************
* \file plDefs.h
* \author Andreas Kuhlewind
*
* \brief
*
*  Detailed description starts here.
*******************************************************************************/
#pragma once


/*******************************************************************************
* includes
*******************************************************************************/
#include "qLib.h"


/*******************************************************************************
* app defines
*******************************************************************************/
const qLib::qString16       VAR_POOL_FILE_NAME          = "varPoolPl.json";
constexpr qLib::dbl         PL_ZOOM_MIN                 = 64; // 1/64 of the original size
constexpr qLib::dbl         PL_ZOOM_MAX                 = 16; // 16 times of the original size
constexpr qLib::s32         MIN_PIC_VISIBLE             = 32; // min amount pixels which are always visible (in zoom)

//constexpr qLib::dbl     GOLDEN_PHI                  = 0.6180339887498948; // for golden cut / coil


/*******************************************************************************
* object Id's
*******************************************************************************/
constexpr qLib::u32         ID_DUMMY                    = qLib::ID_USER;

// standard toolbar
constexpr qLib::u32         ID_FILE_OPEN                = qLib::ID_USER + 1;
constexpr qLib::u32         ID_EXIT                     = qLib::ID_USER + 2;
constexpr qLib::u32         ID_UNDO                     = qLib::ID_USER + 3;
constexpr qLib::u32         ID_REDO                     = qLib::ID_USER + 4;

// enum-IDs for var pool
constexpr qLib::u32         ID_ENUM_SECTION             = qLib::ID_USER + 2000;

// image processing
constexpr qLib::u32         ID_FLIP_HORI                = qLib::ID_USER + 1001;
constexpr qLib::u32         ID_FLIP_VERT                = qLib::ID_USER + 1002;
constexpr qLib::u32         ID_ROTATE_CCW               = qLib::ID_USER + 1003;
constexpr qLib::u32         ID_ROTATE_CW                = qLib::ID_USER + 1004;
constexpr qLib::u32         ID_ROTATE_180               = qLib::ID_USER + 1005;
constexpr qLib::u32         ID_INVERT                   = qLib::ID_USER + 1006;

constexpr qLib::u32         ID_TOOLBOX                  = qLib::ID_USER + 10000;
constexpr qLib::u32         ID_MOVE                     = qLib::ID_USER + 10001;
constexpr qLib::u32         ID_ZOOM                     = qLib::ID_USER + 10002;

constexpr qLib::u32         ID_NAVIGATOR                = qLib::ID_USER + 20000;
constexpr qLib::u32         ID_ZOOM_FIT                 = qLib::ID_USER + 20001;
constexpr qLib::u32         ID_ZOOM_100_PCNT            = qLib::ID_USER + 20002;
constexpr qLib::u32         ID_ZOOM_200_PCNT            = qLib::ID_USER + 20003;
constexpr qLib::u32         ID_ZOOM_SLIDER              = qLib::ID_USER + 20004;

constexpr qLib::u32         ID_PROTOCOL                 = qLib::ID_USER + 30000;
constexpr qLib::u32         ID_CMD_LIST                 = qLib::ID_USER + 30001;

// option windows
constexpr qLib::u32         ID_HALF_CUT                 = qLib::ID_USER +100000;
constexpr qLib::u32         ID_THIRD_CUT                = qLib::ID_USER +100001;
constexpr qLib::u32         ID_GOLDEN_CUT               = qLib::ID_USER +100002;
constexpr qLib::u32         ID_GOLDEN_COIL              = qLib::ID_USER +100003;


/*******************************************************************************
* update commands
*******************************************************************************/
constexpr qLib::u64         UPDATE_CMD_PROCESSING_START = 0x0000000000010000;
constexpr qLib::u64         UPDATE_CMD_PROCESSING_END   = 0x0000000000020000;
constexpr qLib::u64         UPDATE_MODE_CHANGED         = 0x0000000000040000;
constexpr qLib::u64         UPDATE_VIEW_ACTVATED        = 0x0000000000080000;
constexpr qLib::u64         UPDATE_SCALE_CHANGED        = 0x0000000000100000;

constexpr qLib::u64         UPDATE_TOOLBOX_DLG          = 0x0001000000000000;
constexpr qLib::u64         UPDATE_NAVIGATOR_DLG        = 0x0002000000000000;
constexpr qLib::u64         UPDATE_PROTOCOL_DLG         = 0x0004000000000000;
constexpr qLib::u64         UPDATE_OPTION_DLG           = 0x0008000000000000;
constexpr qLib::u64         UPDATE_ALL_DLG              = 0xffff000000000000;


/*******************************************************************************
* Tool IDs
*******************************************************************************/
constexpr qLib::u32         TOOL_ID_ZOOM                = 1000;
constexpr qLib::u32         TOOL_ID_MOVE                = 1001;
constexpr qLib::u32         TOOL_ID_NAVIGATOR           = 1002;


/*******************************************************************************
* ToolBaseFunctions
*******************************************************************************/
constexpr qLib::u64         TBF_WHEEL_ZOOM              = 0x0000000000010000;
constexpr qLib::u64         TBF_LEFT_MOVE               = 0x0000000000020000;   // move with left mouse button
constexpr qLib::u64         TBF_MIDDLE_MOVE             = 0x0000000000040000;   // move with middle mouse button
constexpr qLib::u64         TBF_SECTIONS                = 0x0000000000080000;   // draw the section marker (golden cut etc.)
//constexpr u64   TBF_VIEW_COORDINATES_pic                = 0x00000100;
//constexpr qLib::u64     TBF_DBL_CLICK_CENTER        = 0x0000000000080000;   // center the double clicked point in the zoomed picture



/*******************************************************************************
* enums
*******************************************************************************/
enum class enumMode
{
    None,
    Zoom,
    Move
}; // enumMode


enum class enumSection
{
    NoCut       = 0,
    HalfCut,
    ThirdCut,
    GoldenCut,
    GoldenCoil
}; // enumSection
