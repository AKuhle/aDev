/*******************************************************************************
* \file FullView.cpp
* \author Andreas Kuhlewind
*
* \brief
*
*  Detailed description starts here.
*******************************************************************************/


/*******************************************************************************
* includes
*******************************************************************************/
#include "aHelper.h"
#include "fullView.h"
#include "mainWin.h"
#include "aPainter.h"
#include "aColor.h"

using namespace std;



/*******************************************************************************
* FullView::FullView
*******************************************************************************/
FullView::FullView(SysWin *_pParent)
: ViewBase(_pParent, nullptr)
{
} // FullView::FullView


/*******************************************************************************
* FullView::~FullView
*******************************************************************************/
FullView::~FullView()
{
} // FullView::~FullView


/*******************************************************************************
* FullView::onCreateWin
*******************************************************************************/
bool FullView::onCreateWin()
{
    // unique_ptr<qTool> pTool = make_unique<ToolNavigator> (this);

    // SetTool(std::move (pTool));

    return true;
} // FullView::onCreateWin


/*******************************************************************************
* FullView::updateScrollBars
*******************************************************************************/
void FullView::updateScrollBars()
{
    // does nothing, because the full image is always visible and centered
} // FullView::updateScrollBars


/*******************************************************************************
* FullView::setCenterPointInZoom
*******************************************************************************/
void FullView::setCenterPointInZoom(aVector2D<s32> /*_v2dCenter_zoom*/)
{
    // does nothing, because the full image is always visible and centered
} // FullView::setCenterPointInZoom


/*******************************************************************************
* FullView::updateRenderParams
*******************************************************************************/
void FullView::updateRenderParams(RenderParams &_rp)
{
    shared_ptr<SynchronizedLS>  pSync       = getTopmostLS();

    // 1. set the layerstack
    _rp.setLayerStack(pSync);

    // get the syncronized layerstack
    if (pSync != nullptr)
    {
        SharedLS pShared(*pSync);
        shared_ptr<LayerStack>  pLS = pShared.get();

        if (pLS->isValid())
        {
            aRect2D<s32>                r2dClient   = clientRect();
            aRect2D<s32>                r2dVp;

            // 2. set the zoomfactor
            dbl dZfW = ((dbl) r2dClient.w()) / pLS->w();
            dbl dZfH = ((dbl) r2dClient.h()) / pLS->h();
            _rp.setZoomFactor(aUtil::min<dbl> (dZfW, dZfH));

            // 3. set the viewport
            r2dVp.set(aUtil::max(0, (r2dClient.w() - _rp.w_zoom()) / 2),
                      aUtil::max(0, (r2dClient.h() - _rp.h_zoom()) / 2),
                      _rp.w_zoom(),
                      _rp.h_zoom());

            _rp.setVp_client(r2dVp);

            // 4. set the origin in the image
            _rp.setOrigin_zoom(0, 0);
        }
    }
} // FullView::updateRenderParams


/*******************************************************************************
* FullView::doPaintBackground
*******************************************************************************/
void FullView::doPaintBackground(aPainter &_painter)
{
    aRect2D<s32>                r2dClient   = clientRect();

    _painter.drawFilledRect(r2dClient, &colBlack);
} // FullView::doPaintBackground
