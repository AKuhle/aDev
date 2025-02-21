/*******************************************************************************
* \file aButtonTool.h
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
#include "aWin/aWin_def.h"

#include "aWin/Tool/aToolBase.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aWin {


/*******************************************************************************
* class aButtonTool
*******************************************************************************/
class aButtonTool : public aToolBase
{
    private:
        bool            m_bSelectedBefore;

    public:
        aButtonTool(aBaseWin    *_pOwnerWin,
                    u32         _u32ToolId    = TOOL_ID_BUTTON);

        virtual ~aButtonTool();


    private:
        bool                        isMouseOnButton(const aVector2D<s32>    &_v2dLocal) const;


    /*******************************************************************************
    * qToolBase interface
    *******************************************************************************/
    protected:
        virtual enumToolResult      onEnter(u32                   _u32Modifiers,
                                            const aVector2D<s32>  &_v2dLocal,
                                            const aVector2D<s32>  &_v2dGlobal) override;

        virtual enumToolResult      onLeave(u32 _u32Modifiers) override;

        virtual enumToolResult      onLDoubleClick(u32                     _u32Modifiers,
                                                   const aVector2D<s32>    &_v2dLocal,
                                                   const aVector2D<s32>    &_v2dGlobal) override;

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

        virtual enumToolResult      onLMouseRelease(u32                     _u32Modifiers,
                                                    const aVector2D<s32>    &_v2dLocal,
                                                    const aVector2D<s32>    &_v2dGlobal) override;

}; // class aButtonTool


} // namespace aWin
} // namespace aLib
