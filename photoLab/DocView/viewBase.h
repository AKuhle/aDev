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
#include "aView.h"
#include "aToolMgr.h"

#include "photoLab_defs.h"

#include "document.h"
#include "renderParams.h"


/*******************************************************************************
* forwards
*******************************************************************************/
using namespace aLib::aWin;
using namespace aLib::aGraphic;


/*******************************************************************************
* class ViewBase
*******************************************************************************/
class ViewBase : public aView,
                 public aToolMgr
{
    private:
        RenderParams        m_renderParams;
        // aPoint2D<s32>  m_v2dOrigin_zoom;

    protected:
        ViewBase(SysWin                     *_pParent,
                 std::shared_ptr<Document>  _pDoc);

    public:
        virtual ~ViewBase();

        shared_ptr<Document>        document() const;
        shared_ptr<SynchronizedLS>  layerStack() const;
        // const RenderParams&     GetRenderParams() const;

        void                        setTool(enumEditMode _eEditMode);

        virtual void                doPaint(aPainter &_painter);

    protected:
        virtual void                updateRenderParams(RenderParams &_rp) = 0;
        virtual void                doPaintBackground(aPainter &_painter);
        virtual void                doPaintMarker(aPainter &_painter);

    private:
        void                        setTool();


    /*******************************************************************************
    * coordinates
    *******************************************************************************/
    public:
        dbl                         zoomFactor() const;
        // s32                     ZoomFactor_pml() const;
        void                        setZoomFactor(dbl _dZoomFactor);
        // void                    SetZoomFactor_pml(s32 _s32ZoomFactor_pml);
        // void                    SetZoomFactorFit();  // calculates and sets the zoomfactor to see the whole image
        void                        increaseZoomFactor();
        void                        decreaseZoomFactor();

        aDimension2D<s32>           picDimension_zoom() const;

        // // Client2Pic
        // qRect2D<s32>            Client2Pic(const qRect2D<s32> &_r2d_client) const;
        // aPoint2D<s32>          Client2Pic(const aPoint2D<s32> &_v2d_client) const;
        // aPoint2D<s32>          Client2Pic(const s32	_s32X_client,
        //                                    const s32	_s32Y_client) const;

        // // Client2Zoom
        // qRect2D<s32>            Client2Zoom(const qRect2D<s32> &_r2d_client) const;
        // aPoint2D<s32>          Client2Zoom(const aPoint2D<s32> &_v2d_client) const;
        // aPoint2D<s32>          Client2Zoom(const s32	_s32X_client,
        //                                     const s32	_s32Y_client) const;

        // // Pic2Client
        // qRect2D<s32>            Pic2Client(const qRect2D<s32> &_r2d_pic) const;
        // aPoint2D<s32>          Pic2Client(const aPoint2D<s32> &_v2d_pic) const;
        // aPoint2D<s32>          Pic2Client(const s32	_s32X_pic,
        //                                    const s32	_s32Y_pic) const;

        // // Pic2Zoom
        // qRect2D<s32>            Pic2Zoom(const qRect2D<s32> &_r2d_pic) const;
        aPoint2D<s32>              pic2Zoom(const aPoint2D<s32> &_v2d_pic) const;
        // aPoint2D<s32>          Pic2Zoom(const s32	_s32X_pic,
        //                                  const s32	_s32Y_pic) const;

        // center point
        aPoint2D<s32>              centerPoint_pic() const;
        aPoint2D<s32>              centerPoint_zoom() const;

        void                        setCenterPoint_pic(aPoint2D<s32> _v2dCenter_pic);

        void                        setCenterPoint_pic(s32  _x_pic,
                                                       s32  _y_pic);

        void                        setCenterPoint_zoom(aPoint2D<s32> _v2dCenter_zoom);

        void                        setCenterPoint_zoom(s32     _x_zoom,
                                                        s32     _y_zoom);

        // // mapping methods
        // void                    MapPic2Client(const aPoint2D<s32>  &_v32MapPoint_pic,
        //                                       const aPoint2D<s32>  &_v2dDest_client);

    protected:
        virtual void                updateScrollBars() = 0;
        virtual void                setCenterPointInZoom(aPoint2D<s32> _v2dCenter_zoom) = 0;


    /*******************************************************************************
    * aToolMgr interface
    *******************************************************************************/
    protected:
        void                        onToolStarted(aToolBase *_pTool) override;
        void                        onToolSuccess(aToolBase *_pTool) override;
        void                        onToolCanceled(aToolBase *_pTool) override;
        void                        onToolFinished(u32 _u32ToolId) override;

        void                        onToolMsg(aToolBase *_pTool,
                                              u32       _u32Msg,
                                              s32       _s32Param,
                                              u32       _u32Param,
                                              s64       _s64Param,
                                              u64       _u64Param,
                                              flt       _fltParam,
                                              dbl       _dblParam) override;


    /*******************************************************************************
    * aBaseWin interface
    *******************************************************************************/
    protected:
        bool                        onCreateWin() override;
        bool                        onPaint() override;

    public:
         bool                       doWheel(u32                  _u32Modifiers,
                                            s32                  _s32Degree,
                                            const aPoint2D<s32> &_v2dLocal,
                                            const aPoint2D<s32> &_v2dGlobal);

            // virtual void            OnResize(const qDimension2D<s32>    &_d2dOld,
        //                                  const qDimension2D<s32>    &_d2dNew) override;

}; // class ViewBase
