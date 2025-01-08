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
#include "Tool/qToolBase.h"
#include "Math/qRect2D.h"


namespace qLib {
namespace Tool {


/*******************************************************************************
* class qParentControlTool
*******************************************************************************/
class qParentControlTool : public qToolBase
{
    private:
        qRect2D<s32>    m_r2dMoveStart;


    public:
        qParentControlTool(qWin  *_pOwnerWin,
                           u32   _u32ToolId     = TOOL_ID_PARENT_CONTROL);

        virtual ~qParentControlTool();


    /*******************************************************************************
    * qToolBase interface
    *******************************************************************************/
    protected:
        virtual enumToolResult      onLDoubleClick(u32                     _u32Modifiers,
                                              const qVector2D<s32>    &_v2dLocal,
                                              const qVector2D<s32>    &_v2dGlobal) override;

        virtual enumToolResult      onLMousePress(u32                     _u32Modifiers,
                                                  const qVector2D<s32>    &_v2dLocal,
                                                  const qVector2D<s32>    &_v2dGlobal) override;

        virtual enumToolResult      onLMouseMove(u32                     _u32Modifiers,
                                                 const qVector2D<s32>    &_v2dLocal,
                                                 const qVector2D<s32>    &_v2dGlobal) override;

}; // class qParentControlTool


} // namespace Tool
} // namespace qLib
