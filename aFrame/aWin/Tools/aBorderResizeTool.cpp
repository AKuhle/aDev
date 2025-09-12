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
#include "aCursor.h"
#include "aHelper.h"

using namespace aFrame::aUtil;


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aFrame {
namespace aWin {


/*******************************************************************************
* aBorderResizeTool::aBorderResizeTool
*******************************************************************************/
aBorderResizeTool::aBorderResizeTool(aBaseWin   *_pOwner,
                                     u32        _u32ToolId  /*= TOOL_ID_BORDER_RESIZE*/,
                                     u32        _u32Flags   /*= TF_NONE*/)
: aToolBase(_pOwner, _u32ToolId, _u32Flags, nullptr)
{
    _pOwner->setMouseTracking(true);
} // aBorderResizeTool::aBorderResizeTool


/*******************************************************************************
* aBorderResizeTool::~aBorderResizeTool
*******************************************************************************/
aBorderResizeTool::~aBorderResizeTool()
{
} // aBorderResizeTool::~aBorderResizeTool


/*******************************************************************************
* aBorderResizeTool::findPos
*******************************************************************************/
enumPosition aBorderResizeTool::findPos(const aPoint &_pntLocal) const
{
    CHECK_PRE_CONDITION(ownerWin(), enumPosition::None);

    aRect       rMargin = ownerWin()->marginRect();
    aMargin     mMargin = ownerWin()->marginMargin();
    aMargin     mBorder = ownerWin()->borderMargin();
    s32         x       = _pntLocal.x();
    s32         y       = _pntLocal.y();

    bool        l       = x >= rMargin.t() &&
                          x <= rMargin.t() + mMargin.l() + mBorder.l();

    bool        r       = x <= rMargin.r() &&
                          x >= rMargin.r() - mMargin.r() - mBorder.r();

    bool        t       = y >= rMargin.t() &&
                          y <= rMargin.t() + mMargin.t() + mBorder.t();

    bool        b       = y <= rMargin.b() &&
                          y >= rMargin.b() - mMargin.b() - mBorder.b();

    return (l && t)?    enumPosition::NorthWest :
           (r && t)?    enumPosition::NorthEast :
           (r && b)?    enumPosition::SouthEast :
           (l && b)?    enumPosition::SouthWest :
           (l)?         enumPosition::West :
           (r)?         enumPosition::East :
           (t)?         enumPosition::North :
           (b)?         enumPosition::South :
                        enumPosition::None;
} // aBorderResizeTool::findPos


/*******************************************************************************
* aBorderResizeTool::onMouseMove
*******************************************************************************/
enumToolResult aBorderResizeTool::onMouseMove(u16              /*_u16Modifier*/,
                                              const aPoint     &_pntLocal,
                                              const aPoint     &/*_pntGlobal*/)
{
    CHECK_PRE_CONDITION(ownerWin(), enumToolResult::UNHANDLED);

    switch (findPos(_pntLocal))
    {
        default:
            break;

        case enumPosition::North:
            ownerWin()->setCursor(aCursor(enumCursorShape::SizeVerCursor));
            break;

        case enumPosition::NorthEast:
            ownerWin()->setCursor(aCursor(enumCursorShape::SizeBDiagCursor));
            break;

        case enumPosition::East:
            ownerWin()->setCursor(aCursor(enumCursorShape::SizeHorCursor));
            break;

        case enumPosition::SouthEast:
            ownerWin()->setCursor(aCursor(enumCursorShape::SizeFDiagCursor));
            break;

        case enumPosition::South:
            ownerWin()->setCursor(aCursor(enumCursorShape::SizeVerCursor));
            break;

        case enumPosition::SouthWest:
            ownerWin()->setCursor(aCursor(enumCursorShape::SizeBDiagCursor));
            break;

        case enumPosition::West:
            ownerWin()->setCursor(aCursor(enumCursorShape::SizeHorCursor));
            break;

        case enumPosition::NorthWest:
            ownerWin()->setCursor(aCursor(enumCursorShape::SizeFDiagCursor));
            break;
    }

    return enumToolResult::HANDLED;
} // aBorderResizeTool::onMouseMove


/*******************************************************************************
* aBorderResizeTool::onLButtonPress
*******************************************************************************/
enumToolResult aBorderResizeTool::onLButtonPress(u16              /*_u16Modifier*/,
                                                 const aPoint     &_pntLocal,
                                                 const aPoint     &/*_pntGlobal*/)
{
    CHECK_PRE_CONDITION(ownerWin(), enumToolResult::UNHANDLED);

    m_rctOri = ownerWin()->geometryRect();
    m_eDirection = findPos(_pntLocal);

    return enumToolResult::HANDLED;
} // aBorderResizeTool::onLButtonPress


/*******************************************************************************
* aBorderResizeTool::onLMouseMove
*******************************************************************************/
enumToolResult aBorderResizeTool::onLMouseMove(u16              /*_u16Modifier*/,
                                               const aPoint     &/*_pntLocal*/,
                                               const aPoint     &/*_pntGlobal*/)
{
    CHECK_PRE_CONDITION(ownerWin(), enumToolResult::UNHANDLED);

    aRect           r   = m_rctOri;
    const aPoint    &d  = delta();
    const aPoint    dMax(m_rctOri.w() - ownerWin()->minW(),
                         m_rctOri.h() - ownerWin()->minH());

    switch (m_eDirection)
    {
        default:
            break;

        case enumPosition::North:
            r.y() += aUtil::min(d.y(), dMax.y());
            r.h() -= aUtil::min(d.y(), dMax.y());
            break;

        case enumPosition::NorthEast:
            r.y() += aUtil::min(d.y(), dMax.y());
            r.h() -= aUtil::min(d.y(), dMax.y());
            r.w() += d.x();
            break;

        case enumPosition::East:
            r.w() += d.x();
            break;

        case enumPosition::SouthEast:
            r.h() += d.y();
            r.w() += d.x();
            break;

        case enumPosition::South:
            r.h() += d.y();
            break;

        case enumPosition::SouthWest:
            r.h() += d.y();
            r.x() += aUtil::min(d.x(), dMax.x());
            r.w() -= aUtil::min(d.x(), dMax.x());
            break;

        case enumPosition::West:
            r.x() += aUtil::min(d.x(), dMax.x());
            r.w() -= aUtil::min(d.x(), dMax.x());
            break;

        case enumPosition::NorthWest:
            r.y() += aUtil::min(d.y(), dMax.y());
            r.h() -= aUtil::min(d.y(), dMax.y());
            r.x() += aUtil::min(d.x(), dMax.x());
            r.w() -= aUtil::min(d.x(), dMax.x());
            break;
    }

    ownerWin()->setGeometry(r);

    return enumToolResult::HANDLED;
} // aBorderResizeTool::onLMouseMove


/*******************************************************************************
* aBorderResizeTool::onLButtonRelease
*******************************************************************************/
enumToolResult aBorderResizeTool::onLButtonRelease(u16              /*_u16Modifier*/,
                                                 const aPoint     &/*_pntLocal*/,
                                                 const aPoint     &/*_pntGlobal*/)
{
    CHECK_PRE_CONDITION(ownerWin(), enumToolResult::UNHANDLED);

    return enumToolResult::HANDLED;
} // aBorderResizeTool::onLButtonRelease


} // namespace aWin
} // namespace aFrame
