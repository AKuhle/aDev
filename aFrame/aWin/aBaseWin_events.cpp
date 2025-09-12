/*******************************************************************************
* \file aBaseWin.cpp
* \author Andreas Kuhlewind
*
* \brief
*
*  Detailed description starts here.
*******************************************************************************/
#ifdef _USE_QT_


/*******************************************************************************
* includes
*******************************************************************************/
#include "aBaseWin.h"
#include "aToolMgr.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aFrame {
namespace aWin {


/*******************************************************************************
* aBaseWin::onCloseEvent
*******************************************************************************/
bool aBaseWin::onCloseEvent()
{
    return onCloseWin();
} // aBaseWin::onCloseEvent


/*******************************************************************************
* aBaseWin::onResizeEvent
*******************************************************************************/
void aBaseWin::onResizeEvent(const aDimension   &_dOldDim,
                             const aDimension   &_dNewDim)
{
    // Call the sys resize handler
    onSysResize(_dOldDim, _dNewDim);

    // Call the resize handler
    onResize(_dOldDim, _dNewDim);
} // aBaseWin::onResizeEvent


/*******************************************************************************
* aBaseWin::onPaintEvent
*******************************************************************************/
void aBaseWin::onPaintEvent()
{
    onPaintMargin();
    onPaintBorder();
    onPaintPadding();
    onPaintContentBg();
    onPaintContent();
} // aBaseWin::onPaintEvent


/*******************************************************************************
* aBaseWin::onEnterEvent
*******************************************************************************/
bool aBaseWin::onEnterEvent(u16             _u16Modifier,
                            const aPoint    &_pntLocal,
                            const aPoint    &_pntGlobal)
{
    aToolMgr    *pMgr       = dynamic_cast<aToolMgr *> (this);

    // set the hover flag
    m_bHover = true;

    // 1. let the active tool handle the event
    // 2. not handled by the tool => handle in window class
    return (pMgr != nullptr && pMgr->onToolMgrEnter(_u16Modifier, _pntLocal, _pntGlobal)) ||
           onEnter(_u16Modifier, _pntLocal, _pntGlobal);
} // aBaseWin::onEnterEvent


/*******************************************************************************
* aBaseWin::onLeaveEvent
*******************************************************************************/
bool aBaseWin::onLeaveEvent(u16 _u16Modifier)
{
    aToolMgr    *pMgr       = dynamic_cast<aToolMgr *> (this);

    // reset the hover flag
    m_bHover = false;

    // 1. let the active tool handle the event
    // 2. not handled by the tool => handle in window class
    return (pMgr != nullptr && pMgr->onToolMgrLeave(_u16Modifier)) ||
           onLeave(_u16Modifier);
} // aBaseWin::onLeaveEvent


/*******************************************************************************
* aBaseWin::onWheelEvent
*******************************************************************************/
bool aBaseWin::onWheelEvent(u16            _u16Modifier,
                            s16            _s16Degree,
                            const aPoint   &_pntLocal,
                            const aPoint   &_pntGlobal)
{
    aToolMgr *pMgr = dynamic_cast<aToolMgr *> (this);

    // 1. let the active tool handle the event
    // 2. not handled by the tool => handle in window class
    return (pMgr != nullptr && pMgr->onToolMgrWheel(_u16Modifier, _s16Degree, _pntLocal, _pntGlobal)) ||
           onWheel(_u16Modifier, _s16Degree, _pntLocal, _pntGlobal);
} // aBaseWin::onWheelEvent


/*******************************************************************************
* aBaseWin::onDoubleClickEvent
*******************************************************************************/
bool aBaseWin::onDoubleClickEvent(u16          _u16Modifier,
                                  u16          _u16Btn,
                                  const aPoint &_pntLocal,
                                  const aPoint &_pntGlobal)
{
    aToolMgr *pMgr = dynamic_cast<aToolMgr *> (this);

    // 1. let the active tool handle the event
    // 2. not handled by the tool => handle in window class
    return (pMgr != nullptr && pMgr->onToolMgrDoubleClick(_u16Modifier, _u16Btn, _pntLocal, _pntGlobal)) ||
           onDoubleClick(_u16Modifier, _u16Btn, _pntLocal, _pntGlobal);
} // aBaseWin::onDoubleClickEvent


/*******************************************************************************
* aBaseWin::onButtonPressEvent
*******************************************************************************/
bool aBaseWin::onButtonPressEvent(u16          _u16Modifier,
                                  u16          _u16Btn,
                                  const aPoint &_pntLocal,
                                  const aPoint &_pntGlobal)
{
    aToolMgr *pMgr = dynamic_cast<aToolMgr *> (this);

    // 1. let the active tool handle the event
    // 2. not handled by the tool => handle in window class
    return (pMgr != nullptr && pMgr->onToolMgrButtonPress(_u16Modifier, _u16Btn, _pntLocal, _pntGlobal)) ||
           onButtonPress(_u16Modifier, _u16Btn, _pntLocal, _pntGlobal);
} // aBaseWin::onButtonPressEvent


/*******************************************************************************
* aBaseWin::onMouseMoveEvent
*******************************************************************************/
bool aBaseWin::onMouseMoveEvent(u16            _u16Modifier,
                                u16            _u16Btn,
                                const aPoint   &_pntLocal,
                                const aPoint   &_pntGlobal)
{
    aToolMgr *pMgr = dynamic_cast<aToolMgr *> (this);

    // 1. let the active tool handle the event
    // 2. not handled by the tool => handle in window class
    return (pMgr != nullptr && pMgr->onToolMgrMouseMove(_u16Modifier, _u16Btn, _pntLocal, _pntGlobal)) ||
           onMouseMove(_u16Modifier, _u16Btn, _pntLocal, _pntGlobal);
} // aBaseWin::onMouseMoveEvent


/*******************************************************************************
* aBaseWin::onButtonReleaseEvent
*******************************************************************************/
bool aBaseWin::onButtonReleaseEvent(u16            _u16Modifier,
                                    u16            _u16Btn,
                                    const aPoint   &_pntLocal,
                                    const aPoint   &_pntGlobal)
{
    aToolMgr *pMgr = dynamic_cast<aToolMgr *> (this);

    // 1. let the active tool handle the event
    // 2. not handled by the tool => handle in window class
    return (pMgr != nullptr && pMgr->onToolMgrButtonRelease(_u16Modifier, _u16Btn, _pntLocal, _pntGlobal)) ||
           onButtonRelease(_u16Modifier, _u16Btn, _pntLocal, _pntGlobal);
} // aBaseWin::onButtonReleaseEvent


} // namespace aWin
} // namespace aFrame


#endif //_USE_QT_
