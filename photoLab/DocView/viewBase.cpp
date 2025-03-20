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
#include "aLib_def.h"

#include "mainWin.h"
#include "viewBase.h"
#include "document.h"

#include "aColor.h"
#include "aPainter.h"

//#include "toolMove.h"

using namespace std;
using namespace aLib;
using namespace aLib::aGraphic;


/*******************************************************************************
* ViewBase::ViewBase
*******************************************************************************/
ViewBase::ViewBase(SysWinClass          *_pParent,
                   shared_ptr<Document> _pDoc)
: aView(_pParent, _pDoc)
{
} // ViewBase::ViewBase


/*******************************************************************************
* ViewBase::~ViewBase
*******************************************************************************/
ViewBase::~ViewBase()
{
} // ViewBase::~ViewBase


/*******************************************************************************
* ViewBase::onCreate
*******************************************************************************/
bool ViewBase::onCreate()
{
    // initialize the crollbars
    // UpdateScrollbars();

    // todo: use mode from toolDialog
    setEditMode(enumEditMode::Move);

    // enable mouse tracking
    setMouseTracking(true);

    return true;
} // ViewBase::onCreate


/*******************************************************************************
* ViewBase::setTool
*******************************************************************************/
void ViewBase::setTool()
{
    // unique_ptr<ToolMove> pTool;

    // switch (m_eEditMode)
    // {
    //     case enumEditMode::None:
    //         break;

    //     case enumEditMode::Zoom:
    //         break;

    //     case enumEditMode::Move:
    //         pTool = make_unique<ToolMove> (this);
    //         break;
    // }

    // if (pTool != nullptr)
    // {
    //     aToolMgr::setTool(std::move(pTool));
    // }
} // ViewBase::setTool


/*******************************************************************************
* ViewBase::document
*******************************************************************************/
shared_ptr<Document> ViewBase::document() const
{
    return dynamic_pointer_cast<Document> (doc());
} // ViewBase::document


/*******************************************************************************
* ViewBase::layerStack
*******************************************************************************/
shared_ptr<SynchronizedLS> ViewBase::layerStack() const
{
    shared_ptr<Document> pDoc = document();

    return (pDoc != nullptr)?   pDoc->activeLS() : nullptr;
} // ViewBase::layerStack


/*******************************************************************************
* ViewBase::setEditMode
*******************************************************************************/
void ViewBase::setEditMode(enumEditMode _eEditMode)
{
    // set the edit mode
    m_eEditMode = _eEditMode;

    // set the corresponding tool
    setTool();
} // ViewBase::setEditMode


/*******************************************************************************
* ViewBase::onPaint
*******************************************************************************/
// bool ViewBase::onPaint()
// {
//     cout << __PRETTY_FUNCTION__ << endl;

//     // update the render parameter
//     updateRenderParams(m_renderParams);

//     // get the image
//     QImage *pImg = m_renderParams.createQImage();

//     // paint, if the image exists
//     if (pImg != nullptr)
//     {
//         aPainter        p(ToSysWin());
//         aRect2D<s32>    vp = m_renderParams.viewPort_client();

//         p.drawQImg(*pImg, vp.x(), vp.y());
//     }

//     // OnPaintMarker(m_renderParams);

//     return true;
// } // ViewBase::onPaint







// /*******************************************************************************
// * ViewBase::OnPaintMarker
// *******************************************************************************/
// void ViewBase::OnPaintMarker(const RenderParams &/*_rp*/)
// {
// } // ViewBase::OnPaintMarker




// /*******************************************************************************
// * ViewBase::GetRenderParams
// *******************************************************************************/
// const RenderParams& ViewBase::GetRenderParams() const
// {
//     return m_renderParams;
// } // ViewBase::GetRenderParams


// /*******************************************************************************
// * ViewBase::OnResize
// *******************************************************************************/
// void ViewBase::OnResize(const qDimension2D<s32>   &/*_d2dOld*/,
//                         const qDimension2D<s32>   &/*_d2dNew*/)
// {
//     MainWin &mw = GetMainWin();

//     // UpdateScrollbars();

//     mw.SendUpdateCmd(UPDATE_SCALE_CHANGED | UPDATE_VIEW | UPDATE_GUI, this);
// } // ViewBase::OnResize
