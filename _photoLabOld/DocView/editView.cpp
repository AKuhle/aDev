/*******************************************************************************
* \file EditView.cpp
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
#include "editView.h"
#include "editScrollWin.h"

using namespace std;



/*******************************************************************************
* EditView::EditView
*******************************************************************************/
EditView::EditView(SysWin                       *_pParent,
                   std::shared_ptr<Document>    _pDoc)
: ViewBase(_pParent, _pDoc)
{
} // EditView::EditView


/*******************************************************************************
* EditView::~EditView
*******************************************************************************/
EditView::~EditView()
{
} // EditView::~EditView


/*******************************************************************************
* EditView::onCreateWin
*******************************************************************************/
bool EditView::onCreateWin()
{
    ViewBase::onCreateWin();

    // enable mouse tracking
    setMouseTracking(true);

    return true;
} // EditView::onCreateWin


/*******************************************************************************
* EditView::updateScrollBars
*******************************************************************************/
void EditView::updateScrollBars()
{
    EditScrollWin   *pScrollWin = dynamic_cast<EditScrollWin *> (parent());

    if (pScrollWin != nullptr)
    {
        pScrollWin->updateScrollBars();
    }
} // EditView::updateScrollBars


/*******************************************************************************
* EditView::setCenterPointInZoom
*******************************************************************************/
void EditView::setCenterPointInZoom(aVector2D<s32> /*_v2dCenter_zoom*/)
{
} // EditView::setCenterPointInZoom


/*******************************************************************************
* EditView::updateRenderParams
*******************************************************************************/
void EditView::updateRenderParams(RenderParams &_rp)
{
    shared_ptr<SynchronizedLS>  pSync = layerStack();
    _rp.setLayerStack(pSync);

    if (pSync != nullptr)
    {
        bool bValid = false;

        {
            SharedLS                    pShared(*pSync);

            bValid = pShared.get()->isValid();
        }

        if (bValid)
        {
            aRect2D<s32>        r2dContent      = clientRect();
            s32                 s32HoriSbPos    = 0;//pScrollWin->HoriSbPos();
            s32                 s32VertSbPos    = 0;//pScrollWin->VertSbPos();
            dbl                 dZF             = zoomFactor();
            aDimension2D<s32>   d2dPic_zoom     = picDimension_zoom();
            aRect2D<s32>        r2dVp;
            aRect2D<s32>        r2dPic_zoom(-s32HoriSbPos, -s32VertSbPos,
                                            d2dPic_zoom.w(), d2dPic_zoom.h());

            // calculate the area which needs to be calculated
            r2dVp = r2dPic_zoom.intersect1(r2dContent);

            // 2. set the zoomfactor
            _rp.setZoomFactor(dZF);

            // 3. set the viewport
            _rp.setVp_client(r2dVp);

            // 4. set the origin in the image
            _rp.setOrigin_zoom(0, 0);


    //         // a EditView has always a StdScrollWin as a parent
    //         StdScrollWin *pScrollWin = dynamic_cast<StdScrollWin *> (Parent());
    //         CHECK_PRE_CONDITION_VOID(pScrollWin != nullptr);

    //         qRect2D<s32>        r2dClient       = ClientRect();
    //         s32                 s32HoriSbPos    = pScrollWin->HoriSbPos();
    //         s32                 s32VertSbPos    = pScrollWin->VertSbPos();
    //         dbl                 dZF             = ZoomFactor();
    //         qDimension2D<s32>   d2dPic_zoom     = PicSize_zoom();
    //         qRect2D<s32>        r2dVp;
    //         qRect2D<s32>        r2dPic_zoom(-s32HoriSbPos, -s32VertSbPos,
    //                                         d2dPic_zoom.w(), d2dPic_zoom.h());

    //         // calculate the area which needs to be calculated
    //         r2dVp = r2dPic_zoom.Intersect(r2dClient);

    //         // 2. set the zoomfactor
    //         _rp.SetZoomFactor(dZF);

    //         // 3. set the viewport
    //         _rp.SetVp_client(r2dVp);

    //         // 4. set the origin in the image
    //         _rp.SetOrigin_zoom(Max(0, s32HoriSbPos),
    //                            Max(0, s32VertSbPos));
        }
    }

} // EditView::updateRenderParams


/*******************************************************************************
* EditView::onLeave
*******************************************************************************/
// bool EditView::onLeave(u32 /*_u32Modifiers*/)
// {
//     MainWin     &mw         = getMainWin();

//     mw.sendUpdateCmd(UPDATE_CMD_COORDINATES_CLEAR);

//     // showing the coordinates is not really an action
//     return false;
// } // EditView::onLeave


/*******************************************************************************
* EditView::onMouseMove
*******************************************************************************/
// bool EditView::onMouseMove(u32                  /*_u32Modifiers*/,
//                            u32                  /*_u32MouseButton*/,
//                            const aVector2D<s32> &_v2dLocal,
//                            const aVector2D<s32> &/*_v2dGlobal*/)
// {
//     MainWin     &mw         = getMainWin();

//     mw.sendUpdateCmd(UPDATE_CMD_COORDINATES,
//                      (s64) _v2dLocal.x(),
//                      (s64) _v2dLocal.y());

//     // showing the coordinates is not really an action
//     return false;
// } // EditView::onMouseMove
