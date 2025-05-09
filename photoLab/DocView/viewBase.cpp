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

#include "toolMove.h"

using namespace std;
using namespace aLib;
using namespace aLib::aGraphic;


/*******************************************************************************
* ViewBase::ViewBase
*******************************************************************************/
ViewBase::ViewBase(SysWin               *_pParent,
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
* ViewBase::onCreateWin
*******************************************************************************/
bool ViewBase::onCreateWin()
{
    // initialize the crollbars
    // UpdateScrollbars();

    // todo: use mode from toolDialog

    // enable mouse tracking
    setMouseTracking(true);

    return true;
} // ViewBase::onCreateWin


/*******************************************************************************
* ViewBase::onPaint
*******************************************************************************/
bool ViewBase::onPaint()
{
    aPainter    p(this);

    doPaint(p);

    return true;
} // ViewBase::onPaint


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
* ViewBase::setTool
*******************************************************************************/
void ViewBase::setTool(enumEditMode _eMode)
{
    switch (_eMode)
    {
        default:
            cancelAllTools();
            break;

        case enumEditMode::Move:
        {
            aToolMgr::setTool(std::make_unique<ToolMove> (this));
            break;
        }

        case enumEditMode::Zoom:
            break;
    }
} // ViewBase::setTool


/*******************************************************************************
* ViewBase::doPaint
*******************************************************************************/
void ViewBase::doPaint(aPainter &_painter)
{
    // update the render parameter
    updateRenderParams(m_renderParams);

    // paint the background
    doPaintBackground(_painter);

    // get the image
    QImage *pImg = m_renderParams.createQImage();

    // paint, if the image exists
    if (pImg != nullptr)
    {
        aRect2D<s32>    vp = m_renderParams.viewPort_client();

        _painter.drawQImg(*pImg, vp.x(), vp.y());
    }

    // paint markers
    doPaintMarker(_painter);

} // ViewBase::doPaint


/*******************************************************************************
* ViewBase::doPaintBackground
*******************************************************************************/
void ViewBase::doPaintBackground(aPainter &/*_painter*/)
{
} // ViewBase::doPaintBackground


/*******************************************************************************
* ViewBase::doPaintMarker
*******************************************************************************/
void ViewBase::doPaintMarker(aPainter &/*_painter*/)
{
} // ViewBase::doPaintMarker


/*******************************************************************************
* ViewBase::doWheel
*******************************************************************************/
bool ViewBase::doWheel(u32                  _u32Modifiers,
                       s32                  _s32Degree,
                       const aVector2D<s32> &_v2dLocal,
                       const aVector2D<s32> &_v2dGlobal)
{
    toolMgrOnWheel(_u32Modifiers, _s32Degree, _v2dLocal, _v2dGlobal);

    //aToolBase   *pTool = ActiveTool();

    //if (pTool != nullptr)
    //{

    //}

    // // redirect to the view
    // ViewBase *pView = dynamic_cast<ViewBase*> (viewport());
    // if (pView != nullptr)
    // {
    //     pView->onWheel(_u32Modifiers, _s32Degree, _v2dLocal, _v2dGlobal);
    // }

    return true;
} // ViewBase::doWheel







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
