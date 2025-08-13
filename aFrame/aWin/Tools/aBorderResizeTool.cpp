/*******************************************************************************
* \file aBorderResizeTool.cpp
* \author Andreas Kuhlewind
*
* \brief
*
*  Detailed description starts here.
*******************************************************************************/


/*******************************************************************************
* includes
*******************************************************************************/
#include "aBorderResizeTool.h"
#include "aBaseWin.h"



/*******************************************************************************
* namespace
*******************************************************************************/
namespace aFrame {
namespace aWin {


/*******************************************************************************
* aBorderResizeTool::aBorderResizeTool
*******************************************************************************/
aBorderResizeTool::aBorderResizeTool(aBaseWin   *_pOwner,
                                     u32        _u32ToolId  /*= TOOL_ID_PARENT_CTRL*/,
                                     u32        _u32Flags   /*= TF_NONE*/)
: aToolBase(_pOwner, _u32ToolId, _u32Flags, nullptr)
{
} // aBorderResizeTool::aBorderResizeTool


/*******************************************************************************
* aBorderResizeTool::~aBorderResizeTool
*******************************************************************************/
aBorderResizeTool::~aBorderResizeTool()
{
} // aBorderResizeTool::~aBorderResizeTool


/*******************************************************************************
* aBorderResizeTool::onMouseMove
*******************************************************************************/
enumToolResult aBorderResizeTool::onMouseMove(u16              /*_u16Modifier*/,
                                              const aPoint     &_pntLocal,
                                              const aPoint     &/*_pntGlobal*/)
{
    cout << "Mouse Move: Local(" << _pntLocal << ")" << endl;

    return enumToolResult::HANDLED;
} // aBorderResizeTool::onMouseMove


/*******************************************************************************
* aBorderResizeTool::onLButtonPress
*******************************************************************************/
enumToolResult aBorderResizeTool::onLButtonPress(u16              /*_u16Modifier*/,
                                               const aPoint     &/*_pntLocal*/,
                                               const aPoint     &/*_pntGlobal*/)
{
    CHECK_PRE_CONDITION(ownerParent(), enumToolResult::UNHANDLED);

    m_rctMoveStartRect = ownerParent()->geometryRect();

    return enumToolResult::HANDLED;
} // aBorderResizeTool::onLButtonPress


/*******************************************************************************
* aBorderResizeTool::onLMouseMove
*******************************************************************************/
enumToolResult aBorderResizeTool::onLMouseMove(u16              /*_u16Modifier*/,
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
} // aBorderResizeTool::onLMouseMove


/*******************************************************************************
* aBorderResizeTool::onLButtonRelease
*******************************************************************************/
enumToolResult aBorderResizeTool::onLButtonRelease(u16              /*_u16Modifier*/,
                                                 const aPoint     &/*_pntLocal*/,
                                                 const aPoint     &/*_pntGlobal*/)
{
    CHECK_PRE_CONDITION(ownerParent(), enumToolResult::UNHANDLED);

    return enumToolResult::HANDLED;
} // aBorderResizeTool::onLButtonRelease


} // namespace aWin
} // namespace aFrame
