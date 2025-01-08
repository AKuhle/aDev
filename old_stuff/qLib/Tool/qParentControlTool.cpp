/*******************************************************************************
* \file qParentControlTool.inl
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


/*******************************************************************************
* includes
*******************************************************************************/
#include "Tool/qParentControlTool.h"
#include "Win/FrameWin/qWin.h"


namespace qLib {
namespace Tool {


/*******************************************************************************
* qParentControlTool::qParentControlTool
*******************************************************************************/
qParentControlTool::qParentControlTool(qWin   *_pOwnerWin,
                                       u32    _u32ToolId)
: qToolBase(_pOwnerWin, _u32ToolId, TBF_NONE)
{
} // qParentControlTool::qParentControlTool


/*******************************************************************************
* qParentControlTool::~qParentControlTool
*******************************************************************************/
qParentControlTool::~qParentControlTool()
{
} // qParentControlTool::~qParentControlTool


/*******************************************************************************
* qParentControlTool::onLDoubleClick
*******************************************************************************/
enumToolResult qParentControlTool::onLDoubleClick(u32                     /*_u32Modifiers*/,
                                                  const qVector2D<s32>    &/*_v2dLocal*/,
                                                  const qVector2D<s32>    &/*_v2dGlobal*/)
{
    qWin *pOwner = ownerWin();
    CHECK_PRE_CONDITION(pOwner != nullptr, enumToolResult::Unhandled);

    qWin *pParent = pOwner->parent();
    CHECK_PRE_CONDITION(pParent != nullptr, enumToolResult::Unhandled);

    pParent->toggleMaximized();

    return enumToolResult::Handled;
} // qParentControlTool::onLDoubleClick


/*******************************************************************************
* qParentControlTool::onLMousePress
*******************************************************************************/
enumToolResult qParentControlTool::onLMousePress(u32                     /*_u32Modifiers*/,
                                                 const qVector2D<s32>    &/*_v2dLocal*/,
                                                 const qVector2D<s32>    &/*_v2dGlobal*/)
{
    qWin *pOwner = ownerWin();
    CHECK_PRE_CONDITION(pOwner != nullptr, enumToolResult::Unhandled);

    qWin *pParent = ownerWin()->parent();
    CHECK_PRE_CONDITION(pParent != nullptr, enumToolResult::Unhandled);

    m_r2dMoveStart = pParent->geometry();

    return enumToolResult::Handled;
} // qParentControlTool::onLMousePress


/*******************************************************************************
* qParentControlTool::onLMouseMove
*******************************************************************************/
enumToolResult qParentControlTool::onLMouseMove(u32                     /*_u32Modifiers*/,
                                                const qVector2D<s32>    &/*_v2dLocal*/,
                                                const qVector2D<s32>    &/*_v2dGlobal*/)
{
    qWin *pOwner = ownerWin();
    CHECK_PRE_CONDITION(pOwner != nullptr, enumToolResult::Unhandled);

    qWin *pParent = ownerWin()->parent();
    CHECK_PRE_CONDITION(pParent != nullptr, enumToolResult::Unhandled);

    // don't move, if parent is maximized
    if (!pParent->isMaximized())
    {
        pParent->setGeometry(m_r2dMoveStart.x() + moveDeltaGlobal().x(),
                             m_r2dMoveStart.y() + moveDeltaGlobal().y(),
                             m_r2dMoveStart.w(),
                             m_r2dMoveStart.h());
    }

    return enumToolResult::Handled;
} // qParentControlTool::onLMouseMove


} // namespace Tool
} // namespace qLib
