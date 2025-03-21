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
#include "aGraphic_def.h"

#include "photoLab_defs.h"
#include "aView.h"

#include "document.h"
#include "zoomSteps.h"
#include "renderParams.h"


/*******************************************************************************
* forwards
*******************************************************************************/
using namespace aLib::aWin;
using namespace aLib::aGraphic;


/*******************************************************************************
* class ViewBase
*******************************************************************************/
class ViewBase : public aView
{
    private:
        ZoomSteps           m_zoomSteps;
        RenderParams        m_renderParams;
        // aVector2D<s32>  m_v2dOrigin_zoom;

        enumEditMode        m_eEditMode     { enumEditMode::None };

    protected:
        ViewBase(SysWinClass                *_pParent,
                 std::shared_ptr<Document>  _pDoc);

    public:
        virtual ~ViewBase();

        shared_ptr<Document>        document() const;
        shared_ptr<SynchronizedLS>  layerStack() const;
        // const RenderParams&     GetRenderParams() const;

        void                        setEditMode(enumEditMode _eEditMode);

        void                        doPaint(aPainter &_painter);

    protected:
        virtual void                updateRenderParams(RenderParams &_rp) = 0;

    private:
        void                        setTool();


    /*******************************************************************************
    * coordinates
    *******************************************************************************/
    public:
        dbl                         zoomFactor() const;
        // s32                     ZoomFactor_pml() const;
        // void                    SetZoomFactor(dbl _dZoomFactor);
        // void                    SetZoomFactor_pml(s32 _s32ZoomFactor_pml);
        // void                    SetZoomFactorFit();  // calculates and sets the zoomfactor to see the whole image
        void                        increaseZoomFactor();
        void                        decreaseZoomFactor();

        aDimension2D<s32>           picDimension_zoom() const;

        // // Client2Pic
        // qRect2D<s32>            Client2Pic(const qRect2D<s32> &_r2d_client) const;
        // aVector2D<s32>          Client2Pic(const aVector2D<s32> &_v2d_client) const;
        // aVector2D<s32>          Client2Pic(const s32	_s32X_client,
        //                                    const s32	_s32Y_client) const;

        // // Client2Zoom
        // qRect2D<s32>            Client2Zoom(const qRect2D<s32> &_r2d_client) const;
        // aVector2D<s32>          Client2Zoom(const aVector2D<s32> &_v2d_client) const;
        // aVector2D<s32>          Client2Zoom(const s32	_s32X_client,
        //                                     const s32	_s32Y_client) const;

        // // Pic2Client
        // qRect2D<s32>            Pic2Client(const qRect2D<s32> &_r2d_pic) const;
        // aVector2D<s32>          Pic2Client(const aVector2D<s32> &_v2d_pic) const;
        // aVector2D<s32>          Pic2Client(const s32	_s32X_pic,
        //                                    const s32	_s32Y_pic) const;

        // // Pic2Zoom
        // qRect2D<s32>            Pic2Zoom(const qRect2D<s32> &_r2d_pic) const;
        // aVector2D<s32>          Pic2Zoom(const aVector2D<s32> &_v2d_pic) const;
        // aVector2D<s32>          Pic2Zoom(const s32	_s32X_pic,
        //                                  const s32	_s32Y_pic) const;

        // // center point
        // aVector2D<s32>          CenterPoint_pic() const;
        // aVector2D<s32>          CenterPoint_zoom() const;

        // void                    SetCenterPoint_pic(aVector2D<s32> _v2dCenter_pic);

        // void                    SetCenterPoint_pic(s32     _s32X_pic,
        //                                            s32     _s32Y_pic);

        // void                    SetCenterPoint_zoom(aVector2D<s32> _v2dCenter_zoom);

        // void                    SetCenterPoint_zoom(s32     _s32X_zoom,
        //                                             s32     _s32Y_zoom);

        // // mapping methods
        // void                    MapPic2Client(const aVector2D<s32>  &_v32MapPoint_pic,
        //                                       const aVector2D<s32>  &_v2dDest_client);


    protected:
        // virtual void            SetCenterPointInZoom(aVector2D<s32> _v2dCenter_zoom) = 0;


    /*******************************************************************************
    * aBaseWin interface
    *******************************************************************************/
    protected:
        bool                        onCreate() override;

        // virtual void            OnResize(const qDimension2D<s32>    &_d2dOld,
        //                                  const qDimension2D<s32>    &_d2dNew) override;

        // virtual void            OnPaintMarker(const RenderParams &_rp);

}; // class ViewBase
