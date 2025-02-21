/*******************************************************************************
* \file ViewBase_coordinates.cpp
* \author Andreas Kuhlewind
*
* \brief
*
* $Revision: 69 $
* $LastChangedDate: 2010-08-17 14:10:45 +0200 (Di, 17 Aug 2010) $
* $LastChangedBy: akuhlewi $
*
*  Detailed description starts here.
*******************************************************************************/


/*******************************************************************************
* includes
*******************************************************************************/
#include "qBaseDefs.h"
#include "mainWin.h"
#include "viewBase.h"
#include "renderParams.h"

using namespace qLib;


/*******************************************************************************
* ViewBase::ZoomFactor
*******************************************************************************/
dbl ViewBase::ZoomFactor() const
{
    return m_zoomSteps.ZoomFactor();
} // ViewBase::ZoomFactor


/*******************************************************************************
* ViewBase::ZoomFactor_pml
*******************************************************************************/
s32 ViewBase::ZoomFactor_pml() const
{
    return m_zoomSteps.ZoomFactor_pml();
} // ViewBase::ZoomFactor_pml


/*******************************************************************************
* ViewBase::SetZoomFactor
*******************************************************************************/
void ViewBase::SetZoomFactor(dbl _dZoomFactor)
{
    if (IsUnequal<dbl>(ZoomFactor(), _dZoomFactor))
    {
        MainWin         &mw             =  GetMainWin();

        m_zoomSteps.SetZoomFactor(_dZoomFactor);
        mw.SendUpdateCmd(UPDATE_SCALE_CHANGED, this);
    }
} // ViewBase::SetZoomFactor


/*******************************************************************************
* ViewBase::SetZoomFactor_pml
*******************************************************************************/
void ViewBase::SetZoomFactor_pml(s32 _s32ZoomFactor_pml)
{
    if (IsUnequal<s32>(ZoomFactor_pml(), _s32ZoomFactor_pml))
    {
        MainWin         &mw             =  GetMainWin();

        m_zoomSteps.SetZoomFactor_pml(_s32ZoomFactor_pml);
        mw.SendUpdateCmd(UPDATE_SCALE_CHANGED, this);
    }
} // ViewBase::SetZoomFactor_pml


/*******************************************************************************
* ViewBase::SetZoomFactorFit
*******************************************************************************/
void ViewBase::SetZoomFactorFit()
{
    MainWin                 &mw         =  GetMainWin();
    qRect2D<s32>            r2dClient   = ClientRect();
    shared_ptr<qLayerStack> pLS         = LayerStack();

    if (pLS != nullptr && pLS->IsValid())
    {
        // 2. set the zoomfactor
        dbl dZoomFactor = Min<dbl> (((dbl) r2dClient.w()) / pLS->w(),
                                    ((dbl) r2dClient.h()) / pLS->h());

        if (IsUnequal<dbl>(ZoomFactor(), dZoomFactor))
        {
            m_zoomSteps.SetZoomFactor(dZoomFactor);
            mw.SendUpdateCmd(UPDATE_SCALE_CHANGED, this);
        }
    }
} // ViewBase::SetZoomFactorFit


/*******************************************************************************
* ViewBase::IncreaseZoomFactor
*******************************************************************************/
void ViewBase::IncreaseZoomFactor()
{
    MainWin                 &mw         =  GetMainWin();

    m_zoomSteps.IncreaseZoomFactor();
    mw.SendUpdateCmd(UPDATE_SCALE_CHANGED, this);
} // ViewBase::IncreaseZoomFactor


/*******************************************************************************
* ViewBase::DecreaseZoomFactor
*******************************************************************************/
void ViewBase::DecreaseZoomFactor()
{
    MainWin                 &mw         =  GetMainWin();

    m_zoomSteps.DecreaseZoomFactor();
    mw.SendUpdateCmd(UPDATE_SCALE_CHANGED, this);
} // ViewBase::DecreaseZoomFactor


/*******************************************************************************
* ViewBase::PicSize_zoom
*******************************************************************************/
qDimension2D<s32> ViewBase::PicSize_zoom() const
{
    shared_ptr<qLayerStack> pLS         = LayerStack();
    qDimension2D<s32>       dim;
    CHECK_PRE_CONDITION(pLS != nullptr, dim);

    dbl                     dZF = ZoomFactor();

    dim.Set(dZF * pLS->w(),
            dZF * pLS->h());

    return dim;
} // ViewBase::PicSize_zoom


