/*******************************************************************************
* \file aBorderResizeTool.h
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
#include "aLib_def.h"
#include "aWin/aWin_def.h"

#include "aMath/Obj2D/aRect2D.h"

#include "aWin/Tool/aToolBase.h"

using namespace aLib::aMath;


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aWin {


/*******************************************************************************
* class aBorderResizeTool
*******************************************************************************/
class aBorderResizeTool : public aToolBase
{
    private:
        aRect2D<s32>    m_r2dResizeStart;
        enumPosition    m_eResizePos        { enumPosition::None };
        enumPosition    m_eLastPos          { enumPosition::None };


    public:
        aBorderResizeTool(aBaseWin  *_pOwnerWin,
                          u32       _u32ToolId              = TOOL_ID_BORDER_RESIZE,
                          u64       _u64ToolBaseFunction    = TBF_NONE);

        virtual ~aBorderResizeTool();


    private:
        enumPosition                position(const aVector2D<s32>    &_v2dLocal) const;


    /*******************************************************************************
    * qToolBase interface
    *******************************************************************************/
    protected:
        virtual void                setCursor(u32                   _u32Modifiers,
                                              const aVector2D<s32>  &_v2dLocal,
                                              const aVector2D<s32>  &_v2dGlobal);

        virtual enumToolResult      onLeave(u32 _u32Modifiers) override;

        virtual enumToolResult      onMouseMove(u32                     _u32Modifiers,
                                                u32                     _u32MouseButton,
                                                const aVector2D<s32>    &_v2dLocal,
                                                const aVector2D<s32>    &_v2dGlobal) override;

        virtual enumToolResult      onLMousePress(u32                     _u32Modifiers,
                                                  const aVector2D<s32>    &_v2dLocal,
                                                  const aVector2D<s32>    &_v2dGlobal) override;

        virtual enumToolResult      onLMouseMove(u32                     _u32Modifiers,
                                                 const aVector2D<s32>    &_v2dLocal,
                                                 const aVector2D<s32>    &_v2dGlobal) override;

}; // class aBorderResizeTool


} // namespace aWin
} // namespace aLib
