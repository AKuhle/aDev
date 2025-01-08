/*******************************************************************************
* \file qParentControlTool.h
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
    * class qParentControlTool
    *******************************************************************************/
    class qParentControlTool : public qToolBase
    {
        private:
            qRect2D<s32>    m_r2dMoveStart;


        public:
            qParentControlTool(qWin  *_pOwnerWin,
                               u32   _u32ToolId              = TOOL_ID_PARENT_CONTROL);

            virtual ~qParentControlTool();


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

            virtual enumToolResult      OnLDoubleClick(u32                     _u32Modifiers,
                                                       const qVector2D<s32>    &_v2dLocal,
                                                       const qVector2D<s32>    &_v2dGlobal) override;

    }; // class qParentControlTool

} // namespace qLib