/*******************************************************************************
* ViewBase::Client2Pic
*******************************************************************************/
qRect2D<s32> ViewBase::Client2Pic(const qRect2D<s32> &_r2d_client) const
{
    const qRect2D<s32>  &r2dClient  = m_renderParams.VpRect_client();
    const qRect2D<s32>  &r2dPic     = m_renderParams.VpRect_pic();

    return r2dClient.Transform(r2dPic, _r2d_client);
}; // ViewBase::Client2Pic


/*******************************************************************************
* ViewBase::Client2Pic
*******************************************************************************/
qVector2D<s32> ViewBase::Client2Pic(const qVector2D<s32> &_v2d_client) const
{
    const qRect2D<s32>  &r2dClient  = m_renderParams.VpRect_client();
    const qRect2D<s32>  &r2dPic     = m_renderParams.VpRect_pic();

    return r2dClient.Transform(r2dPic, _v2d_client);
}; // ViewBase::Client2Pic


/*******************************************************************************
* ViewBase::Client2Pic
*******************************************************************************/
qVector2D<s32> ViewBase::Client2Pic(const s32	_s32X_client,
                                    const s32	_s32Y_client) const
{
    return Client2Pic(qVector2D<s32>(_s32X_client, _s32Y_client));
}; // ViewBase::Client2Pic


/*******************************************************************************
* ViewBase::Client2Zoom
*******************************************************************************/
qRect2D<s32> ViewBase::Client2Zoom(const qRect2D<s32> &_r2d_client) const
{
    const qRect2D<s32>  &r2dClient  = m_renderParams.VpRect_client();
    const qRect2D<s32>  &r2dZoom    = m_renderParams.VpRect_pic();

    return r2dClient.Transform(r2dZoom, _r2d_client);
}; // ViewBase::Client2Zoom


/*******************************************************************************
* ViewBase::Client2Zoom
*******************************************************************************/
qVector2D<s32> ViewBase::Client2Zoom(const qVector2D<s32> &_v2d_client) const
{
    const qRect2D<s32>  &r2dClient  = m_renderParams.VpRect_client();
    const qRect2D<s32>  &r2dZoom    = m_renderParams.VpRect_zoom();

    return r2dClient.Transform(r2dZoom, _v2d_client);
}; // ViewBase::Client2Zoom


/*******************************************************************************
* ViewBase::Client2Zoom
*******************************************************************************/
qVector2D<s32> ViewBase::Client2Zoom(const s32	_s32X_client,
                                     const s32	_s32Y_client) const
{
    return Client2Zoom(qVector2D<s32>(_s32X_client, _s32Y_client));
}; // ViewBase::Client2Zoom


/*******************************************************************************
* ViewBase::Pic2Client
*******************************************************************************/
qRect2D<s32> ViewBase::Pic2Client(const qRect2D<s32> &_r2d_client) const
{
    const qRect2D<s32>  &r2dPic     = m_renderParams.VpRect_pic();
    const qRect2D<s32>  &r2dClient  = m_renderParams.VpRect_client();

    return r2dPic.Transform(r2dClient, _r2d_client);
}; // ViewBase::Pic2Client


/*******************************************************************************
* ViewBase::Pic2Client
*******************************************************************************/
qVector2D<s32> ViewBase::Pic2Client(const qVector2D<s32> &_v2d_pic) const
{
    const qRect2D<s32>  &r2dPic     = m_renderParams.VpRect_pic();
    const qRect2D<s32>  &r2dClient  = m_renderParams.VpRect_client();

    return r2dPic.Transform(r2dClient, _v2d_pic);
}; // ViewBase::Pic2Client


/*******************************************************************************
* ViewBase::Pic2Client
*******************************************************************************/
qVector2D<s32> ViewBase::Pic2Client(const s32	_s32X_pic,
                                    const s32	_s32Y_pic) const
{
    return Pic2Client(qVector2D<s32> (_s32X_pic, _s32Y_pic));
}; // ViewBase::Pic2Client


/*******************************************************************************
* ViewBase::Pic2Zoom
*******************************************************************************/
qRect2D<s32> ViewBase::Pic2Zoom(const qRect2D<s32> &_r2d_pic) const
{
    return qRect2D<s32> (_r2d_pic.x() * ZoomFactor(),
                         _r2d_pic.y() * ZoomFactor(),
                         _r2d_pic.w() * ZoomFactor(),
                         _r2d_pic.h() * ZoomFactor());
} // ViewBase::Pic2Zoom


