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
#include "Object/qMargin.h"

#include "Math/qVector2D.h"
#include "Math/qRect2D.h"

#include "Util/qUtil.h"

#include "Win/FrameWin/qWin.h"

#include "qBorderResizeTool.h"

using namespace qLib::Math;
using namespace qLib::Win;

namespace qLib {
namespace Tool {


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
    const qWin *pOwner = ownerWin();
    CHECK_PRE_CONDITION(pOwner != nullptr, enumPosition::None);

    enumPosition    pos         = enumPosition::Inside;

    // maximized win => position always inside
    if (!pOwner->isMaximized())
    {
        qRect2D<s32>    rctMargin = pOwner->marginRect();
        const qMargin   &margins  = pOwner->margin();
        const qMargin   &border   = pOwner->border();

        s32             x = _v2dLocal.x();
        s32             y = _v2dLocal.y();
        bool            l = (x >= 0) && (x < margins.l() + border.l());
        bool            r = (x < rctMargin.r()) && (x > rctMargin.r() - margins.r() - border.r());
        bool            t = (y >= 0) && (y < margins.t() + border.t());
        bool            b = (y < rctMargin.b()) && (y > rctMargin.b() - margins.t() - border.t());

        pos = (t && l)?                             enumPosition::NorthWest :
              (t && r)?                             enumPosition::NorthEast :
              (b && l)?                             enumPosition::SouthWest :
              (b && r)?                             enumPosition::SouthEast :
              (l)?                                  enumPosition::West :
              (r)?                                  enumPosition::East :
              (t)?                                  enumPosition::North :
              (b)?                                  enumPosition::South :
              (rctMargin.pointInRect(_v2dLocal))?   enumPosition::Inside : enumPosition::Outside;
    }

    return pos;
} // qBorderResizeTool::Position


/*******************************************************************************
* qBorderResizeTool::onLeave
*******************************************************************************/
enumToolResult qBorderResizeTool::onLeave(u32 /*_u32Modifiers*/)
{
    m_eLastPos = enumPosition::None;

    return enumToolResult::Handled;
} // qBorderResizeTool::onLeave


/*******************************************************************************
* qBorderResizeTool::onMouseMove
*******************************************************************************/
enumToolResult qBorderResizeTool::onMouseMove(u32                   /*_u32Modifiers*/,
                                              u32                   /*_u32MouseButton*/,
                                              const qVector2D<s32>  &_v2dLocal,
                                              const qVector2D<s32>  &/*_v2dGlobal*/)
{
    qWin *pOwner = ownerWin();
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
                pOwner->setCursor(qCursor(enumCursorShape::Size_TR_BL));
                break;

            case enumPosition::SouthEast:
                pOwner->setCursor(qCursor(enumCursorShape::Size_TL_BR));
                break;

            case enumPosition::SouthWest:
                pOwner->setCursor(qCursor(enumCursorShape::Size_TR_BL));
                break;

            case enumPosition::NorthWest:
                pOwner->setCursor(qCursor(enumCursorShape::Size_TL_BR));
                break;

            case enumPosition::North:
                pOwner->setCursor(qCursor(enumCursorShape::SizeVer));
                break;

            case enumPosition::East:
                pOwner->setCursor(qCursor(enumCursorShape::SizeHor));
                break;

            case enumPosition::South:
                pOwner->setCursor(qCursor(enumCursorShape::SizeVer));
                break;

            case enumPosition::West:
                pOwner->setCursor(qCursor(enumCursorShape::SizeHor));
                break;

            case enumPosition::Inside:
                pOwner->setCursor(qCursor(enumCursorShape::Arrow));
                break;
        }
    }

    return enumToolResult::Handled;
} // qBorderResizeTool::onMouseMove


/*******************************************************************************
* qBorderResizeTool::onLMousePress
*******************************************************************************/
enumToolResult qBorderResizeTool::onLMousePress(u32                     /*_u32Modifiers*/,
                                                const qVector2D<s32>    &_v2dLocal,
                                                const qVector2D<s32>    &/*_v2dGlobal*/)
{
    qWin *pOwner = ownerWin();
    CHECK_PRE_CONDITION(pOwner != nullptr, enumToolResult::Unhandled);

    // maximized win => no geometry change
    CHECK_PRE_CONDITION(!pOwner->isMaximized(), enumToolResult::Unhandled);

    m_eResizePos = Position(_v2dLocal);
    m_r2dResizeStart = pOwner->geometry();

    return enumToolResult::Handled;
} // qBorderResizeTool::onLMousePress


