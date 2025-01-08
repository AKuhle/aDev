/*******************************************************************************
* \file qBorderResizeTool.inl
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
#include "qBorderResizeTool.h"
#include "qWin.h"
#include "qCursor.h"


namespace qLib
{
    /*******************************************************************************
    * qBorderResizeTool::qBorderResizeTool
    *******************************************************************************/
    qBorderResizeTool::qBorderResizeTool(qWin   *_pOwnerWin,
                                         u32    _u32ToolId,
                                         u64    _u64ToolBaseFunction)
    : qToolBase(_pOwnerWin, _u32ToolId, _u64ToolBaseFunction)
	{
    } // qBorderResizeTool::qBorderResizeTool


    /*******************************************************************************
    * qBorderResizeTool::~qBorderResizeTool
    *******************************************************************************/
    qBorderResizeTool::~qBorderResizeTool()
	{
    } // qBorderResizeTool::~qBorderResizeTool


    /*******************************************************************************
    * qBorderResizeTool::Position
    *******************************************************************************/
    enumPosition qBorderResizeTool::Position(const qVector2D<s32> &_v2dLocal) const
    {
        const qWin *pOwner = GetOwnerWin();
        CHECK_PRE_CONDITION(pOwner != nullptr, enumPosition::None);

        enumPosition    pos         = enumPosition::Inside;

        // maximized win => position always inside
        if (!pOwner->IsMaximized())
        {
            qRect2D<s32>    rctMargin = pOwner->GetMarginRect();
            const qEdges    &margins  = pOwner->GetMarginEdges();
            const qEdges    &border   = pOwner->GetBorderEdges();

            s32             x = _v2dLocal.x;
            s32             y = _v2dLocal.y;
            bool            l = (x >= 0) && (x < margins.l + border.l);
            bool            r = (x < rctMargin.r()) && (x > rctMargin.r() - margins.r - border.r);
            bool            t = (y >= 0) && (y < margins.t + border.t);
            bool            b = (y < rctMargin.b()) && (y > rctMargin.b() - margins.t - border.t);

            pos = (t && l)?                             enumPosition::NorthWest :
                  (t && r)?                             enumPosition::NorthEast :
                  (b && l)?                             enumPosition::SouthWest :
                  (b && r)?                             enumPosition::SouthEast :
                  (l)?                                  enumPosition::West :
                  (r)?                                  enumPosition::East :
                  (t)?                                  enumPosition::North :
                  (b)?                                  enumPosition::South :
                  (rctMargin.PointInRect(_v2dLocal))?   enumPosition::Inside : enumPosition::Outside;
        }

        return pos;
    } // qBorderResizeTool::Position


    /*******************************************************************************
    * qBorderResizeTool::OnLeave
    *******************************************************************************/
    enumToolResult qBorderResizeTool::OnLeave(u32 /*_u32Modifiers*/)
    {
        m_eLastPos = enumPosition::None;

        return enumToolResult::Handled;
    } // qBorderResizeTool::OnLeave


    /*******************************************************************************
    * qBorderResizeTool::OnMouseMove
    *******************************************************************************/
    enumToolResult qBorderResizeTool::OnMouseMove(u32                   /*_u32Modifiers*/,
                                                  u32                   /*_u32MouseButton*/,
                                                  const qVector2D<s32>  &_v2dLocal,
                                                  const qVector2D<s32>  &/*_v2dGlobal*/)
    {
        qWin *pOwner = GetOwnerWin();
        CHECK_PRE_CONDITION(pOwner != nullptr, enumToolResult::Unhandled);

        enumPosition    pos = Position(_v2dLocal);

        if (pos != m_eLastPos)
        {
            m_eLastPos = pos;

            switch(pos)
            {
                default:
                    break;

                case enumPosition::NorthEast:
                    pOwner->SetCursor(qCursor(enumCursorShape::Size_TR_BL));
                    break;

                case enumPosition::SouthEast:
                    pOwner->SetCursor(qCursor(enumCursorShape::Size_TL_BR));
                    break;

                case enumPosition::SouthWest:
                    pOwner->SetCursor(qCursor(enumCursorShape::Size_TR_BL));
                    break;

                case enumPosition::NorthWest:
                    pOwner->SetCursor(qCursor(enumCursorShape::Size_TL_BR));
                    break;

                case enumPosition::North:
                    pOwner->SetCursor(qCursor(enumCursorShape::SizeVer));
                    break;

                case enumPosition::East:
                    pOwner->SetCursor(qCursor(enumCursorShape::SizeHor));
                    break;

                case enumPosition::South:
                    pOwner->SetCursor(qCursor(enumCursorShape::SizeVer));
                    break;

                case enumPosition::West:
                    pOwner->SetCursor(qCursor(enumCursorShape::SizeHor));
                    break;

                case enumPosition::Inside:
                    pOwner->SetCursor(qCursor(enumCursorShape::Arrow));
                    break;
            }
        }

        return enumToolResult::Handled;
    } // qBorderResizeTool::OnMouseMove


    /*******************************************************************************
    * qBorderResizeTool::OnLMousePress
    *******************************************************************************/
    enumToolResult qBorderResizeTool::OnLMousePress(u32                     /*_u32Modifiers*/,
                                                    const qVector2D<s32>    &_v2dLocal,
                                                    const qVector2D<s32>    &/*_v2dGlobal*/)
    {
        qWin *pOwner = GetOwnerWin();
        CHECK_PRE_CONDITION(pOwner != nullptr, enumToolResult::Unhandled);

        // maximized win => no geometry change
        CHECK_PRE_CONDITION(!pOwner->IsMaximized(), enumToolResult::Unhandled);

        m_eResizePos = Position(_v2dLocal);
        m_r2dResizeStart = pOwner->GeometryRect();

        return enumToolResult::Handled;
    } // qBorderResizeTool::OnLMousePress


    /*******************************************************************************
    * qBorderResizeTool::OnLMouseMove
    *******************************************************************************/
    enumToolResult qBorderResizeTool::OnLMouseMove(u32                     /*_u32Modifiers*/,
                                                    const qVector2D<s32>    &/*_v2dLocal*/,
                                                    const qVector2D<s32>    &_v2dGlobal)
    {
        qWin *pOwner = GetOwnerWin();
        CHECK_PRE_CONDITION(pOwner != nullptr, enumToolResult::Unhandled);

        // maximized win => no geometry change
        CHECK_PRE_CONDITION(!pOwner->IsMaximized(), enumToolResult::Unhandled);

        qRect2D<s32>    newGeo  = m_r2dResizeStart;

        s32             minW    = pOwner->GetMinSize().w;
        s32             maxW    = pOwner->GetMaxSize().w;
        s32             minH    = pOwner->GetMinSize().h;
        s32             maxH    = pOwner->GetMaxSize().h;

        s32             moveX   = GetMoveDeltaGlobal().x;
        s32             moveY   = GetMoveDeltaGlobal().y;

        typedef         MU<s32> mu;

        switch (m_eResizePos)
        {
            default:
                break;

            case enumPosition::NorthEast:
                newGeo.w = mu::Clamp(m_r2dResizeStart.w + moveX, minW, maxW);

                newGeo.y = mu::Clamp(_v2dGlobal.y, m_r2dResizeStart.b() - maxH, m_r2dResizeStart.b() - minH);
                newGeo.h = m_r2dResizeStart.b() - newGeo.y;
                break;

            case enumPosition::SouthEast:
                newGeo.w = mu::Clamp(m_r2dResizeStart.w + moveX, minW, maxW);
                newGeo.h = mu::Clamp(m_r2dResizeStart.h + moveY, minH, maxH);
                break;

            case enumPosition::SouthWest:
                newGeo.x = mu::Clamp(_v2dGlobal.x, m_r2dResizeStart.r() - maxW, m_r2dResizeStart.r() - minW);
                newGeo.w = m_r2dResizeStart.r() - newGeo.x;

                newGeo.h = mu::Clamp(m_r2dResizeStart.h + moveY, minH, maxH);
                break;

            case enumPosition::NorthWest:
                newGeo.x = mu::Clamp(_v2dGlobal.x, m_r2dResizeStart.r() - maxW, m_r2dResizeStart.r() - minW);
                newGeo.w = m_r2dResizeStart.r() - newGeo.x;

                newGeo.y = mu::Clamp(_v2dGlobal.y, m_r2dResizeStart.b() - maxH, m_r2dResizeStart.b() - minH);
                newGeo.h = m_r2dResizeStart.b() - newGeo.y;
                break;

            case enumPosition::North:
                newGeo.y = mu::Clamp(_v2dGlobal.y, m_r2dResizeStart.b() - maxH, m_r2dResizeStart.b() - minH);
                newGeo.h = m_r2dResizeStart.b() - newGeo.y;
                break;

            case enumPosition::East:
                newGeo.w = mu::Clamp(m_r2dResizeStart.w + moveX, minW, maxW);
                break;

            case enumPosition::South:
                newGeo.h = mu::Clamp(m_r2dResizeStart.h + moveY, minH, maxH);
                break;

            case enumPosition::West:
                newGeo.x = mu::Clamp(_v2dGlobal.x, m_r2dResizeStart.r() - maxW, m_r2dResizeStart.r() - minW);
                newGeo.w = m_r2dResizeStart.r() - newGeo.x;
                break;
        }

        pOwner->SetGeometry(newGeo);

        return enumToolResult::Handled;
    } // qBorderResizeTool::OnLMouseMove


} // namespace qLib
