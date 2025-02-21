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
// #include "mainWin.h"
#include "viewBase.h"
#include "doc.h"

// using namespace std;


/*******************************************************************************
* ViewBase::ViewBase
*******************************************************************************/
ViewBase::ViewBase(qWin             *_pParent,
                   shared_ptr<Doc>  _pDoc)
: qViewBase(_pParent, _pDoc)
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
#include "toolMove.h"       // temp
bool ViewBase::OnCreate()
{
    // initialize the crollbars
    // UpdateScrollbars();

    // temp
    unique_ptr<ToolMove>    pTool = make_unique<ToolMove> (this);
    SetTool(std::move(pTool));
    cout << "tool set" << endl;

    return true;
} // ViewBase::OnCreate


/*******************************************************************************
* ViewBase::GetDoc
*******************************************************************************/
shared_ptr<Doc> ViewBase::GetDoc() const
{
    return dynamic_pointer_cast<Doc> (qViewBase::GetDoc());
} // ViewBase::GetDoc


/*******************************************************************************
* ViewBase::GetLayerStack
*******************************************************************************/
shared_ptr<qLayerStack> ViewBase::GetLayerStack() const
{
    shared_ptr<Doc> pDoc = GetDoc();

    return (pDoc != nullptr)?   pDoc->GetActiveLS() : nullptr;
} // ViewBase::GetLayerStack


/*******************************************************************************
* ViewBase::GetRenderParams
*******************************************************************************/
const RenderParams& ViewBase::GetRenderParams() const
{
    return m_renderParams;
} // ViewBase::GetRenderParams


/*******************************************************************************
* ViewBase::OnPaintContent
*******************************************************************************/
void ViewBase::OnPaintContent()
{
    // update the render parameter
    UpdateRenderParams(m_renderParams);

    // get the image
    QImage *pImg = m_renderParams.CreateQImage();

    // paint, if the image exists
    if (pImg != nullptr)
    {
        qPainter            p(this);
        const qRect2D<s32>  &vp = m_renderParams.GetVpRect_client();

        p.DrawQImg(*pImg, vp.x, vp.y);
    }

//     OnPaintMarker(m_renderParams);
} // ViewBase::OnPaintContent


/*******************************************************************************
* ViewBase::OnResize
*******************************************************************************/
void ViewBase::OnResize(const qDimension2D<s32>   &/*_d2dOld*/,
                        const qDimension2D<s32>   &/*_d2dNew*/)
{
    //MainWin &mw = GetMainWin();

    UpdateScrollbars();

    //mw.SendUpdateCmd(UPDATE_SCALE_CHANGED | UPDATE_VIEW | UPDATE_GUI, this);
} // ViewBase::OnResize


// /*******************************************************************************
// * ViewBase::OnPaintBg
// *******************************************************************************/
// void ViewBase::OnPaintBg()
// {
//     qPainter        p(this);
//     qBrush          brushBg(rgbaBlack);
//     qRect2D<s32>    r2dClient = ClientRect();

//     p.DrawFilledRect(r2dClient, &brushBg);

// } // ViewBase::OnPaintBg


// /*******************************************************************************
// * ViewBase::OnPaintMarker
// *******************************************************************************/
// void ViewBase::OnPaintMarker(const RenderParams &/*_rp*/)
// {
// } // ViewBase::OnPaintMarker
