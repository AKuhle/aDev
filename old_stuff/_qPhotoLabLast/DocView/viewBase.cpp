/*******************************************************************************
* \file ViewBase.cpp
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
#include "viewBase.h"
#include "docPl.h"

using namespace std;


/*******************************************************************************
* ViewBase::ViewBase
*******************************************************************************/
ViewBase::ViewBase(SysWin_t             *_pParent,
                   shared_ptr<DocPl>    _pDoc)
: qViewI(_pParent, _pDoc)
{
} // ViewBase::ViewBase


/*******************************************************************************
* ViewBase::~ViewBase
*******************************************************************************/
ViewBase::~ViewBase()
{
} // ViewBase::~ViewBase


/*******************************************************************************
* ViewBase::OnCreate
*******************************************************************************/
bool ViewBase::OnCreate()
{
    // initialize the crollbars
    // UpdateScrollbars();

    return true;
} // ViewBase::OnCreate


/*******************************************************************************
* ViewBase::Doc
*******************************************************************************/
shared_ptr<DocPl> ViewBase::Doc() const
{
    return dynamic_pointer_cast<DocPl> (qViewI::Doc());
} // ViewBase::Doc


/*******************************************************************************
* ViewBase::LayerStack
*******************************************************************************/
shared_ptr<qLayerStack> ViewBase::LayerStack() const
{
    shared_ptr<DocPl> pDoc = Doc();

    return (pDoc != nullptr)?   pDoc->ActiveLS() : nullptr;
} // ViewBase::LayerStack


/*******************************************************************************
* ViewBase::GetRenderParams
*******************************************************************************/
const RenderParams& ViewBase::GetRenderParams() const
{
    return m_renderParams;
} // ViewBase::GetRenderParams


/*******************************************************************************
* ViewBase::OnResize
*******************************************************************************/
void ViewBase::OnResize(const qDimension2D<s32>   &/*_d2dOld*/,
                        const qDimension2D<s32>   &/*_d2dNew*/)
{
    MainWin &mw = GetMainWin();

    // UpdateScrollbars();

    mw.SendUpdateCmd(UPDATE_SCALE_CHANGED | UPDATE_VIEW | UPDATE_GUI, this);
} // ViewBase::OnResize


/*******************************************************************************
* ViewBase::OnPaint
*******************************************************************************/
void ViewBase::OnPaint()
{
    // update the render parameter
    UpdateRenderParams(m_renderParams);

    // get the image
    QImage *pImg = m_renderParams.CreateQImage();

    // paint, if the image exists
    if (pImg != nullptr)
    {
        qPainter            p(this);
        const qRect2D<s32>  &vp = m_renderParams.VpRect_client();

        p.DrawQImg(*pImg, vp.x(), vp.y());
    }

    OnPaintMarker(m_renderParams);
} // ViewBase::OnPaint


/*******************************************************************************
* ViewBase::OnPaintBg
*******************************************************************************/
void ViewBase::OnPaintBg()
{
    qPainter        p(this);
    qBrush          brushBg(rgbaBlack);
    qRect2D<s32>    r2dClient = ClientRect();

    p.DrawFilledRect(r2dClient, &brushBg);

} // ViewBase::OnPaintBg


/*******************************************************************************
* ViewBase::OnPaintMarker
*******************************************************************************/
void ViewBase::OnPaintMarker(const RenderParams &/*_rp*/)
{
} // ViewBase::OnPaintMarker
