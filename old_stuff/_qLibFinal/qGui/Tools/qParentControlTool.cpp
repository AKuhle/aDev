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
#include "qParentControlTool.h"
#include "qWin.h"


namespace qLib
{
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
    * qParentControlTool::OnLMousePress
    *******************************************************************************/
    enumToolResult qParentControlTool::OnLMousePress(u32                     /*_u32Modifiers*/,
                                                     const qVector2D<s32>    &/*_v2dLocal*/,
                                                     const qVector2D<s32>    &/*_v2dGlobal*/)
    {
        qWin *pOwner = GetOwnerWin();
        CHECK_PRE_CONDITION(pOwner != nullptr, enumToolResult::Unhandled);

        qWin *pParent = GetOwnerWin()->GetParent();
        CHECK_PRE_CONDITION(pParent != nullptr, enumToolResult::Unhandled);

        m_r2dMoveStart = pParent->GeometryRect();

        return enumToolResult::Handled;
    } // qParentControlTool::OnLMousePress


    /*******************************************************************************
    * qParentControlTool::OnLMouseMove
    *******************************************************************************/
    enumToolResult qParentControlTool::OnLMouseMove(u32                     /*_u32Modifiers*/,
                                                    const qVector2D<s32>    &/*_v2dLocal*/,
                                                    const qVector2D<s32>    &/*_v2dGlobal*/)
    {
        qWin *pOwner = GetOwnerWin();
        CHECK_PRE_CONDITION(pOwner != nullptr, enumToolResult::Unhandled);

        qWin *pParent = GetOwnerWin()->GetParent();
        CHECK_PRE_CONDITION(pParent != nullptr, enumToolResult::Unhandled);

        // don't move, if parent is maximized
        if (!pParent->IsMaximized())
        {
            pParent->SetGeometry(m_r2dMoveStart.x + GetMoveDeltaGlobal().x,
                                 m_r2dMoveStart.y + GetMoveDeltaGlobal().y,
                                 m_r2dMoveStart.w,
                                 m_r2dMoveStart.h);
        }

        return enumToolResult::Handled;
    } // qParentControlTool::OnLMouseMove


    /*******************************************************************************
    * qParentControlTool::OnLDoubleClick
    *******************************************************************************/
    enumToolResult qParentControlTool::OnLDoubleClick(u32                     /*_u32Modifiers*/,
                                                    const qVector2D<s32>    &/*_v2dLocal*/,
                                                    const qVector2D<s32>    &/*_v2dGlobal*/)
    {
        qWin *pOwner = GetOwnerWin();
        CHECK_PRE_CONDITION(pOwner != nullptr, enumToolResult::Unhandled);

        qWin *pParent = pOwner->GetParent();
        CHECK_PRE_CONDITION(pParent != nullptr, enumToolResult::Unhandled);

        pParent->ToggleMaximized();

        return enumToolResult::Handled;
    } // qParentControlTool::OnLDoubleClick

} // namespace qLib
