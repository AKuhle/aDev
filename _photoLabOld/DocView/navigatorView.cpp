/*******************************************************************************
* \file NavigatorView.cpp
* \author Andreas Kuhlewind
*
* \brief
*
*  Detailed description starts here.
*******************************************************************************/


/*******************************************************************************
* includes
*******************************************************************************/
#include "navigatorView.h"

using namespace std;



/*******************************************************************************
* NavigatorView::NavigatorView
*******************************************************************************/
NavigatorView::NavigatorView(SysWin *_pParent)
: FullView(_pParent)
{
} // NavigatorView::NavigatorView


/*******************************************************************************
* NavigatorView::~NavigatorView
*******************************************************************************/
NavigatorView::~NavigatorView()
{
} // NavigatorView::~NavigatorView


/*******************************************************************************
* NavigatorView::onCreateWin
*******************************************************************************/
bool NavigatorView::onCreateWin()
{
    // unique_ptr<qTool> pTool = make_unique<ToolNavigator> (this);

    // SetTool(std::move (pTool));

    return true;
} // NavigatorView::onCreateWin


/*******************************************************************************
* NavigatorView::doPaintMarker
*******************************************************************************/
void NavigatorView::doPaintMarker(aPainter &/*_painter*/)
{
    //     ViewBase::OnPaintMarker(_rp);

    //     const RenderParams  *rpActive = GetActiveOrTopmostRenderParams();
    //     CHECK_PRE_CONDITION_VOID(rpActive != nullptr);

    //     // draw a red cross if no active document
    //     qPainter            p(this);
    //     qPen                penVisibleArea(rgbaRed);
    //     qRect2D<s32>        vp_pic      = rpActive->VpRect_pic();
    //     qRect2D<s32>        vp_client   = Pic2Client(vp_pic);

    //     p.DrawRect(vp_client, &penVisibleArea);
} // NavigatorView::doPaintMarker


/*******************************************************************************
* NavigatorView::OnPaintBg
*******************************************************************************/
// void NavigatorView::OnPaintBg()
// {
//     qPainter                p(this);
//     qBrush                  brushBg(rgbaBlack);
//     qRect2D<s32>            r2dClient   = ClientRect();
//     shared_ptr<qLayerStack> pLS         = GetActiveOrTopmostLS();

//     p.DrawFilledRect(r2dClient, &brushBg);

//     // draw a red cross if no active document
//     if (pLS == nullptr)
//     {
//         qPen    penCross(rgbaRebeccaPurple);

//         p.DrawLine(r2dClient.lt(), r2dClient.rb(), &penCross);
//         p.DrawLine(r2dClient.rt(), r2dClient.lb());
//     }

// } // NavigatorView::OnPaintBg
