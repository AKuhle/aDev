/*******************************************************************************
* \file aBorderResizeTool.inl
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
#include "aGraphic/aGraphic_def.h"
#include "aWin/Tool/aBorderResizeTool.h"

#include "aUtil/aHelper.h"

#include "aGraphic/aCursor.h"

#include "aWin/Framework/aBaseWin.h"

using namespace aLib::aGraphic;
using namespace aLib::aUtil;


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aWin {


/*******************************************************************************
* aBorderResizeTool::aBorderResizeTool
*******************************************************************************/
aBorderResizeTool::aBorderResizeTool(aBaseWin   *_pOwnerWin,
                                     u32        _u32ToolId,
                                     u64        _u64ToolBaseFunction)
: aToolBase(_pOwnerWin, _u32ToolId, _u64ToolBaseFunction)
{
} // aBorderResizeTool::aBorderResizeTool


/*******************************************************************************
* aBorderResizeTool::~aBorderResizeTool
*******************************************************************************/
aBorderResizeTool::~aBorderResizeTool()
{
} // aBorderResizeTool::~aBorderResizeTool


/*******************************************************************************
* aBorderResizeTool::position
*******************************************************************************/
enumPosition aBorderResizeTool::position(const aVector2D<s32> &_v2dLocal) const
{
    const aBaseWin *pOwner = ownerWin();
    CHECK_PRE_CONDITION(pOwner != nullptr, enumPosition::None);

    enumPosition    pos         = enumPosition::Inside;

    // maximized win => position always inside
    if (!pOwner->isMaximized())
    {
        aRect2D<s32>    rctMargin = pOwner->winRect();
        const aMargin   &margins  = pOwner->margin();
        const aMargin   &border   = pOwner->border();

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
} // aBorderResizeTool::position


/*******************************************************************************
* aBorderResizeTool::setCursor
*******************************************************************************/
void aBorderResizeTool::setCursor(u32                   /*_u32Modifiers*/,
                                  const aVector2D<s32>  &_v2dLocal,
                                  const aVector2D<s32>  &/*_v2dGlobal*/)
{
    aBaseWin *pOwner = ownerWin();
    CHECK_PRE_CONDITION_VOID(pOwner != nullptr);

    enumPosition    pos = position(_v2dLocal);

    if (pos != m_eLastPos)
    {
        m_eLastPos = pos;

        switch(pos)
        {
            default:
                break;

            case enumPosition::NorthEast:
                pOwner->setCursor(aCursor(enumCursorShape::Size_TR_BL));
                break;

            case enumPosition::SouthEast:
                pOwner->setCursor(aCursor(enumCursorShape::Size_TL_BR));
                break;

            case enumPosition::SouthWest:
                pOwner->setCursor(aCursor(enumCursorShape::Size_TR_BL));
                break;

            case enumPosition::NorthWest:
                pOwner->setCursor(aCursor(enumCursorShape::Size_TL_BR));
                break;

            case enumPosition::North:
                pOwner->setCursor(aCursor(enumCursorShape::SizeVer));
                break;

            case enumPosition::East:
                pOwner->setCursor(aCursor(enumCursorShape::SizeHor));
                break;

            case enumPosition::South:
                pOwner->setCursor(aCursor(enumCursorShape::SizeVer));
                break;

            case enumPosition::West:
                pOwner->setCursor(aCursor(enumCursorShape::SizeHor));
                break;

            case enumPosition::Inside:
                pOwner->setCursor(aCursor(enumCursorShape::Arrow));
                break;
        }
    }
} // aBorderResizeTool::setCursor


/*******************************************************************************
* aBorderResizeTool::onLeave
*******************************************************************************/
enumToolResult aBorderResizeTool::onLeave(u32 /*_u32Modifiers*/)
{
    m_eLastPos = enumPosition::None;

    return enumToolResult::Handled;
} // aBorderResizeTool::onLeave


/*******************************************************************************
* aBorderResizeTool::onMouseMove
*******************************************************************************/
enumToolResult aBorderResizeTool::onMouseMove(u32                     _u32Modifiers,
                                              u32                     /*_u32MouseButton*/,
                                              const aVector2D<s32>    &_v2dLocal,
                                              const aVector2D<s32>    &_v2dGlobal)
{
    setCursor(_u32Modifiers, _v2dLocal, _v2dGlobal);

    return enumToolResult::Unhandled;
} // aBorderResizeTool::onMouseMove


/*******************************************************************************
* aBorderResizeTool::onLMousePress
*******************************************************************************/
enumToolResult aBorderResizeTool::onLMousePress(u32                     /*_u32Modifiers*/,
                                                const aVector2D<s32>    &_v2dLocal,
                                                const aVector2D<s32>    &/*_v2dGlobal*/)
{
    aBaseWin *pOwner = ownerWin();
    CHECK_PRE_CONDITION(pOwner != nullptr, enumToolResult::Unhandled);

    // maximized win => no geometry change
    CHECK_PRE_CONDITION(!pOwner->isMaximized(), enumToolResult::Unhandled);

    m_eResizePos = position(_v2dLocal);
    m_r2dResizeStart = pOwner->geometry();

    return enumToolResult::Handled;
} // aBorderResizeTool::onLMousePress


/*******************************************************************************
* aBorderResizeTool::onLMouseMove
*******************************************************************************/
enumToolResult aBorderResizeTool::onLMouseMove(u32                     /*_u32Modifiers*/,
                                               const aVector2D<s32>    &/*_v2dLocal*/,
                                               const aVector2D<s32>    &_v2dGlobal)
{
    aBaseWin *pOwner = ownerWin();
    CHECK_PRE_CONDITION(pOwner != nullptr, enumToolResult::Unhandled);

    // maximized win => no geometry change
    CHECK_PRE_CONDITION(!pOwner->isMaximized(), enumToolResult::Unhandled);

    aRect2D<s32>    newGeo  = m_r2dResizeStart;

    s32             minW    = pOwner->minDim().w();
    s32             maxW    = pOwner->maxDim().w();
    s32             minH    = pOwner->minDim().h();
    s32             maxH    = pOwner->maxDim().h();

    s32             moveX   = moveDeltaGlobal().x();
    s32             moveY   = moveDeltaGlobal().y();

    switch (m_eResizePos)
    {
        default:
            break;

        case enumPosition::NorthEast:
            newGeo.w() = aUtil::clamp<s32>(m_r2dResizeStart.w() + moveX, minW, maxW);

            newGeo.y() = aUtil::clamp<s32>(_v2dGlobal.y(), m_r2dResizeStart.b() - maxH, m_r2dResizeStart.b() - minH);
            newGeo.h() = m_r2dResizeStart.b() - newGeo.y();
            break;

        case enumPosition::SouthEast:
            newGeo.w() = aUtil::clamp<s32>(m_r2dResizeStart.w() + moveX, minW, maxW);
            newGeo.h() = aUtil::clamp<s32>(m_r2dResizeStart.h() + moveY, minH, maxH);
            break;

        case enumPosition::SouthWest:
            newGeo.x() = aUtil::clamp<s32>(_v2dGlobal.x(), m_r2dResizeStart.r() - maxW, m_r2dResizeStart.r() - minW);
            newGeo.w() = m_r2dResizeStart.r() - newGeo.x();

            newGeo.h() = aUtil::clamp<s32>(m_r2dResizeStart.h() + moveY, minH, maxH);
            break;

        case enumPosition::NorthWest:
            newGeo.x() = aUtil::clamp<s32>(_v2dGlobal.x(), m_r2dResizeStart.r() - maxW, m_r2dResizeStart.r() - minW);
            newGeo.w() = m_r2dResizeStart.r() - newGeo.x();

            newGeo.y() = aUtil::clamp<s32>(_v2dGlobal.y(), m_r2dResizeStart.b() - maxH, m_r2dResizeStart.b() - minH);
            newGeo.h() = m_r2dResizeStart.b() - newGeo.y();
            break;

        case enumPosition::North:
            newGeo.y() = aUtil::clamp<s32>(_v2dGlobal.y(), m_r2dResizeStart.b() - maxH, m_r2dResizeStart.b() - minH);
            newGeo.h() = m_r2dResizeStart.b() - newGeo.y();
            break;

        case enumPosition::East:
            newGeo.w() = aUtil::clamp<s32>(m_r2dResizeStart.w() + moveX, minW, maxW);
            break;

        case enumPosition::South:
            newGeo.h() = aUtil::clamp<s32>(m_r2dResizeStart.h() + moveY, minH, maxH);
            break;

        case enumPosition::West:
            newGeo.x() = aUtil::clamp<s32>(_v2dGlobal.x(), m_r2dResizeStart.r() - maxW, m_r2dResizeStart.r() - minW);
            newGeo.w() = m_r2dResizeStart.r() - newGeo.x();
            break;
    }

    pOwner->setGeometry(newGeo);

    return enumToolResult::Handled;
} // aBorderResizeTool::onLMouseMove


} // namespace aWin
} // namespace aLib
