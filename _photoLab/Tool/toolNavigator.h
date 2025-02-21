/*******************************************************************************
* \file ToolNavigator.h
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
#include "toolBase.h"


/*******************************************************************************
* class ToolNavigator
*******************************************************************************/
class ToolNavigator : public ToolBase
{
    public:
        ToolNavigator(ViewBase   *_pOwnerView);
        virtual ~ToolNavigator();


    /*******************************************************************************
    * qTool interface
    *******************************************************************************/
    protected:
        virtual enumToolResult      OnLDoubleClick(u32                  _u32Modifiers,
                                                   const qVector2D<s32> &_v2dLocal,
                                                   const qVector2D<s32> &_v2dGlobal);

        virtual enumToolResult      OnLMousePress(u32                   _u32Modifiers,
                                                  const qVector2D<s32>  &_v2dLocal,
                                                  const qVector2D<s32>  &_v2dGlobal);

        virtual enumToolResult      OnLMouseMove(u32                    _u32Modifiers,
                                                 const qVector2D<s32>   &_v2dLocal,
                                                 const qVector2D<s32>   &_v2dGlobal);

        virtual enumToolResult      OnLMouseRelease(u32                     _u32Modifiers,
                                                    const qVector2D<s32>    &_v2dLocal,
                                                    const qVector2D<s32>    &_v2dGlobal);

        virtual void                OnXorRect(const qRect2D<s32>    &_r2dXor);

}; // class ToolNavigator
