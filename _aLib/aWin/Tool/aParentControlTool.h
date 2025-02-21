/*******************************************************************************
* \file aParentControlTool.h
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
#include "aMath/aMath_def.h"

#include "aMath/Obj2D/aRect2D.h"

#include "aWin/Tool/aToolBase.h"

using namespace aLib::aMath;


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aWin {


/*******************************************************************************
* class aParentControlTool
*******************************************************************************/
class aParentControlTool : public aToolBase
{
    private:
        aRect2D<s32>    m_r2dMoveStart;


    public:
        aParentControlTool(aBaseWin *_pOwnerWin,
                           u32      _u32ToolId     = TOOL_ID_PARENT_CONTROL);

        virtual ~aParentControlTool();


    /*******************************************************************************
    * qToolBase interface
    *******************************************************************************/
    protected:
        virtual enumToolResult      onLDoubleClick(u32                     _u32Modifiers,
                                                   const aVector2D<s32>    &_v2dLocal,
                                                   const aVector2D<s32>    &_v2dGlobal) override;

        virtual enumToolResult      onLMousePress(u32                     _u32Modifiers,
                                                  const aVector2D<s32>    &_v2dLocal,
                                                  const aVector2D<s32>    &_v2dGlobal) override;

        virtual enumToolResult      onLMouseMove(u32                     _u32Modifiers,
                                                 const aVector2D<s32>    &_v2dLocal,
                                                 const aVector2D<s32>    &_v2dGlobal) override;

}; // class aParentControlTool


} // namespace aWin
} // namespace aLib
