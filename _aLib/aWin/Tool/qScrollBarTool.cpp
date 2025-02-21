/*******************************************************************************
* \file qScrollBarTool.inl
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
#include "qScrollBarTool.h"
#include "qWin.h"
#include "qScrollBar.h"


namespace qLib
{
    /*******************************************************************************
    * qScrollBarTool::qScrollBarTool
    *******************************************************************************/
    qScrollBarTool::qScrollBarTool(qWin   *_pOwnerWin,
                                   u32    _u32ToolId)
    : qToolBase(_pOwnerWin, _u32ToolId, TBF_NONE)
	{
    } // qScrollBarTool::qScrollBarTool


    /*******************************************************************************
    * qScrollBarTool::~qScrollBarTool
    *******************************************************************************/
    qScrollBarTool::~qScrollBarTool()
	{
    } // qScrollBarTool::~qScrollBarTool


    /*******************************************************************************
    * qScrollBarTool::OnLMousePress
    *******************************************************************************/
    enumToolResult qScrollBarTool::OnLMousePress(u32                     /*_u32Modifiers*/,
                                                 const qVector2D<s32>    &_v2dLocal,
                                                 const qVector2D<s32>    &/*_v2dGlobal*/)
    {
        qScrollBar *pSB = dynamic_cast<qScrollBar *> (GetOwnerWin());
        CHECK_PRE_CONDITION(pSB != nullptr, enumToolResult::Unhandled);

        bool            bHori       = (pSB->GetOrientation() == enumOrientation::Hori);
        bool            bVert       = (pSB->GetOrientation() == enumOrientation::Vert);

        //qRect2D<s32>    r2dArea     = pSB->GetSlideArea();
        qRect2D<s32>    r2dHandle   = pSB->GetSliderRect();

        // click left/above of the handle => page decrement
        if ((bHori && _v2dLocal.x < r2dHandle.l()) ||
            (bVert && _v2dLocal.y < r2dHandle.t()))
        {
           pSB->SendToolMsg(this, MSG_PAGE_DEC);
        }

        // click right/below of the handle => page increment
        else if ((bHori && _v2dLocal.x > r2dHandle.r()) ||
                 (bVert && _v2dLocal.y > r2dHandle.b()))
        {
            pSB->SendToolMsg(this, MSG_PAGE_INC);
        }

        else
        {
            m_s32SliderStartPos = pSB->GetPos();
            m_bSliding = true;
        }

        return enumToolResult::Handled;
    } // qScrollBarTool::OnLMousePress


    /*******************************************************************************
    * qScrollBarTool::OnLMouseMove
    *******************************************************************************/
    enumToolResult qScrollBarTool::OnLMouseMove(u32                     /*_u32Modifiers*/,
                                                const qVector2D<s32>    &/*_v2dLocal*/,
                                                const qVector2D<s32>    &/*_v2dGlobal*/)
    {
        qScrollBar *pSB = dynamic_cast<qScrollBar *> (GetOwnerWin());
        CHECK_PRE_CONDITION(pSB != nullptr, enumToolResult::Unhandled);

        if (m_bSliding)
        {
            switch (pSB->GetOrientation())
            {
                case enumOrientation::Hori:
                    pSB->SendToolMsg(this, MSG_SLIDER_POS_MOVED, m_s32SliderStartPos + GetMoveDeltaLocal().x);
                    break;

                case enumOrientation::Vert:
                    pSB->SendToolMsg(this, MSG_SLIDER_POS_MOVED, m_s32SliderStartPos + GetMoveDeltaLocal().y);
                    break;
            }

        } // if (m_bSliding)

        return enumToolResult::Handled;
    } // qScrollBarTool::OnLMouseMove


    /*******************************************************************************
    * qScrollBarTool::OnLMouseRelease
    *******************************************************************************/
    enumToolResult qScrollBarTool::OnLMouseRelease(u32                     /*_u32Modifiers*/,
                                                   const qVector2D<s32>    &/*_v2dLocal*/,
                                                   const qVector2D<s32>    &/*_v2dGlobal*/)
    {
        qScrollBar *pSB = dynamic_cast<qScrollBar *> (GetOwnerWin());
        CHECK_PRE_CONDITION(pSB != nullptr, enumToolResult::Unhandled);

        if (m_bSliding)
        {
            switch (pSB->GetOrientation())
            {
                case enumOrientation::Hori:
                    pSB->SendToolMsg(this, MSG_SLIDER_POS_SET, m_s32SliderStartPos + GetMoveDeltaLocal().x);
                    break;

                case enumOrientation::Vert:
                    pSB->SendToolMsg(this, MSG_SLIDER_POS_SET, m_s32SliderStartPos + GetMoveDeltaLocal().y);
                    break;
            }

            m_bSliding = false;
        } // if (m_bSliding)

        return enumToolResult::Handled;
    } // qScrollBarTool::OnLMouseRelease

} // namespace qLib
