/*******************************************************************************
* \file qScrollBarTool.h
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
#pragma once



/*******************************************************************************
* includes
*******************************************************************************/
#include "qToolBase.h"
#include "qVector2D.h"
#include "qRect2D.h"


namespace qLib
{
    /*******************************************************************************
    * forward
    *******************************************************************************/
    class qWin;


    /*******************************************************************************
    * class qScrollBarTool
    *
    * this tool sends the following messages to the owner win (=tool mgr):
    *   MSG_PAGE_UP: if a user clicked "page up"
    *   MSG_PAGE_DOWN: if a user clicked "page down"
    *
    *******************************************************************************/
    class qScrollBarTool : public qToolBase
    {
        private:
            qRect2D<s32>    m_r2dMoveStart;

            // move member
            bool            m_bSliding              { false };
            s32             m_s32SliderStartPos     { 0 };

        public:
            qScrollBarTool(qWin  *_pOwnerWin,
                           u32   _u32ToolId = TOOL_ID_SCROLL_BAR);

            virtual ~qScrollBarTool();


        /*******************************************************************************
        * qToolBase interface
        *******************************************************************************/
        protected:
            virtual enumToolResult      OnLMousePress(u32                     _u32Modifiers,
                                                      const qVector2D<s32>    &_v2dLocal,
                                                      const qVector2D<s32>    &_v2dGlobal) override;

            virtual enumToolResult      OnLMouseMove(u32                     _u32Modifiers,
                                                     const qVector2D<s32>    &_v2dLocal,
                                                     const qVector2D<s32>    &_v2dGlobal) override;

            virtual enumToolResult      OnLMouseRelease(u32                     _u32Modifiers,
                                                        const qVector2D<s32>    &_v2dLocal,
                                                        const qVector2D<s32>    &_v2dGlobal) override;



    }; // class qScrollBarTool

} // namespace qLib
