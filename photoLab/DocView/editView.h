/*******************************************************************************
* \file EditView.h
* \author Andreas Kuhlewind
*
* \brief
*
*  Detailed description starts here.
*******************************************************************************/
#pragma once



/*******************************************************************************
* includes
*******************************************************************************/
#include "viewBase.h"


/*******************************************************************************
* forwards
*******************************************************************************/


/*******************************************************************************
* class EditView
*******************************************************************************/
class EditView : public ViewBase
{
    public:
        EditView(SysWin                     *_pParent,
                 std::shared_ptr<Document>  _pDoc);

        virtual ~EditView();


    /*******************************************************************************
    * ViewBase interface
    *******************************************************************************/
    protected:
        void            updateRenderParams(RenderParams &_rp) override;

        void            updateScrollBars() override;
        void            setCenterPointInZoom(aPoint2D<s32> _v2dCenter_zoom) override;


    /*******************************************************************************
    * aBaseWin interface
    *******************************************************************************/
    protected:
        bool            onCreateWin() override;

        // bool            onLeave(u32 _u32Modifiers) override;

        // bool            onMouseMove(u32                     _u32Modifiers,
        //                             u32                     _u32MouseButton,
        //                             const aPoint2D<s32>    &_v2dLocal,
        //                             const aPoint2D<s32>    &_v2dGlobal) override;


}; // class EditView