/*******************************************************************************
* qBorderResizeTool::onLMouseMove
*******************************************************************************/
enumToolResult qBorderResizeTool::onLMouseMove(u32                     /*_u32Modifiers*/,
                                               const qVector2D<s32>    &/*_v2dLocal*/,
                                               const qVector2D<s32>    &_v2dGlobal)
{
    qWin *pOwner = ownerWin();
    CHECK_PRE_CONDITION(pOwner != nullptr, enumToolResult::Unhandled);

    // maximized win => no geometry change
    CHECK_PRE_CONDITION(!pOwner->isMaximized(), enumToolResult::Unhandled);

    qRect2D<s32>    newGeo  = m_r2dResizeStart;

    s32             minW    = pOwner->minSize().w();
    s32             maxW    = pOwner->maxSize().w();
    s32             minH    = pOwner->minSize().h();
    s32             maxH    = pOwner->maxSize().h();

    s32             moveX   = moveDeltaGlobal().x();
    s32             moveY   = moveDeltaGlobal().y();

    switch (m_eResizePos)
    {
        default:
            break;

        case enumPosition::NorthEast:
            newGeo.w() = Util::clamp<s32>(m_r2dResizeStart.w() + moveX, minW, maxW);

            newGeo.y() = Util::clamp<s32>(_v2dGlobal.y(), m_r2dResizeStart.b() - maxH, m_r2dResizeStart.b() - minH);
            newGeo.h() = m_r2dResizeStart.b() - newGeo.y();
            break;

        case enumPosition::SouthEast:
            newGeo.w() = Util::clamp<s32>(m_r2dResizeStart.w() + moveX, minW, maxW);
            newGeo.h() = Util::clamp<s32>(m_r2dResizeStart.h() + moveY, minH, maxH);
            break;

        case enumPosition::SouthWest:
            newGeo.x() = Util::clamp<s32>(_v2dGlobal.x(), m_r2dResizeStart.r() - maxW, m_r2dResizeStart.r() - minW);
            newGeo.w() = m_r2dResizeStart.r() - newGeo.x();

            newGeo.h() = Util::clamp<s32>(m_r2dResizeStart.h() + moveY, minH, maxH);
            break;

        case enumPosition::NorthWest:
            newGeo.x() = Util::clamp<s32>(_v2dGlobal.x(), m_r2dResizeStart.r() - maxW, m_r2dResizeStart.r() - minW);
            newGeo.w() = m_r2dResizeStart.r() - newGeo.x();

            newGeo.y() = Util::clamp<s32>(_v2dGlobal.y(), m_r2dResizeStart.b() - maxH, m_r2dResizeStart.b() - minH);
            newGeo.h() = m_r2dResizeStart.b() - newGeo.y();
            break;

        case enumPosition::North:
            newGeo.y() = Util::clamp<s32>(_v2dGlobal.y(), m_r2dResizeStart.b() - maxH, m_r2dResizeStart.b() - minH);
            newGeo.h() = m_r2dResizeStart.b() - newGeo.y();
            break;

        case enumPosition::East:
            newGeo.w() = Util::clamp<s32>(m_r2dResizeStart.w() + moveX, minW, maxW);
            break;

        case enumPosition::South:
            newGeo.h() = Util::clamp<s32>(m_r2dResizeStart.h() + moveY, minH, maxH);
            break;

        case enumPosition::West:
            newGeo.x() = Util::clamp<s32>(_v2dGlobal.x(), m_r2dResizeStart.r() - maxW, m_r2dResizeStart.r() - minW);
            newGeo.w() = m_r2dResizeStart.r() - newGeo.x();
            break;
    }

    pOwner->setGeometry(newGeo);

    return enumToolResult::Handled;
} // qBorderResizeTool::onLMouseMove


} // namespace Tool
} // namespace qLib
