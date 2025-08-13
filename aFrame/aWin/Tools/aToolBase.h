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

#include "aPoint.h"

using namespace aFrame;
using namespace aFrame::aUtil;
using namespace aFrame::aWin;


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aFrame {
namespace aWin {


/*******************************************************************************
* class aToolBase
*******************************************************************************/
class aToolBase
{
    friend class aToolMgr;

    private:
        aBaseWin   *m_pOwner        { nullptr };
        u32        m_u32ToolId      { 0 };
        u32        m_u32Flags       { TF_NONE };

        // member for position tracking
        u16        m_u16Btn         { MOUSE_BTN_NONE };
        aPoint     m_pntStartLocal;     // local move startpoint
        aPoint     m_pntStartGlobal;    // global move startpoint
        aPoint     m_pntDelta;          // move delta


    /*******************************************************************************
    * con-/destruction
    *******************************************************************************/
    protected:
        aToolBase(aBaseWin   *_pOwner,
                  u32        _u32ToolId,
                  u32        _u32Flags       = TF_NONE);

        const aPoint&   startLocal() const     { return m_pntStartLocal; }
        const aPoint&   startGlobal() const    { return m_pntStartGlobal; }
        const aPoint&   delta() const          { return m_pntDelta; }


    public:
        ~aToolBase();

        u32             toolId() const          { return m_u32ToolId; }
        aBaseWin*       ownerWin() const        { return m_pOwner; }
        aBaseWin*       ownerParent() const;


    protected:
        // double click events
        virtual enumToolResult  onLDoubleClick(u16          _u16Modifier,
                                               const aPoint &_pntLocal,
                                               const aPoint &_pntGlobal);

        virtual enumToolResult  onMDoubleClick(u16          _u16Modifier,
                                               const aPoint &_pntLocal,
                                               const aPoint &_pntGlobal);

        virtual enumToolResult  onRDoubleClick(u16          _u16Modifier,
                                               const aPoint &_pntLocal,
                                               const aPoint &_pntGlobal);


        // mouse pressed events
        virtual enumToolResult  onLButtonPress(u16          _u16Modifier,
                                               const aPoint &_pntLocal,
                                               const aPoint &_pntGlobal);

        virtual enumToolResult  onMButtonPress(u16          _u16Modifier,
                                               const aPoint &_pntLocal,
                                               const aPoint &_pntGlobal);

        virtual enumToolResult  onRButtonPress(u16          _u16Modifier,
                                               const aPoint &_pntLocal,
                                               const aPoint &_pntGlobal);


        // mouse move events
        // separate handler for moves without/multiple buttons
        virtual enumToolResult  onLMouseMove(u16          _u16Modifier,
                                             const aPoint &_pntLocal,
                                             const aPoint &_pntGlobal);

        virtual enumToolResult  onMMouseMove(u16          _u16Modifier,
                                             const aPoint &_pntLocal,
                                             const aPoint &_pntGlobal);

        virtual enumToolResult  onRMouseMove(u16          _u16Modifier,
                                             const aPoint &_pntLocal,
                                             const aPoint &_pntGlobal);

        // only called, if mouseTracking is enabled
        virtual enumToolResult  onMouseMove(u16          _u16Modifier,
                                            const aPoint &_pntLocal,
                                            const aPoint &_pntGlobal);


        // mouse release events
        virtual enumToolResult  onLButtonRelease(u16          _u16Modifier,
                                                 const aPoint &_pntLocal,
                                                 const aPoint &_pntGlobal);

        virtual enumToolResult  onMButtonRelease(u16          _u16Modifier,
                                                 const aPoint &_pntLocal,
                                                 const aPoint &_pntGlobal);

        virtual enumToolResult  onRButtonRelease(u16          _u16Modifier,
                                                 const aPoint &_pntLocal,
                                                 const aPoint &_pntGlobal);


    private:
        // double click events
        virtual enumToolResult  onToolDoubleClick(u16           _u16Modifier,
                                                  u16           _u16Btn,
                                                  const aPoint  &_pntLocal,
                                                  const aPoint  &_pntGlobal);

        // mouse pressed events
        virtual enumToolResult  onToolButtonPress(u16           _u16Modifier,
                                                  u16           _u16Btn,
                                                  const aPoint  &_pntLocal,
                                                  const aPoint  &_pntGlobal);

        // mouse move events
        virtual enumToolResult  onToolMouseMove(u16             _u16Modifier,
                                                u16             _u16Btn,
                                                const aPoint    &_pntLocal,
                                                const aPoint    &_pntGlobal);

        // mouse release events
        virtual enumToolResult  onToolButtonRelease(u16          _u16Modifier,
                                                    u16           _u16Btn,
                                                    const aPoint &_pntLocal,
                                                    const aPoint &_pntGlobal);

}; // class aToolBase


} // namespace aWin
} // namespace aFrame


#endif //_USE_QT_
