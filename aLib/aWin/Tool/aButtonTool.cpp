/*******************************************************************************
* \file aButtonTool.inl
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
#include "aWin/Ctrl/aButton.h"

#include "aWin/Ctrl/aCtrlMgr.h"
#include "aWin/Tool/aButtonTool.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aWin {


/*******************************************************************************
* aButtonTool::aButtonTool
*******************************************************************************/
aButtonTool::aButtonTool(aBaseWin   *_pOwnerWin,
                         u32        _u32ToolId /*= TOOL_ID_BUTTON*/)
: aToolBase(_pOwnerWin, _u32ToolId, TBF_NONE)
{
} // aButtonTool::aButtonTool


/*******************************************************************************
* aButtonTool::~aButtonTool
*******************************************************************************/
aButtonTool::~aButtonTool()
{
} // aButtonTool::~aButtonTool


/*******************************************************************************
* aButtonTool::isMouseOnButton
*******************************************************************************/
bool aButtonTool::isMouseOnButton(const aVector2D<s32>    &_v2dLocal) const
{
    const aButton *pOwner = dynamic_cast<const aButton *> (ownerWin());
    CHECK_PRE_CONDITION(pOwner != nullptr, false);

    aRect2D<s32>    r = pOwner->borderRect();

    return (_v2dLocal.x() > r.x()) &&
           (_v2dLocal.x() < r.r()) &&
           (_v2dLocal.y() > r.y()) &&
           (_v2dLocal.y() < r.b());
} // aButtonTool::isMouseOnButton


/*******************************************************************************
* aButtonTool::onLeave
*******************************************************************************/
enumToolResult aButtonTool::onLeave(u32                   /*_u32Modifiers*/)
{
    aButton *pOwner = dynamic_cast<aButton *> (ownerWin());
    CHECK_PRE_CONDITION(pOwner != nullptr, enumToolResult::Unhandled);

    pOwner->update();

    return enumToolResult::Handled;
} // aButtonTool::onLeave


/*******************************************************************************
* aButtonTool::onLDoubleClick
*******************************************************************************/
enumToolResult aButtonTool::onLDoubleClick(u32                     /*_u32Modifiers*/,
                                          const aVector2D<s32>    &/*_v2dLocal*/,
                                          const aVector2D<s32>    &/*_v2dGlobal*/)
{
    return enumToolResult::Handled;
} // aButtonTool::onLDoubleClick


/*******************************************************************************
* aButtonTool::onMouseMove
*******************************************************************************/
enumToolResult aButtonTool::onMouseMove(u32                   /*_u32Modifiers*/,
                                        u32                   /*_u32MouseButton*/,
                                        const aVector2D<s32>  &/*_v2dLocal*/,
                                        const aVector2D<s32>  &/*_v2dGlobal*/)
{
    aButton *pOwner = dynamic_cast<aButton *> (ownerWin());
    CHECK_PRE_CONDITION(pOwner != nullptr, enumToolResult::Unhandled);

    pOwner->update();

    return enumToolResult::Handled;
} // aButtonTool::onMouseMove


/*******************************************************************************
* aButtonTool::onLMousePress
*******************************************************************************/
enumToolResult aButtonTool::onLMousePress(u32                     /*_u32Modifiers*/,
                                          const aVector2D<s32>    &/*_v2dLocal*/,
                                          const aVector2D<s32>    &/*_v2dGlobal*/)
{
    aButton *pOwner = dynamic_cast<aButton *> (ownerWin());
    CHECK_PRE_CONDITION(pOwner != nullptr, enumToolResult::Unhandled);

    m_bSelectedBefore = pOwner->isSelected();

    pOwner->setSelected(!m_bSelectedBefore);

    pOwner->update();

    return enumToolResult::Handled;
} // aButtonTool::onLMousePress


/*******************************************************************************
* aButtonTool::onLMouseMove
*******************************************************************************/
enumToolResult aButtonTool::onLMouseMove(u32                     /*_u32Modifiers*/,
                                         const aVector2D<s32>    &_v2dLocal,
                                         const aVector2D<s32>    &/*_v2dGlobal*/)
{
    aButton *pOwner = dynamic_cast<aButton *> (ownerWin());
    CHECK_PRE_CONDITION(pOwner != nullptr, enumToolResult::Unhandled);

    bool bOn    = isMouseOnButton(_v2dLocal);
    bool bNew   = (bOn)?   !m_bSelectedBefore : m_bSelectedBefore;

    if (bNew != pOwner->isSelected())
    {
        pOwner->setSelected(bNew);
        pOwner->update();
    }

    return enumToolResult::Handled;
} // aButtonTool::onLMouseMove


/*******************************************************************************
* aButtonTool::onLMouseRelease
*******************************************************************************/
enumToolResult aButtonTool::onLMouseRelease(u32                     /*_u32Modifiers*/,
                                            const aVector2D<s32>    &_v2dLocal,
                                            const aVector2D<s32>    &/*_v2dGlobal*/)
{
    aButton *pOwner = dynamic_cast<aButton *> (ownerWin());
    CHECK_PRE_CONDITION(pOwner != nullptr, enumToolResult::Unhandled);

    if (isMouseOnButton(_v2dLocal))
    {
        if (pOwner->isSelectable())
        {
            // the button already has the correct selection state (from press/move event)
            // just send the message
            pOwner->ctrlMgr()->sendCtrlMessage(pOwner, MSG_CLICKED);
        }
        else
        {
            // the button is selected => set unselected and send the message
            pOwner->setSelected(false);
            pOwner->update();
            if (pOwner->ctrlMgr() != nullptr)
            {
                pOwner->ctrlMgr()->sendCtrlMessage(pOwner, MSG_CLICKED);
            }
        }
    }

    return enumToolResult::Handled;
} // aButtonTool::onLMouseRelease


} // namespace aWin
} // namespace aLib
