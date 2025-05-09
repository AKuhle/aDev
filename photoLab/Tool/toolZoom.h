/*******************************************************************************
* \file ToolZoom.h
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
* class ToolZoom
*******************************************************************************/
class ToolZoom : public ToolBase
{
    public:
        ToolZoom(ViewBase   *_pOwnerView);
        virtual ~ToolZoom();


    /*******************************************************************************
    * qTool interface
    *******************************************************************************/
    protected:
        enumToolResult          OnContextMenu(u32                  _u32Modifiers,
                                     const qVector2D<s32> &_v2dLocal,
                                     const qVector2D<s32> &_v2dGlobal) override;
}; // class ToolZoom
