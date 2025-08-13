/*******************************************************************************
* \file aToolBase.cpp
* \author Andreas Kuhlewind
*
* \brief
*
*  Detailed description starts here.
*******************************************************************************/


/*******************************************************************************
* includes
*******************************************************************************/
#include "aToolBase.h"
#include "aBaseWin.h"



/*******************************************************************************
* namespace
*******************************************************************************/
namespace aFrame {
namespace aWin {


/*******************************************************************************
* aToolBase::aToolBase
*******************************************************************************/
aToolBase::aToolBase(aBaseWin   *_pOwner,
                     u32        _u32ToolId,
                     u32        _u32Flags,
                     aToolCb    *_pToolCb)
: m_pOwner(_pOwner),
  m_u32ToolId(_u32ToolId),
  m_u32Flags(_u32Flags),
  m_pToolCb(_pToolCb)
{
} // aToolBase::aToolBase


/*******************************************************************************
* aToolBase::~aToolBase
*******************************************************************************/
aToolBase::~aToolBase()
{
} // aToolBase::~aToolBase


/*******************************************************************************
* aToolBase::ownerParent
*******************************************************************************/
aBaseWin* aToolBase::ownerParent() const
{
    CHECK_PRE_CONDITION(m_pOwner, nullptr);

    return m_pOwner->parent();
} // aToolBase::ownerParent


/*******************************************************************************
* aToolBase::onActivate
*******************************************************************************/
void aToolBase::onActivate(bool /*_bActivate*/)
{
} // aToolBase::onActivate


/*******************************************************************************
* aToolBase::onLDoubleClick
*******************************************************************************/
enumToolResult aToolBase::onLDoubleClick(u16              /*_u16Modifier*/,
                                         const aPoint     &/*_pntLocal*/,
                                         const aPoint     &/*_pntGlobal*/)
{
    return enumToolResult::UNHANDLED;
} // aToolBase::onLDoubleClick


/*******************************************************************************
* aToolBase::onMDoubleClick
*******************************************************************************/
enumToolResult aToolBase::onMDoubleClick(u16              /*_u16Modifier*/,
                                         const aPoint     &/*_pntLocal*/,
                                         const aPoint     &/*_pntGlobal*/)
{
    return enumToolResult::UNHANDLED;
} // aToolBase::onMDoubleClick


/*******************************************************************************
* aToolBase::onRDoubleClick
*******************************************************************************/
enumToolResult aToolBase::onRDoubleClick(u16              /*_u16Modifier*/,
                                         const aPoint     &/*_pntLocal*/,
                                         const aPoint     &/*_pntGlobal*/)
{
    return enumToolResult::UNHANDLED;
} // aToolBase::onRDoubleClick


/*******************************************************************************
* aToolBase::onLButtonPress
*******************************************************************************/
enumToolResult aToolBase::onLButtonPress(u16              /*_u16Modifier*/,
                                         const aPoint     &/*_pntLocal*/,
                                         const aPoint     &/*_pntGlobal*/)
{
    return enumToolResult::UNHANDLED;
} // aToolBase::onLButtonPress


/*******************************************************************************
* aToolBase::onMButtonPress
*******************************************************************************/
enumToolResult aToolBase::onMButtonPress(u16              /*_u16Modifier*/,
                                         const aPoint     &/*_pntLocal*/,
                                         const aPoint     &/*_pntGlobal*/)
{
    return enumToolResult::UNHANDLED;
} // aToolBase::onMButtonPress


/*******************************************************************************
* aToolBase::onRButtonPress
*******************************************************************************/
enumToolResult aToolBase::onRButtonPress(u16              /*_u16Modifier*/,
                                         const aPoint     &/*_pntLocal*/,
                                         const aPoint     &/*_pntGlobal*/)
{
    return enumToolResult::UNHANDLED;
} // aToolBase::onRButtonPress


/*******************************************************************************
* aToolBase::onMouseMove
*******************************************************************************/
enumToolResult aToolBase::onMouseMove(u16              /*_u16Modifier*/,
                                      const aPoint     &/*_pntLocal*/,
                                      const aPoint     &/*_pntGlobal*/)
{
    return enumToolResult::UNHANDLED;
} // aToolBase::onMouseMove


/*******************************************************************************
* aToolBase::onLMouseMove
*******************************************************************************/
enumToolResult aToolBase::onLMouseMove(u16              /*_u16Modifier*/,
                                       const aPoint     &/*_pntLocal*/,
                                       const aPoint     &/*_pntGlobal*/)
{
    return enumToolResult::UNHANDLED;
} // aToolBase::onLMouseMove


/*******************************************************************************
* aToolBase::onMMouseMove
*******************************************************************************/
enumToolResult aToolBase::onMMouseMove(u16              /*_u16Modifier*/,
                                       const aPoint     &/*_pntLocal*/,
                                       const aPoint     &/*_pntGlobal*/)
{
    return enumToolResult::UNHANDLED;
} // aToolBase::onMMouseMove


/*******************************************************************************
* aToolBase::onRMouseMove
*******************************************************************************/
enumToolResult aToolBase::onRMouseMove(u16              /*_u16Modifier*/,
                                       const aPoint     &/*_pntLocal*/,
                                       const aPoint     &/*_pntGlobal*/)
{
    return enumToolResult::UNHANDLED;
} // aToolBase::onRMouseMove


/*******************************************************************************
* aToolBase::onLButtonRelease
*******************************************************************************/
enumToolResult aToolBase::onLButtonRelease(u16              /*_u16Modifier*/,
                                           const aPoint     &/*_pntLocal*/,
                                           const aPoint     &/*_pntGlobal*/)
{
    return enumToolResult::UNHANDLED;
} // aToolBase::onLButtonRelease


/*******************************************************************************
* aToolBase::onMButtonRelease
*******************************************************************************/
enumToolResult aToolBase::onMButtonRelease(u16              /*_u16Modifier*/,
                                           const aPoint     &/*_pntLocal*/,
                                           const aPoint     &/*_pntGlobal*/)
{
    return enumToolResult::UNHANDLED;
} // aToolBase::onMButtonRelease


/*******************************************************************************
* aToolBase::onRButtonRelease
*******************************************************************************/
enumToolResult aToolBase::onRButtonRelease(u16              /*_u16Modifier*/,
                                           const aPoint     &/*_pntLocal*/,
                                           const aPoint     &/*_pntGlobal*/)
{
    return enumToolResult::UNHANDLED;
} // aToolBase::onRButtonRelease


/*******************************************************************************
* aToolBase::onToolDoubleClick
*******************************************************************************/
enumToolResult aToolBase::onToolDoubleClick(u16             _u16Modifier,
                                            u16             _u16Btn,
                                            const aPoint    &_pntLocal,
                                            const aPoint    &_pntGlobal)
{
    enumToolResult eResult = enumToolResult::UNHANDLED;

    if (_u16Btn == MOUSE_BTN_LEFT)
    {
        eResult = onLDoubleClick(_u16Modifier, _pntLocal, _pntGlobal);
    }
    else if (_u16Btn == MOUSE_BTN_MIDDLE)
    {
        eResult = onMDoubleClick(_u16Modifier, _pntLocal, _pntGlobal);
    }
    else if (_u16Btn == MOUSE_BTN_RIGHT)
    {
        eResult = onRDoubleClick(_u16Modifier, _pntLocal, _pntGlobal);
    }

    return eResult;
} // aToolBase::onToolDoubleClick


/*******************************************************************************
* aToolBase::onToolButtonPress
*******************************************************************************/
enumToolResult aToolBase::onToolButtonPress(u16             _u16Modifier,
                                            u16             _u16Btn,
                                            const aPoint    &_pntLocal,
                                            const aPoint    &_pntGlobal)
{
    enumToolResult eResult = enumToolResult::UNHANDLED;

    // set the start point for m position tracking
    m_u16Btn            = _u16Btn;
    m_pntStartLocal     = _pntLocal;
    m_pntStartGlobal    = _pntGlobal;

    if (_u16Btn == MOUSE_BTN_LEFT)
    {
        eResult = onLButtonPress(_u16Modifier, _pntLocal, _pntGlobal);
    }
    else if (_u16Btn == MOUSE_BTN_MIDDLE)
    {
        eResult = onMButtonPress(_u16Modifier, _pntLocal, _pntGlobal);
    }
    else if (_u16Btn == MOUSE_BTN_RIGHT)
    {
        eResult = onRButtonPress(_u16Modifier, _pntLocal, _pntGlobal);
    }

    return eResult;
} // aToolBase::onToolButtonPress


/*******************************************************************************
* aToolBase::onToolMouseMove
*******************************************************************************/
enumToolResult aToolBase::onToolMouseMove(u16           _u16Modifier,
                                           u16          /*_u16Btn*/,
                                           const aPoint &_pntLocal,
                                           const aPoint &_pntGlobal)
{
    enumToolResult eResult = enumToolResult::UNHANDLED;

    // calculate the move delta
    m_pntDelta = _pntGlobal - m_pntStartGlobal;

    if (m_u16Btn == MOUSE_BTN_NONE)
    {
        eResult = onMouseMove(_u16Modifier, _pntLocal, _pntGlobal);
    }
    else if (m_u16Btn == MOUSE_BTN_LEFT)
    {
        eResult = onLMouseMove(_u16Modifier, _pntLocal, _pntGlobal);
    }
    else if (m_u16Btn == MOUSE_BTN_MIDDLE)
    {
        eResult = onMMouseMove(_u16Modifier, _pntLocal, _pntGlobal);
    }
    else if (m_u16Btn == MOUSE_BTN_RIGHT)
    {
        eResult = onRMouseMove(_u16Modifier, _pntLocal, _pntGlobal);
    }

    return eResult;
} // aToolBase::onToolMouseMove


/*******************************************************************************
* aToolBase::onToolButtonRelease
*******************************************************************************/
enumToolResult aToolBase::onToolButtonRelease(u16           _u16Modifier,
                                              u16           /*_u16Btn*/,
                                              const aPoint  &_pntLocal,
                                              const aPoint  &_pntGlobal)
{
    enumToolResult eResult = enumToolResult::UNHANDLED;

    // set the start point for m position tracking
    m_pntStartLocal  = _pntLocal;
    m_pntStartGlobal = _pntGlobal;

    if (m_u16Btn == MOUSE_BTN_LEFT)
    {
        eResult = onLButtonRelease(_u16Modifier, _pntLocal, _pntGlobal);
    }
    else if (m_u16Btn == MOUSE_BTN_MIDDLE)
    {
        eResult = onMButtonRelease(_u16Modifier, _pntLocal, _pntGlobal);
    }
    else if (m_u16Btn == MOUSE_BTN_RIGHT)
    {
        eResult = onRButtonRelease(_u16Modifier, _pntLocal, _pntGlobal);
    }

    m_u16Btn = MOUSE_BTN_NONE;

    return eResult;
} // aToolBase::onToolButtonRelease


} // namespace aWin
} // namespace aFrame
