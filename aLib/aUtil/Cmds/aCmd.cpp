/*******************************************************************************
* \file aCmd.cpp
* \author Andreas Kuhlewind
*
* \brief
*
*  Detailed description starts here.
*******************************************************************************/


/*******************************************************************************
* includes
*******************************************************************************/
#include "aCmd.h"
#include "aCmdMgr.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aUtil {


/*******************************************************************************
* aCmd::aCmd
*******************************************************************************/
aCmd::aCmd(s32              _s32ID,
           const aString    &_sName,
           enumCmdType      _eType)
: aCmdBase(_s32ID, _sName, _eType)
{
} // aCmd::aCmd


/*******************************************************************************
* aCmd::~aCmd
*******************************************************************************/
aCmd::~aCmd()
{
} // aCmd::~aCmd


/*******************************************************************************
* aCmd::doPrepare
*******************************************************************************/
void aCmd::doPrepare()
{
    cmdMgr()->manageCmd(enumCmdMsg::Prepare, this, prepare());
} // aCmd::doPreparem


/*******************************************************************************
* aCmd::doExecute
*******************************************************************************/
void aCmd::doExecute()
{
    cmdMgr()->manageCmd(enumCmdMsg::Do, this, execute());
} // aCmd::doExecute


/*******************************************************************************
* aCmd::doUndo
*******************************************************************************/
void aCmd::doUndo()
{
    cmdMgr()->manageCmd(enumCmdMsg::Undo, this, undo());
} // aCmd::doUndo


/*******************************************************************************
* aCmd::doRedo
*******************************************************************************/
void aCmd::doRedo()
{
    cmdMgr()->manageCmd(enumCmdMsg::Redo, this, redo());
} // aCmd::doRedo


} // namespace aUtil
} // namespace aLib
