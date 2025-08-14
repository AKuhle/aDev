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
* class aBorderResizeTool
*******************************************************************************/
class aBorderResizeTool : public aToolBase
{
    private:
        aRect           m_rctOri;       // original window size before resizing
        enumPosition    m_eDirection;   // resize direction

    /*******************************************************************************
    * con-/destruction
    *******************************************************************************/
    public:
        aBorderResizeTool(aBaseWin  *_pOwner,
                          u32       _u32ToolId     = TOOL_ID_BORDER_RESIZE,
                          u32       _u32Flags       = TF_NONE);

        ~aBorderResizeTool();

    private:
        enumPosition        findPos(const aPoint &_pntLocal) const;


    /*******************************************************************************
    * aToolBase implementation
    *******************************************************************************/
    protected:
        enumToolResult      onMouseMove(u16          _u16Modifier,
                                        const aPoint &_pntLocal,
                                        const aPoint &_pntGlobal);

        enumToolResult      onLButtonPress(u16          _u16Modifier,
                                           const aPoint &_pntLocal,
                                           const aPoint &_pntGlobal) override;

        enumToolResult      onLMouseMove(u16          _u16Modifier,
                                         const aPoint &_pntLocal,
                                         const aPoint &_pntGlobal) override;

        enumToolResult      onLButtonRelease(u16          _u16Modifier,
                                             const aPoint &_pntLocal,
                                             const aPoint &_pntGlobal) override;
}; // class aBorderResizeTool


} // namespace aWin
} // namespace aFrame


#endif //_USE_QT_
