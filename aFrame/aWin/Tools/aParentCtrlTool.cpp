/*******************************************************************************
* \file aParentCtrlTool.cpp
* \author Andreas Kuhlewind
*
* \brief
*
*  Detailed description starts here.
*******************************************************************************/


/*******************************************************************************
* includes
*******************************************************************************/
#include "aParentCtrlTool.h"



/*******************************************************************************
* namespace
*******************************************************************************/
namespace aFrame {
namespace aWin {


/*******************************************************************************
* aParentCtrlTool::aParentCtrlTool
*******************************************************************************/
aParentCtrlTool::aParentCtrlTool(aBaseWin   *_pOwner,
                                 u32        _u32ToolId  /*= TOOL_ID_PARENT_CTRL*/,
                                 u32        _u32Flags   /*= TF_NONE*/)
: aToolBase(_pOwner, _u32ToolId, _u32Flags)
{
} // aParentCtrlTool::aParentCtrlTool


/*******************************************************************************
* aParentCtrlTool::~aParentCtrlTool
*******************************************************************************/
aParentCtrlTool::~aParentCtrlTool()
{
} // aParentCtrlTool::~aParentCtrlTool


/*******************************************************************************
* aParentCtrlTool::onLDoubleClick
*******************************************************************************/
bool aParentCtrlTool::onLDoubleClick(u16              /*_u16Modifier*/,
                                     const aPoint     &/*_pntLocal*/,
                                     const aPoint     &/*_pntGlobal*/)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;

    return true;
} // aParentCtrlTool::onLDoubleClick


} // namespace aWin
} // namespace aFrame
