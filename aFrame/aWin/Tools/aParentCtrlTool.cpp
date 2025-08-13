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
#include "aBaseWin.h"



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
: aToolBase(_pOwner, _u32ToolId, _u32Flags, nullptr)
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
enumToolResult aParentCtrlTool::onLDoubleClick(u16              /*_u16Modifier*/,
                                               const aPoint     &/*_pntLocal*/,
                                               const aPoint     &/*_pntGlobal*/)
{
    CHECK_PRE_CONDITION(ownerParent(), enumToolResult::UNHANDLED);

    ownerParent()->toggleMaximized();

    return enumToolResult::HANDLED;
} // aParentCtrlTool::onLDoubleClick


/*******************************************************************************
* aParentCtrlTool::onLButtonPress
*******************************************************************************/
enumToolResult aParentCtrlTool::onLButtonPress(u16              /*_u16Modifier*/,
                                               const aPoint     &/*_pntLocal*/,
                                               const aPoint     &/*_pntGlobal*/)
{
    CHECK_PRE_CONDITION(ownerParent(), enumToolResult::UNHANDLED);

    m_rctMoveStartRect = ownerParent()->geometryRect();

    return enumToolResult::HANDLED;
} // aParentCtrlTool::onLButtonPress


/*******************************************************************************
* aParentCtrlTool::onLMouseMove
*******************************************************************************/
enumToolResult aParentCtrlTool::onLMouseMove(u16              /*_u16Modifier*/,
                                             const aPoint     &/*_pntLocal*/,
                                             const aPoint     &/*_pntGlobal*/)
{
    CHECK_PRE_CONDITION(ownerParent(), enumToolResult::UNHANDLED);

    // only normal windows (not fullscreen or maximized) can be moved
    if (ownerParent()->isNormal())
    {
        ownerParent()->setGeometry(m_rctMoveStartRect.x() + delta().x(),
                                   m_rctMoveStartRect.y() + delta().y(),
                                   m_rctMoveStartRect.w(),
                                   m_rctMoveStartRect.h());
    }
    return enumToolResult::HANDLED;
} // aParentCtrlTool::onLMouseMove


/*******************************************************************************
* aParentCtrlTool::onLButtonRelease
*******************************************************************************/
enumToolResult aParentCtrlTool::onLButtonRelease(u16              /*_u16Modifier*/,
                                                 const aPoint     &/*_pntLocal*/,
                                                 const aPoint     &/*_pntGlobal*/)
{
    CHECK_PRE_CONDITION(ownerParent(), enumToolResult::UNHANDLED);

    return enumToolResult::HANDLED;
} // aParentCtrlTool::onLButtonRelease


} // namespace aWin
} // namespace aFrame
