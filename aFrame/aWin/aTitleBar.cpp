/*******************************************************************************
* \file aTitleBar.cpp
* \author Andreas Kuhlewind
*
* \brief
*
*  Detailed description starts here.
*******************************************************************************/


/*******************************************************************************
* includes
*******************************************************************************/
#include "aFrame_def.h"
#include "aWin_def.h"

#include "aTitleBar.h"
#include "aParentCtrlTool.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aFrame {
namespace aWin {


/*******************************************************************************
* aTitleBar::aTitleBar
*******************************************************************************/
aTitleBar::aTitleBar(aBaseWin *_pParent /*= nullptr*/)
: aBaseWin(_pParent)
{
} // aTitleBar::aTitleBar


/*******************************************************************************
* aTitleBar::~aTitleBar
*******************************************************************************/
aTitleBar::~aTitleBar()
{
} // aTitleBar::~aTitleBar


/*******************************************************************************
* aTitleBar::onSysCreateWin
*******************************************************************************/
bool aTitleBar::onSysCreateWin()
{
    CHECK_PRE_CONDITION(aBaseWin::onSysCreateWin(), false);

    addTool(make_unique<aParentCtrlTool> (this));

    return true;
} // namespace aFrame


/*******************************************************************************
* aTitleBar::onDoubleClick
*******************************************************************************/
 bool aTitleBar::onDoubleClick(u16              _u16Modifier,
                                u16             _u16Btn,
                                const aPoint    &_pntLocal,
                                const aPoint    &_pntGlobal)
{
     return onToolMgrDoubleClick(_u16Modifier, _u16Btn, _pntLocal, _pntGlobal);
} // aTitleBar::onDoubleClick


 /*******************************************************************************
 * aTitleBar::onButtonPress
 *******************************************************************************/
 bool aTitleBar::onButtonPress(u16          _u16Modifier,
                               u16          _u16Btn,
                               const aPoint &_pntLocal,
                               const aPoint &_pntGlobal)
{
    return onToolMgrButtonPress(_u16Modifier, _u16Btn, _pntLocal, _pntGlobal);
} // aTitleBar::onButtonPress


/*******************************************************************************
* aTitleBar::onMouseMove
*******************************************************************************/
bool aTitleBar::onMouseMove(u16             _u16Modifier,
                            u16             _u16Btn,
                            const aPoint    &_pntLocal,
                            const aPoint    &_pntGlobal)
{
    return onToolMgrMouseMove(_u16Modifier, _u16Btn, _pntLocal, _pntGlobal);
} // aTitleBar::onMouseMove


/*******************************************************************************
* aTitleBar::onButtonRelease
*******************************************************************************/
bool aTitleBar::onButtonRelease(u16             _u16Modifier,
                                u16             _u16Btn,
                                const aPoint    &_pntLocal,
                                const aPoint    &_pntGlobal)
{
    return onToolMgrButtonRelease(_u16Modifier, _u16Btn, _pntLocal, _pntGlobal);
} // aTitleBar::onLDoubleClick


} // namespace aWin
} // namespace aFrame
