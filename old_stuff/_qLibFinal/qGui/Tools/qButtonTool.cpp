/*******************************************************************************
* \file qButtonTool.inl
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
#include "qButtonTool.h"
#include "qWin.h"
#include "qCursor.h"
#include "qButtonBase.h"
#include "qCtrlMgr.h"

namespace qLib
{
    /*******************************************************************************
    * qButtonTool::qButtonTool
    *******************************************************************************/
    qButtonTool::qButtonTool(qWin   *_pOwnerWin,
                             u32    _u32ToolId)
    : qToolBase(_pOwnerWin, _u32ToolId, TBF_NONE)
	{
    } // qButtonTool::qButtonTool


    /*******************************************************************************
    * qButtonTool::~qButtonTool
    *******************************************************************************/
    qButtonTool::~qButtonTool()
	{
    } // qButtonTool::~qButtonTool


    /*******************************************************************************
    * qButtonTool::IsMouseOnButton
    *******************************************************************************/
    bool qButtonTool::IsMouseOnButton(const qVector2D<s32>    &_v2dLocal) const
    {
        const qButtonBase *pOwner = dynamic_cast<const qButtonBase *> (GetOwnerWin());
        CHECK_PRE_CONDITION(pOwner != nullptr, false);

        qRect2D<s32>    r = pOwner->GetMarginRect();

        return (_v2dLocal.x > r.x) &&
               (_v2dLocal.x < r.r()) &&
               (_v2dLocal.y > r.y) &&
               (_v2dLocal.y < r.b());
    } // qButtonTool::IsMouseOnButton


    /*******************************************************************************
    * qButtonTool::OnLeave
    *******************************************************************************/
    enumToolResult qButtonTool::OnLeave(u32                   /*_u32Modifiers*/)
    {
        qButtonBase *pOwner = dynamic_cast<qButtonBase *> (GetOwnerWin());
        CHECK_PRE_CONDITION(pOwner != nullptr, enumToolResult::Unhandled);

        pOwner->Update();

        return enumToolResult::Handled;
    } // qButtonTool::OnLeave


    /*******************************************************************************
    * qButtonTool::OnMouseMove
    *******************************************************************************/
    enumToolResult qButtonTool::OnMouseMove(u32                   /*_u32Modifiers*/,
                                            u32                   /*_u32MouseButton*/,
                                            const qVector2D<s32>  &/*_v2dLocal*/,
                                            const qVector2D<s32>  &/*_v2dGlobal*/)
    {
        qButtonBase *pOwner = dynamic_cast<qButtonBase *> (GetOwnerWin());
        CHECK_PRE_CONDITION(pOwner != nullptr, enumToolResult::Unhandled);

        pOwner->Update();

        return enumToolResult::Handled;
    } // qButtonTool::OnLMousePress


    /*******************************************************************************
    * qButtonTool::OnLMousePress
    *******************************************************************************/
    enumToolResult qButtonTool::OnLMousePress(u32                     /*_u32Modifiers*/,
                                              const qVector2D<s32>    &/*_v2dLocal*/,
                                              const qVector2D<s32>    &/*_v2dGlobal*/)
    {
        qButtonBase *pOwner = dynamic_cast<qButtonBase *> (GetOwnerWin());
        CHECK_PRE_CONDITION(pOwner != nullptr, enumToolResult::Unhandled);

        m_bSelectedBefore = pOwner->IsSelected();

        pOwner->SetSelected(!m_bSelectedBefore);

        pOwner->Update();

        return enumToolResult::Handled;
    } // qButtonTool::OnLMousePress


    /*******************************************************************************
    * qButtonTool::OnLMouseMove
    *******************************************************************************/
    enumToolResult qButtonTool::OnLMouseMove(u32                     /*_u32Modifiers*/,
                                              const qVector2D<s32>    &_v2dLocal,
                                              const qVector2D<s32>    &/*_v2dGlobal*/)
    {
        qButtonBase *pOwner = dynamic_cast<qButtonBase *> (GetOwnerWin());
        CHECK_PRE_CONDITION(pOwner != nullptr, enumToolResult::Unhandled);

        bool bOn    = IsMouseOnButton(_v2dLocal);
        bool bNew = (bOn)?   !m_bSelectedBefore : m_bSelectedBefore;

        pOwner->SetHover(bOn);

        if (bNew != pOwner->IsSelected())
        {
            pOwner->SetSelected(bNew);
            pOwner->Update();
        }

        return enumToolResult::Handled;
    } // qButtonTool::OnLMouseMove


    /*******************************************************************************
    * qButtonTool::OnLMouseRelease
    *******************************************************************************/
    enumToolResult qButtonTool::OnLMouseRelease(u32                     /*_u32Modifiers*/,
                                                const qVector2D<s32>    &_v2dLocal,
                                                const qVector2D<s32>    &/*_v2dGlobal*/)
    {
        qButtonBase *pOwner = dynamic_cast<qButtonBase *> (GetOwnerWin());
        CHECK_PRE_CONDITION(pOwner != nullptr, enumToolResult::Unhandled);

        if (IsMouseOnButton(_v2dLocal))
        {
            if (pOwner->IsSelectable())
            {
                // the button already has the correct selection state (from press/move event)
                // just send the message
                pOwner->GetCtrlMgr()->SendCtrlMessage(pOwner, MSG_CLICKED);
            }
            else
            {
                // the button is selected => set unselected and send the message
                pOwner->SetSelected(false);
                pOwner->Update();
                if (pOwner->GetCtrlMgr() != nullptr)
                {
                    pOwner->GetCtrlMgr()->SendCtrlMessage(pOwner, MSG_CLICKED);
                }
            }
        }

        return enumToolResult::Handled;
    } // qButtonTool::OnLMouseRelease

} // namespace qLib