/*******************************************************************************
* ViewBase::Pic2Zoom
*******************************************************************************/
qVector2D<s32> ViewBase::Pic2Zoom(const qVector2D<s32> &_v2d_pic) const
{
    return qVector2D<s32> (_v2d_pic * ZoomFactor());
} // ViewBase::Pic2Zoom


/*******************************************************************************
* ViewBase::Pic2Zoom
*******************************************************************************/
qVector2D<s32> ViewBase::Pic2Zoom(const s32	_s32X_pic,
                                  const s32	_s32Y_pic) const
{
   return Pic2Zoom(qVector2D<s32>(_s32X_pic, _s32Y_pic));
} // ViewBase::Pic2Zoom


/*******************************************************************************
* ViewBase::CenterPoint_pic
*******************************************************************************/
qVector2D<s32> ViewBase::CenterPoint_pic() const
{
    return m_renderParams.VpRect_pic().CenterPoint();
}; // ViewBase::CenterPoint_pic


/*******************************************************************************
* ViewBase::CenterPoint_zoom
*******************************************************************************/
qVector2D<s32> ViewBase::CenterPoint_zoom() const
{
    return m_renderParams.VpRect_zoom().CenterPoint();
}; // ViewBase::CenterPoint_zoom


/*******************************************************************************
* ViewBase::SetCenterPoint_pic
*******************************************************************************/
void ViewBase::SetCenterPoint_pic(qVector2D<s32> _v2dCenter_pic)
{
    // call the virtual member because
    // some vies have a parent with scrollbars, which must be adjusted, other not
    // fullView e.g. will probabla ignore this etc.
    SetCenterPointInZoom(Pic2Zoom(_v2dCenter_pic));
}; // ViewBase::SetCenterPoint_pic


/*******************************************************************************
* ViewBase::SetCenterPoint_pic
*******************************************************************************/
void ViewBase::SetCenterPoint_pic(s32     _s32X_pic,
                                  s32     _s32Y_pic)
{
    // call the virtual member because
    // some vies have a parent with scrollbars, which must be adjusted, other not
    // fullView e.g. will probabla ignore this etc.
    SetCenterPoint_pic(qVector2D<s32> (_s32X_pic, _s32Y_pic));
}; // ViewBase::SetCenterPoint_pic


/*******************************************************************************
* ViewBase::SetCenterPoint_zoom
*******************************************************************************/
void ViewBase::SetCenterPoint_zoom(qVector2D<s32> _v2dCenter_zoom)
{
    // call the virtual member because
    // some vies have a parent with scrollbars, which must be adjusted, other not
    // fullView e.g. will probabla ignore this etc.
    SetCenterPointInZoom(_v2dCenter_zoom);
}; // ViewBase::SetCenterPoint_zoom


/*******************************************************************************
* ViewBase::SetCenterPoint_zoom
*******************************************************************************/
void ViewBase::SetCenterPoint_zoom(s32     _s32X_zoom,
                                   s32     _s32Y_zoom)
{
    // call the virtual member because
    // some vies have a parent with scrollbars, which must be adjusted, other not
    // fullView e.g. will probabla ignore this etc.
    SetCenterPointInZoom(qVector2D<s32> (_s32X_zoom, _s32Y_zoom));
}; // ViewBase::SetCenterPoint_zoom


/*******************************************************************************
* ViewBase::MapPic2Client
*******************************************************************************/
void ViewBase::MapPic2Client(const qVector2D<s32>   &_v32MapPoint_pic,
                             const qVector2D<s32>   &_v2dDest_client)
{
    const qRect2D<s32>      r2dContent          = ClientRect();

    const qVector2D<s32>    v2dVpCenterPoint    = r2dContent.CenterPoint();
    qVector2D<s32>          v2dMapPoint_zoom    = Pic2Zoom(_v32MapPoint_pic);

    v2dMapPoint_zoom.x() -= _v2dDest_client.x() - v2dVpCenterPoint.x();
    v2dMapPoint_zoom.y() -= _v2dDest_client.y() - v2dVpCenterPoint.y();

    SetCenterPoint_zoom(v2dMapPoint_zoom);
} // ViewBase
