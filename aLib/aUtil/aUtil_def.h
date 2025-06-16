/*******************************************************************************
* \file qlBaseDefs.h
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
#include "aLib_def.h"

#ifdef _USE_QT_
    #include <QUrl>

    using SysUrl       = QUrl;
#endif // _USE_QT_


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aUtil {


/*******************************************************************************
* ToolBaseFunctions
*******************************************************************************/
constexpr u64   TBF_NONE                    = 0x0000000000000000;
constexpr u64   TBF_LXOR_RECT               = 0x0000000000000001;
constexpr u64   TBF_USER                    = 0xffffffffffff0000;


/*******************************************************************************
* enums
*******************************************************************************/
enum class enumCmdType
{
    CMD_TYPE_UNDO,                  ///< Commando can be undone
    CMD_TYPE_NO_UNDO				///< Commando can't be undone
}; // enum class enumCmdType

enum class enumToolResult
{
    Handled,
    Unhandled,
    Success,
    Canceled
}; // enumToolResult

enum class enumCmdMsg
{
    Prepare,
    Do,
    Undo,
    Redo
};


/*******************************************************************************
* classes
*******************************************************************************/
template <typename Tkey, typename T2> class aMap;
template <typename T> class aVector;
template <typename T> class aPtrList;
template <typename T> class aUniquePtrList;
template <typename T> class aSharedPtrList;
template <typename T> class aSharedPtVector;
template <typename T> class aUniquePtrDeque;
template <typename T> class aPoolVarBase;

class aArgument;
class aColor;
class aJsonFile;
class aJsonObj;
class aJsonValue;
class aMargin;
class aPath;
class aProgressMgr;
class aProgressCb;
class aStopwatch;
class aString;
class aThread;
class aUrl;
class aThreadCb;
class aVersionInfo;

class aToolBase;
class aToolMgr;

class aCmdBase;
class aCmdMgr;
class aCmdStack;
class aCmd;
class aCmdThread;

class aPoolVarBool;
class aPoolVarColor;
class aPoolVarDbl;
class aPoolVarS32;
class aPoolVarString;
class aPoolVarU32;
class aVarPool;

} // namespace aUtil
} // namespace aLib
