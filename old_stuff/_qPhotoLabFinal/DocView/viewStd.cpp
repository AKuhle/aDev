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
#include "scrollWin.h"

using namespace std;



/*******************************************************************************
* ViewStd::ViewStd
*******************************************************************************/
ViewStd::ViewStd(qWin               *_pParent,
                 shared_ptr<Doc>    _pDoc)
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
* ViewStd::UpdateScrollbars
*******************************************************************************/
void ViewStd::UpdateScrollbars()
{
    // parent must be a ScrollWin
    ScrollWin *pScrollWin = dynamic_cast<ScrollWin *> (GetParent());
    CHECK_PRE_CONDITION_VOID(pScrollWin != nullptr);

    qRect2D<s32>        r2dContent  = GetContentRect();
    qDimension2D<s32>   dim_zoom    = GetPicSize_zoom();

    //qLog::Log(enumCoutColor::cyan, "hori range: ", 0, " - ", dim_zoom.w);
    //qLog::Log(enumCoutColor::cyan, "hori page: ", r2dContent.w);

    pScrollWin->SetHoriRange(0, dim_zoom.w);
    pScrollWin->SetHoriPageStep(r2dContent.w);

    pScrollWin->SetVertRange(0, dim_zoom.h);
    pScrollWin->SetVertPageStep(r2dContent.h);
} // ViewStd::UpdateScrollbars


/*******************************************************************************
* ViewStd::UpdateRenderParams
*******************************************************************************/
void ViewStd::UpdateRenderParams(RenderParams &_rp)
{
    // parent must be a ScrollWin
    ScrollWin *pScrollWin = dynamic_cast<ScrollWin *> (GetParent());
    CHECK_PRE_CONDITION_VOID(pScrollWin != nullptr);

    shared_ptr<qLayerStack> pLS         = GetLayerStack();

    //qLog::Log(enumCoutColor::cyan, "hori: ", pScrollWin->GetHoriValue(), ", vert: ", pScrollWin->GetVertValue());

    // 1. set the layerstack
    _rp.SetLayerStack(pLS);

    if (pLS != nullptr && pLS->IsValid())
    {
        qRect2D<s32>        r2dContent      = GetContentRect();
        s32                 s32HoriSbPos    = pScrollWin->GetHoriValue();
        s32                 s32VertSbPos    = pScrollWin->GetVertValue();
        dbl                 dZF             = GetZoomFactor();
        qDimension2D<s32>   d2dPic_zoom     = GetPicSize_zoom();
        qRect2D<s32>        r2dVp;
        qRect2D<s32>        r2dPic_zoom(-s32HoriSbPos, -s32VertSbPos,
                                        d2dPic_zoom.w, d2dPic_zoom.h);

        // calculate the area which needs to be calculated
        r2dVp = r2dPic_zoom.Intersect(r2dContent);

        // 2. set the zoomfactor
        _rp.SetZoomFactor(dZF);

        // 3. set the viewport
        _rp.SetVp_client(r2dVp);

        // 4. set the origin in the image
        _rp.SetOrigin_zoom(MU<s32>::Max(0, s32HoriSbPos + r2dVp.x),
                           MU<s32>::Max(0, s32VertSbPos + r2dVp.y));
    }

} // ViewStd::UpdateRenderParams


/*******************************************************************************
* ViewStd::SetCenterPointInZoom
*******************************************************************************/
// void ViewStd::SetCenterPointInZoom(qVector2D<s32> _v2dCenter_zoom)
// {
//     shared_ptr<qLayerStack> pLS         = LayerStack();

//     if (pLS != nullptr && pLS->IsValid())
//     {
//         // a ViewStd has always a StdScrollWin as a parent
//         StdScrollWin *pScrollWin = dynamic_cast<StdScrollWin *> (Parent());
//         CHECK_PRE_CONDITION_VOID(pScrollWin != nullptr);

//         qRect2D<s32> r2dClient = ClientRect();

//         pScrollWin->SetHoriSbPos(_v2dCenter_zoom.x() - r2dClient.w() / 2);
//         pScrollWin->SetVertSbPos(_v2dCenter_zoom.y() - r2dClient.h() / 2);
//     }

// } // ViewStd::SetCenterPointInZoom
