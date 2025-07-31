/*******************************************************************************
* \file FullView.h
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
* class FullView
*******************************************************************************/
class FullView : public ViewBase
{
    public:
        FullView(SysWin *_pParent);

        virtual ~FullView();


    /*******************************************************************************
    * ViewBase interface
    *******************************************************************************/
    protected:
        void                updateRenderParams(RenderParams &_rp) override;
        void                doPaintBackground(aPainter &_painter) override;

        void                setCenterPointInZoom(aPoint2D<s32> _v2dCenter_zoom) override;
        void                updateScrollBars() override;


    /*******************************************************************************
    * qSysWin interface
    *******************************************************************************/
    protected:
        bool                onCreateWin() override;

}; // class FullView
