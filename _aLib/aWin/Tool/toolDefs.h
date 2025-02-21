/*******************************************************************************
* \file toolDefs.h
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
#include "qLibDefs.h"

using namespace qLib;


namespace qLib {
namespace Tool {


/*******************************************************************************
* ToolBaseFunctions
*******************************************************************************/
constexpr u64   TBF_NONE                = 0x00000000;
constexpr u64   TBF_LXOR_RECT           = 0x00000001;
constexpr u64   TBF_USER                = 0xffffff00;


/*******************************************************************************
* tool id's
*******************************************************************************/
constexpr u32   TOOL_ID_PARENT_CONTROL  = 1;
constexpr u32   TOOL_ID_BORDER_RESIZE   = 2;

constexpr u32   TOOL_ID_USER            = 1000;


/*******************************************************************************
* enums
*******************************************************************************/
enum class enumToolResult
{
    Handled,
    Unhandled,
    Success,
    Canceled
}; // enumToolResult


/*******************************************************************************
* classes
*******************************************************************************/
class qToolBase;
class qParentControlTool;

class qToolMgr;


} // namespace Tool
} // namespace qLib
