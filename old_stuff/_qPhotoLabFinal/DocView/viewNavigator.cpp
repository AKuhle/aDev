/*******************************************************************************
* \file ViewNavigator.cpp
* \author Andreas Kuhlewind
*
* \brief
*
*  Detailed description starts here.
*******************************************************************************/


/*******************************************************************************
* includes
*******************************************************************************/
#include "mainWin.h"
#include "viewNavigator.h"
#include "toolNavigator.h"

using namespace std;



/*******************************************************************************
* ViewNavigator::ViewNavigator
*******************************************************************************/
ViewNavigator::ViewNavigator(SysWin_t *_pParent)
: ViewBase(_pParent, nullptr)
{
} // ViewNavigator::ViewNavigator


/*******************************************************************************
* ViewNavigator::~ViewNavigator
*******************************************************************************/
ViewNavigator::~ViewNavigator()
{
} // ViewNavigator::~ViewNavigator


/*******************************************************************************
* ViewNavigator::OnCreate
*******************************************************************************/
bool ViewNavigator::OnCreate()
{
    unique_ptr<qTool> pTool = make_unique<ToolNavigator> (this);

    SetTool(std::move (pTool));

    return true;
} // ViewNavigator::OnCreate


/*******************************************************************************
* ViewNavigator::UpdateRenderParams
*******************************************************************************/
void ViewNavigator::UpdateRenderParams(RenderParams &_rp)
{
    shared_ptr<qLayerStack> pLS         = GetActiveOrTopmostLS();
    qRect2D<s32>            r2dClient   = ClientRect();
    qRect2D<s32>            r2dVp;

    // 1. set the layerstack
    _rp.SetLayerStack(pLS);

    if (pLS != nullptr && pLS->IsValid())
    {
        // 2. set the zoomfactor
        dbl dZfW = ((dbl) r2dClient.w()) / pLS->w();
        dbl dZfH = ((dbl) r2dClient.h()) / pLS->h();
        _rp.SetZoomFactor(Min<dbl> (dZfW, dZfH));

        // 3. set the viewport
        r2dVp.Set(Max(0, (r2dClient.w() - _rp.ZoomedW()) / 2),
                  Max(0, (r2dClient.h() - _rp.ZoomedH()) / 2),
                  _rp.ZoomedW(),
                  _rp.ZoomedH());

        _rp.SetVp_client(r2dVp);

        // 4. set the origin in the image
        _rp.SetOrigin_zoom(0, 0);
    }

} // ViewNavigator::UpdateRenderParams


/*******************************************************************************
* ViewNavigator::SetCenterPointInZoom
*******************************************************************************/
void ViewNavigator::SetCenterPointInZoom(qVector2D<s32> /*_v2dCenter_zoom*/)
{
    // does nothing, because the full image is always visible
} // ViewNavigator::SetCenterPointInZoom


/*******************************************************************************
* ViewNavigator::OnPaintBg
*******************************************************************************/
void ViewNavigator::OnPaintBg()
{
    qPainter                p(this);
    qBrush                  brushBg(rgbaBlack);
    qRect2D<s32>            r2dClient   = ClientRect();
    shared_ptr<qLayerStack> pLS         = GetActiveOrTopmostLS();

    p.DrawFilledRect(r2dClient, &brushBg);

    // draw a red cross if no active document
    if (pLS == nullptr)
    {
        qPen    penCross(rgbaRebeccaPurple);

        p.DrawLine(r2dClient.lt(), r2dClient.rb(), &penCross);
        p.DrawLine(r2dClient.rt(), r2dClient.lb());
    }

} // ViewNavigator::OnPaintBg


/*******************************************************************************
* ViewNavigator::OnPaintMarker
*******************************************************************************/
void ViewNavigator::OnPaintMarker(const RenderParams &_rp)
{
    ViewBase::OnPaintMarker(_rp);

    const RenderParams  *rpActive = GetActiveOrTopmostRenderParams();
    CHECK_PRE_CONDITION_VOID(rpActive != nullptr);

    // draw a red cross if no active document
    qPainter            p(this);
    qPen                penVisibleArea(rgbaRed);
    qRect2D<s32>        vp_pic      = rpActive->VpRect_pic();
    qRect2D<s32>        vp_client   = Pic2Client(vp_pic);

    p.DrawRect(vp_client, &penVisibleArea);

} // ViewNavigator::OnPaintMarker
