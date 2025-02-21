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
* namespace
*******************************************************************************/
namespace aLib {
namespace aUtil {


/*******************************************************************************
* enums
*******************************************************************************/
enum class enumCmdType
{
    CMD_TYPE_UNDO,                  ///< Commando can be undone
    CMD_TYPE_NO_UNDO				///< Commando can't be undone
}; // enum class enumCmdType

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
template <typename T> class aUniquePtrDeque;

#ifdef _USE_QT_
    namespace SysQt
    {
        class aUrlQt;
        class aThreadQt;
    } // namespace SysQt

    using aUrl = aLib::aUtil::SysQt::aUrlQt;
    using aThread = aLib::aUtil::SysQt::aThreadQt;
#endif // _USE_QT_

class aArgument;
class aColor;
class aMargin;
class aPath;
class aProgressMgr;
class aProgressCb;
class aStopwatch;
class aString;
class aThreadCb;
class aVersionInfo;

class aCmdBase;
class aCmdMgr;
class aCmdStack;
class aCmd;
class aCmdThread;

} // namespace aUtil
} // namespace aLib
