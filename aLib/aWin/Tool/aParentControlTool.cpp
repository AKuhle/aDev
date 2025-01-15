/*******************************************************************************
* \file aParentControlTool.inl
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
#include "aWin/Tool/aParentControlTool.h"
#include "aWin/Framework/aBaseWin.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aWin {


/*******************************************************************************
* aParentControlTool::aParentControlTool
*******************************************************************************/
aParentControlTool::aParentControlTool(aBaseWin *_pOwnerWin,
                                       u32      _u32ToolId)
: aToolBase(_pOwnerWin, _u32ToolId, TBF_NONE)
{
} // aParentControlTool::aParentControlTool


/*******************************************************************************
* aParentControlTool::~aParentControlTool
*******************************************************************************/
aParentControlTool::~aParentControlTool()
{
} // aParentControlTool::~aParentControlTool


/*******************************************************************************
* aParentControlTool::onLDoubleClick
*******************************************************************************/
enumToolResult aParentControlTool::onLDoubleClick(u32                     /*_u32Modifiers*/,
                                                  const aVector2D<s32>    &/*_v2dLocal*/,
                                                  const aVector2D<s32>    &/*_v2dGlobal*/)
{
    aBaseWin *pOwner = ownerWin();
    CHECK_PRE_CONDITION(pOwner != nullptr, enumToolResult::Unhandled);

    aBaseWin *pParent = pOwner->parent();
    CHECK_PRE_CONDITION(pParent != nullptr, enumToolResult::Unhandled);

    pParent->toggleMaximized();

    return enumToolResult::Handled;
} // aParentControlTool::onLDoubleClick


/*******************************************************************************
* aParentControlTool::onLMousePress
*******************************************************************************/
enumToolResult aParentControlTool::onLMousePress(u32                     /*_u32Modifiers*/,
                                                 const aVector2D<s32>    &/*_v2dLocal*/,
                                                 const aVector2D<s32>    &/*_v2dGlobal*/)
{
    aBaseWin *pOwner = ownerWin();
    CHECK_PRE_CONDITION(pOwner != nullptr, enumToolResult::Unhandled);

    aBaseWin *pParent = ownerWin()->parent();
    CHECK_PRE_CONDITION(pParent != nullptr, enumToolResult::Unhandled);

    m_r2dMoveStart = pParent->geometry();

    return enumToolResult::Handled;
} // aParentControlTool::onLMousePress


/*******************************************************************************
* aParentControlTool::onLMouseMove
*******************************************************************************/
enumToolResult aParentControlTool::onLMouseMove(u32                     /*_u32Modifiers*/,
                                                const aVector2D<s32>    &/*_v2dLocal*/,
                                                const aVector2D<s32>    &/*_v2dGlobal*/)
{
    aBaseWin *pOwner = ownerWin();
    CHECK_PRE_CONDITION(pOwner != nullptr, enumToolResult::Unhandled);

    aBaseWin *pParent = ownerWin()->parent();
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
} // aParentControlTool::onLMouseMove


} // namespace aWin
} // namespace aLib
