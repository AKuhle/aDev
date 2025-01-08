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
// #include "qLib.h"
#include "renderParams.h"
#include "zoomSteps.h"


/*******************************************************************************
* forwards
*******************************************************************************/
using namespace qLib;

class DocPl;


/*******************************************************************************
* class ViewBase
*******************************************************************************/
class ViewBase : public qViewI
{
    private:
        ZoomSteps       m_zoomSteps;
        RenderParams    m_renderParams;
        qVector2D<s32>  m_v2dOrigin_zoom;

    protected:
        ViewBase(SysWin_t               *_pParent,
                 std::shared_ptr<DocPl> _pDoc);

    public:
        virtual ~ViewBase();

        shared_ptr<DocPl>       Doc() const;
        shared_ptr<qLayerStack> LayerStack() const;
        const RenderParams&     GetRenderParams() const;

    protected:
        virtual void            UpdateRenderParams(RenderParams &_rp) = 0;


    /*******************************************************************************
    * coordinates
    *******************************************************************************/
    public:
        dbl                     ZoomFactor() const;
        s32                     ZoomFactor_pml() const;
        void                    SetZoomFactor(dbl _dZoomFactor);
        void                    SetZoomFactor_pml(s32 _s32ZoomFactor_pml);
        void                    SetZoomFactorFit();  // calculates and sets the zoomfactor to see the whole image
        void                    IncreaseZoomFactor();
        void                    DecreaseZoomFactor();

        qDimension2D<s32>       PicSize_zoom() const;

        // Client2Pic
        qRect2D<s32>            Client2Pic(const qRect2D<s32> &_r2d_client) const;
        qVector2D<s32>          Client2Pic(const qVector2D<s32> &_v2d_client) const;
        qVector2D<s32>          Client2Pic(const s32	_s32X_client,
                                           const s32	_s32Y_client) const;

        // Client2Zoom
        qRect2D<s32>            Client2Zoom(const qRect2D<s32> &_r2d_client) const;
        qVector2D<s32>          Client2Zoom(const qVector2D<s32> &_v2d_client) const;
        qVector2D<s32>          Client2Zoom(const s32	_s32X_client,
                                            const s32	_s32Y_client) const;

        // Pic2Client
        qRect2D<s32>            Pic2Client(const qRect2D<s32> &_r2d_pic) const;
        qVector2D<s32>          Pic2Client(const qVector2D<s32> &_v2d_pic) const;
        qVector2D<s32>          Pic2Client(const s32	_s32X_pic,
                                           const s32	_s32Y_pic) const;

        // Pic2Zoom
        qRect2D<s32>            Pic2Zoom(const qRect2D<s32> &_r2d_pic) const;
        qVector2D<s32>          Pic2Zoom(const qVector2D<s32> &_v2d_pic) const;
        qVector2D<s32>          Pic2Zoom(const s32	_s32X_pic,
                                         const s32	_s32Y_pic) const;

        // center point
        qVector2D<s32>          CenterPoint_pic() const;
        qVector2D<s32>          CenterPoint_zoom() const;

        void                    SetCenterPoint_pic(qVector2D<s32> _v2dCenter_pic);

        void                    SetCenterPoint_pic(s32     _s32X_pic,
                                                   s32     _s32Y_pic);

        void                    SetCenterPoint_zoom(qVector2D<s32> _v2dCenter_zoom);

        void                    SetCenterPoint_zoom(s32     _s32X_zoom,
                                                    s32     _s32Y_zoom);

        // mapping methods
        void                    MapPic2Client(const qVector2D<s32>  &_v32MapPoint_pic,
                                              const qVector2D<s32>  &_v2dDest_client);


    protected:
        virtual void            SetCenterPointInZoom(qVector2D<s32> _v2dCenter_zoom) = 0;



    /*******************************************************************************
    * qSysWin interface
    *******************************************************************************/
    protected:
        virtual bool            OnCreate() override;

        virtual void            OnResize(const qDimension2D<s32>    &_d2dOld,
                                         const qDimension2D<s32>    &_d2dNew) override;

        virtual void            OnPaint() override;
        virtual void            OnPaintBg() override;
        virtual void            OnPaintMarker(const RenderParams &_rp);


        DECLARE_PAINT_EVENT
        DECLARE_RESIZE_EVENT

        DECLARE_WHEEL_EVENT

        DECLARE_MOUSE_PRESS_EVENT
        DECLARE_MOUSE_MOVE_EVENT
        DECLARE_MOUSE_RELEASE_EVENT

}; // class ViewBase
