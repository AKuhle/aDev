/*******************************************************************************
* \file qBorderResizeTool.h
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
    * class qBorderResizeTool
    *******************************************************************************/
    class qBorderResizeTool : public qToolBase
    {
        private:
            qRect2D<s32>    m_r2dResizeStart;
            enumPosition    m_eResizePos        { enumPosition::None };
            enumPosition    m_eLastPos          { enumPosition::None };


        public:
            qBorderResizeTool(qWin  *_pOwnerWin,
                               u32   _u32ToolId              = TOOL_ID_BORDER_RESIZE,
                               u64   _u64ToolBaseFunction    = TBF_NONE);

            virtual ~qBorderResizeTool();


        private:
            enumPosition                Position(const qVector2D<s32>    &_v2dLocal) const;


        /*******************************************************************************
        * qToolBase interface
        *******************************************************************************/
        protected:
            virtual enumToolResult      OnLeave(u32 _u32Modifiers) override;

            virtual enumToolResult      OnMouseMove(u32                     _u32Modifiers,
                                                    u32                     _u32MouseButton,
                                                    const qVector2D<s32>    &_v2dLocal,
                                                    const qVector2D<s32>    &_v2dGlobal) override;

            virtual enumToolResult      OnLMousePress(u32                     _u32Modifiers,
                                                      const qVector2D<s32>    &_v2dLocal,
                                                      const qVector2D<s32>    &_v2dGlobal) override;

            virtual enumToolResult      OnLMouseMove(u32                     _u32Modifiers,
                                                     const qVector2D<s32>    &_v2dLocal,
                                                     const qVector2D<s32>    &_v2dGlobal) override;

    }; // class qBorderResizeTool

} // namespace qLib
