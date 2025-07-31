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
#include "viewBase.h"



/*******************************************************************************
* ViewBase::zoomFactor
*******************************************************************************/
dbl ViewBase::zoomFactor() const
{
    return m_renderParams.zoomFactor();
} // ViewBase::zoomFactor


// /*******************************************************************************
// * ViewBase::ZoomFactor_pml
// *******************************************************************************/
// s32 ViewBase::ZoomFactor_pml() const
// {
//     return m_zoomSteps.ZoomFactor_pml();
// } // ViewBase::ZoomFactor_pml


/*******************************************************************************
* ViewBase::setZoomFactor
*******************************************************************************/
void ViewBase::setZoomFactor(dbl _dZoomFactor)
{
    if (isUnequal<dbl>(m_renderParams.zoomFactor(), _dZoomFactor))
    {
        m_renderParams.setZoomFactor(_dZoomFactor);
        updateScrollBars();
    }
} // ViewBase::setZoomFactor


// /*******************************************************************************
// * ViewBase::SetZoomFactor_pml
// *******************************************************************************/
// void ViewBase::SetZoomFactor_pml(s32 _s32ZoomFactor_pml)
// {
//     if (IsUnequal<s32>(ZoomFactor_pml(), _s32ZoomFactor_pml))
//     {
//         MainWin         &mw             =  GetMainWin();

//         m_zoomSteps.SetZoomFactor_pml(_s32ZoomFactor_pml);
//     }
// } // ViewBase::SetZoomFactor_pml


// /*******************************************************************************
// * ViewBase::SetZoomFactorFit
// *******************************************************************************/
// void ViewBase::SetZoomFactorFit()
// {
//     MainWin                 &mw         =  GetMainWin();
//     qRect2D<s32>            r2dClient   = ClientRect();
//     shared_ptr<qLayerStack> pLS         = LayerStack();

//     if (pLS != nullptr && pLS->IsValid())
//     {
//         // 2. set the zoomfactor
//         dbl dZoomFactor = Min<dbl> (((dbl) r2dClient.w()) / pLS->w(),
//                                     ((dbl) r2dClient.h()) / pLS->h());

//         if (IsUnequal<dbl>(ZoomFactor(), dZoomFactor))
//         {
//             m_zoomSteps.SetZoomFactor(dZoomFactor);
//             mw.SendUpdateCmd(UPDATE_SCALE_CHANGED, this);
//         }
//     }
// } // ViewBase::SetZoomFactorFit


/*******************************************************************************
* ViewBase::increaseZoomFactor
*******************************************************************************/
void ViewBase::increaseZoomFactor()
{
    m_renderParams.increaseZoomFactor();
    updateScrollBars();
} // ViewBase::increaseZoomFactor


/*******************************************************************************
* ViewBase::decreaseZoomFactor
*******************************************************************************/
void ViewBase::decreaseZoomFactor()
{
    m_renderParams.decreaseZoomFactor();
    updateScrollBars();
} // ViewBase::decreaseZoomFactor


/*******************************************************************************
* ViewBase::picDimension_zoom
*******************************************************************************/
aDimension2D<s32> ViewBase::picDimension_zoom() const
{
    return m_renderParams.dimension_zoom();
} // ViewBase::picDimension_zoom


// /*******************************************************************************
// * ViewBase::Client2Pic
// *******************************************************************************/
// qRect2D<s32> ViewBase::Client2Pic(const qRect2D<s32> &_r2d_client) const
// {
//     const qRect2D<s32>  &r2dClient  = m_renderParams.VpRect_client();
//     const qRect2D<s32>  &r2dPic     = m_renderParams.VpRect_pic();

//     return r2dClient.Transform(r2dPic, _r2d_client);
// }; // ViewBase::Client2Pic


// /*******************************************************************************
// * ViewBase::Client2Pic
// *******************************************************************************/
// qVector2D<s32> ViewBase::Client2Pic(const qVector2D<s32> &_v2d_client) const
// {
//     const qRect2D<s32>  &r2dClient  = m_renderParams.VpRect_client();
//     const qRect2D<s32>  &r2dPic     = m_renderParams.VpRect_pic();

