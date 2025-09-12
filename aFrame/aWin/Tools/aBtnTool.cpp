/*******************************************************************************
* \file aBtnTool.cpp
* \author Andreas Kuhlewind
*
* \brief
*
*  Detailed description starts here.
*******************************************************************************/


/*******************************************************************************
* includes
*******************************************************************************/
#include "aBtnTool.h"
#include "aBaseWin.h"
#include "aCursor.h"
#include "aHelper.h"
#include "aBtn.h"

using namespace aFrame::aUtil;


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aFrame {
namespace aWin {


/*******************************************************************************
* aBtnTool::aBtnTool
*******************************************************************************/
aBtnTool::aBtnTool(aBaseWin   *_pOwner,
                   u32        _u32ToolId  /*= TOOL_ID_BUTTON*/,
                   u32        _u32Flags   /*= TF_NONE*/)
: aToolBase(_pOwner, _u32ToolId, _u32Flags, nullptr)
{
    _pOwner->setMouseTracking(true);
} // aBtnTool::aBtnTool


/*******************************************************************************
* aBtnTool::~aBtnTool
*******************************************************************************/
aBtnTool::~aBtnTool()
{
} // aBtnTool::~aBtnTool


/*******************************************************************************
* aBtnTool::stateColor
*******************************************************************************/
aColor aBtnTool::stateColor() const
{
    aBtn *pBtn = dynamic_cast<aBtn *> (ownerWin());
    CHECK_PRE_CONDITION(pBtn, colRed);

    bool    bDisabled   = pBtn->isDisabled();
    bool    bHover      = pBtn->isHover();
    bool    bChecked    = pBtn->isChecked();

    if (bDisabled)                          // disabled is disabled is disabled
        return pBtn->disabledColor();

    else if (m_bMousePressed && m_bMouseOver)
        return (bChecked)?   pBtn->normalColor() : pBtn->activeColor();

    else if (m_bMousePressed && !m_bMouseOver)
        return (bChecked)?   pBtn->activeColor() : pBtn->normalColor();

    else if (bHover)
        return pBtn->hoverColor();

    else if (bChecked)
        return pBtn->activeColor();

    else
        return pBtn->normalColor();

} // aBtnTool::stateColor


/*******************************************************************************
* aBtnTool::isOnBtn
*******************************************************************************/
bool aBtnTool::isOnBtn(const aPoint &_pntLocal) const
{
    aBtn *pBtn = dynamic_cast<aBtn *> (ownerWin());
    CHECK_PRE_CONDITION(pBtn, false);

    aRect   r = pBtn->contentRect();

    return r.pointInRect(_pntLocal);
} // aBtnTool::isOnBtn


/*******************************************************************************
* aBtnTool::onEnter
*******************************************************************************/
enumToolResult aBtnTool::onEnter(u16              /*_u16Modifier*/,
                                 const aPoint     &/*_pntLocal*/,
                                 const aPoint     &/*_pntGlobal*/)
{
    aBtn *pBtn = dynamic_cast<aBtn *> (ownerWin());
    CHECK_PRE_CONDITION(pBtn, enumToolResult::UNHANDLED);

    // if disabled => no state change
    CHECK_PRE_CONDITION(pBtn->isEnabled(), enumToolResult::HANDLED);

    m_bMouseOver = true;

    // update the button
    pBtn->update();

    return enumToolResult::HANDLED;
} // aBtnTool::onEnter


/*******************************************************************************
* aBtnTool::onLeave
*******************************************************************************/
enumToolResult aBtnTool::onLeave(u16 /*_u16Modifier*/)
{
    aBtn *pBtn = dynamic_cast<aBtn *> (ownerWin());
    CHECK_PRE_CONDITION(pBtn, enumToolResult::UNHANDLED);

    // if disabled => no state change
    CHECK_PRE_CONDITION(pBtn->isEnabled(), enumToolResult::HANDLED);

    m_bMouseOver = false;

    // update the button
    pBtn->update();

    return enumToolResult::HANDLED;
} // aBtnTool::onLeave


/*******************************************************************************
* aBtnTool::onLDoubleClick
*******************************************************************************/
enumToolResult aBtnTool::onLDoubleClick(u16              /*_u16Modifier*/,
                                        const aPoint     &/*_pntLocal*/,
                                        const aPoint     &/*_pntGlobal*/)
{
    // do nothing, but avoid to route it to the parent

    return enumToolResult::HANDLED;
} // aBtnTool::onLDoubleClick


/*******************************************************************************
* aBtnTool::onLButtonPress
*******************************************************************************/
enumToolResult aBtnTool::onLButtonPress(u16              /*_u16Modifier*/,
                                        const aPoint     &/*_pntLocal*/,
                                        const aPoint     &/*_pntGlobal*/)
{
    aBtn *pBtn = dynamic_cast<aBtn *> (ownerWin());
    CHECK_PRE_CONDITION(pBtn, enumToolResult::UNHANDLED);

    // if disabled => no state change
    CHECK_PRE_CONDITION(pBtn->isEnabled(), enumToolResult::HANDLED);

    m_bMouseOver    = true;
    m_bMousePressed = true;

    // update the button
    pBtn->update();

    return enumToolResult::HANDLED;
} // aBtnTool::onLButtonPress


/*******************************************************************************
* aBtnTool::onLMouseMove
*******************************************************************************/
enumToolResult aBtnTool::onLMouseMove(u16              /*_u16Modifier*/,
                                      const aPoint     &_pntLocal,
                                      const aPoint     &/*_pntGlobal*/)
{
    aBtn *pBtn = dynamic_cast<aBtn *> (ownerWin());
    CHECK_PRE_CONDITION(pBtn, enumToolResult::UNHANDLED);

    // if disabled => no state change
    CHECK_PRE_CONDITION(pBtn->isEnabled(), enumToolResult::HANDLED);

    m_bMouseOver = isOnBtn(_pntLocal);

    // update the button
    pBtn->update();

    return enumToolResult::HANDLED;
} // aBtnTool::onLMouseMove


/*******************************************************************************
* aBtnTool::onLButtonRelease
*******************************************************************************/
enumToolResult aBtnTool::onLButtonRelease(u16              /*_u16Modifier*/,
                                          const aPoint     &/*_pntLocal*/,
                                          const aPoint     &/*_pntGlobal*/)
{
    aBtn *pBtn = dynamic_cast<aBtn *> (ownerWin());
    CHECK_PRE_CONDITION(pBtn, enumToolResult::UNHANDLED);

    // if disabled => no state change
    CHECK_PRE_CONDITION(pBtn->isEnabled(), enumToolResult::HANDLED);

    // only if the mouse was on the button, the action is triggered
    if (m_bMouseOver)
    {
        if (pBtn->isCheckable())
        {
            // button is checkable => toggle the check state
            pBtn->setChecked(!pBtn->isChecked());
        }
        else
        {
            // button not checkable => press signal
        }

        // call the callback handler
        for (auto &cb : pBtn->m_vClickHandler)
        {
            cb(pBtn);
        }
    }

    // button is not longer pressed
    m_bMouseOver = false;
    m_bMousePressed = false;

    // update the button
    pBtn->update();

    return enumToolResult::HANDLED;
} // aBtnTool::onLButtonRelease


} // namespace aWin
} // namespace aFrame
