/*******************************************************************************
* \file ViewStd.cpp
* \author Andreas Kuhlewind
*
* \brief
*
*  Detailed description starts here.
*******************************************************************************/


/*******************************************************************************
* includes
*******************************************************************************/
#include "viewStd.h"
#include "stdScrollWin.h"

using namespace std;



/*******************************************************************************
* ViewStd::ViewStd
*******************************************************************************/
ViewStd::ViewStd(SysWin_t           *_pParent,
                 shared_ptr<DocPl>  _pDoc)
: ViewBase(_pParent, _pDoc)
{
} // ViewStd::ViewStd


/*******************************************************************************
* ViewStd::~ViewStd
*******************************************************************************/
ViewStd::~ViewStd()
{
} // ViewStd::~ViewStd


/*******************************************************************************
* ViewStd::UpdateRenderParams
*******************************************************************************/
void ViewStd::UpdateRenderParams(RenderParams &_rp)
{
    shared_ptr<qLayerStack> pLS         = LayerStack();

    // 1. set the layerstack
    _rp.SetLayerStack(pLS);

    if (pLS != nullptr && pLS->IsValid())
    {
        // a ViewStd has always a StdScrollWin as a parent
        StdScrollWin *pScrollWin = dynamic_cast<StdScrollWin *> (Parent());
        CHECK_PRE_CONDITION_VOID(pScrollWin != nullptr);

        qRect2D<s32>        r2dClient       = ClientRect();
        s32                 s32HoriSbPos    = pScrollWin->HoriSbPos();
        s32                 s32VertSbPos    = pScrollWin->VertSbPos();
        dbl                 dZF             = ZoomFactor();
        qDimension2D<s32>   d2dPic_zoom     = PicSize_zoom();
        qRect2D<s32>        r2dVp;
        qRect2D<s32>        r2dPic_zoom(-s32HoriSbPos, -s32VertSbPos,
                                        d2dPic_zoom.w(), d2dPic_zoom.h());

        // calculate the area which needs to be calculated
        r2dVp = r2dPic_zoom.Intersect(r2dClient);

        // 2. set the zoomfactor
        _rp.SetZoomFactor(dZF);

        // 3. set the viewport
        _rp.SetVp_client(r2dVp);

        // 4. set the origin in the image
        _rp.SetOrigin_zoom(Max(0, s32HoriSbPos),
                           Max(0, s32VertSbPos));
    }

} // ViewStd::UpdateRenderParams


/*******************************************************************************
* ViewStd::SetCenterPointInZoom
*******************************************************************************/
void ViewStd::SetCenterPointInZoom(qVector2D<s32> _v2dCenter_zoom)
{
    shared_ptr<qLayerStack> pLS         = LayerStack();

    if (pLS != nullptr && pLS->IsValid())
    {
        // a ViewStd has always a StdScrollWin as a parent
        StdScrollWin *pScrollWin = dynamic_cast<StdScrollWin *> (Parent());
        CHECK_PRE_CONDITION_VOID(pScrollWin != nullptr);

        qRect2D<s32> r2dClient = ClientRect();

        pScrollWin->SetHoriSbPos(_v2dCenter_zoom.x() - r2dClient.w() / 2);
        pScrollWin->SetVertSbPos(_v2dCenter_zoom.y() - r2dClient.h() / 2);
    }

} // ViewStd::SetCenterPointInZoom
