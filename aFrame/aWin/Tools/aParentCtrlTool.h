/*******************************************************************************
* \file qWin.h
* \author Andreas Kuhlewind
*
* \brief
*
*  Detailed description starts here.
*******************************************************************************/
#pragma once

#ifdef _USE_QT_


/*******************************************************************************
* includes
*******************************************************************************/
#include "aFrame_def.h"
#include "aUtil_def.h"
#include "aWin_def.h"

#include "aToolBase.h"
#include "aRect.h"

using namespace aFrame;
using namespace aFrame::aUtil;
using namespace aFrame::aWin;


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aFrame {
namespace aWin {


/*******************************************************************************
* class aParentCtrlTool
*******************************************************************************/
class aParentCtrlTool : public aToolBase
{
    private:
        aRect   m_rctMoveStartRect;

    /*******************************************************************************
    * con-/destruction
    *******************************************************************************/
    public:
        aParentCtrlTool(aBaseWin   *_pOwner,
                        u32        _u32ToolId     = TOOL_ID_PARENT_CTRL,
                        u32        _u32Flags       = TF_NONE);

        ~aParentCtrlTool();

    protected:
        enumToolResult      onLDoubleClick(u16          _u16Modifier,
                                           const aPoint &_pntLocal,
                                           const aPoint &_pntGlobal) override;

        enumToolResult      onLButtonPress(u16          _u16Modifier,
                                           const aPoint &_pntLocal,
                                           const aPoint &_pntGlobal) override;

        enumToolResult      onLMouseMove(u16          _u16Modifier,
                                         const aPoint &_pntLocal,
                                         const aPoint &_pntGlobal) override;

        enumToolResult      onLButtonRelease(u16          _u16Modifier,
                                             const aPoint &_pntLocal,
                                             const aPoint &_pntGlobal) override;

}; // class aParentCtrlTool


} // namespace aWin
} // namespace aFrame


#endif //_USE_QT_