//     return r2dClient.Transform(r2dPic, _v2d_client);
// }; // ViewBase::Client2Pic


// /*******************************************************************************
// * ViewBase::Client2Pic
// *******************************************************************************/
// qVector2D<s32> ViewBase::Client2Pic(const s32	_s32X_client,
//                                     const s32	_s32Y_client) const
// {
//     return Client2Pic(qVector2D<s32>(_s32X_client, _s32Y_client));
// }; // ViewBase::Client2Pic


// /*******************************************************************************
// * ViewBase::Client2Zoom
// *******************************************************************************/
// qRect2D<s32> ViewBase::Client2Zoom(const qRect2D<s32> &_r2d_client) const
// {
//     const qRect2D<s32>  &r2dClient  = m_renderParams.VpRect_client();
//     const qRect2D<s32>  &r2dZoom    = m_renderParams.VpRect_pic();

//     return r2dClient.Transform(r2dZoom, _r2d_client);
// }; // ViewBase::Client2Zoom


// /*******************************************************************************
// * ViewBase::Client2Zoom
// *******************************************************************************/
// qVector2D<s32> ViewBase::Client2Zoom(const qVector2D<s32> &_v2d_client) const
// {
//     const qRect2D<s32>  &r2dClient  = m_renderParams.VpRect_client();
//     const qRect2D<s32>  &r2dZoom    = m_renderParams.VpRect_zoom();

//     return r2dClient.Transform(r2dZoom, _v2d_client);
// }; // ViewBase::Client2Zoom


// /*******************************************************************************
// * ViewBase::Client2Zoom
// *******************************************************************************/
// qVector2D<s32> ViewBase::Client2Zoom(const s32	_s32X_client,
//                                      const s32	_s32Y_client) const
// {
//     return Client2Zoom(qVector2D<s32>(_s32X_client, _s32Y_client));
// }; // ViewBase::Client2Zoom


// /*******************************************************************************
// * ViewBase::Pic2Client
// *******************************************************************************/
// qRect2D<s32> ViewBase::Pic2Client(const qRect2D<s32> &_r2d_client) const
// {
//     const qRect2D<s32>  &r2dPic     = m_renderParams.VpRect_pic();
//     const qRect2D<s32>  &r2dClient  = m_renderParams.VpRect_client();

//     return r2dPic.Transform(r2dClient, _r2d_client);
// }; // ViewBase::Pic2Client


// /*******************************************************************************
// * ViewBase::Pic2Client
// *******************************************************************************/
// qVector2D<s32> ViewBase::Pic2Client(const qVector2D<s32> &_v2d_pic) const
// {
//     const qRect2D<s32>  &r2dPic     = m_renderParams.VpRect_pic();
//     const qRect2D<s32>  &r2dClient  = m_renderParams.VpRect_client();

//     return r2dPic.Transform(r2dClient, _v2d_pic);
// }; // ViewBase::Pic2Client


// /*******************************************************************************
// * ViewBase::Pic2Client
// *******************************************************************************/
// qVector2D<s32> ViewBase::Pic2Client(const s32	_s32X_pic,
//                                     const s32	_s32Y_pic) const
// {
//     return Pic2Client(qVector2D<s32> (_s32X_pic, _s32Y_pic));
// }; // ViewBase::Pic2Client


// /*******************************************************************************
// * ViewBase::Pic2Zoom
// *******************************************************************************/
// qRect2D<s32> ViewBase::Pic2Zoom(const qRect2D<s32> &_r2d_pic) const
// {
//     return qRect2D<s32> (_r2d_pic.x() * ZoomFactor(),
//                          _r2d_pic.y() * ZoomFactor(),
//                          _r2d_pic.w() * ZoomFactor(),
//                          _r2d_pic.h() * ZoomFactor());
// } // ViewBase::Pic2Zoom


