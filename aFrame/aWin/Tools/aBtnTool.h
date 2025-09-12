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
* class aBtnTool
*******************************************************************************/
class aBtnTool : public aToolBase
{
    private:
        bool    m_bMouseOver    { false };  // true => mouse over btn
        bool    m_bMousePressed { false };  // true => mouse pressed


    /*******************************************************************************
    * con-/destruction
    *******************************************************************************/
    public:
        aBtnTool(aBaseWin  *_pOwner,
                 u32       _u32ToolId    = TOOL_ID_BUTTON,
                 u32       _u32Flags     = TF_NONE);

        ~aBtnTool();

        aColor              stateColor() const;


    private:
        bool                isOnBtn(const aPoint &_pntLocal) const;


    /*******************************************************************************
    * aToolBase implementation
    *******************************************************************************/
    protected:
        // enter / leave events
        enumToolResult      onEnter(u16             _u16Modifier,
                                    const aPoint    &_pntLocal,
                                    const aPoint    &_pntGlobal) override;

        enumToolResult      onLeave(u16 _u16Modifier) override;


        // mouse events
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
}; // class aBtnTool


} // namespace aWin
} // namespace aFrame


#endif //_USE_QT_
