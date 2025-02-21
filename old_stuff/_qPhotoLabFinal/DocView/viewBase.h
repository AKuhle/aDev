/*******************************************************************************
* \file ViewBase.h
* \author Andreas Kuhlewind
*
* \brief
*
*  Detailed description starts here.
*******************************************************************************/
#pragma once



/*******************************************************************************
* includes
*******************************************************************************/
#include "renderParams.h"
#include "zoomSteps.h"


/*******************************************************************************
* forwards
*******************************************************************************/
using namespace qLib;

class Doc;


/*******************************************************************************
* class ViewBase
*******************************************************************************/
class ViewBase : public qViewBase
{
    private:
        ZoomSteps       m_zoomSteps;
        RenderParams    m_renderParams;
        // qVector2D<s32>  m_v2dOrigin_zoom;

    protected:
        ViewBase(qWin                   *_pParent,
                 std::shared_ptr<Doc>   _pDoc);

    public:
        virtual ~ViewBase();

        shared_ptr<Doc>         GetDoc() const;
        shared_ptr<qLayerStack> GetLayerStack() const;
        const RenderParams      &GetRenderParams() const;

    protected:
        virtual void            UpdateScrollbars() = 0;
        virtual void            UpdateRenderParams(RenderParams &_rp) = 0;


    /*******************************************************************************
    * coordinates
    *******************************************************************************/
    public:
        dbl                     GetZoomFactor() const;
        s32                     GetZoomFactor_pml() const;
        void                    SetZoomFactor(dbl _dZoomFactor);
        void                    SetZoomFactor_pml(s32 _s32ZoomFactor_pml);
        void                    SetZoomFactorFit();  // calculates and sets the zoomfactor to see the whole image
        void                    IncreaseZoomFactor();
        void                    DecreaseZoomFactor();

        qDimension2D<s32>       GetPicSize_zoom() const;

    //     // Client2Pic
    //     qRect2D<s32>            Client2Pic(const qRect2D<s32> &_r2d_client) const;
    //     qVector2D<s32>          Client2Pic(const qVector2D<s32> &_v2d_client) const;
    //     qVector2D<s32>          Client2Pic(const s32	_s32X_client,
    //                                        const s32	_s32Y_client) const;

    //     // Client2Zoom
    //     qRect2D<s32>            Client2Zoom(const qRect2D<s32> &_r2d_client) const;
    //     qVector2D<s32>          Client2Zoom(const qVector2D<s32> &_v2d_client) const;
    //     qVector2D<s32>          Client2Zoom(const s32	_s32X_client,
    //                                         const s32	_s32Y_client) const;

    //     // Pic2Client
    //     qRect2D<s32>            Pic2Client(const qRect2D<s32> &_r2d_pic) const;
    //     qVector2D<s32>          Pic2Client(const qVector2D<s32> &_v2d_pic) const;
    //     qVector2D<s32>          Pic2Client(const s32	_s32X_pic,
    //                                        const s32	_s32Y_pic) const;

    //     // Pic2Zoom
    //     qRect2D<s32>            Pic2Zoom(const qRect2D<s32> &_r2d_pic) const;
    //     qVector2D<s32>          Pic2Zoom(const qVector2D<s32> &_v2d_pic) const;
    //     qVector2D<s32>          Pic2Zoom(const s32	_s32X_pic,
    //                                      const s32	_s32Y_pic) const;

    //     // center point
    //     qVector2D<s32>          CenterPoint_pic() const;
    //     qVector2D<s32>          CenterPoint_zoom() const;

    //     void                    SetCenterPoint_pic(qVector2D<s32> _v2dCenter_pic);

    //     void                    SetCenterPoint_pic(s32     _s32X_pic,
    //                                                s32     _s32Y_pic);

    //     void                    SetCenterPoint_zoom(qVector2D<s32> _v2dCenter_zoom);

    //     void                    SetCenterPoint_zoom(s32     _s32X_zoom,
    //                                                 s32     _s32Y_zoom);

    //     // mapping methods
    //     void                    MapPic2Client(const qVector2D<s32>  &_v32MapPoint_pic,
    //                                           const qVector2D<s32>  &_v2dDest_client);


    // protected:
    //     virtual void            SetCenterPointInZoom(qVector2D<s32> _v2dCenter_zoom) = 0;



    /*******************************************************************************
    * qWin interface
    *******************************************************************************/
    protected:
        virtual bool                OnCreate() override;

        virtual void                OnResize(const qDimension2D<s32>    &_d2dOld,
                                             const qDimension2D<s32>    &_d2dNew) override;

        virtual void                OnPaintContent() override;

}; // class ViewBase