/*******************************************************************************
* ViewBase::pic2Zoom
*******************************************************************************/
aPoint2D<s32> ViewBase::pic2Zoom(const aPoint2D<s32> &_v2d_pic) const
{
    return aPoint2D<s32> (_v2d_pic * zoomFactor());
} // ViewBase::pic2Zoom


// /*******************************************************************************
// * ViewBase::Pic2Zoom
// *******************************************************************************/
// qVector2D<s32> ViewBase::Pic2Zoom(const s32	_s32X_pic,
//                                   const s32	_s32Y_pic) const
// {
//    return Pic2Zoom(qVector2D<s32>(_s32X_pic, _s32Y_pic));
// } // ViewBase::Pic2Zoom


/*******************************************************************************
* ViewBase::centerPoint_pic
*******************************************************************************/
aPoint2D<s32> ViewBase::centerPoint_pic() const
{
    return m_renderParams.viewPort_pic().centerPoint();
} // ViewBase::centerPoint_pic


/*******************************************************************************
* ViewBase::centerPoint_zoom
*******************************************************************************/
aPoint2D<s32> ViewBase::centerPoint_zoom() const
{
    return m_renderParams.viewPort_zoom().centerPoint();
} // ViewBase::centerPoint_zoom


/*******************************************************************************
* ViewBase::setCenterPoint_pic
*******************************************************************************/
void ViewBase::setCenterPoint_pic(aPoint2D<s32> _v2dCenter_pic)
{
    // call the virtual member because
    // some views have a parent with scrollbars, which must be adjusted, other not
    // fullView e.g. will probabla ignore this etc.
    setCenterPointInZoom(pic2Zoom(_v2dCenter_pic));
} // ViewBase::setCenterPoint_pic


/*******************************************************************************
* ViewBase::setCenterPoint_pic
*******************************************************************************/
void ViewBase::setCenterPoint_pic(s32     _x_pic,
                                  s32     _y_pic)
{
    // call the virtual member because
    // some views have a parent with scrollbars, which must be adjusted, other not
    // fullView e.g. will probabla ignore this etc.
    setCenterPointInZoom(pic2Zoom(aPoint2D<s32> (_x_pic, _y_pic)));
} // ViewBase::setCenterPoint_pic


/*******************************************************************************
* ViewBase::setCenterPoint_zoom
*******************************************************************************/
void ViewBase::setCenterPoint_zoom(aPoint2D<s32> _v2dCenter_zoom)
{
    // call the virtual member because
    // some views have a parent with scrollbars, which must be adjusted, other not
    // fullView e.g. will probabla ignore this etc.
    setCenterPointInZoom(_v2dCenter_zoom);
} // ViewBase::setCenterPoint_zoom


/*******************************************************************************
* ViewBase::setCenterPoint_zoom
*******************************************************************************/
void ViewBase::setCenterPoint_zoom(s32     _x_zoom,
                                   s32     _y_zoom)
{
    // call the virtual member because
    // some views have a parent with scrollbars, which must be adjusted, other not
    // fullView e.g. will probabla ignore this etc.
    setCenterPointInZoom(aPoint2D<s32> (_x_zoom, _y_zoom));
} // ViewBase::setCenterPoint_zoom


// /*******************************************************************************
// * ViewBase::MapPic2Client
// *******************************************************************************/
// void ViewBase::MapPic2Client(const qVector2D<s32>   &_v32MapPoint_pic,
//                              const qVector2D<s32>   &_v2dDest_client)
// {
//     const qRect2D<s32>      r2dContent          = ClientRect();

//     const qVector2D<s32>    v2dVpCenterPoint    = r2dContent.CenterPoint();
//     qVector2D<s32>          v2dMapPoint_zoom    = Pic2Zoom(_v32MapPoint_pic);

//     v2dMapPoint_zoom.x() -= _v2dDest_client.x() - v2dVpCenterPoint.x();
//     v2dMapPoint_zoom.y() -= _v2dDest_client.y() - v2dVpCenterPoint.y();

//     SetCenterPoint_zoom(v2dMapPoint_zoom);
// } // ViewBase
